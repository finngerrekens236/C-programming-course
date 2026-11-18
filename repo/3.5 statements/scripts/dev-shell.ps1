# Laadt de Visual Studio Developer-omgeving (cl, link, INCLUDE, LIB) in deze PowerShell-sessie.
# Wordt gebruikt door het terminalprofiel "PowerShell (MSVC)" in .vscode/settings.json.
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (-not (Test-Path $vswhere)) {
    Write-Warning 'vswhere.exe niet gevonden: is Visual Studio / Build Tools met C++ workload geinstalleerd?'
    return
}
$vsPath = & $vswhere -latest -products * -property installationPath
if (-not $vsPath) {
    Write-Warning 'Geen Visual Studio-installatie gevonden.'
    return
}
& (Join-Path $vsPath 'Common7\Tools\Launch-VsDevShell.ps1') -Arch amd64 -HostArch amd64 -SkipAutomaticLocation
