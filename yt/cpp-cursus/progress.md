# Voortgang – C++ cursus aantekeningen

Video: https://www.youtube.com/watch?v=8jLOx1hD3_o — "C++ Programming Course - Beginner to Advanced" (freeCodeCamp.org, Daniel Gakwaya), 31:07:29, 2022-02-17.

## Tools
- yt-dlp 2026.10.26 (pip)
- ffmpeg 9.0.2 (winget Gyan.FFmpeg; niet in PATH, niet nodig voor ondertitels)
- g++ 16.2.0 (MSYS2 UCRT64, Rev4) — verificatie met `g++ -std=c++20 -Wall -Wextra`

## Stappen
- [x] 1 meta.json + desc.txt
- [x] 2 ondertitels: alleen automatische (en-orig), ../_raw/subs.en-orig.vtt
- [x] 3 transcript_volledig.md (2325 alinea's, ±45 s, conservatieve termfixes)
- [x] 4 indeling akkoord (2026-10-29); chunks/h01–h19.md geschreven (subblokken bij >65 min)
- [x] 5 hoofdstukken/hXX.md — 19 subagents gestart (brief: ../_tools/BRIEF.md, verify: ../_tools/verify.py)

- [x] 5b verificatie.md (383 voorbeelden, FAIL 0)
- [x] 6 cpp_cursus_aantekeningen.md (126.585 woorden, 0 gebroken ankers)

## Indeling (voorstel)
YouTube-chapters onbruikbaar (laatste chapter 0:51:32–31:07:29). Gebruikt: 19 hoofdstukken uit beschrijving; intro (0:00–4:32) bij h01.


## Hoofdstukstatus

| h | status | woorden | cpp-blokken | verify |
|---|---|---|---|---|
| h09 | klaar | ~3776 | 20 (4 bewust fout) | 16/16 ok |
| h13 | klaar | ~3070 | 10 (2 bewust fout) | 10/10 ok |
| h01 | klaar | ~4560 | 9 | 9/9 ok |
| h05 | klaar | ~5460 | 21 (3 bewust fout) | 21/21 ok (fallthrough-warnings bewust) |
| h06 | klaar | ~4170 | 16 (1 bewust fout) | 16/16 ok |
| h12 | klaar | ~3937 | 11 (1 bewust fout, 2 nocheck) | 11/11 ok |
| h02 | klaar | ~5337 | 21 (4 bewust fout) | 21/21 ok |
| h14 | klaar | ~4880 | 19 (1 bewust fout, 2 nocheck) | 19/19 ok |
| h15 | klaar | ~4650 | 18 (3 bewust fout, 3 nocheck) | 18/18 ok |
| h07 | klaar | ~4980 | 23 (7 bewust fout, 1 nocheck) | 23/23 ok |
| h16 | klaar | ~5127 | 19 (6 bewust fout) + 15 syntaxfragmenten als c++ | 19/19 ok |
| h03 | klaar | ~6470 | 22 (4 bewust fout, 4 nocheck) | 22/22 ok |
| h04 | klaar | ~8655 | 23 (1 bewust fout) | 23/23 ok |
| h08 | klaar | ~7650 | 26 (8 bewust fout, 5 nocheck) | 26/26 ok, 2 gecorrigeerd |
| h10 | klaar | ~7159 | 28 (4 bewust fout, 2 nocheck) | 28/28 ok, 6 gecorrigeerd |
| h11 | klaar | ~6100 | 30 (10 support-files, 3 bewust fout, 3 nocheck) | 30/30 ok |
| h17 | klaar | ~8900 | 31 (4 support, 3 bewust fout, 3 nocheck) | 31/31 ok |
| h18 | klaar | ~9600 | 21 (6 bewust fout) + 7 c++-fragmenten | 21/21 ok |

## Afgerond
Alles klaar; tijdelijke bestanden (_raw, _tools, desc.txt) verwijderd.
