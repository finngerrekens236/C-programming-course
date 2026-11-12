"""Compileer en draai elk ```cpp-blok uit een hoofdstukbestand en vergelijk met het direct volgende ```text-blok.

Gebruik (vanuit de map aantekeningen):
    python tools/verify.py hoofdstukken/h05.md          # één hoofdstuk
    python tools/verify.py hoofdstukken/*.md            # alles (bash/Git Bash)

Vereist g++ in PATH (getest met g++ 16.2, MSYS2 UCRT64). Compileert met: g++ -std=c++20 -Wall -Wextra

Conventies in een cpp-blok:
  // ❌ bewust fout: ...   -> overgeslagen (bewuste compilerfout / undefined behaviour)
  // stdin: 5 7            -> tekst die als invoer naar het programma gaat (\\n voor meerdere regels)
  // nocheck-output        -> wel compileren en draaien, output niet vergelijken (adressen, random, sizeof)
  // file: naam.h          -> hulpbestand (zonder main), wordt naast de volgende blokken gezet
  // multi: a.cpp          -> compileer dit main-blok samen met eerder gedefinieerde // file: .cpp-bestanden
"""
import re, sys, os, subprocess, tempfile, shutil, glob

GXX = shutil.which('g++') or r'C:\msys64\ucrt64\bin\g++.exe'


def norm(s):
    return '\n'.join(l.rstrip() for l in s.replace('\r\n', '\n').strip('\n').split('\n'))


def verify(path):
    src = open(path, encoding='utf-8').read()
    blocks = []
    for m in re.finditer(r'^[ \t]*```(cpp|text)[ \t]*\n(.*?)^[ \t]*```[ \t]*$', src, re.M | re.S):
        blocks.append((m[1], m[2], src.count('\n', 0, m.start()) + 1, m.start(), m.end()))
    results, files = [], {}
    tmp = tempfile.mkdtemp(prefix='cppverify_')
    for i, (kind, code, line, st, en) in enumerate(blocks):
        if kind != 'cpp':
            continue
        r = {'line': line}
        fm = re.search(r'//\s*file:\s*(\S+)', code)
        if fm and 'int main' not in code:
            files[fm[1]] = code
            r['status'] = 'support-file'
            results.append(r)
            continue
        if '❌ bewust fout' in code:
            r['status'] = 'skipped-intentional'
            results.append(r)
            continue
        expected = None
        if i + 1 < len(blocks) and blocks[i + 1][0] == 'text' and len(src[en:blocks[i + 1][3]].strip()) < 200:
            expected = blocks[i + 1][1]
        d = os.path.join(tmp, f'b{line}')
        os.makedirs(d)
        for fn, c in files.items():
            open(os.path.join(d, fn), 'w', encoding='utf-8').write(c)
        main = os.path.join(d, 'main.cpp')
        open(main, 'w', encoding='utf-8').write(code)
        srcs = [main]
        if '// multi:' in code:
            srcs += [os.path.join(d, f) for f in files if f.endswith('.cpp')]
        exe = os.path.join(d, 'a.exe')
        c = subprocess.run([GXX, '-std=c++20', '-Wall', '-Wextra', *srcs, '-o', exe],
                           capture_output=True, text=True, encoding='utf-8', errors='replace')
        if c.returncode != 0:
            r.update(status='COMPILE-ERROR', detail=c.stderr[-1500:])
            results.append(r)
            continue
        sm = re.search(r'//\s*stdin:\s*(.*)', code)
        stdin = sm[1].replace('\\n', '\n') + '\n' if sm else ''
        try:
            p = subprocess.run([exe], input=stdin, capture_output=True, text=True, timeout=10,
                               encoding='utf-8', errors='replace', cwd=d)
        except subprocess.TimeoutExpired:
            r['status'] = 'TIMEOUT'
            results.append(r)
            continue
        out = p.stdout + p.stderr
        if expected is None or 'nocheck-output' in code:
            r['status'] = 'ok-no-expected' if expected is None else 'ok-nocheck'
        elif norm(out) == norm(expected):
            r['status'] = 'ok'
        else:
            r.update(status='OUTPUT-MISMATCH', got=out[-1500:], expected=expected[-1500:])
        results.append(r)
    shutil.rmtree(tmp, ignore_errors=True)
    return results


if __name__ == '__main__':
    paths = [p for a in sys.argv[1:] for p in (glob.glob(a) or [a])]
    if not paths:
        sys.exit(__doc__)
    total_fail = 0
    for path in paths:
        res = verify(path)
        bad = [r for r in res if r['status'] in ('COMPILE-ERROR', 'OUTPUT-MISMATCH', 'TIMEOUT')]
        total_fail += len(bad)
        print(f'{os.path.basename(path)}: {len(res)} blokken, {len(bad)} mislukt')
        for r in bad:
            print(f'  regel {r["line"]}: {r["status"]}')
            for k in ('detail', 'got', 'expected'):
                if k in r:
                    print(f'  --- {k}:\n{r[k]}')
    sys.exit(1 if total_fail else 0)
