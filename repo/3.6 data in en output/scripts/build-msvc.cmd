@echo off
rem Bouwt met MSVC zonder dat VS Code via de Developer Command Prompt gestart hoeft te worden.
rem Gebruik: build-msvc.cmd <output.exe> <bronbestanden...>
rem vswhere.exe staat altijd op dezelfde plek, ongeacht VS-versie of -editie.

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
    echo [build-msvc] vswhere.exe niet gevonden. Is Visual Studio of de Build Tools met C++ workload geinstalleerd?
    exit /b 1
)

rem Via tijdelijk bestand i.p.v. "for /f": de haakjes in "Program Files (x86)" breken de for-syntax.
set "VCTMP=%TEMP%\vcvars-path-%RANDOM%.txt"
"%VSWHERE%" -latest -products * -find VC\Auxiliary\Build\vcvars64.bat > "%VCTMP%"
set /p VCVARS=<"%VCTMP%"
del "%VCTMP%" >nul 2>&1
if not defined VCVARS (
    echo [build-msvc] vcvars64.bat niet gevonden. Installeer de workload "Desktop development with C++".
    exit /b 1
)

call "%VCVARS%" >nul 2>&1 || exit /b 1

set "OUT=%~1"
shift
cl.exe /nologo /Zi /std:c++latest /EHsc /Fe:"%OUT%" %1 %2 %3 %4 %5 %6 %7 %8 %9
