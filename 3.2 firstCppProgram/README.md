# C++ template (VS Code, Windows)

Template voor C++20-oefeningen met drie compilers: MSVC (standaard), GCC en Clang.

## Eenmalige setup op een nieuwe laptop

1. **VS Code** + extensie *C/C++* (VS Code stelt die zelf voor via `.vscode/extensions.json`).
2. **MSVC**: Visual Studio 2022 (of Build Tools) met workload *Desktop development with C++*.
   Niet nodig om via de Developer Command Prompt te starten: `scripts/build-msvc.cmd` zoekt zelf `vcvars64.bat` via `vswhere`.
3. **GCC** (optioneel): MinGW-w64, bv. `winget install BrechtSanders.WinLibs.POSIX.UCRT`, en zet de `bin`-map in je PATH.
4. **Clang** (optioneel): `winget install LLVM.LLVM` (zet `C:\Program Files\LLVM\bin` in PATH).

Controle in een gewone terminal:

```powershell
g++ --version
clang++ --version
```

De standaardterminal van dit project is het profiel *PowerShell (MSVC)* (`.vscode/settings.json` + `scripts/dev-shell.ps1`), waarin ook `cl` direct werkt. Een gewone PowerShell buiten VS Code kent `cl` niet; de build-task regelt dat zelf.

## Gebruik

- `Ctrl+Shift+B` bouwt het actieve bestand met MSVC (standaard-task); kies een andere task voor GCC of Clang.
- Het resultaat is `rooster.exe` naast het bronbestand.
