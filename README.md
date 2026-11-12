# C++ programming course – oefenen

Mijn oefenprojecten en studieaantekeningen bij de cursus
[C++ Programming Course – Beginner to Advanced](https://www.youtube.com/watch?v=8jLOx1hD3_o) (freeCodeCamp, Daniel Gakwaya, C++20).

## Wat staat waar?

| Map | Inhoud |
|---|---|
| `3.2 firstCppProgram`, `3.3 comments`, … | één oefenproject per les; het nummer volgt de lesnummering van de cursus |
| [`aantekeningen/`](aantekeningen/) | uitgebreide Nederlandstalige aantekeningen van de hele cursus — begin bij de [README daar](aantekeningen/README.md) |

### Welke les hoort bij welk hoofdstuk van de aantekeningen?

Lesnummer *N.x* hoort bij hoofdstuk *N − 1* in de aantekeningen:

| Lessen | Hoofdstuk aantekeningen |
|---|---|
| 3.2 first program · 3.3 comments · 3.4 errors & warnings · 3.5 statements · 3.6 data in- en output | [Hoofdstuk 2 – Diving in](aantekeningen/hoofdstukken/h02.md) |
| 4.x getallen en datatypes | [Hoofdstuk 3 – Variables and data types](aantekeningen/hoofdstukken/h03.md) |
| 5.x, 6.x, … | [Hoofdstuk 4](aantekeningen/hoofdstukken/h04.md), [5](aantekeningen/hoofdstukken/h05.md), … |

## Een oefenproject openen en bouwen

Elk oefenproject is een zelfstandige VS Code-map:

```text
3.2 firstCppProgram/
├── main.cpp                     de code van de les
├── .vscode/
│   ├── tasks.json               build-tasks voor GCC, Clang en MSVC
│   ├── c_cpp_properties.json    IntelliSense-instellingen
│   ├── settings.json            standaardterminal "PowerShell (MSVC)"
│   └── extensions.json          aanbevolen extensie (C/C++)
└── scripts/
    ├── build-msvc.cmd           bouwt met MSVC zonder Developer Command Prompt
    └── dev-shell.ps1            laadt de MSVC-omgeving in de terminal
```

1. Open de **map van het project** in VS Code (*File → Open Folder*), niet de hoofdmap — de tasks gebruiken `${workspaceFolder}`.
2. Open `main.cpp` en druk op **Ctrl+Shift+B**:
   - de standaardtask is **Build with MSVC** (Visual Studio of Build Tools met *Desktop development with C++* nodig);
   - via *Terminal → Run Task…* kies je **build with GCC** of **build with Clang** (dan moeten `g++`/`clang++` in `PATH` staan, bv. via MSYS2 of LLVM).
3. Draai het resultaat in de terminal:

```powershell
.\rooster.exe
```

Alle tasks bouwen met **C++20** (`-std=c++20` / `/std:c++latest`) en compileren alle `.cpp`-bestanden in de map samen.

### Nieuw oefenproject maken

Kopieer de map van de vorige les, geef hem het volgende lesnummer en vervang `main.cpp`. Build-output
(`*.exe`, `*.obj`, `*.pdb`, `*.ilk`, …) wordt door `.gitignore` buiten git gehouden.
