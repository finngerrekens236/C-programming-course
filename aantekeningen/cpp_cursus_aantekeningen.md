# C++ cursus – studieaantekeningen

**Bron:** [C++ Programming Course - Beginner to Advanced](https://www.youtube.com/watch?v=8jLOx1hD3_o) — freeCodeCamp.org, docent Daniel Gakwaya  
**Duur:** 31:07:29 · **Gepubliceerd:** 2022-02-17 · **Hoofdstukken:** 19  
**Compiler voor codeverificatie:** g++ 16.2.0 (MSYS2 UCRT64), `g++ -std=c++20 -Wall -Wextra` — zie `verificatie.md`  
**Taalstandaard:** C++20  
**Bronmateriaal:** automatische Engelse ondertitels (geen handmatige ondertitels beschikbaar); code op het scherm is gereconstrueerd uit de uitleg.

**Legenda:** `> 💡 Aanvulling` = toegevoegd, niet door de docent behandeld · `> ⚠️ Onduidelijk in opname` · `> ℹ️ Gereconstrueerd uit uitleg` · `// ❌ bewust fout` = voorbeeld dat bewust niet compileert of UB toont.

## Inhoud

- [Overzicht van de cursus](#overzicht)
- [Hoofdstuk 1 – Introductie en tools instellen (00:00:00 – 01:43:01)](#h01)
- [Hoofdstuk 2 – Diving in (01:43:01 – 03:00:47)](#h02)
- [Hoofdstuk 3 – Variables and data types (03:00:47 – 04:46:46)](#h03)
- [Hoofdstuk 4 – Operations on data (04:46:46 – 07:01:58)](#h04)
- [Hoofdstuk 5 – Flow control (07:01:58 – 07:53:49)](#h05)
- [Hoofdstuk 6 – Loops (07:53:49 – 08:47:08)](#h06)
- [Hoofdstuk 7 – Arrays (08:47:08 – 09:53:23)](#h07)
- [Hoofdstuk 8 – Pointers (09:53:23 – 12:11:04)](#h08)
- [Hoofdstuk 9 – References (12:11:04 – 12:44:29)](#h09)
- [Hoofdstuk 10 – Character manipulation and strings (12:44:29 – 14:12:47)](#h10)
- [Hoofdstuk 11 – Functions (14:12:47 – 16:03:20)](#h11)
- [Hoofdstuk 12 – Getting things out of functions (16:03:20 – 16:32:35)](#h12)
- [Hoofdstuk 13 – Function overloading (16:32:35 – 16:49:00)](#h13)
- [Hoofdstuk 14 – Lambda functions (16:49:00 – 17:40:08)](#h14)
- [Hoofdstuk 15 – Function templates (17:40:08 – 19:04:31)](#h15)
- [Hoofdstuk 16 – C++20 concepts (19:04:31 – 20:15:40)](#h16)
- [Hoofdstuk 17 – Classes (20:15:40 – 22:52:43)](#h17)
- [Hoofdstuk 18 – Inheritance (22:52:43 – 26:21:03)](#h18)
- [Hoofdstuk 19 – Polymorphism (26:21:03 – 31:07:29)](#h19)
- [C++ Cheatsheet](#cheatsheet)
- [Begrippenlijst](#begrippenlijst)
- [Overzicht valkuilen](#valkuilen)
- [Samenhang](#samenhang)

<a id="overzicht"></a>

## Overzicht van de cursus

### De rode draad

De cursus bouwt C++ op van "hoe krijg ik een programma aan de praat" naar objectgeoriënteerd programmeren met polymorfisme. De docent werkt steeds op dezelfde manier: een concept introduceren met een slide, het in VS Code uittypen, compileren (meestal met GCC, soms ook Clang en MSVC), de output bespreken en vervolgens bewust iets kapotmaken om de compilerfout of het rare gedrag te laten zien. Drie thema's komen telkens terug:

1. **Wat gebeurt er in het geheugen?** Vanaf de variabelen (hoofdstuk 3) wordt steeds gekeken naar `sizeof`, adressen en de memory map (stack, heap, code). Dat mondt uit in pointers en dynamisch geheugen (8), references (9), pass by value/pointer/reference (11), de levensduur van objecten (17) en de layout en grootte van polymorfe objecten (19).
2. **Wanneer weet de compiler wat?** Compile-time versus runtime: `const`/`constexpr`, declaratie versus definitie en de One Definition Rule (11), templates die pas code worden als je ze gebruikt (15), concepts die template-argumenten al bij compilatie controleren (16), en static versus dynamic binding (19).
3. **Code hergebruiken zonder te kopiëren.** Functions (11–13), lambdas (14), templates en concepts (15–16), classes (17), inheritance (18) en polymorfisme (19) zijn achtereenvolgende antwoorden op de vraag hoe je hetzelfde gedrag voor meer gevallen schrijft.

### Leerpad van basis naar gevorderd

| Fase | Hoofdstukken | Wat je kunt na deze fase |
|---|---|---|
| **0. Werkomgeving** | [1](#h01) | Een compiler (GCC/Clang/MSVC) en VS Code installeren en configureren, een C++20-programma bouwen en draaien. |
| **1. Fundament** | [2](#h02), [3](#h03), [4](#h04) | De structuur van een programma, invoer en uitvoer, de fundamentele types en hun grootte, rekenen en vergelijken, output formatteren. |
| **2. Programmaverloop** | [5](#h05), [6](#h06), [7](#h07) | Beslissingen nemen (`if`, `switch`, `?:`), herhalen (`for`, `while`, `do-while`) en reeksen gegevens opslaan in arrays. |
| **3. Geheugen** | [8](#h08), [9](#h09), [10](#h10) | Pointers, `new`/`delete`, de valkuilen van dynamisch geheugen, references, C-strings en `std::string`. |
| **4. Functions** | [11](#h11), [12](#h12), [13](#h13), [14](#h14) | Code opdelen in functions over meerdere bestanden, argumenten doorgeven, resultaten teruggeven, overloading en lambdas. |
| **5. Generiek programmeren** | [15](#h15), [16](#h16) | Function templates schrijven, specialiseren en met C++20 concepts beperken. |
| **6. Objectgeoriënteerd** | [17](#h17), [18](#h18), [19](#h19) | Classes met constructors en destructors, inheritance met access specifiers, en polymorfisme met virtual functions, `override`, `final`, `dynamic_cast` en abstracte classes. |

**Tip bij het studeren:** werk de hoofdstukken in volgorde door, typ de codevoorbeelden zelf over en maak de oefeningen voordat je de uitwerking openklapt. De [cheatsheet](#cheatsheet) en de [begrippenlijst](#begrippenlijst) achterin zijn bedoeld als naslag; het [overzicht valkuilen](#valkuilen) is handig als checklist bij het debuggen.

---

<a id="h01"></a>

## Hoofdstuk 1 – Introductie en tools instellen (00:00:00 – 01:43:01) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=0s)

### Leerdoelen
- Weten wat je van de cursus kunt verwachten: van absolute beginner tot objectgeoriënteerd programmeren (classes, inheritance, polymorphism) in C++20.
- Begrijpen welke twee soorten tools je nodig hebt: een **editor/IDE** en een **compiler**, en wat elk ervan doet.
- Op **Windows** drie compilers installeren: GCC (via MinGW/WinLibs), Clang/LLVM en MSVC (via Visual Studio Community), en ze in de `PATH` zetten.
- Op **Linux** (Ubuntu 20.04) GCC, Clang en GDB installeren via `apt`, en de nieuwste GCC via Homebrew.
- Op **macOS** GCC en LLVM/Clang via Homebrew installeren en Apple Clang via de Xcode command line tools.
- **Visual Studio Code** installeren met de Microsoft C/C++-extensie.
- Een `tasks.json` maken die met elke compiler in C++20-modus *alle* `.cpp`-bestanden van een map bouwt tot één programma `rooster`.
- IntelliSense instellen op C++20 via `c_cpp_properties.json`.
- Een herbruikbaar **template-project** opzetten.
- Online compilers gebruiken (Wandbox, Coliru, Compiler Explorer) om code te testen en te delen.

### Verband met eerdere hoofdstukken
Dit is het eerste hoofdstuk; er is nog geen voorkennis. Alles wat hier wordt ingericht (de compilers, VS Code, `tasks.json` en het template-project) gebruik je in alle volgende hoofdstukken. Hoofdstuk 2 (Diving in) begint meteen met je eerste echte programma in dit template-project. De testcode van dit hoofdstuk (`<=>`, `auto`, `std::cout`) wordt pas later uitgelegd: in hoofdstuk 2 (`std::cout`, statements), 3 (`auto`) en 4 (vergelijkingsoperatoren).

### Uitleg

#### Over de cursus
De cursus is gemaakt voor complete beginners, maar ook iemand met wat C++-ervaring leert er nog iets van. Het eerste en grootste deel gaat over **procedureel** programmeren: programma's die van boven naar beneden worden uitgevoerd. Pas tegen het einde komt **objectgeoriënteerd programmeren** aan bod, met classes, inheritance en polymorphism. De docent besteedt veel aandacht aan de tools: je hoeft vooraf niet te weten wat een compiler of IDE is. Er zijn maar twee vereisten: tijd om te oefenen en de wil om te leren. De code staat in een GitHub-repository en er is een Discord-server voor vragen. De docent raadt aan om daar ook anderen te helpen, omdat je daar zelf veel van leert.

- tijdlink: [▶ 00:00:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=0s)

#### De twee tools: editor/IDE en compiler
Om C++ te schrijven en uit te voeren heb je twee dingen nodig:

1. **Een editor of IDE** (Integrated Development Environment): hierin typ je de code. Een goede editor geeft o.a. syntax highlighting en autocomplete.
2. **Een compiler**: software die je broncode omzet in **binaire, uitvoerbare code** die rechtstreeks op de hardware en het besturingssysteem draait. Op Windows krijg je een `.exe`, op Linux een Linux-binary, enzovoort. Een binary voor het ene besturingssysteem draait dus niet zomaar op een ander.

De werkwijze is steeds: code typen in de editor → compileerproces starten → het programma (de binary) uitvoeren.

**Waarom VS Code?** Het is makkelijk te installeren, werkt op alle platforms (Windows, Linux, macOS), is populair en heeft veel extensies. Andere IDE's kunnen ook (Visual Studio of CodeLite op Windows, Qt Creator of CodeLite op Linux, Xcode of CodeLite op macOS). De docent raadt VS Code toch aan, zodat iedereen dezelfde basis heeft en beginners niet in de war raken.

**Welke compiler?** In de hele cursus is **GCC** de gemeenschappelijke basis. Moet je er maar één installeren, kies dan GCC. De docent raadt wel aan om meerdere compilers te installeren (GCC, Clang, MSVC). Als je code met verschillende compilers werkt, is ze **draagbaarder** (portable) naar andere compilers en besturingssystemen.

| Platform | Compilers in de cursus |
|---|---|
| Windows | GCC via MinGW (WinLibs), Clang/LLVM, MSVC (Microsoft) |
| Linux | GCC, Clang/LLVM |
| macOS | GCC en LLVM/Clang via Homebrew, Apple Clang (Xcode) |

- tijdlink: [▶ 00:04:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=240s)

#### Compilerondersteuning controleren (cppreference)
Niet elke compiler ondersteunt elke C++20-feature even goed. Zoek op **"C++ compiler support"**: je komt dan op de cppreference-pagina met een tabel per standaard (C++20 core features, library features). Per feature zie je of GCC, Clang, MSVC en Apple Clang die ondersteunen en vanaf welke versie. De docent geeft als voorbeeld "lambdas in unevaluated contexts", die op het moment van opname wel in GCC en MSVC werkten maar nog niet in Clang. Werkt iets niet, kijk dan eerst op deze pagina of je compiler het al ondersteunt.

Algemeen advies: installeer altijd de **nieuwste versie** die je kunt krijgen. De docent nam op in 2021 met GCC 11.2.0 en Clang 12.0.1. Kijk je later, dan zijn er nieuwere versies; gebruik die.

- tijdlink: [▶ 00:11:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=676s)

#### Windows: GCC en Clang via WinLibs
**MinGW** is een project dat de GCC-compiler naar Windows brengt. De makkelijkste manier om GCC *en* Clang in één keer te krijgen is **WinLibs** (zoek op "winlibs"):

1. Kies op de site de nieuwste release, de variant **met LLVM/Clang**. Neem de 64-bit versie (op 32-bit Windows de 32-bit versie). Of je het 7-Zip- of het ZIP-archief neemt maakt niet uit.
2. Pak het archief uit. In de map `bin` staan onder andere `gcc.exe`, `g++.exe`, `clang.exe`, `clang++.exe` en `gdb.exe` (de debugger).
3. Zet de uitgepakte map ergens neer, bijvoorbeeld `C:\mingw64`.
4. Zet de map `C:\mingw64\bin` in de **omgevingsvariabele `PATH`**: typ `env` in het Startmenu → *Systeemeigenschappen* → *Omgevingsvariabelen* → `Path` (bij gebruiker of systeem; de docent kiest systeem omdat hij de enige gebruiker is) → *Bewerken* → *Nieuw* → pad plakken → *OK*.

**Waarom de PATH?** Als je in een terminal `g++` typt, zoekt het besturingssysteem in alle mappen uit `PATH` naar `g++.exe`. Zonder die vermelding vindt het de compiler niet.

Testen in een nieuwe opdrachtprompt (`cmd`):

```text
g++ --version
clang++ --version
```

Zie je de versie-informatie, dan werken de installatie en de PATH.

- tijdlink: [▶ 00:13:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=819s)

#### Windows: MSVC via Visual Studio Community
De compiler van Microsoft (**MSVC**, programma `cl.exe`) krijg je door **Microsoft Visual Studio** te installeren. In de opname was dat versie 2019; de gratis **Community**-editie is genoeg.

1. Download en start de *Visual Studio Installer*.
2. Vink de workload **"Desktop development with C++"** aan en klik op *Install*.
3. Wacht. Dit is een grote installatie (20 minuten is normaal), veel groter dan GCC of Clang.

Daarna typ je `developer` in het Startmenu. Je krijgt dan *Developer PowerShell for VS 2019* en *Developer Command Prompt*. In zo'n terminal zijn de omgevingsvariabelen al ingesteld, en als je `cl.exe` typt verschijnt de versie-informatie van de compiler. Krijg je een foutmelding, dan is de installatie niet goed gelukt.

- tijdlink: [▶ 00:20:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=1208s)

#### VS Code installeren (alle platforms)
1. Zoek "Visual Studio Code" en download de versie voor jouw systeem:
   - **Windows**: User of System installer, 64-bit (of 32-bit). Daarna de installer doorklikken.
   - **Linux (Debian/Ubuntu)**: het `.deb`-pakket. Installeren met dubbelklikken of met `sudo dpkg -i <pakket>.deb`.
   - **macOS**: de Mac-download. Sleep de app naar de map *Applications* (Programma's).
2. Open VS Code → tabblad **Extensions** → zoek op `C/C++` → kies de extensie **van Microsoft** → *Install*. Daarna staan er de knoppen *Disable/Uninstall*, wat betekent dat de extensie actief is.

Belangrijke tabbladen links: **Explorer** (bestanden), **Source Control** (git), **Run and Debug** (komt later) en **Extensions**. Door op het actieve tabblad te klikken klap je de zijbalk in of uit.

Vanaf de terminal kun je VS Code in de huidige map openen met:

```text
code .
```

- tijdlink: [▶ 00:24:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=1451s)

#### Het testprogramma (template)
De docent maakt een map voor een template-project, opent die met *Open with Code* en kiest **Trust** bij de vraag of je de map vertrouwt (vertrouw alleen mappen waarvan je weet wat erin staat). Met het plus-icoon maakt hij `main.cpp` aan met een klein testprogramma. Het enige doel is controleren of de compiler **C++20** ondersteunt. Daarvoor gebruikt hij de **spaceship operator** `<=>` (three-way comparison), die nieuw is in C++20. Je hoeft de code nog niet te begrijpen; alles komt later in de cursus terug.

- `10 <=> 20` vergelijkt de twee getallen en geeft een resultaat dat "kleiner", "gelijk" of "groter" betekent.
- `(10 <=> 20) > 0` vraagt: "is 10 groter dan 20?" → `false`.
- `std::cout` print een `bool` als `0` of `1`, dus de uitvoer is **`0`**.

Zie de volledige code onder *Codevoorbeelden*.

- tijdlink: [▶ 00:29:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=1786s)

#### tasks.json: VS Code koppelen aan GCC (Windows)
Een **task** is een set instructies voor VS Code: welke compiler moet hij aanroepen, met welke argumenten, om je project om te zetten in een binary.

1. Menu **Terminal → Configure Tasks...**. VS Code doorzoekt het systeem en toont de gevonden compilers, bijvoorbeeld `C/C++: g++.exe build active file` met het pad `C:\mingw64\bin\g++.exe` en ook `clang++.exe`.
2. Kies **g++**. VS Code maakt de map **`.vscode`** met daarin **`tasks.json`**.
3. Pas het `label` aan naar een beschrijvende naam, bijvoorbeeld `Build with GCC 11.2.0`.
4. Voeg het argument **`-std=c++20`** toe. De docent zocht dit zelf op (via een zoekmachine of Stack Overflow) en raadt aan om dat ook zo te doen. Let op de komma's tussen de elementen, anders is de JSON ongeldig.
5. **Terminal → New Terminal** om een terminal te openen. Selecteer `main.cpp` in de editor en kies **Terminal → Run Task... → Build with GCC 11.2.0**.
6. De build lukt en er verschijnt `main.exe`. Typ in de terminal `clear` en daarna `./main.exe`. De uitvoer is `0`, en daarmee werkt de koppeling.

Daarna vervangt de docent de argumenten door de configuratie die hij voor al zijn projecten gebruikt:
- compileren in C++20-modus;
- **alle `.cpp`-bestanden** in de projectmap compileren (`${workspaceFolder}\\*.cpp`), zodat projecten met meerdere bestanden ook werken;
- de binary een vaste naam geven: **`rooster.exe`**. De docent gebruikt die naam in de hele cursus en raadt aan hetzelfde te doen.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Build with GCC 11.2.0",
            "command": "C:\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "-std=c++20",
                "${workspaceFolder}\\*.cpp",
                "-o",
                "${fileDirname}\\rooster.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": "build",
            "detail": "compiler: C:\\mingw64\\bin\\g++.exe"
        }
    ]
}
```

Na het opslaan verwijdert hij de oude binary (`dir` om de inhoud te zien, `rm main.exe` om te verwijderen), bouwt opnieuw en voert `./rooster.exe` uit. Tip: typ het begin van een bestandsnaam en druk op **Tab**, dan vult de terminal de naam aan.

**Waar komt deze kennis vandaan?** In het tabblad Extensions → C/C++ staan links naar officiële tutorials: *MSVC on Windows*, *MinGW on Windows*, *GCC on Linux* en *Clang on macOS*. Lees de tutorial voor jouw platform. Daar staat ook dat je met `gdb --version` kunt controleren of de debugger beschikbaar is.

- tijdlink: [▶ 00:31:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=1885s)

#### tasks.json: Clang toevoegen (Windows)
Dit is dezelfde procedure: **Terminal → Configure Tasks...** → kies `clang++.exe`. Er komt een **tweede** entry bij in dezelfde `tasks.json`. Geef die het label `Build with Clang++ 12.0.1` en kopieer de `args` van de GCC-task. Clang accepteert dezelfde opties als GCC. Voer daarna `rm rooster.exe` uit en kies **Run Task → Build with Clang**. Het resultaat is weer `rooster.exe`, en die print `0`.

Via **Run Task** kies je nu zelf welke compiler je gebruikt.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```json
{
    "type": "cppbuild",
    "label": "Build with Clang++ 12.0.1",
    "command": "C:\\mingw64\\bin\\clang++.exe",
    "args": [
        "-g",
        "-std=c++20",
        "${workspaceFolder}\\*.cpp",
        "-o",
        "${fileDirname}\\rooster.exe"
    ],
    "options": {
        "cwd": "${fileDirname}"
    },
    "problemMatcher": ["$gcc"],
    "group": "build"
}
```

- tijdlink: [▶ 00:41:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=2513s)

#### tasks.json: MSVC toevoegen (Windows)
MSVC werkt anders. In een gewone terminal geeft `cl.exe` de fout dat het commando niet herkend wordt, omdat MSVC **niet** in de `PATH` staat. Dat is een bewuste keuze van Microsoft: je kunt meerdere Visual Studio-versies naast elkaar hebben, en via de juiste *Developer PowerShell* kies je zelf welke compiler actief is.

De oplossing is VS Code **starten vanuit een Developer PowerShell**:
1. Sluit VS Code.
2. Open *Developer PowerShell for VS 2019*. De docent geeft de voorkeur aan PowerShell boven de Command Prompt, omdat het meer commando's ondersteunt (zoals `ls`).
3. Ga met `cd <pad-naar-project>` naar je projectmap.
4. Typ `code .`. VS Code erft nu de omgevingsvariabelen van MSVC, en in de terminal van VS Code werkt `cl.exe` wel.
5. Kies **Terminal → Configure Tasks... → `cl.exe build active file`**. Er komt een derde entry bij. Geef die het label `Build with MSVC` en vervang de argumenten.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```json
{
    "type": "cppbuild",
    "label": "Build with MSVC",
    "command": "cl.exe",
    "args": [
        "/Zi",
        "/std:c++latest",
        "/EHsc",
        "/nologo",
        "/Fe${fileDirname}\\rooster.exe",
        "${workspaceFolder}\\*.cpp"
    ],
    "options": {
        "cwd": "${fileDirname}"
    },
    "problemMatcher": ["$msCompile"],
    "group": "build"
}
```

Bij MSVC zijn de opties anders: `/std:c++latest` (de nieuwste standaard), `/Fe...` voor de naam van het uitvoerbestand en het invoerpatroon `*.cpp`. Na **Run Task → Build with MSVC** print `rooster` weer `0`. Je kunt de code nu met drie compilers bouwen.

> 💡 Aanvulling: in nieuwere MSVC-versies bestaat ook `/std:c++20`. `/std:c++latest` zet ook experimentele features van de nog nieuwere standaard aan.

- tijdlink: [▶ 00:45:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=2707s)

#### IntelliSense instellen: c_cpp_properties.json
Compileren loopt via `tasks.json`, maar de **editor zelf** (IntelliSense: autocomplete, rode kronkellijnen onder fouten) heeft zijn eigen instellingen. Ga naar **View → Command Palette** → typ `C/C++` → kies **C/C++: Edit Configurations (UI)**. Hier stel je in:
- **Compiler path**: welke compiler IntelliSense gebruikt om je code te analyseren (MSVC, g++ of clang++);
- **IntelliSense mode**: bijvoorbeeld `windows-msvc-x64` op Windows of `linux-gcc-x64` op Linux;
- **C++ standard**: zet dit op **`c++20`**.

VS Code bewaart dit in `.vscode/c_cpp_properties.json`. Op Linux zag je dat de kronkellijnen onder `<=>` verdwenen zodra de standaard op C++20 stond: de editor "begrijpt" de code dan.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": ["${workspaceFolder}/**"],
            "compilerPath": "cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++20",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
```

- tijdlink: [▶ 00:53:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=3187s)

#### Het template-project opruimen en hergebruiken
MSVC laat extra bestanden achter: `rooster.exe`, `.pdb` (debuginformatie), `main.obj` (objectbestand) en `.ilk`. De docent verwijdert die met `rm`, maar laat `main.cpp` en de map `.vscode` staan. Daarna hernoemt hij de map naar **`C++20 template project`** (sluit VS Code eerst, anders klaagt Windows dat de map in gebruik is).

Voor elk nieuw project kopieer je deze map en geef je de kopie een nieuwe naam. Alle compilerconfiguratie werkt dan meteen.

- tijdlink: [▶ 00:55:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=3328s)

#### Linux: GCC, Clang en GDB installeren (Ubuntu 20.04)
Met `uname -a` zie je informatie over je systeem. Gebruik je een andere distributie, dan pas je de commando's daaraan aan.

- GCC 11 zat op het moment van opname nog niet in de Ubuntu 20.04-pakketten (`sudo apt-get install gcc-11` geeft "unable to locate"). De beste versie via apt was **GCC 10**:

```text
sudo apt-get install gcc-10
sudo apt-get install g++-10
sudo apt-get install gdb
sudo apt-get install clang-12
```

- Controleren: `gcc-10 --version`, `g++-10 --version`, `gdb --version`.
- De compilers staan in `/usr/bin`. Met `ls` zie je daar bijvoorbeeld `clang-10`, `clang-11`, `clang-12` en de bijbehorende `clang++`-varianten.
- **De nieuwste GCC via Homebrew**: Homebrew is een package manager die ook op Linux werkt. Installeer het met het commando van de Homebrew-website (kopiëren en in de terminal plakken). Daarna:

```text
brew install gcc
```

  Dit duurt even en levert de nieuwste GCC op (bij de docent `gcc-11` / `g++-11`, versie 11.2). Zo hoef je de compiler niet zelf te bouwen, wat ingewikkeld is.

- tijdlink: [▶ 00:57:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=3425s)

#### Linux: VS Code configureren
1. `mkdir cpp20_template_project` (de docent vermijdt `+`-tekens in de mapnaam voor de zekerheid), `cd` naar die map en `code .` → **Trust**.
2. Maak `main.cpp` met hetzelfde testprogramma.
3. **Terminal → Configure Tasks...**: VS Code vindt onder andere clang-10/11/12 en g++-10/11. Kies **g++-11** (van Homebrew). g++-10 werkt voor het grootste deel van de cursus ook.
4. Geef de task het label `Build with GCC 11.2.0` en voer de task uit **zonder** `-std=c++20`. De build mislukt: de compiler kent `<=>` niet. De docent liet deze fout bewust zien, omdat veel mensen deze stap vergeten.
5. Voeg `-std=c++20` toe en bouw opnieuw. Dan lukt het: `ls` toont `main`, en `./main` print `0`. Op Linux heeft een binary geen `.exe`.
6. Vervang de argumenten door de "alle `.cpp`-bestanden → `rooster`"-configuratie, aangepast voor Linux (`/` als scheidingsteken, geen `.exe`).

> ⚠️ Onduidelijk in opname: de docent zegt dat hij de padscheidingstekens aanpast en noemt ze "backslashes". In de Linux-documentatie van VS Code (en op Linux in het algemeen) zijn dat **forward slashes** `/`. Die staan hieronder.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```json
{
    "type": "cppbuild",
    "label": "Build with GCC 11.2.0",
    "command": "/home/linuxbrew/.linuxbrew/bin/g++-11",
    "args": [
        "-g",
        "-std=c++20",
        "${workspaceFolder}/*.cpp",
        "-o",
        "${fileDirname}/rooster"
    ],
    "options": {
        "cwd": "${fileDirname}"
    },
    "problemMatcher": ["$gcc"],
    "group": "build"
}
```

7. Voeg op dezelfde manier een task toe voor **clang++-12**, met dezelfde `args`. `clang++-12 --version` gaf bij de docent versie 12.0.0, dus het label wordt `Build with Clang 12.0.0`. VS Code kan in de lijst van *Run Task* dubbele items tonen; kies het item met jouw label.
8. Stel IntelliSense op C++20 in (Command Palette → *C/C++: Edit Configurations (UI)*). De compiler blijft op de standaard (gcc-11) staan.
9. Ook hier geldt: gebruik deze map als template en kopieer hem voor elk nieuw project.

- tijdlink: [▶ 01:07:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=4053s)

#### macOS: compilers en VS Code
De docent had geen Mac. Hij beschrijft de stappen en toont ze op Linux/WSL.

- **Command line tools / Xcode**: voer in de macOS-terminal het commando uit de DigitalOcean-handleiding uit (`xcode-select --install`). Dat installeert de bouwtools en **Apple Clang**. Je kunt ook Xcode installeren via de App Store.
- **Homebrew** installeren met het commando van brew.sh (kopiëren en plakken, wachtwoord invullen, geduld hebben).
- Daarna:

```text
brew install gcc
brew install llvm
```

  Homebrew installeert alles onder `/usr/local` (op Apple Silicon `/opt/homebrew`). Daar vind je de binaries.
- VS Code: de Mac-download naar *Applications* slepen en de C/C++-extensie installeren.
- Configureren: maak een map (bijvoorbeeld `cpp_template_project`), open die met `code .`, maak `main.cpp` en kies **Terminal → Configure Tasks...**. Waarschijnlijk wordt eerst **Apple Clang** (`/usr/bin/clang++`) gevonden. Zet in de args `-std=c++20` en de "alle `.cpp` → `rooster`"-configuratie. Wil je de Homebrew-versie van Clang of GCC gebruiken, controleer dan of het pad in `command` naar `/usr/local/...` wijst en niet naar `/usr/bin` (dat is Apple's Clang). Zie de tutorial *Using Clang in VS Code on macOS* in de extensie.

> 💡 Aanvulling: in `/usr/bin` staat op macOS ook een `gcc`, maar dat is een alias voor Apple Clang. De echte GCC van Homebrew heet `gcc-<versie>` / `g++-<versie>`, bijvoorbeeld `g++-11`.

- tijdlink: [▶ 01:22:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=4928s)

#### Online compilers
Kun je (nog) niets installeren, of wil je snel iets testen of delen, gebruik dan een online compiler. Die ziet eruit als een IDE in de browser: je typt code, het programma wordt op een server gecompileerd en je ziet de uitvoer.

- **Wandbox** (wandbox.org): veel versies van GCC en Clang, te kiezen in een lijst. Je kunt ook bibliotheken laden (bijvoorbeeld Boost). Met **Share** krijg je een URL die je naar iemand stuurt (bijvoorbeeld je docent), die dan dezelfde code ziet en kan uitvoeren. Handig als je hulp nodig hebt.
- **Coliru**: eenvoudig, geen keuze in compiler (g++), knop *Compile, Link and Run*.
- **Compiler Explorer** (godbolt.org): eigenlijk bedoeld om de **assembly** te bekijken die de compiler van je code maakt (gevorderd). Je kunt het ook gebruiken om code met veel compilers te testen: GCC, Clang en zelfs MSVC. Belangrijk:
  - Vul de **compilervlaggen** zelf in, bijvoorbeeld `-std=c++20`. Een fout als `-std=hello` geeft `unrecognized command line option`.
  - Zet **"Run the compiled output"** aan (bij *Execution*), anders zie je geen programma-uitvoer.
  - Ook hier kun je een deellink maken. De docent opent die in een privévenster en ziet dezelfde code.

- tijdlink: [▶ 01:35:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=5702s)

### Codevoorbeelden

#### C++20-testprogramma (template `main.cpp`) [▶ 00:29:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=1786s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // <=> (spaceship operator) bestaat pas sinds C++20:
    // compileert dit, dan staat je compiler in C++20-modus.
    auto result = (10 <=> 20) > 0;   // is 10 groter dan 20? -> false
    std::cout << result << std::endl; // bool wordt als 0/1 geprint
    return 0;
}
```
```text
0
```

#### Wandbox: een boodschap toevoegen [▶ 01:37:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=5849s)
De docent voegt in Wandbox een regel toe om te laten zien dat de online compiler echt draait.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
    std::cout << "Hello there" << std::endl; // extra regel om de uitvoer te testen
    return 0;
}
```
```text
0
Hello there
```

#### Coliru: "The sky is blue" [▶ 01:39:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=5944s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
    std::cout << "The sky is blue" << std::endl;
    return 0;
}
```
```text
0
The sky is blue
```

#### Compiler Explorer: "The sky is white" [▶ 01:40:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6041s)
In Compiler Explorer gebruikt de docent GCC 10.2 met de vlag `-std=c++20`. Daarna haalt hij één regel weg om te laten zien dat de code automatisch opnieuw wordt gecompileerd. Hieronder staat de versie met beide regels.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
    std::cout << "The sky is white" << std::endl;
    return 0;
}
```
```text
0
The sky is white
```

### Valkuilen & veelgemaakte fouten

#### `-std=c++20` vergeten
Zonder deze vlag (of met een oudere standaard) kent de compiler `<=>` niet, en mislukt de build van het testprogramma. Bij MSVC is de vlag `/std:c++latest` of `/std:c++20`. De docent liet dit op Linux bewust zien, omdat veel mensen deze stap vergeten.

#### Compiler niet gevonden (`PATH`)
`'g++' is not recognized...` of `command not found` betekent dat de `bin`-map van de compiler niet in `PATH` staat, of dat je terminal (of VS Code) nog vóór de wijziging was geopend. Open dan een nieuwe terminal of herstart VS Code.

#### `cl.exe` werkt niet in een gewone terminal
Dat is normaal. MSVC staat niet in de `PATH`. Start VS Code met `code .` vanuit een **Developer PowerShell / Developer Command Prompt**, anders kan de MSVC-task de compiler niet vinden.

#### Verkeerd bestand actief bij Run Task
De standaardtask gebruikt variabelen als `${fileDirname}`. Zorg dat `main.cpp` (een bestand in het project) geselecteerd is in de editor voordat je **Run Task** kiest, en niet bijvoorbeeld `tasks.json`.

#### Ongeldige JSON in tasks.json
Een vergeten komma tussen twee argumenten, of tussen twee tasks, maakt het bestand ongeldig. VS Code toont dan een foutmelding of vindt je task niet.

#### Verkeerde vlag in een online compiler
In Compiler Explorer ben je zelf verantwoordelijk voor de vlaggen. Met een ongeldige optie krijg je bijvoorbeeld:

```text
error: unrecognized command line option '-std=hello'
```

Zie je geen uitvoer, controleer dan of "Run the compiled output" aanstaat.

#### Pad- en naamverschillen tussen platforms
Op Windows heet de binary `rooster.exe` en gebruik je `\\` in de JSON-paden. Op Linux/macOS heet hij `rooster` (geen extensie), gebruik je `/` en voer je hem uit met `./rooster`. Vermijd voor de zekerheid speciale tekens zoals `+` in mapnamen.

#### Verkeerde Clang op macOS
`/usr/bin/clang++` is Apple Clang en niet de Homebrew-LLVM. Controleer het pad in `command` als je een specifieke compiler wilt gebruiken.

#### Oude GCC uit de pakketbron
Ubuntu 20.04 levert standaard geen GCC 11. Gebruik `gcc-10`/`g++-10` of installeer de nieuwste versie via Homebrew. Oudere compilers missen C++20-features (zie de pagina "C++ compiler support").

### Best practices
- Installeer de **nieuwste** compilerversies die je kunt krijgen.
- Installeer **meerdere compilers** (GCC, Clang, MSVC) en test je code met elk ervan. Dat verhoogt de draagbaarheid.
- Gebruik GCC als gemeenschappelijke basis als je maar één compiler installeert.
- Geef tasks een **beschrijvend label** met compiler en versie, bijvoorbeeld `Build with GCC 11.2.0`.
- Laat de task **alle `.cpp`-bestanden** in de map compileren met een vaste uitvoernaam (`rooster`), zodat projecten met meerdere bestanden zonder extra werk bouwen.
- Zet zowel de **compiler** (`tasks.json`) als **IntelliSense** (`c_cpp_properties.json`) op **C++20**.
- Werk met een **template-project** en kopieer dat voor elk nieuw project.
- Zoek zelf in de documentatie (C/C++-extensietutorials, cppreference, zoekmachine). Zo kwam de docent ook aan zijn configuratie.
- Vertrouw (Trust) in VS Code alleen mappen waarvan je de inhoud kent.
- Gebruik bij problemen een online compiler en stuur de **deellink** naar wie je helpt.

### Samenvatting
- Je hebt een **editor/IDE** (VS Code + Microsoft C/C++-extensie) en een **compiler** nodig. De compiler zet broncode om in een binary voor jouw besturingssysteem.
- Windows: GCC + Clang via **WinLibs** (map `bin` in `PATH`), en MSVC via **Visual Studio Community** ("Desktop development with C++").
- Linux: `apt-get install g++-10 clang-12 gdb`, en de nieuwste GCC via **Homebrew** (`brew install gcc`).
- macOS: `xcode-select --install` (Apple Clang), en `brew install gcc` / `brew install llvm`.
- **Terminal → Configure Tasks** maakt `.vscode/tasks.json`. Per compiler voeg je een task toe met `-std=c++20`, `*.cpp` als invoer en `rooster` als uitvoer.
- MSVC staat niet in de `PATH`: start VS Code vanuit een **Developer PowerShell** met `code .`.
- **C/C++: Edit Configurations (UI)** → `c_cpp_properties.json` zet IntelliSense op C++20.
- Het testprogramma met `(10 <=> 20) > 0` print `0` als alles goed is ingesteld.
- Online compilers: **Wandbox**, **Coliru** en **Compiler Explorer**, handig om te testen en te delen. Vul de juiste vlaggen zelf in.

### Oefeningen
1. Kopieer je template-project naar een nieuwe map `oefening1`. Laat `main.cpp` naast de `0` ook `Hello World` op een nieuwe regel printen. Bouw het project met minstens twee verschillende compilers via **Run Task**.
2. Pas het testprogramma aan zodat het vraagt of **20** groter is dan **10** (`(20 <=> 10) > 0`). Wat print het programma nu? Laat daarna met `std::boolalpha` het woord `true` printen in plaats van `1`.
3. Controleer welke C++-standaard je compiler echt gebruikt door de voorgedefinieerde macro `__cplusplus` te printen. Voor C++20 is de waarde `202002`. Probeer daarna in Compiler Explorer `-std=c++17`: welke waarde krijg je dan?
4. Test of je `tasks.json` echt **alle** `.cpp`-bestanden compileert. Maak een tweede bestand `extra.cpp` met een functie `print_extra()` die `Hallo vanuit extra.cpp` print. Declareer die functie in `main.cpp` en roep hem aan. Bouw het project zonder `tasks.json` aan te passen.
5. Schrijf in `tasks.json` een extra task `Build with Clang (debug off)` die hetzelfde doet als je Clang-task, maar zonder `-g` en met de extra waarschuwingsvlaggen `-Wall -Wextra`.

<details><summary>Uitwerking</summary>

**Oefening 1**
```cpp
#include <iostream>

int main() {
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
    std::cout << "Hello World" << std::endl;
    return 0;
}
```
```text
0
Hello World
```

**Oefening 2**
```cpp
#include <iostream>

int main() {
    auto result = (20 <=> 10) > 0;              // 20 is groter dan 10 -> true
    std::cout << result << std::endl;           // standaard: 1
    std::cout << std::boolalpha << result << std::endl; // nu: true
    return 0;
}
```
```text
1
true
```

**Oefening 3** (met `-std=c++20`; met `-std=c++17` krijg je `201703`)
```cpp
#include <iostream>

int main() {
    // __cplusplus geeft de C++-standaard waarin de compiler compileert
    std::cout << __cplusplus << std::endl;
    return 0;
}
```
```text
202002
```

> 💡 Aanvulling: MSVC geeft voor `__cplusplus` standaard `199711`, tenzij je ook de vlag `/Zc:__cplusplus` meegeeft.

**Oefening 4**: het tweede bestand (geen `main`):
```cpp
// file: extra.cpp
#include <iostream>

void print_extra() {
    std::cout << "Hallo vanuit extra.cpp" << std::endl;
}
```

En `main.cpp`, dat samen met `extra.cpp` wordt gecompileerd (dat doet `${workspaceFolder}/*.cpp` in je task):
```cpp
// multi: main.cpp extra.cpp
#include <iostream>

void print_extra(); // declaratie: de definitie staat in extra.cpp

int main() {
    std::cout << "Hallo vanuit main.cpp" << std::endl;
    print_extra();
    return 0;
}
```
```text
Hallo vanuit main.cpp
Hallo vanuit extra.cpp
```

**Oefening 5**: de extra entry in de array `tasks` (Windows-paden):
```json
{
    "type": "cppbuild",
    "label": "Build with Clang (debug off)",
    "command": "C:\\mingw64\\bin\\clang++.exe",
    "args": [
        "-std=c++20",
        "-Wall",
        "-Wextra",
        "${workspaceFolder}\\*.cpp",
        "-o",
        "${fileDirname}\\rooster.exe"
    ],
    "options": {
        "cwd": "${fileDirname}"
    },
    "problemMatcher": ["$gcc"],
    "group": "build"
}
```

</details>

---

<a id="h02"></a>

## Hoofdstuk 2 – Diving in (01:43:01 – 03:00:47) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6181s)

### Leerdoelen
- De opbouw van een eerste C++-programma begrijpen: `#include`, de `main`-functie, statements en `return 0`.
- Tekst en waarden naar de console schrijven met `std::cout` en een nieuwe regel afdrukken met `std::endl`.
- Commentaar schrijven met `//` (regelcommentaar) en `/* ... */` (blokcommentaar), en weten waarom blokcommentaar niet genest mag worden.
- Het verschil kennen tussen compile-time errors, runtime errors en warnings.
- Weten wat een statement is, dat statements van boven naar beneden worden uitgevoerd en dat ze met een puntkomma eindigen.
- Een eenvoudige functie definiëren (returntype, naam, parameters, body) en die meerdere keren aanroepen.
- Gegevens inlezen met `std::cin`, invoer ketenen en regels met spaties lezen met `std::getline`; het doel van `std::cerr` en `std::clog` kennen.
- Een vereenvoudigd beeld hebben van hoe een programma in het geheugen (RAM) wordt geladen en statement voor statement door de CPU wordt uitgevoerd, inclusief een functieaanroep met een return-adres.
- Het verschil kunnen uitleggen tussen de core language, de standard library en de STL.

### Verband met eerdere hoofdstukken
In hoofdstuk 1 zijn de tools geïnstalleerd (VS Code, GCC/Clang/MSVC) en is een **C++20-templateproject** opgezet met een `main.cpp` en een `.vscode`-map met `tasks.json`. Dat template is het vertrekpunt voor elk project in dit hoofdstuk: de docent kopieert telkens `main.cpp` en de map `.vscode` naar een nieuwe projectmap, opent die map in VS Code, verwijdert de `consteval`-testfunctie (die alleen diende om te controleren of de compiler C++20 ondersteunt) en bouwt met de task "build with GCC". Het resultaat is telkens `rooster.exe`, dat in de terminal wordt uitgevoerd. In hoofdstuk 3 gaan we dieper in op variabelen en datatypes, die hier al informeel opduiken (`int`, `std::string`).

### Uitleg

#### Projectopzet vanuit het template
De docent begint elk onderwerp met dezelfde routine:
1. Kopieer `main.cpp` en de map `.vscode` uit het C++20-templateproject naar een nieuwe map (bijvoorbeeld "first C++ program", "comments", "errors and warnings", ...). Overbodige bestanden uit het template (een oude `.exe`, een `vc140`-bestand) laat je weg.
2. Open VS Code (de docent doet dat vanuit de *Developer PowerShell* zodat ook de MSVC-compiler beschikbaar is), sluit de vorige map via *File → Close Folder* en open de nieuwe via *File → Open Folder*.
3. Bouw via *Terminal → Run Task → build with GCC* (of de standaard-buildtask met `Ctrl+Shift+B`).
4. Open een terminal (*Terminal → New Terminal*), controleer met `dir` dat `rooster.exe` bestaat en start het programma met `./rooster.exe`. Met de pijl-omhoogtoets haal je het vorige commando terug; met `rm rooster.exe` verwijder je het bestand; `clear` maakt de terminal leeg.

[▶ 01:43:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6186s)

#### `#include <iostream>` – voorgebouwde functionaliteit laden
De eerste regel van het programma is `#include <iostream>`. Daarmee laad je een voorgebouwde bibliotheek in je programma; `iostream` zorgt er onder meer voor dat je tekst naar de console kunt schrijven. Het printen gebeurt met:

```
std::cout << "Hello World" << std::endl;
```

- `std::cout` is het uitvoerkanaal naar de console; `std::` geeft aan dat het uit de standaardbibliotheek komt.
- `<<` (twee kleiner-dantekens) stuurt gegevens naar `std::cout`.
- `std::endl` zet een nieuwe regel.
- De regel eindigt met een puntkomma.

Om te laten zien wat `#include` doet, haalt de docent de regel weg. VS Code toont dan rode kronkellijnen en in het tabblad *Problems* meldingen als "namespace std has no member cout" en "namespace std has no member endl": de compiler weet niet waar `cout` en `endl` vandaan komen. Zet je de include terug, dan verdwijnen de fouten.

Let op: achter een `#include`-regel staat **geen** puntkomma, terwijl de meeste andere C++-statements er wel een nodig hebben.

[▶ 01:46:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6377s)

> 💡 Aanvulling: `#include` is een *preprocessor-directive*, geen gewoon statement. Daarom hoort er geen puntkomma achter.

#### De `main`-functie – het entry point
`int main() { ... }` is de **main-functie**. Een functie is een blok code dat een taak uitvoert; `main` is bijzonder omdat het het **startpunt** (entry point) van je programma is. Start je het programma, dan wordt `main` als eerste uitgevoerd, en de statements daarin lopen **in volgorde van boven naar beneden**. Het programma eindigt wanneer de afsluitende accolade van `main` is bereikt.

De docent laat dit zien door "Number1", "Number2" en "Number3" te printen. Zonder `std::endl` na een regel komt de volgende tekst er direct achter op dezelfde regel ("Number2Number3"); pas met een `std::endl` erachter verschijnt elke tekst op een eigen regel.

Je kunt ook `return 0;` aan het einde van `main` zetten. Daarmee geeft `main` aan het besturingssysteem door of het programma succesvol is afgesloten (0) of dat er een probleem was. Meer details over functies volgen later in de cursus.

[▶ 01:48:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6522s) · [▶ 01:50:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6619s) · [▶ 01:53:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6811s)

> 💡 Aanvulling: laat je `return 0;` in `main` weg, dan doet de compiler alsof het er staat. Dat geldt alleen voor `main`; andere functies met een returntype moeten expliciet iets teruggeven.

#### Commentaar
Commentaar is tekst in je code die bedoeld is voor **mensen**; de compiler negeert het volledig. C++ kent twee vormen:
- **Regelcommentaar**: `// ...` – alles vanaf `//` tot het einde van de regel wordt genegeerd. Je mag het overal zetten: boven een statement, achter een statement, zelfs na `return`.
- **Blokcommentaar**: `/* ... */` – alles tussen `/*` en `*/` wordt genegeerd, ook over meerdere regels. Handig om een stuk tekst of een blok code tijdelijk "uit te zetten".

In VS Code verschijnt commentaar groen; het programma bouwt en draait precies hetzelfde alsof die regels er niet stonden.

**Blokcommentaar mag je niet nesten.** Zet je een `/* ... */` binnen een ander `/* ... */`, dan sluit de eerste `*/` het hele commentaar al af en blijft de rest als "code" achter, wat verwarrende compilerfouten oplevert. Tot slot: gebruik commentaar verstandig en overdrijf niet, anders wordt je programma "een roman".

[▶ 01:55:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6955s) · [▶ 01:59:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7198s)

#### Errors en warnings
Het doel van iedere C++-ontwikkelaar is een uitvoerbaar binair bestand maken uit de broncode. De compiler legt daarbij **regels** op; breek je die regels, dan krijg je problemen in drie vormen:

1. **Compile-time error** – de code voldoet niet aan de regels van de taal, bijvoorbeeld een vergeten puntkomma na een `std::cout`-statement. De compilatie **mislukt**, er komt géén executable, en je moet eerst de fout oplossen. GCC meldt in dit geval iets als `expected ';' before 'return'`. Andere IDE's/compilers formuleren de melding anders. Fouten zie je in de terminal en in het tabblad *Problems* van VS Code.
2. **Runtime error** – de compilatie slaagt, maar tijdens het uitvoeren doet het programma niet wat je bedoelde (een logische fout, bv. grijs printen waar groen bedoeld was). Soms laat een runtime error het programma meteen stoppen: het programma **crasht**.
3. **Warning** – een probleem dat niet ernstig genoeg is om de compilatie te stoppen. Je krijgt wél een executable, maar de compiler waarschuwt dat iets verkeerd kan aflopen. Los warnings op voordat ze serieuze problemen worden.

De demo van de docent: `7 / 0` (deling door nul). GCC bouwt het programma, maar meldt een warning ("division by zero"). VS Code kleurt `main.cpp` geel in de verkenner. Zolang het resultaat niet gebruikt wordt, lijkt het programma gewoon te werken. Zodra hij het resultaat opslaat in `int value = 7 / 0;` en print, loopt het programma vast: "Hello World" verschijnt nog, maar bij het printen van `value` stopt het abrupt. Dat is een runtime error (crash).

Een compile-time error is eigenlijk goed nieuws: de compiler voorkomt dat je een programma maakt dat niet werkt. Een runtime error is erger, omdat de compiler je niet tegenhoudt.

[▶ 02:01:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7293s) · [▶ 02:06:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7585s) · [▶ 02:07:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7678s) · [▶ 02:10:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7823s)

> 💡 Aanvulling: een gehele deling door nul is in C++ *undefined behavior*. Op Windows/x86 leidt het meestal tot een crash ("integer divide by zero"), maar de standaard garandeert niets: het programma mag eender wat doen.

#### Statements
Een **statement** is de basiseenheid van berekening in C++: het kleinste stuk dat je programma uitvoert. Elk C++-programma is een verzameling statements die op een bepaalde manier georganiseerd zijn. Elk statement eindigt met een **puntkomma**; vergeet je die, dan krijg je een compile-time error.

In het voorbeeld van de slides:
```
int first_number {12};
int second_number {9};
int sum = first_number + second_number;
std::cout << "The sum of the two numbers is : " << sum << std::endl;
return 0;
```
Elke regel is een statement. Ze worden **in volgorde** uitgevoerd: eerst wordt 12 in het geheugen gezet, dan 9, dan de som berekend, dan geprint, tot `return` het programma beëindigt en de returnwaarde naar het besturingssysteem gaat. Een statement staat meestal op één regel, maar mag ook over meerdere regels verspreid zijn.

[▶ 02:12:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7967s)

#### Variabelen (eerste kennismaking)
Variabelen zijn nog niet officieel behandeld, maar de docent gebruikt ze al: een variabele is een benoemde plek waar je gegevens bewaart. `int` betekent "geheel getal" (zonder decimalen, zoals 1, 7 of 10). Het voordeel: als je de waarde van een variabele wijzigt (bv. `first_number` van 3 naar 13), dan neemt de rest van het programma automatisch de nieuwe waarde over; je hoeft de `std::cout`-statements niet aan te passen.

[▶ 02:19:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8395s) · [▶ 02:22:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8540s)

#### Functies
Een **functie** is als een machine: je geeft input, je krijgt output. Twee getallen optellen kun je zien als een machine met twee getallen als input en de som als output (de *returnwaarde*).

Syntax van een functiedefinitie:
```
int add_numbers(int first_param, int second_param)
{
    int result = first_param + second_param;
    return result;
}
```
- `int` links: het **returntype** (wat de functie teruggeeft).
- `add_numbers`: de **naam** (vrij te kiezen).
- `(int first_param, int second_param)`: de **parameterlijst**, de input. Van elke parameter geef je eerst het type en dan de naam.
- `{ ... }`: de **body**, de statements die de functie uitvoert.
- `return result;` geeft het resultaat terug aan wie de functie aanriep.

Aanroepen gaat met `sum = add_numbers(25, 7);`. Je kunt variabelen of letterlijke getallen meegeven, en je kunt een aanroep ook rechtstreeks in een `std::cout`-statement zetten: `std::cout << add_numbers(3, 42);`. Het grote voordeel van functies is **hergebruik**: je roept dezelfde code meerdere keren aan zonder de statements opnieuw te schrijven.

Belangrijk: een functie moet **gedefinieerd zijn vóór ze gebruikt wordt**. Daarom staat `add_numbers` boven `main`.

[▶ 02:15:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8154s) · [▶ 02:16:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8202s) · [▶ 02:23:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8636s) · [▶ 02:28:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8927s)

> 💡 Aanvulling: strikt genomen moet een functie vóór gebruik *gedeclareerd* zijn; de definitie mag ook later of in een ander bestand staan. Dat komt aan bod in hoofdstuk 11 (declaratie versus definitie).

#### Uitvoer: `std::cout`, `std::cerr`, `std::clog`
Zie `std::cout` als een **snelweg** van je programma naar de terminal. De `<<`-tekens wijzen naar links, naar `std::cout`: de gegevens stromen van je programma in de stream. Je kunt er tekst, getallen en variabelen naartoe sturen.

Naast `std::cout` zijn er nog twee uitvoerstreams:
- `std::cerr` – voor **foutmeldingen**.
- `std::clog` – voor **logberichten**.

Ze werken op dezelfde manier (stream-output-operator `<<`). Waarom aparte streams? Zo kun je je bedoeling uitdrukken: een programma of terminal kan foutmeldingen bijvoorbeeld rood kleuren, en logberichten naar een bestand of database sturen. In de gewone terminal zie je ze er gewoon tussen staan.

[▶ 02:31:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9074s) · [▶ 02:32:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9170s) · [▶ 02:40:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9601s)

> 💡 Aanvulling: `std::cerr` en `std::clog` schrijven allebei naar de *standard error*-stream (stderr), `std::cout` naar *standard output* (stdout). Je kunt ze daardoor in de shell apart omleiden. `std::cerr` is niet gebufferd (verschijnt meteen), `std::clog` wel.

#### Invoer: `std::cin`
`std::cin` doet het omgekeerde: het is de snelweg van de terminal naar je programma. De **stream-input-operator** `>>` wijst naar de variabele: de gegevens stromen van `std::cin` naar de variabele.

```
int age1;
std::string name;
std::cout << "Please type your name and age : " << std::endl;
std::cin >> name;
std::cin >> age1;
```
Voor `std::string` (een type om tekst op te slaan; later meer) is `#include <string>` nodig.

**Ketenen**: je kunt meerdere `>>` achter elkaar zetten om alles in één statement in te lezen: `std::cin >> name >> age1;`. De gebruiker typt dan bijvoorbeeld de naam en leeftijd gescheiden door een spatie.

[▶ 02:33:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9217s) · [▶ 02:41:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9700s) · [▶ 02:45:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9946s)

#### Tekst met spaties: `std::getline`
`std::cin >> name` leest maar tot de eerste spatie. Typt de docent "Daniel Gakwaya", dan komt alleen "Daniel" in `name` terecht. Het restant ("Gakwaya") blijft in de invoer staan en wordt meteen gebruikt voor de volgende `>>`. Die verwacht een getal voor de leeftijd, waardoor het inlezen mislukt en de gebruiker geen kans krijgt om de leeftijd te typen: het programma "faalt jammerlijk".

De oplossing is `std::getline(stream, variabele)`: als eerste argument geef je de inputstream (`std::cin`), als tweede de `std::string` waarin de hele regel, spaties inbegrepen, wordt opgeslagen:
```
std::getline(std::cin, full_name);
std::cin >> age3;
```
De docent laat ook zien dat je een lang statement (zoals de begroeting met `std::cout`) over meerdere regels mag spreiden; pas de puntkomma sluit het statement af. Hij vergeet die puntkomma eerst, waardoor de build mislukt: een mooi voorbeeld van een compile-time error.

[▶ 02:36:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9407s) · [▶ 02:46:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9994s)

#### Het uitvoeringsmodel van een C++-programma
De docent schetst een vereenvoudigd **geheugenmodel**. De gecompileerde executable is een **binair** bestand. Probeer je `rooster.exe` in VS Code te openen, dan krijg je de melding dat het bestand binair is; geforceerd openen toont onleesbare tekens. Binair formaat is bedoeld voor de CPU, niet voor mensen.

Het verloop:
1. Het programma staat in binair formaat op de **harde schijf** en wacht tot je het start (dubbelklikken of via de terminal).
2. Bij het starten wordt het binaire bestand in het **RAM** (random access memory, niet het geheugen op de harde schijf) geladen.
3. De CPU voert het programma **statement voor statement** uit, van boven naar beneden:
   - `int a {10};` → ruimte reserveren voor `a` en er 10 in zetten.
   - `int b {5};` → idem voor `b` met 5.
   - `int c;` → ruimte voor `c`, maar zonder waarde: er staat een **willekeurige rommelwaarde** (junk) in.
   - "Statement 1" en "Statement 2" printen.
4. Dan volgt een **functieaanroep**. De code van de functie staat op een andere plek in het geheugen, mogelijk ver weg van `main` en de variabelen. Voor de CPU naar die functie springt, onthoudt hij het **return-adres** (in het voorbeeld adres 6): waar hij na de functie verder moet. Dan springt hij naar de functie (adres 30), neemt `a` als eerste parameter (10) en `b` als tweede (5), telt ze op en geeft het resultaat 15 terug, dat in `c` wordt geschreven.
5. De CPU keert terug naar het return-adres en gaat verder: "Statement 3", "Statement 4".
6. Aan het einde wordt het programma uit het geheugen verwijderd en is het afgelopen.

Waarom dit belangrijk is: sommige C++-features begrijp je alleen met zo'n model. Voorbeeld: de sprong van adres 6 naar 30 en terug is relatief "zwaar" voor een kleine functie die alleen twee getallen optelt. Zo'n aanroep kan daarom geoptimaliseerd worden tot een **inline**-functie: de optelling gebeurt dan direct op adres 6, zonder sprong. Dit model komt in de rest van de cursus nog vaak terug.

[▶ 02:49:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10187s) · [▶ 02:51:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10284s) · [▶ 02:53:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10380s) · [▶ 02:55:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10528s)

> 💡 Aanvulling: in werkelijkheid is het de **compiler** (niet de CPU tijdens het draaien) die beslist om een aanroep te inlinen. Het return-adres wordt in de praktijk op de *call stack* bewaard; dat komt later aan bod.

#### Core language vs. standard library vs. STL
Drie termen die je vaak tegenkomt in C++-documentatie:
- **Core language features**: de basisbouwstenen van de taal zelf. Hoe je variabelen definieert, de ingebouwde basistypes (`int`, ...), de regels voor het definiëren en gebruiken van functies, wat wel en niet mag. Zet je bijvoorbeeld een `<` op een verkeerde plek in een functiedefinitie, dan compileert het niet, omdat je de kernregels van de taal overtreedt. Dit is het fundament waarop je programma's bouwt.
- **Standard library**: een verzameling kant-en-klare, gespecialiseerde componenten die je eenvoudig in je programma's gebruikt, zoals `iostream` (`std::cout`, `std::cin`) en `string` (`std::string`). Je gebruikt `std::cout` zonder te weten hoe de gegevens precies naar de terminal gaan; die complexe details zijn verpakt in herbruikbare componenten.
- **STL** (Standard Template Library): een **deel van** de standard library, bestaande uit:
  - **containers**: types die verzamelingen van dingen opslaan;
  - **algoritmes**: functies die op die verzamelingen werken;
  - **iterators**: gespecialiseerde types om door containers te lopen, eventueel terwijl je algoritmes op elk element toepast.

[▶ 02:56:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10577s) · [▶ 02:59:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10770s)

### Codevoorbeelden

#### Hello World [▶ 01:46:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6377s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream> // laadt std::cout en std::endl (geen puntkomma!)

int main() {
    std::cout << "Hello World" << std::endl; // print tekst + nieuwe regel
    return 0; // 0 = succesvol afgesloten
}
```
```text
Hello World
```

#### Zonder `#include <iostream>` [▶ 01:47:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6474s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: include ontbreekt, 'cout' is not a member of 'std'
int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

#### Statements in volgorde en het effect van `std::endl` [▶ 01:50:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=6619s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    std::cout << "Number1" << std::endl; // nieuwe regel na Number1
    std::cout << "Number2";              // GEEN endl: Number3 plakt erachter
    std::cout << "Number3" << std::endl;
    return 0;
}
```
```text
Number1
Number2Number3
```

Met een `std::endl` na elk statement (zoals de docent het uiteindelijk oplost):
```cpp
#include <iostream>

int main() {
    std::cout << "Number1" << std::endl;
    std::cout << "Number2" << std::endl;
    std::cout << "Number3" << std::endl;
    return 0;
}
```
```text
Number1
Number2
Number3
```

#### Commentaar [▶ 01:58:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7099s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream> // This brings in the iostream library

int main() {
    // This is going to print Hello World to the console
    std::cout << "Hello World" << std::endl;

    /*
        Dit is een blokcommentaar.
        Alles hiertussen wordt door de compiler genegeerd.
    */
    return 0; // commentaar mag zelfs na het return-statement
}
```
```text
Hello World
```

#### Genest blokcommentaar (fout) [▶ 01:59:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7198s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: blokcommentaar genest; de eerste */ sluit alles af
#include <iostream>

int main() {
    /*
        This is a comment
        /*
            This is another comment
        */
    */
    std::cout << "Hello World" << std::endl;
    return 0;
}
```
De binnenste `*/` sluit het commentaar al af. De laatste `*/` staat dan als "code" in het programma, wat een compilerfout geeft.

#### Compile-time error: vergeten puntkomma [▶ 02:06:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7585s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: puntkomma ontbreekt -> error: expected ';' before 'return'
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl
    return 0;
}
```

#### Warning en runtime error: deling door nul [▶ 02:10:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=7823s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: warning 'division by zero' en undefined behavior (crash) tijdens uitvoeren
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    int value = 7 / 0;           // compiler waarschuwt, maar bouwt wel
    std::cout << value << std::endl; // hier crasht het programma
    return 0;
}
```
De docent ziet "Hello World" verschijnen, waarna het programma zonder de waarde te printen stopt. Daarna zet hij de regels in commentaar.

#### Statements en variabelen [▶ 02:19:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8395s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int first_number {13}; // statement 1 (docent begon met 3, wijzigde naar 13)
    int second_number {7}; // statement 2

    std::cout << "First number : " << first_number << std::endl;
    std::cout << "Second number : " << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl;
    return 0;
}
```
```text
First number : 13
Second number : 7
Sum : 20
```

#### Een functie definiëren en hergebruiken [▶ 02:23:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=8636s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

// returntype naam(parameters) { body }
int add_numbers(int first_param, int second_param) {
    int result = first_param + second_param;
    return result; // geef het resultaat terug aan de aanroeper
}

int main() {
    int first_number {13};
    int second_number {7};

    std::cout << "First number : " << first_number << std::endl;
    std::cout << "Second number : " << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl;

    sum = add_numbers(25, 7); // functie aanroepen, resultaat opslaan
    std::cout << "Sum : " << sum << std::endl;

    sum = add_numbers(30, 54); // hergebruik zonder code te herhalen
    std::cout << "Sum : " << sum << std::endl;

    // aanroep rechtstreeks in een cout-statement
    std::cout << "Sum : " << add_numbers(3, 42) << std::endl;
    return 0;
}
```
```text
First number : 13
Second number : 7
Sum : 20
Sum : 32
Sum : 84
Sum : 45
```

#### Uitvoer naar `cout`, `cerr` en `clog` [▶ 02:38:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9504s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    std::cout << "Hello C++20" << std::endl; // data: programma -> cout -> terminal
    int age {21};
    std::cout << "Age : " << age << std::endl;

    std::cerr << "Error message : Something is wrong" << std::endl; // foutmelding
    std::clog << "Log message : Something happened" << std::endl;   // logbericht
    return 0;
}
```
```text
Hello C++20
Age : 21
Error message : Something is wrong
Log message : Something happened
```

#### Invoer met `std::cin` [▶ 02:41:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9700s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// stdin: Daniel\n33
#include <iostream>
#include <string> // nodig voor std::string

int main() {
    int age1;
    std::string name;

    std::cout << "Please type your name and age : " << std::endl;
    std::cin >> name; // data: cin -> name
    std::cin >> age1; // data: cin -> age1

    std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;
    return 0;
}
```
Ingevoerd: `Daniel` (Enter), `33` (Enter). De invoer zelf verschijnt niet in de onderstaande uitvoer.
```text
Please type your name and age : 
Hello Daniel you are 33 years old!
```

#### Invoer ketenen [▶ 02:45:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9946s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// stdin: Daniel 33
#include <iostream>
#include <string>

int main() {
    int age1;
    std::string name;

    std::cout << "Please type your name and age : " << std::endl;
    std::cin >> name >> age1; // twee waarden in één statement

    std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;
    return 0;
}
```
Ingevoerd: `Daniel 33` (Enter).
```text
Please type your name and age : 
Hello Daniel you are 33 years old!
```

#### Het probleem met spaties [▶ 02:46:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=9994s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// stdin: Daniel Gakwaya\n33
#include <iostream>
#include <string>

int main() {
    int age1 {0};
    std::string name;

    std::cout << "Please type your name and age : " << std::endl;
    std::cin >> name >> age1; // name = "Daniel"; "Gakwaya" is geen getal -> inlezen faalt

    std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;
    return 0;
}
```
Ingevoerd: `Daniel Gakwaya` (Enter). Het programma wacht niet op de leeftijd: `>>` probeert "Gakwaya" als getal te lezen en faalt.
```text
Please type your name and age : 
Hello Daniel you are 0 years old!
```

> 💡 Aanvulling: sinds C++11 zet een mislukte `>>` op een `int` de variabele op 0. De docent initialiseerde de variabele niet; dan kun je in oudere situaties een rommelwaarde zien. Hier is `age1 {0}` gebruikt zodat de uitvoer voorspelbaar is.

#### Tekst met spaties inlezen met `std::getline` [▶ 02:47:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10043s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// stdin: Daniel Gakwaya\n33
#include <iostream>
#include <string>

int main() {
    std::string full_name;
    int age3;

    std::cout << "Type in your full name and age : " << std::endl;
    std::getline(std::cin, full_name); // leest de hele regel, spaties inbegrepen
    std::cin >> age3;

    // een lang statement mag over meerdere regels lopen
    std::cout << "Hello " << full_name
              << " you are " << age3 << " years old!" << std::endl;
    return 0;
}
```
Ingevoerd: `Daniel Gakwaya` (Enter), `33` (Enter).
```text
Type in your full name and age : 
Hello Daniel Gakwaya you are 33 years old!
```

#### Het programma uit het uitvoeringsmodel [▶ 02:49:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10187s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int add_numbers(int param1, int param2) { // staat elders in het geheugen
    int result = param1 + param2;
    return result;
}

int main() {
    int a {10}; // ruimte voor a, waarde 10
    int b {5};  // ruimte voor b, waarde 5
    int c;      // ruimte voor c, nog een rommelwaarde

    std::cout << "statement1" << std::endl;
    std::cout << "statement2" << std::endl;

    c = add_numbers(a, b); // CPU bewaart return-adres, springt, komt terug met 15

    std::cout << "statement3" << std::endl;
    std::cout << "statement4" << std::endl;
    std::cout << "c : " << c << std::endl; // toegevoegd om het resultaat te tonen
    return 0;
}
```
```text
statement1
statement2
statement3
statement4
c : 15
```

#### Core, standard library en STL in één programma [▶ 02:58:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10721s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream> // standard library
#include <string>   // standard library

// core language: int, functiedefinitie, parameters, return
int add_numbers(int first_param, int second_param) {
    return first_param + second_param;
}

int main() {
    std::string name {"Daniel"}; // std::string: standard library-type
    std::cout << name << " : " << add_numbers(3, 4) << std::endl; // std::cout: standard library
    return 0;
}
```
```text
Daniel : 7
```

> 💡 Aanvulling: een voorbeeld van de STL zelf (container `std::vector`, algoritmes uit `<algorithm>`, iterators) komt pas later in de cursus; de docent noemt hier alleen de begrippen.

### Valkuilen & veelgemaakte fouten

#### Puntkomma vergeten
Bijna elk statement moet met `;` eindigen. Een vergeten puntkomma is de klassieke compile-time error (`expected ';' before 'return'`). De docent maakt deze fout zelf tijdens de `getline`-demo. De foutmelding wijst vaak naar de regel *ná* de echte fout.

#### Puntkomma achter `#include`
`#include <iostream>` krijgt géén puntkomma. Het is een preprocessor-directive, geen gewoon statement.

#### `#include` vergeten
Zonder `#include <iostream>` zijn `std::cout` en `std::endl` onbekend ("namespace std has no member cout"). Zonder `#include <string>` werkt `std::string`/`std::getline` niet altijd.

#### `std::endl` vergeten
Zonder nieuwe regel plakken opeenvolgende uitvoerstatements tegen elkaar ("Number2Number3").

#### Blokcommentaar nesten
`/* ... /* ... */ ... */` werkt niet: de eerste `*/` sluit af en de rest geeft verwarrende fouten.

#### Warnings negeren
Een warning stopt de build niet, maar kan een runtime-probleem aankondigen, zoals `7 / 0`: het programma bouwt, maar crasht tijdens het uitvoeren.

#### `>>` met tekst die spaties bevat
`std::cin >> name` stopt bij de eerste spatie; de rest blijft in de invoer en verpest de volgende `>>`. Gebruik `std::getline`.

#### Functie gebruiken vóór de definitie
Een functie die onder `main` staat (en niet vooraf gedeclareerd is) is op het moment van aanroepen onbekend: compileerfout. Zet de functie boven `main`.

#### Niet-geïnitialiseerde variabele
`int c;` bevat een rommelwaarde tot je er iets aan toekent. Lees zo'n variabele niet uit voordat je hem een waarde gaf.

> 💡 Aanvulling: mix je `std::cin >> x` en daarna `std::getline`, dan leest `getline` vaak een lege regel, namelijk de Enter die na `x` in de invoer bleef staan. De docent omzeilt dit door `getline` vóór `>>` te gebruiken. Een oplossing is `std::cin >> std::ws` vóór de `getline`.

### Best practices
- Begin elk nieuw project vanuit het werkende template en bouw regelmatig, zodat je fouten direct ziet.
- Kijk zowel naar de terminaluitvoer als naar het tabblad *Problems* in VS Code.
- Los warnings op; behandel ze als vroege waarschuwingen voor echte bugs.
- Gebruik commentaar om uit te leggen *waarom*, niet om elke regel te herhalen. Niet overdrijven.
- Gebruik `//` voor korte opmerkingen en `/* ... */` om tijdelijk een blok code uit te zetten (zoals de docent bij de I/O-demo).
- Stop herhaalde berekeningen in een functie met een duidelijke naam en hergebruik die.
- Gebruik `std::cerr` voor foutmeldingen en `std::clog` voor logberichten, zodat je bedoeling duidelijk is.
- Gebruik `std::getline` voor invoer die spaties kan bevatten (volledige naam, zinnen).
- Speel met de code: typ, bouw, voer uit en kijk wat er gebeurt; dat is volgens de docent de beste manier om te leren.

### Samenvatting
- `#include <iostream>` laadt de standaardbibliotheek-component voor console-I/O; zonder die regel kent de compiler `std::cout` niet.
- `main` is het entry point; de statements daarin lopen van boven naar beneden, en `return 0;` meldt succes aan het besturingssysteem.
- `std::cout << ... << std::endl;` print naar de console; `std::endl` zet een nieuwe regel.
- Commentaar: `//` voor één regel, `/* */` voor een blok; blokcommentaar mag niet genest worden.
- Drie soorten problemen: compile-time errors (geen executable), runtime errors (verkeerd gedrag of crash) en warnings (wel een executable, maar opletten).
- Een statement is de kleinste uitvoerbare eenheid, eindigt met `;` en wordt in volgorde uitgevoerd.
- Een functie heeft een returntype, een naam, parameters en een body; ze moet vóór gebruik gedefinieerd zijn en kan onbeperkt hergebruikt worden.
- `std::cin >>` leest invoer (ook geketend); `std::getline(std::cin, s)` leest een hele regel met spaties; `std::cerr` en `std::clog` zijn voor fouten en logs.
- Een programma wordt van schijf in het RAM geladen; de CPU voert het statement voor statement uit en bewaart bij een functieaanroep een return-adres. Inlining voorkomt die sprong.
- Core language = basisregels en -types van de taal; standard library = kant-en-klare componenten (`iostream`, `string`); STL = deel van de standard library met containers, algoritmes en iterators.

### Oefeningen
1. Schrijf een programma dat je naam 10 keer onder elkaar print (opdracht van de docent).
2. Schrijf een functie `multiply_numbers` die twee gehele getallen vermenigvuldigt, en roep die in `main` aan met (3, 4) en (6, 7). Print het resultaat (opdracht van de docent).
3. Lees de naam en leeftijd van de gebruiker in met één geketend `std::cin`-statement en print hoe oud de gebruiker over 10 jaar is. Gebruik een functie `add_numbers` voor de optelling.
4. Lees een volledige naam (met spaties) in met `std::getline` en daarna een geboortejaar met `std::cin`. Print de naam en de leeftijd in 2026 via een functie `compute_age(int birth_year)`. Schrijf bovendien een melding naar `std::clog` dat het programma klaar is.

<details><summary>Uitwerking</summary>

Oefening 1:
```cpp
#include <iostream>

int main() {
    // tien statements, van boven naar beneden uitgevoerd
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    std::cout << "Daniel" << std::endl;
    return 0;
}
```
```text
Daniel
Daniel
Daniel
Daniel
Daniel
Daniel
Daniel
Daniel
Daniel
Daniel
```

Oefening 2:
```cpp
#include <iostream>

int multiply_numbers(int first_param, int second_param) {
    int result = first_param * second_param;
    return result;
}

int main() {
    int product = multiply_numbers(3, 4);
    std::cout << "Product : " << product << std::endl;
    std::cout << "Product : " << multiply_numbers(6, 7) << std::endl;
    return 0;
}
```
```text
Product : 12
Product : 42
```

Oefening 3 (invoer: `Anna 25`):
```cpp
// stdin: Anna 25
#include <iostream>
#include <string>

int add_numbers(int first_param, int second_param) {
    return first_param + second_param;
}

int main() {
    std::string name;
    int age;

    std::cout << "Type your name and age : " << std::endl;
    std::cin >> name >> age; // geketende invoer

    std::cout << name << ", in 10 years you will be "
              << add_numbers(age, 10) << " years old." << std::endl;
    return 0;
}
```
```text
Type your name and age : 
Anna, in 10 years you will be 35 years old.
```

Oefening 4 (invoer: `Anna de Vries` en `2000`). Het logbericht gaat naar stderr en verschijnt in de terminal gewoon na de rest:
```cpp
// stdin: Anna de Vries\n2000
#include <iostream>
#include <string>

int compute_age(int birth_year) {
    return 2026 - birth_year;
}

int main() {
    std::string full_name;
    int birth_year;

    std::cout << "Type your full name and birth year : " << std::endl;
    std::getline(std::cin, full_name); // eerst getline: hele regel met spaties
    std::cin >> birth_year;

    std::cout << "Hello " << full_name << ", you are (or will be) "
              << compute_age(birth_year) << " in 2026." << std::endl;
    std::clog << "Log : program finished" << std::endl;
    return 0;
}
```
```text
Type your full name and birth year : 
Hello Anna de Vries, you are (or will be) 26 in 2026.
Log : program finished
```
</details>

---

<a id="h03"></a>

## Hoofdstuk 3 – Variables and data types (03:00:47 – 04:46:46) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10847s)

### Leerdoelen
- Begrijpen dat alle data in het geheugen uit bits (enen en nullen) bestaat, gegroepeerd in bytes.
- Talstelsels kennen (decimaal, binair, octaal, hexadecimaal) en ze in C++ als literal kunnen schrijven (`15`, `017`, `0x0F`, `0b00001111`).
- Weten wat een variabele is: een *named piece of memory* van een bepaald type.
- De drie manieren van initialiseren kennen: braced (`{}`), functional (`()`) en assignment (`=`), en waarom braced initialization veiliger is (narrowing).
- `sizeof` gebruiken om de grootte van types en variabelen op te vragen.
- De integer modifiers `signed`, `unsigned`, `short`, `long` en `long long` kennen, plus de bereikformules.
- Werken met `float`, `double` en `long double`: precisie, suffixes (`f`, `l`), scientific notation, `inf` en `nan`.
- `bool` gebruiken, en `std::boolalpha` om `true`/`false` te tonen in plaats van `1`/`0`.
- `char` en de ASCII-codering begrijpen, en een `char` als getal tonen met `static_cast<int>`.
- Types laten afleiden met `auto` (inclusief literal-suffixes `u`, `ul`, `ll`).
- Waarden opnieuw toekennen (assignment) en de valkuil van `auto` + negatieve waarde in een `unsigned` kennen.

### Verband met eerdere hoofdstukken
- In hoofdstuk 2 schreven we al programma's met `int`, statements, functies, `std::cout`/`std::cin` en comments, maar het type `int` zelf werd nog niet uitgelegd. Dit hoofdstuk vult dat gat.
- Het geheugen- en executiemodel uit hoofdstuk 2 (programma in RAM, variabelen in geheugen) is de basis voor het idee "een variabele is een benoemd stuk geheugen".
- Elk project wordt weer gemaakt door het templateproject uit hoofdstuk 1 te kopiëren (`main.cpp`, `tasks.json`) en te bouwen met de task "Build with GCC"; het programma heet `rooster.exe`.
- `if`-statements worden hier al kort gebruikt bij booleans; die worden pas in hoofdstuk 5 volledig behandeld. Operatoren en output-formattering (`std::setprecision`, `std::boolalpha` ...) komen uitgebreid terug in hoofdstuk 4.

### Uitleg

#### Ingebouwde types: een overzicht
C++ heeft een aantal voorgedefinieerde (fundamental) types. De docent noemt:
- `int`: gehele getallen (1, 2, 3).
- `double` en `float`: getallen met een decimaal deel (2.5, 7.3); het verschil zit in grootte en precisie.
- `char`: één teken (`'a'`, `'b'`, ...).
- `bool`: twee toestanden, `true` of `false`.
- `void`: een "typeless type", pas echt zinvol bij functies (later in de cursus).
- `auto`: eigenlijk geen type maar een keyword waarmee de compiler het type afleidt.

[▶ 03:01:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=10865s)

#### Bits, bytes en waarom talstelsels bestaan
Alles in je programma staat in het RAM als een reeks enen en nullen. Eén 0 of 1 heet een **bit**; acht bits samen vormen een **byte**. Je kunt bits ook in groepen van 16, 32 of 64 nemen. Mensen kunnen niets met lange rijen bits, dus er moet een vertaling zijn tussen "mensvriendelijke" data (22, een naam) en de representatie in het geheugen. Die vertaling (voor gehele getallen) doen we met **talstelsels**: binair, octaal, hexadecimaal.

[▶ 03:03:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11011s)

#### Decimaal en binair
In het decimale stelsel (base 10) is elk cijfer een macht van 10:
`2371 = 2·10³ + 3·10² + 7·10¹ + 1·10⁰ = 2000 + 300 + 70 + 1`.

Binair (base 2) werkt precies zo, maar met machten van 2 en alleen de cijfers 0 en 1:
`10010 = 1·2⁴ + 0·2³ + 0·2² + 1·2¹ + 0·2⁰ = 16 + 2 = 18`.
`100101 = 32 + 4 + 1 = 37`, en `111 = 4 + 2 + 1 = 7`.

De docent gebruikt de Windows-rekenmachine in **Programmer**-modus om zulke omzettingen te controleren.

Met *n* bits kun je (unsigned) de getallen **0 tot 2ⁿ − 1** voorstellen:

| Bits | Bereik |
|---|---|
| 1 | 0 – 1 |
| 3 | 0 – 7 |
| 4 | 0 – 15 |
| 5 | 0 – 31 |
| 8 | 0 – 255 |
| 16 | 0 – 65 535 |
| 32 | 0 – 4 294 967 295 |
| 64 | 0 – 18 446 744 073 709 551 615 |

Voorbeeld van groeperen per 4 bits: `0110` = 6, dus die vier bits "bevatten" een 6. Per 5 bits: `01101` = 8 + 4 + 1 = 13.

> ⚠️ Onduidelijk in opname: de docent zegt dat 5 cijfers "van 0 tot 32" gaan en dat `01101` "een 17" is. Volgens de formule 2ⁿ − 1 is het bereik 0–31 en `01101` is 13 (wat hij eerder in dezelfde zin ook zegt).

[▶ 03:05:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11106s)

#### Hexadecimaal
Hexadecimaal (base 16) is vooral een manier om lange binaire getallen **korter** op te schrijven. Je splitst het binaire getal (van rechts af) in groepjes van 4 bits; elk groepje krijgt één symbool: `0000`=0 ... `1001`=9, `1010`=A, `1011`=B, `1100`=C, `1101`=D, `1110`=E, `1111`=F.

Zo wordt een getal van 32 bits geschreven met slechts 8 hex-symbolen. Het prefix `0x` betekent "dit is hexadecimaal". Past het aantal bits niet precies in groepen van 4, dan vul je links aan met nullen: **padding**.

[▶ 03:12:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11538s)

#### Octaal
Octaal (base 8, cijfers 0–7) werkt hetzelfde maar met groepjes van 3 bits (`111` = 7, `100` = 4, ...). Ook hier vul je links aan met nullen. Een octaal getal schrijf je in C++ met een **voorloopnul**. Octaal wordt vandaag nauwelijks nog gebruikt; de docent noemt het voor de volledigheid.

[▶ 03:14:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11682s)

#### Talstelsels in C++-code
Hetzelfde getal 15 kun je op vier manieren schrijven:

| Stelsel | Literal |
|---|---|
| decimaal | `15` |
| octaal | `017` (voorloopnul!) |
| hexadecimaal | `0x0F` of `0x0f` (hoofdletters/kleine letters maakt niet uit) |
| binair | `0b00001111` (sinds C++14) |

Let op: `017` is **niet** 17 maar 15. In het geheugen is de representatie in alle vier gevallen exact dezelfde; je kiest de schrijfwijze die het handigst is voor wat je doet.

[▶ 03:16:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11780s) · demo [▶ 03:17:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11878s)

#### Integers en wat een variabele is
`int` slaat gehele getallen op en neemt meestal **4 bytes** in. Een **variabele** is een *named piece of memory*: een stuk geheugen met een naam (bv. `age`) waarin je data van een bepaald type bewaart. De waarde staat daar binair.

[▶ 03:21:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12076s)

#### Braced initialization
- `int elephant_count;` declareert zonder waarde: de variabele bevat een **garbage value** (willekeurige oude bits). Sommige compilers zetten er toevallig 0 in, maar daar mag je niet op rekenen.
- `int lion_count{};` met lege accolades initialiseert op **0**.
- `int dog_count{10};` initialiseert expliciet.
- Je mag een expressie gebruiken: `int domesticated_animals{dog_count + cat_count};`.
- Een naam gebruiken die nergens gedeclareerd is (`doesnt_exist`) geeft een **compilerfout**; VS Code toont dat zelfs al vóór het compileren.
- Een kommagetal in een `int` met accolades (`int narrowing_conversion{2.9};`) geeft een **narrowing**-fout. GCC in C++20-modus weigert dit: *"narrowing conversion of '2.8999999999999999e+0' from 'double' to 'int'"*. Dat is precies de bedoeling: braced initialization beschermt je tegen dataverlies.

[▶ 03:22:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12174s) · demo [▶ 03:29:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12561s)

#### Functional initialization
Met haakjes: `int apple_count(5);`. Dit doet grotendeels hetzelfde als accolades, met één belangrijk verschil: `int narrowing_conversion_functional(2.9);` compileert **zonder fout** en hakt stilletjes het decimale deel eraf, zodat er `2` in staat. Dit heet een **implicit conversion**. Omdat het stil gebeurt is het gevaarlijk.

> 💡 Aanvulling: de docent zegt dat dit gebeurt "omdat 2.9 meer dan 4 bytes is". De echte reden is dat een `int` geen decimaal deel kan bewaren; de conversie double → int kapt altijd af richting nul, ongeacht de grootte.

[▶ 03:25:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12320s) · demo [▶ 03:34:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12897s)

#### Assignment initialization
Met het gelijkteken: `int bike_count = 2;`. Ook hier wordt `int narrowing_conversion_assignment = 2.9;` stil afgekapt tot `2`. Samengevat:

| Vorm | Syntax | Narrowing (bv. 2.9 → int) |
|---|---|---|
| braced | `int x{5};` | compilerfout (veilig) |
| functional | `int x(5);` | stil afgekapt |
| assignment | `int x = 5;` | stil afgekapt |

Deze drie vormen werken voor alle types, niet alleen voor `int`.

[▶ 03:26:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12369s) · demo [▶ 03:37:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13043s)

#### sizeof
`sizeof(int)` of `sizeof(variabele)` geeft het aantal **bytes** dat een type of variabele inneemt. Op het systeem van de docent: `sizeof(int)` = 4. Elk fundamental type heeft zo een grootte, al kan die per compiler/platform verschillen.

[▶ 03:26:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12418s) · demo [▶ 03:38:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13091s)

#### Regels voor variabelenamen
- Begin met een letter (a–z, A–Z) of een underscore `_`; **niet** met een cijfer.
- Daarna mogen letters, cijfers en underscores.
- Namen zijn **case sensitive**: `bike_count` en `Bike_count` zijn twee verschillende variabelen.
- Geen spaties of speciale tekens zoals `+`.

Algemene vorm: `type naam {initialisatiewaarde};` (of met `()` of `=`).

[▶ 03:27:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12465s)

#### Integer modifiers: signed en unsigned
Een `int` kan zowel positieve als negatieve getallen bevatten (`10`, `-300`), omdat `int` standaard **`signed`** is. Je mag `signed int` ook expliciet schrijven; dat verandert niets. Wil je alleen niet-negatieve waarden, gebruik dan **`unsigned int`**. `unsigned int value4{-5};` geeft met accolades een compilerfout (narrowing van −5 naar unsigned). Signed of unsigned: de grootte blijft 4 bytes.

Bereikformules voor *n* bits:
- unsigned: **0 tot 2ⁿ − 1** → voor 32 bits: 0 tot 4 294 967 295 (≈ 4 miljard)
- signed: **−2ⁿ⁻¹ tot 2ⁿ⁻¹ − 1** → voor 32 bits: −2 147 483 648 tot 2 147 483 647 (≈ ±2 miljard)

Bij signed wordt het bereik dus "in tweeën gedeeld": de ene helft voor negatieve, de andere voor positieve getallen.

[▶ 03:40:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13235s) · demo [▶ 03:44:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13474s)

#### Integer modifiers: short, long, long long
Met `short` en `long` maak je het bereik kleiner of groter. Je mag `int` weglaten: `short` betekent `short int`. De docent toont een tabel met alle combinaties; op zijn systeem (Windows, GCC):

| Groep | Combinaties | Grootte |
|---|---|---|
| short | `short`, `short int`, `signed short`, `signed short int`, `unsigned short`, `unsigned short int` | 2 bytes |
| int | `int`, `signed`, `signed int`, `unsigned`, `unsigned int` | 4 bytes |
| long | `long`, `long int`, `signed long`, `signed long int`, `unsigned long`, `unsigned long int` | 4 bytes |
| long long | `long long`, `long long int`, `signed long long`, `signed long long int`, `unsigned long long`, `unsigned long long int` | 8 bytes |

Deze modifiers werken **alleen op integral types** (gehele getallen). Op types voor kommagetallen geven ze een compilerfout.

> 💡 Aanvulling: `long` is 4 bytes op Windows, maar 8 bytes op 64-bit Linux/macOS. De standaard garandeert alleen minimumgroottes (short ≥ 16 bits, long ≥ 32, long long ≥ 64).

[▶ 03:42:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13378s) · demo [▶ 03:48:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13720s)

#### Fractional numbers: float, double, long double
Kommagetallen heten technisch **floating point types**:

| Type | Grootte (typisch) | Precisie | Suffix |
|---|---|---|---|
| `float` | 4 bytes | ~7 cijfers | `f` |
| `double` | 8 bytes | ~15 cijfers | geen (standaard) |
| `long double` | 12 bytes (bij de docent: 16) | > 15 cijfers | `l` / `L` |

**Precisie** = het aantal significante cijfers dat het type betrouwbaar kan voorstellen, **inclusief** de cijfers vóór de komma. Een getal met 12 significante cijfers past dus niet in een `float`; `double` (15) is het kleinste type dat volstaat. `long double` is minstens zo precies als `double`, maar kan afhankelijk van de compiler ook gelijk zijn aan `double`.

> ⚠️ Onduidelijk in opname: de docent zegt "number of bits"; bedoeld wordt het aantal (decimale) cijfers.

Floating point getallen worden niet met de gewone talstelsels opgeslagen maar met een speciaal systeem (de docent verwijst ernaar zonder het te behandelen). Ook die getallen zijn uiteindelijk enen en nullen.

> 💡 Aanvulling: dat systeem is de IEEE 754-standaard (teken, exponent, mantisse).

[▶ 03:54:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14057s) · demo [▶ 04:03:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14592s)

#### Precisie tonen met std::setprecision
Standaard toont `std::cout` maar 6 significante cijfers. Met `std::setprecision(20)` (uit de header `<iomanip>`) vraag je er meer. Dan zie je dat een `float` na ongeveer 7 cijfers "garbage" toont, een `double` na 15–17 cijfers en `long double` nog verder correct blijft. De docent haalt `<iomanip>` uit de documentatie van de standard library.

[▶ 03:56:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14202s) · demo [▶ 04:04:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14691s)

#### Narrowing en suffixes bij floating point
`float number4 {192400023.0f};` compileert gewoon, ook met accolades, maar het getal heeft 9 cijfers en `float` kan er maar ~7 bewaren: de uitvoer wordt `192400016`. De laatste cijfers zijn "junk".

Belangrijke les van de docent: verander je alleen het type naar `double` maar laat je de **`f`-suffix** staan, dan krijg je hetzelfde foute resultaat. De literal `192400023.0f` is dan al een `float`; de precisie is verloren nog vóór de waarde in de `double` komt. Haal je de `f` weg, dan is de literal een `double` en zie je `192400023`.

Regels:
- Zonder suffix is een kommaliteral een `double`.
- `f` → `float`, `l`/`L` → `long double`.
- Met functional (`()`) of assignment (`=`) notatie wordt ook stil afgekapt.

> 💡 Aanvulling: in de demo krijgt de float-literal geen narrowing-fout omdat een `float`-literal in een `float` geen conversie is. Een `double`-literal zoals `float x{192400023.0};` zou met accolades wél een narrowing-fout geven.

[▶ 03:57:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14250s) · demo [▶ 04:07:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14837s)

#### Scientific notation
Tot nu toe gebruikten we **fixed notation** (`192400023.0`). Met **scientific notation** schrijf je een getal als mantisse × macht van 10:
- `1.92400023e8` = 1.92400023 × 10⁸: schuif de komma 8 plaatsen naar rechts → 192400023.
- `1.924e8` = 192400000 (de ontbrekende cijfers worden nullen).
- `3.498e-11` = 3.498 × 10⁻¹¹ = 0.00000000003498: schuif de komma 11 plaatsen naar links.

Ook als je een heel klein getal in fixed notation schrijft (`0.00000000003498`), print `std::cout` het in scientific notation (`3.498e-11`). Zonder suffix zijn al deze literals `double`.

[▶ 03:58:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14298s) · demo [▶ 04:11:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15077s)

#### Infinity en NaN
Met floating point kun je dingen die met integers niet mogen:
- positief getal / 0.0 → **`inf`** (positief oneindig);
- negatief getal / 0.0 → **`-inf`**;
- `inf` + iets kleins → nog steeds `inf`;
- 0.0 / 0.0 → **`nan`** ("not a number").

Het programma crasht niet, maar `nan` is een teken dat je iets fout doet; met zulke waarden verder rekenen is zinloos.

> 💡 Aanvulling: met integers is delen door 0 undefined behavior (vaak een crash). Afhankelijk van platform/library kan 0.0/0.0 als `nan` of `-nan` geprint worden.

[▶ 04:00:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14448s) · demo [▶ 04:13:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15224s)

#### Booleans
`bool` kan twee toestanden bewaren: `true` of `false`. Booleans gebruik je vooral om **beslissingen** te nemen. De docent toont alvast een `if` (pas in hoofdstuk 5 uitgelegd):
- `if (red_light == true) { ... } else { ... }`
- korter: `if (green_light) { ... }`, de variabele zelf is al de test.

Een `bool` neemt **1 byte** (8 bits) in, terwijl één bit zou volstaan. Dat lijkt verspilling, maar met moderne geheugens is dat geen probleem; voor geheugenarme apparaten bestaan technieken om meer data in een byte te pakken (later in de cursus).

Printen: standaard toont `std::cout` `true` als `1` en `false` als `0`. Met `std::cout << std::boolalpha;` krijg je `true`/`false`. Die instelling blijft actief voor alle volgende output.

[▶ 04:16:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15368s) · demo [▶ 04:19:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15557s)

#### Characters en ASCII
`char` slaat één teken op, tussen **enkele aanhalingstekens**: `char character1{'a'};`. Zonder die quotes krijg je een compilerfout. Een `char` neemt **1 byte** in, dus 256 mogelijke waarden (0–255 als je alleen positieve waarden neemt).

Elke waarde koppel je aan een teken: dat is de **ASCII**-codering. Voorbeelden: 33 = `!`, 48 = `'0'`, 49 = `'1'`, 65 = `'A'`, 70 = `'F'`, 71 = `'G'`, 112 = `'p'`. ASCII gebruikt de eerste 128 waarden.

Je kunt een geldig ASCII-getal direct in een `char` stoppen: `char value = 65;`. Printen geeft dan `A`, niet `65`. Wil je het getal zien, dan zet je de waarde om met `static_cast<int>(value)` (meer over `static_cast` later in de cursus).

Voor talen als Arabisch, Japans of Chinees volstaat ASCII niet; daarvoor bestaat **Unicode**, maar dat valt buiten deze cursus.

[▶ 04:24:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15890s) · demo [▶ 04:28:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16132s)

#### auto
Met `auto` laat je de compiler het type afleiden uit de initialisatiewaarde. Handig bij lange, moeilijk te typen typenamen (voorbeelden daarvan komen later in de cursus). Het type hangt af van de literal en zijn suffix:

| Declaratie | Afgeleid type |
|---|---|
| `auto var1{12};` | `int` |
| `auto var2{13.0};` | `double` |
| `auto var3{14.0f};` | `float` |
| `auto var4{15.0l};` | `long double` |
| `auto var5{'e'};` | `char` |
| `auto var6{123u};` | `unsigned int` |
| `auto var7{434ul};` | `unsigned long` |
| `auto var8{452ll};` | `long long` |

In VS Code zie je het afgeleide type al door met de muis over de variabele te hoveren; met `sizeof` controleer je het na het compileren. De docent vermeldt ook dat je met de task "Build with MSVC" kunt bouwen, maar hij verkiest GCC.

[▶ 04:32:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16325s) · demo [▶ 04:34:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16472s)

#### Assignments
Na de initialisatie kun je een variabele later een **nieuwe waarde** geven met `=`: `var1 = 55;`. Zo hergebruik je de variabele. Dat werkt voor elk type: `double` (`var2 = 99.99;`), `bool` (`state = true;`), enz.

Valkuil met `auto`: bij `auto var3{333u};` zie je het type (`unsigned int`) niet meteen aan de declaratie. Ken je dan `var3 = -22;` toe, dan krijg je **geen** compilerfout. De −22 wordt stil omgezet naar een groot positief getal (4294967274, bijna 4 miljard). VS Code toont dat al bij hoveren. Zo'n fout is later moeilijk op te sporen.

> ⚠️ Onduidelijk in opname: op de slide zegt de docent dat dit een compilerfout geeft; in de demo blijkt het (correct) een stille omzetting zonder fout te zijn.

[▶ 04:37:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16667s) · demo [▶ 04:39:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16766s)

#### Samenvatting door de docent
Fundamental types voor integers, floating points, booleans en characters; type deduction met `auto`; data als enen en nullen; talstelsels (binair, octaal, hexadecimaal) als vertaling voor integral types.

[▶ 04:45:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17107s)

### Codevoorbeelden

#### Talstelsels [▶ 03:17:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=11878s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int number1 = 15;          // decimaal
    int number2 = 017;         // octaal (voorloopnul!)
    int number3 = 0x0F;        // hexadecimaal
    int number4 = 0b00001111;  // binair (sinds C++14)

    std::cout << "number1 : " << number1 << std::endl;
    std::cout << "number2 : " << number2 << std::endl;
    std::cout << "number3 : " << number3 << std::endl;
    std::cout << "number4 : " << number4 << std::endl;
    return 0;
}
```
```text
number1 : 15
number2 : 15
number3 : 15
number4 : 15
```

#### Niet-geïnitialiseerde variabele [▶ 03:30:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12610s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: lezen van een niet-geïnitialiseerde variabele is undefined behavior (garbage value)
#include <iostream>

int main() {
    int elephant_count;   // geen initialisatie: garbage value
    std::cout << "Elephant count : " << elephant_count << std::endl;
    return 0;
}
```

#### Niet-gedeclareerde variabele en narrowing [▶ 03:31:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12706s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: doesnt_exist is niet gedeclareerd en {2.9} in een int is narrowing
int main() {
    int new_number{doesnt_exist};          // error: 'doesnt_exist' was not declared
    int narrowing_conversion{2.9};         // error: narrowing conversion from double to int
    return 0;
}
```

#### Braced initialization [▶ 03:33:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12801s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int lion_count{};                          // lege accolades: 0
    int dog_count{10};                         // expliciet 10
    int cat_count{15};
    int domesticated_animals{dog_count + cat_count};  // expressie als initialisatie

    std::cout << "Lion count : " << lion_count << std::endl;
    std::cout << "Dog count : " << dog_count << std::endl;
    std::cout << "Cat count : " << cat_count << std::endl;
    std::cout << "Domesticated animals count : " << domesticated_animals << std::endl;
    return 0;
}
```
```text
Lion count : 0
Dog count : 10
Cat count : 15
Domesticated animals count : 25
```

#### Functional initialization [▶ 03:34:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=12897s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int apple_count(5);
    int orange_count(10);
    int fruit_count(apple_count + orange_count);
    int narrowing_conversion_functional(2.9);  // stil afgekapt: informatie verloren!

    std::cout << "Apple count : " << apple_count << std::endl;
    std::cout << "Orange count : " << orange_count << std::endl;
    std::cout << "Fruit count : " << fruit_count << std::endl;
    std::cout << "Narrowing conversion : " << narrowing_conversion_functional << std::endl;
    return 0;
}
```
```text
Apple count : 5
Orange count : 10
Fruit count : 15
Narrowing conversion : 2
```

#### Assignment initialization en sizeof [▶ 03:37:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13043s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int bike_count = 2;
    int truck_count = 7;
    int vehicle_count = bike_count + truck_count;
    int narrowing_conversion_assignment = 2.9;   // ook stil afgekapt

    std::cout << "Bike count : " << bike_count << std::endl;
    std::cout << "Truck count : " << truck_count << std::endl;
    std::cout << "Vehicle count : " << vehicle_count << std::endl;
    std::cout << "Narrowing conversion : " << narrowing_conversion_assignment << std::endl;

    // sizeof met een type of met een variabele
    std::cout << "sizeof int : " << sizeof(int) << std::endl;
    std::cout << "sizeof truck_count : " << sizeof(truck_count) << std::endl;
    return 0;
}
```
```text
Bike count : 2
Truck count : 7
Vehicle count : 9
Narrowing conversion : 2
sizeof int : 4
sizeof truck_count : 4
```

#### signed en unsigned [▶ 03:44:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13474s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int value1{10};
    int value2{-300};          // int is standaard signed
    signed int value3{-50};    // expliciet signed: hetzelfde effect
    unsigned int value4{4};    // alleen niet-negatieve waarden
    // unsigned int value5{-5}; // compilerfout: narrowing van -5 naar unsigned int

    std::cout << "value1 : " << value1 << std::endl;
    std::cout << "value2 : " << value2 << std::endl;
    std::cout << "value3 : " << value3 << std::endl;
    std::cout << "value4 : " << value4 << std::endl;
    std::cout << "sizeof(value1) : " << sizeof(value1) << std::endl;
    std::cout << "sizeof(value2) : " << sizeof(value2) << std::endl;
    std::cout << "sizeof(value4) : " << sizeof(value4) << std::endl;
    return 0;
}
```
```text
value1 : 10
value2 : -300
value3 : -50
value4 : 4
sizeof(value1) : 4
sizeof(value2) : 4
sizeof(value4) : 4
```

#### Negatief getal in unsigned (compilerfout) [▶ 03:47:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13624s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: narrowing conversion of '-5' from 'int' to 'unsigned int'
int main() {
    unsigned int value4{-5};
    return 0;
}
```

#### short, int, long, long long [▶ 03:48:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=13720s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

int main() {
    short short_var{-32768};
    short int short_int{455};
    signed short signed_short{122};
    unsigned short int unsigned_short_int{456};

    int int_var{55};
    signed signed_var{66};
    unsigned int unsigned_int{123};

    long long_var{88};
    signed long int signed_long_int{44};
    unsigned long int unsigned_long_int{33};

    long long long_long{888};
    signed long long int signed_long_long_int{555};
    unsigned long long int unsigned_long_long_int{8888};

    std::cout << "short_var : " << short_var << ", size : " << sizeof(short_var) << " bytes" << std::endl;
    std::cout << "short_int : " << short_int << ", size : " << sizeof(short_int) << " bytes" << std::endl;
    std::cout << "signed_short : " << signed_short << ", size : " << sizeof(signed_short) << " bytes" << std::endl;
    std::cout << "unsigned_short_int : " << unsigned_short_int << ", size : " << sizeof(unsigned_short_int) << " bytes" << std::endl;
    std::cout << "int_var : " << int_var << ", size : " << sizeof(int_var) << " bytes" << std::endl;
    std::cout << "signed_var : " << signed_var << ", size : " << sizeof(signed_var) << " bytes" << std::endl;
    std::cout << "unsigned_int : " << unsigned_int << ", size : " << sizeof(unsigned_int) << " bytes" << std::endl;
    std::cout << "long_var : " << long_var << ", size : " << sizeof(long_var) << " bytes" << std::endl;
    std::cout << "signed_long_int : " << signed_long_int << ", size : " << sizeof(signed_long_int) << " bytes" << std::endl;
    std::cout << "unsigned_long_int : " << unsigned_long_int << ", size : " << sizeof(unsigned_long_int) << " bytes" << std::endl;
    std::cout << "long_long : " << long_long << ", size : " << sizeof(long_long) << " bytes" << std::endl;
    std::cout << "signed_long_long_int : " << signed_long_long_int << ", size : " << sizeof(signed_long_long_int) << " bytes" << std::endl;
    std::cout << "unsigned_long_long_int : " << unsigned_long_long_int << ", size : " << sizeof(unsigned_long_long_int) << " bytes" << std::endl;
    return 0;
}
```
Voorbeeldoutput (Windows, GCC; op Linux is `long` 8 bytes):
```text
short_var : -32768, size : 2 bytes
short_int : 455, size : 2 bytes
signed_short : 122, size : 2 bytes
unsigned_short_int : 456, size : 2 bytes
int_var : 55, size : 4 bytes
signed_var : 66, size : 4 bytes
unsigned_int : 123, size : 4 bytes
long_var : 88, size : 4 bytes
signed_long_int : 44, size : 4 bytes
unsigned_long_int : 33, size : 4 bytes
long_long : 888, size : 8 bytes
signed_long_long_int : 555, size : 8 bytes
unsigned_long_long_int : 8888, size : 8 bytes
```

#### Groottes en precisie van floating point types [▶ 04:04:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14640s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>
#include <iomanip>   // voor std::setprecision

int main() {
    float number1{1.12345678901234567890f};          // precisie ~7
    double number2{1.12345678901234567890};          // precisie ~15
    long double number3{1.12345678901234567890L};    // precisie > 15

    std::cout << "sizeof float : " << sizeof(float) << std::endl;
    std::cout << "sizeof double : " << sizeof(double) << std::endl;
    std::cout << "sizeof long double : " << sizeof(long double) << std::endl;

    std::cout << std::setprecision(20);   // toon maximaal 20 cijfers
    std::cout << "number1 is : " << number1 << std::endl;
    std::cout << "number2 is : " << number2 << std::endl;
    std::cout << "number3 is : " << number3 << std::endl;
    return 0;
}
```
Voorbeeldoutput (Windows, GCC/MinGW-w64):
```text
sizeof float : 4
sizeof double : 8
sizeof long double : 16
number1 is : 1.1234568357467651367
number2 is : 1.1234567890123456912
number3 is : 1.1234567890123456789
```

#### Narrowing en de f-suffix [▶ 04:07:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=14837s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setprecision(20);

    float number4{192400023.0f};          // te veel cijfers voor een float
    double number4b{192400023.0f};        // double, maar literal is nog float!
    double number4c{192400023.0};         // double-literal: correct
    float number4d(192400023.0f);         // functional: zelfde verlies
    float number4e = 192400023.0f;        // assignment: zelfde verlies

    std::cout << "number4  : " << number4 << std::endl;
    std::cout << "number4b : " << number4b << std::endl;
    std::cout << "number4c : " << number4c << std::endl;
    std::cout << "number4d : " << number4d << std::endl;
    std::cout << "number4e : " << number4e << std::endl;
    return 0;
}
```
```text
number4  : 192400016
number4b : 192400016
number4c : 192400023
number4d : 192400016
number4e : 192400016
```

#### Scientific notation [▶ 04:11:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15077s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    double number5{192400023};          // fixed notation
    double number6{1.92400023e8};       // scientific: 1.92400023 x 10^8
    double number7{1.924e8};            // laatste cijfers worden nullen
    double number8{0.00000000003498};   // fixed notation, heel klein
    double number9{3.498e-11};          // scientific: 3.498 x 10^-11

    std::cout << std::fixed;            // forceer vaste notatie voor de grote getallen
    std::cout.precision(0);
    std::cout << "number5 : " << number5 << std::endl;
    std::cout << "number6 : " << number6 << std::endl;
    std::cout << "number7 : " << number7 << std::endl;
    std::cout << std::defaultfloat;     // terug naar standaardnotatie
    std::cout.precision(6);
    std::cout << "number8 : " << number8 << std::endl;
    std::cout << "number9 : " << number9 << std::endl;
    return 0;
}
```
```text
number5 : 192400023
number6 : 192400023
number7 : 192400000
number8 : 3.498e-11
number9 : 3.498e-11
```
> 💡 Aanvulling: in de video stond `std::setprecision(20)` nog actief, waardoor de grote getallen volledig getoond werden. Hier wordt `std::fixed` met precisie 0 gebruikt om hetzelfde beeld te krijgen zonder lange staarten; die formatteringsopties komen in hoofdstuk 4 aan bod.

#### Infinity en NaN [▶ 04:13:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15224s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

int main() {
    double number10{5.6};
    double number11{};       // 0
    double number12{};       // 0
    double neg_number{-5.6};

    double result{number10 / number11};   // positief / 0 -> inf
    std::cout << number10 << "/" << number11 << " yields " << result << std::endl;
    std::cout << result << " + " << 10 << " yields " << result + 10 << std::endl;

    result = neg_number / number11;       // negatief / 0 -> -inf
    std::cout << neg_number << "/" << number11 << " yields " << result << std::endl;

    result = number11 / number12;         // 0 / 0 -> nan
    std::cout << number11 << "/" << number12 << " = " << result << std::endl;
    return 0;
}
```
Voorbeeldoutput (op sommige platforms verschijnt `-nan` in plaats van `nan`):
```text
5.6/0 yields inf
inf + 10 yields inf
-5.6/0 yields -inf
0/0 = nan
```

#### Booleans [▶ 04:19:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=15557s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    bool red_light{false};
    bool green_light{true};

    if (red_light == true) {
        std::cout << "Stop!" << std::endl;
    } else {
        std::cout << "Go through!" << std::endl;
    }

    if (green_light) {              // de variabele zelf is de test
        std::cout << "The light is green!" << std::endl;
    } else {
        std::cout << "The light is NOT green!" << std::endl;
    }

    std::cout << "sizeof(bool) : " << sizeof(bool) << std::endl;

    // standaard: 1 en 0
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;

    std::cout << std::boolalpha;    // vanaf nu true/false
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;
    return 0;
}
```
```text
Go through!
The light is green!
sizeof(bool) : 1
red_light : 0
green_light : 1
red_light : false
green_light : true
```

#### Characters en ASCII [▶ 04:28:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16132s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    char character1{'a'};
    char character2{'r'};
    char character3{'r'};
    char character4{'o'};
    char character5{'w'};

    std::cout << character1 << std::endl;
    std::cout << character2 << std::endl;
    std::cout << character3 << std::endl;
    std::cout << character4 << std::endl;
    std::cout << character5 << std::endl;

    std::cout << "sizeof(char) : " << sizeof(char) << std::endl;

    char value = 65;   // ASCII-code voor 'A'
    std::cout << "value : " << value << std::endl;                          // als teken
    std::cout << "value(int) : " << static_cast<int>(value) << std::endl;   // als getal
    return 0;
}
```
```text
a
r
r
o
w
sizeof(char) : 1
value : A
value(int) : 65
```

#### auto [▶ 04:34:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16472s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

int main() {
    auto var1{12};       // int
    auto var2{13.0};     // double
    auto var3{14.0f};    // float
    auto var4{15.0l};    // long double
    auto var5{'e'};      // char

    auto var6{123u};     // unsigned int
    auto var7{434ul};    // unsigned long
    auto var8{452ll};    // long long

    std::cout << "var1 occupies : " << sizeof(var1) << " bytes" << std::endl;
    std::cout << "var2 occupies : " << sizeof(var2) << " bytes" << std::endl;
    std::cout << "var3 occupies : " << sizeof(var3) << " bytes" << std::endl;
    std::cout << "var4 occupies : " << sizeof(var4) << " bytes" << std::endl;
    std::cout << "var5 occupies : " << sizeof(var5) << " bytes" << std::endl;
    std::cout << "var6 occupies : " << sizeof(var6) << " bytes" << std::endl;
    std::cout << "var7 occupies : " << sizeof(var7) << " bytes" << std::endl;
    std::cout << "var8 occupies : " << sizeof(var8) << " bytes" << std::endl;
    return 0;
}
```
Voorbeeldoutput (Windows, GCC):
```text
var1 occupies : 4 bytes
var2 occupies : 8 bytes
var3 occupies : 4 bytes
var4 occupies : 16 bytes
var5 occupies : 1 bytes
var6 occupies : 4 bytes
var7 occupies : 4 bytes
var8 occupies : 8 bytes
```
> ⚠️ Onduidelijk in opname: de docent zegt dat var3 "3 bytes" inneemt; een `float` is 4 bytes, zoals de uitvoer toont.

#### Assignments en de auto-valkuil [▶ 04:39:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=16766s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int var1{123};                      // initialisatie
    std::cout << "var1 : " << var1 << std::endl;
    var1 = 55;                          // assignment: nieuwe waarde
    std::cout << "var1 : " << var1 << std::endl;

    std::cout << std::endl;

    double var2{44.55};
    std::cout << "var2 : " << var2 << std::endl;
    var2 = 99.99;
    std::cout << "var2 : " << var2 << std::endl;

    std::cout << std::endl;

    bool state{false};
    std::cout << std::boolalpha;
    std::cout << "state : " << state << std::endl;
    state = true;
    std::cout << "state : " << state << std::endl;

    std::cout << std::endl;

    auto var3{333u};                    // afgeleid: unsigned int
    var3 = -22;                         // geen fout, maar stil omgezet!
    std::cout << "var3 : " << var3 << std::endl;
    return 0;
}
```
```text
var1 : 123
var1 : 55

var2 : 44.55
var2 : 99.99

state : false
state : true

var3 : 4294967274
```

### Valkuilen & veelgemaakte fouten

#### Niet-geïnitialiseerde variabelen
`int x;` bevat een garbage value. Dat sommige compilers er 0 in zetten, is toeval. Initialiseer altijd, minstens met `{}`.

#### Octale voorloopnul
`017` is octaal en dus 15, niet 17. Zet nooit "voor de mooiheid" een 0 voor een decimaal getal.

#### Stille narrowing bij () en =
`int x(2.9);` en `int x = 2.9;` geven stil `2`. Alleen `{}` houdt dit tegen met een compilerfout.

#### Vergeten float-suffix of foute suffix
Zonder `f` is een kommaliteral een `double`. Omgekeerd: `double d{192400023.0f};` verliest precisie omdat de literal zelf al een `float` is. Het type van de variabele redt dat niet meer.

#### Precisie van float overschatten
Een `float` heeft maar ~7 significante cijfers (inclusief die vóór de komma). Meer cijfers zijn junk.

#### Negatieve waarde in unsigned
Met accolades geeft `unsigned int x{-5};` een fout, maar een latere toekenning `x = -22;` (ook via `auto` met `u`-suffix) compileert zonder fout en geeft een enorm getal (4294967274).

#### auto verbergt het type
Bij `auto` zie je het type niet in de declaratie. Controleer het (hover in VS Code) voordat je waarden toekent.

#### nan en inf negeren
Delen door 0.0 crasht niet, maar geeft `inf` of `nan`. Daarmee verder rekenen levert onzin op.

#### Modifiers op kommagetallen
`short`, `long`, `unsigned` enz. zijn alleen voor integral types; `unsigned double` is een compilerfout.

#### char zonder enkele quotes
`char c{a};` zoekt een variabele `a`; je bedoelt `'a'`. En `char value = 65;` print `A`, niet `65`.

#### Groottes zijn platformafhankelijk
`long` is 4 bytes op Windows maar 8 op 64-bit Linux; `long double` kan 8, 12 of 16 bytes zijn. Gebruik `sizeof` in plaats van aannames.

### Best practices
- Gebruik standaard **braced initialization** (`{}`): de compiler stopt narrowing.
- Initialiseer elke variabele bij declaratie; `{}` geeft een veilige nulwaarde.
- Kies het type met voldoende bereik en precisie; `double` is de veilige standaard voor kommagetallen.
- Zet altijd de juiste suffix (`f` voor `float`, `L` voor `long double`, `u`/`ul`/`ll` voor integers als je dat type wilt).
- Gebruik `unsigned` alleen bewust, en wees extra voorzichtig met `auto` + `unsigned`.
- Gebruik `sizeof` om groottes te controleren in plaats van ze te veronderstellen.
- Gebruik `std::boolalpha` als je booleans leesbaar wilt printen.
- Gebruik `static_cast<int>(c)` om de numerieke waarde van een `char` te tonen.
- Kies de schrijfwijze (decimaal, hex, binair) die het best bij de taak past; het geheugen bevat hetzelfde.
- Geef variabelen duidelijke namen volgens de naamregels (letter of `_` vooraan, case sensitive).

### Samenvatting
- Alle data staat als bits in het geheugen; 8 bits = 1 byte. Met *n* bits: 0 tot 2ⁿ − 1 (unsigned).
- Talstelsels vertalen bits naar getallen: binair (`0b`), octaal (voorloopnul), hexadecimaal (`0x`); hex en octaal verkorten lange bitreeksen.
- Een variabele is een benoemd stuk geheugen van een bepaald type.
- Initialiseren kan met `{}`, `()` of `=`; alleen `{}` blokkeert narrowing (bv. 2.9 → `int`).
- `int` is meestal 4 bytes en standaard `signed`; `unsigned`, `short`, `long`, `long long` passen teken en bereik aan.
- `float` (4 B, ~7 cijfers), `double` (8 B, ~15 cijfers), `long double` (≥ double); suffixes `f` en `l` bepalen het literal-type.
- Floating point kent scientific notation (`1.924e8`, `3.498e-11`), `inf`, `-inf` en `nan`.
- `bool` (1 byte) bewaart `true`/`false`; print als 1/0 tenzij `std::boolalpha`.
- `char` (1 byte) bewaart een teken via ASCII; `static_cast<int>` toont de code.
- `auto` leidt het type af uit de initialisatie; assignment geeft een variabele later een nieuwe waarde, met de `unsigned`-valkuil bij negatieve waarden.

### Oefeningen
1. Schrijf een programma dat het getal 42 op vier manieren opslaat (decimaal, octaal, hexadecimaal, binair) en alle vier print.
2. Declareer `int a{}`, `int b(7.8)` en `int c = 3.99`, en print ze. Leg uit waarom `int d{7.8}` niet compileert.
3. Print met `sizeof` de grootte van `bool`, `char`, `short`, `int`, `long long`, `float` en `double`, en print de ASCII-codes van `'0'`, `'A'` en `'a'` met `static_cast<int>`.
4. Laat met `std::setprecision(10)` zien dat `float f{123456789.0f}` en `double d{123456789.0}` verschillende waarden printen. Print ook `1.0 / 0.0` en `-1.0 / 0.0` via variabelen.
5. Gebruik `auto x{10u};` en ken daarna `x = -1;` toe. Print `x` en `x + 1`. Verklaar de uitvoer.

<details><summary>Uitwerking</summary>

Oefening 1:
```cpp
#include <iostream>

int main() {
    int dec = 42;
    int oct = 052;          // 5*8 + 2 = 42
    int hex = 0x2A;         // 2*16 + 10 = 42
    int bin = 0b00101010;   // 32 + 8 + 2 = 42
    std::cout << dec << " " << oct << " " << hex << " " << bin << std::endl;
    return 0;
}
```
```text
42 42 42 42
```

Oefening 2 (`int d{7.8}` geeft een narrowing-fout, dus die regel staat in commentaar):
```cpp
#include <iostream>

int main() {
    int a{};        // 0
    int b(7.8);     // stil afgekapt tot 7
    int c = 3.99;   // stil afgekapt tot 3 (niet afgerond!)
    // int d{7.8};  // error: narrowing conversion
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    return 0;
}
```
```text
a : 0
b : 7
c : 3
```

Oefening 3:
```cpp
#include <iostream>

int main() {
    std::cout << "bool : " << sizeof(bool) << std::endl;
    std::cout << "char : " << sizeof(char) << std::endl;
    std::cout << "short : " << sizeof(short) << std::endl;
    std::cout << "int : " << sizeof(int) << std::endl;
    std::cout << "long long : " << sizeof(long long) << std::endl;
    std::cout << "float : " << sizeof(float) << std::endl;
    std::cout << "double : " << sizeof(double) << std::endl;

    char zero{'0'};
    char upper_a{'A'};
    char lower_a{'a'};
    std::cout << "'0' : " << static_cast<int>(zero) << std::endl;
    std::cout << "'A' : " << static_cast<int>(upper_a) << std::endl;
    std::cout << "'a' : " << static_cast<int>(lower_a) << std::endl;
    return 0;
}
```
```text
bool : 1
char : 1
short : 2
int : 4
long long : 8
float : 4
double : 8
'0' : 48
'A' : 65
'a' : 97
```

Oefening 4:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    float f{123456789.0f};
    double d{123456789.0};
    std::cout << std::setprecision(10);
    std::cout << "float  : " << f << std::endl;   // maar ~7 cijfers correct
    std::cout << "double : " << d << std::endl;

    double one{1.0};
    double zero{};
    std::cout << "1/0  : " << one / zero << std::endl;
    std::cout << "-1/0 : " << -one / zero << std::endl;
    return 0;
}
```
```text
float  : 123456792
double : 123456789
1/0  : inf
-1/0 : -inf
```

Oefening 5: `-1` wordt omgezet naar de grootste `unsigned int` (2³² − 1). Daar 1 bij optellen loopt rond naar 0 (unsigned rekenen is modulo 2³²).
```cpp
#include <iostream>

int main() {
    auto x{10u};    // unsigned int
    x = -1;         // geen fout: stil omgezet
    std::cout << "x : " << x << std::endl;
    std::cout << "x + 1 : " << x + 1 << std::endl;
    return 0;
}
```
```text
x : 4294967295
x + 1 : 0
```
</details>

---

<a id="h04"></a>

## Hoofdstuk 4 – Operations on data (04:46:46 – 07:01:58) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17206s)

### Leerdoelen

Na dit hoofdstuk kun je:

- rekenen met de operatoren `+`, `-`, `*`, `/` en `%` en uitleggen waarom integer-deling het fractionele deel weggooit;
- met de regels van **precedence** (voorrang) en **associativity** (richting) voorspellen hoe een expressie met meerdere operatoren wordt uitgerekend, en met haakjes je bedoeling expliciet maken;
- het verschil uitleggen tussen **prefix** (`++x`, `--x`) en **postfix** (`x++`, `x--`) increment en decrement;
- **compound assignment**-operatoren gebruiken (`+=`, `-=`, `*=`, `/=`, `%=`);
- waarden vergelijken met **relational operators** (`<`, `<=`, `>`, `>=`, `==`, `!=`) en weten waarom je ze tussen haakjes zet in een `std::cout`-statement;
- **logical operators** (`&&`, `||`, `!`) toepassen en combineren met relational operators;
- output opmaken met manipulators uit `<ios>` en `<iomanip>`: `std::endl`, `std::flush`, `std::setw`, `std::left`/`std::right`/`std::internal`, `std::setfill`, `std::boolalpha`, `std::showpos`, `std::dec`/`std::hex`/`std::oct`, `std::showbase`, `std::uppercase`, `std::fixed`/`std::scientific`, `std::setprecision`, `std::showpoint`;
- met `std::numeric_limits` het bereik van een type opvragen;
- de belangrijkste functies uit `<cmath>` gebruiken (`floor`, `ceil`, `abs`, `exp`, `pow`, `log`, `log10`, `sqrt`, `round`, ...);
- uitleggen waarom het resultaat van `short + short` of `char + char` een `int` is.

### Verband met eerdere hoofdstukken

- In **hoofdstuk 3** heb je variabelen en datatypes leren declareren en initialiseren (`int`, modifiers zoals `short`/`unsigned`, `float`/`double`/`long double`, `bool`, `char`, `auto`). In dit hoofdstuk ga je met die data **rekenen, vergelijken en ze netjes tonen**.
- De talstelsels uit hoofdstuk 3 (decimaal, hexadecimaal, octaal) komen terug bij `std::hex`, `std::oct` en `std::showbase`.
- De handmatige berekening van het bereik van integer-types (hoofdstuk 3) wordt hier bevestigd met `std::numeric_limits`.
- `std::boolalpha` en `std::setprecision` zag je al kort in hoofdstuk 3; hier worden ze volledig uitgewerkt.
- `sizeof` (hoofdstuk 3) gebruik je opnieuw om te zien dat kleine integer-types bij rekenen naar `int` worden omgezet.
- Vooruitblik: relational en logical operators zijn de bouwstenen voor de condities in **hoofdstuk 5** (flow control: `if`, `switch`, ternary).

### Uitleg

#### Basisrekenkunde: `+`, `-`, `*`, `/`, `%`

C++ heeft de gebruikelijke rekenkundige operatoren. Je combineert twee waarden (operands) met een operator en slaat het resultaat op in een variabele:

- `+` optellen, `-` aftrekken (het resultaat kan negatief zijn: `2 - 7` geeft `-5`), `*` vermenigvuldigen (de "ster", zoals in bijna alle programmeertalen).
- `/` delen. **Let op bij integers**: als beide operands integers zijn, krijg je **integer-deling**. C++ kijkt hoeveel keer de deler volledig in het getal past; het fractionele deel wordt gewoon weggegooid (afgekapt). `31 / 10` geeft `3`, `7 / 2` geeft `3`. Een `int` kan nu eenmaal geen fractie bevatten.
- `%` is de **modulus**-operator: hij geeft de **rest** van de deling. `31 % 10` = `1` (10 past 3 keer in 31, rest 1), `7 % 2` = `1`. Dit lijkt in het begin vreemd, maar het is in veel toepassingen nuttig (bijvoorbeeld testen of een getal even is).

De docent benadrukt dat je `+`, `-`, `*`, `/` op alle getallen kunt toepassen, maar dat modulus alleen zinvol is voor **integral types**; op floating-point getallen werkt `%` niet.

> 💡 Aanvulling: wil je toch een rest bij floating-point getallen, dan gebruik je `std::fmod` uit `<cmath>`. En wil je bij delen van twee `int`s een fractie, maak dan minstens één operand een `double`, bv. `static_cast<double>(7) / 2` geeft `3.5`.

Tijdlink: [▶ 04:47:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17251s) (slides), [▶ 04:50:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17446s) (in VS Code)

#### Precedence en associativity

Als een expressie meerdere operatoren bevat, zoals `a + b * c - d / e - f + g`, heb je **regels** nodig om te weten wat eerst gebeurt; anders kan iedereen een ander antwoord vinden.

- **Precedence** (voorrang) bepaalt **welke operator eerst** wordt uitgevoerd. `*`, `/` en `%` hebben een hogere precedence dan `+` en `-`. Dus eerst `b * c` en `d / e`, daarna pas optellen en aftrekken.
- **Associativity** bepaalt **in welke richting** operatoren met dezelfde precedence worden uitgewerkt: van links naar rechts (left-to-right) of van rechts naar links (right-to-left). `+`, `-`, `*`, `/` zijn allemaal left-to-right.

Deze regels staan in de **C++ Operator Precedence**-tabel op cppreference.com. De docent raadt aan die tabel te raadplegen telkens je een nieuwe operator leert, zodat je weet waar hij in de tabel zit.

Uitgewerkt voorbeeld met `a=6, b=3, c=8, d=9, e=3, f=2, g=5`:

1. `a + b * c - d / e - f + g`: eerst `b*c = 24` en `d/e = 3`; dan van links naar rechts `6 + 24 = 30`, `30 - 3 = 27`, `27 - 2 = 25`, `25 + 5 = 30`.
2. `a / b * c + d - e + f`: `/` en `*` hebben dezelfde precedence en zijn left-to-right, dus eerst `a / b = 2`, dan `2 * c = 16`; daarna `16 + 9 = 25`, `25 - 3 = 22`, `22 + 2 = 24`. (De docent vergiste zich eerst in de waarde van `f` en corrigeerde dat.)

**Haakjes** doen twee dingen:

- ze maken je bedoeling **duidelijk** voor de lezer: `a + (b * c) - (d / e) - f + g` geeft hetzelfde (30), maar niemand hoeft de tabel op te zoeken;
- ze kunnen de standaardregels **overschrijven**: `(a + b) * c - d / e - f + g` rekent eerst `a + b = 9`, dan `9 * 8 = 72`, dan `72 - 3 - 2 + 5 = 72`.

Advies van de docent: vertrouw als beginner niet te veel op de precedence-tabel; maak je bedoeling expliciet met haakjes. Leesbaarheid is belangrijk.

Tijdlink: [▶ 04:57:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17876s), haakjes: [▶ 05:06:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=18412s)

#### Prefix en postfix increment/decrement

**Incrementeren** betekent iets bij een waarde optellen, **decrementeren** iets aftrekken. De klassieke manier is `value = value + 1;`. C++ heeft daar speciale operatoren voor:

- **Postfix** `value++` / `value--`: de **huidige** waarde wordt eerst gebruikt (bv. geprint), en pas **daarna** wordt de variabele met 1 verhoogd/verlaagd. `std::cout << value++;` met `value == 5` print `5`; het volgende gebruik van `value` vindt `6`.
- **Prefix** `++value` / `--value`: de variabele wordt **eerst** aangepast en daarna wordt de nieuwe waarde gebruikt. `std::cout << ++value;` met `value == 5` print `6`.

Belangrijk:

- Deze operatoren verhogen/verlagen **altijd met precies 1**. Je kunt geen andere stapgrootte opgeven; daarvoor gebruik je compound assignment (zie volgende onderwerp).
- Er bestaan **geen** vergelijkbare operatoren voor vermenigvuldigen of delen (zoals `**` of `//`).

Tijdlink: [▶ 05:11:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=18704s), in VS Code: [▶ 05:16:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=18992s)

#### Compound assignment

Compound assignment-operatoren voeren een rekenkundige bewerking uit **en** kennen het resultaat in één keer toe aan dezelfde variabele:

| Operator | Betekent |
|---|---|
| `value += 5;` | `value = value + 5;` |
| `value -= 5;` | `value = value - 5;` |
| `value *= 2;` | `value = value * 2;` |
| `value /= 3;` | `value = value / 3;` |
| `value %= 11;` | `value = value % 11;` |

De docent toont dat `value += 5` echt hetzelfde resultaat geeft als `value = value + 5`. Waarom dan deze vorm? Het is compacter, veel programmeurs (de docent incluis) vinden het prettiger, en je komt het overal tegen in bestaande C++-code.

Tijdlink: [▶ 05:23:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=19380s)

#### Relational operators

Relational operators **vergelijken** twee waarden: `<`, `<=`, `>`, `>=`, `==` (gelijk aan) en `!=` (niet gelijk aan). Het resultaat is een **`bool`**: `true` of `false`. Met `std::boolalpha` laat je `std::cout` die als `true`/`false` tonen in plaats van `1`/`0`.

Twee aandachtspunten:

- `==` (twee isgelijktekens) **vergelijkt**; `=` (één teken) **kent toe**: de waarde rechts wordt in de variabele links gezet. Een veel gemaakte fout.
- Zet de vergelijking **tussen haakjes** in een `std::cout`-statement: `std::cout << (number1 < number2)`. Zonder haakjes krijg je een vreemde compilerfout. De reden is precedence: de stream-operator `<<` staat in de tabel hoger (niveau 7) dan `<`/`>` (niveau 9) en `==`/`!=` (niveau 10). De compiler doet dus eerst `std::cout << number1` en probeert daarna het resultaat (een stream) met `<` te vergelijken met `number2`. Dat lukt niet.

> ⚠️ Onduidelijk in opname: de docent noemt de niveaus "11" voor `<<` en "9 en 8" voor de vergelijkingen. In de huidige cppreference-tabel is `<<` niveau 7, `<`/`>`/`<=`/`>=` niveau 9 en `==`/`!=` niveau 10 (lager getal = hogere precedence). De conclusie blijft dezelfde: `<<` bindt sterker.

Je kunt het resultaat van een vergelijking ook in een `bool`-variabele opslaan en later gebruiken: `bool result = (number1 == number2);`.

Tijdlink: [▶ 05:31:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=19861s), compilerfout zonder haakjes: [▶ 05:34:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20098s)

#### Logical operators

Logical operators werken op **boolean** operands:

| a | b | `a && b` (AND) | `a \|\| b` (OR) |
|---|---|---|---|
| false | false | false | false |
| false | true | false | true |
| true | false | false | true |
| true | true | true | true |

- **AND** (`&&`, twee ampersands): resultaat is `false` zodra **één** operand `false` is. Ook duizend keer `true` AND één `false` geeft `false`.
- **OR** (`||`, twee verticale strepen): resultaat is `true` zodra **één** operand `true` is.
- **NOT** (`!`, uitroepteken): keert de waarde om; `!true` is `false`, `!false` is `true`.

Je kunt ze **ketenen** (`a && b && c`) en **combineren** (`!(a && b) || c`). Ook hier gelden de precedence- en associativity-regels (`&&` en `||` zijn left-to-right: `a || b || c` wordt `(a || b) || c`), maar de docent gebruikt haakjes voor de duidelijkheid en om het `<<`-probleem te vermijden.

Je kunt logical operators combineren met relational operators, omdat die laatste ook een `bool` opleveren: `(d > e) && (d > f)`.

Je hoeft de waarheidstabellen niet uit het hoofd te leren; na een tijd zitten ze er vanzelf in, en anders zoek je ze op.

Tijdlink: [▶ 05:40:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20441s), in VS Code: [▶ 05:48:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20880s)

#### Output formatting: overzicht

Met **manipulators** bepaal je hoe data via `std::cout` op de terminal verschijnt. Zo maak je van een rommelige tabel een nette, uitgelijnde tabel. De manipulators komen uit twee headers:

| Header | Manipulators (selectie) |
|---|---|
| `<ios>` (via `<iostream>`) | `std::boolalpha`/`std::noboolalpha`, `std::showpos`/`std::noshowpos`, `std::dec`/`std::hex`/`std::oct`, `std::showbase`/`std::noshowbase`, `std::uppercase`/`std::nouppercase`, `std::fixed`/`std::scientific`, `std::showpoint`/`std::noshowpoint`, `std::left`/`std::right`/`std::internal` |
| `<ostream>` (via `<iostream>`) | `std::endl`, `std::flush` |
| `<iomanip>` | `std::setw`, `std::setfill`, `std::setprecision` |

De docent toont hoe je zelf de juiste header vindt: zoek bv. "std setw" op, open de pagina van **cppreference.com** en lees bovenaan "Defined in header `<iomanip>`". Hij benadrukt dat de documentatie, met haar voorbeeldcode onderaan elke pagina, van onschatbare waarde is.

Tijdlink: [▶ 05:56:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21365s), header opzoeken: [▶ 06:13:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22437s)

#### `std::endl` en `std::flush`

- `std::endl` zet een newline in de output, zodat de volgende tekst op een nieuwe regel komt. `"\n"` doet ogenschijnlijk hetzelfde, maar ze werken "onder de motorkap" anders; de docent gaat daar nog niet op in.
- `std::flush` stuurt de inhoud van de **output buffer** meteen naar de terminal. Wat is die buffer? Wanneer `std::cout` iets print, gaat de tekst niet meteen naar de terminal maar eerst naar een tussenliggende opslag. Pas als die buffer vol is, wordt alles in één keer doorgestuurd. Met `std::flush` forceer je dat het nu gebeurt. Je ziet in een eenvoudig programma geen verschil, maar het kan in sommige toepassingen belangrijk zijn.

> 💡 Aanvulling: het verschil tussen `std::endl` en `"\n"` is precies die buffer: `std::endl` = `"\n"` + `std::flush`. In code die veel print, is `"\n"` daarom sneller.

Tijdlink: [▶ 05:56:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21416s), flush: [▶ 05:58:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21514s)

#### `std::setw`, justification en `std::setfill`

- `std::setw(n)` (uit `<iomanip>`) geeft de **volgende** waarde een veld van `n` tekens breed. Als de tekst korter is, worden de overige posities met spaties opgevuld. Zo ontstaan nette kolommen.
- Tip van de docent: bewaar de breedte in een variabele (bv. `int col_width{14};`) en gebruik die overal. Wil je de breedte veranderen, dan pas je één plaats aan in plaats van tientallen.
- **Justification**: standaard staat data **rechts** uitgelijnd in het veld (`std::right`). Met `std::left` lijn je links uit. Met `std::internal` komt bij een negatief getal het **teken links** en het **getal rechts** in het veld, handig voor tabellen met getallen.
- `std::setfill(c)` bepaalt met welk teken lege posities worden opgevuld, bv. `'-'` of `'*'`.

Tijdlink: [▶ 05:59:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21561s), justification: [▶ 06:01:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21661s), in VS Code: [▶ 06:16:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22582s)

#### `std::boolalpha` en `std::showpos`

- `std::boolalpha` toont `bool`s als `true`/`false`; `std::noboolalpha` zet het terug naar `1`/`0` (de standaard).
- `std::showpos` toont een `+` voor positieve getallen; `std::noshowpos` zet dat weer uit (de standaard). Het minteken van negatieve getallen wordt altijd getoond, ongeacht deze instelling.

Tijdlink: [▶ 06:01:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21709s), showpos: [▶ 06:02:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21757s)

#### Talstelsels: `std::dec`, `std::hex`, `std::oct`, `std::showbase`, `std::uppercase`

- `std::dec`, `std::hex` en `std::oct` tonen integers in decimaal, hexadecimaal of octaal. Bij een negatief `int` zie je in hex/oct de two's-complement-bitpatronen.
- Dit heeft **geen effect op floating-point getallen**: die worden anders in het geheugen opgeslagen (een geavanceerd formaat dat buiten het bestek van de cursus valt).
- **Let op**: de instelling **blijft actief** ("sticky"). Na `std::oct` wordt alles in octaal getoond tot je zelf terugschakelt met `std::dec`.
- `std::showbase` toont het prefix van het talstelsel: niets voor decimaal, `0x` voor hex, `0` voor octaal.
- `std::uppercase` toont de letters in hexadecimale getallen (en `0X`) in hoofdletters; standaard zijn ze klein.

Tijdlink: [▶ 06:03:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21806s), showbase: [▶ 06:04:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21857s), uppercase: [▶ 06:05:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21905s)

#### Floating-point formaat: `std::fixed`, `std::scientific` en terug naar de standaard

- Standaard toont `std::cout` floating-point getallen met decimaal punt en schakelt het **waar nodig** over naar wetenschappelijke notatie (bv. `1.34e-10` = 1,34 × 10⁻¹⁰).
- `std::fixed` forceert vaste notatie met (standaard) 6 cijfers na de komma. Een heel klein getal zoals `1.34e-10` wordt dan `0.000000`: met die precisie is het getal niet van nul te onderscheiden.
- `std::scientific` forceert wetenschappelijke notatie voor alles.
- Er is **geen officiële manipulator** om terug te keren naar de standaardweergave. De docent gebruikt een "hack" die hij niet verder uitlegt: `std::cout.unsetf(std::ios::scientific | std::ios::fixed);`.

> 💡 Aanvulling: sinds C++11 bestaat `std::defaultfloat`, dat precies dit doet: `std::cout << std::defaultfloat;`.

Tijdlink: [▶ 06:05:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=21951s), hack: [▶ 06:07:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22047s)

#### `std::setprecision` en `std::showpoint`

- `std::setprecision(n)` bepaalt met hoeveel (significante) cijfers een floating-point getal wordt getoond; de standaard is 6. Je kunt 10, 20, 50 vragen, maar het type beperkt wat zinvol is: `float` ongeveer 7 cijfers, `double` ongeveer 15, `long double` minstens zoveel als `double`. Cijfers voorbij die grens zijn **"garbage"**: ze tonen de binaire benadering, niet je oorspronkelijke getal.
- Ook `setprecision` is sticky: in de demo van de docent stond de precisie nog op 20 van het vorige voorbeeld, waardoor latere getallen met veel cijfers verschenen.
- `std::showpoint` forceert het tonen van het **decimaal punt**, ook bij getallen als `12.0` (die standaard als `12` verschijnen). Bijwerking: er worden ook **trailing zeros** getoond tot de precisie gevuld is (`12.0000`).

Tijdlink: [▶ 06:07:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22047s), showpoint: [▶ 06:09:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22144s)

#### `std::numeric_limits`

In hoofdstuk 3 moest je het bereik van een type met een formule uitrekenen, en voor floating-point types was dat erg lastig. De header `<limits>` biedt een gestandaardiseerde manier om eigenschappen van rekenkundige types op te vragen:

```
std::numeric_limits<T>::min()
std::numeric_limits<T>::max()
std::numeric_limits<T>::lowest()
```

Zie `T` als **placeholder** voor het type dat je wilt onderzoeken (de docent zegt: laat je niet afschrikken door de template-syntax).

- Voor **floating-point** types: `min()` = het **kleinste positieve** getal dat je kunt voorstellen, `max()` = het grootste getal, `lowest()` = het **laagste (meest negatieve)** getal.
- Voor **integer** types: `min()` = het kleinste getal (negatief bij signed, `0` bij unsigned), `max()` = het grootste. `lowest()` voegt hier niets toe (het is gelijk aan `min()`).

Er zijn nog meer eigenschappen, zoals `is_signed` (is het type signed?) en `digits` (aantal bits/cijfers zonder tekenbit). Voor de volledige lijst verwijst de docent naar cppreference.

Tijdlink: [▶ 06:33:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23598s), in VS Code: [▶ 06:35:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23744s)

#### Math functions uit `<cmath>`

De standaardbibliotheek heeft wiskundige functies in de header `<cmath>`:

| Functie | Betekenis | Voorbeeld |
|---|---|---|
| `std::floor(x)` | naar beneden afronden | `floor(7.7)` = 7 |
| `std::ceil(x)` | naar boven afronden | `ceil(7.7)` = 8 |
| `std::abs(x)` | absolute waarde ("grootte zonder teken") | `abs(-5000)` = 5000 |
| `std::exp(x)` | e^x, met e ≈ 2.71828 | `exp(10)` ≈ 22026.5 |
| `std::pow(a, b)` | a tot de macht b | `pow(3, 4)` = 81 |
| `std::log(x)` | natuurlijke logaritme (grondtal e): "tot welke macht moet ik e verheffen om x te krijgen?" | `log(54.59)` ≈ 4 |
| `std::log10(x)` | logaritme met grondtal 10 | `log10(10000)` = 4 |
| `std::sqrt(x)` | vierkantswortel | `sqrt(81)` = 9 |
| `std::round(x)` | afronden; halverwege (x.5) **weg van nul** | `round(2.5)` = 3, `round(2.4)` = 2 |
| `std::sin`, `std::cos`, `std::tan` | goniometrie | |

De logaritme is het omgekeerde van de machtsverheffing: log₂ 8 = 3 omdat 2³ = 8. De docent controleert `exp(10)` met de Windows-rekenmachine (22026,47...) en ziet dat het programma door de standaardprecisie van 6 cijfers `22026.5` toont. Op cppreference vind je de volledige lijst (ook `remainder`, `fmin`, ...) met voorbeeldcode.

Tijdlink: [▶ 06:40:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=24034s), in VS Code: [▶ 06:46:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=24414s)

#### Weird integral types

Integral types die **kleiner dan 4 bytes** zijn (`char` = 1 byte, `short int` = meestal 2 bytes) ondersteunen volgens de docent geen rekenkundige bewerkingen rechtstreeks. Dat heeft met het processorontwerp te maken: `int` is gekozen als kleinste type waarop gerekend wordt. De compiler is slim genoeg om dat op te merken en zet de kleinere operands **impliciet om naar `int`** voordat hij rekent. Het resultaat is dus ook een `int`.

Gevolg: `short + short` geeft een `int` (4 bytes), niet een `short`; `char + char` geeft ook een `int`. Met `auto result = var1 + var2;` zie je dat `sizeof(result)` 4 is. Als de logica van je programma afhangt van de grootte van data, kan dit je bijten, en zulke fouten zijn moeilijk te vinden. Hetzelfde gedrag zie je bij de shift-operators (`<<`, `>>` op bits), die later in de cursus aan bod komen.

> 💡 Aanvulling: de officiële naam van dit mechanisme is **integral promotion**. Strikt genomen "kan" je wel met `short` rekenen; de taal schrijft alleen voor dat de operands eerst worden gepromoveerd naar `int`.

Tijdlink: [▶ 06:54:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=24857s), in VS Code: [▶ 06:56:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25002s)

### Codevoorbeelden

#### Basisrekenkunde [▶ 04:50:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=17446s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int number1{2};
    int number2{7};

    // Addition
    int result = number1 + number2;
    std::cout << "result : " << result << std::endl;

    // Subtraction
    result = number2 - number1;
    std::cout << "result : " << result << std::endl;
    result = number1 - number2; // negatief resultaat
    std::cout << "result : " << result << std::endl;

    // Multiplication
    result = number1 * number2;
    std::cout << "result : " << result << std::endl;

    // Division: integer-deling, fractie wordt afgekapt
    result = number2 / number1; // 7 / 2 -> 3
    std::cout << "result : " << result << std::endl;

    // Modulus: rest van de deling
    result = number2 % number1; // 7 % 2 -> 1
    std::cout << "result : " << result << std::endl;

    result = 31 % 10; // 10 past 3 keer in 31, rest 1
    std::cout << "result : " << result << std::endl;

    return 0;
}
```

```text
result : 9
result : 5
result : -5
result : 14
result : 3
result : 1
result : 1
```

#### Precedence, associativity en haakjes [▶ 05:02:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=18122s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int a{6};
    int b{3};
    int c{8};
    int d{9};
    int e{3};
    int f{2};
    int g{5};

    // * en / eerst, dan + en - van links naar rechts
    int result = a + b * c - d / e - f + g; // 6 + 24 - 3 - 2 + 5
    std::cout << "result : " << result << std::endl;

    // / en * hebben dezelfde precedence: left-to-right
    result = a / b * c + d - e + f; // (6/3)*8 + 9 - 3 + 2
    std::cout << "result : " << result << std::endl;

    // Haakjes maken de bedoeling duidelijk (zelfde resultaat)
    result = a + (b * c) - (d / e) - f + g;
    std::cout << "result : " << result << std::endl;

    // Haakjes overschrijven de standaardregels
    result = (a + b) * c - d / e - f + g; // 9*8 - 3 - 2 + 5
    std::cout << "result : " << result << std::endl;

    return 0;
}
```

```text
result : 30
result : 24
result : 30
result : 72
```

#### Prefix en postfix increment/decrement [▶ 05:16:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=18992s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int value{5};

    // De klassieke manier
    value = value + 1;
    std::cout << "The value is : " << value << std::endl; // 6
    value = 5; // reset
    value = value - 1;
    std::cout << "The value is : " << value << std::endl; // 4

    std::cout << "------------------------" << std::endl;

    // Postfix: eerst gebruiken, dan verhogen/verlagen
    value = 5;
    std::cout << "The value is (incrementing) : " << value++ << std::endl; // 5
    std::cout << "The value is : " << value << std::endl;                  // 6

    value = 5;
    std::cout << "The value is (decrementing) : " << value-- << std::endl; // 5
    std::cout << "The value is : " << value << std::endl;                  // 4

    std::cout << "------------------------" << std::endl;

    // Prefix: eerst verhogen/verlagen, dan gebruiken
    value = 5;
    ++value;
    std::cout << "The value is (prefix ++ apart) : " << value << std::endl; // 6

    value = 5;
    std::cout << "The value is (prefix ++ in place) : " << ++value << std::endl; // 6

    value = 5;
    --value;
    std::cout << "The value is (prefix -- apart) : " << value << std::endl; // 4

    value = 5;
    std::cout << "The value is (prefix -- in place) : " << --value << std::endl; // 4

    return 0;
}
```

```text
The value is : 6
The value is : 4
------------------------
The value is (incrementing) : 5
The value is : 6
The value is (decrementing) : 5
The value is : 4
------------------------
The value is (prefix ++ apart) : 6
The value is (prefix ++ in place) : 6
The value is (prefix -- apart) : 4
The value is (prefix -- in place) : 4
```

#### Compound assignment [▶ 05:27:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=19621s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int value{45};
    std::cout << "The value is : " << value << std::endl;

    value += 5; // value = value + 5
    std::cout << "The value is (after +=5) : " << value << std::endl;

    value -= 5; // value = value - 5
    std::cout << "The value is (after -=5) : " << value << std::endl;

    value *= 2; // value = value * 2
    std::cout << "The value is (after *=2) : " << value << std::endl;

    value /= 3; // value = value / 3
    std::cout << "The value is (after /=3) : " << value << std::endl;

    value %= 11; // value = value % 11 -> 30 % 11 = 8
    std::cout << "The value is (after %=11) : " << value << std::endl;

    return 0;
}
```

```text
The value is : 45
The value is (after +=5) : 50
The value is (after -=5) : 45
The value is (after *=2) : 90
The value is (after /=3) : 30
The value is (after %=11) : 8
```

#### Relational operators [▶ 05:33:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20004s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int number1{45};
    int number2{60};

    std::cout << "number1 : " << number1 << std::endl;
    std::cout << "number2 : " << number2 << std::endl;

    std::cout << std::boolalpha; // true/false i.p.v. 1/0
    // Haakjes rond de vergelijking zijn nodig (precedence van <<)
    std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
    std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
    std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

    // Resultaat opslaan in een bool en later gebruiken
    bool result = (number1 == number2);
    std::cout << number1 << " == " << number2 << " : " << result << std::endl;

    return 0;
}
```

```text
number1 : 45
number2 : 60
number1 < number2 : true
number1 <= number2 : true
number1 > number2 : false
number1 >= number2 : false
number1 == number2 : false
number1 != number2 : true
45 == 60 : false
```

#### Zonder haakjes: compilerfout [▶ 05:34:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20098s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: << heeft hogere precedence dan <, dus (std::cout << number1) < number2
#include <iostream>

int main() {
    int number1{45};
    int number2{60};
    std::cout << number1 < number2 << std::endl; // compilerfout
    return 0;
}
```

De compiler geeft een lange, onduidelijke foutmelding (bv. "no match for 'operator<'"). Oplossing: `std::cout << (number1 < number2) << std::endl;`.

#### Logical operators [▶ 05:48:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=20880s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool a{true};
    bool b{false};
    bool c{true};

    std::cout << std::boolalpha;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    // AND: false zodra één operand false is
    std::cout << "Basic AND operations" << std::endl;
    std::cout << "a && b : " << (a && b) << std::endl;
    std::cout << "a && c : " << (a && c) << std::endl;
    std::cout << "a && b && c : " << (a && b && c) << std::endl;

    // OR: true zodra één operand true is
    std::cout << "Basic OR operations" << std::endl;
    std::cout << "a || b : " << (a || b) << std::endl;
    std::cout << "a || c : " << (a || c) << std::endl;
    std::cout << "a || b || c : " << (a || b || c) << std::endl;

    // NOT: keert om
    std::cout << "Basic NOT operations" << std::endl;
    std::cout << "!a : " << !a << std::endl;
    std::cout << "!b : " << !b << std::endl;
    std::cout << "!c : " << !c << std::endl;

    // Combinaties
    std::cout << "Combinations" << std::endl;
    std::cout << "(a && b) || c : " << ((a && b) || c) << std::endl;
    std::cout << "!(a && b) || c : " << (!(a && b) || c) << std::endl;

    // Logical + relational operators
    int d{45};
    int e{20};
    int f{11};
    std::cout << "d : " << d << ", e : " << e << ", f : " << f << std::endl;
    std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl;
    std::cout << "(d == e) || (e <= f) : " << ((d == e) || (e <= f)) << std::endl;
    std::cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << std::endl;
    std::cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << std::endl;
    std::cout << "!(d > e) && (d > f) : " << (!(d > e) && (d > f)) << std::endl;

    return 0;
}
```

```text
a : true
b : false
c : true
Basic AND operations
a && b : false
a && c : true
a && b && c : false
Basic OR operations
a || b : true
a || c : true
a || b || c : true
Basic NOT operations
!a : false
!b : true
!c : false
Combinations
(a && b) || c : true
!(a && b) || c : true
d : 45, e : 20, f : 11
(d > e) && (d > f) : true
(d == e) || (e <= f) : false
(d < e) || (d > f) : true
(f > e) || (d < f) : false
!(d > e) && (d > f) : false
```

#### `std::endl` en `std::flush` [▶ 06:10:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22243s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Zonder newline: alles op één regel
    std::cout << "Hello";
    std::cout << "World";

    std::cout << std::endl;

    // Met std::endl: aparte regels
    std::cout << "Hello" << std::endl;
    std::cout << "World" << std::endl;

    std::cout << std::endl;

    // "\n" heeft hetzelfde zichtbare effect
    std::cout << "Hello\n";
    std::cout << "World\n";

    // std::flush: buffer meteen naar de terminal sturen
    std::cout << "This is a nice message...." << std::endl << std::flush;

    return 0;
}
```

```text
HelloWorld
Hello
World

Hello
World
This is a nice message....
```

#### `std::setw`: ongeformatteerde vs. geformatteerde tabel [▶ 06:13:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22437s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <iomanip> // std::setw

int main() {
    std::cout << "Unformatted table : " << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "Stanley" << " " << "Woods" << " 33" << std::endl;
    std::cout << "Jordan" << " " << "Parker" << " 45" << std::endl;

    std::cout << std::endl;

    // Breedte in een variabele: makkelijk aan te passen
    int col_width{14};

    std::cout << "Formatted table : " << std::endl;
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname"
              << std::setw(col_width / 2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Gray" << std::setw(col_width) << "Daniel"
              << std::setw(col_width / 2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Woods" << std::setw(col_width) << "Stanley"
              << std::setw(col_width / 2) << "33" << std::endl;
    std::cout << std::setw(col_width) << "Parker" << std::setw(col_width) << "Jordan"
              << std::setw(col_width / 2) << "45" << std::endl;

    return 0;
}
```

```text
Unformatted table : 
Daniel Gray 25
Stanley Woods 33
Jordan Parker 45

Formatted table : 
      Lastname     Firstname    Age
          Gray        Daniel     25
         Woods       Stanley     33
        Parker        Jordan     45
```

#### Justification (`std::left`, `std::right`, `std::internal`) en `std::setfill` [▶ 06:16:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22582s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int col_width{10};

    // Standaard: rechts uitgelijnd
    std::cout << "Right justified (default) :" << std::endl;
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::endl;
    std::cout << std::setw(col_width) << "Woods" << std::setw(col_width) << "Gray" << std::endl;

    std::cout << std::endl;

    // Links uitlijnen (blijft actief tot je het wijzigt)
    std::cout << "Left justified :" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::endl;
    std::cout << std::setw(col_width) << "Woods" << std::setw(col_width) << "Gray" << std::endl;

    std::cout << std::endl;

    // Internal: teken links, getal rechts
    std::cout << std::right;
    std::cout << "right    : " << std::setw(10) << -123.45 << std::endl;
    std::cout << std::internal;
    std::cout << "internal : " << std::setw(10) << -123.45 << std::endl;

    std::cout << std::endl;

    // setfill: lege posities opvullen met een ander teken
    std::cout << std::left << std::setfill('-');
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::endl;
    std::cout << std::setw(col_width) << "Woods" << std::setw(col_width) << "Gray" << std::endl;

    std::cout << std::setfill('*');
    std::cout << std::setw(col_width) << "Woods" << std::setw(col_width) << "Gray" << std::endl;

    return 0;
}
```

```text
Right justified (default) :
  Lastname Firstname
     Woods      Gray

Left justified :
Lastname  Firstname 
Woods     Gray      

right    :    -123.45
internal : -   123.45

Lastname--Firstname-
Woods-----Gray------
Woods*****Gray******
```

#### `std::boolalpha` en `std::showpos` [▶ 06:20:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22824s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool condition{true};
    bool other_condition{false};

    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;

    std::cout << std::boolalpha; // aanzetten
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;

    std::cout << std::noboolalpha; // terug naar 1/0
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;

    std::cout << std::endl;

    int pos_num{34};
    int neg_num{-45};

    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;

    std::cout << std::showpos; // + tonen bij positieve getallen
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;

    std::cout << std::noshowpos; // terug naar standaard
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;

    return 0;
}
```

```text
condition : 1
other_condition : 0
condition : true
other_condition : false
condition : 1
other_condition : 0

pos_num : 34
neg_num : -45
pos_num : +34
neg_num : -45
pos_num : 34
neg_num : -45
```

#### Talstelsels, `std::showbase` en `std::uppercase` [▶ 06:22:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=22920s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int pos_int{717171};
    int neg_int{-47347};
    double double_var{498.32};

    std::cout << "default base format : " << std::endl;
    std::cout << "pos_int : " << pos_int << std::endl;
    std::cout << "neg_int : " << neg_int << std::endl;
    std::cout << "double_var : " << double_var << std::endl;

    std::cout << "pos_int in different bases : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;

    std::cout << "neg_int in different bases : " << std::endl;
    std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;
    std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl;
    std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl;

    // Geen effect op floating-point getallen
    std::cout << "double_var in different bases : " << std::endl;
    std::cout << "double_var (dec) : " << std::dec << double_var << std::endl;
    std::cout << "double_var (hex) : " << std::hex << double_var << std::endl;
    std::cout << "double_var (oct) : " << std::oct << double_var << std::endl;

    // Sticky: we staan nog op octaal!
    std::cout << "pos_int (still oct) : " << pos_int << std::endl;
    std::cout << std::dec; // reset

    std::cout << std::endl;

    // showbase: prefix van het talstelsel tonen
    std::cout << std::showbase;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;

    std::cout << std::endl;

    // uppercase: hex-letters in hoofdletters
    std::cout << "pos_int (nouppercase) : " << std::hex << pos_int << std::endl;
    std::cout << std::uppercase;
    std::cout << "pos_int (uppercase) : " << std::hex << pos_int << std::endl;

    std::cout << std::dec << std::noshowbase << std::nouppercase; // alles resetten
    return 0;
}
```

```text
default base format : 
pos_int : 717171
neg_int : -47347
double_var : 498.32
pos_int in different bases : 
pos_int (dec) : 717171
pos_int (hex) : af173
pos_int (oct) : 2570563
neg_int in different bases : 
neg_int (dec) : -47347
neg_int (hex) : ffff470d
neg_int (oct) : 37777643415
double_var in different bases : 
double_var (dec) : 498.32
double_var (hex) : 498.32
double_var (oct) : 498.32
pos_int (still oct) : 2570563

pos_int (dec) : 717171
pos_int (hex) : 0xaf173
pos_int (oct) : 02570563

pos_int (nouppercase) : 0xaf173
pos_int (uppercase) : 0XAF173
```

#### `std::fixed`, `std::scientific` en terug naar de standaard [▶ 06:26:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23163s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    double a{3.1415926535897932384626433832795};
    double b{2006.0};
    double c{1.34e-10};

    std::cout << "double values (default) : " << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    std::cout << "double values (fixed) : " << std::endl;
    std::cout << std::fixed;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl; // te klein voor 6 decimalen

    std::cout << "double values (scientific) : " << std::endl;
    std::cout << std::scientific;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    // De "hack" van de docent om terug te gaan naar de standaard
    std::cout << "double values (back to defaults) : " << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    return 0;
}
```

```text
double values (default) : 
a : 3.14159
b : 2006
c : 1.34e-10
double values (fixed) : 
a : 3.141593
b : 2006.000000
c : 0.000000
double values (scientific) : 
a : 3.141593e+00
b : 2.006000e+03
c : 1.340000e-10
double values (back to defaults) : 
a : 3.14159
b : 2006
c : 1.34e-10
```

#### `std::setprecision` [▶ 06:28:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23307s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <iomanip> // std::setprecision

int main() {
    double a{3.141592653589793238462643383279502884197169399375105820974944592307816406286};

    std::cout << "a (default precision 6) : " << a << std::endl;
    std::cout << std::setprecision(10);
    std::cout << "a (precision 10) : " << a << std::endl;
    std::cout << std::setprecision(20);
    std::cout << "a (precision 20) : " << a << std::endl; // na ~15 cijfers: garbage
    std::cout << std::setprecision(50);
    std::cout << "a (precision 50) : " << a << std::endl;

    return 0;
}
```

```text
a (default precision 6) : 3.14159
a (precision 10) : 3.141592654
a (precision 20) : 3.141592653589793116
a (precision 50) : 3.141592653589793115997963468544185161590576171875
```

Vergelijk met de echte waarde van π (3.14159265358979323846...): vanaf het 16e/17e cijfer klopt de output niet meer. Dat zijn de "garbage"-cijfers waar de docent voor waarschuwt.

#### `std::showpoint` [▶ 06:30:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23402s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    double d{34.1};
    double e{101.99};
    double f{12.0};
    double g{23.0};

    std::cout << "noshowpoint (default) : " << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl; // 12, zonder punt
    std::cout << "g : " << g << std::endl;

    std::cout << "showpoint : " << std::endl;
    std::cout << std::showpoint; // punt + trailing zeros forceren
    std::cout << "d : " << d << std::endl;
    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl;
    std::cout << "g : " << g << std::endl;

    return 0;
}
```

```text
noshowpoint (default) : 
d : 34.1
e : 101.99
f : 12
g : 23
showpoint : 
d : 34.1000
e : 101.990
f : 12.0000
g : 23.0000
```

#### `std::numeric_limits` [▶ 06:35:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=23744s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << "The range for short int is from " << std::numeric_limits<short int>::min()
              << " to " << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "The range for unsigned short int is from " << std::numeric_limits<unsigned short int>::min()
              << " to " << std::numeric_limits<unsigned short int>::max() << std::endl;
    std::cout << "The range for int is from " << std::numeric_limits<int>::min()
              << " to " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min()
              << " to " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "The range for long int is from " << std::numeric_limits<long int>::min()
              << " to " << std::numeric_limits<long int>::max() << std::endl;

    // Floating point: min() = kleinste positieve, lowest() = meest negatieve
    std::cout << "The range for float is from " << std::numeric_limits<float>::min()
              << " to " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The range(with lowest) for float is from " << std::numeric_limits<float>::lowest()
              << " to " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The range(with lowest) for double is from " << std::numeric_limits<double>::lowest()
              << " to " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "The range(with lowest) for long double is from " << std::numeric_limits<long double>::lowest()
              << " to " << std::numeric_limits<long double>::max() << std::endl;

    // Andere eigenschappen
    std::cout << std::boolalpha;
    std::cout << "int is signed : " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "int digits : " << std::numeric_limits<int>::digits << std::endl;

    return 0;
}
```

Output met g++ (MinGW, Windows 64-bit; `long int` is daar 4 bytes, en `long double` hangt af van het platform):

```text
The range for short int is from -32768 to 32767
The range for unsigned short int is from 0 to 65535
The range for int is from -2147483648 to 2147483647
The range for unsigned int is from 0 to 4294967295
The range for long int is from -2147483648 to 2147483647
The range for float is from 1.17549e-38 to 3.40282e+38
The range(with lowest) for float is from -3.40282e+38 to 3.40282e+38
The range(with lowest) for double is from -1.79769e+308 to 1.79769e+308
The range(with lowest) for long double is from -1.18973e+4932 to 1.18973e+4932
int is signed : true
int digits : 31
```

#### Math functions [▶ 06:46:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=24414s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cmath>

int main() {
    double weight{7.7};

    // Afronden
    std::cout << "Weight rounded to floor is : " << std::floor(weight) << std::endl;
    std::cout << "Weight rounded to ceil is : " << std::ceil(weight) << std::endl;

    // Absolute waarde
    double savings{-5000};
    std::cout << "Abs of weight is : " << std::abs(weight) << std::endl;
    std::cout << "Abs of savings is : " << std::abs(savings) << std::endl;

    // Exponentiële functie: e^10
    double exponential = std::exp(10);
    std::cout << "The exponential of 10 is : " << exponential << std::endl;

    // Machten
    std::cout << "3 ^ 4 is : " << std::pow(3, 4) << std::endl;
    std::cout << "9 ^ 3 is : " << std::pow(9, 3) << std::endl;

    // Logaritmen: log() = grondtal e, log10() = grondtal 10
    std::cout << "To get 54.59, you'd elevate e to the power of : " << std::log(54.59) << std::endl;
    std::cout << "To get 10000, you'd elevate 10 to the power of : " << std::log10(10000) << std::endl;

    // Vierkantswortel
    std::cout << "The square root of 81 is : " << std::sqrt(81) << std::endl;

    // round: halverwege weg van nul
    std::cout << "3.654 rounded to : " << std::round(3.654) << std::endl;
    std::cout << "2.5 is rounded to : " << std::round(2.5) << std::endl;
    std::cout << "2.4 is rounded to : " << std::round(2.4) << std::endl;
    std::cout << "-2.5 is rounded to : " << std::round(-2.5) << std::endl;

    return 0;
}
```

```text
Weight rounded to floor is : 7
Weight rounded to ceil is : 8
Abs of weight is : 7.7
Abs of savings is : 5000
The exponential of 10 is : 22026.5
3 ^ 4 is : 81
9 ^ 3 is : 729
To get 54.59, you'd elevate e to the power of : 3.99985
To get 10000, you'd elevate 10 to the power of : 4
The square root of 81 is : 9
3.654 rounded to : 4
2.5 is rounded to : 3
2.4 is rounded to : 2
-2.5 is rounded to : -3
```

#### Weird integral types [▶ 06:57:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25050s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    short int var1{10}; // 2 bytes
    short int var2{20};

    char var3{40}; // 1 byte
    char var4{50};

    std::cout << "size of var1 : " << sizeof(var1) << std::endl;
    std::cout << "size of var2 : " << sizeof(var2) << std::endl;
    std::cout << "size of var3 : " << sizeof(var3) << std::endl;
    std::cout << "size of var4 : " << sizeof(var4) << std::endl;

    // Operands worden impliciet naar int omgezet -> resultaat is int
    auto result1 = var1 + var2;
    auto result2 = var3 + var4;

    std::cout << "size of result1 : " << sizeof(result1) << std::endl; // 4
    std::cout << "size of result2 : " << sizeof(result2) << std::endl; // 4
    std::cout << "result1 : " << result1 << ", result2 : " << result2 << std::endl;

    return 0;
}
```

Output op een typisch desktopplatform (sizes kunnen per platform verschillen):

```text
size of var1 : 2
size of var2 : 2
size of var3 : 1
size of var4 : 1
size of result1 : 4
size of result2 : 4
result1 : 30, result2 : 90
```

### Valkuilen & veelgemaakte fouten

#### Integer-deling gooit de fractie weg
`7 / 2` is `3`, niet `3.5`. Ook `double x = 7 / 2;` geeft `3.0`, want de deling gebeurt eerst met twee `int`s. Maak minstens één operand een floating-point waarde als je een fractie wilt.

#### Modulus op floating-point getallen
`%` werkt alleen voor integral types; `7.5 % 2` compileert niet.

> 💡 Aanvulling: gebruik `std::fmod(7.5, 2)` uit `<cmath>`.

#### `=` in plaats van `==`
`=` kent toe, `==` vergelijkt. `if (x = 5)` zet `x` op 5 en is altijd waar (wordt in hoofdstuk 5 relevant).

#### Vergelijking zonder haakjes in `std::cout`
`std::cout << a < b;` geeft een cryptische compilerfout omdat `<<` sterker bindt dan `<`. Schrijf `std::cout << (a < b);`. Hetzelfde geldt voor `&&`, `||` en combinaties.

#### Postfix vs. prefix verwarren
`std::cout << x++;` print de **oude** waarde; `std::cout << ++x;` print de **nieuwe**. En `++`/`--` werken alleen met stap 1.

#### Sticky manipulators vergeten te resetten
`std::hex`, `std::oct`, `std::left`, `std::setfill`, `std::setprecision`, `std::fixed`, `std::boolalpha`, `std::showpos`, ... blijven actief. Na `std::oct` wordt elke volgende integer octaal getoond. Uitzondering: `std::setw` geldt alleen voor de **volgende** waarde.

#### Te veel precisie vragen
`std::setprecision(50)` op een `double` levert cijfers op die niet bij je getal horen ("garbage"). Een `double` is maar op ongeveer 15 cijfers nauwkeurig.

#### `std::fixed` maakt kleine getallen nul
`1.34e-10` met `std::fixed` wordt `0.000000`. Gebruik scientific notation (of meer precisie) voor zeer kleine waarden.

#### `numeric_limits<float>::min()` is niet het meest negatieve getal
Voor floating-point types is `min()` het **kleinste positieve** getal. Voor het meest negatieve getal gebruik je `lowest()`.

#### Kleine integer-types worden `int` bij rekenen
`short + short` en `char + char` geven een `int`. Als je logica afhangt van `sizeof` (of je slaat het resultaat met `auto` op), is dat een verrassing die moeilijk op te sporen is.

### Best practices

- Gebruik **haakjes** om de volgorde van bewerkingen expliciet te maken; vertrouw niet op het geheugen van de lezer voor de precedence-tabel.
- Zet vergelijkingen en logische expressies in `std::cout` altijd tussen haakjes.
- Gebruik compound assignment (`+=`, `-=`, ...) voor compacte, gangbare code.
- Bewaar kolombreedtes voor `std::setw` in een variabele, zodat je ze op één plek kunt aanpassen.
- Reset sticky instellingen (`std::dec`, `std::noboolalpha`, ...) wanneer je ze niet meer nodig hebt.
- Gebruik `std::numeric_limits` in plaats van zelf bereiken uit te rekenen of getallen hard te coderen.
- Zoek bij twijfel de juiste header en het gedrag van een functie op in **cppreference.com**; probeer de voorbeeldcode zelf uit.
- Typ de voorbeelden zelf over en verander waarden: zo leer je de operatoren en manipulators echt kennen (advies van de docent).

### Samenvatting

- `+`, `-`, `*`, `/`, `%` zijn de basisoperatoren; integer-deling kapt af, `%` geeft de rest en werkt alleen voor integral types.
- **Precedence** bepaalt welke operator eerst gaat, **associativity** in welke richting; haakjes maken dit expliciet of overschrijven het.
- Postfix `x++` gebruikt eerst de oude waarde, prefix `++x` eerst de nieuwe; beide altijd met stap 1.
- Compound assignment (`+=`, `-=`, `*=`, `/=`, `%=`) combineert bewerking en toewijzing.
- Relational operators leveren een `bool`; zet ze tussen haakjes in `std::cout` vanwege de precedence van `<<`.
- Logical operators: `&&` is false bij één false, `||` is true bij één true, `!` keert om; ze combineren met relational operators.
- Manipulators uit `<ios>`/`<iomanip>` regelen breedte, uitlijning, vulteken, bool-weergave, plusteken, talstelsel, hoofdletters, fixed/scientific, precisie en decimaal punt; de meeste zijn sticky.
- `std::numeric_limits<T>` geeft `min()`, `max()`, `lowest()` en meer eigenschappen van een type.
- `<cmath>` biedt `floor`, `ceil`, `abs`, `exp`, `pow`, `log`, `log10`, `sqrt`, `round`, goniometrie en meer.
- Types kleiner dan `int` worden bij rekenen impliciet naar `int` omgezet; het resultaat is een `int`.

### Oefeningen

1. Lees twee gehele getallen in en toon hun som, verschil, product, quotiënt (integer-deling) en rest.
2. Bereken met `a=10, b=4, c=3` zonder te compileren: `a - b * c + a / b` en `(a - b) * (c + a) % b`. Controleer daarna met een programma.
3. Voorspel de output: `int x{3}; int y = x++ + 10; int z = ++x * 2;` en print `x`, `y`, `z`. Controleer daarna.
4. Een getal `n` (ingelezen) is "speciaal" als het even is **en** tussen 10 en 100 ligt (grenzen inbegrepen), **of** als het gelijk is aan 7. Print met `std::boolalpha` of het getal speciaal is.
5. Maak een nette prijstabel met drie producten (naam links uitgelijnd in 12 tekens, prijs rechts uitgelijnd in 10 tekens, `std::fixed` met 2 decimalen, puntjes als vulteken) en toon onderaan de totaalprijs. Toon ook de grootste waarde van een `unsigned short` met `std::numeric_limits` en de vierkantswortel van het totaal (afgerond met `std::round`).

<details><summary>Uitwerking</summary>

Oefening 1, met invoer `17 5`:

```cpp
// stdin: 17 5
#include <iostream>

int main() {
    int a{};
    int b{};
    std::cout << "Enter two integers : ";
    std::cin >> a >> b;

    std::cout << std::endl;
    std::cout << "sum : " << a + b << std::endl;
    std::cout << "difference : " << a - b << std::endl;
    std::cout << "product : " << a * b << std::endl;
    std::cout << "quotient : " << a / b << std::endl; // integer-deling
    std::cout << "remainder : " << a % b << std::endl;
    return 0;
}
```

```text
Enter two integers : 
sum : 22
difference : 12
product : 85
quotient : 3
remainder : 2
```

Oefening 2: `10 - 12 + 2 = 0` (want `10 / 4 = 2`) en `6 * 13 % 4 = 78 % 4 = 2` (`*` en `%` zelfde precedence, left-to-right).

```cpp
#include <iostream>

int main() {
    int a{10};
    int b{4};
    int c{3};
    std::cout << "a - b * c + a / b : " << a - b * c + a / b << std::endl;
    std::cout << "(a - b) * (c + a) % b : " << (a - b) * (c + a) % b << std::endl;
    return 0;
}
```

```text
a - b * c + a / b : 0
(a - b) * (c + a) % b : 2
```

Oefening 3: `y = 3 + 10 = 13` (x wordt daarna 4), dan `++x` maakt x 5 en `z = 10`.

```cpp
#include <iostream>

int main() {
    int x{3};
    int y = x++ + 10; // oude waarde 3 gebruikt, x wordt 4
    int z = ++x * 2;  // x wordt eerst 5
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
    return 0;
}
```

```text
x : 5, y : 13, z : 10
```

Oefening 4, met invoer `42`:

```cpp
// stdin: 42
#include <iostream>

int main() {
    int n{};
    std::cout << "Enter a number : ";
    std::cin >> n;

    bool special = ((n % 2 == 0) && (n >= 10) && (n <= 100)) || (n == 7);

    std::cout << std::endl << std::boolalpha;
    std::cout << n << " is special : " << special << std::endl;
    return 0;
}
```

```text
Enter a number : 
42 is special : true
```

Oefening 5:

```cpp
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main() {
    const int name_width{12};
    const int price_width{10};

    double price1{3.5};
    double price2{12.25};
    double price3{100.0};
    double total = price1 + price2 + price3;

    std::cout << std::fixed << std::setprecision(2) << std::setfill('.');
    std::cout << std::left << std::setw(name_width) << "Coffee"
              << std::right << std::setw(price_width) << price1 << std::endl;
    std::cout << std::left << std::setw(name_width) << "Book"
              << std::right << std::setw(price_width) << price2 << std::endl;
    std::cout << std::left << std::setw(name_width) << "Headphones"
              << std::right << std::setw(price_width) << price3 << std::endl;
    std::cout << std::left << std::setw(name_width) << "TOTAL"
              << std::right << std::setw(price_width) << total << std::endl;

    std::cout << std::setfill(' '); // reset vulteken
    std::cout.unsetf(std::ios::fixed); // terug naar standaardformaat

    std::cout << "max unsigned short : " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "rounded sqrt of total : " << std::round(std::sqrt(total)) << std::endl;
    return 0;
}
```

```text
Coffee............3.50
Book.............12.25
Headphones......100.00
TOTAL...........115.75
max unsigned short : 65535
rounded sqrt of total : 11
```

</details>

---

<a id="h05"></a>

## Hoofdstuk 5 – Flow control (07:01:58 – 07:53:49) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25318s)

### Leerdoelen

- Begrijpen wat *conditional programming* (voorwaardelijk programmeren) is en waarom een programma beslissingen moet kunnen nemen.
- Het `if`-statement schrijven, met een boolean variabele of rechtstreeks met een expressie als voorwaarde.
- Een `else`-clausule gebruiken om het "andere geval" op te vangen.
- `if`-statements nesten en geneste voorwaarden vervangen door logische operatoren (`&&`, `!`).
- Met een keten van `if` / `else if` / `else` uit meerdere mogelijkheden precies één tak kiezen.
- Het `switch`-statement gebruiken, inclusief `case`, `break`, `default`, fall-through en het groeperen van cases.
- Weten dat de expressie van een `switch` een integraal type (of enum) moet zijn, en dat `std::string` niet mag.
- De ternary operator `? :` lezen en schrijven, voor toekenning én initialisatie, en begrijpen welk type het resultaat krijgt.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 3 (Variables & data types):** de voorwaarden in dit hoofdstuk zijn `bool`-waarden. Ook `auto` komt terug, om te zien welk type de ternary operator oplevert. Integrale typen (`int`, `char`, `short`, `long`, `unsigned`) zijn precies de typen die een `switch` accepteert.
- **Hoofdstuk 4 (Operations on data):** relationele operatoren (`<`, `>`, `==`) leveren de booleans waarop we testen. Logische operatoren (`&&`, `||`, `!`) laten je voorwaarden combineren. Ook impliciete conversies (int ↔ float) komen terug bij de ternary operator.
- **Hoofdstuk 2:** `const` wordt gebruikt om de "tool"-constanten onveranderlijk te maken; `std::cout` voor alle output.
- **Vooruitblik:** hoofdstuk 6 (Loops) bouwt hierop voort: elke lus heeft een voorwaarde die op dezelfde manier wordt geëvalueerd. Enums, die de docent hier een paar keer noemt als betere manier om tools voor te stellen, komen later in de cursus.

### Uitleg

#### Wat is flow control?

Tot nu toe voerde elk programma zijn statements gewoon van boven naar beneden uit. In de praktijk wil je vaak iets *alleen* doen als aan een voorwaarde voldaan is. De docent gebruikt het voorbeeld van een verkeerslicht: een paar boolean variabelen `red`, `yellow`, `green` en `police_stop`. Is het licht rood, dan stop je; is het geel, dan vertraag je; is het groen, dan rijd je door. Dat is *conditional programming*.

C++ biedt hiervoor een aantal constructies, die in dit hoofdstuk één voor één aan bod komen:

- het keyword `if` (met eventueel `else`),
- `else if` om meerdere voorwaarden na elkaar te testen,
- het keyword `switch`,
- een aparte operator: de *ternary operator* `? :`.

Tijdlink: [▶ 07:02:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25341s)

#### Het if-statement

Een `if`-statement voert een stuk code alleen uit als een voorwaarde `true` is.

Syntax:

```
if (voorwaarde) {
    // body: wordt alleen uitgevoerd als voorwaarde true is
}
```

- Na `if` komt een paar haakjes met daarin de voorwaarde.
- Daarna volgt een blok tussen accolades: de *body* van het if-statement.
- De voorwaarde moet iets zijn dat als boolean behandeld kan worden: `true` of `false`.

Het voorbeeld van de docent: twee integers `number1 = 55` en `number2 = 60`. De vergelijking `number1 < number2` levert een `bool` op, die in de variabele `result` wordt opgeslagen. Daarna:

- `if (result == true)` → print "55 is less than 60".
- Om het omgekeerde geval te testen schrijft hij `if (!(result == true))`. Dat leest als "als niet (result is true)", en dat is hetzelfde als "als result false is". De docent geeft toe dat deze notatie voor beginners verwarrend kan zijn: laat het even rustig op je inwerken.

Omdat de twee tests elkaars exacte tegengestelde zijn, wordt altijd precies één van de twee bodies uitgevoerd. Verander je `number1` naar 65, dan wordt `result` false, faalt de eerste test en slaagt de tweede.

De docent benadrukt dat dit fundamenteel is, niet alleen in C++ maar in elke programmeercarrière.

Tijdlink: [▶ 07:03:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25389s) · demo [▶ 07:07:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25679s)

#### De else-clausule

Twee losse `if`-statements die elkaars tegengestelde testen is omslachtig. Met `else` vang je direct het geval op waarin de test *niet* slaagt:

```
if (result == true) {
    // voorwaarde waar
} else {
    // voorwaarde niet waar
}
```

Dit doet precies hetzelfde als de twee losse if's, maar is compacter en leesbaarder. Met 65 en 60 is `result` false, dus komt de uitvoering in de `else`-tak terecht: "65 is not less than 60".

Tijdlink: [▶ 07:11:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25918s)

#### Een expressie rechtstreeks als voorwaarde

Je hoeft het resultaat van een vergelijking niet eerst in een variabele op te slaan. Omdat `number1 < number2` zelf al een boolean oplevert, mag je de expressie direct tussen de haakjes zetten:

```
if (number1 < number2) { ... } else { ... }
```

Dat is volkomen legaal in C++. De docent test dit met 55/60 (eerste tak) en met 75/60 (else-tak).

Tijdlink: [▶ 07:13:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26011s)

#### Meerdere losse voorwaarden: het verkeerslicht

Met de verkeerslichtvariabelen (`red = false`, `yellow = false`, `green = true`, `police_stop = true`) schrijft de docent drie losse if-statements: rood → "Stop", geel → "Slow down", groen → "Go". Omdat alleen `green` true is, wordt "Go" geprint. `police_stop` speelt hier nog geen rol. De docent moedigt aan de booleans te veranderen en te kijken wat er gebeurt.

> 💡 Aanvulling: als boolean variabele schrijf je in de praktijk gewoon `if (red)` in plaats van `if (red == true)`. Dat is korter en betekent hetzelfde.

Tijdlink: [▶ 07:15:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26157s)

#### Geneste if-statements

Je kunt een `if`-statement binnen de body van een ander `if`-statement plaatsen. Bij het verkeerslicht: als het licht groen is, zou je mogen rijden, maar een politieagent mag je toch tegenhouden (zo zijn de regels in het land waar de docent woont). Dus:

- buitenste `if (green)`,
- daarbinnen `if (police_stop)` → "Stop", anders → "Go".

Met `green = true` en `police_stop = true` wordt "Stop" geprint.

Belangrijk punt dat de docent hier maakt: zodra één blok van een if/else-constructie slaagt en uitgevoerd wordt, worden de andere blokken (zoals de `else`) **niet** meer uitgevoerd. De controle springt naar het eerste statement na de hele constructie.

Tijdlink: [▶ 07:16:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26205s)

#### Voorwaarden combineren met logische operatoren

Hetzelfde resultaat kun je zonder nesting bereiken door de logische operatoren uit hoofdstuk 4 te gebruiken:

```
if (green && !police_stop) {
    // Go
} else {
    // Stop
}
```

"Als het licht groen is én de agent heeft je niet tegengehouden, rijd dan; anders stop." Dit geeft exact hetzelfde resultaat als de geneste versie, maar de docent vindt het een stuk netter. Logische operatoren combineren met conditional programming geeft je veel uitdrukkingskracht, en dat zie je de hele cursus terug.

Tijdlink: [▶ 07:19:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26347s)

#### De else if-clausule

Soms moet je uit veel mogelijkheden kiezen. Het voorbeeld van de docent: een tekenapplicatie waarin de gebruiker op elk moment één tool actief heeft: pen, marker, eraser, rectangle, circle of ellipse. Als de gebruiker klikt en sleept, moet het programma weten welke tool geselecteerd is en de bijbehorende instellingen gebruiken. (De docent toont hier een Qt-applicatie uit een van zijn andere cursussen die precies dit doet.)

Syntax:

```
if (voorwaarde1) {
    ...
} else if (voorwaarde2) {
    ...
} else if (voorwaarde3) {
    ...
} else {
    // optioneel: als niets matcht
}
```

- Elke `else if` heeft zijn eigen haakjes met een voorwaarde die naar een boolean evalueert, gevolgd door een blok code.
- In de hele keten wordt **hoogstens één blok** uitgevoerd: het eerste waarvan de voorwaarde slaagt. Daarna springt de controle naar het einde van de keten; de rest wordt overgeslagen.
- Je zou dit ook met een hoop losse if-statements kunnen doen, maar dat is lelijk en moeilijk te lezen.

In de demo definieert de docent de tools buiten `main` als integer-constanten: `pen = 10`, `marker = 20`, `eraser = 30`, `rectangle = 40`, `circle = 50`, `ellipse = 60`. Ze zijn `const` zodat ze niet per ongeluk gewijzigd kunnen worden. Hij zegt er uitdrukkelijk bij dat dit niet de beste manier is (later in de cursus komt een betere aanpak, enums), maar voor nu volstaat het.

In `main` maakt hij `int tool {circle};` en test hij met de keten welke tool actief is → "Active tool is circle". Wijzigt hij `tool` naar `rectangle` of `eraser`, dan wordt telkens het juiste blok uitgevoerd. Probeert hij een niet-bestaande naam zoals `bird`, dan geeft de compiler een fout: `'bird' was not declared in this scope`. Je kunt alleen namen gebruiken die eerder gedeclareerd zijn.

Ten slotte zet hij een `std::cout << "Moving on"` ná de keten om te laten zien dat, na het ene uitgevoerde blok, de uitvoering verdergaat met de code na de hele keten.

Tijdlink: [▶ 07:20:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26443s) · demo [▶ 07:23:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26636s)

#### `==` versus `=`

Bij het testen op gelijkheid gebruik je **twee** gelijktekens: `tool == pen`. Eén gelijkteken (`tool = pen`) is een *toekenning*. De docent waarschuwt dat zo'n toekenning in een voorwaarde "altijd naar true evalueert", dus dat wil je nooit.

> 💡 Aanvulling: preciezer gezegd is de waarde van `tool = pen` de nieuw toegekende waarde (hier 10). Elke waarde ongelijk aan 0 telt als `true`, vandaar dat de test bijna altijd slaagt. Bij `tool = 0` zou hij juist altijd falen. Bovendien heb je `tool` dan ook nog eens overschreven. GCC waarschuwt hiervoor met `-Wall` ("suggest parentheses around assignment used as truth value").

Tijdlink: [▶ 07:25:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26730s)

#### Het switch-statement

`switch` is een alternatief voor een lange `else if`-keten wanneer je één variabele tegen een reeks vaste waarden vergelijkt. Het is compacter. De docent gebruikt hetzelfde tool-voorbeeld.

Syntax:

```
switch (expressie) {
    case waarde1: {
        // code voor waarde1
    }
    break;
    case waarde2: {
        // code voor waarde2
    }
    break;
    default: {
        // als geen enkele case matcht
    }
}
```

- Tussen de haakjes na `switch` staat de variabele (expressie) waarover je "switcht".
- Elke `case waarde:` (met een dubbele punt) markeert een mogelijke waarde. De docent zet de code van elke case tussen accolades.
- **`break`** vertelt C++: "je bent klaar, spring uit het switch-blok." Laat je `break` weg, dan worden **alle cases ná de gematchte case ook uitgevoerd**. Dat heet *fall-through* en is bijna nooit wat je wilt.
- **`default`** wordt uitgevoerd als geen enkele case gematcht is. Zie het als de `else` van de switch.
- Na de switch gaat de uitvoering verder met de code eronder ("Moving on").

VS Code biedt een *snippet* aan: als je `switch` typt, kun je een sjabloon met case en default laten invullen. De docent typt de cases toch live uit, omdat de constructie voor beginners verwarrend kan zijn.

Tijdens de demo maakt hij zelf een copy-paste-fout: bij `case ellipse` stond nog "Active tool is pen", waardoor met `tool = ellipse` de verkeerde tekst verscheen. Een mooi voorbeeld van hoe makkelijk dit gebeurt bij copy-pasten van cases.

Tijdlink: [▶ 07:28:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26923s) · demo [▶ 07:31:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27116s)

#### Fall-through: wat er gebeurt zonder break

De docent zet `tool` op `marker` en verwijdert alle `break`-statements (ook bij default). Het programma compileert zonder problemen, maar de output is:

- "Active tool is marker", "eraser", "rectangle", "circle", "ellipse" én "No match found", en daarna "Moving on".

Zodra een case matcht, wordt dus alles daaronder ook uitgevoerd, tot een `break` of het einde van de switch. Met `tool = eraser` begint de reeks bij eraser. Daarom: vergeet je `break` niet.

> 💡 Aanvulling: GCC waarschuwt hiervoor met `-Wextra` (`-Wimplicit-fallthrough`): "this statement may fall through". Wil je bewust fall-through, dan zet je sinds C++17 `[[fallthrough]];` op die plek, zodat lezer en compiler weten dat het opzettelijk is.

Tijdlink: [▶ 07:37:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27456s)

#### Cases groeperen

Als meerdere waarden dezelfde behandeling moeten krijgen, kun je cases onder elkaar zetten zonder code ertussen. Rectangle, circle en ellipse zijn allemaal vormen:

```
case rectangle:
case circle:
case ellipse: {
    std::cout << "Drawing Shapes" << std::endl;
}
break;
```

Elk van de drie waarden leidt naar hetzelfde blok. Hier is "doorvallen" juist gewenst, en het is geen probleem omdat er tussen de labels geen code staat.

> ⚠️ Onduidelijk in opname: de docent zegt dat de huidige tool "eraser" is en dat "Drawing Shapes" geprint wordt. Met eraser zou dat niet kunnen; vermoedelijk had hij de tool op een van de vormen gezet. In het voorbeeld hieronder gebruiken we `circle`.

Tijdlink: [▶ 07:39:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27599s)

#### Beperking: alleen integrale typen en enums

De expressie in een `switch` moet een **integraal type** zijn (`int`, `long`, `short`, `unsigned`, `char`, ...) of een **enum** (die komt later in de cursus). Probeer je bijvoorbeeld te switchen op een `std::string name {"John"};`, dan weigert de compiler. VS Code meldt "expression must have an integral or enum type", en GCC geeft een vergelijkbare fout. Volgens de docent "heeft switchen op een string ook niet echt zin" in deze constructie.

Tijdlink: [▶ 07:31:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27067s) · demo [▶ 07:41:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27694s)

#### De ternary operator

De ternary operator is een korte manier om een keuze tussen twee waarden te maken. Voorbeeld: het maximum van `a` en `b` vinden. Met `if`:

```
if (a > b)
    max = a;
else
    max = b;
```

Met de ternary operator:

```
max = (a > b) ? a : b;
```

Algemene vorm: `result = (voorwaarde) ? optie1 : optie2;`

- Is de voorwaarde true, dan is de uitkomst `optie1`; anders `optie2`.
- Het is equivalent aan `if (voorwaarde) result = optie1; else result = optie2;`. De docent noemt het *syntactic sugar*: een verkorte schrijfwijze die je overal in C++-code tegenkomt.
- De haakjes rond de voorwaarde zijn niet verplicht ("ik heb een beetje gelogen"), maar ze maken de code wel duidelijker.

In de demo is eerst `a = 35`, `b = 20` → "Max: 35"; daarna `b = 200` → "Max: 200". De ternary-versie geeft precies hetzelfde.

Tijdlink: [▶ 07:42:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27742s) · demo [▶ 07:45:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27934s)

#### Ternary initialisatie

Je kunt de ternary operator ook gebruiken om een variabele te *initialiseren*:

```
bool fast {false};
int speed {fast ? 300 : 150};   // 150
```

"Als fast, initialiseer met 300; zo niet, met 150."

Tijdlink: [▶ 07:44:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27885s)

#### Typen van de twee opties

`optie1` en `optie2` moeten **van hetzelfde type zijn, of naar elkaar converteerbaar**. Anders krijg je een compilerfout.

- `max = (a > b) ? a : "Hello";` mislukt: een string literal (`const char*`) en een `int` zijn niet compatibel. VS Code: "operand types are incompatible ("int" and "const char *")". GCC: "operands to '?:' have different types 'int' and 'const char*'".
- `max = (a > b) ? a : 22.5f;` mag wel: `int` en `float` zijn converteerbaar. Met `a = 35`, `b = 200` is de voorwaarde false en krijg je 22.5, maar omdat `max` een `int` is, wordt bij de **toekenning** afgekapt → "Max: 22".

Welk type levert de ternary expressie dan zelf op? Om dat te zien gebruikt de docent `auto max1 = (a > b) ? a : 22.5f;`. Het resultaat is **`float`**: de `int` is naar `float` geconverteerd, en `max1` bevat 22.5. Je zou misschien een conversie van float naar int verwachten, maar het is net andersom: de compiler kiest een gemeenschappelijk type voor beide opties (zoals bij gewone rekenkundige operaties), en pas bij de toekenning aan `int max` werd het weer afgekapt.

Tijdlink: [▶ 07:48:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28124s) · `auto` [▶ 07:50:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28219s)

#### Samenvatting van de docent

De gereedschappen voor flow control draaien om vier dingen: `if`-statements, `else`-clausules, `else if`-ketens voor lange reeksen beslissingen, en `switch` als alternatief bij veel mogelijke waarden. Daarnaast is er de ternary operator voor keuzes met twee opties, waarmee je zo'n beslissing tot één regel terugbrengt.

Tijdlink: [▶ 07:51:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28314s)

### Codevoorbeelden

#### if met een boolean variabele [▶ 07:07:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25679s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int number1 {55};
    int number2 {60};

    bool result = (number1 < number2); // vergelijking levert een bool op
    std::cout << std::boolalpha << "result : " << result << std::endl;

    std::cout << std::endl;
    std::cout << "Free standing if statement" << std::endl;

    if (result == true) {
        std::cout << number1 << " is less than " << number2 << std::endl;
    }

    if (!(result == true)) { // "als niet (result is true)" == "als result false is"
        std::cout << number1 << " is NOT less than " << number2 << std::endl;
    }

    return 0;
}
```

```text
result : true

Free standing if statement
55 is less than 60
```

Met `number1 {65}` wordt `result` false en print het programma `65 is NOT less than 60`.

#### if met else [▶ 07:11:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=25918s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int number1 {65};
    int number2 {60};
    bool result = (number1 < number2);

    std::cout << "Using else :" << std::endl;
    if (result == true) {
        std::cout << number1 << " is less than " << number2 << std::endl;
    } else { // vangt het geval op waarin de test faalt
        std::cout << number1 << " is NOT less than " << number2 << std::endl;
    }

    return 0;
}
```

```text
Using else :
65 is NOT less than 60
```

#### Expressie rechtstreeks als voorwaarde [▶ 07:13:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26011s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int number1 {75};
    int number2 {60};

    std::cout << "Using expression as condition :" << std::endl;
    if (number1 < number2) { // geen hulpvariabele nodig: de expressie is al een bool
        std::cout << number1 << " is less than " << number2 << std::endl;
    } else {
        std::cout << number1 << " is NOT less than " << number2 << std::endl;
    }

    return 0;
}
```

```text
Using expression as condition :
75 is NOT less than 60
```

#### Verkeerslicht met losse if-statements [▶ 07:15:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26157s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool red {false};
    bool green {true};
    bool yellow {false};
    bool police_stop {true}; // wordt hier nog niet gebruikt
    (void)police_stop;       // onderdrukt de "unused variable"-waarschuwing

    if (red) {
        std::cout << "Stop" << std::endl;
    }
    if (yellow) {
        std::cout << "Slow down" << std::endl;
    }
    if (green) {
        std::cout << "Go" << std::endl;
    }

    return 0;
}
```

```text
Go
```

#### Geneste if-statements [▶ 07:16:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26205s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool green {true};
    bool police_stop {true};

    // Groen licht: normaal rijden, maar de agent mag je tegenhouden
    if (green) {
        if (police_stop) {      // geneste if
            std::cout << "Stop" << std::endl;
        } else {
            std::cout << "Go" << std::endl;
        }
    }
    // na het uitgevoerde blok gaat de controle hier verder

    return 0;
}
```

```text
Stop
```

#### Logische operatoren in plaats van nesting [▶ 07:19:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26347s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool green {true};
    bool police_stop {true};

    // Zelfde logica als de geneste versie, in één test
    if (green && !police_stop) {
        std::cout << "Go" << std::endl;
    } else {
        std::cout << "Stop" << std::endl;
    }

    return 0;
}
```

```text
Stop
```

#### else if-keten voor de actieve tool [▶ 07:23:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26636s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

// Tools als constanten (later in de cursus: enums)
const int pen {10};
const int marker {20};
const int eraser {30};
const int rectangle {40};
const int circle {50};
const int ellipse {60};

int main() {
    int tool {eraser};

    if (tool == pen) {              // == test op gelijkheid, = is toekenning!
        std::cout << "Active tool is pen" << std::endl;
    } else if (tool == marker) {
        std::cout << "Active tool is marker" << std::endl;
    } else if (tool == eraser) {
        std::cout << "Active tool is eraser" << std::endl;
    } else if (tool == rectangle) {
        std::cout << "Active tool is rectangle" << std::endl;
    } else if (tool == circle) {
        std::cout << "Active tool is circle" << std::endl;
    } else if (tool == ellipse) {
        std::cout << "Active tool is ellipse" << std::endl;
    }

    // Slechts één blok wordt uitgevoerd, daarna gaat het hier verder
    std::cout << "Moving on" << std::endl;

    return 0;
}
```

```text
Active tool is eraser
Moving on
```

#### Niet-gedeclareerde naam in de voorwaarde [▶ 07:26:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=26779s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: 'bird' was not declared in this scope
#include <iostream>

const int pen {10};

int main() {
    int tool {bird}; // bird bestaat niet
    if (tool == pen) {
        std::cout << "Active tool is pen" << std::endl;
    }
    return 0;
}
```

#### switch met break en default [▶ 07:31:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27116s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

const int pen {10};
const int marker {20};
const int eraser {30};
const int rectangle {40};
const int circle {50};
const int ellipse {60};

int main() {
    int tool {eraser};

    switch (tool) {
        case pen: {
            std::cout << "Active tool is pen" << std::endl;
        }
        break; // spring uit de switch
        case marker: {
            std::cout << "Active tool is marker" << std::endl;
        }
        break;
        case eraser: {
            std::cout << "Active tool is eraser" << std::endl;
        }
        break;
        case rectangle: {
            std::cout << "Active tool is rectangle" << std::endl;
        }
        break;
        case circle: {
            std::cout << "Active tool is circle" << std::endl;
        }
        break;
        case ellipse: {
            std::cout << "Active tool is ellipse" << std::endl;
        }
        break;
        default: { // geen enkele case matcht
            std::cout << "No match found" << std::endl;
        }
        break;
    }

    std::cout << "Moving on" << std::endl;

    return 0;
}
```

```text
Active tool is eraser
Moving on
```

#### Fall-through: alle break-statements vergeten [▶ 07:37:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27456s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

Dit compileert, maar GCC geeft met `-Wextra` waarschuwingen ("this statement may fall through"). Dat is precies het punt van de demo.

```cpp
#include <iostream>

const int pen {10};
const int marker {20};
const int eraser {30};
const int rectangle {40};
const int circle {50};
const int ellipse {60};

int main() {
    int tool {marker};

    switch (tool) { // GEEN break: alles na de gematchte case wordt uitgevoerd
        case pen: {
            std::cout << "Active tool is pen" << std::endl;
        }
        case marker: {
            std::cout << "Active tool is marker" << std::endl;
        }
        case eraser: {
            std::cout << "Active tool is eraser" << std::endl;
        }
        case rectangle: {
            std::cout << "Active tool is rectangle" << std::endl;
        }
        case circle: {
            std::cout << "Active tool is circle" << std::endl;
        }
        case ellipse: {
            std::cout << "Active tool is ellipse" << std::endl;
        }
        default: {
            std::cout << "No match found" << std::endl;
        }
    }

    std::cout << "Moving on" << std::endl;

    return 0;
}
```

```text
Active tool is marker
Active tool is eraser
Active tool is rectangle
Active tool is circle
Active tool is ellipse
No match found
Moving on
```

#### Cases groeperen [▶ 07:39:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27599s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

const int pen {10};
const int marker {20};
const int eraser {30};
const int rectangle {40};
const int circle {50};
const int ellipse {60};

int main() {
    int tool {circle};

    switch (tool) {
        case pen: {
            std::cout << "Active tool is pen" << std::endl;
        }
        break;
        case marker: {
            std::cout << "Active tool is marker" << std::endl;
        }
        break;
        case eraser: {
            std::cout << "Active tool is eraser" << std::endl;
        }
        break;
        case rectangle: // drie labels, één blok
        case circle:
        case ellipse: {
            std::cout << "Drawing Shapes" << std::endl;
        }
        break;
        default: {
            std::cout << "No match found" << std::endl;
        }
        break;
    }

    std::cout << "Moving on" << std::endl;

    return 0;
}
```

```text
Drawing Shapes
Moving on
```

#### switch op een std::string mag niet [▶ 07:41:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27694s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: switch-expressie moet een integraal type of enum zijn, std::string mag niet
#include <iostream>
#include <string>

int main() {
    std::string name {"John"};
    switch (name) {
        default:
            std::cout << "No match" << std::endl;
    }
    return 0;
}
```

#### Maximum met if en met de ternary operator [▶ 07:45:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27934s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int max {};
    int a {35};
    int b {200};

    // Met een gewone if
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    std::cout << "max (if) : " << max << std::endl;

    // Zelfde met de ternary operator: (voorwaarde) ? optie1 : optie2
    max = (a > b) ? a : b;
    std::cout << "max (ternary) : " << max << std::endl;

    return 0;
}
```

```text
max (if) : 200
max (ternary) : 200
```

#### Ternary initialisatie [▶ 07:44:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=27885s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    bool fast {false};
    int speed {fast ? 300 : 150}; // initialisatie met een ternary expressie

    std::cout << "The speed is : " << speed << std::endl;

    return 0;
}
```

```text
The speed is : 150
```

#### Incompatibele types in de ternary operator [▶ 07:48:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28124s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: operands to '?:' have different types 'int' and 'const char*'
#include <iostream>

int main() {
    int max {};
    int a {35};
    int b {200};
    max = (a > b) ? a : "Hello";
    std::cout << "max : " << max << std::endl;
    return 0;
}
```

#### Converteerbare types en het type van het resultaat [▶ 07:50:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28219s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int max {};
    int a {35};
    int b {200};

    // int en float zijn converteerbaar: dit compileert
    max = (a > b) ? a : 22.5f; // resultaat 22.5f, afgekapt bij toekenning aan int
    std::cout << "max : " << max << std::endl;

    // Welk type levert de ternary expressie zelf op? auto laat het zien:
    auto max1 = (a > b) ? a : 22.5f; // float! (int -> float, niet andersom)
    std::cout << "max1 : " << max1 << std::endl;
    std::cout << "sizeof(max1) : " << sizeof(max1) << std::endl;

    return 0;
}
```

```text
max : 22
max1 : 22.5
sizeof(max1) : 4
```

> 💡 Aanvulling: `sizeof(max1)` is 4 bij GCC/Clang/MSVC op gangbare platforms (een `float`), en dat is hier alleen toegevoegd om te tonen dat het een float is. De docent laat het alleen zien via de geprinte waarde 22.5.

### Valkuilen & veelgemaakte fouten

#### `=` in plaats van `==`

`if (tool = pen)` is een toekenning, geen vergelijking. De voorwaarde krijgt de toegekende waarde (≠ 0 → true) en je overschrijft `tool`. Gebruik altijd `==` om op gelijkheid te testen. Let op de waarschuwing van `-Wall`.

#### `break` vergeten in een switch

Zonder `break` vallen alle volgende cases (inclusief `default`) mee door. Het programma compileert gewoon, dus de fout blijkt pas bij het uitvoeren. Zet na elke case een `break`, of markeer bewuste fall-through met `[[fallthrough]];` (aanvulling).

#### Copy-paste-fouten tussen cases

De docent liet het zelf zien: bij `case ellipse` stond nog de tekst van `pen`. Controleer bij gekopieerde cases altijd label én body.

#### switch op een niet-integraal type

`switch (name)` met een `std::string` (of een `double`) compileert niet: "expression must have an integral or enum type". Gebruik daarvoor een `if`/`else if`-keten.

#### Niet-gedeclareerde namen

Een case of vergelijking met een naam die nergens gedeclareerd is (`bird`) geeft "was not declared in this scope". Constanten moeten vóór gebruik gedeclareerd zijn.

#### Incompatibele opties in de ternary operator

Beide opties moeten van hetzelfde type zijn of naar elkaar converteerbaar: `int` en `const char*` gaan niet samen.

#### Verrassend resultaattype van `? :`

Bij `a : 22.5f` is het resultaat `float`, niet `int`. Wijs je het toe aan een `int`, dan wordt het stilletjes afgekapt (22.5 → 22). Gebruik `auto` of let goed op het doeltype als je precisie wilt behouden.

#### Denken dat meerdere takken van een keten draaien

In een `if` / `else if` / `else`-keten wordt hoogstens één tak uitgevoerd: de eerste die slaagt. Losse `if`-statements daarentegen worden allemaal getest.

### Best practices

- Gebruik `else` in plaats van een tweede `if` met de negatie van dezelfde voorwaarde: compacter en geen risico dat de twee tests uit de pas lopen.
- Zet een expressie direct in de voorwaarde als je het resultaat verder niet nodig hebt.
- Vervang diepe nesting waar mogelijk door logische operatoren (`green && !police_stop`); dat leest vaak makkelijker.
- Gebruik `else if`-ketens in plaats van een reeks losse if's wanneer de mogelijkheden elkaar uitsluiten.
- Kies `switch` als je één integrale variabele tegen veel vaste waarden vergelijkt. Sluit elke case af met `break` en voorzie een `default`.
- Groepeer cases die dezelfde behandeling krijgen in plaats van code te dupliceren.
- Maak "magische getallen" zoals de tool-codes `const` (en later: gebruik enums).
- Gebruik de ternary operator voor eenvoudige keuzes tussen twee waarden, zeker bij initialisatie. Zet de voorwaarde tussen haakjes voor de leesbaarheid.
- Compileer met `-Wall -Wextra`: de compiler vangt dan `=`/`==`-verwarring en onbedoelde fall-through op (aanvulling).

### Samenvatting

- Flow control laat een programma beslissingen nemen op basis van voorwaarden die naar `true`/`false` evalueren.
- `if (voorwaarde) { ... }` voert de body alleen uit als de voorwaarde true is; `else` vangt het andere geval op.
- Een vergelijkingsexpressie mag rechtstreeks als voorwaarde dienen; een hulpvariabele is niet nodig.
- If-statements kun je nesten, of je combineert voorwaarden met `&&`, `||` en `!`.
- Een `if` / `else if` / `else`-keten voert hoogstens één blok uit en springt daarna naar het einde van de keten.
- Test op gelijkheid met `==`; `=` is een toekenning.
- `switch` vergelijkt één integrale (of enum-)expressie met `case`-waarden. `break` springt eruit, `default` vangt de rest op.
- Zonder `break` krijg je fall-through; cases kun je bewust groeperen door labels te stapelen.
- `switch` werkt niet met `std::string`.
- De ternary operator `(voorwaarde) ? optie1 : optie2` is een korte if/else voor twee waarden. De opties moeten compatibele types hebben, en het resultaattype is hun gemeenschappelijke type (int + float → float).

### Oefeningen

1. Schrijf een programma met `int temperature {18};` dat "Warm" print als de temperatuur boven 25 ligt, en anders "Not warm". Gebruik `if`/`else`.
2. Schrijf een programma met `int score {72};` dat via een `else if`-keten een cijfer print: ≥ 90 → "A", ≥ 80 → "B", ≥ 70 → "C", ≥ 60 → "D", anders "F". Print daarna "Done".
3. Schrijf een programma met `char grade {'b'};` dat met een `switch` "Excellent" print voor `'A'`/`'a'`, "Good" voor `'B'`/`'b'`, "Pass" voor `'C'`/`'c'` en "Unknown" voor alles anders. Groepeer de hoofdletter- en kleineletter-cases.
4. Lees twee gehele getallen in met `std::cin` en print het grootste met de ternary operator. Initialiseer daarna `bool both_positive` met een logische expressie en print met een ternary "both positive" of "not both positive". Test met invoer `-3 8`.
5. Voorspel en controleer: welk type en welke waarde heeft `auto x = (1 > 2) ? 7 : 2.5;`? En wat print het programma als je het resultaat aan een `int y` toekent? Leg uit.

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

int main() {
    int temperature {18};
    if (temperature > 25) {
        std::cout << "Warm" << std::endl;
    } else {
        std::cout << "Not warm" << std::endl;
    }
    return 0;
}
```

```text
Not warm
```

Oefening 2:

```cpp
#include <iostream>

int main() {
    int score {72};
    if (score >= 90) {
        std::cout << "A" << std::endl;
    } else if (score >= 80) {
        std::cout << "B" << std::endl;
    } else if (score >= 70) {
        std::cout << "C" << std::endl; // eerste tak die slaagt
    } else if (score >= 60) {
        std::cout << "D" << std::endl;
    } else {
        std::cout << "F" << std::endl;
    }
    std::cout << "Done" << std::endl;
    return 0;
}
```

```text
C
Done
```

Oefening 3:

```cpp
#include <iostream>

int main() {
    char grade {'b'};
    switch (grade) { // char is een integraal type
        case 'A':
        case 'a':
            std::cout << "Excellent" << std::endl;
            break;
        case 'B':
        case 'b':
            std::cout << "Good" << std::endl;
            break;
        case 'C':
        case 'c':
            std::cout << "Pass" << std::endl;
            break;
        default:
            std::cout << "Unknown" << std::endl;
            break;
    }
    return 0;
}
```

```text
Good
```

Oefening 4 (invoer: `-3 8`):

```cpp
// stdin: -3 8
#include <iostream>

int main() {
    int a {};
    int b {};
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    int largest = (a > b) ? a : b;
    std::cout << "Largest: " << largest << std::endl;

    bool both_positive {(a > 0) && (b > 0)};
    std::cout << (both_positive ? "both positive" : "not both positive") << std::endl;
    return 0;
}
```

```text
Enter two numbers: Largest: 8
not both positive
```

Oefening 5: `7` (int) en `2.5` (double) hebben als gemeenschappelijk type `double`. De voorwaarde is false, dus `x` is de `double` 2.5. Bij toekenning aan `int y` wordt afgekapt naar 2.

```cpp
#include <iostream>

int main() {
    auto x = (1 > 2) ? 7 : 2.5;  // type double
    int y = (1 > 2) ? 7 : 2.5;   // double 2.5 -> int 2 (afgekapt)
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "sizeof(x) == sizeof(double) : " << std::boolalpha
              << (sizeof(x) == sizeof(double)) << std::endl;
    return 0;
}
```

```text
x : 2.5
y : 2
sizeof(x) == sizeof(double) : true
```

</details>

---

<a id="h06"></a>

## Hoofdstuk 6 – Loops (07:53:49 – 08:47:08) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28429s)

### Leerdoelen

Na dit hoofdstuk kun je:

- uitleggen waarom loops bestaan en welk probleem ze oplossen (herhaling zonder copy-paste);
- de vijf onderdelen van elke loop benoemen: iterator, startpunt, test, incrementatie en body;
- een `for`-loop schrijven, stap voor stap "in je hoofd" uitvoeren en voorspellen hoe vaak de body draait;
- `size_t` gebruiken als type voor iterators en uitleggen waarom dat de conventie is;
- de scope van een iterator begrijpen: binnen de loop gedeclareerd versus buiten de loop gedeclareerd;
- het initialisatiedeel van een `for`-loop weglaten als de iterator al bestaat;
- hardgecodeerde lusgrenzen vervangen door een (const) variabele als enig controlepunt;
- dezelfde herhaling schrijven met een `while`-loop en met een `do-while`-loop;
- het cruciale verschil van `do-while` uitleggen: de body draait **altijd minstens één keer**, ook als de test meteen onwaar is.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 2 (Diving in)**: je gebruikt weer `std::cout`, `std::endl` en de stream output operator `<<`, en dezelfde template-project-werkwijze in VS Code (build-task met GCC, programma `rooster.exe` draaien).
- **Hoofdstuk 3 (Variables & data types)**: `unsigned int` en het idee van een type dat alleen positieve getallen kan bevatten komen terug in `size_t`. Ook brace-initialisatie (`size_t i{0}`) gebruik je weer.
- **Hoofdstuk 4 (Operations on data)**: de increment-operator `++i`, relationele operatoren (`<`), `sizeof` en de begrippen overflow/underflow zijn direct nodig voor de test- en incrementatiedelen van een loop.
- **Hoofdstuk 5 (Flow control)**: daar besliste een test (`if`, `switch`) **of** code één keer wordt uitgevoerd; in dit hoofdstuk bepaalt een test **hoe vaak** code wordt uitgevoerd. Een loop is in feite een herhaalde `if`.
- **Vooruitblik hoofdstuk 7 (Arrays)**: de docent noemt in de intro ook de *range-based for loop*; die wordt pas bij arrays behandeld, omdat je er een verzameling voor nodig hebt.

### Uitleg

#### Waarom loops? [▶ 07:54:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28458s)

Stel dat je "I love C++" tien keer moet printen. Je kunt de `std::cout`-regel tien keer kopiëren, en dat werkt. Maar zodra iemand vraagt om het 10 000 of 100 000 keer te doen, wordt copy-paste onhoudbaar. C++ biedt daarom constructies om code herhaaldelijk uit te voeren:

- de `for`-loop;
- de range-based `for`-loop (komt bij arrays);
- de `while`-loop;
- de `do-while`-loop.

Het grote voordeel: ongeacht hoe vaak de code draait, de loop zelf blijft een paar regels code. Je verandert alleen het getal dat het aantal herhalingen bepaalt.

#### De vijf onderdelen van een loop [▶ 07:55:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28553s)

De docent ontleedt elke loop in vijf delen. Deze terminologie gebruikt hij voor alle drie de loopsoorten:

1. **Iterator** – een variabele die je gebruikt om door de loop te "navigeren", bijvoorbeeld `unsigned int i`.
2. **Startpunt** – de waarde waarmee je de iterator initialiseert, bijvoorbeeld `0`.
3. **Test** – een voorwaarde die bepaalt wanneer de loop stopt, bijvoorbeeld `i < 10`. Zolang de test `true` is, gaat de loop door. Het eindpunt zit dus in de test verwerkt.
4. **Incrementatie** – het deel dat de iterator verandert zodat de loop vooruitgaat, bijvoorbeeld `++i`. Dat kan ook een decrementatie zijn, maar voor de eenvoud noemt de docent het steeds "het incrementatiedeel".
5. **Body** – de code tussen de accolades `{ }` die je meerdere keren wilt uitvoeren.

#### De for-loop: syntax [▶ 07:55:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28505s)

```
for (unsigned int i{0}; i < 10; ++i) {
    // body
}
```

Tussen de ronde haakjes staan drie delen, **gescheiden door puntkomma's** (niet door komma's): declaratie + initialisatie van de iterator, de test, en de incrementatie. Daarna volgt de body tussen accolades.

#### Hoe een for-loop uitgevoerd wordt [▶ 07:57:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28650s)

De docent loopt de uitvoering stap voor stap door:

1. De initialisatie draait **precies één keer**: `i` wordt `0`.
2. De test wordt uitgevoerd: is `0 < 10`? Ja → spring in de body en print het bericht (eerste keer).
3. Na de body draait de incrementatie: `i` wordt `1`.
4. Terug naar de test: `1 < 10`? Ja → body (tweede keer) → incrementatie → `i` wordt `2` ...
5. Dit gaat door tot `i` `9` is: `9 < 10` is waar, de body draait voor de tiende keer, daarna wordt `i` `10`.
6. Test: `10 < 10`? Nee → de loop stopt en de uitvoering gaat verder met de code **na** de sluitende accolade.

Het patroon is dus: *init – test – body – increment – test – body – increment – test – ...* tot de test faalt. Omdat `i` van 0 tot en met 9 loopt, draait de body 10 keer. De test bepaalt het aantal herhalingen: wil je 20 keer, dan test je op `i < 20`. Je hoeft ook niet bij 0 te beginnen: je kunt bijvoorbeeld bij 30 starten en stoppen bij 55. De docent raadt aan de loop op papier of in een tekstbestand na te spelen om het mechanisme echt te begrijpen.

#### size_t als type voor de iterator [▶ 08:01:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28891s)

Iterators komen veel voor in C++. Er is een type dat speciaal gebruikt wordt voor groottes en tellers: `size_t`. Het is een alias voor een `unsigned` integer-type van je compiler; de exacte grootte verschilt per compiler/platform. Op het systeem van de docent is `sizeof(size_t)` gelijk aan 8 bytes, dus er past een enorm bereik aan (positieve) waarden in.

Waarom `size_t`?

- Het kan alleen niet-negatieve getallen voorstellen. Dat past bij dingen die nooit negatief kunnen zijn: het aantal studenten in een klas, het aantal stoelen in een auto, het aantal keer dat een loop draait.
- De C++ standard library gebruikt `size_t` zelf om groottes aan te duiden. Code die met de standard library samenwerkt, wordt dus leesbaarder en voorspelbaarder als je dezelfde conventie volgt.

`unsigned int` werkt ook prima; `size_t` is gewoon de gangbare keuze. Probeer je er een negatief getal in te stoppen, dan krijg je een underflow (zie hoofdstuk 4).

> 💡 Aanvulling: formeel heet het type `std::size_t` en staat het in `<cstddef>`. Via `<iostream>` is `size_t` in de praktijk bij GCC/Clang/MSVC ook zonder `std::` beschikbaar, zoals de docent het gebruikt.

#### Wat er in de body kan, en accolades weglaten [▶ 08:03:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28988s)

In de body kun je alles doen wat je elders ook doet, bijvoorbeeld de huidige waarde van de iterator en het dubbele ervan printen. Je kunt de accolades weglaten, maar **alleen als de body uit één enkel statement bestaat**. Een loop `for (size_t i{0}; i < 5; ++i)` draait 5 keer: `i` gaat van 0 tot en met 4 en de loop stopt als `i` niet meer kleiner is dan 5.

#### Scope van de iterator [▶ 08:03:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29036s)

Een iterator die je in het initialisatiedeel van de `for`-loop declareert, bestaat alleen binnen de loop: in de controle-onderdelen tussen de ronde haakjes en in de body. Gebruik je `i` na de sluitende accolade, dan krijg je een compilerfout. In de demo [▶ 08:18:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29900s) toont VS Code al een rode golflijn ("identifier is undefined") en GCC meldt bij het compileren dat `i` niet gedeclareerd is in deze scope, met het regelnummer erbij.

Wil je de iterator ook ná de loop gebruiken (bijvoorbeeld om te zien waar hij geëindigd is), declareer hem dan **buiten** de loop [▶ 08:04:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29083s). In het initialisatiedeel zet je dan alleen nog een toekenning (bijvoorbeeld `i = 0`), of je laat dat deel helemaal leeg [▶ 08:21:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30090s): `for ( ; i < 10; ++i)`. De puntkomma blijft dan wel staan. Zo'n loop kom je in bestaande code tegen ("in the wild"), maar de docent vindt het meestal minder intuïtief en declareert zijn iterator liever in de loop zelf.

Na afloop van zo'n loop heeft `i` de waarde waarbij de test faalde: bij `i < 10` is dat `10`.

#### Geen hardgecodeerde waarden [▶ 08:05:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29132s)

`i < 10` bevat een *hardgecodeerde* waarde. Moet het aantal herhalingen veranderen, dan moet je alle loops in je code opzoeken en het getal overal aanpassen — foutgevoelig als het op veel plaatsen staat. Beter: zet de waarde in een variabele en test daartegen:

```
const size_t COUNT{10};
for (size_t i{0}; i < COUNT; ++i) { ... }
```

Nu heb je **één controlepunt**: verander je `COUNT` naar 100, dan draait de loop 100 keer [▶ 08:23:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30236s). De variabele is van het type `size_t`, omdat een aantal herhalingen nooit negatief is, en `const`, omdat hij niet hoort te veranderen. Bij de `while`-demo schrijft de docent de naam in hoofdletters (`COUNT`): een veelgebruikte conventie voor constanten, niet verplicht, maar het maakt code leesbaarder voor anderen.

#### De while-loop [▶ 08:25:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30332s)

Een `while`-loop heeft dezelfde vijf onderdelen, alleen anders gerangschikt:

```
unsigned int i{0};          // iterator + startpunt: buiten de loop
while (i < 10) {            // test tussen ronde haakjes
    // body
    ++i;                    // incrementatie: zelf in de body, na je code
}
```

De uitvoering is identiek aan de `for`-loop: test → body → incrementatie → test → ... tot de test faalt bij `i == 10`, waarna de code na de loop draait. In de demo [▶ 08:31:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30711s) speelt de docent alle tien de iteraties uit in een Notepad-bestand en vergelijkt dat daarna met de echte output.

Belangrijk: de incrementatie staat niet meer in de kop van de loop, dus je moet hem **zelf** in de body zetten. Vergeet je `++i`, dan blijft de test altijd waar en "gebeurt er iets heel ergs". De docent zegt dat hij daar later op terugkomt.

> ⚠️ Onduidelijk in opname: de beloofde behandeling van wat er gebeurt als je de incrementatie vergeet (een oneindige loop) zit niet in dit fragment van de video.

`for` en `while` zijn in wezen hetzelfde: dezelfde informatie, een andere syntax. Soms is de ene handiger, soms de andere; je kiest wat het beste past bij je probleem.

#### De do-while-loop [▶ 08:36:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31002s)

```
size_t i{0};                // iterator + startpunt
do {
    // body
    ++i;                    // incrementatie
} while (i < 10);           // test ACHTERAAN, let op de puntkomma
```

Ook hier zijn de vijf onderdelen aanwezig, maar de volgorde verschilt fundamenteel: **eerst draait de body, pas daarna de test**. De test staat na de sluitende accolade, gevolgd door een puntkomma. In de demo [▶ 08:41:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31287s) loopt de docent weer alle iteraties na: body met `i == 0`, increment naar 1, test `1 < 10`, body, ... tot de test `10 < 10` faalt en "Loop done" wordt geprint.

#### De valkuil van do-while: count = 0 [▶ 08:45:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31525s)

Zet je `COUNT` op 0 omdat je wilt dat de body **niet** draait, dan doet een `do-while` niet wat je verwacht: de body draait al één keer vóórdat de test voor het eerst gecontroleerd wordt. De output is dan `0 : I love C++` gevolgd door `Loop done`. Wil je dat de body bij een telling van 0 helemaal niet draait, gebruik dan een `while`- of `for`-loop. Een `do-while` is juist handig als je zeker wilt weten dat de body minstens één keer uitgevoerd wordt.

### Codevoorbeelden

#### De slechte manier: copy-paste [▶ 08:07:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29226s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Bad design: the same statement copied 10 times
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    return 0;
}
```

```text
I love C++
I love C++
I love C++
I love C++
I love C++
I love C++
I love C++
I love C++
I love C++
I love C++
```

#### Eerste for-loop met unsigned int [▶ 08:07:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29275s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // iterator + start ; test ; incrementation
    for (unsigned int i{0}; i < 10; ++i) {
        // body: print the current iteration and the message
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
```

Verander je de test in `i < 100` of `i < 10000`, dan loopt de iterator van 0 tot en met 99 respectievelijk 9999 [▶ 08:11:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29513s); de loop zelf blijft even kort.

#### size_t als iterator en de grootte ervan [▶ 08:13:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29611s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // size_t: the conventional type for sizes and counters
    for (size_t i{0}; i < 10; ++i) {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;

    // How big is size_t on this system?
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    return 0;
}
```

De grootte hangt af van compiler en platform; op een 64-bit systeem (zoals bij de docent) is het 8.

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
sizeof(size_t) : 8
```

#### Body zonder accolades [▶ 08:03:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=28988s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Braces may be left out when the body is a single statement
    for (size_t i{0}; i < 5; ++i)
        std::cout << "i : " << i << ", double : " << (i * 2) << std::endl;

    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
i : 0, double : 0
i : 1, double : 2
i : 2, double : 4
i : 3, double : 6
i : 4, double : 8
Loop done!
```

#### Scope: iterator buiten de loop gebruiken geeft een fout [▶ 08:16:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29803s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: i bestaat alleen binnen de for-loop
#include <iostream>

int main() {
    for (size_t i{0}; i < 10; ++i) {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    std::cout << "i : " << i << std::endl; // compiler error: 'i' was not declared in this scope
    return 0;
}
```

GCC geeft een fout van de vorm `error: 'i' was not declared in this scope`, met het regelnummer van de foute regel.

#### Iterator buiten de loop gedeclareerd [▶ 08:19:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=29995s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    size_t i{0}; // declared outside: usable after the loop too

    for (i = 0; i < 10; ++i) {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    std::cout << "i : " << i << std::endl; // i is still in scope
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
i : 10
```

#### Initialisatiedeel weglaten [▶ 08:21:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30090s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    size_t i{0};

    // Declaration part left out; the semicolon must stay
    for ( ; i < 10; ++i) {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
```

#### Geen hardgecodeerde waarden: const count [▶ 08:23:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30188s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    const size_t COUNT{10}; // single point of control

    for (size_t i{0}; i < COUNT; ++i) {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
```

#### While-loop [▶ 08:29:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=30570s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    const size_t COUNT{10};

    size_t i{0};               // iterator + starting point
    while (i < COUNT) {        // test
        std::cout << i << " : I love C++" << std::endl;
        ++i;                   // incrementation: don't forget it!
    }
    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
```

#### Do-while-loop [▶ 08:39:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31191s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    const size_t COUNT{10};

    size_t i{0};               // iterator + starting point
    do {
        std::cout << i << " : I love C++" << std::endl;
        ++i;                   // incrementation
    } while (i < COUNT);       // test runs AFTER the body; note the semicolon

    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
1 : I love C++
2 : I love C++
3 : I love C++
4 : I love C++
5 : I love C++
6 : I love C++
7 : I love C++
8 : I love C++
9 : I love C++
Loop done!
```

#### Do-while met COUNT = 0: body draait toch één keer [▶ 08:46:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31572s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    const size_t COUNT{0}; // intention: run the body zero times

    size_t i{0};
    do {
        std::cout << i << " : I love C++" << std::endl; // still runs once!
        ++i;
    } while (i < COUNT);

    std::cout << "Loop done!" << std::endl;
    return 0;
}
```

```text
0 : I love C++
Loop done!
```

> 💡 Aanvulling: dezelfde situatie met een `while`-loop print alleen `Loop done!`, omdat de test `0 < 0` meteen faalt vóór de body (zie oefening 4).

### Valkuilen & veelgemaakte fouten

#### Iterator gebruiken buiten de scope van de for-loop
Een iterator die in de kop van de `for`-loop gedeclareerd is, bestaat na de sluitende accolade niet meer → compilerfout `'i' was not declared in this scope`. Nodig na de loop? Declareer hem erbuiten.

#### Hardgecodeerde lusgrenzen
`i < 10` op tien plekken in je code betekent tien plekken om aan te passen (en te vergeten). Gebruik één `const size_t COUNT{...}`.

#### Incrementatie vergeten in while en do-while
Bij `while` en `do-while` staat de incrementatie niet in de kop. Vergeet je `++i`, dan verandert de iterator nooit, blijft de test waar en stopt de loop niet.

#### Do-while draait altijd minstens één keer
De test komt pas na de body. Met `COUNT = 0` krijg je toch één iteratie. Gebruik `for` of `while` als nul iteraties mogelijk moeten zijn.

#### Komma's in plaats van puntkomma's in de for-kop
De drie delen van een `for`-kop worden gescheiden door `;`. Ook als je het initialisatiedeel weglaat, blijft de puntkomma staan: `for ( ; i < 10; ++i)`.

#### Puntkomma na while(...) van een do-while vergeten
`} while (i < COUNT);` eindigt met een puntkomma; zonder krijg je een compilerfout.

#### Accolades weglaten bij meer dan één statement
Zonder accolades hoort alleen het eerstvolgende statement bij de loop. Een tweede regel die ingesprongen staat, draait toch maar één keer, na de loop.

#### Negatieve waarden in size_t
`size_t` is unsigned. Een negatieve waarde toekennen geeft een underflow naar een enorm positief getal (zie hoofdstuk 4).

### Best practices

- Gebruik `size_t` voor iterators en tellers die groottes of aantallen voorstellen; dat is de conventie van de standard library.
- Zet het aantal herhalingen in een `const`-variabele (bijvoorbeeld `COUNT`) als enig controlepunt in plaats van magische getallen.
- Declareer de iterator in de `for`-kop als je hem na de loop niet nodig hebt; zo blijft de scope zo klein mogelijk. Declareer hem alleen buiten de loop als de logica dat vraagt.
- Schrijf bij `while` en `do-while` de incrementatie meteen op als je de loop opzet, zodat je haar niet vergeet.
- Kies `do-while` alleen als de body echt minstens één keer moet draaien; anders `for` of `while`.
- Speel een nieuwe loop eerst op papier of in een tekstbestand na (iterator, test, output per stap) om te controleren dat hij het juiste aantal keer draait.
- Print de iterator mee in de output tijdens het leren of debuggen; zo zie je direct waar de loop is.

### Samenvatting

- Loops voeren code herhaaldelijk uit zonder copy-paste; de loop blijft kort, ongeacht het aantal herhalingen.
- Elke loop heeft vijf onderdelen: iterator, startpunt, test, incrementatie en body.
- `for (init; test; increment) { body }`: init draait één keer, daarna herhaalt *test – body – increment* tot de test faalt.
- Met `i` van 0 en test `i < N` draait de body precies N keer; na de loop zou `i` gelijk zijn aan N.
- `size_t` is een unsigned type (op 64-bit meestal 8 bytes) en de standaardkeuze voor groottes en iterators.
- Een iterator gedeclareerd in de `for`-kop is alleen binnen de loop zichtbaar; declareer hem erbuiten als je hem later nodig hebt. Het initialisatiedeel mag zelfs leeg blijven.
- Vermijd hardgecodeerde grenzen: gebruik een `const size_t COUNT`.
- `while (test) { body; ++i; }`: dezelfde logica, de iterator staat buiten de loop en de incrementatie in de body.
- `do { body; ++i; } while (test);`: de test staat achteraan, dus de body draait altijd minstens één keer, ook met `COUNT = 0`.

### Oefeningen

1. Schrijf met een `for`-loop een programma dat de getallen 1 tot en met 5 print, elk op een eigen regel, met een `const size_t COUNT{5}`. Begin de iterator bij 1.
2. Schrijf een programma dat van 30 tot en met 35 telt met een iterator die **buiten** de `for`-loop gedeclareerd is, en print na de loop de eindwaarde van de iterator.
3. Lees een getal `n` in (`size_t`) en bereken met een `while`-loop de som 1 + 2 + ... + n.
4. Zet een `while`-loop en een `do-while`-loop naast elkaar, beide met `COUNT{0}`, en laat zien hoeveel keer elke body draait.
5. Schrijf met een `do-while`-loop een aftelling van `COUNT{5}` naar 1 (gebruik een decrementatie `--i`) en print daarna "Liftoff!".

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

int main() {
    const size_t COUNT{5};
    for (size_t i{1}; i <= COUNT; ++i) {
        std::cout << i << std::endl;
    }
    return 0;
}
```

```text
1
2
3
4
5
```

Oefening 2:

```cpp
#include <iostream>

int main() {
    size_t i{30};
    for ( ; i <= 35; ++i) {
        std::cout << "i : " << i << std::endl;
    }
    std::cout << "Final value of i : " << i << std::endl;
    return 0;
}
```

```text
i : 30
i : 31
i : 32
i : 33
i : 34
i : 35
Final value of i : 36
```

Oefening 3 (invoer: `5`):

```cpp
// stdin: 5
#include <iostream>

int main() {
    size_t n{0};
    std::cout << "Enter n : ";
    std::cin >> n;

    size_t sum{0};
    size_t i{1};
    while (i <= n) {
        sum += i;
        ++i;
    }
    std::cout << "Sum : " << sum << std::endl;
    return 0;
}
```

```text
Enter n : Sum : 15
```

Oefening 4:

```cpp
#include <iostream>

int main() {
    const size_t COUNT{0};

    size_t i{0};
    while (i < COUNT) {
        std::cout << "while body, i : " << i << std::endl;
        ++i;
    }
    std::cout << "while done, iterations : " << i << std::endl;

    size_t j{0};
    do {
        std::cout << "do-while body, j : " << j << std::endl;
        ++j;
    } while (j < COUNT);
    std::cout << "do-while done, iterations : " << j << std::endl;
    return 0;
}
```

```text
while done, iterations : 0
do-while body, j : 0
do-while done, iterations : 1
```

Oefening 5:

```cpp
#include <iostream>

int main() {
    const size_t COUNT{5};
    size_t i{COUNT};
    do {
        std::cout << i << "..." << std::endl;
        --i;                    // decrementation moves the loop forward
    } while (i > 0);
    std::cout << "Liftoff!" << std::endl;
    return 0;
}
```

```text
5...
4...
3...
2...
1...
Liftoff!
```

</details>

---

<a id="h07"></a>

## Hoofdstuk 7 – Arrays (08:47:08 – 09:53:23) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31628s)

### Leerdoelen

- Begrijpen waarom arrays bestaan: veel variabelen van hetzelfde type groeperen onder één naam.
- Een array declareren, elementen lezen en schrijven met de indexoperator `[]`, zowel handmatig als in een loop.
- Arrays initialiseren met braced initialization, ook gedeeltelijk (rest wordt 0) en zonder expliciete grootte (compiler leidt grootte af).
- Een `const` array declareren en begrijpen waarom je die niet kunt wijzigen.
- Het aantal elementen van een array opvragen met `std::size()` (C++17) en met de oudere truc `sizeof(array) / sizeof(array[0])`.
- Range-based for loops gebruiken om door een array te lopen zonder de grootte bij te houden.
- Character arrays begrijpen: waarom ze direct met `std::cout` geprint kunnen worden, wat een null terminator (`'\0'`) is en wat een C-string is.
- String literals (`"Hello"`) gebruiken om character arrays veilig te initialiseren.
- Begrijpen wat er gebeurt als je buiten de grenzen (bounds) van een array leest of schrijft.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 3 (Variables & data types):** een array is een aaneengesloten rij variabelen van één type (`int`, `double`, `char`, ...). Braced initialization `{}` en `auto` uit hoofdstuk 3 komen hier terug. Ook `sizeof` en het feit dat een `int` (meestal) 4 bytes is, zijn nodig om `sizeof(array)` te begrijpen.
- **Hoofdstuk 4 (Operations on data):** compound operators zoals `+=` gebruik je om de elementen van een array op te tellen.
- **Hoofdstuk 6 (Loops):** de `for`-loop met een iterator `i` (vaak `size_t`) is de standaardmanier om elk element via zijn index te bezoeken. De range-based for loop, die al even kort voorbijkwam, wordt hier pas echt handig.
- **Vooruitblik op hoofdstuk 8 (Pointers):** de docent laat zien dat het printen van een `int`-array met `std::cout` een vreemd getal oplevert (een adres) en belooft dat dat in het hoofdstuk over pointers duidelijk wordt. **Hoofdstuk 10** gaat verder met C-strings en `std::string`.

### Uitleg

#### Wat is een array en waarom bestaat het?

Stel dat je de scores van tien studenten wilt bijhouden. Tien losse variabelen (`score1`, `score2`, ...) is onhandig: je kunt er niet in een loop doorheen en elke nieuwe score vraagt een nieuwe variabele. Een **array** lost dat op: het is een verzameling variabelen **van hetzelfde type** die naast elkaar in het geheugen liggen en samen één naam hebben.

De docent tekent het geheugen als een rij blokjes van elk 4 bytes (één `int` per blokje). Die tien blokjes groepeer je onder de naam `scores`. Elk blokje bereik je via een **index** tussen vierkante haken: `scores[0]` is het eerste element, `scores[9]` het laatste.

[▶ 08:48:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31718s)

#### Een array declareren

Syntax: eerst het type van de elementen, dan de naam, dan tussen vierkante haken de grootte:

```
int scores[10];   // ruimte voor 10 ints
```

Zodra deze regel uitgevoerd is, is er geheugen voor 10 aaneengesloten integers gereserveerd onder de naam `scores`. Een spatie tussen naam en `[` maakt niets uit.

Belangrijk:
- **Arrays zijn geïndexeerd vanaf 0**, niet vanaf 1. Bij grootte 10 lopen de geldige indexen van `0` tot en met `9`. De docent hamert hierop: "drill dit in je brein".
- Een array die je zo declareert (zonder initialisatie, binnen een functie) bevat **junk/garbage data**: er staat wel iets in, maar niets wat jij erin gezet hebt. Bij het draaien zag de docent een willekeurig getal op index 0 en toevallig een 0 op index 1; je kunt daar niet op rekenen.

[▶ 08:50:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31813s) · in VS Code [▶ 08:59:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32344s)

#### Elementen lezen

Je leest een element met `naam[index]`, bijvoorbeeld `std::cout << scores[0];`. Handmatig elk element printen is tijdrovend; omdat je de grootte kent, kun je een `for`-loop gebruiken waarbij de iterator `i` (type `size_t`) van 0 tot kleiner dan 10 loopt en je `scores[i]` print. Hier komen de loops uit het vorige hoofdstuk van pas.

[▶ 08:52:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=31960s) · in VS Code [▶ 09:02:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32534s)

#### Elementen schrijven

Schrijven gebruikt dezelfde syntax, maar dan links van een toekenning: `scores[0] = 20; scores[1] = 21; scores[2] = 22;`. De overige elementen blijven junk. Vaak schrijf je in een loop, waarbij de index de huidige iteratie is, bijvoorbeeld `scores[i] = i * 10;`. Dat levert 0, 10, 20, ..., 90 op. Dit patroon (index = loopteller) is volgens de docent iets waar je vertrouwd mee moet raken.

[▶ 08:53:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32008s) · in VS Code [▶ 09:03:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32632s)

#### Declareren en initialiseren in één statement

Met braced initialization geef je meteen een kommagescheiden lijst waarden mee:

```
double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};
```

Arrays kunnen elementen van elk type bevatten, niet alleen `int`.

[▶ 08:55:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32104s) · in VS Code [▶ 09:07:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32869s)

#### Gedeeltelijke initialisatie: de rest wordt 0

Geef je minder waarden dan de grootte, dan worden de voorste elementen gevuld en de **rest op 0 gezet**: `int families[5] {12, 7, 5};` geeft `12 7 5 0 0`.

[▶ 08:55:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32151s) · in VS Code [▶ 09:09:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32968s)

#### Grootte weglaten: de compiler leidt ze af

Je mag de grootte weglaten als je initialiseert: `int class_sizes[] {10, 12, 15, 11, 18, 17};` heeft grootte 6. Laat je de grootte weg **en** initialiseer je niet (`int class_sizes[];`), dan krijg je een compilerfout: de compiler weet dan niet hoeveel geheugen hij moet reserveren.

Hier blinkt de **range-based for loop** uit: `for (auto value : class_sizes)` loopt over alle elementen, hoeveel het er ook zijn. Voeg je later `23` toe, dan hoef je de loop niet aan te passen. Bij een hardgecodeerde grootte in een gewone `for`-loop zou de code dan "breken".

[▶ 08:56:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32200s) · in VS Code [▶ 09:10:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33016s)

#### Const arrays

Met `const` maak je de elementen onwijzigbaar: `const int birds[] {10, 12, 15, 11, 18, 17, 23};`. Een poging als `birds[2] = 8;` geeft een compilerfout; VS Code toont al "expression must be a modifiable lvalue". Gebruik dit als anderen de data niet mogen veranderen. Lezen mag wel gewoon.

[▶ 09:11:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33111s)

#### Bewerkingen op array-data

Je kunt rekenen met de elementen, bijvoorbeeld ze optellen: begin met `int sum {0};`, loop met een range-based for loop en tel elk element op bij `sum`. De docent liep tijdens het bouwen tegen "redeclaration of scores" aan, omdat er hoger in `main` al een array `scores` stond. Twee variabelen met dezelfde naam in dezelfde scope mag niet; hij loste het op door de oude declaratie uit te commentariëren.

[▶ 09:13:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33207s)

#### Arrays bevatten elementen van hetzelfde type

Een array krijgt een blok bytes dat bestaat uit gelijke stukken van één type. Als je er iets van een ander, groter of kleiner type in zou stoppen, weet de compiler niet hoe hij die bytes moet lezen. Daarom: **een array bevat altijd elementen van één type**. Probeer je iets in te stoppen dat niet in dat type past, dan geeft de compiler een fout.

[▶ 08:57:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32247s)

> 💡 Aanvulling: een waarde die impliciet *converteerbaar* is (bijv. een `char` in een `int`-array) wordt wel geaccepteerd; met braced initialization weigert de compiler alleen *narrowing* conversies, zoals een `double` in een `int`-array.

#### De grootte van een array opvragen: `std::size()`

Probleem: als je de grootte hardcodeert in een loop (`i < 10`) en iemand voegt elementen toe of haalt ze weg, klopt de loop niet meer. Die loop kan diep in je project zitten, waardoor dit een bron van lastig te vinden bugs wordt.

Oplossing: `std::size(array)` (standaardbibliotheek, sinds **C++17**) geeft het werkelijke aantal elementen. Je hoeft dan alleen nog de initializer aan te passen; de loop past zich vanzelf aan.

[▶ 09:15:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33350s) · in VS Code [▶ 09:19:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33541s)

> 💡 Aanvulling: `std::size` zit in `<iterator>` (en wordt ook beschikbaar via o.a. `<array>`, `<string>`, `<vector>`). Met alleen `<iostream>` werkt het bij GCC vaak toevallig, maar include `<iterator>` om zeker te zijn. Het geeft een `std::size_t` terug; de docent gebruikt `int count {std::size(scores)}`, in de voorbeelden hieronder gebruiken we `std::size_t` zodat er geen signed/unsigned-vergelijking of narrowing ontstaat.

#### De oude truc: `sizeof(array) / sizeof(array[0])`

Vóór C++17 deed men het zo: `sizeof(scores)` geeft het **totale aantal bytes** van de array; `sizeof(scores[0])` geeft de grootte van **één element**. Deel je die op elkaar, dan heb je het aantal elementen. Bij een array van 8 `int`s gaf dat bij de docent `32` en `4`, en 32 / 4 = 8. Je mag elk element nemen; `[0]` is gewoon het makkelijkst omdat het altijd bestaat.

[▶ 09:17:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33447s) · in VS Code [▶ 09:21:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33685s)

#### Range-based for loop als eenvoudigste oplossing

De docent benadrukt: vaak heb je `std::size` of de `sizeof`-truc helemaal niet nodig. Met `for (auto i : scores)` krijg je elk element, met type deduction via `auto`. Het nadeel: je verliest de **index**. Heb je de index nodig, gebruik dan de gewone loop met `std::size`; heb je alleen de waarden nodig, dan is de range-based for loop schoner.

[▶ 09:24:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33880s)

#### Arrays van characters

Een `char`-array declareer je zoals elke array: `char message[5] {'H', 'e', 'l', 'l', 'o'};`. Je kunt erdoor lopen en elk teken printen (zonder `std::endl` tussen de tekens zodat ze naast elkaar staan) en je kunt tekens wijzigen: `message[1] = 'a';` maakt van "Hello" "Hallo". Let op: `'e'` staat op index 1, niet 2 (de docent vergist zich eerst ook). Tekens staan tussen **enkele** aanhalingstekens.

Het bijzondere: een `char`-array kun je **direct** printen met `std::cout << message;`, zonder loop. Dat kan met geen enkel ander soort array.

[▶ 09:26:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33976s) · in VS Code [▶ 09:31:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34311s)

#### De null terminator en C-strings

Direct printen werkt alleen betrouwbaar als de array eindigt op het **null-teken** `'\0'` (null terminator). `std::cout` print teken voor teken door tot het een `'\0'` tegenkomt. Ontbreekt die, dan print het gewoon verder in het geheugen ná de array, met **garbage-tekens** als gevolg, tot het toevallig ergens een 0-byte vindt. De docent liet zien dat "Hello" dan gevolgd werd door rommel.

Een null-terminated character array heet een **C-string** (afkomstig uit de programmeertaal C). Manieren om er een te maken:

1. `char message1[] {'H', 'e', 'l', 'l', 'o', '\0'};` — de terminator zelf toevoegen; de compiler leidt grootte 6 af.
2. `char message2[6] {'H', 'e', 'l', 'l', 'o'};` — grootte 6 maar 5 tekens: het overgebleven element wordt met nul gevuld, en de nul-waarde van een `char` *is* `'\0'`.
3. `char message4[] {"Hello"};` — een **string literal** tussen dubbele aanhalingstekens; de compiler voegt `'\0'` automatisch toe, dus `sizeof` is 6.

**Geen** C-string: `char message3[] {'H', 'e', 'l', 'l', 'o'};` — de compiler leidt grootte 5 af uit de initializer, en er is geen plek voor een terminator. Printen met `std::cout` is dan onveilig.

Ook: `char message[5] {'H','e','l','l','o','\0'};` (6 waarden in een array van 5) geeft de compilerfout "too many initializer values" / "too many initializers".

[▶ 09:27:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34072s) · in VS Code [▶ 09:35:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34548s)

#### String literals

Tekens één voor één tussen enkele quotes typen is lelijk en onpraktisch: niemand wil zo tekst invoeren. Met een **string literal** (`"..."`) zeg je tegen C++: "breek dit op in tekens, stop ze in de array en voeg netjes een null terminator toe". Spaties en leestekens mogen gewoon: `char message5[] {"Hello World, how are you doing?"};`. Dit is volgens de docent de aanbevolen en "beschaafde" manier, en zo werkt de rest van de cursus.

[▶ 09:30:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34213s) · in VS Code [▶ 09:43:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34981s)

#### Andere arrays kun je niet direct printen

Ter bewijs dat character arrays speciaal zijn: `int numbers[] {1, 2, 3, 4, 5}; std::cout << numbers;` compileert wel, maar print geen `1 2 3 4 5`. Je krijgt een vreemd (hexadecimaal) getal. Waarom dat zo is, legt de docent uit in het hoofdstuk over pointers: het is het geheugenadres van de array.

[▶ 09:44:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35080s)

#### Array bounds: buiten de grenzen lezen en schrijven

Een array krijgt precies het aantal geheugenplekken dat je opgeeft (of dat de compiler afleidt). Alleen die plekken mag je gebruiken. Wat ervoor of erna ligt, kan van een ander deel van je programma zijn, van een ander programma, of zelfs van het besturingssysteem.

C++ houdt je **niet** tegen: `numbers[12]` bij een array van 10 elementen compileert gewoon. De gevolgen:
- **Lezen** buiten de grenzen geeft garbage, of je programma crasht omdat je beschermd geheugen leest.
- **Schrijven** buiten de grenzen wordt ook toegestaan. Je bezit dat geheugen niet, dus iets anders kan het overschrijven (je leest later iets anders terug), of jij overschrijft data van iets anders.
- De docent schreef op index `1000000` (een miljoen plekken verderop): het programma **crasht**. Een `std::cout`-regel daarna wordt nooit meer uitgevoerd, omdat het besturingssysteem het programma afschiet.

C++ laat dit toe omdat het ervan uitgaat dat jij als ontwikkelaar weet wat je doet. De boodschap: **blijf binnen de grenzen van je array.**

[▶ 09:46:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35177s) · in VS Code [▶ 09:49:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35370s)

> 💡 Aanvulling: in standaardtermen is lezen/schrijven buiten de grenzen *undefined behavior* (UB): alles kan gebeuren, ook dat het "lijkt te werken". De docent zegt aan het eind dat bij de crash geheugen "niet goed teruggegeven" wordt aan het OS; in de praktijk ruimt een modern besturingssysteem het geheugen van een gecrasht proces wel op. Het echte probleem is dat het gedrag onvoorspelbaar is. Hulpmiddel bij het zoeken: compileer met `-fsanitize=address` (Linux/macOS) om zulke fouten te laten melden.

### Codevoorbeelden

#### Ongeïnitialiseerde array lezen (junk data) [▶ 09:00:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32440s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: leest ongeïnitialiseerde elementen (junk data, UB) – output elke keer anders
#include <iostream>

int main() {
    int scores[10]; // 10 ints, NIET geïnitialiseerd: junk data

    std::cout << "scores[0] : " << scores[0] << std::endl;
    std::cout << "scores[1] : " << scores[1] << std::endl;

    for (size_t i {0}; i < 10; ++i) {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }
    return 0;
}
```

Voorbeeldoutput: willekeurige getallen zoals `scores[0] : 4200987` en `scores[1] : 0`. Ze kunnen bij elke run of build anders zijn.

#### Data schrijven: handmatig en in een loop [▶ 09:03:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32632s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int scores[10] {}; // {} zet alles op 0, zodat er geen junk data in staat

    // Handmatig schrijven
    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    std::cout << "Handmatig geschreven:" << std::endl;
    for (size_t i {0}; i < 3; ++i) {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }

    // Schrijven in een loop: index = huidige iteratie
    for (size_t i {0}; i < 10; ++i) {
        scores[i] = static_cast<int>(i) * 10;
    }

    std::cout << "Geschreven in een loop:" << std::endl;
    for (size_t i {0}; i < 10; ++i) {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }
    return 0;
}
```

```text
Handmatig geschreven:
scores[0] : 20
scores[1] : 21
scores[2] : 22
Geschreven in een loop:
scores[0] : 0
scores[1] : 10
scores[2] : 20
scores[3] : 30
scores[4] : 40
scores[5] : 50
scores[6] : 60
scores[7] : 70
scores[8] : 80
scores[9] : 90
```

> 💡 Aanvulling: de docent laat de array ongeïnitialiseerd en schrijft er alleen 0–2 in; dan zijn 3–9 nog junk. Hier is `{}` gebruikt zodat de output voorspelbaar is.

#### Declareren en initialiseren in één statement (`double`) [▶ 09:07:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32869s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};

    for (size_t i {0}; i < 5; ++i) {
        std::cout << "salary " << i << " : " << salaries[i] << std::endl;
    }
    return 0;
}
```

```text
salary 0 : 12.7
salary 1 : 7.5
salary 2 : 13.2
salary 3 : 8.1
salary 4 : 9.3
```

#### Gedeeltelijk initialiseren: de rest wordt 0 [▶ 09:09:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=32968s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int families[5] {12, 7, 5}; // index 3 en 4 worden 0

    for (size_t i {0}; i < 5; ++i) {
        std::cout << "families[" << i << "] : " << families[i] << std::endl;
    }
    return 0;
}
```

```text
families[0] : 12
families[1] : 7
families[2] : 5
families[3] : 0
families[4] : 0
```

#### Grootte weglaten + range-based for loop [▶ 09:10:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33016s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Grootte wordt afgeleid uit de initializer: 7 elementen
    int class_sizes[] {10, 12, 15, 11, 18, 17, 23};

    // Range-based for loop: past zich automatisch aan de grootte aan
    for (auto value : class_sizes) {
        std::cout << "value : " << value << std::endl;
    }
    return 0;
}
```

```text
value : 10
value : 12
value : 15
value : 11
value : 18
value : 17
value : 23
```

Grootte weglaten zonder initializer geeft een compilerfout:

```cpp
// ❌ bewust fout: grootte ontbreekt en er is geen initializer – compiler weet niet hoeveel ruimte nodig is
#include <iostream>

int main() {
    int class_sizes[]; // error: storage size of 'class_sizes' isn't known
    return 0;
}
```

#### Const array [▶ 09:11:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33111s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: schrijven naar een const array geeft een compilerfout
#include <iostream>

int main() {
    const int birds[] {10, 12, 15, 11, 18, 17, 23};
    birds[2] = 8; // error: assignment of read-only location 'birds[2]'
    return 0;
}
```

Lezen uit een const array mag wel:

```cpp
#include <iostream>

int main() {
    const int birds[] {10, 12, 15, 11, 18, 17, 23};

    std::cout << "birds[2] : " << birds[2] << std::endl; // lezen is prima
    return 0;
}
```

```text
birds[2] : 15
```

#### Elementen optellen [▶ 09:13:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33207s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. De docent noemt alleen 2 en 5 als eerste elementen en de som 37; de overige waarden zijn zo gekozen dat de som klopt.

```cpp
#include <iostream>

int main() {
    int scores[] {2, 5, 8, 10, 12};
    int sum {0};

    for (int element : scores) {
        sum += element; // 0+2=2, 2+5=7, 7+8=15, ...
    }

    std::cout << "Sum : " << sum << std::endl;
    return 0;
}
```

```text
Sum : 37
```

#### Arrays bevatten één type

```cpp
// ❌ bewust fout: een string past niet in een int-array (en 2.5 is narrowing)
#include <iostream>

int main() {
    int values[3] {1, 2.5, "drie"}; // compilerfout
    return 0;
}
```

#### Grootte opvragen met `std::size` [▶ 09:19:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33589s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <iterator> // std::size

int main() {
    int scores[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Werkelijk aantal elementen, ook als er later elementen bijkomen
    std::size_t count {std::size(scores)};

    for (std::size_t i {0}; i < count; ++i) {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }
    return 0;
}
```

```text
scores[0] : 1
scores[1] : 2
scores[2] : 3
scores[3] : 4
scores[4] : 5
scores[5] : 6
scores[6] : 7
scores[7] : 8
scores[8] : 9
scores[9] : 10
scores[10] : 11
scores[11] : 12
```

#### `sizeof` en de oude telmethode [▶ 09:21:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33685s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Uitgaande van een 4-byte `int` (zoals bij de docent en bij GCC op Windows/Linux).

```cpp
#include <iostream>

int main() {
    int scores[] {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl;       // hele array
    std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl; // één element

    // Vóór C++17: aantal = totale bytes / bytes per element
    std::size_t count {sizeof(scores) / sizeof(scores[0])};
    std::cout << "count : " << count << std::endl;

    for (std::size_t i {0}; i < count; ++i) {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }
    return 0;
}
```

```text
sizeof(scores) : 32
sizeof(scores[0]) : 4
count : 8
scores[0] : 1
scores[1] : 2
scores[2] : 3
scores[3] : 4
scores[4] : 5
scores[5] : 6
scores[6] : 7
scores[7] : 8
```

#### Range-based for loop: geen grootte nodig [▶ 09:24:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=33880s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int scores[] {1, 2, 3, 4, 5, 6, 7};

    for (auto i : scores) { // i is een waarde, geen index
        std::cout << "value : " << i << std::endl;
    }
    return 0;
}
```

```text
value : 1
value : 2
value : 3
value : 4
value : 5
value : 6
value : 7
```

#### Character array printen en wijzigen [▶ 09:31:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34311s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    char message[5] {'H', 'e', 'l', 'l', 'o'};

    std::cout << "message : ";
    for (auto c : message) {
        std::cout << c; // geen endl: tekens naast elkaar
    }
    std::cout << std::endl;

    message[1] = 'a'; // 'e' staat op index 1

    std::cout << "message : ";
    for (auto c : message) {
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}
```

```text
message : Hello
message : Hallo
```

#### Direct printen zonder null terminator (garbage) [▶ 09:35:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34500s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: geen '\0' aan het eind – std::cout leest voorbij de array (UB, garbage-tekens)
#include <iostream>

int main() {
    char message[5] {'H', 'e', 'l', 'l', 'o'};
    std::cout << "message : " << message << std::endl; // kan "Hello" + rommel printen

    char message3[] {'H', 'e', 'l', 'l', 'o'}; // grootte 5, GEEN C-string
    std::cout << "message3 : " << message3 << std::endl;
    std::cout << "size : " << sizeof(message3) << std::endl; // 5
    return 0;
}
```

Voorbeeldoutput: iets als `message : Hello╠╠╠@x` – wat er na "Hello" verschijnt is onvoorspelbaar.

#### Proper C-strings [▶ 09:38:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=34691s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // 1. Zelf de null terminator toevoegen; grootte afgeleid: 6
    char message1[] {'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << "message1 : " << message1 << std::endl;
    std::cout << "size : " << sizeof(message1) << std::endl;

    // 2. Grootte 6, 5 tekens: laatste element wordt '\0'
    char message2[6] {'H', 'e', 'l', 'l', 'o'};
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "size : " << sizeof(message2) << std::endl;

    // 3. String literal: compiler voegt '\0' toe
    char message4[] {"Hello"};
    std::cout << "message4 : " << message4 << std::endl;
    std::cout << "size : " << sizeof(message4) << std::endl;

    // Spaties en leestekens mogen gewoon
    char message5[] {"Hello World, how are you doing?"};
    std::cout << "message5 : " << message5 << std::endl;
    return 0;
}
```

```text
message1 : Hello
size : 6
message2 : Hello
size : 6
message4 : Hello
size : 6
message5 : Hello World, how are you doing?
```

Te veel initializers geeft een compilerfout:

```cpp
// ❌ bewust fout: 6 waarden in een array van 5 – "too many initializers"
#include <iostream>

int main() {
    char message[5] {'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << message << std::endl;
    return 0;
}
```

#### Een int-array direct printen [▶ 09:44:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35080s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

int main() {
    int numbers[] {1, 2, 3, 4, 5};
    std::cout << "numbers : " << numbers << std::endl; // print een adres, niet 1 2 3 4 5
    return 0;
}
```

```text
voorbeeldoutput:
numbers : 0x5ffe90
```

#### Buiten de grenzen lezen en schrijven [▶ 09:49:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35370s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: out-of-bounds lezen/schrijven (UB) – garbage of crash
#include <iostream>

int main() {
    int numbers[10] {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // geldig: 0..9

    // Lezen buiten de grenzen: compileert, geeft garbage
    std::cout << "numbers[12] : " << numbers[12] << std::endl;

    // Schrijven buiten de grenzen: geheugen dat niet van jou is!
    numbers[12] = 1000;
    std::cout << "numbers[12] : " << numbers[12] << std::endl;

    // Een miljoen plekken verderop: het OS stopt het programma (crash)
    numbers[1000000] = 2000000;
    std::cout << "numbers[1000000] : " << numbers[1000000] << std::endl;

    std::cout << "Program ending..." << std::endl; // wordt nooit bereikt na de crash
    return 0;
}
```

Voorbeeldoutput bij de docent: eerst een onbekend getal, dan (misschien) `1000`, daarna crasht het programma en verschijnt "Program ending..." niet.

### Valkuilen & veelgemaakte fouten

#### Tellen vanaf 1 in plaats van 0
Het eerste element is `arr[0]`, het laatste `arr[N-1]`. `arr[N]` ligt al buiten de array. Een loop moet `i < N` gebruiken, niet `i <= N`.

#### Ongeïnitialiseerde arrays gebruiken
`int scores[10];` bevat junk data. Lees pas als je er zelf iets in hebt geschreven, of initialiseer met `{}`.

#### Hardgecodeerde grootte in loops
Verandert het aantal elementen, dan klopt `i < 10` niet meer: je mist elementen of leest buiten de grenzen. Gebruik `std::size` of een range-based for loop.

#### Grootte weglaten zonder initializer
`int arr[];` compileert niet: de compiler weet niet hoeveel ruimte hij moet reserveren.

#### Een `const` array proberen te wijzigen
`birds[2] = 8;` op een `const` array geeft een compilerfout ("expression must be a modifiable lvalue").

#### Dezelfde naam twee keer declareren
Bij het experimenteren in één `main` krijg je "redeclaration of 'scores'". Hernoem of verwijder de oude declaratie.

#### Character array zonder null terminator printen
`char msg[] {'H','e','l','l','o'};` heeft grootte 5 en geen `'\0'`; `std::cout << msg` print door tot het ergens een 0-byte vindt, met garbage of erger als gevolg. Zorg voor een `'\0'` of gebruik een string literal.

#### Te weinig ruimte voor de terminator
`char msg[5] {"Hello"};` of 6 tekens in `char msg[5]` geeft "too many initializers": "Hello" heeft 6 plekken nodig (5 tekens + `'\0'`).

#### Verwachten dat `std::cout << intArray` de elementen print
Alleen `char`-arrays worden als tekst geprint; bij andere arrays zie je een adres.

#### Buiten de grenzen lezen of schrijven
C++ controleert het niet. Het gevolg is garbage data, het overschrijven van andermans data, of een crash. Het "lijkt te werken" is geen bewijs dat het goed is.

#### Index kwijt in een range-based for loop
`for (auto i : scores)` geeft waarden, geen indexen. Heb je de positie nodig, gebruik dan de klassieke loop.

### Best practices

- Initialiseer arrays altijd, minstens met `{}` (alles 0).
- Gebruik een range-based for loop als je alleen de waarden nodig hebt; dat is het eenvoudigst en het veiligst tegen grootte-wijzigingen.
- Heb je indexen nodig, gebruik dan `std::size(arr)` in de loopconditie in plaats van een hardgecodeerd getal; `sizeof(arr)/sizeof(arr[0])` is het pre-C++17 alternatief.
- Maak een array `const` als de data niet mag veranderen.
- Initialiseer character arrays met string literals (`char msg[] {"Hello"};`), zodat de null terminator automatisch wordt toegevoegd.
- Blijf altijd binnen de grenzen `0 .. N-1`.

> 💡 Aanvulling: in modern C++ worden vaak `std::array` (vaste grootte, kent zijn eigen `size()`, `at()` met bounds-check) en `std::string` gebruikt in plaats van ruwe arrays en C-strings. De docent behandelt `std::string` in hoofdstuk 10.

### Samenvatting

- Een array groepeert meerdere variabelen van **hetzelfde type** aaneengesloten in het geheugen onder één naam.
- Declaratie: `type naam[grootte];`; toegang via `naam[index]`, met indexen van **0** tot **grootte−1**.
- Ongeïnitialiseerde arrays bevatten junk data; met `{...}` initialiseer je ze. Ontbrekende elementen worden 0, en `[]` zonder grootte laat de compiler tellen.
- `const` arrays kun je lezen maar niet wijzigen.
- `std::size(arr)` (C++17) geeft het aantal elementen; vroeger gebruikte men `sizeof(arr) / sizeof(arr[0])`.
- Range-based for loops (`for (auto x : arr)`) zijn de eenvoudigste manier om alle waarden te bezoeken, maar je ziet geen index.
- `char`-arrays kun je direct printen, maar alleen correct als ze null-terminated zijn (`'\0'`): een **C-string**.
- String literals (`"Hello"`) voegen automatisch de null terminator toe; `char msg[] {"Hello"};` heeft daarom grootte 6.
- Andere arrays direct printen geeft een adres (uitleg in hoofdstuk 8).
- Buiten de grenzen lezen/schrijven compileert, maar leidt tot garbage, corruptie of een crash. Blijf binnen de bounds.

### Oefeningen

1. Declareer een `int`-array van 5 elementen, vul die in een loop met de kwadraten van de index (0, 1, 4, 9, 16) en print elk element met zijn index.
2. Gegeven `double temps[] {21.5, 19.0, 23.5, 18.0, 22.0};`: bereken met een range-based for loop het gemiddelde en print het. Gebruik `std::size` om door het aantal elementen te delen.
3. Gegeven `int values[] {7, 3, 9, 1, 12, 5};`: zoek met een klassieke loop en `std::size` het grootste getal **en** de index waarop het staat.
4. Maak een C-string met een string literal `"programmeren"`. Print de `sizeof` van de array, tel daarna met een loop het aantal tekens vóór de `'\0'`, en vervang elke `'e'` door een `'E'` voordat je de string print.

<details><summary>Uitwerking</summary>

```cpp
// Oefening 1
#include <iostream>

int main() {
    int squares[5] {};
    for (size_t i {0}; i < 5; ++i) {
        squares[i] = static_cast<int>(i * i);
    }
    for (size_t i {0}; i < 5; ++i) {
        std::cout << "squares[" << i << "] : " << squares[i] << std::endl;
    }
    return 0;
}
```

```text
squares[0] : 0
squares[1] : 1
squares[2] : 4
squares[3] : 9
squares[4] : 16
```

```cpp
// Oefening 2
#include <iostream>
#include <iterator>

int main() {
    double temps[] {21.5, 19.0, 23.5, 18.0, 22.0};
    double total {0.0};
    for (double t : temps) {
        total += t;
    }
    double average {total / static_cast<double>(std::size(temps))};
    std::cout << "Average : " << average << std::endl;
    return 0;
}
```

```text
Average : 20.8
```

```cpp
// Oefening 3
#include <iostream>
#include <iterator>

int main() {
    int values[] {7, 3, 9, 1, 12, 5};
    std::size_t max_index {0};
    for (std::size_t i {1}; i < std::size(values); ++i) {
        if (values[i] > values[max_index]) {
            max_index = i;
        }
    }
    std::cout << "Max : " << values[max_index] << " at index " << max_index << std::endl;
    return 0;
}
```

```text
Max : 12 at index 4
```

```cpp
// Oefening 4
#include <iostream>

int main() {
    char word[] {"programmeren"};
    std::cout << "sizeof : " << sizeof(word) << std::endl; // 12 tekens + '\0'

    std::size_t length {0};
    while (word[length] != '\0') {
        ++length;
    }
    std::cout << "length : " << length << std::endl;

    for (std::size_t i {0}; i < length; ++i) {
        if (word[i] == 'e') {
            word[i] = 'E';
        }
    }
    std::cout << "word : " << word << std::endl;
    return 0;
}
```

```text
sizeof : 13
length : 12
word : programmErEn
```

</details>

---

<a id="h08"></a>

## Hoofdstuk 8 – Pointers (09:53:23 – 12:11:04) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35603s)

### Leerdoelen

Na dit hoofdstuk kun je:

- uitleggen wat een pointer is: een variabele die het **adres** van een andere variabele opslaat;
- pointers declareren, initialiseren met `nullptr` of met een adres (`&`), en dereferencen (`*`);
- uitleggen waarom alle pointers op één systeem even groot zijn, en waarom je pointers van verschillende types niet door elkaar mag toewijzen;
- de valkuil van `int* a, b;` herkennen;
- werken met `const char*` naar een string literal en het verschil met een `char`-array begrijpen;
- het geheugenmodel van een programma beschrijven: virtueel geheugen, memory map, MMU, stack en heap;
- geheugen dynamisch op de heap aanvragen met `new` en vrijgeven met `delete`;
- de drie soorten dangling pointers herkennen en voorkomen;
- afhandelen dat `new` mislukt, met `try`/`catch` of met `std::nothrow`;
- null pointer safety toepassen (controleren op `nullptr`, en weten dat `delete nullptr` veilig is);
- memory leaks herkennen (pointer overschrijven, dubbele allocatie, scope verlaten);
- dynamische arrays aanmaken met `new[]`, vrijgeven met `delete[]`, en de beperkingen ervan kennen (geen `std::size`, geen range-based `for`).

### Verband met eerdere hoofdstukken

- **Hoofdstuk 2 (executiemodel)**: daar zag je hoe een programma gecompileerd en in het geheugen geladen wordt. In dit hoofdstuk wordt dat model uitgebreid met virtueel geheugen, de memory map, stack en heap.
- **Hoofdstuk 3 (variabelen en datatypes)**: braced initialization (`{}`) en `sizeof` komen terug. Een pointer met `{}` initialiseren levert `nullptr` op. Adressen worden hexadecimaal getoond (talstelsels).
- **Hoofdstuk 5 (flow control)**: `if`/`else` gebruik je hier voor `nullptr`-controles.
- **Hoofdstuk 6 (loops)**: met `for`-loops doorloop je dynamische arrays en put je in de demo de heap uit.
- **Hoofdstuk 7 (arrays)**: stack-arrays, `std::size`, range-based `for`, en dat een `char`-array met een string literal geïnitialiseerd kan worden. Hier zie je dat een array naar een pointer kan *vervallen* (decay) en dat dynamische arrays daardoor die gemakken verliezen.
- **Vooruitblik**: hoofdstuk 9 (references) bouwt direct op pointers voort, en exceptions (`try`/`catch`) komen later in de cursus uitgebreider aan bod.

### Uitleg

#### Wat is een pointer?

Tot nu toe gebruikte je variabelen gewoon: waarde erin zetten, uitprinten, een nieuwe waarde toewijzen. Elke variabele heeft echter ook een **adres** in het geheugen. In het voorbeeld van de docent staat `int var` op adres `1008`. Dat adres kun je opvragen en bewaren in een speciaal soort variabele: een **pointer**.

- Een pointer is een variabele die **adressen van andere variabelen** opslaat.
- Het type schrijf je met een ster na het type: `int*` betekent "pointer naar `int`". De pointer `p_var` heeft als naam `p_var`, als type `int*`, en als waarde bijvoorbeeld `1008`, het adres van `var`.
- Je kunt een pointer naar elk type maken: `char*`, `double*`, `float*` en later ook naar eigen types (klassen).

Pointers en gewone variabelen werken dus samen: de pointer "wijst" naar de variabele.

[▶ 09:53:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35612s)

#### Pointers declareren en initialiseren

Syntax:

```
int* p_number {};                 // braced initializer -> nullptr
double* p_fractional_number {};
int* p_number1 {nullptr};         // expliciet nullptr
```

- Een pointer naar `int` mag **alleen** adressen van `int`-variabelen bevatten. Een adres van een ander type erin zetten levert een compilerfout op.
- Met lege accolades `{}` wordt een pointer geïnitialiseerd met de "nul-waarde" voor pointers, en dat is `nullptr`. Dat is een speciaal adres dat betekent: *deze pointer wijst nog nergens naar*. Je kunt `nullptr` ook expliciet invullen.
- Een pointer die `nullptr` bevat mag je **niet** dereferencen: er staat daar niets bruikbaars.
- De docent raadt sterk aan pointers **altijd te initialiseren**. Een niet-geïnitialiseerde pointer bevat een willekeurig (junk) adres.

[▶ 09:55:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=35754s) · [▶ in VS Code 10:02:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36135s)

#### Alle pointers zijn even groot

Een pointer naar `int` en een pointer naar `double` slaan precies hetzelfde soort ding op: een adres. Daarom zijn **alle pointers op één systeem even groot**, ongeacht het type waarnaar ze wijzen. Op de 64-bit machine van de docent gaf `sizeof(int)` 4, `sizeof(double)` 8, en elke pointer 8 bytes. Die grootte is niet gelijk tussen alle besturingssystemen of systemen (op 32-bit is het meestal 4), maar op één machine is ze voor alle pointertypes gelijk.

[▶ 10:05:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36331s)

#### Plaats van de ster en meerdere declaraties op één regel

- Of je `int* p`, `int *p` of zelfs `int * p` schrijft maakt voor de compiler niet uit. De docent zet de ster het liefst links (bij het type).
- Verwarrend wordt het bij `int* p_number5{}, other_int_var{};`. De vraag is of `other_int_var` ook een pointer is. Met `sizeof` toont de docent dat het antwoord **nee** is: `p_number5` is 8 bytes (pointer), `other_int_var` is 4 bytes (gewone `int`). De ster hoort bij de naam die erop volgt, niet bij het type voor de hele regel.
- Advies: declareer pointers elk op een eigen regel, dan is er geen verwarring mogelijk.

[▶ 10:06:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36379s) · [▶ 10:07:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36427s)

#### Een adres opslaan met de address-of operator `&`

Nieuw is de operator `&` voor een variabele: `&int_var` betekent "het adres van `int_var`".

```
int int_var {43};
int* p_int {&int_var};   // p_int wijst naar int_var
```

- Print je `int_var`, dan zie je 43. Print je `p_int`, dan zie je een **adres**, hexadecimaal (bijvoorbeeld `0x61fe14`).
- Een pointer kan later naar een andere variabele wijzen: `p_int = &int_var1;`. Daarna print je een ander adres (bij de docent eindigde het eerst op `de4`, daarna op `de0`).
- **Geen kruiselingse toewijzing**: `int* p_int1 {}; double double_var{33}; p_int1 = &double_var;` geeft de fout dat een `double*` niet aan een `int*` kan worden toegewezen. VS Code toont al een rode kronkellijn ("a value of type double* cannot be assigned to an entity of type int*"), en GCC weigert het te compileren.

[▶ 10:08:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36522s)

#### Dereferencen: lezen via een pointer

**Dereferencen** is via een pointer bij de waarde komen die op dat adres staat. Je schrijft een ster vóór de pointervariabele:

```
int* p_int2 {nullptr};
int int_data {56};
p_int2 = &int_data;
std::cout << *p_int2;    // 56
```

Let op het dubbele gebruik van `*`: in een declaratie (`int* p`) betekent het "dit is een pointer"; in een expressie (`*p`) betekent het "de waarde waar p naar wijst". Via `*p = ...` kun je ook schrijven naar de variabele waarnaar gewezen wordt.

[▶ 10:12:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36761s)

#### Pointer naar `char`

Een `char*` werkt in de basis zoals elke pointer: je kunt hem laten wijzen naar een `char`-variabele (`'A'`), dereferencen, en hem daarna naar een andere `char` (`'C'`) laten wijzen.

Bijzonder is dat je een `char`-pointer kunt initialiseren met een **string literal**:

```
const char* p_message {"Hello World!"};
```

- De compiler maakt van `"Hello World!"` een **array van `const char`**, en `p_message` wijst naar het **eerste** teken van die array. (De relatie tussen arrays en pointers komt later uitgebreider aan bod.)
- Omdat de array uit `const char` bestaat, moet de pointer een `const char*` zijn. Schrijf je `char* p_message {"Hello World!"};`, dan weigeren moderne compilers dat. Visual Studio 2019 (MSVC) geeft een fout, en GCC meldt ook dat dit niet mag ("ISO C++ forbids converting a string constant to `char*`"). Met `const` erbij compileren beide.
- `std::cout << p_message` print de **hele** string: `char`-pointers zijn speciaal, `std::cout` print alle tekens vanaf het adres tot aan het afsluitende nul-teken.
- `std::cout << *p_message` print alleen het eerste teken: `H`.
- Via de pointer de string wijzigen (`*p_message = 'B';`) mag niet: dat is een compilerfout bij `const char*`. Zonder `const` zou het zelfs op runtime kunnen crashen.
- Wil je de string wel kunnen wijzigen, gebruik dan een gewone `char`-array: `char message1[] {"Hello World!"}; message1[0] = 'B';` geeft `Bello World!`.

De vuistregel van de docent: wil je de string alleen opslaan en printen, gebruik `const char*`. Wil je hem kunnen aanpassen, gebruik een `char`-array.

[▶ 10:14:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36857s) · [▶ in VS Code 10:21:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=37291s)

> ⚠️ Onduidelijk in opname: in de slides spreekt de docent eerst over de `H` veranderen in een `B`, en bij het array-voorbeeld over een `T`. In VS Code gebruikt hij `message1[0] = 'B'` (resultaat `Bello World!`). Het principe is hetzelfde: alleen een array (geen string literal) mag je wijzigen.

#### Het geheugenmodel herzien: virtueel geheugen en de memory map

De ontwikkelcyclus blijft: code → compiler → binair uitvoerbaar bestand (bij de docent `rooster.exe`). Start je dat programma, dan wordt het in het **RAM** geladen (werkgeheugen, niet de harde schijf, die ook wel "geheugen" genoemd wordt).

Maar een programma gebruikt niet rechtstreeks het echte RAM:

- **Waarom virtueel geheugen?** Er draaien honderden of duizenden programma's tegelijk. Als elk direct echt geheugen zou claimen, raak je snel op. Daarom laat het besturingssysteem elk programma geloven dat het **alleen** draait en de **hele adresruimte** bezit.
- Elk programma draait als een **proces**. Elk proces ziet een adresbereik van 0 tot 2ⁿ, met n het aantal bits van het systeem (0 tot 2⁶⁴ op 64-bit, 0 tot 2³² op 32-bit). Dat beeld van het geheugen heet de **memory map**.
- De **Memory Management Unit (MMU)**, een onderdeel van de CPU, vertaalt tussen de memory map van elk proces en de echte indeling van het RAM. Alleen de delen van het programma die binnenkort nodig zijn, worden echt in het RAM geladen. Delen die waarschijnlijk niet gebruikt worden, worden op de harde schijf geparkeerd. De details zijn complex en verborgen in CPU en OS; als C++-programmeur hoef je je daar niet mee bezig te houden.
- De opbouw van de memory map is een **standaard van het besturingssysteem**. Daarom kun je een Windows-executable niet zomaar op Linux draaien: alle programma's voor een OS moeten zich aan diens memory map houden.

De memory map bestaat uit secties, onder andere:

| Sectie | Inhoud |
|---|---|
| **text** | de binaire code van het programma die de CPU uitvoert |
| **data** | (globale/statische) data |
| **heap** | extra geheugen dat je dynamisch kunt aanvragen |
| **stack** | lokale variabelen van `main` en andere functies |

Voor deze cursus zijn **stack** en **heap** de belangrijke delen. Op internet zie je verschillende varianten van dit plaatje; het idee blijft hetzelfde.

[▶ 10:27:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=37631s)

#### Dynamische geheugenallocatie: stack versus heap

Eerst herhaalt de docent hoe pointers tot nu toe gebruikt werden: een stack-variabele aanmaken en het adres ervan in een pointer zetten (bij declaratie of later). Daarna twee regels die je nooit mag breken:

1. **Gebruik geen niet-geïnitialiseerde pointer.** `int* p_number2; *p_number2 = 55;` schrijft naar een willekeurig adres. Dat kan geheugen van een ander programma of van het OS zijn. Gevolg: een crash of beschadigde data. In de demo print het programma nog "Writing 55" en wordt daarna door het besturingssysteem afgeschoten; alle regels erna (ook het vrijgeven van eerder gealloceerd geheugen) worden nooit uitgevoerd.
2. **Gebruik geen pointer die `nullptr` bevat.** `int* p_number3{}; *p_number3 = 33;` is **undefined behavior**: C++ geeft geen enkele garantie, in de demo crasht het programma.

Verschil tussen stack en heap:

| | Stack | Heap |
|---|---|---|
| Grootte | eindig | ook eindig, maar extra geheugen voor als de stack niet genoeg is |
| Levensduur | bepaald door de **scope**: de variabele sterft bij de sluitende `}` | de **programmeur** bepaalt wanneer het geheugen ontstaat en verdwijnt |

Bij `{ int local_scope_var {23}; }` heb jij als ontwikkelaar geen controle over wanneer de variabele verdwijnt. Soms wil je dat juist wel, en daarvoor dient de heap.

Syntax om op de heap te alloceren:

```
int* p_number4 {nullptr};
p_number4 = new int;   // vraag 4 bytes op de heap
*p_number4 = 77;       // gebruik via dereferencen
```

- Op het moment dat `new int` uitgevoerd wordt, krijgt je programma een stuk heapgeheugen dat groot genoeg is voor een `int` (4 bytes). Het is **van jou** en geen ander programma kan het gebruiken, tot je het expliciet teruggeeft.
- Geheugen dat met `new` verkregen is blijft bestaan, ook buiten de scope waarin het aangevraagd werd, zolang je er nog een pointer naar hebt.

[▶ 10:36:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=38164s) · [▶ in VS Code 10:46:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=38794s) · [▶ slechte gevallen 10:49:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=38940s) · [▶ new 10:53:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39228s)

#### Geheugen teruggeven met `delete`

```
delete p_number4;      // geef het geheugen terug aan het OS
p_number4 = nullptr;   // reset de pointer
```

- Na `delete` is het geheugen niet meer van jou. Er staat junk in. Schrijf je er toch naartoe (`*p_number4 = 45;` na `delete`), dan compileert dat gewoon, maar in de demo crasht het programma.
- Zet de pointer daarom na `delete` **altijd** op `nullptr`. Dan kunnen jij en andere ontwikkelaars controleren of er een geldig adres in zit voor ze hem gebruiken.
- Het stappenplan van de docent: pointer declareren → met `new` geheugen voor een type aanvragen → via de pointer gebruiken → met `delete` vrijgeven → pointer op `nullptr` zetten.

Je kunt een pointer ook meteen bij declaratie met dynamisch geheugen initialiseren:

```
int* p_number5 {new int};       // niet-geïnitialiseerde int op de heap: junkwaarde
int* p_number6 {new int(22)};   // direct initialisatie
int* p_number7 {new int{23}};   // braced initialisatie
```

`*p_number5` bevat junk, omdat je er zelf niets in gezet hebt. Gebruik die waarde niet.

**Pointers hergebruiken**: na `delete` en reset op `nullptr` blijft de pointervariabele zelf bestaan. Je kunt hem opnieuw laten wijzen naar nieuw geheugen: `p_number5 = new int(81);`. Vergeet niet ook dat nieuwe geheugen weer met `delete` vrij te geven.

**Nooit twee keer `delete`**: `delete p_number5; delete p_number5;` compileert, maar de runtime of het OS ziet dat je hetzelfde geheugen twee keer vrijgeeft en beëindigt het programma. Alles daarna (ook het vrijgeven van ander geheugen) wordt niet uitgevoerd. In de praktijk gebeurt dit zelden op twee regels na elkaar, maar wel wanneer meerdere pointers naar hetzelfde geheugen wijzen.

[▶ delete 10:55:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39324s) · [▶ initialiseren bij declaratie 10:58:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39516s) · [▶ hergebruik 11:00:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39610s) · [▶ dubbele delete 11:02:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39753s)

#### Dangling pointers

Een **dangling pointer** is een pointer die niet naar een geldig adres wijst. Dangling pointers leiden tot undefined behavior en kunnen je programma laten crashen. De docent onderscheidt drie gevallen:

1. **Niet-geïnitialiseerde pointer**: `int* p_number;` bevat een junkadres. Dereferencen kan crashen. In de demo crasht het programma inderdaad en wordt "Program ending well" niet geprint.
2. **Verwijderde pointer**: `int* p_number1 {new int{67}}; delete p_number1; *p_number1` lezen. In de demo eindigt het programma *soms gewoon goed*, maar dat is juist het gevaarlijke: je hebt geen garantie dat het elke keer zo gaat. Als dat geheugen intussen voor iets anders gebruikt wordt, crasht het.
3. **Meerdere pointers naar hetzelfde adres**: `int* p_number3 {new int{83}}; int* p_number4 {p_number3};`. Beide tonen hetzelfde adres en 83. Na `delete p_number3` wijst `p_number4` nog steeds naar het verwijderde geheugen; gebruik ervan is undefined behavior (junk, of een crash).

Oplossingen:

1. **Initialiseer pointers altijd**, met `nullptr` als je nog geen adres weet, of direct met `new`. Controleer vóór gebruik: `if (p_number6 != nullptr) ... else "Invalid address"`.
2. **Zet een pointer na `delete` op `nullptr`**, en controleer daarop vóór gebruik ("Invalid memory access").
3. **Meerdere pointers naar hetzelfde adres**: kies één **master pointer** die als enige het geheugen mag vrijgeven. De andere pointers (de docent noemt ze *slave*-pointers) mogen het geheugen lezen en gebruiken, maar controleren eerst of de master pointer niet `nullptr` is.

Daarmee wordt het gedrag van je programma consistent over verschillende runs.

[▶ 11:05:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39944s) · [▶ in VS Code 11:12:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=40328s) · [▶ oplossingen 11:17:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=40669s)

> 💡 Aanvulling: de master-pointer-aanpak werkt alleen zolang iedereen zich aan de afspraak houdt; de andere pointers zelf worden niet automatisch `nullptr`. Modern C++ lost dit eigendomsprobleem op met smart pointers (`std::unique_ptr`, `std::shared_ptr`).

#### Wanneer `new` mislukt

Meestal slaagt `new`, maar in zeldzame gevallen niet (de heap is niet oneindig). Doe je niets, dan crasht het programma. Veel code in de praktijk controleert dit niet, omdat het zo zelden gebeurt; maar als het nodig is, kun je het afhandelen.

De docent forceert het falen op twee manieren:

- in één keer een enorm aantal `int`s alloceren: `int* data = new int[10000000000000];`. Bij een té groot getal klaagt de compiler/VS Code al ("array is too large"), maar met een iets kleiner getal compileert het, en het programma eindigt niet goed;
- in een loop heel vaak `new int[100000000]` doen, tot de heap van het proces op is.

Twee manieren om het af te handelen:

1. **Het exception-mechanisme**: zet de code die kan mislukken in een `try`-blok, en vang het probleem op in een `catch (std::exception& ex)`-blok. `ex.what()` vertelt wat er misging. Het programma crasht niet en loopt door tot het einde. Wat "afhandelen" betekent hangt af van je programma: lukt het bijvoorbeeld niet om kleuren in te stellen, dan kun je de interface in zwart-wit tonen in plaats van te crashen. De `&` en exceptions worden later in de cursus uitgelegd.
2. **`std::nothrow`**: `new(std::nothrow) int[n]` gooit geen exception, maar geeft `nullptr` terug als het mislukt. Dat controleer je met `if (data != nullptr)`. VS Code toont hier een kronkellijn, maar GCC compileert het prima.

[▶ 11:24:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41054s) · [▶ in VS Code 11:28:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41293s) · [▶ try/catch 11:31:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41487s) · [▶ std::nothrow 11:35:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41726s)

> 💡 Aanvulling: `std::exception` staat in `<exception>` en `std::nothrow` in `<new>`. Een mislukte `new` gooit concreet een `std::bad_alloc`. Op Linux kan het besturingssysteem door *overcommit* grote allocaties eerst toestaan, zodat het falen pas later (of anders) optreedt.

#### Null pointer safety

**Null pointer safety** is een reeks controles die je doet om alleen pointers te gebruiken die een geldig adres bevatten.

- Uitgebreide versie: `if (p_number != nullptr) { ... geldig ... } else { ... ongeldig ... }`.
- Korte versie: `if (p_number) { ... }`. Een pointer wordt impliciet naar `bool` omgezet: `nullptr` geeft `false`, elk ander adres `true`.
- Ook vlak voor het einde van het programma zet de docent een pointer na `delete` nog op `nullptr`: het is hier technisch nutteloos, maar zo wordt het een gewoonte en schrijf je veiliger code.
- **`delete` op een `nullptr` is veilig.** Een controle als `if (p_number1 != nullptr) { delete p_number1; }` is overbodig ("overkill"); gewoon `delete p_number1;` volstaat.

[▶ 11:37:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41873s) · [▶ in VS Code 11:40:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42018s) · [▶ delete op nullptr 11:43:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42210s)

#### Memory leaks

Een **memory leak** ontstaat wanneer je de toegang verliest tot dynamisch gealloceerd geheugen: de pointer die ernaar wees is weg of wijst ergens anders naar. Je kunt het geheugen niet meer gebruiken en ook niet meer vrijgeven, terwijl het besturingssysteem denkt dat het nog van jouw programma is. Niemand kan het dus nog gebruiken.

Drie voorbeelden van de docent:

1. **Pointer overschrijven**: `int* p_number {new int{67}}; int number{55}; p_number = &number;`. De heap-`int` met 67 is onbereikbaar geworden.
2. **Dubbele allocatie**: `int* p_number1 {new int{55}}; p_number1 = new int{44};`. De `55` lekt. Een latere `delete p_number1` geeft alleen het geheugen met `44` vrij.
3. **Scope verlaten**: in een geneste scope `{ int* p_number2 {new int{57}}; }`. De pointer zelf is een lokale stack-variabele en sterft bij `}`, maar het heapgeheugen niet. `delete p_number2;` na de scope compileert niet meer, want `p_number2` bestaat daar niet. Geef het geheugen dus vrij **binnen** de scope.

Al deze programma's compileren en lopen zonder zichtbare fout: de compiler kan je hier niet tegen beschermen. Bij programma's die lang draaien (servers die maanden aanstaan) kan een groeiend lek ertoe leiden dat `new` uiteindelijk faalt en het programma beëindigd wordt. Vermijd memory leaks "als de pest": geef geheugen vrij zodra je het niet meer nodig hebt.

[▶ 11:45:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42306s) · [▶ in VS Code 11:49:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42595s) · [▶ geneste scope 11:53:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42790s)

#### Dynamisch gealloceerde arrays

Tot nu toe stonden arrays op de stack. Met `new` kun je ook arrays op de heap zetten:

```
size_t size {10};
double* p_salaries {new double[size]};                     // junkwaarden
int* p_students {new(std::nothrow) int[size]{}};            // alles 0
double* p_scores {new(std::nothrow) double[size]{1,2,3,4,5}}; // rest 0
```

- Zonder initializer bevatten de elementen junk.
- Met `{}` worden alle elementen 0.
- Met een initializerlijst worden de eerste elementen ingevuld en de rest op 0 gezet, net als bij stack-arrays.
- `new` reserveert zoveel ruimte als nodig is: 10 `double`s betekent ruimte voor 10 `double`s.
- Ook de `std::nothrow`-variant werkt voor arrays.
- De grootte hoeft **niet** `const` te zijn, in tegenstelling tot stack-arrays (hoofdstuk 7).
- Elementen benaderen kan met `p_scores[i]` of met pointer-aritmetiek `*(p_scores + i)`; beide werken even goed.
- Vrijgeven doe je met **`delete[]`** (vierkante haken!), daarna de pointer weer op `nullptr`.

**Beperkingen**: een stack-array zoals `int scores[10] {1,...,10};` werkt met `std::size(scores)` (geeft 10) en met een range-based `for`. Een dynamische array niet: de pointer `p_scores1` is gewoon een pointer naar een geheugenlocatie. De array is *vervallen* (decayed) tot een pointer en heeft de informatie over de grootte verloren. `std::size(p_scores1)` en `for (auto s : p_scores1)` geven allebei een compilerfout. Oplossing: bewaar de grootte zelf in een variabele en gebruik een gewone `for`-loop met index.

[▶ 11:55:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42931s) · [▶ in VS Code 12:00:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43218s) · [▶ delete[] 12:03:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43410s) · [▶ statisch vs. dynamisch 12:05:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43503s) · [▶ std::size werkt niet 12:07:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43651s)

### Codevoorbeelden

#### Pointers declareren en sizeof [▶ 10:02:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36135s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int* p_number {};                    // impliciet nullptr
    double* p_fractional_number {};
    int* p_number1 {nullptr};            // expliciet nullptr
    double* p_fractional_number1 {nullptr};

    std::cout << "sizeof int : " << sizeof(int) << std::endl;
    std::cout << "sizeof double : " << sizeof(double) << std::endl;
    std::cout << "sizeof double* : " << sizeof(double*) << std::endl;
    std::cout << "sizeof int* : " << sizeof(int*) << std::endl;
    std::cout << "sizeof p_number : " << sizeof(p_number) << std::endl;
    std::cout << "sizeof p_fractional_number : " << sizeof(p_fractional_number) << std::endl;
    std::cout << "sizeof p_number1 : " << sizeof(p_number1) << std::endl;
    std::cout << "sizeof p_fractional_number1 : " << sizeof(p_fractional_number1) << std::endl;
    // nocheck-output (pointergrootte hangt af van het platform)
    return 0;
}
```

Voorbeeldoutput (64-bit systeem):

```text
sizeof int : 4
sizeof double : 8
sizeof double* : 8
sizeof int* : 8
sizeof p_number : 8
sizeof p_fractional_number : 8
sizeof p_number1 : 8
sizeof p_fractional_number1 : 8
```

#### Positie van de ster en declaraties op één regel [▶ 10:06:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36379s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int* p_number2 {};   // ster links (voorkeur docent)
    int *p_number3 {};   // ster rechts
    int * p_number4 {};  // ster in het midden: legaal, maar vreemd

    // Verwarrend: alleen p_number5 is een pointer!
    int* p_number5 {}, other_int_var {};
    int *p_number6 {}, other_int_var6 {};

    std::cout << "sizeof p_number5 : " << sizeof(p_number5) << std::endl;
    std::cout << "sizeof other_int_var : " << sizeof(other_int_var) << std::endl;
    std::cout << "sizeof p_number6 : " << sizeof(p_number6) << std::endl;
    std::cout << "sizeof other_int_var6 : " << sizeof(other_int_var6) << std::endl;

    // Beter: elke declaratie op een eigen regel
    int* p_number7 {};
    int other_int_var7 {};

    (void)p_number2; (void)p_number3; (void)p_number4; // ongebruikt in deze demo
    (void)p_number7; (void)other_int_var7;
    // nocheck-output (pointergrootte hangt af van het platform)
    return 0;
}
```

Voorbeeldoutput (64-bit systeem):

```text
sizeof p_number5 : 8
sizeof other_int_var : 4
sizeof p_number6 : 8
sizeof other_int_var6 : 4
```

#### Een adres opslaan en de pointer verzetten [▶ 10:08:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36522s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int int_var {43};
    int* p_int {&int_var};   // & = address-of operator

    std::cout << "Int var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl;

    int int_var1 {65};
    p_int = &int_var1;       // pointer wijst nu naar een andere variabele
    std::cout << "p_int (with different address) : " << p_int << std::endl;
    // nocheck-output (adressen verschillen per run)
    return 0;
}
```

Voorbeeldoutput:

```text
Int var : 43
p_int (Address in memory) : 0x61fde4
p_int (with different address) : 0x61fde0
```

#### Kruiselingse toewijzing is verboden [▶ 10:11:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36666s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: double* kan niet aan int* worden toegewezen
#include <iostream>

int main() {
    int* p_int1 {nullptr};
    double double_var {33};
    p_int1 = &double_var;   // compilerfout: cannot convert 'double*' to 'int*'
    return 0;
}
```

#### Dereferencen [▶ 10:12:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=36761s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int* p_int2 {nullptr};
    int int_data {56};
    p_int2 = &int_data;

    std::cout << "value : " << *p_int2 << std::endl;   // lezen via de pointer

    *p_int2 = 60;                                       // schrijven via de pointer
    std::cout << "int_data : " << int_data << std::endl;
    return 0;
}
```

```text
value : 56
int_data : 60
```

#### Pointer naar char en const char* [▶ 10:21:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=37291s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Gewone char-pointer naar een char-variabele
    char* p_char_var {nullptr};
    char char_var {'A'};
    p_char_var = &char_var;
    std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

    char char_var1 {'C'};
    p_char_var = &char_var1;
    std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

    // String literal -> array van const char; pointer wijst naar het eerste teken
    const char* message {"Hello World!"};
    std::cout << "message : " << message << std::endl;    // hele string
    std::cout << "*message : " << *message << std::endl;  // alleen 'H'

    // Wijzigen? Gebruik een char-array
    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;
    return 0;
}
```

```text
The value stored in p_char_var is : A
The value stored in p_char_var is : C
message : Hello World!
*message : H
message1 : Bello World!
```

#### String literal wijzigen via een pointer [▶ 10:23:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=37437s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: char* naar string literal en schrijven in const char-array
#include <iostream>

int main() {
    char* p_message {"Hello World!"};   // fout: string literal is const char[13]
    const char* message {"Hello World!"};
    *message = 'B';                     // fout: assignment of read-only location
    std::cout << p_message << message << std::endl;
    return 0;
}
```

#### Niet-geïnitialiseerde en nullptr-pointers gebruiken (UB) [▶ 10:49:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=38940s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: UB-demo, schrijven via niet-geïnitialiseerde pointer en via nullptr
#include <iostream>

int main() {
    // Slecht 1: niet-geïnitialiseerde pointer bevat een junkadres
    int* p_number2;
    std::cout << "Writing 55" << std::endl;
    *p_number2 = 55;              // crash of corrupte data
    std::cout << "Done writing!" << std::endl;

    // Slecht 2: pointer naar nullptr
    int* p_number3 {};
    std::cout << "Writing 33" << std::endl;
    *p_number3 = 33;              // undefined behavior, meestal crash
    std::cout << "Done writing!" << std::endl;
    return 0;
}
```

#### Dynamisch geheugen: new en delete [▶ 10:53:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39228s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int* p_number4 {nullptr};
    p_number4 = new int;          // 4 bytes op de heap, nu van ons
    *p_number4 = 77;              // schrijven via de pointer
    std::cout << "Dynamically allocating memory : " << std::endl;
    std::cout << "*p_number4 : " << *p_number4 << std::endl;

    delete p_number4;             // geheugen terug naar het OS
    p_number4 = nullptr;          // reset: "ik bevat niets geldigs"

    // Initialiseren bij declaratie
    int* p_number6 {new int(22)};
    int* p_number7 {new int{23}};
    std::cout << "*p_number6 : " << *p_number6 << std::endl;
    std::cout << "*p_number7 : " << *p_number7 << std::endl;

    delete p_number6;
    p_number6 = nullptr;
    delete p_number7;
    p_number7 = nullptr;

    // Een pointer hergebruiken voor nieuw geheugen
    p_number6 = new int(81);
    std::cout << "*p_number6 (reused) : " << *p_number6 << std::endl;
    delete p_number6;
    p_number6 = nullptr;

    std::cout << "Program is ending well" << std::endl;
    return 0;
}
```

```text
Dynamically allocating memory : 
*p_number4 : 77
*p_number6 : 22
*p_number7 : 23
*p_number6 (reused) : 81
Program is ending well
```

#### Junkwaarde in niet-geïnitialiseerd heapgeheugen [▶ 10:58:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39516s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int* p_number5 {new int};    // geheugen gereserveerd, maar niet geïnitialiseerd
    std::cout << "p_number5 : " << p_number5 << std::endl;
    std::cout << "*p_number5 : " << *p_number5 << std::endl;   // junkwaarde, niet gebruiken
    delete p_number5;
    p_number5 = nullptr;
    // nocheck-output (adres en junkwaarde verschillen)
    return 0;
}
```

Voorbeeldoutput:

```text
p_number5 : 0x1e1a00
*p_number5 : 15867184
```

#### Gebruik na delete en dubbele delete (UB) [▶ 10:56:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=39371s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: UB-demo, schrijven na delete en twee keer delete
#include <iostream>

int main() {
    int* p_number4 {new int};
    *p_number4 = 77;
    delete p_number4;
    *p_number4 = 45;              // schrijven in vrijgegeven geheugen: UB
    std::cout << "Done writing" << std::endl;

    int* p_number5 {new int(99)};
    std::cout << *p_number5 << std::endl;
    delete p_number5;
    delete p_number5;             // dubbele delete: programma wordt afgebroken
    std::cout << "Program is ending well" << std::endl;   // wordt niet bereikt
    return 0;
}
```

#### De drie soorten dangling pointers (UB) [▶ 11:12:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=40328s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: UB-demo van dangling pointers
#include <iostream>

int main() {
    // Geval 1: niet-geïnitialiseerde pointer
    int* p_number;
    std::cout << "p_number : " << p_number << std::endl;
    std::cout << "*p_number : " << *p_number << std::endl;

    // Geval 2: verwijderde pointer
    int* p_number1 {new int{67}};
    std::cout << "*p_number1 (before delete) : " << *p_number1 << std::endl;
    delete p_number1;
    std::cout << "*p_number1 (after delete) : " << *p_number1 << std::endl;

    // Geval 3: twee pointers naar hetzelfde adres
    int* p_number3 {new int{83}};
    int* p_number4 {p_number3};
    std::cout << "p_number3 : " << p_number3 << " - " << *p_number3 << std::endl;
    std::cout << "p_number4 : " << p_number4 << " - " << *p_number4 << std::endl;
    delete p_number3;
    std::cout << "p_number4 (after deleting p_number3) : " << *p_number4 << std::endl;

    std::cout << "Program is ending well" << std::endl;
    return 0;
}
```

#### Oplossingen voor dangling pointers [▶ 11:17:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=40669s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Oplossing 1: altijd initialiseren en vóór gebruik controleren
    int* p_number5 {nullptr};
    int* p_number6 {new int(87)};

    if (p_number6 != nullptr) {
        std::cout << "*p_number6 : " << *p_number6 << std::endl;
    } else {
        std::cout << "Invalid address" << std::endl;
    }
    if (p_number5 != nullptr) {
        std::cout << "*p_number5 : " << *p_number5 << std::endl;
    } else {
        std::cout << "Invalid address" << std::endl;
    }

    // Oplossing 2: na delete resetten naar nullptr
    int* p_number7 {new int{82}};
    std::cout << "*p_number7 : " << *p_number7 << std::endl;
    delete p_number7;
    p_number7 = nullptr;

    if (p_number7 != nullptr) {
        std::cout << "*p_number7 : " << *p_number7 << std::endl;
    } else {
        std::cout << "Invalid memory access!" << std::endl;
    }

    // Oplossing 3: één master pointer beheert het geheugen
    int* p_number8 {new int{382}};   // master pointer
    int* p_number9 {p_number8};      // wijst naar hetzelfde geheugen

    if (p_number8 != nullptr) {      // altijd controleren via de master
        std::cout << "p_number9 - " << *p_number9 << std::endl;
    }

    delete p_number8;                // alleen de master geeft vrij
    p_number8 = nullptr;

    if (p_number8 != nullptr) {
        std::cout << "p_number9 - " << *p_number9 << std::endl;
    } else {
        std::cout << "WARNING : Trying to use an invalid pointer" << std::endl;
    }

    delete p_number6;
    p_number6 = nullptr;
    std::cout << "Program is ending well" << std::endl;
    return 0;
}
```

```text
*p_number6 : 87
Invalid address
*p_number7 : 82
Invalid memory access!
p_number9 - 382
WARNING : Trying to use an invalid pointer
Program is ending well
```

#### new laten falen (crash) [▶ 11:28:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41293s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: put de heap uit zonder afhandeling, programma crasht (en lekt geheugen)
#include <iostream>

int main() {
    // int* data = new int[10000000000000];   // in één keer: te groot

    for (size_t i {0}; i < 100000000; ++i) {
        int* data = new int[100000000];       // lekt elke iteratie 400 MB
        (void)data;
    }
    std::cout << "Program ending well" << std::endl;
    return 0;
}
```

#### new afhandelen met try/catch [▶ 11:31:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41487s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. De loop is vervangen door één allocatie die gegarandeerd faalt, zodat het voorbeeld snel en voorspelbaar is.

```cpp
#include <exception>
#include <iostream>

int main() {
    size_t huge_count {10'000'000'000'000};   // ±40 TB aan ints

    try {
        int* data = new int[huge_count];      // dit kan mislukken
        std::cout << "Data allocated" << std::endl;
        delete[] data;
    } catch (std::exception& ex) {
        std::cout << "Something went wrong : " << ex.what() << std::endl;
    }

    std::cout << "Program ending well" << std::endl;
    return 0;
}
```

```text
Something went wrong : std::bad_alloc
Program ending well
```

#### new afhandelen met std::nothrow [▶ 11:35:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=41726s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Ook hier één gegarandeerd falende allocatie in plaats van de loop.

```cpp
#include <iostream>
#include <new>

int main() {
    size_t huge_count {10'000'000'000'000};

    int* data = new (std::nothrow) int[huge_count];   // geeft nullptr bij falen
    if (data != nullptr) {
        std::cout << "Data allocated" << std::endl;
        delete[] data;
    } else {
        std::cout << "Data allocation failed" << std::endl;
    }

    std::cout << "Program ending well" << std::endl;
    return 0;
}
```

```text
Data allocation failed
Program ending well
```

#### Null pointer safety [▶ 11:40:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42018s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    // Uitgebreide controle
    int* p_number {};   // nullptr
    if (!(p_number == nullptr)) {
        std::cout << "p_number points to a VALID address : " << p_number << std::endl;
    } else {
        std::cout << "p_number points to an INVALID address." << std::endl;
    }

    // Korte controle: pointer wordt impliciet omgezet naar bool
    int* p_number2 {new int{7}};
    if (p_number2) {
        std::cout << "*p_number2 : " << *p_number2 << std::endl;
    } else {
        std::cout << "Invalid address" << std::endl;
    }
    delete p_number2;
    p_number2 = nullptr;

    if (p_number2) {
        std::cout << "*p_number2 : " << *p_number2 << std::endl;
    } else {
        std::cout << "Invalid address" << std::endl;
    }

    // delete op nullptr is veilig, geen controle nodig
    int* p_number1 {};
    delete p_number1;
    p_number1 = nullptr;

    std::cout << "Program ending well" << std::endl;
    return 0;
}
```

```text
p_number points to an INVALID address.
*p_number2 : 7
Invalid address
Program ending well
```

#### Memory leaks [▶ 11:49:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=42595s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Dit programma lekt bewust geheugen; het compileert en draait zonder zichtbare fout.

```cpp
#include <iostream>

int main() {
    // Lek 1: pointer overschrijven
    int* p_number {new int{67}};    // heapgeheugen met 67
    int number {55};                // stack-variabele
    p_number = &number;             // 67 is nu onbereikbaar: gelekt
    std::cout << "*p_number : " << *p_number << std::endl;

    // Lek 2: dubbele allocatie
    int* p_number1 {new int{55}};
    p_number1 = new int{44};        // 55 is gelekt
    std::cout << "*p_number1 : " << *p_number1 << std::endl;
    delete p_number1;               // geeft alleen 44 vrij
    p_number1 = nullptr;

    // Lek 3: pointer in een geneste scope
    {
        int* p_number2 {new int{57}};
        std::cout << "*p_number2 : " << *p_number2 << std::endl;
        // delete p_number2;  <- hier had het gemoeten
    }
    // delete p_number2;  // compileert niet: p_number2 bestaat hier niet meer

    std::cout << "Program ending well" << std::endl;
    return 0;
}
```

```text
*p_number : 55
*p_number1 : 44
*p_number2 : 57
Program ending well
```

#### Dynamische arrays [▶ 12:00:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43218s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <new>

int main() {
    size_t size {10};   // hoeft niet const te zijn

    double* p_salaries {new double[size]};                     // junkwaarden
    int* p_students {new (std::nothrow) int[size]{}};          // allemaal 0
    double* p_scores {new (std::nothrow) double[size]{1, 2, 3, 4, 5}};  // rest 0

    if (p_scores) {
        std::cout << "Size of scores (it's a regular pointer) : " << sizeof(p_scores) << std::endl;
        std::cout << "Successfully allocated memory for scores." << std::endl;

        // Index-notatie
        for (size_t i {}; i < size; ++i) {
            std::cout << "value : " << p_scores[i] << " : " << *(p_scores + i) << std::endl;
        }
    }

    // Vrijgeven met delete[] en resetten
    delete[] p_salaries;
    p_salaries = nullptr;
    delete[] p_students;
    p_students = nullptr;
    delete[] p_scores;
    p_scores = nullptr;
    // nocheck-output (sizeof van een pointer hangt af van het platform)
    return 0;
}
```

Voorbeeldoutput (64-bit systeem):

```text
Size of scores (it's a regular pointer) : 8
Successfully allocated memory for scores.
value : 1 : 1
value : 2 : 2
value : 3 : 3
value : 4 : 4
value : 5 : 5
value : 0 : 0
value : 0 : 0
value : 0 : 0
value : 0 : 0
value : 0 : 0
```

#### Statische versus dynamische arrays [▶ 12:05:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43503s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <iterator>

int main() {
    // Statische array: leeft op de stack
    int scores[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "scores size : " << std::size(scores) << std::endl;
    for (auto score : scores) {
        std::cout << "value : " << score << std::endl;
    }

    std::cout << "-------------" << std::endl;

    // Dynamische array: leeft op de heap, grootte zelf bijhouden
    size_t size {10};
    int* p_scores1 {new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    // std::size(p_scores1);           // compilerfout: pointer, geen array
    // for (auto s : p_scores1) {}     // compilerfout
    for (size_t i {}; i < size; ++i) {
        std::cout << "value : " << p_scores1[i] << std::endl;
    }
    delete[] p_scores1;
    p_scores1 = nullptr;
    return 0;
}
```

```text
scores size : 10
value : 1
value : 2
value : 3
value : 4
value : 5
value : 6
value : 7
value : 8
value : 9
value : 10
-------------
value : 1
value : 2
value : 3
value : 4
value : 5
value : 6
value : 7
value : 8
value : 9
value : 10
```

#### std::size en range-based for op een dynamische array [▶ 12:07:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43651s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: std::size en range-based for werken niet op een pointer
#include <iostream>
#include <iterator>

int main() {
    int* p_scores1 {new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    std::cout << "p_scores1 size : " << std::size(p_scores1) << std::endl;
    for (auto score : p_scores1) {
        std::cout << "value : " << score << std::endl;
    }
    delete[] p_scores1;
    return 0;
}
```

### Valkuilen & veelgemaakte fouten

#### Meerdere declaraties op één regel
`int* a {}, b {};` maakt alleen `a` een pointer; `b` is een gewone `int`. Zet elke pointerdeclaratie op een eigen regel.

#### Pointers van verschillende types door elkaar toewijzen
Een `int*` kan geen adres van een `double` bevatten: compilerfout. Het type van de pointer moet overeenkomen met het type van de variabele.

#### Niet-geïnitialiseerde pointer gebruiken
Een pointer zonder initializer bevat een junkadres. Schrijven of lezen via die pointer is undefined behavior: crash of beschadigde data, en de rest van het programma (ook opruimcode) wordt niet uitgevoerd.

#### nullptr dereferencen
`*p = 33;` terwijl `p == nullptr` is undefined behavior. Controleer altijd eerst met `if (p)` of `if (p != nullptr)`.

#### `char*` naar een string literal
Een string literal is een array van `const char`. `char* p {"..."};` wordt door moderne compilers geweigerd en wijzigen via de pointer kan crashen. Gebruik `const char*`, of een `char`-array als je wilt wijzigen.

#### Een `char*` dereferencen in plaats van printen
`std::cout << p_message` print de hele string, `std::cout << *p_message` slechts het eerste teken.

#### Geheugen gebruiken na `delete`
Na `delete` is het geheugen niet meer van jou. Het programma lijkt soms gewoon te werken, maar dat is geen garantie: het gedrag kan per run verschillen.

#### Twee keer `delete`
Hetzelfde geheugen twee keer vrijgeven laat het programma afbreken. Dit gebeurt vooral als meerdere pointers naar hetzelfde geheugen wijzen.

#### Meerdere pointers naar hetzelfde geheugen
Na `delete` via de ene pointer wijst de andere nog steeds naar vrijgegeven geheugen. Spreek een master pointer af die als enige vrijgeeft.

#### Memory leaks
De pointer overschrijven, opnieuw `new` op dezelfde pointer doen zonder eerst `delete`, of een scope verlaten waarin de enige pointer leefde: het geheugen is dan onbereikbaar. De compiler waarschuwt hier niet voor.

#### `delete` in plaats van `delete[]`
Geheugen dat met `new[]` aangevraagd is, geef je vrij met `delete[]`.

> 💡 Aanvulling: `delete` gebruiken op een array die met `new[]` gealloceerd is (of omgekeerd) is undefined behavior.

#### `std::size` en range-based `for` op een dynamische array
Een dynamische array is via een pointer bereikbaar en weet zijn eigen grootte niet. Beide geven een compilerfout. Houd de grootte zelf bij.

#### Niet controleren of `new` slaagt
Zeldzaam, maar zonder `try`/`catch` of `std::nothrow` crasht het programma als de heap op is.

### Best practices

- Initialiseer pointers **altijd**: met `nullptr` (of `{}`) als je nog geen adres hebt, anders met een geldig adres of met `new`.
- Zet een pointer direct na `delete` op `nullptr`, ook als het programma daarna eindigt: maak er een gewoonte van.
- Controleer pointers vóór gebruik op `nullptr`; de korte vorm `if (p)` is prima.
- Controleer **niet** op `nullptr` vóór `delete`: `delete nullptr` is veilig.
- Declareer elke pointer op een eigen regel; de docent zet de ster het liefst links (`int* p`).
- Gebruik `const char*` voor strings die je niet wilt wijzigen, en een `char`-array voor strings die je wel wilt wijzigen.
- Elke `new` hoort bij precies één `delete`, en elke `new[]` bij precies één `delete[]`.
- Wijzen meerdere pointers naar hetzelfde geheugen, laat dan één master pointer het geheugen beheren en vrijgeven.
- Geef heapgeheugen vrij in de scope waar je de pointer nog hebt.
- Handel een mogelijk falende `new` af met `try`/`catch` of `std::nothrow` als dat voor je programma belangrijk is.
- Houd bij dynamische arrays de grootte zelf bij in een variabele en gebruik een gewone `for`-loop met index.

> 💡 Aanvulling: in modern C++ gebruik je voor eigendom van heapgeheugen bij voorkeur `std::unique_ptr`/`std::shared_ptr` en voor dynamische arrays `std::vector`. Die geven het geheugen automatisch vrij en voorkomen de meeste valkuilen van dit hoofdstuk. De cursus gebruikt hier bewust "raw" pointers om te laten zien hoe het werkt.

### Samenvatting

- Een pointer is een variabele die het **adres** van een andere variabele opslaat; `T*` is "pointer naar `T`", `&x` geeft het adres van `x`, en `*p` dereferencet.
- Initialiseer met `{}`/`nullptr`; alle pointers op één systeem zijn even groot (8 bytes op 64-bit); `int*` en `double*` mag je niet door elkaar toewijzen.
- `int* a, b;` maakt alleen `a` een pointer.
- Een string literal is een `const char`-array; gebruik `const char*`. `std::cout` print bij een `char*` de hele string, `*p` geeft alleen het eerste teken. Wil je wijzigen, gebruik een `char`-array.
- Elk proces ziet via virtueel geheugen een eigen **memory map** (text, data, heap, stack); de MMU vertaalt naar het echte RAM.
- Op de **stack** bepaalt de scope de levensduur; op de **heap** bepaal jij die met `new` en `delete`.
- Dangling pointers (niet geïnitialiseerd, verwijderd, meerdere pointers naar hetzelfde geheugen) voorkom je door altijd te initialiseren, na `delete` op `nullptr` te zetten en een master pointer te gebruiken.
- `new` kan falen: vang het op met `try`/`catch (std::exception& ex)` of gebruik `new(std::nothrow)` en controleer op `nullptr`.
- `delete` op `nullptr` is veilig; memory leaks ontstaan als je de enige pointer naar heapgeheugen kwijtraakt.
- Dynamische arrays: `new T[n]` (n hoeft niet `const` te zijn), vrijgeven met `delete[]`; geen `std::size`, geen range-based `for`.

### Oefeningen

1. Declareer een `int` met waarde 10 en een `int*` die ernaar wijst. Verhoog de waarde via de pointer met 5 en print daarna zowel de variabele als `*p`.
2. Maak een `const char*` naar `"Pointers"` en een `char`-array met dezelfde tekst. Print van de pointer de hele string en het eerste teken. Verander in de array het eerste teken in `'p'` en print de array.
3. Alloceer met `new` een `int` met waarde 100 op de heap. Laat een tweede pointer naar hetzelfde geheugen wijzen. Gebruik de eerste als master pointer: geef het geheugen vrij via de master, zet die op `nullptr` en laat de tweede pointer daarna alleen nog lezen als de master niet `nullptr` is (anders een melding printen).
4. Vraag de gebruiker hoeveel getallen hij wil invoeren, maak een dynamische array van die grootte, lees de getallen in, en print de som en het gemiddelde. Geef het geheugen netjes vrij. (Invoer: `4` en daarna `2 4 6 8`.)
5. Schrijf een programma dat met `new(std::nothrow)` eerst een array van 5 `int`s en daarna een onmogelijk grote array (bijvoorbeeld 10 000 000 000 000 `int`s) probeert te alloceren. Print voor elke poging of het gelukt is, en geef het gelukte geheugen weer vrij.

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

int main() {
    int value {10};
    int* p_value {&value};
    *p_value += 5;   // wijzigt value via de pointer
    std::cout << "value : " << value << std::endl;
    std::cout << "*p_value : " << *p_value << std::endl;
    return 0;
}
```

```text
value : 15
*p_value : 15
```

Oefening 2:

```cpp
#include <iostream>

int main() {
    const char* p_text {"Pointers"};
    char text[] {"Pointers"};

    std::cout << p_text << std::endl;    // hele string
    std::cout << *p_text << std::endl;   // eerste teken

    text[0] = 'p';                       // mag: het is een array
    std::cout << text << std::endl;
    return 0;
}
```

```text
Pointers
P
pointers
```

Oefening 3:

```cpp
#include <iostream>

int main() {
    int* p_master {new int{100}};
    int* p_other {p_master};

    if (p_master) {
        std::cout << "p_other reads : " << *p_other << std::endl;
    }

    delete p_master;     // alleen de master geeft vrij
    p_master = nullptr;

    if (p_master) {
        std::cout << "p_other reads : " << *p_other << std::endl;
    } else {
        std::cout << "Memory released, not using p_other" << std::endl;
    }
    return 0;
}
```

```text
p_other reads : 100
Memory released, not using p_other
```

Oefening 4 (invoer: `4`, daarna `2 4 6 8`):

```cpp
// stdin: 4\n2 4 6 8
#include <iostream>

int main() {
    size_t count {};
    std::cout << "How many numbers? ";
    std::cin >> count;

    double* p_numbers {new double[count] {}};
    for (size_t i {}; i < count; ++i) {
        std::cin >> p_numbers[i];
    }

    double sum {};
    for (size_t i {}; i < count; ++i) {
        sum += p_numbers[i];
    }
    std::cout << std::endl;
    std::cout << "Sum : " << sum << std::endl;
    std::cout << "Average : " << sum / static_cast<double>(count) << std::endl;

    delete[] p_numbers;
    p_numbers = nullptr;
    return 0;
}
```

```text
How many numbers? 
Sum : 20
Average : 5
```

Oefening 5:

```cpp
#include <iostream>
#include <new>

int main() {
    size_t small {5};
    size_t huge {10'000'000'000'000};

    int* p_small {new (std::nothrow) int[small] {}};
    std::cout << "Small allocation : " << (p_small ? "succeeded" : "failed") << std::endl;

    int* p_huge {new (std::nothrow) int[huge]};
    std::cout << "Huge allocation : " << (p_huge ? "succeeded" : "failed") << std::endl;

    delete[] p_small;   // delete[] op nullptr zou ook veilig zijn
    p_small = nullptr;
    delete[] p_huge;
    p_huge = nullptr;
    return 0;
}
```

```text
Small allocation : succeeded
Huge allocation : failed
```

</details>

---

<a id="h09"></a>

## Hoofdstuk 9 – References (12:11:04 – 12:44:29) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43864s)

### Leerdoelen

Na dit hoofdstuk kun je:

- uitleggen wat een reference is: een **alias** (tweede naam) voor een bestaande variabele;
- een reference declareren en initialiseren met de syntax `type& naam{variabele};`;
- aantonen dat een reference en de originele variabele dezelfde waarde, hetzelfde adres en dezelfde grootte hebben;
- data wijzigen via de originele variabele of via de reference, en begrijpen waarom beide kanten de wijziging zien;
- de verschillen tussen pointers en references benoemen (dereferencing, opnieuw laten verwijzen, verplichte initialisatie);
- uitleggen waarom `ref = andereVariabele;` een **toekenning van een waarde** is en géén nieuwe binding;
- een `const` reference maken en uitleggen waarop de `const` slaat;
- het gedrag van een (const) reference nabootsen met een `const`-pointer (naar `const`).

### Verband met eerdere hoofdstukken

- **Hoofdstuk 3 (Variables & data types):** references worden net als gewone variabelen met braced initialization (`{}`) geïnitialiseerd; `sizeof` gebruik je hier weer om groottes te vergelijken.
- **Hoofdstuk 8 (Pointers):** dit hoofdstuk bouwt direct voort op pointers. Je kent al de address-of operator `&`, de dereference operator `*`, `const`-pointers en pointers naar `const`. References doen grotendeels hetzelfde als pointers, maar met een eenvoudigere syntax en strengere regels.
- **Vooruitblik:** de docent benadrukt dat references vooral nuttig worden bij **functies** (hoofdstuk 11: pass by reference) en verderop in de cursus: je geeft data door zonder kopieën te maken.

### Uitleg

#### Wat is een reference?

Een reference is een **alias**: een andere naam voor een variabele die al bestaat. Je gebruikt de reference precies zoals je de originele variabele zou gebruiken. Er wordt geen nieuwe kopie van de data gemaakt; beide namen verwijzen naar **dezelfde plek in het geheugen**.

Waarom bestaat dit? Met pointers kon je al via een omweg bij een variabele komen, maar daarvoor moet je steeds dereferencen met `*` en loop je risico's (niet-geïnitialiseerde pointers, pointers die ergens anders heen wijzen). Een reference geeft je dezelfde mogelijkheid "werken op het origineel, zonder kopie", maar met de syntax van een gewone variabele. Dat wordt later vooral handig als je data aan functies doorgeeft.

[▶ 12:11:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43895s)

#### Declareren en initialiseren van references

De syntax is eenvoudig: je zet een `&` achter het type, geeft de reference een naam, en initialiseert die met de variabele waarnaar de reference moet verwijzen.

```
int int_data{33};
int& ref_int_data{int_data};        // braced initialization
double double_data{55};
double& ref_double_data = double_data; // assignment-stijl initialisatie
```

Beide vormen van initialisatie (met `{}` of met `=`) zijn geldig. Let op: de `&` in een **declaratie** betekent "reference naar". Dezelfde `&` vóór een bestaande variabele in een **expressie** (`&int_data`) is de address-of operator uit hoofdstuk 8. Dezelfde tekens, een andere betekenis afhankelijk van de context.

[▶ 12:12:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=43944s)

#### Een reference gedraagt zich als het origineel

De docent print de waarde **en het adres** van de originele variabelen en van de references. Resultaat:

- de waarden zijn gelijk;
- de **adressen zijn identiek**: `&ref_int_data` geeft hetzelfde adres als `&int_data`;
- ook `sizeof` geeft dezelfde grootte (bv. 4 voor `int`, 8 voor `double` bij GCC op x86-64).

Onder de motorkap: de reference is geen apart object met eigen geheugen dat je kunt aanspreken; alles wat je via de reference doet, gebeurt rechtstreeks op het originele object. Daarom zegt de docent dat de twee namen "vrijwel precies hetzelfde ding" zijn.

[▶ 12:14:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44087s)

#### Wijzigingen werken in beide richtingen

- Wijzig je de **originele variabele** (`int_data = 111;`), dan ziet de reference de nieuwe waarde.
- Wijzig je via de **reference** (`ref_int_data = 1012;`), dan verandert de originele variabele mee.

Dat is logisch: er is maar één geheugenlocatie. Hierdoor kun je data "doorgeven" zonder kopieën: wie de reference krijgt, werkt op dezelfde data.

[▶ 12:18:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44328s) · [▶ 12:20:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44422s)

#### Pointers versus references: de verschillen

De docent zet de drie belangrijkste verschillen op een rij:

| | Reference | Pointer |
|---|---|---|
| Toegang tot de waarde | direct via de naam, geen `*` nodig | moet dereferencen met `*` |
| Later naar iets anders laten verwijzen | **kan niet** | kan (als de pointer zelf niet `const` is) |
| Initialisatie bij declaratie | **verplicht** (anders compilerfout) | niet verplicht (maar dan bevat hij een junk-adres) |

**1. Geen dereferencing.** Lezen en schrijven via een reference ziet eruit alsof je de originele variabele gebruikt: `ref_double_value = 16.8;`. Via een pointer moet je `*p_double_value = 15.44;` schrijven. Vergeet je de `*`, dan werk je met het **adres** dat in de pointer staat in plaats van met de waarde. Veel mensen vinden de pointer-syntax daarom minder leesbaar en kiezen voor references; pointers blijven volgens de docent wel belangrijk voor later in de cursus.

[▶ 12:22:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44565s) · [▶ 12:27:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44850s)

**2. Een reference kan niet opnieuw gebonden worden.** Schrijf je

```
ref_double_value = some_other_double_value;
```

dan verwijst `ref_double_value` daarna **niet** naar `some_other_double_value`. Wat er gebeurt: de **waarde** van `some_other_double_value` wordt gekopieerd naar de variabele waar de reference al naar verwees (`double_value`). Het adres van de reference blijft hetzelfde. In de demo ziet de docent de waarde 78.45 verschijnen, maar het adres verandert niet.

Een pointer kan je wél laten wijzen naar iets anders: `p_double_value = &some_other_double_value;`. Wijzig je daarna `*p_double_value`, dan verandert `some_other_double_value` en blijft `double_value` ongemoeid; de pointer en de originele variabele "leven" dan op verschillende adressen.

In dit opzicht kun je een reference vergelijken met een **const-pointer** (`double* const`): ook die kan niet naar iets anders wijzen; een poging daartoe geeft een compilerfout.

[▶ 12:25:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44755s) · [▶ 12:29:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44992s) · [▶ 12:33:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45238s)

**3. Een reference moet bij declaratie geïnitialiseerd worden.** Omdat je een reference later niet meer kunt laten verwijzen naar iets anders, is de declaratie de **enige kans** om hem te binden. Een reference zonder initialisatie zou nutteloos zijn, dus de compiler weigert het:

- `double& ref_double_value;` → GCC: *`'ref_double_value' declared as reference but not initialized`*; de VS Code-extensie meldt *"reference variable ... requires an initializer"*.
- `double& ref_double_value{};` (lege initializer) → VS Code meldt *"initial value of reference to non-const must be an lvalue"*: een niet-`const` reference moet aan een bestaand object (een lvalue) gebonden worden.

Een pointer mag je wel zonder initialisatie declareren, maar dan bevat hij een willekeurig adres en is gebruik ervan vragen om problemen (zie hoofdstuk 8).

[▶ 12:31:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45095s)

#### Const references

Een gewone (niet-`const`) reference kun je gebruiken om het origineel te wijzigen, bv. `++ref_age;` maakt van `age` 28. Wil je een alias die **alleen-lezen** is, dan maak je een const reference:

```
const int& ref_age{age};
```

Via `ref_age` kun je `age` nu lezen, maar niet wijzigen. `++ref_age;` geeft een compilerfout, bij GCC: *`increment of read-only reference 'ref_age'`*.

Belangrijk punt van de docent: **de `const` slaat op de naam van de reference, niet op de originele variabele.** `age` zelf mag gewoon een niet-`const` `int` zijn (en je kunt `age` dan nog steeds direct wijzigen), of het mag een `const int` zijn: in beide gevallen is het wijzigen via `ref_age` verboden.

[▶ 12:37:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45435s) · [▶ 12:39:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45582s)

#### Geen `const int& const`

Een vorm als `const int& const ref_age{age};` bestaat niet en geeft een compilerfout. Een reference kan sowieso nooit opnieuw gebonden worden, dus een tweede `const` (zoals bij pointers) heeft geen betekenis. GCC meldt: *`'const' qualifiers cannot be applied to 'const int&'`*.

[▶ 12:38:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45533s)

#### References nabootsen met pointers

Je kunt het gedrag van een const reference nabootsen met een **const pointer naar const**:

```
const int* const p_age{&age};
```

- de eerste `const` (vóór `*`): je kunt via de pointer de waarde niet wijzigen (zoals een const reference);
- de tweede `const` (na `*`): de pointer kan niet naar iets anders wijzen (zoals elke reference).

Probeer je `*p_age = 45;` of `++(*p_age);`, dan krijg je bij GCC *`assignment of read-only location '*(const int*)p_age'`*. Voor een gewone, niet-`const` reference is de tegenhanger `int* const`.

[▶ 12:42:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45724s) · [▶ 12:43:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45820s)

### Codevoorbeelden

#### Declareren en gebruiken van references [▶ 12:14:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44087s)

De docent print in de opname ook de echte adressen; die verschillen per run. Dit programma print ze wel, dus de output is voorbeeldoutput.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

int main() {
    int int_data{33};
    double double_data{55};

    // References: aliassen voor de bestaande variabelen
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    // Lezen via de originele variabelen
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    // Lezen via de references: zelfde waarden EN zelfde adressen
    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

    return 0;
}
```

```text
voorbeeldoutput:
int_data : 33
&int_data : 0x5ffe94
double_data : 55
&double_data : 0x5ffe88
=======================
ref_int_data : 33
&ref_int_data : 0x5ffe94
ref_double_data : 55
&ref_double_data : 0x5ffe88
```

#### Adressen en groottes vergelijken (controleerbaar) [▶ 12:17:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44230s)

> 💡 Aanvulling: in plaats van adressen te printen, vergelijken we ze hier met `==`. Zo is de output elke run hetzelfde. `sizeof(int)` = 4 en `sizeof(double)` = 8 gelden voor GCC op Windows/Linux x86-64.

```cpp
#include <iostream>

int main() {
    int int_data{33};
    double double_data{55};
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    std::cout << std::boolalpha;
    std::cout << "Zelfde adres (int)    : " << (&int_data == &ref_int_data) << std::endl;
    std::cout << "Zelfde adres (double) : " << (&double_data == &ref_double_data) << std::endl;
    std::cout << "sizeof(int_data)        : " << sizeof(int_data) << std::endl;
    std::cout << "sizeof(ref_int_data)    : " << sizeof(ref_int_data) << std::endl;
    std::cout << "sizeof(double_data)     : " << sizeof(double_data) << std::endl;
    std::cout << "sizeof(ref_double_data) : " << sizeof(ref_double_data) << std::endl;
    return 0;
}
```

```text
Zelfde adres (int)    : true
Zelfde adres (double) : true
sizeof(int_data)        : 4
sizeof(ref_int_data)    : 4
sizeof(double_data)     : 8
sizeof(ref_double_data) : 8
```

#### Wijzigen via origineel en via reference [▶ 12:18:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44328s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int int_data{33};
    double double_data{55};
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    std::cout << "int_data : " << int_data << ", ref_int_data : " << ref_int_data << std::endl;
    std::cout << "double_data : " << double_data << ", ref_double_data : " << ref_double_data << std::endl;
    std::cout << std::endl;

    // Wijzigen via de originele variabelen
    int_data = 111;
    double_data = 67.2;
    std::cout << "Na wijzigen via originele variabelen:" << std::endl;
    std::cout << "int_data : " << int_data << ", ref_int_data : " << ref_int_data << std::endl;
    std::cout << "double_data : " << double_data << ", ref_double_data : " << ref_double_data << std::endl;
    std::cout << std::endl;

    // Wijzigen via de references
    ref_int_data = 1012;
    ref_double_data = 1000.45;
    std::cout << "Na wijzigen via references:" << std::endl;
    std::cout << "int_data : " << int_data << ", ref_int_data : " << ref_int_data << std::endl;
    std::cout << "double_data : " << double_data << ", ref_double_data : " << ref_double_data << std::endl;

    return 0;
}
```

```text
int_data : 33, ref_int_data : 33
double_data : 55, ref_double_data : 55

Na wijzigen via originele variabelen:
int_data : 111, ref_int_data : 111
double_data : 67.2, ref_double_data : 67.2

Na wijzigen via references:
int_data : 1012, ref_int_data : 1012
double_data : 1000.45, ref_double_data : 1000.45
```

#### Lezen en schrijven via reference en pointer [▶ 12:27:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44850s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    double double_value{12.34};
    double& ref_double_value{double_value};   // reference
    double* p_double_value{&double_value};    // pointer

    // Lezen: reference direct, pointer via dereferencing (*)
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << std::endl;

    // Schrijven via de pointer: dereferencen is nodig
    *p_double_value = 15.44;
    std::cout << "Na schrijven via pointer:" << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << std::endl;

    // Schrijven via de reference: gewoon de naam gebruiken
    ref_double_value = 16.8;
    std::cout << "Na schrijven via reference:" << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    return 0;
}
```

```text
double_value : 12.34
ref_double_value : 12.34
*p_double_value : 12.34

Na schrijven via pointer:
double_value : 15.44
ref_double_value : 15.44
*p_double_value : 15.44

Na schrijven via reference:
double_value : 16.8
ref_double_value : 16.8
*p_double_value : 16.8
```

> ⚠️ Onduidelijk in opname: de exacte nieuwe waarden die via pointer en reference geschreven worden zijn niet hoorbaar; 15.44 en 16.8 zijn gekozen als voorbeeld.

#### Een reference kan niet opnieuw gebonden worden, een pointer wel [▶ 12:29:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=44992s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Adressen worden met `==` vergeleken zodat de output vast is.

```cpp
#include <iostream>

int main() {
    double double_value{12.34};
    double& ref_double_value{double_value};
    double* p_double_value{&double_value};

    double some_other_double_value{78.45};

    // GEEN nieuwe binding: dit kopieert de WAARDE 78.45 naar double_value
    ref_double_value = some_other_double_value;

    std::cout << std::boolalpha;
    std::cout << "Na 'ref_double_value = some_other_double_value':" << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "reference nog steeds op adres van double_value : "
              << (&ref_double_value == &double_value) << std::endl;
    std::cout << std::endl;

    // Een pointer KAN wel naar iets anders wijzen
    p_double_value = &some_other_double_value;
    *p_double_value = 555.5;   // wijzigt some_other_double_value, niet double_value

    std::cout << "Na pointer naar some_other_double_value laten wijzen:" << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "some_other_double_value : " << some_other_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    std::cout << "pointer wijst nog naar double_value : "
              << (p_double_value == &double_value) << std::endl;

    return 0;
}
```

```text
Na 'ref_double_value = some_other_double_value':
double_value : 78.45
ref_double_value : 78.45
reference nog steeds op adres van double_value : true

Na pointer naar some_other_double_value laten wijzen:
double_value : 78.45
ref_double_value : 78.45
some_other_double_value : 555.5
*p_double_value : 555.5
pointer wijst nog naar double_value : false
```

#### Reference zonder initialisatie [▶ 12:31:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45095s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: reference zonder initializer geeft compilerfout
#include <iostream>

int main() {
    double& ref_double_value;   // error: 'ref_double_value' declared as reference but not initialized
    std::cout << ref_double_value << std::endl;
    return 0;
}
```

#### Non-const reference wijzigt het origineel [▶ 12:39:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45582s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int main() {
    int age{27};
    int& ref_age{age};   // niet-const reference

    std::cout << "age : " << age << std::endl;
    ++ref_age;           // wijzigt age via de reference
    std::cout << "age : " << age << std::endl;
    return 0;
}
```

```text
age : 27
age : 28
```

#### Const reference: wijzigen is verboden [▶ 12:40:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45630s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: wijzigen via een const reference
#include <iostream>

int main() {
    int age{27};
    const int& ref_age{age};

    std::cout << "age : " << age << std::endl;
    ++ref_age;   // error: increment of read-only reference 'ref_age'
    std::cout << "age : " << age << std::endl;
    return 0;
}
```

Lezen via een const reference mag wel, en de originele (niet-`const`) variabele blijft gewoon wijzigbaar. De `const` slaat alleen op de naam `ref_age`:

```cpp
#include <iostream>

int main() {
    int age{27};
    const int& ref_age{age};      // read-only alias

    std::cout << "ref_age : " << ref_age << std::endl;
    age = 30;                     // direct via age mag wel
    std::cout << "ref_age : " << ref_age << std::endl;

    const int fixed_age{40};      // ook een const variabele kan gebonden worden
    const int& ref_fixed_age{fixed_age};
    std::cout << "ref_fixed_age : " << ref_fixed_age << std::endl;
    return 0;
}
```

```text
ref_age : 27
ref_age : 30
ref_fixed_age : 40
```

#### `const int& const` bestaat niet [▶ 12:38:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45533s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: een reference kan geen tweede const krijgen
#include <iostream>

int main() {
    int age{27};
    const int& const ref_age{age};   // error: 'const' qualifiers cannot be applied to 'const int&'
    std::cout << ref_age << std::endl;
    return 0;
}
```

#### Reference-gedrag nabootsen met een const pointer naar const [▶ 12:42:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45773s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: wijzigen via een const pointer naar const
#include <iostream>

int main() {
    int age{27};

    // Simuleer reference-gedrag met pointers
    const int* const p_age{&age};

    std::cout << "*p_age : " << *p_age << std::endl;
    *p_age = 45;   // error: assignment of read-only location '*(const int*)p_age'
    return 0;
}
```

Lezen via deze pointer werkt wel; alleen schrijven en "opnieuw laten wijzen" zijn verboden:

```cpp
#include <iostream>

int main() {
    int age{27};
    const int* const p_age{&age};   // kan niet wijzigen, kan niet herwijzen
    const int& ref_age{age};        // zelfde gedrag, eenvoudigere syntax

    std::cout << "*p_age : " << *p_age << std::endl;
    std::cout << "ref_age : " << ref_age << std::endl;

    age = 45;   // het origineel zelf mag wel wijzigen
    std::cout << "*p_age : " << *p_age << std::endl;
    std::cout << "ref_age : " << ref_age << std::endl;
    return 0;
}
```

```text
*p_age : 27
ref_age : 27
*p_age : 45
ref_age : 45
```

### Valkuilen & veelgemaakte fouten

#### Denken dat `ref = andere;` de reference opnieuw bindt
`ref_double_value = some_other_double_value;` kopieert alleen de waarde naar het object waar de reference al naar verwees. Het origineel krijgt dus een nieuwe waarde; de reference blijft op hetzelfde adres. Wil je echt naar iets anders kunnen wijzen, gebruik dan een pointer.

#### Reference declareren zonder initialisatie
`int& r;` is een compilerfout. De declaratie is de enige kans om een reference te binden.

#### Een niet-const reference aan een letterlijke waarde binden
`int& r{33};` werkt niet: een niet-`const` reference moet aan een lvalue (een bestaande variabele) gebonden worden ("initial value of reference to non-const must be an lvalue").

> 💡 Aanvulling: een `const int& r{33};` is wel toegestaan; de compiler maakt dan een tijdelijk object waarvan de levensduur verlengd wordt. De docent behandelt dit hier niet.

#### `&` in declaratie verwarren met address-of
In `int& r{x};` betekent `&` "reference naar". In `std::cout << &x;` is het de address-of operator. Zelfde teken, andere betekenis.

#### `*` vergeten bij een pointer
`std::cout << p_double_value;` print het adres, niet de waarde. Bij een reference speelt dit probleem niet.

#### Denken dat `const` op de originele variabele slaat
`const int& ref_age{age};` maakt `age` niet `const`. Je kunt `age` nog steeds direct wijzigen; alleen via `ref_age` mag het niet.

#### `const int& const` schrijven
Bestaat niet; een reference is al "niet herbindbaar". Gebruik gewoon `const int&`.

### Best practices

- Gebruik references wanneer je een alias nodig hebt die altijd naar hetzelfde object verwijst; de syntax is leesbaarder dan pointers.
- Initialiseer references direct bij de declaratie, bij voorkeur met braced initialization (`int& r{x};`).
- Maak een reference `const` als je via die naam alleen wilt lezen; zo voorkomt de compiler onbedoelde wijzigingen.
- Gebruik een pointer als het doel moet kunnen veranderen (herwijzen) of als "naar niets wijzen" (`nullptr`) mogelijk moet zijn.
- Geef references een herkenbare naam (zoals de docent met `ref_`-voorvoegsel) zodat duidelijk is dat wijzigingen het origineel raken.
- Wil je pointer-gedrag dat lijkt op een reference: `int* const` (≈ `int&`) en `const int* const` (≈ `const int&`).

### Samenvatting

- Een reference is een alias voor een bestaande variabele: `type& naam{variabele};`.
- Reference en origineel hebben dezelfde waarde, hetzelfde adres en dezelfde `sizeof`; er wordt niets gekopieerd.
- Wijzigingen via de reference zijn zichtbaar in het origineel en omgekeerd.
- Een reference gebruik je zonder `*`; een pointer moet je dereferencen.
- Een reference kan na de declaratie niet naar iets anders verwijzen; `ref = x;` kopieert alleen de waarde van `x`.
- Een reference moet bij declaratie geïnitialiseerd worden, anders compilerfout.
- In dat opzicht lijkt een reference op een const pointer (`T* const`).
- `const T& ref{x};` maakt een read-only alias; de `const` slaat op de reference-naam, niet op `x`.
- `const T& const` bestaat niet; een const reference boots je na met `const T* const`.

### Oefeningen

1. Declareer een `int score{10};` en een reference `ref_score` ernaar. Verhoog de score drie keer via de reference met 5 en print daarna `score`.
2. Maak een `double temperature{21.5};`, een reference en een pointer ernaar. Zet via de pointer de waarde op 18.0 en via de reference op 25.25; print na elke stap de waarde via alle drie de namen.
3. Schrijf een programma met `int a{1}; int b{2}; int& r{a};`. Voer `r = b;` uit en daarna `b = 100;`. Voorspel de waarden van `a`, `b` en `r` en controleer met een print. Print ook (met `std::boolalpha`) of `&r == &a`.
4. Maak een `int level{3};` en zowel een `const int& ref_level{level};` als een `const int* const p_level{&level};`. Verhoog `level` direct naar 4 en print de waarde via beide. Leg in commentaar uit waarom `++ref_level;` en `++(*p_level);` niet zouden compileren.

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

int main() {
    int score{10};
    int& ref_score{score};

    ref_score += 5;
    ref_score += 5;
    ref_score += 5;

    std::cout << "score : " << score << std::endl;
    return 0;
}
```

```text
score : 25
```

Oefening 2:

```cpp
#include <iostream>

int main() {
    double temperature{21.5};
    double& ref_temperature{temperature};
    double* p_temperature{&temperature};

    std::cout << temperature << " " << ref_temperature << " " << *p_temperature << std::endl;

    *p_temperature = 18.0;   // via pointer: dereferencen
    std::cout << temperature << " " << ref_temperature << " " << *p_temperature << std::endl;

    ref_temperature = 25.25; // via reference: direct
    std::cout << temperature << " " << ref_temperature << " " << *p_temperature << std::endl;
    return 0;
}
```

```text
21.5 21.5 21.5
18 18 18
25.25 25.25 25.25
```

Oefening 3:

```cpp
#include <iostream>

int main() {
    int a{1};
    int b{2};
    int& r{a};

    r = b;     // kopieert de waarde 2 naar a; r blijft aan a gebonden
    b = 100;   // raakt a en r niet

    std::cout << std::boolalpha;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "r : " << r << std::endl;
    std::cout << "&r == &a : " << (&r == &a) << std::endl;
    return 0;
}
```

```text
a : 2
b : 100
r : 2
&r == &a : true
```

Oefening 4:

```cpp
#include <iostream>

int main() {
    int level{3};
    const int& ref_level{level};          // read-only alias
    const int* const p_level{&level};     // read-only, niet herwijsbaar

    level = 4;   // direct wijzigen mag: level zelf is niet const

    std::cout << "ref_level : " << ref_level << std::endl;
    std::cout << "*p_level : " << *p_level << std::endl;

    // ++ref_level;   -> fout: ref_level is een const reference (read-only)
    // ++(*p_level);  -> fout: p_level wijst naar const int (read-only location)
    return 0;
}
```

```text
ref_level : 4
*p_level : 4
```

</details>

---

<a id="h10"></a>

## Hoofdstuk 10 – Character manipulation and strings (12:44:29 – 14:12:47) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45869s)

### Leerdoelen

Na dit hoofdstuk kun je:

- uitleggen waarom C-strings (character arrays met een afsluitend null-karakter) onhandig en onveilig zijn om mee te werken;
- losse karakters onderzoeken en omzetten met de functies uit `<cctype>`: `std::isalnum`, `std::isalpha`, `std::isblank`, `std::islower`, `std::isupper`, `std::isdigit`, `std::toupper` en `std::tolower`;
- de return-waarde van die functies correct interpreteren (niet-nul = waar, nul = onwaar, en dus niet per se `1`);
- C-strings bewerken met `<cstring>`: lengte bepalen (`std::strlen`), vergelijken (`std::strcmp`, `std::strncmp`), zoeken (`std::strchr`, `std::strrchr`);
- C-strings samenvoegen en kopiëren (`std::strcat`, `std::strncat`, `std::strcpy`, `std::strncpy`) en weten waar het gevaar zit (te kleine bestemming, ontbrekende null-terminator);
- het verschil tussen `strlen` en `sizeof` uitleggen, ook bij een array die tot pointer is "vervallen" (decay);
- `std::string` declareren en initialiseren op de verschillende manieren die de docent laat zien, en begrijpen waarom `std::string` vanzelf kan groeien.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 3 (data types):** `char` is een klein integer type dat een karakter voorstelt. Alles in dit hoofdstuk bouwt daarop.
- **Hoofdstuk 4 (operations on data):** `static_cast` om een `int`-resultaat naar `bool` om te zetten.
- **Hoofdstuk 6 (loops):** gewone `for`-loops met `std::size`, range based `for`-loops en `while`-loops komen hier voortdurend terug.
- **Hoofdstuk 7 (arrays):** een C-string *is* een character array met een `'\0'` aan het eind. `std::size` werkt alleen op echte (statische) arrays.
- **Hoofdstuk 8 (pointers):** `const char*` naar een string literal, array decay naar pointer, pointer-arithmetiek (`++result`), `nullptr` als "niet gevonden", en dynamische arrays met `new[]`/`delete[]`.
- **Hoofdstuk 9 (references):** niet direct nodig, maar in latere hoofdstukken geef je `std::string` vaak als `const std::string&` door.

### Uitleg

#### Waarom een hoofdstuk over karakters en strings?

Tekst is overal in programma's. Tot nu toe sloegen we tekst op als **C-string**: een array van `char` waarvan het laatste element het null-karakter `'\0'` is. Met C-strings kun je veel: de lengte opvragen, strings aan elkaar plakken, kopiëren, erin zoeken. Maar de docent benadrukt meteen dat dit **niet veilig en niet handig** is:

- je moet zelf bijhouden hoe groot de array in het geheugen is;
- je moet zelf zorgen dat de string correct eindigt met `'\0'`;
- schrijf je voorbij de grenzen van de array, dan krijg je crashes of erger.

C++ biedt daarom `std::string`, een type dat bovenop een character array is gebouwd maar al die details voor je verbergt. Het hoofdstuk bouwt op: eerst losse karakters (`<cctype>`), dan C-strings (`<cstring>`), en ten slotte `std::string`.

[▶ 12:44:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45869s)

#### Karakters onderzoeken met `<cctype>`

De standaardbibliotheek bevat in de header `<cctype>` een reeks functies om één karakter te onderzoeken of om te zetten: is het alfanumeriek, alfabetisch, een spatie, een cijfer, een hoofdletter of kleine letter? De docent toont de lijst op cppreference.com en behandelt er een selectie van; de rest kun je zelf in de documentatie opzoeken.

Belangrijk is de **return-waarde**. Deze functies geven een `int` terug:

- een waarde **verschillend van nul** als de test slaagt (die je als `true` kunt behandelen);
- **nul** als de test faalt (`false`).

Er is **geen garantie dat je precies `1` krijgt**. De docent laat dat live zien: `std::isalnum('C')` geeft bij hem `1`, maar `std::isalpha('e')` geeft een andere niet-nul waarde. Gebruik de functies daarom in een voorwaarde (`if (std::isalpha(c))`) of zet het resultaat om met `static_cast<bool>(...)` als je echt `true`/`false` wilt.

De docent vermeldt nog dat het resultaat afhangt van de **C locale** (instellingen die bepalen wat een karakter betekent). Hij zegt dat we ons daar nu geen zorgen over hoeven te maken: de standaardinstellingen volstaan.

In zijn demo merkt de docent op dat de code compileert zonder `#include <cctype>`, omdat `<iostream>` het bij zijn compiler al indirect meebrengt. Hij laat de include daarom weg.

> 💡 Aanvulling: dat `<iostream>` toevallig `<cctype>` meebrengt is een implementatiedetail van je standaardbibliotheek, niet gegarandeerd door de standaard. Op een andere compiler kan je code dan ineens niet meer compileren. Zet `#include <cctype>` er dus zelf bij; in de voorbeelden hieronder doen we dat.

[▶ 12:46:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=45960s)

#### `std::isalnum` – alfanumeriek?

`std::isalnum(c)` test of `c` een letter (a–z, A–Z) of een cijfer (0–9) is. `'C'` is alfanumeriek, een teken zoals `'^'` of `'*'` niet. De docent gebruikt de functie zowel om de ruwe waarde te printen als in een `if`-test: "input_char is alphanumeric" of "is not alphanumeric".

[▶ 12:47:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46057s)

#### `std::isalpha` – alfabetisch?

`std::isalpha(c)` geeft niet-nul terug voor een letter a–z of A–Z (kleine letters en hoofdletters). Een leesteken of een cijfer zoals `'7'` geeft nul. Hier ziet de docent dat de waarde voor `'e'` geen `1` is: het enige wat gegarandeerd is, is "niet nul".

[▶ 12:50:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46202s)

#### Andere compilers proberen (MSVC)

Tussendoor bouwt de docent hetzelfde programma met de Microsoft-compiler (MSVC, via de "build with msvc"-taak in VS Code) en krijgt hij dezelfde output. Hij raadt aan je code op meerdere compilers te proberen: sommige compilers markeren functies uit de C-bibliotheek (zoals de `<cstring>`-functies verderop) als **onveilig** en geven waarschuwingen of fouten. Zo leer je die meldingen herkennen. Daarna gaat hij verder met GCC.

[▶ 12:58:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46729s)

#### `std::isblank` – spatie of tab?

`std::isblank(c)` geeft niet-nul terug voor een "blank" karakter: een spatie `' '` of een horizontale tab `'\t'`. Het voorbeeld van de docent telt de blanks in een bericht. Hij loopt met een gewone `for`-loop tot `std::size(message)` (dat kan, want `message` is een echte statische array) en print bij elke blank de index.

Een opmerking die hij maakt: de teller was eerst een `int`, maar een aantal kan nooit negatief zijn. Gebruik daarom `std::size_t` (of een ander unsigned type) voor tellers en groottes. Dat doet hij vanaf dan in alle voorbeelden.

[▶ 12:50:49](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46249s)

#### `std::islower` en `std::isupper`

Met een range based `for`-loop over een character array tel je hoeveel kleine letters (`std::islower`) en hoeveel hoofdletters (`std::isupper`) er in een tekst staan. Spaties en leestekens zijn geen van beide en worden dus niet meegeteld.

Bij het testen print de docent per ongeluk ook elk karakter dat hij als kleine letter herkent. Daardoor ziet hij een vreemde rij letters zonder hoofdletters op het scherm: dat zijn gewoon alle kleine letters achter elkaar. De bedoelde output is alleen de twee tellers.

[▶ 12:51:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46297s)

#### `std::isdigit` – cijfer?

`std::isdigit(c)` geeft niet-nul terug voor `'0'` t/m `'9'`. Het voorbeeld loopt weer over een bericht, print elk gevonden cijfer en telt ze in een `std::size_t`.

[▶ 12:52:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46345s)

#### `std::toupper` en `std::tolower` – omzetten

`std::toupper(c)` geeft de hoofdletter-variant van `c` terug; is `c` geen kleine letter, dan krijg je `c` ongewijzigd terug. `std::tolower(c)` doet het omgekeerde. Het origineel verandert **niet**: je krijgt een nieuwe waarde terug die je zelf ergens moet opslaan.

Het voorbeeld van de docent heeft een array `original_str` ("Home. The feeling of belonging") en een even grote bestemmingsarray `dest_str`. Een loop tot `std::size(original_str)` zet elk karakter om en schrijft het in `dest_str` op dezelfde index. Daarna doet hij hetzelfde met `std::tolower`, en overschrijft daarbij de bestemming.

Omdat de loop ook het laatste element (`'\0'`) meeneemt, wordt de null-terminator gewoon mee gekopieerd: `std::toupper('\0')` is `'\0'`. Daarom is `dest_str` na de loop een geldige C-string die je kunt printen.

> 💡 Aanvulling: `std::toupper` geeft een `int` terug. Bij opslaan in een `char` vindt een impliciete conversie plaats; met `static_cast<char>(...)` maak je dat expliciet. Formeel moet je ook `char`s met een negatieve waarde (bijv. niet-ASCII bytes) eerst naar `unsigned char` omzetten voordat je ze aan een `<cctype>`-functie geeft, anders is het gedrag ongedefinieerd. Voor gewone ASCII-tekst zoals in deze voorbeelden speelt dat niet.

[▶ 12:53:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46392s)

#### C-strings bewerken met `<cstring>`

In de volgende les komt de header `<cstring>` aan bod. Die stamt uit C (daar heette hij `string.h`) en bevat functies die werken op `char`-pointers naar null-terminated strings. Omdat ze een pointer krijgen, werken ze **evengoed op een echte array als op een vervallen pointer** (een `const char*` die naar een string literal wijst). Dat is een verschil met `std::size` en range based `for`-loops: die werken niet meer zodra een array tot pointer vervallen is.

[▶ 13:09:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47354s)

#### `std::strlen` versus `sizeof`

`std::strlen(str)` telt de karakters tot (niet inclusief) de eerste `'\0'`. De null-terminator die de compiler automatisch toevoegt aan een string literal telt dus **niet** mee.

`sizeof` werkt anders:

- op een **echte array** geeft `sizeof` het aantal bytes van de hele array, **inclusief** `'\0'`. Voor `const char message1[] {"The sky is blue."}` is `strlen` 16 en `sizeof` 17;
- op een **pointer** geeft `sizeof` de grootte van de pointer zelf (8 bytes op een 64-bit systeem), niet van de tekst waar hij naar wijst.

`std::strlen` werkt dus ook op pointers, `sizeof` niet (nuttig).

[▶ 13:11:39 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47499s) · [▶ 13:19:37 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47977s)

#### `std::strcmp` – twee C-strings vergelijken

`int std::strcmp(const char* lhs, const char* rhs)` vergelijkt twee C-strings **lexicografisch** (woordenboekvolgorde, karakter per karakter op basis van de karaktercode):

- **negatief** als `lhs` vóór `rhs` komt ("Alabama" vs "Blabama": `'A'` < `'B'`);
- **nul** als ze gelijk zijn;
- **positief** als `lhs` ná `rhs` komt.

De docent krijgt `-1`, `0` en `1`, maar de standaard garandeert alleen het **teken** (negatief/nul/positief), niet de exacte waarde. Hij laat zien dat het niet uitmaakt of de string via een `const char*` of in een array staat. Daarna wijst hij de pointers naar andere literals (bijv. "Alakama" en "Alabama", "India" en "France", "Kigali" en "Kigali") en vergelijkt opnieuw.

Daarbij maakt hij een belangrijk punt: een **pointer** (die niet zelf `const` is) mag je naar een andere string laten wijzen, een **array niet**. `string_data3 = "...";` met een array geeft een compilerfout.

[▶ 13:11:39 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47499s) · [▶ 13:21:12 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48072s)

#### `std::strncmp` – de eerste n karakters vergelijken

`int std::strncmp(const char* lhs, const char* rhs, std::size_t count)` werkt als `strcmp`, maar vergelijkt hoogstens `count` karakters. Vergelijk je "aaaia" en "aaance" op 3 karakters, dan zijn ze gelijk (`0`). Op 5 karakters komt `'i'` vóór `'n'` (negatief); vervang je `'i'` door `'o'`, dan komt de eerste ná de tweede (positief). De docent waarschuwt dat je `count` zinnig moet kiezen ten opzichte van de stringlengte.

[▶ 13:13:16 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47596s) · [▶ 13:27:38 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48458s)

#### `std::strchr` – eerste voorkomen van een karakter

`const char* std::strchr(const char* str, int ch)` zoekt het **eerste** voorkomen van `ch` in `str`:

- gevonden: een pointer naar dat karakter **binnen** de originele string;
- niet gevonden: `nullptr`.

Het voorbeeld (overgenomen van cppreference) zoekt alle hoofdletters `'T'` in "Try not. Do, or do not. There is no try.":

1. `result` begint gelijk aan `str`.
2. In de `while`-voorwaarde wordt `result = std::strchr(result, target)` uitgevoerd en vergeleken met `nullptr`.
3. Eerste ronde: `result` wijst naar de `T` van "Try". `std::cout << result` print vanaf daar tot de `'\0'`, dus de hele rest van de zin.
4. `++result` (pointer-arithmetiek) schuift één karakter op, naar de `r`. Zo vindt de volgende zoekactie niet nog eens dezelfde `T`.
5. Tweede ronde: vanaf de `r` vindt `strchr` de `T` van "There".
6. Derde ronde: na "There" is er geen `T` meer, `strchr` geeft `nullptr` en de loop stopt. Totaal: 2 iteraties.

De sleutel is dat het **resultaat terug in de zoekpositie** wordt gezet: daardoor springt de loop meteen naar de volgende treffer.

Waarom niet gewoon `str` zelf verschuiven? Omdat je `str` intact wilt laten: wie later naar `str` kijkt, verwacht het hele bericht. De docent maakt de pointer zelf daarom `const` (`const char* const str`). Elke poging tot `++str` geeft dan een compilerfout.

[▶ 13:14:04 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47644s) · [▶ 13:30:01 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48601s)

#### De foute variant: 25 iteraties in plaats van 2

Daarna laat de docent een versie zien die veel beginners schrijven: het resultaat van `strchr` gaat in `result`, maar in de body wordt `str` met één opgehoogd in plaats van naar `result + 1` te springen. Gevolg: zolang er *ergens verderop* nog een `T` staat, slaagt de zoekactie, en schuift de loop telkens maar één positie op. De laatste `T` staat op index 24, dus de loop draait 25 keer en print de "There..."-treffer tientallen keren. "Doe dit niet", is zijn advies.

[▶ 13:36:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48986s)

#### `std::strrchr` – laatste voorkomen van een karakter

`std::strrchr(str, ch)` (de extra `r` staat voor "reverse") geeft een pointer naar het **laatste** voorkomen van `ch`, of `nullptr`. Praktisch voorbeeld: de bestandsnaam uit een pad halen. In "/home/user/hello.cpp" zoek je de laatste `'/'`. Is het resultaat geen `nullptr`, dan print je vanaf `output + 1` (één karakter verder dan de slash), en krijg je `hello.cpp`.

> ⚠️ Onduidelijk in opname: de docent spreekt over een "backslash", maar het pad is een Linux/macOS-pad met gewone slashes (`/`). In de code hieronder zoeken we dus naar `'/'`.

[▶ 13:17:13 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47833s) · [▶ 13:39:37 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49177s)

#### `std::strcat` – C-strings samenvoegen

`char* std::strcat(char* dest, const char* src)` plakt `src` achter `dest`. Hoe dat werkt: `strcat` zoekt de `'\0'` aan het eind van `dest`, **overschrijft die** met het eerste karakter van `src`, kopieert de rest van `src` en zet aan het eind een nieuwe `'\0'`. De return-waarde is `dest`.

Twee voorwaarden waar **jij** voor moet zorgen:

1. `dest` moet **wijzigbaar** zijn. Een array van `const char` als bestemming geeft een compilerfout.
2. `dest` moet **groot genoeg** zijn voor de oude inhoud + `src` + `'\0'`. Is dat niet zo, dan schrijf je voorbij het einde van de array (buffer overflow). Dit is precies de reden waarom compilers zoals MSVC deze functies als onveilig beschouwen.

De docent laat dat laatste zien door de bestemming te verkleinen naar 3 karakters: VS Code waarschuwt, en zijn GCC-build weigert. Hij merkt op dat niet elke compiler je zo beschermt.

> 💡 Aanvulling: GCC detecteert zo'n overflow alleen als hij de groottes tijdens het compileren kent (en dan vaak als *waarschuwing*, niet altijd als fout). Bij dynamische of onbekende groottes krijg je geen enkele melding en is het gewoon undefined behavior.

Het tweede voorbeeld gebruikt **dynamische arrays** op de heap (`new char[30]{...}`) die met losse karakters en een expliciete `'\0'` zijn geïnitialiseerd. `strlen` vóór en na de concatenatie bewijst dat de lengtes netjes optellen.

[▶ 13:41:58 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49318s) · [▶ 13:49:10 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49750s) · [▶ 13:53:12 (heap-voorbeeld)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49992s)

#### `std::strncat` – hoogstens n karakters toevoegen

`char* std::strncat(char* dest, const char* src, std::size_t count)` voegt hoogstens `count` karakters van `src` toe aan `dest` en zet daarna **altijd** een `'\0'`. Met `dest = "Hello"` en `src = " There is a bird on my window"` en `count = 6` krijg je "Hello There". De docent print zowel `dest` als de teruggegeven pointer: die wijzen naar hetzelfde, dus je ziet de tekst twee keer. Hoe hij weet wat de functie teruggeeft? Uit de documentatie op cppreference: hij moedigt aan die zelf op te zoeken.

[▶ 13:45:13 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49513s) · [▶ 13:55:35 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50135s)

#### `std::strcpy` – een C-string kopiëren

`char* std::strcpy(char* dest, const char* src)` kopieert `src` inclusief `'\0'` naar `dest`, **vanaf het begin** van `dest` (wat er stond wordt overschreven). In het voorbeeld wordt de bestemming op de heap gemaakt met precies de juiste grootte: `new char[std::strlen(source3) + 1]`. De `+ 1` is nodig omdat `strlen` de null-terminator niet meetelt.

[▶ 13:46:00 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49560s) · [▶ 13:57:11 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50231s)

#### `std::strncpy` – hoogstens n karakters kopiëren

`char* std::strncpy(char* dest, const char* src, std::size_t count)` kopieert hoogstens `count` karakters. In het voorbeeld is `src` "Hello" en `dest` "abcdef"; met `count = 5` worden de eerste vijf posities van `dest` overschreven door "Hello", terwijl de `'f'` en de oorspronkelijke `'\0'` blijven staan. Resultaat: "Hellof". De docent leest de documentatie voor: kopieert *hoogstens* `count` karakters, inclusief de null-terminator *als die binnen die count valt*.

Let op wat dat betekent: als `src` minstens `count` karakters heeft, wordt er **geen** `'\0'` gekopieerd. Hier ging dat goed omdat `dest` al een terminator op de juiste plek had.

[▶ 13:47:36 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49656s) · [▶ 13:58:48 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50328s)

#### Introductie van `std::string`

Na al het werk met character arrays vat de docent de problemen samen: je moet de **grootte** in de gaten houden (buiten de grenzen schrijven kan crashen) en je moet altijd de **null-terminator** onthouden. Dat is vervelend als je alleen maar wat tekst wilt opslaan.

`std::string` is een type uit de standaardbibliotheek dat die details "onder de grond" verbergt. Intern zit er nog steeds een character array, maar `std::string` regelt zelf de grootte, het geheugen en de terminator. Je kunt er alles mee wat je met C-strings deed (samenvoegen, zoeken, kopiëren), maar dan veilig en handig. Latere lessen werken dat verder uit.

[▶ 14:01:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50476s)

#### `std::string` declareren en initialiseren

Je hebt `#include <string>` nodig. Het type heet voluit `std::string` (waarom die `std::` erbij moet, komt in een later hoofdstuk over namespaces). De manieren die de docent laat zien:

| Code | Betekenis |
|---|---|
| `std::string full_name;` | lege string |
| `std::string planet {"Earth. Where the sky is blue"};` | geïnitialiseerd met een string literal |
| `std::string preferred_planet {planet};` | kopie van een andere string |
| `std::string message {"Hello there", 5};` | de eerste 5 karakters van een literal: "Hello" |
| `std::string weird_message(4, 'e');` | 4 keer het karakter `'e'`: "eeee" |
| `std::string saying_hello {greeting, 6, 5};` | deel van een andere string: vanaf index 6, 5 karakters |

Bij `weird_message` gebruikt de docent **ronde haakjes**. Dat is geen toeval: met accolades `{4, 'e'}` zou je een string met twee karakters krijgen (code 4 en `'e'`), omdat accolades de voorkeur geven aan de initializer-list-constructor.

> 💡 Aanvulling: de docent noemt dit verschil tussen `()` en `{}` niet expliciet, maar het is een klassieke valkuil. Zie ook de valkuilen hieronder.

`std::cout` kan een `std::string` direct printen.

[▶ 14:03:40 (slides)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50620s) · [▶ 14:06:05 (demo)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50765s)

#### `std::string` groeit vanzelf

Het grote voordeel: je kunt een `std::string` tijdens runtime een **langere** waarde geven dan waarmee hij geïnitialiseerd werd. `std::string` regelt zelf het geheugen: als de oude buffer te klein is, wordt nieuw geheugen aangevraagd en het oude teruggegeven. Bij een array kan dat niet: een array heeft een vaste grootte.

De docent vergelijkt dat met een `const char*`:

```
const char* planet1 {"Earth. Where the sky is blue Earth."};
planet1 = "Earth. Where the sky is blue Earth. Earth. Where the sky is blue";
```

Dat compileert en print hetzelfde, maar wat er gebeurt is anders: de pointer wordt alleen naar een **andere** literal in het geheugen omgezet. De eerste tekst blijft ongebruikt in het geheugen staan. Bij `std::string` wordt het oude geheugen netjes vrijgegeven.

> 💡 Aanvulling: string literals staan in statisch, alleen-lezen geheugen en bestaan sowieso de hele levensduur van het programma; ze worden nooit "teruggegeven" en tellen niet als lek. De kern van het verhaal klopt wel: met een `const char*` verander je alleen waar de pointer naar wijst, met `std::string` verandert de inhoud zelf en beheert het object zijn eigen geheugen. Strikt genomen geeft `std::string` het geheugen terug aan de allocator (heap), niet direct aan het besturingssysteem.

[▶ 14:10:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51005s) · [▶ 14:11:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51100s)

### Codevoorbeelden

#### `std::isalnum`: ruwe waarde en test [▶ 12:54:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46488s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

De exacte niet-nul waarde is implementatie-afhankelijk, daarom voorbeeldoutput.

```cpp
// nocheck-output
#include <iostream>
#include <cctype>

int main() {
    // Ruwe int-waarde: niet-nul = alfanumeriek, 0 = niet
    std::cout << "C is alphanumeric : " << std::isalnum('C') << '\n';
    std::cout << "^ is alphanumeric : " << std::isalnum('^') << '\n';

    // In een test gebruiken
    char input_char {'*'};
    if (std::isalnum(input_char)) {
        std::cout << input_char << " is alphanumeric\n";
    } else {
        std::cout << input_char << " is not alphanumeric\n";
    }
    return 0;
}
```
```text
C is alphanumeric : 1
^ is alphanumeric : 0
* is not alphanumeric
```

#### `std::isalpha` met `bool`-conversie [▶ 12:57:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46632s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cctype>

int main() {
    std::cout << std::boolalpha;
    // static_cast<bool> maakt van "niet-nul / nul" netjes true / false
    std::cout << "e is alphabetic : " << static_cast<bool>(std::isalpha('e')) << '\n';
    std::cout << "^ is alphabetic : " << static_cast<bool>(std::isalpha('^')) << '\n';
    std::cout << "7 is alphabetic : " << static_cast<bool>(std::isalpha('7')) << '\n';

    if (std::isalpha('e')) {
        std::cout << "e is alphabetic\n";
    } else {
        std::cout << "e is not alphabetic\n";
    }
    return 0;
}
```
```text
e is alphabetic : true
^ is alphabetic : false
7 is alphabetic : false
e is alphabetic
```

#### Blanks tellen met `std::isblank` [▶ 13:00:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=46829s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. De tekst van het bericht is niet letterlijk bekend; de output hoort bij de tekst hieronder.

```cpp
#include <iostream>
#include <cctype>
#include <iterator> // std::size
#include <cstddef>  // std::size_t

int main() {
    char message[] {"Hello there. How do you do? The sun is shining."};

    std::size_t blank_count {}; // telling is nooit negatief -> size_t
    for (std::size_t i {}; i < std::size(message); ++i) {
        if (std::isblank(message[i])) {
            std::cout << "Found a blank character at index : [" << i << "]\n";
            ++blank_count;
        }
    }
    std::cout << "In total, we found " << blank_count << " blank characters.\n";
    return 0;
}
```
```text
Found a blank character at index : [5]
Found a blank character at index : [12]
Found a blank character at index : [16]
Found a blank character at index : [19]
Found a blank character at index : [23]
Found a blank character at index : [27]
Found a blank character at index : [31]
Found a blank character at index : [35]
Found a blank character at index : [38]
In total, we found 9 blank characters.
```

#### Hoofdletters en kleine letters tellen [▶ 13:03:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47021s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cctype>
#include <cstddef>

int main() {
    char message[] {"The Life Of Brian Is A Funny Movie"};

    std::size_t lowercase_count {};
    std::size_t uppercase_count {};

    std::cout << "Original string : " << message << '\n';

    for (char c : message) { // range based for: werkt op een echte array
        if (std::islower(c)) {
            ++lowercase_count;
        }
        if (std::isupper(c)) {
            ++uppercase_count;
        }
    }

    std::cout << "Found " << lowercase_count << " lowercase characters and "
              << uppercase_count << " uppercase characters.\n";
    return 0;
}
```
```text
Original string : The Life Of Brian Is A Funny Movie
Found 19 lowercase characters and 8 uppercase characters.
```

#### Cijfers vinden met `std::isdigit` [▶ 13:05:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47116s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cctype>
#include <cstddef>

int main() {
    char statement[] {"Mr Holmes lives at 221 Baker Street."};

    std::size_t digit_count {};
    for (char c : statement) {
        if (std::isdigit(c)) {
            std::cout << "Found digit : " << c << '\n';
            ++digit_count;
        }
    }
    std::cout << "Found " << digit_count << " digits in the statement string.\n";
    return 0;
}
```
```text
Found digit : 2
Found digit : 2
Found digit : 1
Found 3 digits in the statement string.
```

#### Omzetten met `std::toupper` en `std::tolower` [▶ 13:06:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47212s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cctype>
#include <iterator>
#include <cstddef>

int main() {
    char original_str[] {"Home. The feeling of belonging"};
    char dest_str[std::size(original_str)]; // even groot, inclusief '\0'

    // Naar hoofdletters (de '\0' wordt ook gekopieerd)
    for (std::size_t i {}; i < std::size(original_str); ++i) {
        dest_str[i] = static_cast<char>(std::toupper(original_str[i]));
    }
    std::cout << "Original string : " << original_str << '\n';
    std::cout << "Uppercase string : " << dest_str << '\n';

    // Naar kleine letters, bestemming wordt overschreven
    for (std::size_t i {}; i < std::size(original_str); ++i) {
        dest_str[i] = static_cast<char>(std::tolower(original_str[i]));
    }
    std::cout << "Lowercase string : " << dest_str << '\n';
    return 0;
}
```
```text
Original string : Home. The feeling of belonging
Uppercase string : HOME. THE FEELING OF BELONGING
Lowercase string : home. the feeling of belonging
```

#### `std::strlen` en `sizeof` [▶ 13:19:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=47977s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

`sizeof` van een pointer is platformafhankelijk (8 op een 64-bit systeem), daarom voorbeeldoutput.

```cpp
// nocheck-output
#include <iostream>
#include <cstring>

int main() {
    const char message1[] {"The sky is blue."}; // echte array
    const char* message2 {"The sky is blue."};  // pointer naar literal

    std::cout << "strlen(message1) : " << std::strlen(message1) << '\n'; // zonder '\0'
    std::cout << "sizeof(message1) : " << sizeof(message1) << '\n';      // met '\0'
    std::cout << "strlen(message2) : " << std::strlen(message2) << '\n'; // werkt ook op pointer
    std::cout << "sizeof(message2) : " << sizeof(message2) << '\n';      // grootte van de pointer!
    return 0;
}
```
```text
strlen(message1) : 16
sizeof(message1) : 17
strlen(message2) : 16
sizeof(message2) : 8
```

#### `std::strcmp` op pointers en arrays [▶ 13:21:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48072s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

De exacte waarde is implementatie-afhankelijk; alleen het teken is gegarandeerd. Met deze compiler geeft het programma:

```cpp
#include <iostream>
#include <cstring>

int main() {
    // C-strings via pointers
    const char* string_data1 {"Alabama"};
    const char* string_data2 {"Blabama"};

    // C-strings in arrays
    char string_data3[] {"Alabama"};
    char string_data4[] {"Blabama"};

    std::cout << "strcmp(" << string_data1 << ", " << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << '\n';
    std::cout << "strcmp(" << string_data3 << ", " << string_data4 << ") : "
              << std::strcmp(string_data3, string_data4) << '\n';

    // Een (niet-const) pointer mag naar een andere string wijzen
    string_data1 = "Alakama";
    string_data2 = "Alabama";
    std::cout << "strcmp(" << string_data1 << ", " << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << '\n';

    string_data1 = "India";
    string_data2 = "France";
    std::cout << "strcmp(" << string_data1 << ", " << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << '\n';

    string_data1 = "Kigali";
    string_data2 = "Kigali";
    std::cout << "strcmp(" << string_data1 << ", " << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << '\n';
    return 0;
}
```
```text
strcmp(Alabama, Blabama) : -1
strcmp(Alabama, Blabama) : -1
strcmp(Alakama, Alabama) : 1
strcmp(India, France) : 1
strcmp(Kigali, Kigali) : 0
```

#### Array laten wijzen naar andere string: compilerfout [▶ 13:25:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48315s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: een array kun je niet opnieuw toewijzen
#include <cstring>

int main() {
    char string_data3[] {"Alabama"};
    char string_data4[] {"Blabama"};
    string_data3 = "Alakama"; // error: invalid array assignment
    string_data4 = "Alabama";
    return std::strcmp(string_data3, string_data4);
}
```

#### `std::strncmp`: n karakters vergelijken [▶ 13:27:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48458s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>
#include <cstddef>

int main() {
    const char* string_data1 {"Alabama"};
    const char* string_data2 {"Blabama"};
    std::size_t n {3};

    std::cout << "strncmp(" << string_data1 << ", " << string_data2 << ", " << n
              << ") : " << std::strncmp(string_data1, string_data2, n) << '\n';

    string_data1 = "aaaia";
    string_data2 = "aaance";
    std::cout << "strncmp(" << string_data1 << ", " << string_data2 << ", " << n
              << ") : " << std::strncmp(string_data1, string_data2, n) << '\n';

    n = 5; // nu telt 'i' vs 'n' mee
    std::cout << "strncmp(" << string_data1 << ", " << string_data2 << ", " << n
              << ") : " << std::strncmp(string_data1, string_data2, n) << '\n';

    string_data1 = "aaaoa"; // 'o' komt na 'n'
    std::cout << "strncmp(" << string_data1 << ", " << string_data2 << ", " << n
              << ") : " << std::strncmp(string_data1, string_data2, n) << '\n';
    return 0;
}
```
```text
strncmp(Alabama, Blabama, 3) : -1
strncmp(aaaia, aaance, 3) : 0
strncmp(aaaia, aaance, 5) : -1
strncmp(aaaoa, aaance, 5) : 1
```

#### Alle voorkomens zoeken met `std::strchr` [▶ 13:30:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48601s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm (gebaseerd op het cppreference-voorbeeld).

```cpp
#include <iostream>
#include <cstring>
#include <cstddef>

int main() {
    // const pointer: str zelf kan niet meer verschoven worden (++str = fout)
    const char* const str {"Try not. Do, or do not. There is no try."};
    char target {'T'};
    const char* result {str};
    std::size_t iterations {};

    // Resultaat terug in 'result' -> volgende zoekactie begint na de treffer
    while ((result = std::strchr(result, target)) != nullptr) {
        std::cout << "Found '" << target << "' starting at '" << result << "'\n";
        ++result; // één voorbij de gevonden T, anders vinden we hem opnieuw
        ++iterations;
    }
    std::cout << "iterations : " << iterations << '\n';
    return 0;
}
```
```text
Found 'T' starting at 'Try not. Do, or do not. There is no try.'
Found 'T' starting at 'There is no try.'
iterations : 2
```

#### De foute `strchr`-loop (25 iteraties) [▶ 13:36:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=48986s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Om de output kort te houden printen we alleen de telling.

```cpp
#include <iostream>
#include <cstring>
#include <cstddef>

int main() {
    const char* str {"Try not. Do, or do not. There is no try."};
    char target {'T'};
    const char* result {nullptr};
    std::size_t iterations {};

    // FOUT: we zoeken telkens vanaf str en schuiven str maar 1 positie op
    while ((result = std::strchr(str, target)) != nullptr) {
        // std::cout << "Found '" << target << "' starting at '" << result << "'\n";
        ++str;        // zou str = result + 1 moeten zijn
        ++iterations;
    }
    std::cout << "iterations : " << iterations << '\n';
    return 0;
}
```
```text
iterations : 25
```

#### Bestandsnaam uit pad met `std::strrchr` [▶ 13:39:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49177s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    char input[] {"/home/user/hello.cpp"};
    char* output = std::strrchr(input, '/'); // laatste '/'

    if (output) { // niet nullptr
        std::cout << output + 1 << '\n'; // één verder: de bestandsnaam
    }
    return 0;
}
```
```text
hello.cpp
```

#### `std::strcat` met arrays op de stack [▶ 13:49:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49750s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    char dest[50] {"Hello "};   // groot genoeg voor alles wat erbij komt
    char src[50] {"World!"};

    std::strcat(dest, src);     // overschrijft de '\0' van dest
    std::cout << "dest : " << dest << '\n';

    std::strcat(dest, " Goodbye World!");
    std::cout << "dest : " << dest << '\n';
    return 0;
}
```
```text
dest : Hello World!
dest : Hello World! Goodbye World!
```

#### `std::strcat` met dynamische arrays [▶ 13:53:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=49992s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    // Heap-arrays, met losse karakters en een expliciete '\0' geïnitialiseerd
    char* dest1 = new char[30]{'F', 'i', 'r', 'e', 'L', 'o', 'r', 'd', '\0'};
    char* source1 = new char[30]{',', ' ', 'T', 'h', 'e', ' ', 'P', 'h', 'o',
                                 'e', 'n', 'i', 'x', ' ', 'K', 'i', 'n', 'g', '\0'};

    std::cout << "strlen(dest1) : " << std::strlen(dest1) << '\n';
    std::cout << "strlen(source1) : " << std::strlen(source1) << '\n';

    std::strcat(dest1, source1); // komma overschrijft de '\0' na "FireLord"

    std::cout << "After concatenation : \n";
    std::cout << "strlen(dest1) : " << std::strlen(dest1) << '\n';
    std::cout << "dest1 : " << dest1 << '\n';

    delete[] dest1;   // heap-geheugen altijd teruggeven
    delete[] source1;
    return 0;
}
```
```text
strlen(dest1) : 8
strlen(source1) : 18
After concatenation : 
strlen(dest1) : 26
dest1 : FireLord, The Phoenix King
```

#### `std::strncat` en de return-waarde [▶ 13:55:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50135s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    char dest2[50] {"Hello"};
    char source2[] {" There is a bird on my window"};

    // Hoogstens 6 karakters uit source2 toevoegen: " There"
    char* result = std::strncat(dest2, source2, 6);

    std::cout << "The concatenated string is : " << dest2 << '\n';
    std::cout << "The concatenated string is : " << result << '\n'; // zelfde adres
    return 0;
}
```
```text
The concatenated string is : Hello There
The concatenated string is : Hello There
```

#### `std::strcpy` naar een heap-array [▶ 13:57:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50231s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    const char* source3 {"C++ is a multipurpose programming language."};
    // +1 voor de '\0', want strlen telt die niet mee
    char* dest3 = new char[std::strlen(source3) + 1];

    std::strcpy(dest3, source3); // kopieert inclusief '\0'

    std::cout << "strlen(dest3) : " << std::strlen(dest3) << " characters\n";
    std::cout << "dest3 : " << dest3 << '\n';

    delete[] dest3;
    return 0;
}
```
```text
strlen(dest3) : 43 characters
dest3 : C++ is a multipurpose programming language.
```

#### `std::strncpy`: hoogstens n karakters [▶ 13:58:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50328s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <cstring>

int main() {
    const char* source4 {"Hello"};
    char dest4[] {'a', 'b', 'c', 'd', 'e', 'f', '\0'};

    std::cout << "dest4 : " << dest4 << '\n';
    // 5 karakters: overschrijft "abcde", 'f' en '\0' blijven staan
    std::strncpy(dest4, source4, 5);
    std::cout << "dest4 : " << dest4 << '\n';
    return 0;
}
```
```text
dest4 : abcdef
dest4 : Hellof
```

#### `std::string` declareren en initialiseren [▶ 14:06:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=50765s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string full_name;                          // lege string
    std::string planet {"Earth. Where the sky is blue"}; // uit literal
    std::string preferred_planet {planet};          // kopie van andere string
    std::string message {"Hello there", 5};         // eerste 5 karakters
    std::string weird_message(4, 'e');              // 4 x 'e' (ronde haakjes!)
    std::string greeting {"Hello World"};
    std::string saying_hello {greeting, 6, 5};      // vanaf index 6, 5 karakters

    std::cout << "full_name : " << full_name << '\n';
    std::cout << "planet : " << planet << '\n';
    std::cout << "preferred_planet : " << preferred_planet << '\n';
    std::cout << "message : " << message << '\n';
    std::cout << "weird_message : " << weird_message << '\n';
    std::cout << "greeting : " << greeting << '\n';
    std::cout << "saying_hello : " << saying_hello << '\n';
    return 0;
}
```
```text
full_name : 
planet : Earth. Where the sky is blue
preferred_planet : Earth. Where the sky is blue
message : Hello
weird_message : eeee
greeting : Hello World
saying_hello : World
```

#### `std::string` groeit, `const char*` wijst alleen om [▶ 14:10:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51005s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string planet {"Earth. Where the sky is blue"};
    std::cout << "planet : " << planet << '\n';

    // Langere waarde toewijzen: std::string regelt zelf nieuw geheugen
    planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where the sky is blue";
    std::cout << "planet : " << planet << '\n';

    // Met een const char* wijst de pointer alleen naar een andere literal
    const char* planet1 {"Earth. Where the sky is blue"};
    planet1 = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where the sky is blue";
    std::cout << "planet1 : " << planet1 << '\n';
    return 0;
}
```
```text
planet : Earth. Where the sky is blue
planet : Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where the sky is blue
planet1 : Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where the sky is blue
```

### Valkuilen & veelgemaakte fouten

#### Verwachten dat `<cctype>`-functies `1` teruggeven

De functies geven een `int` terug die alleen "niet-nul" of "nul" is. `if (std::isalpha(c) == 1)` kan dus onterecht falen. Test op waarheid (`if (std::isalpha(c))`) of gebruik `static_cast<bool>`.

#### Vertrouwen op indirecte includes

Bij de docent compileert `std::isalnum` zonder `<cctype>`, omdat `<iostream>` het meebrengt. Op een andere compiler of versie hoeft dat niet zo te zijn. Include altijd wat je gebruikt.

#### `int` gebruiken voor tellers en groottes

Een aantal karakters is nooit negatief. De docent vervangt `int` daarom door `std::size_t`. Dat voorkomt ook signed/unsigned-vergelijkingswaarschuwingen als je vergelijkt met `std::size(...)` of `std::strlen(...)`.

#### `sizeof` gebruiken als stringlengte

`sizeof` op een array telt de `'\0'` mee (17 i.p.v. 16), en `sizeof` op een pointer geeft de pointergrootte (8), niet de tekstlengte. Gebruik `std::strlen` voor de lengte van een C-string.

#### Vergeten dat `strlen` de `'\0'` niet telt

Wie een buffer maakt met `new char[std::strlen(src)]` en daarin kopieert, schrijft één byte te veel. Altijd `+ 1` voor de null-terminator.

#### Een array opnieuw willen toewijzen

`char arr[] {"Alabama"}; arr = "Blabama";` geeft een compilerfout. Een array is geen pointer die je kunt omzetten. Alleen een (niet-const) pointer kun je naar een andere string laten wijzen.

#### De `strchr`-loop die nooit verspringt

Als je het resultaat van `strchr` niet terugzet in de zoekpositie (en `str` maar met één ophoogt), vind je dezelfde treffer keer op keer: 25 iteraties in plaats van 2. Gebruik `result = std::strchr(result, target)` en daarna `++result`.

#### De oorspronkelijke pointer verschuiven

Als je `str` zelf ophoogt tijdens het zoeken, ben je het begin van je bericht kwijt. Gebruik een aparte zoekpointer en maak de originele pointer `const` (`const char* const str`), dan vangt de compiler een `++str` af:

```cpp
// ❌ bewust fout: const pointer kan niet verschoven worden
int main() {
    const char* const str {"Try not."};
    ++str; // error: increment of read-only variable 'str'
    return 0;
}
```

#### `strcat`/`strcpy` naar een te kleine bestemming

`strcat` en `strcpy` controleren niets. Is de bestemming te klein, dan schrijf je buiten de array (buffer overflow, undefined behavior). De compiler vangt dit alleen soms op:

```cpp
// ❌ bewust fout: dest is veel te klein (buffer overflow / UB)
#include <cstring>

int main() {
    char dest[3] {"He"};
    std::strcat(dest, "llo World!"); // schrijft voorbij het einde van dest
    return 0;
}
```

#### Een `const` bestemming meegeven

De bestemming van `strcat`/`strcpy` moet wijzigbaar zijn:

```cpp
// ❌ bewust fout: bestemming is een array van const char
#include <cstring>

int main() {
    const char dest[50] {"Hello "};
    std::strcat(dest, "World!"); // error: invalid conversion from 'const char*' to 'char*'
    return 0;
}
```

#### `strncpy` laat de null-terminator weg

Als de bron minstens `count` karakters heeft, kopieert `strncpy` **geen** `'\0'`. In het voorbeeld ging het goed omdat `dest4` al een terminator achter de `'f'` had. Begin je met een niet-geïnitialiseerde buffer, dan heb je geen geldige C-string meer.

#### Exacte waarde van `strcmp` gebruiken

`-1`, `0`, `1` is wat de docent ziet, maar de standaard belooft alleen negatief/nul/positief. Test op `< 0`, `== 0`, `> 0`.

#### `{}` versus `()` bij `std::string(4, 'e')`

> 💡 Aanvulling: `std::string s {4, 'e'};` maakt een string van **twee** karakters (code 4 en `'e'`), omdat accolades de initializer-list-constructor kiezen. Voor "4 keer 'e'" gebruik je ronde haakjes, zoals de docent doet.

### Best practices

- Include de header van wat je gebruikt: `<cctype>` voor karakterfuncties, `<cstring>` voor C-stringfuncties, `<string>` voor `std::string`.
- Gebruik `<cctype>`-resultaten in een voorwaarde of zet ze om met `static_cast<bool>`.
- Gebruik `std::size_t` voor tellers, indexen en groottes.
- Gebruik `std::strlen` voor de lengte van een C-string, en reken altijd `+ 1` voor de `'\0'` bij het reserveren van geheugen.
- Laat de originele pointer met rust bij zoeken; gebruik een aparte zoekpointer en maak de originele `const`.
- Zorg bij `strcat`, `strcpy` en verwanten zelf dat de bestemming wijzigbaar en groot genoeg is; geef heap-geheugen terug met `delete[]`.
- Test je code op meerdere compilers (GCC, Clang, MSVC); zo leer je hun waarschuwingen over onveilige functies kennen.
- Lees de documentatie op cppreference.com: daar staan signatuur, return-waarde en een voorbeeld van elke functie.
- Gebruik in nieuwe code bij voorkeur `std::string`: geen handmatig geheugenbeheer, geen null-terminator, en hij groeit vanzelf.

### Samenvatting

- Een C-string is een `char`-array met een afsluitende `'\0'`; je moet zelf grootte en terminator bewaken, wat foutgevoelig is.
- `<cctype>` biedt `isalnum`, `isalpha`, `isblank`, `islower`, `isupper`, `isdigit` (geven niet-nul/nul) en `toupper`/`tolower` (geven het omgezette karakter terug).
- `std::strlen` telt karakters zonder `'\0'` en werkt ook op pointers; `sizeof` telt bij arrays de `'\0'` mee en geeft bij pointers de pointergrootte.
- `std::strcmp`/`std::strncmp` vergelijken lexicografisch: negatief, nul of positief.
- `std::strchr`/`std::strrchr` geven een pointer naar het eerste/laatste voorkomen of `nullptr`; met pointer-arithmetiek loop je verder door de string.
- `std::strcat`/`std::strncat` plakken achter de bestemming (vanaf de oude `'\0'`), `std::strcpy`/`std::strncpy` kopiëren vanaf het begin; de bestemming moet wijzigbaar en groot genoeg zijn.
- `strncpy` zet niet altijd een `'\0'`; `strncat` wel.
- `std::string` (header `<string>`) verbergt al die details, kent meerdere initialisatievormen (leeg, literal, kopie, deel van literal, n keer een karakter, deel van andere string) en groeit automatisch.
- Een `const char*` opnieuw toewijzen verandert alleen waar de pointer naar wijst; een `std::string` beheert zelf zijn geheugen.

### Oefeningen

1. Schrijf een programma dat in de zin `"C++20 came out in 2020, wow!"` telt hoeveel letters, cijfers, blanks en overige tekens er zijn. Gebruik `std::isalpha`, `std::isdigit` en `std::isblank`, en `std::size_t` voor de tellers.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstddef>

int main() {
    const char* sentence {"C++20 came out in 2020, wow!"};
    std::size_t letters {}, digits {}, blanks {}, others {};

    for (std::size_t i {}; i < std::strlen(sentence); ++i) {
        char c {sentence[i]};
        if (std::isalpha(c)) {
            ++letters;
        } else if (std::isdigit(c)) {
            ++digits;
        } else if (std::isblank(c)) {
            ++blanks;
        } else {
            ++others;
        }
    }
    std::cout << "letters : " << letters << '\n';
    std::cout << "digits : " << digits << '\n';
    std::cout << "blanks : " << blanks << '\n';
    std::cout << "others : " << others << '\n';
    return 0;
}
```
```text
letters : 13
digits : 6
blanks : 5
others : 4
```
</details>

2. Maak van `char text[] {"hello world from c++"}` een versie waarin alleen de **eerste letter van elk woord** een hoofdletter is ("Hello World From C++"). Pas de array zelf aan met `std::toupper`.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <cctype>
#include <iterator>
#include <cstddef>

int main() {
    char text[] {"hello world from c++"};
    bool new_word {true}; // begin van de tekst = begin van een woord

    for (std::size_t i {}; i < std::size(text) - 1; ++i) { // -1: '\0' overslaan
        if (std::isblank(text[i])) {
            new_word = true;
        } else if (new_word) {
            text[i] = static_cast<char>(std::toupper(text[i]));
            new_word = false;
        }
    }
    std::cout << text << '\n';
    return 0;
}
```
```text
Hello World From C++
```
</details>

3. Tel met een correcte `std::strchr`-loop hoe vaak de letter `'a'` voorkomt in `"banana bandana"`, en print bij elke treffer de index (tip: `result - str` geeft de index).

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <cstring>
#include <cstddef>

int main() {
    const char* const str {"banana bandana"};
    const char* result {str};
    std::size_t count {};

    while ((result = std::strchr(result, 'a')) != nullptr) {
        std::cout << "'a' at index " << (result - str) << '\n'; // pointer-verschil
        ++result;
        ++count;
    }
    std::cout << "count : " << count << '\n';
    return 0;
}
```
```text
'a' at index 1
'a' at index 3
'a' at index 5
'a' at index 8
'a' at index 11
'a' at index 13
count : 6
```
</details>

4. Schrijf een programma dat de C-strings `"Fire"`, `"Lord"` en `"!"` met `std::strcpy` en `std::strcat` samenvoegt in een **heap-array van precies de juiste grootte** (bereken die met `std::strlen`). Print het resultaat en de lengte, en geef het geheugen netjes terug.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <cstring>
#include <cstddef>

int main() {
    const char* a {"Fire"};
    const char* b {"Lord"};
    const char* c {"!"};

    // +1 voor de null-terminator
    std::size_t size {std::strlen(a) + std::strlen(b) + std::strlen(c) + 1};
    char* result = new char[size];

    std::strcpy(result, a); // begin met een kopie (zet ook '\0')
    std::strcat(result, b);
    std::strcat(result, c);

    std::cout << result << " (" << std::strlen(result) << " characters)\n";
    delete[] result;
    return 0;
}
```
```text
FireLord! (9 characters)
```
</details>

5. Doe hetzelfde als in oefening 4, maar nu met `std::string`. Gebruik daarnaast de initialisatievormen uit dit hoofdstuk: maak `std::string line(9, '-')` en een `std::string` met alleen `"Lord"` als deel van je resultaat (vanaf index 4, 4 karakters). Merk op hoeveel eenvoudiger het is.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <string>

int main() {
    std::string result {"Fire"};
    result = "FireLord!";              // groeit vanzelf, geen grootte bijhouden
    std::string line(9, '-');          // 9 x '-'
    std::string part {result, 4, 4};   // vanaf index 4, 4 karakters

    std::cout << line << '\n';
    std::cout << result << '\n';
    std::cout << line << '\n';
    std::cout << "part : " << part << '\n';
    return 0;
}
```
```text
---------
FireLord!
---------
part : Lord
```
</details>

---

<a id="h11"></a>

## Hoofdstuk 11 – Functions (14:12:47 – 16:03:20) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51167s)

### Leerdoelen
- De **One Definition Rule (ODR)** begrijpen voor vrijstaande variabelen, functies en classes, en het verschil zien tussen een compilerfout (redefinition) en een linkerfout (multiple definition).
- Functies schrijven: return type, naam, parameterlijst, body en `return`.
- Het verschil kennen tussen **parameters** en **argumenten**, en tussen **signature** en **prototype**.
- Een functie opsplitsen in een **declaratie** (prototype) en een **definitie**.
- Het uitgebreide compilatiemodel kennen: **preprocessing → compilatie → linking**, en weten wat een **translation unit** en een **object file** zijn.
- Functies verdelen over meerdere bestanden (`.h` + `.cpp`) en linkerfouten zoals `undefined reference` herkennen.
- Argumenten doorgeven **by value**, **by pointer** en **by reference**, en weten wanneer er een kopie wordt gemaakt.

### Verband met eerdere hoofdstukken
- In **hoofdstuk 2** zag je al dat een C++-programma uit statements en functies bestaat, met `main` als startpunt, en een eerste versie van het compilatiemodel (broncode → compiler → binary `rooster`). In dit hoofdstuk wordt dat model uitgebreid met preprocessing en linking.
- **Hoofdstuk 3** (types, `size_t`, `unsigned`) en de impliciete conversies uit **hoofdstuk 4** komen terug bij het kiezen van parametertypes en bij het aanroepen van functies met het "verkeerde" type.
- **Hoofdstuk 5 en 6** (if/else, loops) gebruik je in de bodies van de functies (`enter_bar`, `max`, een loop die een functie herhaald aanroept).
- **Hoofdstuk 8 (pointers)** en **hoofdstuk 9 (references)** zijn de basis voor pass by pointer en pass by reference: het address-of operator `&`, dereferencen met `*` en het idee dat een reference een alias is.
- Vooruitblik: **hoofdstuk 12** gaat over de andere kant van de machine: hoe je data *uit* een functie krijgt (output parameters, return by value). **Hoofdstuk 13** (overloading) bouwt voort op het begrip signature, en **hoofdstuk 17** behandelt classes uitgebreid (de `Person`-class met een static member wordt hier al kort gebruikt).

### Uitleg

#### De One Definition Rule (ODR)
- **Wat en waarom:** de ODR zegt dat iets (een variabele, een functie, ...) in je hele programma maar **één definitie** mag hebben. Anders weten compiler of linker niet welke versie bedoeld is.
- **Vrijstaande variabelen:** `double weight {};` buiten elke functie is tegelijk een declaratie én een definitie. Zet je hem twee keer in hetzelfde bestand, dan geeft de compiler een *redefinition*-fout. Zet je de tweede kopie in een ander `.cpp`-bestand, dan slaagt het compileren per bestand wel, maar de **linker** ziet twee definities van `weight` en stopt met `multiple definition of 'weight'`. Dit is dus een linkerfout. [▶ 14:14:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51246s)
- **Functies:** precies hetzelfde. Twee definities van `double add(double a, double b)` in één bestand geven een compilerfout (*redefinition of add*); één in `main.cpp` en één in `some_other_file.cpp` geven een linkerfout (*multiple definition of add*). Haal je één van beide weg (bijvoorbeeld door hem uit te commentariëren), dan werkt alles weer en print `add(10, 20)` netjes 30. [▶ 14:16:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51388s)
- **Uitzondering: classes.** Een class-definitie (ook een `struct`) mag in **meerdere translation units** voorkomen. Dat moet ook wel: elke translation unit die objecten van die class maakt, moet de volledige definitie kennen. Je mag dezelfde class alleen niet twee keer in **dezelfde** translation unit definiëren, dan krijg je weer *redefinition of struct Point*. De docent laat dit zien met `struct Point { double m_x{}; double m_y{}; };`, eerst zonder initialisatie (rommelwaarden), daarna met `{}` (nullen). [▶ 14:18:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51534s)
- **Header met class + static member:** in de praktijk staat de class-definitie in een header (`person.h`, met include guard) die je in meerdere `.cpp`-bestanden include. De class zelf mag dus overal zichtbaar zijn, maar de **definities van de member functions** (zoals de constructor) en van een **static member variabele** (`person_count`) vallen weer gewoon onder de ODR: die mogen maar in één `.cpp`-bestand staan. Kopieer je ze ook naar `main.cpp`, dan meldt de linker *multiple definition* voor zowel de constructor als `person_count`. [▶ 14:21:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51675s)

> ⚠️ Onduidelijk in opname: het transcript begint midden in de inleidende slide over de ODR; het begin van die uitleg (14:12:47 – 14:13:19) ontbreekt.

#### Wat is een functie?
- **Wat en waarom:** een functie is een herbruikbaar stuk code. Je kunt het zien als een **machine**: je stopt er input in, de machine verwerkt die, en geeft (optioneel) output terug die afhangt van de input. Eenmaal gebouwd kun je de machine zo vaak gebruiken als je wilt. [▶ 14:28:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52102s)
- **Syntax:** [▶ 14:29:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52151s)
  ```
  return_type function_name(type1 param1, type2 param2, ...) {
      // body: verwerking
      return result;
  }
  ```
  - Het **return type** is verplicht. Laat je het weg, dan krijg je een compilerfout.
  - `void` betekent: de functie geeft niets terug. In een `void`-functie mag je `return` weglaten of een kale `return;` schrijven. Bij elk ander return type moet je een waarde teruggeven.
  - Een lege parameterlijst `()` betekent: de functie neemt geen input.
- **Parameters vs. argumenten:** in de *definitie/declaratie* staan **parameters** (`int a, int b`). De waarden die je bij het *aanroepen* meegeeft (`max(10, 20)`) zijn **argumenten**. [▶ 14:33:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52392s)
- **Aanroepen:** `result_var = function_name(arg1, arg2);`. De returnwaarde kun je opvangen in een variabele, direct in een `std::cout` gebruiken of negeren. Een functie zonder parameters roep je aan met lege haakjes: `lucky_number()`. [▶ 14:31:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52295s)
- **Volgorde:** een functie moet **gedeclareerd zijn vóór** je hem gebruikt. Daarom zette de docent in de eerste voorbeelden alle functies boven `main`. [▶ 14:51:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53507s)

#### Signature: wat maakt een functie uniek?
- Elke functie moet uniek zijn op basis van zijn **signature** = **functienaam + parameterlijst** (de types). Het **return type hoort er niet bij**. [▶ 14:30:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52248s)
- Twee functies `int max(int a, int b)` en `void max(int a, int b)` hebben dus dezelfde signature: compilerfout (*redefinition of int max*/ambiguating new declaration). Ook andere **parameternamen** (`int c, int d`) helpen niet: namen zijn geen onderdeel van de signature. [▶ 14:54:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53652s)
- De docent zegt dat we nog niet alle gereedschap hebben om dit volledig te begrijpen; dat komt bij function overloading (hoofdstuk 13).

#### Eerste functies in VS Code
- `enter_bar(unsigned int age)`: een leeftijd kan niet negatief zijn, dus de docent kiest een unsigned type. Bij `age > 18` mag je naar binnen, anders "too young". Tijdens de demo had hij per ongeluk `age > 10` getypt, waardoor 15 ook binnen mocht; dat is daarna verbeterd naar 18. [▶ 14:40:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52831s)
- De functie wordt één keer gedefinieerd maar meerdere keren aangeroepen, ook in een loop `for (size_t i{1}; i < 20; ++i) enter_bar(i);`. Omdat `i` een `size_t` is, verandert de docent het parametertype ook in `size_t` om impliciete conversies te vermijden. [▶ 14:45:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53119s)
- `int max(int a, int b)`: geeft `a` terug als `a > b`, anders `b`. Bij `max(10, 20)` springt de controle naar de body, de argumenten worden **gekopieerd** naar `a` en `b`, en de returnwaarde wordt de waarde van de aanroep-expressie. [▶ 14:47:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53265s)
- `void say_hello()` (geen input, geen output) en `int lucky_number()` (geen input, wel output: 99). [▶ 14:52:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53555s)

#### Impliciete conversies bij aanroepen
- Roep je een functie met `int`-parameters aan met `double`-argumenten, dan voegt de compiler **stilletjes** een conversie `double → int` toe (de decimalen gaan verloren). Zorg dat zulke conversies in je voordeel werken, anders krijg je lastig te vinden bugs. [▶ 14:37:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52636s)

#### Argumenten worden gekopieerd
- Met parameters zoals `double a` werkt de functie op **kopieën** van de argumenten. Verhoog je `a` en `b` in `incr_mult`, dan veranderen `h` en `i` in `main` niet. De kopieën verdwijnen zodra de functie eindigt. [▶ 14:38:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52686s) · demo [▶ 14:56:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53794s)

#### Function declarations en definitions
- **Waarom:** soms wil je de **header** van een functie (wat gaat erin, wat komt eruit) scheiden van de **implementatie** (hoe het gebeurt). Lezers van `main` willen meestal alleen weten *hoe* ze de functie gebruiken, niet alle details. [▶ 15:00:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54035s)
- **Declaratie / prototype:** return type + naam + parameterlijst + **puntkomma**: `int max(int a, int b);`
- **Definitie:** dezelfde header, zonder puntkomma, maar met een body `{ ... }`. Die mag overal staan, bijvoorbeeld na `main`.
- **Prototype vs. signature:** het prototype bevat *ook* het return type; de signature niet.
- Het prototype moet vóór de aanroep staan. Een definitie boven `main` werkt tegelijk als declaratie; daarom werkten de vorige voorbeelden.
- **Declaratie zonder definitie:** de compiler is tevreden (hij kent de vorm van de functie), maar de **linker** zoekt de body en vindt hem niet: `undefined reference to 'max(int, int)'`. [▶ 15:08:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54512s)
- **Parameternamen in de declaratie zijn optioneel:** `int max(int, int);` compileert ook. De docent laat ze er toch in staan, omdat dat de code zelfdocumenterend maakt. In de definitie heb je de namen wél nodig, want je gebruikt ze in de body. [▶ 15:14:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54850s)
- In de demo: `max`, `min` en `incr_mult` met declaraties boven `main` en definities eronder. `incr_mult(5, 12)` geeft `6 * 13 = 78`. [▶ 15:11:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54707s)

#### Het compilatiemodel herzien: preprocessing, compilatie, linking
- Het oude model was: `main.cpp` → compiler → binary `rooster` → uitvoeren. Nu zoomt de docent in op de stap "compiler" bij een programma met meerdere bronbestanden. [▶ 15:14:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54898s)
- **1. Preprocessing:** elke `#include` wordt vervangen door de volledige inhoud van het geïncludeerde bestand (kopiëren en plakken). Het resultaat per bronbestand heet een **translation unit**. [▶ 15:16:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54995s)
- **2. Compilatie:** elke translation unit wordt los vertaald naar een **object file** (binaire vorm). 20 translation units → 20 object files.
- **3. Linking:** de **linker** plakt alle object files aan elkaar tot één uitvoerbaar bestand. Daarbij zoekt hij voor elke aangeroepen functie de definitie, **in alle translation units**. [▶ 15:18:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55093s)
- Daardoor is het onderscheid belangrijk: declaraties zijn nodig in de **compilatiefase**, definities in de **linkfase**. Geen definitie → `undefined reference`; twee definities → `multiple definition` (ODR).

#### Functies over meerdere bestanden
- Opzet: `compare.h` bevat de **declaraties** van `max` en `min`; `compare.cpp` bevat de **definities**; `main.cpp` doet `#include "compare.h"` en roept de functies aan. [▶ 15:24:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55481s)
- Zonder de include klaagt de compiler: *'max' was not declared in this scope*. Met de include plakt de preprocessor de declaraties in `main.cpp` en is de compiler tevreden. [▶ 15:26:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55576s)
- In de demo had de docent eerst een variabele `max` en een functie `max` met dezelfde naam, wat de compiler verwart; hij noemt de variabele daarom `maximum`. [▶ 15:23:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55383s)
- **Definities mogen in elk `.cpp`-bestand staan**, ze hoeven niet in een bestand met dezelfde naam als de header. De docent verplaatst `max` naar `some_other_file.cpp` en laat `min` in `compare.cpp`; het programma werkt nog steeds, omdat de linker alle translation units doorzoekt. [▶ 15:29:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55769s)
- **Linkerfout:** commentarieer je de definitie van `min` uit, dan geeft GCC `undefined reference to 'min(int, int)'` en `ld returned 1 exit status` (`ld` is de linker van GCC). MSVC zegt hetzelfde met *unresolved external symbol* (fout LNK2019). [▶ 15:31:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55864s) · MSVC [▶ 15:33:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56010s)
- **Oefening van de docent:** splits `incr_mult` in `operations.h` en `operations.cpp`. Daarbij maakte hij eerst de fout `a++` in plaats van `++a`, waardoor `incr_mult(4, 5)` 24 gaf in plaats van 30 (`a++` levert de oude waarde 4 op). [▶ 15:36:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56203s)
- **Quotes vs. punthaken:** je eigen headers include je met aanhalingstekens (`#include "operations.h"`), headers van de standaardbibliotheek met punthaken (`#include <iostream>`). [▶ 15:39:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56349s)
- Voordeel: `main.cpp` blijft overzichtelijk, ook als het project honderden of duizenden functies heeft, en wie de header leest wordt niet lastiggevallen met implementatiedetails.

#### Pass by value
- **Wat:** de parameter is een gewone variabele (`int age`). Bij de aanroep maakt de compiler een **kopie** van het argument in een nieuwe, lokale variabele van de functie. Wat je in de body wijzigt, wijzigt alleen die kopie; bij het einde van de functie verdwijnt de kopie en blijft de variabele buiten onaangetast. [▶ 15:42:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56540s)
- **Bewijs met adressen:** de docent print `&age` in `main` en in `say_age`. De adressen verschillen (eindigend op ...dec tegenover ...dc0): het is een volledig nieuwe geheugenlocatie. Voor de aanroep is `age` 23, in de functie 24, na de aanroep weer 23. [▶ 15:48:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56882s)
- Tijdens de demo zat er een copy-paste-fout in: beide regels zeiden "before call"; daarna verbeterd naar "after call".

#### Pass by pointer
- **Waarom:** om de kopie van pass by value te vermijden en het **origineel** te kunnen wijzigen. [▶ 15:50:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57025s)
- **Syntax:** in declaratie én definitie een pointer-parameter: `void say_age(int* age);`. Bij de aanroep geef je een **adres** mee: `say_age(&age);`. In de body werk je via **dereferencen**: `++(*age);` en `std::cout << *age`.
- **Onder de motorkap:** de pointer zelf bevat het adres van de variabele in `main`, dus `*age` *is* die originele variabele. Resultaat: 23 voor, 24 in de functie, 24 na.
- Fouten van de docent tijdens de demo: eerst vergat hij het dereferencen bij het verhogen, daarna bij het printen (dan print je het adres in plaats van de leeftijd). [▶ 15:54:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57266s)

#### Pass by reference
- **Waarom:** ook geen kopie, maar met een **schonere syntax** dan pointers. [▶ 15:57:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57457s)
- **Syntax:** `void say_age(int& age);` in declaratie en definitie. Bij de aanroep geef je gewoon de variabele mee (`say_age(age);`, geen `&`), en in de body gebruik je hem direct (`++age;`, geen `*`).
- **Onder de motorkap:** een reference is een echte **alias** voor de originele variabele. `&age` in de functie geeft daarom **hetzelfde adres** als in `main`. Resultaat: 23 voor, 24 in de functie, 24 na. [▶ 16:02:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57742s)

> 💡 Aanvulling: wil je een groot object zonder kopie doorgeven maar **niet** wijzigen, gebruik dan `const T&` (bijvoorbeeld `const std::string&`). Voor kleine types zoals `int` en `double` is pass by value prima en meestal sneller.

### Codevoorbeelden

#### ODR: één definitie van een variabele en een functie [▶ 14:16:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51388s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

double weight {};                 // declaratie én definitie (vrijstaande variabele)
// double weight {};              // tweede definitie -> error: redefinition of 'double weight'

double add(double a, double b);   // declaratie

int main() {
    double result = add(10, 20);
    std::cout << "weight : " << weight << std::endl;
    std::cout << "result : " << result << std::endl;
    return 0;
}

double add(double a, double b) {  // de enige definitie van add
    return a + b;
}
```
```text
weight : 0
result : 30
```

#### ODR-schending: twee definities in hetzelfde bestand [▶ 14:17:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51436s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: twee definities van dezelfde naam in één translation unit
#include <iostream>

double weight {};
double weight {};                 // error: redefinition of 'double weight'

double add(double a, double b) { return a + b; }
double add(double a, double b) { return a + b; }   // error: redefinition of 'double add(double, double)'

int main() {
    std::cout << add(10, 20) << std::endl;
    return 0;
}
```
Staan de twee definities in verschillende `.cpp`-bestanden, dan compileert elk bestand wel, maar stopt de linker met `multiple definition of 'add(double, double)'` / `multiple definition of 'weight'`.

#### Classes mogen in meerdere translation units staan [▶ 14:21:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=51675s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

De class-definitie staat in een header met include guard:
```cpp
// file: person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name_param, int age_param);   // alleen declaratie
    void print_info() const {
        std::cout << "Name : " << full_name << ", age : " << age << std::endl;
    }
    static int person_count;                                 // alleen declaratie

private:
    std::string full_name;
    int age;
};

#endif // PERSON_H
```
De definities van de constructor en van de static member staan in **één** `.cpp`-bestand:
```cpp
// file: person.cpp
#include "person.h"

Person::Person(const std::string& name_param, int age_param)
    : full_name{name_param}, age{age_param} {
    ++person_count;                 // constructor telt het aantal objecten
}

int Person::person_count {8};       // definitie + initialisatie van de static member
```
`main.cpp` include dezelfde header (dus de class-definitie staat nu in twee translation units: toegestaan) en mag ook een eigen `struct Point` hebben:
```cpp
// multi: person.cpp
#include <iostream>
#include "person.h"

struct Point {                      // class-definitie; mag ook in een andere TU staan
    double m_x {};
    double m_y {};
};
// struct Point { double m_x{}; double m_y{}; };   // in DEZELFDE TU -> error: redefinition of 'struct Point'

int main() {
    Point p1;
    std::cout << "p1.x : " << p1.m_x << ", p1.y : " << p1.m_y << std::endl;

    Person p2("John Snow", 35);
    p2.print_info();
    std::cout << "person count : " << Person::person_count << std::endl;
    return 0;
}
```
```text
p1.x : 0, p1.y : 0
Name : John Snow, age : 35
person count : 9
```
Zet je de constructor- en `person_count`-definitie uit `person.cpp` óók in `main.cpp`, dan meldt de linker `multiple definition of 'Person::Person(...)'` en `multiple definition of 'Person::person_count'`.

#### Eerste functies: enter_bar, max, say_hello, lucky_number [▶ 14:40:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52831s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

// geen output, één input
void enter_bar(size_t age) {
    if (age > 18) {
        std::cout << "You are " << age << " years old. Please proceed." << std::endl;
    } else {
        std::cout << "Sorry, you are too young for this. No offense." << std::endl;
    }
    return;                       // mag bij void, maar is niet verplicht
}

// twee inputs, één output
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// geen input, geen output
void say_hello() {
    std::cout << "Hello there" << std::endl;
    // return;                    // weglaten mag bij void
}

// geen input, wel output
int lucky_number() {
    return 99;
}

int main() {
    enter_bar(22);
    enter_bar(15);

    int result = max(10, 20);     // 10 en 20 zijn argumenten
    std::cout << "max : " << result << std::endl;

    int x {22};
    int y {44};
    result = max(x, y);
    std::cout << "max : " << result << std::endl;
    std::cout << "max : " << max(100, 20) << std::endl;   // returnwaarde direct gebruiken

    say_hello();

    int lucky {};
    lucky = lucky_number();
    std::cout << "lucky number : " << lucky << std::endl;
    return 0;
}
```
```text
You are 22 years old. Please proceed.
Sorry, you are too young for this. No offense.
max : 20
max : 44
max : 100
Hello there
lucky number : 99
```

#### Een functie in een loop aanroepen [▶ 14:45:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53119s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

void enter_bar(size_t age) {      // size_t, zodat i zonder conversie past
    if (age > 18) {
        std::cout << "You are " << age << " years old. Please proceed." << std::endl;
    } else {
        std::cout << age << " : sorry, you are too young for this." << std::endl;
    }
}

int main() {
    for (size_t i {1}; i < 20; ++i) {
        enter_bar(i);             // één definitie, 19 aanroepen
    }
    return 0;
}
```
```text
1 : sorry, you are too young for this.
2 : sorry, you are too young for this.
3 : sorry, you are too young for this.
4 : sorry, you are too young for this.
5 : sorry, you are too young for this.
6 : sorry, you are too young for this.
7 : sorry, you are too young for this.
8 : sorry, you are too young for this.
9 : sorry, you are too young for this.
10 : sorry, you are too young for this.
11 : sorry, you are too young for this.
12 : sorry, you are too young for this.
13 : sorry, you are too young for this.
14 : sorry, you are too young for this.
15 : sorry, you are too young for this.
16 : sorry, you are too young for this.
17 : sorry, you are too young for this.
18 : sorry, you are too young for this.
You are 19 years old. Please proceed.
```

#### Dezelfde signature twee keer: compilerfout [▶ 14:54:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53652s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: twee functies met dezelfde signature (naam + parameters)
#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void max(int c, int d) {          // ander return type en andere namen helpen NIET
    std::cout << c << d << std::endl;
}

int main() {
    std::cout << max(22, 44) << std::endl;
    return 0;
}
```
GCC meldt dan een fout over een conflicterende declaratie/redefinition van `max(int, int)`.

#### Impliciete conversie bij een aanroep [▶ 14:37:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=52636s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    double f {4.8};
    double g {7.9};
    // de compiler zet f en g stilletjes om naar int: 4 en 7
    std::cout << "min(f, g) : " << min(f, g) << std::endl;
    return 0;
}
```
```text
min(f, g) : 4
```

#### Argumenten worden gekopieerd [▶ 14:56:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=53794s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

double incr_mult(double a, double b) {
    std::cout << "Inside function, before increment : a : " << a << ", b : " << b << std::endl;
    ++a;                          // wijzigt alleen de lokale kopie
    ++b;
    double result = a * b;
    std::cout << "Inside function, after increment  : a : " << a << ", b : " << b << std::endl;
    return result;
}

int main() {
    double h {3};
    double i {4};
    std::cout << "Before call : h : " << h << ", i : " << i << std::endl;
    double incr_mult_result = incr_mult(h, i);
    std::cout << "After call  : h : " << h << ", i : " << i << std::endl;
    std::cout << "result : " << incr_mult_result << std::endl;
    return 0;
}
```
```text
Before call : h : 3, i : 4
Inside function, before increment : a : 3, b : 4
Inside function, after increment  : a : 4, b : 5
After call  : h : 3, i : 4
result : 20
```

#### Declaraties boven main, definities eronder [▶ 15:10:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54656s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

// declaraties (prototypes): return type + naam + parameters + ;
int max(int a, int b);
int min(int, int);               // parameternamen mogen weg in een declaratie
int incr_mult(int a, int b);

int main() {
    int x {5};
    int y {12};

    int result = max(x, y);
    std::cout << "max : " << result << std::endl;

    result = min(x, y);
    std::cout << "min : " << result << std::endl;

    result = incr_mult(x, y);    // (5+1) * (12+1)
    std::cout << "incr_mult : " << result << std::endl;
    return 0;
}

// definities: zelfde header, nu met body
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int incr_mult(int a, int b) {
    return (++a) * (++b);
}
```
```text
max : 12
min : 5
incr_mult : 78
```

#### Declaratie zonder definitie: linkerfout [▶ 15:08:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=54512s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: compileert, maar linken faalt (undefined reference to 'max(int, int)')
#include <iostream>

int max(int a, int b);           // alleen declaratie, nergens een definitie

int main() {
    int result = max(5, 12);
    std::cout << "max : " << result << std::endl;
    return 0;
}
```
Foutmelding van GCC (ingekort): `undefined reference to 'max(int, int)'` gevolgd door `collect2.exe: error: ld returned 1 exit status`.

#### Functies verdeeld over compare.h, compare.cpp en some_other_file.cpp [▶ 15:24:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=55481s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

De header bevat alleen declaraties:
```cpp
// file: compare.h
#ifndef COMPARE_H
#define COMPARE_H

int max(int a, int b);   // declaraties
int min(int a, int b);

#endif // COMPARE_H
```
`compare.cpp` bevat de definitie van `min`:
```cpp
// file: compare.cpp
#include "compare.h"

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
```
De definitie van `max` staat in een ander bestand. Dat mag: de linker doorzoekt alle translation units.
```cpp
// file: some_other_file.cpp
#include "compare.h"

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
```
`main.cpp` include alleen de header:
```cpp
// multi: compare.cpp some_other_file.cpp
#include <iostream>
#include "compare.h"          // eigen header: aanhalingstekens

int main() {
    int maximum = max(134, 56);   // variabele niet "max" noemen: botst met de functie
    std::cout << "max : " << maximum << std::endl;

    int minimum = min(34, 23);
    std::cout << "min : " << minimum << std::endl;
    return 0;
}
```
```text
max : 134
min : 23
```
> ⚠️ Onduidelijk in opname: de argumenten van de `min`-aanroep zijn maar half verstaanbaar ("... and 23"); 34 is een aanname.

Commentarieer je de definitie van `min` in `compare.cpp` uit, dan compileert alles nog (de declaratie staat in `compare.h`), maar de linker meldt `undefined reference to 'min(int, int)'` (GCC) of `LNK2019: unresolved external symbol` (MSVC).

#### Oefening docent: incr_mult in operations.h / operations.cpp [▶ 15:37:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56251s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// file: operations.h
#ifndef OPERATIONS_H
#define OPERATIONS_H

int incr_mult(int a, int b);   // declaratie

#endif // OPERATIONS_H
```
```cpp
// file: operations.cpp
#include "operations.h"

int incr_mult(int a, int b) {
    // a++ * ++b zou 4 * 6 = 24 geven: a++ levert de OUDE waarde op
    return (++a) * (++b);       // prefix: eerst verhogen, dan gebruiken
}
```
```cpp
// multi: operations.cpp
#include <iostream>             // standaardheader: punthaken
#include "operations.h"         // eigen header: aanhalingstekens

int main() {
    int x {4};
    int y {5};
    int result = incr_mult(x, y);   // (4+1) * (5+1)
    std::cout << "result : " << result << std::endl;
    return 0;
}
```
```text
result : 30
```

#### Pass by value [▶ 15:44:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=56686s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

void say_age(int age);          // declaratie: by value

int main() {
    int age {23};
    std::cout << "age (before call) : " << age << " &age : " << &age << std::endl;
    say_age(age);               // er wordt een kopie van age gemaakt
    std::cout << "age (after call)  : " << age << " &age : " << &age << std::endl;
    return 0;
}

void say_age(int age) {         // age is hier een nieuwe, lokale variabele
    ++age;
    std::cout << "Hello, you are " << age << " years old! &age : " << &age << std::endl;
}
```
Voorbeeldoutput (adressen verschillen per run en per machine):
```text
age (before call) : 23 &age : 0x5ffe9c
Hello, you are 24 years old! &age : 0x5ffe70
age (after call)  : 23 &age : 0x5ffe9c
```
Het adres binnen de functie is anders: het is een kopie. De waarde buiten blijft 23.

#### Pass by pointer [▶ 15:52:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57170s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

void say_age(int* age);         // declaratie: by pointer

int main() {
    int age {23};
    std::cout << "age (before call) : " << age << " &age : " << &age << std::endl;
    say_age(&age);              // adres meegeven
    std::cout << "age (after call)  : " << age << " &age : " << &age << std::endl;
    return 0;
}

void say_age(int* age) {
    ++(*age);                   // dereferencen: wijzigt het origineel
    std::cout << "Hello, you are " << *age << " years old! &age : " << age << std::endl;
}
```
Voorbeeldoutput:
```text
age (before call) : 23 &age : 0x5ffe9c
Hello, you are 24 years old! &age : 0x5ffe9c
age (after call)  : 24 &age : 0x5ffe9c
```
De pointer bevat hetzelfde adres als `&age` in `main`; de wijziging is buiten zichtbaar.

#### Pass by reference [▶ 15:59:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57552s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

void say_age(int& age);         // declaratie: by reference

int main() {
    int age {23};
    std::cout << "age (before call) : " << age << " &age : " << &age << std::endl;
    say_age(age);               // gewoon de variabele, geen &
    std::cout << "age (after call)  : " << age << " &age : " << &age << std::endl;
    return 0;
}

void say_age(int& age) {        // age is een alias voor de variabele in main
    ++age;                      // geen * nodig
    std::cout << "Hello, you are " << age << " years old! &age : " << &age << std::endl;
}
```
Voorbeeldoutput:
```text
age (before call) : 23 &age : 0x5ffe9c
Hello, you are 24 years old! &age : 0x5ffe9c
age (after call)  : 24 &age : 0x5ffe9c
```

#### Drie manieren naast elkaar (controleerbare versie)
> 💡 Aanvulling: dezelfde drie mechanismen zonder adressen, zodat je de output exact kunt voorspellen.
```cpp
#include <iostream>

void by_value(int age)      { ++age; std::cout << "inside by_value : " << age << std::endl; }
void by_pointer(int* age)   { ++(*age); }
void by_reference(int& age) { ++age; }

int main() {
    int a {23};
    int b {23};
    int c {23};
    by_value(a);
    by_pointer(&b);
    by_reference(c);
    std::cout << "by value     : " << a << std::endl;
    std::cout << "by pointer   : " << b << std::endl;
    std::cout << "by reference : " << c << std::endl;
    return 0;
}
```
```text
inside by_value : 24
by value     : 23
by pointer   : 24
by reference : 24
```

### Valkuilen & veelgemaakte fouten

#### Return type vergeten
Een functie zonder return type is in C++ een compilerfout. Ook bij een functie die niets teruggeeft moet je `void` schrijven.

#### Een functie gebruiken vóór de declaratie
Als de aanroep boven de declaratie staat, kent de compiler de functie nog niet (`'max' was not declared in this scope`). Zet een prototype boven `main` of include de juiste header.

#### Alleen een declaratie, geen definitie
Dit geeft geen compilerfout maar een **linkerfout**: `undefined reference to ...` (GCC, herkenbaar aan `ld returned 1 exit status`) of `unresolved external symbol` (MSVC). Controleer of het `.cpp`-bestand met de definitie wel meegecompileerd wordt en of de definitie niet uitgecommentarieerd is.

#### Dubbele definities (ODR)
In één bestand: *redefinition* (compilerfout). Verdeeld over bestanden: *multiple definition* (linkerfout). Let vooral op definities van member functions en static members: die horen in precies één `.cpp`-bestand, niet in een header die overal wordt geïncludeerd en niet als kopie in `main.cpp`.

#### Denken dat return type of parameternamen de signature uniek maken
`int max(int, int)` en `void max(int c, int d)` hebben dezelfde signature. Alleen naam + parametertypes tellen.

#### Een variabele dezelfde naam geven als een functie
`int max = max(34, 56);` verwart de compiler, omdat de lokale variabele `max` de functie verbergt. Kies een andere naam (`maximum`).

#### Ongemerkte impliciete conversies
Een `double` doorgeven aan een `int`-parameter gooit de decimalen weg, zonder foutmelding (met `-Wall -Wextra` zelfs zonder waarschuwing). Kies passende parametertypes, zoals de docent `size_t` koos voor de loopvariabele.

#### Verwachten dat pass by value het origineel wijzigt
Bij `void f(int x)` werk je op een kopie; wijzigingen zijn na de aanroep weg. Wil je het origineel wijzigen, gebruik dan een pointer of reference.

#### Dereferencen vergeten bij pass by pointer
`++age;` op een `int*` verhoogt de **pointer**, niet de waarde, en `std::cout << age` print een adres. Schrijf `++(*age);` en `*age`. Vergeet ook niet `&` bij de aanroep (`say_age(&age)`).

#### Postfix in plaats van prefix
`a++ * ++b` gebruikt de oude waarde van `a`. In `incr_mult` gaf dat 24 in plaats van 30. Gebruik `++a` als je de verhoogde waarde direct nodig hebt.

#### Eigen header met punthaken includen
Gebruik `#include "compare.h"` voor je eigen headers en `#include <iostream>` voor standaardheaders.

### Best practices
- Splits functies in een **declaratie** (in een header of boven `main`) en een **definitie** (in een `.cpp`-bestand); houd `main.cpp` schoon.
- Zet **declaraties in headers**, **definities in `.cpp`-bestanden**, en geef de header een include guard.
- Houd de parameternamen in declaraties, ook al zijn ze optioneel: dat maakt de header zelfdocumenterend.
- Organiseer definities logisch (bijv. `compare.h` ↔ `compare.cpp`), ook al eist C++ dat niet.
- Kies parametertypes die passen bij de data (`unsigned`/`size_t` voor een leeftijd of teller) om conversies te vermijden.
- Gebruik **pass by value** als de functie het origineel niet mag/hoeft te wijzigen en het type klein is; **pass by reference** als je het origineel wilt wijzigen of een kopie wilt vermijden. Pass by reference heeft een schonere syntax dan pass by pointer.
- Lees foutmeldingen goed: zie je `ld` of `LNK`, dan zoek je het probleem in de **linkfase** (ontbrekende of dubbele definitie), niet in de syntax.

### Samenvatting
- De **ODR**: elke variabele en functie heeft precies één definitie in het hele programma; classes mogen in meerdere translation units gedefinieerd worden, maar niet twee keer in dezelfde.
- Een functie bestaat uit return type, naam, parameterlijst en body; `void` betekent geen returnwaarde.
- **Parameters** staan in de definitie, **argumenten** geef je mee bij de aanroep.
- **Signature** = naam + parameters (zonder return type); **prototype** = return type + naam + parameters + `;`.
- Een declaratie moet vóór de aanroep staan; de definitie mag overal staan, ook in een ander bestand.
- Compilatie verloopt in drie fasen: **preprocessing** (includes plakken → translation units), **compilatie** (object files) en **linking** (één binary).
- Ontbrekende definitie → `undefined reference` / `unresolved external symbol`; dubbele definitie → `multiple definition`.
- **Pass by value** maakt een kopie (ander adres); **pass by pointer** geeft een adres door dat je dereferencet; **pass by reference** geeft een alias door (zelfde adres) zonder extra syntax in de body.

### Oefeningen
1. Schrijf een functie `bool is_even(int n)` met de **declaratie boven** `main` en de **definitie onder** `main`. Laat `main` voor de getallen 1 t/m 5 printen of ze even zijn.
2. Schrijf een functie `double average(double a, double b, double c)` en roep hem eerst aan met `double`s en daarna met de `int`s 1, 2 en 4. Print beide resultaten. Wat gebeurt er met de `int`-argumenten?
3. Schrijf drie functies `void triple_value(int x)`, `void triple_pointer(int* x)` en `void triple_reference(int& x)` die hun parameter met 3 vermenigvuldigen. Start in `main` met drie variabelen met waarde 7 en print na de aanroepen hun waarden.
4. Splits twee functies `int rect_area(int w, int h)` en `int rect_perimeter(int w, int h)` over `rectangle.h` (declaraties, met include guard) en `rectangle.cpp` (definities). Gebruik ze in `main` voor een rechthoek van 4 bij 6.
5. Schrijf `void swap_values(int& a, int& b)` die twee variabelen omwisselt, en een versie `void swap_ptr(int* a, int* b)` met pointers. Laat in `main` zien dat beide werken.

<details><summary>Uitwerking</summary>

**Oefening 1**
```cpp
#include <iostream>

bool is_even(int n);                 // declaratie

int main() {
    for (int i {1}; i <= 5; ++i) {
        std::cout << i << (is_even(i) ? " is even" : " is odd") << std::endl;
    }
    return 0;
}

bool is_even(int n) {                // definitie
    return n % 2 == 0;
}
```
```text
1 is odd
2 is even
3 is odd
4 is even
5 is odd
```

**Oefening 2**: de `int`s worden impliciet naar `double` omgezet; dat is hier verliesvrij.
```cpp
#include <iostream>

double average(double a, double b, double c) {
    return (a + b + c) / 3;
}

int main() {
    std::cout << "average(1.5, 2.5, 3.5) : " << average(1.5, 2.5, 3.5) << std::endl;
    std::cout << "average(1, 2, 4)       : " << average(1, 2, 4) << std::endl;   // int -> double
    return 0;
}
```
```text
average(1.5, 2.5, 3.5) : 2.5
average(1, 2, 4)       : 2.33333
```

**Oefening 3**
```cpp
#include <iostream>

void triple_value(int x)      { x *= 3; std::cout << "inside triple_value : " << x << std::endl; }   // kopie
void triple_pointer(int* x)   { *x *= 3; }     // via dereferencen
void triple_reference(int& x) { x *= 3; }      // via alias

int main() {
    int a {7};
    int b {7};
    int c {7};
    triple_value(a);
    triple_pointer(&b);
    triple_reference(c);
    std::cout << "a : " << a << ", b : " << b << ", c : " << c << std::endl;
    return 0;
}
```
```text
inside triple_value : 21
a : 7, b : 21, c : 21
```

**Oefening 4**
```cpp
// file: rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

int rect_area(int w, int h);
int rect_perimeter(int w, int h);

#endif // RECTANGLE_H
```
```cpp
// file: rectangle.cpp
#include "rectangle.h"

int rect_area(int w, int h) {
    return w * h;
}

int rect_perimeter(int w, int h) {
    return 2 * (w + h);
}
```
```cpp
// multi: rectangle.cpp
#include <iostream>
#include "rectangle.h"

int main() {
    std::cout << "area      : " << rect_area(4, 6) << std::endl;
    std::cout << "perimeter : " << rect_perimeter(4, 6) << std::endl;
    return 0;
}
```
```text
area      : 24
perimeter : 20
```

**Oefening 5**
```cpp
#include <iostream>

void swap_values(int& a, int& b) {
    int temp {a};
    a = b;
    b = temp;
}

void swap_ptr(int* a, int* b) {
    int temp {*a};
    *a = *b;
    *b = temp;
}

int main() {
    int x {1};
    int y {2};
    swap_values(x, y);
    std::cout << "after swap_values : x : " << x << ", y : " << y << std::endl;
    swap_ptr(&x, &y);
    std::cout << "after swap_ptr    : x : " << x << ", y : " << y << std::endl;
    return 0;
}
```
```text
after swap_values : x : 2, y : 1
after swap_ptr    : x : 1, y : 2
```
</details>

---

<a id="h12"></a>

## Hoofdstuk 12 – Getting things out of functions (16:03:20 – 16:32:35) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57800s)

### Leerdoelen

Na dit hoofdstuk kun je:

- uitleggen welke twee mechanismen C++ biedt om data **uit** een functie te krijgen: output parameters en de return-waarde;
- het verschil benoemen tussen **input parameters** (data de functie in) en **output parameters** (data de functie uit);
- een output parameter correct opzetten met een niet-`const` reference, of met een pointer;
- uitleggen waarom input parameters meestal `const` zijn en waarom fundamentele types gewoon by value mogen;
- uitleggen wat *return by value* betekent: er wordt (standaard) een kopie van de lokale variabele teruggegeven;
- met adressen aantonen dat een `int` die je teruggeeft een andere variabele is dan de variabele in de aanroeper;
- uitleggen waarom bij een `std::string` het adres binnen en buiten de functie gelijk kan zijn (compileroptimalisatie) en waarom je code daar niet van moet afhangen.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 11 (Functions)**: daar zag je pass by value, pass by pointer en pass by reference. Dit hoofdstuk gebruikt precies die technieken, maar nu met een ander doel: niet om data de functie in te krijgen, maar om resultaten eruit te halen. Ook het `return`-statement en de scope van lokale variabelen komen uit hoofdstuk 11.
- **Hoofdstuk 9 (References)**: een reference is een echte *alias* voor de originele variabele. Daarom zijn wijzigingen via een reference-parameter na afloop van de functie zichtbaar in de aanroeper.
- **Hoofdstuk 8 (Pointers)**: het adres doorgeven met `&` en in de functie *dereferencen* met `*` gebruik je hier voor de pointer-variant van een output parameter. Het printen van adressen met `&variabele` gebruik je om return by value te bewijzen.
- **Hoofdstuk 10 (Strings)**: `std::string` vergelijken met `>` (lexicografisch) en samenvoegen met `+`.
- **Hoofdstuk 4 (Operations on data)**: de ternary/`if`-logica om een maximum te bepalen en relationele operatoren.

### Uitleg

#### Twee manieren om data uit een functie te krijgen

Een functie die alleen iets berekent maar het resultaat niet aan de aanroeper kan geven, is niet erg nuttig. De docent bespreekt in deze twee lessen twee kanalen om data naar buiten te krijgen:

1. **Output parameters**: je geeft de functie een variabele mee (via reference of pointer) waarin de functie het resultaat schrijft. De functie zelf kan `void` teruggeven.
2. **Het return-mechanisme**: de functie geeft een waarde terug met `return`, en de aanroeper vangt die op in een eigen variabele.

Dit hoofdstuk behandelt eerst de output parameters en daarna *return by value*.

[▶ 16:03:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57839s)

#### Input en output parameters

De docent laat drie functies zien: `max_str`, `max_int` en `max_double`. Elke functie heeft drie parameters:

- de **eerste twee** zijn **input parameters**: ze brengen data de functie in;
- de **derde** is de **output parameter**: daarin schrijft de functie het resultaat, zodat de aanroeper het na afloop kan uitlezen.

```
void max_str(const std::string& input1, const std::string& input2, std::string& output);
void max_int(int input1, int input2, int& output);
void max_double(double input1, double input2, double* output);
```

**Waarom werkt dit?** Bij pass by value krijgt de functie een kopie; wat je met die kopie doet, verdwijnt als de functie eindigt. Bij een **reference** werkt de functie direct op de originele variabele van de aanroeper (de reference is een echte alias). Alles wat je in de functie aan `output` toekent, staat dus na de return nog in de variabele die als argument is meegegeven. Met een **pointer** bereik je hetzelfde: de functie krijgt het adres van de originele variabele en schrijft via `*output = ...` naar dat geheugen.

**Waarom geen `const` op de output parameter?** De input parameters van `max_str` zijn `const std::string&`: ze worden niet gekopieerd (efficiënt voor strings) en de functie mag ze niet wijzigen. Bij de output parameter laat je `const` juist bewust weg, want de functie *moet* erin kunnen schrijven. Zou je de derde parameter `const` maken, dan geeft de toekenning `output = input1;` een compilerfout.

De docent vat het samen in een paar regels:

- Output parameters moet je zo doorgeven dat de functie het argument kan **wijzigen**: via een reference of via een pointer. In modern C++ gaat de **voorkeur naar references**.
- Input parameters zijn niet bedoeld om gewijzigd te worden; daarom zie je ze in de meeste gevallen als `const` gemarkeerd. Wil je ze toch in de functie aanpassen, dan kun je de `const` weghalen.

[▶ 16:07:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58029s)

#### Output parameter via reference: `max_str`

In VS Code (project "input and output parameters") zet de docent eerst `max_str` op. De functie vergelijkt twee strings: is `input1 > input2`, dan wordt `input1` in `output` geschreven, anders `input2`. Omdat `output` een reference is, werkt de functie op de originele variabele in `main`.

In `main` maakt hij drie `std::string`-variabelen (en voegt `#include <string>` toe): `out_str` als outputvariabele en twee inputs, `"Alabama"` en `"Bellevue"`. De aanroep `max_str(in_str1, in_str2, out_str);` gebruikt het return-mechanisme helemaal niet; het resultaat komt via de derde parameter naar buiten. Daarna print hij `out_str`: dat is `Bellevue`. Verandert hij de eerste input in `"Casablanca"`, dan is het maximum `Casablanca`.

> 💡 Aanvulling: `>` op `std::string` vergelijkt **lexicografisch** (teken voor teken, op basis van de tekencodes). `"Bellevue" > "Alabama"` omdat `'B'` na `'A'` komt; `"Casablanca" > "Bellevue"` omdat `'C'` na `'B'` komt. Let op: hoofdletters komen in ASCII vóór kleine letters, dus `"apple" > "Zebra"` is `true`.

[▶ 16:08:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58125s)

#### Output parameter via reference met fundamentele types: `max_int`

Het tweede voorbeeld lijkt sterk op `max_str`, met één verschil: de inputs zijn **geen references** maar gewone waarden (`int input1, int input2`). Fundamentele types zijn klein in het geheugen, dus kopiëren is goedkoop; pass by value is hier helemaal niet verspillend. Alleen de **derde parameter** moet by reference, omdat die als output dient.

In `main`: `int out_int;`, `int in_int1{45};`, `int in_int2{23};`, dan `max_int(in_int1, in_int2, out_int);` en printen. Resultaat: `45`. Zet de docent een grotere waarde in de tweede variabele, dan komt die eruit.

De docent wijst erop dat deze techniek veel voorkomt, vooral in C++-code die moet samenwerken met **C-code**: C kent geen references en geeft vaak meerdere resultaten terug via pointer-parameters.

[▶ 16:11:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58270s)

#### Output parameter via pointer: `max_double`

Je kunt hetzelfde effect bereiken met een **pointer**. `max_double` krijgt twee `double`-inputs by value en een `double* output`. In de functie moet je de pointer **dereferencen** om naar de variabele van de aanroeper te schrijven: `*output = input1;`.

Bij de aanroep geef je het **adres** van de outputvariabele mee: `max_double(in_double1, in_double2, &out_double);`. Met `45.8` en `6.9` is het resultaat `45.8`; zet de docent de tweede waarde op `76.9`, dan wordt dat het maximum. (Onderweg vergeet hij een puntkomma achter de functie-aanroep; de squiggly line in VS Code wijst je daarop.)

Het principe blijft gelijk: de functie schrijft naar het geheugen van een variabele die buiten de functie leeft, dus de wijziging blijft bestaan nadat de functie terugkeert.

[▶ 16:14:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58461s)

#### Returning from functions by value

De tweede les behandelt het **return-mechanisme** als alternatief voor output parameters. Het basisvoorbeeld:

```
int sum(int a, int b) {
    int result = a + b;   // lokale variabele van sum
    return result;        // waarde gaat naar de aanroeper
}
```

- `result` in `sum` is **lokaal**: hij wordt vernietigd zodra de functie eindigt.
- In `main` staat ook een variabele `result`, maar dat is een **heel andere variabele**: hij leeft in een andere scope.
- `int result = sum(a, b);` in `main`: de functie berekent de som, geeft die terug, en de waarde wordt in de lokale variabele van `main` opgeslagen. Met `34` en `16` krijg je `50`.

**Return by value** betekent: de waarde die je teruggeeft, wordt **gekopieerd** naar de variabele van de aanroeper. De docent bewijst dat door het adres van `result` binnen `sum` te printen en daarna het adres van `result` in `main`. Die adressen zijn verschillend: het zijn twee aparte variabelen, en het return-mechanisme kopieert de waarde van de ene naar de andere.

Of een functie by value teruggeeft, zie je aan het return-type: staat er geen pointer- of reference-decoratie bij (`int`, `std::string`), dan is het return by value.

[▶ 16:17:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58655s)

#### Demo in VS Code: `sum` met adressen

In het project "returning from functions by value" werkt de docent met `int x{5}` en `int y{9}` en `int result = sum(x, y);`. De inputs gaan by value, omdat kopiëren van een `int` goedkoop is. In de functie print hij `In : &result(int) : ...` en in `main` `Out : &result(int) : ...` (hij moet het label "in" eerst nog veranderen in "out"). Bij hem eindigt het adres binnen de functie op `dac` en buiten op `de4`: twee verschillende geheugenadressen, dus twee verschillende variabelen. Daarna print hij ook het resultaat: `14`, en met `15` en `9` wordt het `24`.

[▶ 16:24:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59046s)

#### De uitzondering: de compiler optimaliseert de kopie weg

Return by value is het **standaardgedrag**, maar de docent laat zien dat de compiler soms slimmer is. In `add_strings` worden twee strings met `+` samengevoegd in een lokale variabele `result`, wordt het adres van die lokale string geprint en wordt `result` teruggegeven. In `main`: `std::string in_str1{"Hello"};`, `std::string in_str2{" World"};`, `std::string result_str = add_strings(in_str1, in_str2);`, en dan het adres van `result_str` en de string zelf printen.

Resultaat: het adres **binnen** de functie en het adres **buiten** de functie zijn **gelijk** (bij de docent beide eindigend op `d30`). Dat lijkt in tegenspraak met "return by value maakt een kopie".

De uitleg van de docent:

- De compiler ziet dat de lokale `result` in de functie direct na de return toch zou sterven. Een kopie maken van iets dat meteen wordt weggegooid is verspilling, zeker als de string bijvoorbeeld duizend tekens bevat.
- Daarom hergebruikt de compiler hetzelfde geheugen: hij laat het *lijken* alsof je by reference teruggeeft, zonder dat er een kopie wordt gemaakt.
- Het is **geen echte return by reference**: een reference naar een lokale variabele teruggeven zou gevaarlijk zijn, omdat die variabele na de return dood is. Het is een optimalisatie die de compiler achter de schermen doet.
- De boodschap: **laat je code er niet van afhangen** dat return by value altijd een kopie maakt. De compiler mag de kopie weglaten wanneer hij ziet dat hij het beter kan.

> 💡 Aanvulling: deze optimalisatie heet **copy elision**, in dit geval **NRVO** (*Named Return Value Optimization*): de compiler construeert de lokale variabele direct op de plek van de variabele van de aanroeper. Sinds C++17 is copy elision **gegarandeerd** wanneer je een tijdelijke waarde teruggeeft (`return a + b;`, RVO); bij een benoemde lokale variabele (NRVO, zoals hier) mag de compiler het doen maar is het niet verplicht. Bij de `int` in `sum` zie je geen gedeeld adres omdat een kleine `int` meestal via een register wordt teruggegeven, en omdat het adres-printen de variabele in het stackframe van `sum` dwingt.

> 💡 Aanvulling: "Niet afhankelijk zijn van returning by value" moet je lezen als: ga er niet van uit dat er een kopie gemaakt wordt (bijvoorbeeld omdat je op aparte adressen of op bijwerkingen van kopiëren rekent). Returnen by value is in modern C++ juist de gebruikelijke en aanbevolen manier om resultaten terug te geven, ook voor grote objecten zoals `std::string` en `std::vector`: dankzij copy elision en move semantics is dat goedkoop.

[▶ 16:27:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59238s) · [▶ 16:30:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59429s)

### Codevoorbeelden

#### Output parameter via reference: max_str [▶ 16:08:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58125s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

// input1 en input2: input parameters (const, niet kopiëren)
// output: output parameter (niet-const reference, wordt beschreven)
void max_str(const std::string& input1, const std::string& input2, std::string& output) {
    if (input1 > input2) {
        output = input1;   // schrijft in de originele variabele van de aanroeper
    } else {
        output = input2;
    }
}

int main() {
    std::string out_str;
    std::string in_str1{"Alabama"};
    std::string in_str2{"Bellevue"};

    max_str(in_str1, in_str2, out_str);   // geen return: resultaat komt via out_str
    std::cout << "max_str : " << out_str << std::endl;

    in_str1 = "Casablanca";
    max_str(in_str1, in_str2, out_str);
    std::cout << "max_str : " << out_str << std::endl;

    return 0;
}
```

```text
max_str : Bellevue
max_str : Casablanca
```

#### Output parameter by reference met int: max_int [▶ 16:11:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58270s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

// Fundamentele types: inputs gewoon by value (kopiëren is goedkoop)
// Alleen de output parameter moet een reference zijn
void max_int(int input1, int input2, int& output) {
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

int main() {
    int out_int;          // wordt door max_int ingevuld
    int in_int1{45};
    int in_int2{23};

    max_int(in_int1, in_int2, out_int);
    std::cout << "max_int : " << out_int << std::endl;

    in_int2 = 99;         // nu is de tweede input het maximum
    max_int(in_int1, in_int2, out_int);
    std::cout << "max_int : " << out_int << std::endl;

    return 0;
}
```

```text
max_int : 45
max_int : 99
```

#### Output parameter via pointer: max_double [▶ 16:14:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58461s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

// Output parameter als pointer: de aanroeper geeft een adres mee
void max_double(double input1, double input2, double* output) {
    if (input1 > input2) {
        *output = input1;   // dereferencen: schrijven naar de variabele van de aanroeper
    } else {
        *output = input2;
    }
}

int main() {
    double out_double;
    double in_double1{45.8};
    double in_double2{6.9};

    max_double(in_double1, in_double2, &out_double);   // adres van out_double meegeven
    std::cout << "max_double : " << out_double << std::endl;

    in_double2 = 76.9;
    max_double(in_double1, in_double2, &out_double);
    std::cout << "max_double : " << out_double << std::endl;

    return 0;
}
```

```text
max_double : 45.8
max_double : 76.9
```

#### Const op de output parameter geeft een compilerfout [▶ 16:04:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=57886s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: output is const, dus de toekenning compileert niet
#include <iostream>
#include <string>

void max_str(const std::string& input1, const std::string& input2, const std::string& output) {
    if (input1 > input2) {
        output = input1;   // error: passing 'const std::string' as 'this' argument discards qualifiers
    } else {
        output = input2;
    }
}

int main() {
    std::string out_str;
    max_str("Alabama", "Bellevue", out_str);
    std::cout << out_str << std::endl;
    return 0;
}
```

#### Return by value met int: twee verschillende adressen [▶ 16:24:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59046s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

int sum(int a, int b) {
    int result = a + b;                                   // lokaal in sum
    std::cout << "In : &result(int) : " << &result << std::endl;
    return result;                                        // waarde wordt gekopieerd
}

int main() {
    int x{5};
    int y{9};

    int result = sum(x, y);                               // andere variabele, andere scope
    std::cout << "Out : &result(int) : " << &result << std::endl;
    std::cout << "result : " << result << std::endl;

    return 0;
}
```

Voorbeeldoutput (adressen verschillen per run en per systeem; belangrijk is dat ze **verschillend** zijn):

```text
In : &result(int) : 0x5ffe5c
Out : &result(int) : 0x5ffe8c
result : 14
```

#### Return by value met std::string: de compiler hergebruikt het adres [▶ 16:27:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59238s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>
#include <string>

std::string add_strings(const std::string& str1, const std::string& str2) {
    std::string result = str1 + str2;                     // lokale string
    std::cout << "In : &result(std::string) : " << &result << std::endl;
    return result;                                        // by value, maar kopie kan wegvallen
}

int main() {
    std::string in_str1{"Hello"};
    std::string in_str2{" World"};

    std::string result_str = add_strings(in_str1, in_str2);
    std::cout << "Out : &result_str(std::string) : " << &result_str << std::endl;
    std::cout << "result_str : " << result_str << std::endl;

    return 0;
}
```

Voorbeeldoutput (met GCC zijn beide adressen doorgaans **gelijk** door NRVO):

```text
In : &result(std::string) : 0x5ffe30
Out : &result_str(std::string) : 0x5ffe30
result_str : Hello World
```

#### Beide technieken naast elkaar [▶ 16:17:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=58655s)

> 💡 Aanvulling: dit vergelijkingsprogramma combineert de twee lessen; de docent typt het niet zo.

```cpp
#include <iostream>

// Variant 1: resultaat via output parameter
void sum_out(int a, int b, int& output) {
    output = a + b;
}

// Variant 2: resultaat via return by value
int sum_ret(int a, int b) {
    return a + b;
}

int main() {
    int a{34};
    int b{16};

    int r1;
    sum_out(a, b, r1);          // r1 wordt in de functie ingevuld
    int r2 = sum_ret(a, b);     // r2 krijgt de teruggegeven waarde

    std::cout << "via output parameter : " << r1 << std::endl;
    std::cout << "via return           : " << r2 << std::endl;
    return 0;
}
```

```text
via output parameter : 50
via return           : 50
```

### Valkuilen & veelgemaakte fouten

#### Output parameter by value doorgeven

Vergeet je de `&` bij de output parameter (`void max_int(int a, int b, int output)`), dan schrijft de functie in een **kopie**. Het programma compileert gewoon, maar de variabele in `main` blijft ongewijzigd (en is mogelijk zelfs niet geïnitialiseerd). GCC waarschuwt hooguit dat de parameter gezet maar niet gebruikt wordt.

#### Const op een output parameter

Een output parameter met `const` (`const std::string& output`) kan niet beschreven worden: de toekenning geeft een compilerfout. `const` hoort bij de **input** parameters, niet bij de output.

#### Pointer-output: dereferencen of adres vergeten

Bij een pointer-parameter moet je in de functie `*output = ...` schrijven, niet `output = ...` (dan wijzig je alleen de lokale pointer-kopie, of krijg je een typefout). En bij de aanroep moet je `&out_double` meegeven, niet `out_double`. De docent vergat ook nog een puntkomma achter de aanroep: let op de squiggly lines in de editor.

> 💡 Aanvulling: bij een pointer-parameter kan de aanroeper `nullptr` meegeven. Dereferencen van een null-pointer is undefined behavior; daarom is een reference (die altijd aan een bestaand object gekoppeld is) veiliger en heeft die de voorkeur.

#### Lokale variabele en variabele in main door elkaar halen

`result` in `sum` en `result` in `main` hebben dezelfde naam, maar het zijn **verschillende variabelen** in verschillende scopes. De lokale variabele van de functie bestaat niet meer na de return; alleen de teruggegeven waarde komt naar buiten.

#### Ervan uitgaan dat return by value altijd kopieert

Bij `add_strings` blijkt het adres binnen en buiten gelijk. Schrijf geen code die afhankelijk is van het maken van een kopie bij het returnen: de compiler mag die kopie weglaten.

#### Een reference naar een lokale variabele teruggeven

De docent benadrukt dat de compiler-optimalisatie *geen* echte return by reference is, omdat een reference naar een lokale variabele na de return naar een dode variabele zou wijzen.

> 💡 Aanvulling: `std::string& f() { std::string s{"x"}; return s; }` compileert (met een warning `reference to local variable 's' returned`), maar gebruik van het resultaat is undefined behavior. Return by reference komt in een later deel van de cursus aan bod; geef nooit een reference of pointer naar een lokale variabele terug.

#### Labels in de debug-output niet aanpassen

Klein maar herkenbaar: de docent kopieert de print-regel van "in" en vergeet twee keer "In" te veranderen in "Out". Daardoor lijkt het alsof beide adressen binnen de functie geprint zijn. Controleer je labels als je adressen vergelijkt.

### Best practices

- Gebruik voor output parameters bij voorkeur een **niet-`const` reference**; pointers alleen als het nodig is (bijvoorbeeld bij samenwerking met C-code).
- Markeer **input parameters** als `const` (en bij grote types zoals `std::string` als `const` reference, zodat er niet gekopieerd wordt).
- Geef **fundamentele types** (`int`, `double`, `char`, ...) als input gewoon **by value** door: kopiëren is goedkoop.
- Zet output parameters herkenbaar achteraan in de parameterlijst en geef ze een duidelijke naam (`output`, `out_...`), zoals de docent doet.
- Gebruik het **return-mechanisme** wanneer een functie één resultaat oplevert; de aanroeper kan het dan direct in een variabele opvangen.
- Laat je code niet afhangen van het wel of niet kopiëren bij return by value; de compiler kan optimaliseren.

> 💡 Aanvulling: de C++ Core Guidelines (F.20) adviseren om voor "uitvoer"-waarden bij voorkeur return values te gebruiken in plaats van output parameters. Meerdere waarden teruggeven kan met een `struct` of `std::pair`/`std::tuple`. Output parameters blijven nuttig bij C-API's of als je een bestaand groot object wilt hergebruiken.

### Samenvatting

- Er zijn twee manieren om data uit een functie te krijgen: **output parameters** en het **return-mechanisme**.
- Input parameters brengen data de functie in en zijn meestal `const`; output parameters brengen data naar buiten en zijn juist **niet** `const`.
- Een output parameter werkt omdat de functie via een **reference** (alias) of **pointer** (adres) op de originele variabele van de aanroeper schrijft.
- In modern C++ gaat de voorkeur naar references boven pointers voor output parameters.
- Fundamentele types mag je als input by value doorgeven; kopiëren kost bijna niets.
- Bij een pointer-output schrijf je `*output = ...` en geef je bij de aanroep `&variabele` mee.
- **Return by value** is het standaardgedrag als het return-type geen pointer of reference is: de lokale waarde wordt naar de variabele van de aanroeper gekopieerd (bij `int` zie je verschillende adressen).
- De compiler kan die kopie **wegoptimaliseren** (bij `std::string` gelijke adressen); dat is geen echte return by reference.
- Laat je code niet afhangen van het maken van kopieën bij returnen.

### Oefeningen

1. Schrijf een functie `void min_int(int a, int b, int& output)` die het minimum van twee getallen in `output` zet. Test met `12` en `7`, en daarna met `3` en `20`.
2. Schrijf een functie `void min_max(int a, int b, int& smallest, int& largest)` die via **twee** output parameters zowel het minimum als het maximum teruggeeft. Test met `8` en `3`.
3. Herschrijf `max_double` zodat de output parameter een reference is in plaats van een pointer, en laat zien dat het resultaat gelijk blijft. Print bovendien met een tweede functie `double max_double_ret(double a, double b)` hetzelfde maximum via `return`.
4. Schrijf `void longest(const std::string& s1, const std::string& s2, std::string& output)` die de **langste** string in `output` zet (bij gelijke lengte `s1`), en een functie `std::string shout(const std::string& s)` die de string met een uitroepteken erachter teruggeeft (return by value). Combineer ze: zoek de langste van `"cat"` en `"giraffe"` en print `shout` van het resultaat.

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

void min_int(int a, int b, int& output) {
    if (a < b) {
        output = a;
    } else {
        output = b;
    }
}

int main() {
    int result;
    min_int(12, 7, result);
    std::cout << "min : " << result << std::endl;
    min_int(3, 20, result);
    std::cout << "min : " << result << std::endl;
    return 0;
}
```

```text
min : 7
min : 3
```

Oefening 2:

```cpp
#include <iostream>

// Twee output parameters: meerdere resultaten uit één functie
void min_max(int a, int b, int& smallest, int& largest) {
    if (a < b) {
        smallest = a;
        largest = b;
    } else {
        smallest = b;
        largest = a;
    }
}

int main() {
    int lo;
    int hi;
    min_max(8, 3, lo, hi);
    std::cout << "smallest : " << lo << ", largest : " << hi << std::endl;
    return 0;
}
```

```text
smallest : 3, largest : 8
```

Oefening 3:

```cpp
#include <iostream>

// Output parameter als reference: geen * en geen & bij de aanroep nodig
void max_double(double input1, double input2, double& output) {
    output = (input1 > input2) ? input1 : input2;
}

// Hetzelfde via return by value
double max_double_ret(double input1, double input2) {
    return (input1 > input2) ? input1 : input2;
}

int main() {
    double out_double;
    max_double(45.8, 76.9, out_double);
    std::cout << "via reference : " << out_double << std::endl;
    std::cout << "via return    : " << max_double_ret(45.8, 76.9) << std::endl;
    return 0;
}
```

```text
via reference : 76.9
via return    : 76.9
```

Oefening 4:

```cpp
#include <iostream>
#include <string>

void longest(const std::string& s1, const std::string& s2, std::string& output) {
    if (s2.size() > s1.size()) {
        output = s2;
    } else {
        output = s1;   // ook bij gelijke lengte
    }
}

std::string shout(const std::string& s) {
    std::string result = s + "!";
    return result;     // return by value
}

int main() {
    std::string winner;
    longest("cat", "giraffe", winner);
    std::cout << shout(winner) << std::endl;
    return 0;
}
```

```text
giraffe!
```

</details>

---

<a id="h13"></a>

## Hoofdstuk 13 – Function overloading (16:32:35 – 16:49:00) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59555s)

### Leerdoelen

- Begrijpen wat function overloading is: meerdere functies met **dezelfde naam** maar een **verschillende parameterlijst**.
- Weten waarom overloading bestaat: code die prettiger leest en schrijft, omdat je niet voor elk type een andere functienaam hoeft te verzinnen (`max_int`, `max_double`, ...).
- Kennen van de regel dat het **return type niet meetelt** in de signature van een functie, en dus nooit genoeg is om twee overloads van elkaar te onderscheiden.
- Overloads kunnen maken door te variëren in:
  - het **type** van de parameters,
  - de **volgorde** van de parameters (met verschillende types),
  - het **aantal** parameters.
- Begrijpen hoe de compiler bij een aanroep de "best passende" overload kiest, inclusief een **impliciete conversie** zoals string literal → `std::string_view`.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 11 (Functions)**: daar leerde je functies declareren en definiëren, en de One Definition Rule (ODR). Overloading lijkt in eerste instantie de ODR te schenden ("twee functies met dezelfde naam?"), maar dat is niet zo: voor de compiler zijn het verschillende functies, omdat hun **signature** verschilt (naam + parameterlijst).
- **Hoofdstuk 11/12 (pass by value, return by value)**: alle overloads in dit hoofdstuk nemen hun parameters by value en geven hun resultaat by value terug, precies zoals eerder behandeld.
- **Hoofdstuk 3 (`auto`)**: de docent gebruikt `auto result = max(x, y);` – het type van `result` wordt afgeleid uit het return type van de overload die de compiler kiest.
- **Hoofdstuk 10 (strings)**: `std::string` en `std::string_view` komen terug als parametertypes; een string literal (`"Hello"`) is een `const char`-array die impliciet naar `std::string_view` kan converteren.
- **Vooruitblik**: in hoofdstuk 15 (function templates) zie je een alternatief voor het met de hand uitschrijven van een overload per type: de compiler genereert de overloads dan zelf.

### Uitleg

#### Wat is function overloading?

Function overloading is een mechanisme in C++ waarmee je **meerdere verschillende functies** kunt maken die **allemaal dezelfde naam** hebben. Zulke functies heten *overloads* van elkaar.

Het probleem dat het oplost: stel dat je het maximum wilt bepalen van twee `int`s, van twee `double`s en van twee strings. Zonder overloading zou je drie namen nodig hebben (`max_int`, `max_double`, `max_string`) en moet de programmeur bij elke aanroep zelf de juiste kiezen. Met overloading heten ze alle drie `max`, en **de compiler kiest bij elke aanroep zelf de best passende overload** op basis van de argumenten die je meegeeft:

- `max(x, y)` met `int`-argumenten → de `int`-overload;
- `max(s1, s2)` met `std::string`-argumenten → de `std::string`-overload.

Je hoeft je als aanroeper dus niet druk te maken over "welke versie heb ik nodig?" – dat maakt de code flexibel en makkelijk te gebruiken. Er gelden wel een paar regels om overloads correct op te zetten; die volgen hieronder.

Tijdlink: [▶ 16:32:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59574s)

#### De signature: naam + parameters, níét het return type

Wat twee functies voor de compiler "verschillend" maakt, is hun **signature**. Die bestaat uit:

- de **functienaam**, en
- de **parameterlijst** (types, volgorde, aantal).

Het **return type hoort er niet bij**. Als je twee functies `max` maakt met exact dezelfde parameters en alleen een ander return type, weigert de compiler dat:

```
int    max(int a, int b);
double max(int a, int b);   // fout: alleen het return type verschilt
```

De docent laat dit zien door de `int`-versie te kopiëren en alleen het return type te veranderen. VS Code toont meteen een rode kronkel, en de compiler meldt (MSVC/IntelliSense-formulering) iets als *"cannot overload functions distinguished by return type alone"*. GCC zegt: *"ambiguating new declaration of 'double max(int, int)'"*. De boodschap is helder: het return type is niet genoeg.

Waarom niet? Bij een aanroep als `max(4, 9);` (waarbij je het resultaat misschien niet eens gebruikt) kan de compiler aan de aanroep niet zien welk return type je bedoelt. Alleen de argumenten zijn zichtbaar, dus alleen de parameters kunnen de keuze bepalen.

Tijdlinks: [▶ 16:34:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59669s), [▶ 16:38:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59913s)

#### Overloaden op het type van de parameters

De eerste (en meest gebruikte) manier: geef de parameters een ander **type**. Naast `int max(int a, int b)` maak je `double max(double a, double b)`. Dat is geldige C++: het zijn twee verschillende functies met dezelfde naam.

- Roep je `max` aan met twee `int`s (variabelen of literals zoals `max(10, 20)`), dan kiest de compiler de `int`-overload.
- Roep je `max` aan met twee `double`s, dan kiest hij de `double`-overload.

De docent bewijst dit door in elke overload een regel te printen (`"int overload called"`, `"double overload called"`). Met `int x{4}, y{9}` en `double a{5.4}, b{7.4}` levert `auto result = max(x, y);` de tekst `int overload called` op, en `max(a, b)` geeft `double overload called`. Omdat `result` als `auto` gedeclareerd is, is het type ervan het return type van de gekozen overload: `int` bij de eerste aanroep, `double` bij de tweede. Om de `double`-overload consistent te maken past de docent ook het return type aan naar `double`. Dat mag gewoon: het return type mag per overload verschillen, het telt alleen niet mee om ze van elkaar te onderscheiden.

Tijdlinks: [▶ 16:39:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59962s), [▶ 16:40:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60059s)

#### Overloaden op de volgorde van de parameters

Als de parameters verschillende types hebben, maakt ook de **volgorde** verschil:

```
double max(int a, double b);   // (int, double)
double max(double a, int b);   // (double, int)
```

Dat zijn twee verschillende parameterlijsten en dus twee geldige overloads. Samen met `(int, int)` en `(double, double)` heeft `max` nu vier overloads.

- `max(x, b)` → `x` is `int`, `b` is `double` → de `(int, double)`-overload: `int double overload called`.
- `max(b, x)` → omgedraaid → de `(double, int)`-overload: `double int overload called`.

De docent benadrukt dat dit voorbeeld op zich vrij nutteloos is: hij raadt je niet aan om zulke "rare" overloads te maken. Het gaat erom dat je weet dát het kan, zodat je het kunt inzetten wanneer het in je eigen applicatie zinvol is.

Tijdlinks: [▶ 16:42:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60154s), [▶ 16:44:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60252s)

#### Overloaden op het aantal parameters

De derde manier: een ander **aantal** parameters. De docent maakt een overload die er voor de eerste twee parameters uitziet als `(double, int)`, maar met een derde parameter `int c` erbij:

```
double max(double a, int b, int c);
```

Hij werkt niet uit hoe je het maximum van drie waarden berekent (hij geeft gewoon `a` terug); het gaat alleen om het feit dat dit een geldige overload is. De aanroep `max(b, x, y)` – een `double` en twee `int`s – kiest deze overload, en de uitvoer is `double int int overload called`.

Samengevat kun je overloads dus onderscheiden door:

1. andere **types** van de parameters,
2. een andere **volgorde** van parameters (met verschillende types),
3. een ander **aantal** parameters.

Tijdlinks: [▶ 16:45:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60301s), [▶ 16:46:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60396s)

#### Overload met `std::string_view` en impliciete conversie

Als laatste voegt de docent een overload toe die twee `std::string_view`-parameters neemt en de "grootste" (lexicografisch) teruggeeft:

```
std::string_view max(std::string_view a, std::string_view b);
```

Bij de aanroep `max("Hello", "World")` gebeurt het volgende onder de motorkap:

1. De compiler zoekt eerst een overload die precies twee **character arrays** (string literals, type `const char[6]`) als parameters neemt. Die bestaat niet.
2. Daarna kijkt hij welke overloads hij kan bereiken via **impliciete conversies**. Een string literal kan impliciet geconverteerd worden naar `std::string_view`.
3. De compiler voegt die conversie automatisch in en roept de `string_view`-overload aan: `string_view string_view overload called`.

Hetzelfde geldt natuurlijk als je `max` aanroept met twee `std::string_view`-variabelen: dan is het een exacte match.

> 💡 Aanvulling: de keuze van de overload heet *overload resolution*. Grofweg rangschikt de compiler de kandidaten: een exacte match wint van een promotie (bv. `float` → `double`), die wint weer van een conversie (bv. `int` → `double`, of string literal → `std::string_view`). Zijn er twee kandidaten even goed, dan is de aanroep **ambigu** en krijg je een compilerfout (zie Valkuilen).

Tijdlinks: [▶ 16:36:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59817s), [▶ 16:47:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60444s), [▶ 16:48:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60492s)

### Codevoorbeelden

#### Introductie: `max` voor `int` en `std::string` [▶ 16:32:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59574s)

In de introductie laat de docent op een slide zien dat dezelfde naam `max` voor verschillende types kan werken; de compiler kiest de juiste overload.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

// overload 1: twee ints
int max(int a, int b) {
    return (a > b) ? a : b;
}

// overload 2: twee std::strings (zelfde naam, andere parametertypes)
std::string max(const std::string& a, const std::string& b) {
    return (a > b) ? a : b;
}

int main() {
    int x{3};
    int y{8};
    std::string s1{"apple"};
    std::string s2{"banana"};

    std::cout << max(x, y) << '\n';   // compiler kiest max(int, int)
    std::cout << max(s1, s2) << '\n'; // compiler kiest max(std::string, std::string)
    return 0;
}
```

```text
8
banana
```

#### Return type alleen is niet genoeg [▶ 16:38:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59913s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: twee functies die alleen in return type verschillen
#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// fout: "cannot overload functions distinguished by return type alone"
double max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(4, 9) << '\n';
    return 0;
}
```

Dit programma compileert niet. De oplossing is de parameterlijst te veranderen, zoals in het volgende voorbeeld.

#### Overloads op type: `int` en `double` [▶ 16:39:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=59962s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int max(int a, int b) {
    std::cout << "int overload called" << '\n';
    return (a > b) ? a : b;
}

double max(double a, double b) {
    std::cout << "double overload called" << '\n';
    return (a > b) ? a : b;
}

int main() {
    int x{4};
    int y{9};
    double a{5.4};
    double b{7.4};

    auto result = max(x, y);   // int-argumenten -> int-overload, result is int
    std::cout << "result: " << result << '\n';

    auto result2 = max(a, b);  // double-argumenten -> double-overload, result2 is double
    std::cout << "result2: " << result2 << '\n';

    max(10, 20);               // int literals -> int-overload
    return 0;
}
```

```text
int overload called
result: 9
double overload called
result2: 7.4
int overload called
```

#### Overloads op volgorde en aantal parameters [▶ 16:43:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60203s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

int max(int a, int b) {
    std::cout << "int overload called" << '\n';
    return (a > b) ? a : b;
}

double max(double a, double b) {
    std::cout << "double overload called" << '\n';
    return (a > b) ? a : b;
}

// zelfde types, andere volgorde -> twee verschillende overloads
double max(int a, double b) {
    std::cout << "int double overload called" << '\n';
    return (a > b) ? a : b;
}

double max(double a, int b) {
    std::cout << "double int overload called" << '\n';
    return (a > b) ? a : b;
}

// ander aantal parameters -> ook een geldige overload
double max(double a, int b, int c) {
    std::cout << "double int int overload called" << '\n';
    // de docent werkt de berekening niet uit en geeft gewoon a terug
    (void)b;   // voorkomt waarschuwing "unused parameter"
    (void)c;
    return a;
}

int main() {
    int x{4};
    int y{9};
    double b{7.4};

    max(x, b);      // (int, double)
    max(b, x);      // (double, int)
    max(b, x, y);   // (double, int, int)
    return 0;
}
```

```text
int double overload called
double int overload called
double int int overload called
```

#### Overload met `std::string_view` en string literals [▶ 16:47:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60444s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string_view>

int max(int a, int b) {
    std::cout << "int overload called" << '\n';
    return (a > b) ? a : b;
}

double max(double a, double b) {
    std::cout << "double overload called" << '\n';
    return (a > b) ? a : b;
}

std::string_view max(std::string_view a, std::string_view b) {
    std::cout << "string_view string_view overload called" << '\n';
    return (a > b) ? a : b;
}

int main() {
    std::string_view s1{"Hello"};
    std::string_view s2{"World"};

    std::cout << max(s1, s2) << '\n';           // exacte match: string_view-overload

    // geen overload voor twee char-arrays; de compiler converteert
    // de string literals impliciet naar std::string_view
    std::cout << max("Hello", "World") << '\n';
    return 0;
}
```

```text
string_view string_view overload called
World
string_view string_view overload called
World
```

### Valkuilen & veelgemaakte fouten

#### Alleen het return type veranderen

`int max(int, int)` en `double max(int, int)` naast elkaar is een compilerfout. Het return type maakt geen deel uit van de signature. Verander altijd iets aan de **parameterlijst** (type, volgorde of aantal).

#### Volgorde veranderen bij gelijke types helpt niet

> 💡 Aanvulling: `max(int a, double b)` en `max(double a, int b)` zijn verschillende overloads, maar `max(int a, int b)` en `max(int b, int a)` niet: alleen de **types** in de lijst tellen, niet de namen van de parameters. Ook andere parameternamen maken geen nieuwe overload.

#### Ambigue aanroepen

> 💡 Aanvulling: als er geen exacte match is en meerdere overloads even goed bereikbaar zijn via conversies, weet de compiler niet welke hij moet kiezen en geeft hij een fout ("call of overloaded ... is ambiguous").

```cpp
// ❌ bewust fout: ambigue aanroep
#include <iostream>

int max(int a, int b) { return (a > b) ? a : b; }
double max(double a, double b) { return (a > b) ? a : b; }

int main() {
    // 4 is int, 5.5 is double: max(int,int) en max(double,double)
    // vergen allebei één conversie -> ambigu
    std::cout << max(4, 5.5) << '\n';
    return 0;
}
```

Oplossing: zorg dat de argumenten exact passen (bv. `max(4.0, 5.5)`), gebruik een expliciete conversie (`static_cast<double>(4)`), of voeg een overload toe die wel exact past (zoals de docent met `max(int, double)` deed).

#### Verwachten dat de "logische" overload wordt gekozen bij literals

De literal `5.4` is een `double`, `5.4f` een `float`, `4` een `int` en `"Hello"` een `const char`-array (geen `std::string` of `std::string_view`!). Welke overload gekozen wordt, hangt af van deze exacte types. Bij `max("Hello", "World")` werkt het alleen omdat er een impliciete conversie naar `std::string_view` bestaat.

#### Ongebruikte parameters in een "demo-overload"

> 💡 Aanvulling: een overload die parameters neemt maar niet gebruikt (zoals de drie-parameterversie van de docent die gewoon `a` teruggeeft) geeft met `-Wextra` een waarschuwing *unused parameter*. Gebruik de parameters, laat hun naam weg, of markeer ze met `[[maybe_unused]]`.

### Best practices

- Gebruik overloading alleen als de functies **conceptueel hetzelfde** doen (bv. "maximum bepalen") voor verschillende soorten invoer. Totaal verschillende functionaliteit verdient een andere naam.
- Vermijd "rare" overloads zoals `(int, double)` naast `(double, int)` tenzij ze echt iets toevoegen; de docent gebruikt ze alleen om het mechanisme te tonen.
- Houd het return type logisch per overload (de docent past het return type van de `double`-versie aan naar `double` voor consistentie).
- Wees bewust van impliciete conversies: ze maken aanroepen zoals `max("Hello", "World")` mogelijk, maar kunnen ook tot ambiguïteit of onverwachte keuzes leiden.
- Neem `std::string_view` als parameter voor read-only tekst: het accepteert zowel `std::string`, `std::string_view` als string literals zonder kopie.
- > 💡 Aanvulling: als de code van de overloads voor elk type identiek is, is een function template (hoofdstuk 15) vaak een betere keuze dan handmatig overloads kopiëren.

### Samenvatting

- Function overloading = meerdere functies met dezelfde naam maar een verschillende parameterlijst; ze heten overloads van elkaar.
- De compiler kiest bij elke aanroep zelf de best passende overload op basis van de argumenten.
- De signature bestaat uit de functienaam en de parameterlijst; het **return type telt niet mee**.
- Alleen het return type veranderen geeft de fout "cannot overload functions distinguished by return type alone".
- Overloads kun je onderscheiden door het **type**, de **volgorde** (bij verschillende types) of het **aantal** parameters.
- Met `auto result = max(...)` krijgt `result` het return type van de gekozen overload.
- Als er geen exacte match is, kan de compiler een **impliciete conversie** toepassen, bv. string literal → `std::string_view`.
- Gebruik overloading waar het je code duidelijker en flexibeler maakt, niet om "zomaar" varianten te maken.

### Oefeningen

1. Schrijf twee overloads van een functie `print`: één die een `int` neemt en `"int: <waarde>"` print, en één die een `double` neemt en `"double: <waarde>"` print. Roep ze aan met `7` en `3.5`.
2. Schrijf overloads van `area`: met één `double` (oppervlakte van een vierkant met zijde `s`) en met twee `double`s (oppervlakte van een rechthoek `w * h`). Print `area(3.0)` en `area(2.0, 4.5)`.
3. Schrijf `int min(int a, int b)` en een overload `int min(int a, int b, int c)` die de eerste hergebruikt. Print `min(8, 3)` en `min(8, 3, 5)`.
4. Schrijf vier overloads van `describe` met parameterlijsten `(int, int)`, `(double, double)`, `(int, double)` en `(double, int)`, die elk hun eigen variant printen (bv. `"int double"`). Roep ze aan met de juiste argumenten zodat elke overload precies één keer gekozen wordt. Voeg daarna een overload `describe(std::string_view, std::string_view)` toe en roep die aan met twee string literals.

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>

void print(int value) {
    std::cout << "int: " << value << '\n';
}

void print(double value) {
    std::cout << "double: " << value << '\n';
}

int main() {
    print(7);     // int-overload
    print(3.5);   // double-overload
    return 0;
}
```

```text
int: 7
double: 3.5
```

Oefening 2:

```cpp
#include <iostream>

// vierkant: één parameter
double area(double s) {
    return s * s;
}

// rechthoek: twee parameters (ander aantal -> geldige overload)
double area(double w, double h) {
    return w * h;
}

int main() {
    std::cout << area(3.0) << '\n';
    std::cout << area(2.0, 4.5) << '\n';
    return 0;
}
```

```text
9
9
```

Oefening 3:

```cpp
#include <iostream>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min(int a, int b, int c) {
    return min(min(a, b), c);   // hergebruik van de twee-parameter-overload
}

int main() {
    std::cout << min(8, 3) << '\n';
    std::cout << min(8, 3, 5) << '\n';
    return 0;
}
```

```text
3
3
```

Oefening 4:

```cpp
#include <iostream>
#include <string_view>

void describe(int, int)       { std::cout << "int int" << '\n'; }
void describe(double, double) { std::cout << "double double" << '\n'; }
void describe(int, double)    { std::cout << "int double" << '\n'; }
void describe(double, int)    { std::cout << "double int" << '\n'; }

void describe(std::string_view a, std::string_view b) {
    std::cout << "string_view string_view: " << a << ' ' << b << '\n';
}

int main() {
    describe(1, 2);          // (int, int)
    describe(1.5, 2.5);      // (double, double)
    describe(1, 2.5);        // (int, double)
    describe(1.5, 2);        // (double, int)
    describe("Hello", "World"); // literals -> impliciet naar string_view
    return 0;
}
```

```text
int int
double double
int double
double int
string_view string_view: Hello World
```

</details>

---

<a id="h14"></a>

## Hoofdstuk 14 – Lambda functions (16:49:00 – 17:40:08) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60540s)

### Leerdoelen
- Begrijpen wat een lambda function (anonieme functie) is en waarom je ze gebruikt.
- De volledige syntax van een lambda kennen: capture list, parameterlijst, optioneel return type, body en afsluitende puntkomma.
- Een lambda een naam (handle) geven via `auto` en hem één of meerdere keren aanroepen.
- Een lambda direct aanroepen zonder naam (de "immediately invoked" vorm).
- Parameters doorgeven aan een lambda en waarden teruggeven, ook rechtstreeks binnen een `std::cout`-statement.
- Het return type expliciet vastleggen met `->` en zien wat dat doet met impliciete conversies.
- Variabelen van buiten de lambda bereikbaar maken met de capture list: by value (`[c]`) en by reference (`[&c]`).
- Alles in de omgeving in één keer capturen: `[=]` (alles by value) en `[&]` (alles by reference).
- Met adressen aantonen dat een by-value capture een kopie is en een by-reference capture naar dezelfde variabele wijst.

### Verband met eerdere hoofdstukken
- **Hoofdstuk 3 (Variables & data types)**: `auto` type deduction komt hier terug; het type van een lambda kun je niet zelf uitschrijven, dus `auto` is de enige praktische manier om een lambda in een variabele te bewaren.
- **Hoofdstuk 4 (Operations on data)**: impliciete conversies (int → double, double → int) spelen een rol bij parameters en het expliciete return type. `sizeof` wordt gebruikt om het type van een resultaat te "bewijzen".
- **Hoofdstuk 6 (Loops)**: de capture-demo's draaien in een `for`-lus.
- **Hoofdstuk 8 (Pointers)**: de adresoperator `&` wordt gebruikt om adressen van de buitenste en binnenste variabele te vergelijken.
- **Hoofdstuk 9 (References)**: capture by reference werkt precies als een reference: een alias naar de oorspronkelijke variabele.
- **Hoofdstuk 11–12 (Functions, getting things out of functions)**: een lambda is een functie zonder naam; parameters, pass by value vs. by reference en return by value werken hetzelfde als bij gewone functies.
- **Hoofdstuk 13 (Function overloading)**: na de "gewone" functies breidt dit hoofdstuk het functiebegrip uit naar functies die je ter plekke definieert.
- **Vooruitblik hoofdstuk 15**: de docent sluit af met de opmerking dat er nog veel meer met lambdas kan, maar dat je daarvoor eerst meer gereedschap (zoals templates) nodig hebt.

### Uitleg

#### Wat is een lambda function?
Een lambda function is een **anonieme functie**: een functie zonder naam die je midden in je code, op de plek waar je hem nodig hebt, definieert. Je kunt hem optioneel een naam geven door hem aan een variabele toe te kennen, of je kunt hem meteen aanroepen zonder dat hij ooit een naam krijgt.

Waarom bestaat dit? Vaak heb je een klein stukje functionaliteit nodig dat maar op één plek gebruikt wordt. Daarvoor een aparte, benoemde functie bovenaan je bestand definiëren is omslachtig. Een lambda zet de code precies waar hij gebruikt wordt. De docent benadrukt dat lambdas later in de cursus "een heleboel dingen makkelijker maken" in C++; in dit hoofdstuk leer je vooral de basissyntax.

[▶ 16:49:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60587s)

> ⚠️ Onduidelijk in opname: de ondertiteling spreekt steeds over "angle brackets" voor de capture list, maar bedoeld zijn de **vierkante haken** `[ ]`. In deze aantekeningen staat overal de juiste notatie.

#### De syntax van een lambda
De algemene vorm is:

```
[capture list] (parameters) -> return_type { body };
```

1. **Capture list** `[ ]` – altijd als eerste. Hiermee geef je de lambda toegang tot variabelen van buiten (zie verderop). Voorlopig is hij leeg.
2. **Parameterlijst** `( )` – net als bij een gewone functie. Hier komen de argumenten binnen als je de lambda aanroept.
3. **Return type** `-> type` – **optioneel**. Laat je het weg, dan leidt de compiler het return type zelf af uit de `return`-statements in de body.
4. **Body** `{ }` – de code die de lambda uitvoert.
5. **Puntkomma** `;` – de hele lambda-definitie staat in een statement, en elk C++-statement eindigt met een puntkomma.

Het eenvoudigste voorbeeld:

```
[](){ std::cout << "Hello World!" << std::endl; };
```

Dit is geldige C++-code en compileert, maar doet **niets**: de lambda wordt alleen gedefinieerd, niet aangeroepen. De docent laat dit zien door na de lambda een `std::cout << "Done!"` te zetten: het programma print alleen "Done!".

[▶ 16:50:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60635s) · [▶ 16:57:48 (in VS Code)](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61068s)

#### Een lambda een naam geven en aanroepen
Om een lambda te kunnen aanroepen, kun je hem een naam geven door hem aan een variabele toe te kennen. Het type van een lambda is een uniek, door de compiler gegenereerd type dat je niet zelf kunt uitschrijven; daarom gebruik je **`auto`**:

```
auto func = [](){ std::cout << "Hello World!" << std::endl; };
func();   // aanroep met gewone functie-aanroepsyntax
```

De docent noemt de variabele `func` een **handle** naar de lambda. Zolang de handle in scope is (hier: de hele `main`-functie), kun je de lambda zo vaak aanroepen als je wilt: `func(); func();` print twee keer "Hello World!". Alleen de toekenning aan `func` roept de lambda nog niet aan; pas `func()` doet dat.

[▶ 16:52:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60732s) · [▶ 16:59:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61164s)

#### Een lambda direct aanroepen
Je kunt een lambda ook definiëren en **meteen** aanroepen door direct na de afsluitende accolade een paar haakjes `()` te zetten:

```
[](){ std::cout << "Hello World!" << std::endl; }();
```

Omdat er geen handle is, heb je maar **één kans** om deze lambda aan te roepen. Dit gebruik je als je een stukje functionaliteit precies één keer wilt uitvoeren en het later niet meer nodig hebt. De docent zegt dat er veel soorten problemen zijn waarbij dit handig is.

[▶ 16:53:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60780s) · [▶ 17:01:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61310s)

#### Lambdas met parameters
Parameters zet je in de parameterlijst, net als bij een gewone functie:

```
[](double a, double b){ std::cout << "a + b : " << (a + b) << std::endl; }(10.0, 5.0);
```

Hier wordt de lambda direct aangeroepen met de double-literals `10.0` en `5.0`, dus hij print `a + b : 15`. Roep je een lambda met parameters aan met een lege argumentlijst `()`, dan krijg je een **compilerfout**, net als bij een gewone functie.

Met een handle kun je dezelfde lambda met verschillende argumenten aanroepen:

```
auto func1 = [](double a, double b){ ... };
func1(10, 20);   // 30
func1(5, 7);     // 12
```

Let op: hier worden **int**-literals meegegeven, terwijl de parameters `double` zijn. De compiler voegt een **impliciete conversie** van int naar double in. De docent waarschuwt dat je je bewust moet zijn van zulke conversies en moet zorgen dat ze in je voordeel werken.

[▶ 16:54:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60876s) · [▶ 17:03:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61407s) · [▶ 17:06:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61602s)

#### Lambdas die iets teruggeven
Een lambda kan met `return` een waarde teruggeven:

```
[](double a, double b){ return a + b; }(10, 20);
```

Deze regel doet zichtbaar **niets**: de som wordt berekend en teruggegeven, maar niemand doet iets met de returnwaarde. Om het resultaat te gebruiken moet je het "opvangen", bijvoorbeeld in een variabele:

```
auto result = [](double a, double b){ return a + b; }(10, 20);
std::cout << "result : " << result << std::endl;   // result : 30
```

Je kunt de hele aanroep ook rechtstreeks in een `std::cout`-statement zetten. De volledige lambda-uitdrukking met aanroep gedraagt zich dan als één enkele waarde:

```
std::cout << "result : " << [](double a, double b){ return a + b; }(10, 60) << std::endl;
```

De docent geeft toe dat deze syntax "really cryptic" oogt, maar hij werkt. Ook met een handle (`func1(23, 7)`, `func1(9, 45)`, `func1(5, 2)`) kun je de resultaten opslaan of direct printen.

[▶ 16:55:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60924s) · [▶ 17:08:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61699s) · [▶ 17:11:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61892s)

#### Het return type expliciet opgeven
Na de parameterlijst kun je met een pijl `->` (een streepje en een groter-dan-teken) het return type vastleggen:

```
auto func3 = [](double a, double b) -> int { return a + b; };
```

Wat gebeurt er onder de motorkap? `a + b` wordt berekend als `double`. Omdat het return type expliciet `int` is, zet de compiler dat double-resultaat **impliciet om naar int** (de decimalen worden afgekapt) en geeft een int terug. Zonder `-> int` leidt de compiler het return type af uit `a + b`, en dat is `double`.

De docent bewijst dit met `sizeof`:
- `func3(6.9, 3.5)` met `-> int` geeft `10`, en `sizeof(result3)` is 4 (grootte van int op zijn systeem).
- `func4(6.9, 3.5)` zonder expliciet return type geeft `10.4`, en `sizeof(result4)` is 8 (grootte van double).

In de slides zei de docent dat je zo "een double forceert", in de demo gebruikt hij `int`; het principe is hetzelfde: het type na `->` wint, ongeacht wat de body berekent.

[▶ 16:56:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=60971s) · [▶ 17:13:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62036s) · [▶ 17:18:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62322s)

#### Capture lists: toegang tot variabelen van buiten
Tot nu toe was de capture list `[ ]` steeds leeg. Een lambda is "zijn eigen ding": de body kan alleen werken met wat erin gedeclareerd is en met de parameters die binnenkomen. Probeer je in de body een lokale variabele van de omringende functie te gebruiken, dan krijg je een compilerfout. VS Code (IntelliSense) meldt dan zoiets als *"an enclosing-function local variable cannot be referenced in a lambda body unless it is in the capture list"*, en GCC zegt:

```
error: 'a' is not captured
error: 'b' is not captured
```

De oplossing: zet de variabelen in de capture list, gescheiden door komma's:

```
double a{10};
double b{20};
auto func = [a, b](){ std::cout << "a + b : " << a + b << std::endl; };
func();   // a + b : 30
```

Belangrijk: de waarden komen nu de lambda binnen **via de capture list**, niet via de parameterlijst. Dat is het hele doel van de capture list: de lambda toegang geven tot dingen die buiten zijn eigen scope gedeclareerd zijn.

[▶ 17:20:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62418s) · [▶ 17:25:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62753s)

#### Capture by value
Zet je alleen de naam van de variabele in de capture list (`[c]`), dan capture je **by value**: binnen de lambda zit een **kopie** van de buitenste variabele, gemaakt op het moment dat de lambda wordt aangemaakt.

De docent toont dit met een lus: `c` begint op 42, in elke iteratie wordt eerst de buitenste waarde geprint, dan de lambda aangeroepen (die de binnenste waarde print) en daarna `++c`. Resultaat: de **outer value** loopt op van 42 tot 46, maar de **inner value** blijft steeds 42, omdat de ophoging alleen de buitenste variabele raakt en niet de kopie in de lambda.

Als extra bewijs print hij de adressen (`&c`) binnen en buiten de lambda: ze zijn **verschillend**. Binnen en buiten zijn dus twee aparte stukken geheugen.

[▶ 17:21:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62515s) · [▶ 17:28:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62897s) · [▶ 17:30:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63041s)

> 💡 Aanvulling: een by-value capture is standaard **read-only** binnen de lambda; `++c` in de body geeft een compilerfout. Wil je de kopie toch aanpassen, dan moet je de lambda `mutable` maken (`[c]() mutable { ++c; }`). De docent behandelt dat in dit hoofdstuk niet.

#### Capture by reference
Zet je een ampersand voor de naam (`[&c]`), dan capture je **by reference**: binnen de lambda zit geen kopie, maar een echte reference naar de buitenste variabele. In dezelfde lusdemo lopen outer en inner value nu **samen** op (42, 43, 44, ...), en de adressen binnen en buiten zijn **identiek**: het is dezelfde variabele.

Je kiest zelf per variabele: `[c]` voor een kopie, `[&c]` voor een reference. Je mag ze ook mengen in één capture list.

[▶ 17:23:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62610s) · [▶ 17:32:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63136s)

#### Alles capturen: `[=]` en `[&]`
Als je niet elke variabele los wilt opsommen, kun je in één keer **alles** uit de omringende context capturen:

- `[=]` – capture alles **by value**. Elke variabele die je in de body gebruikt, wordt als kopie meegenomen. Gedrag in de lusdemo: outer value verandert, inner value blijft 42.
- `[&]` – capture alles **by reference**. Elke variabele die je gebruikt, is een reference naar het origineel. Outer en inner value veranderen samen.

De docent voegt in de by-reference-demo een extra variabele `d{5}` toe en gebruikt die in de lambda zonder hem expliciet in de capture list te zetten: dat werkt, omdat `[&]` alles capturet.

Hij waarschuwt bij `[&]`: je kunt er "pretty nasty things" mee doen, omdat wijzigingen binnen de lambda buiten zichtbaar zijn en omgekeerd. Gebruik het alleen als dat precies is wat je wilt.

[▶ 17:33:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63232s) · [▶ 17:35:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63331s) · [▶ 17:36:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63378s) · [▶ 17:38:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63522s)

> 💡 Aanvulling: `[=]` en `[&]` capturen alleen de variabelen die je in de body **werkelijk gebruikt**, niet letterlijk alles in de scope. Veel richtlijnen raden aan om expliciet te capturen (`[a, &b]`) zodat direct zichtbaar is wat de lambda gebruikt.

### Codevoorbeelden

#### Lambda declareren zonder aanroep [▶ 16:57:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61068s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // Lambda wordt alleen gedeclareerd, nooit aangeroepen -> print niets
    [](){
        std::cout << "Hello World!" << std::endl;
    };

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
Done!
```

#### Lambda met een naam (handle) aanroepen [▶ 17:00:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61214s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // Toekennen aan een variabele: func is een handle naar de lambda
    auto func = [](){
        std::cout << "Hello World!" << std::endl;
    };

    func(); // eerste aanroep
    func(); // handle blijft geldig in de scope van main

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
Hello World!
Hello World!
Done!
```

#### Lambda declareren en direct aanroepen [▶ 17:01:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61310s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // () direct na de afsluitende accolade -> meteen aanroepen, geen handle
    [](){
        std::cout << "Hello World!" << std::endl;
    }();

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
Hello World!
Done!
```

#### Lambda met parameters [▶ 17:03:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61407s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // Direct aanroepen met twee double-literals
    [](double a, double b){
        std::cout << "a + b : " << (a + b) << std::endl;
    }(10.0, 50.0);

    // Met handle: meerdere keren aanroepen
    auto func1 = [](double a, double b){
        std::cout << "a + b : " << (a + b) << std::endl;
    };
    func1(10, 20); // int-literals -> impliciet omgezet naar double
    func1(5, 7);

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
a + b : 60
a + b : 30
a + b : 12
Done!
```

#### Lambda die iets teruggeeft [▶ 17:08:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=61699s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // Returnwaarde opvangen in een variabele
    auto result = [](double a, double b){
        return a + b;
    }(10, 60);
    std::cout << "result : " << result << std::endl;

    // Hele aanroep direct in een cout-statement
    std::cout << "result : " << [](double a, double b){
        return a + b;
    }(10, 60) << std::endl;

    // Met handle, meerdere aanroepen
    auto func1 = [](double a, double b){
        return a + b;
    };
    auto result1 = func1(23, 7);
    auto result2 = func1(9, 45);
    std::cout << "result1 : " << result1 << std::endl;
    std::cout << "result2 : " << result2 << std::endl;
    std::cout << "direct call : " << func1(5, 2) << std::endl;

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
result : 70
result : 70
result1 : 30
result2 : 54
direct call : 7
Done!
```

#### Expliciet return type met `->` [▶ 17:13:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62036s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    // Return type expliciet int: double-som wordt omgezet naar int
    auto func3 = [](double a, double b) -> int {
        return a + b;
    };

    // Return type door compiler afgeleid: double
    auto func4 = [](double a, double b){
        return a + b;
    };

    double a{6.9};
    double b{3.5};

    auto result3 = func3(a, b);
    auto result4 = func4(a, b);

    std::cout << "sizeof(result3) : " << sizeof(result3) << std::endl; // int
    std::cout << "sizeof(result4) : " << sizeof(result4) << std::endl; // double

    std::cout << "result3 : " << result3 << std::endl;
    std::cout << "result4 : " << result4 << std::endl;

    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
sizeof(result3) : 4
sizeof(result4) : 8
result3 : 10
result4 : 10.4
Done!
```

#### Variabele gebruiken zonder capture (compilerfout) [▶ 17:25:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62753s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: a en b zijn niet gecaptured -> "'a' is not captured"
#include <iostream>

int main() {
    double a{10};
    double b{20};

    auto func = [](){
        std::cout << "a + b : " << a + b << std::endl;
    };
    func();
    return 0;
}
```

#### Capture list met meerdere variabelen [▶ 17:26:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62801s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    double a{10};
    double b{20};

    // a en b komen binnen via de capture list, niet via parameters
    auto func = [a, b](){
        std::cout << "a + b : " << a + b << std::endl;
    };
    func();
    return 0;
}
```
```text
a + b : 30
```

#### Capture by value: kopie blijft gelijk [▶ 17:28:17](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=62897s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int c{42};

    // c wordt gekopieerd op het moment dat de lambda gemaakt wordt
    auto func = [c](){
        std::cout << "Inner value : " << c << std::endl;
    };

    for (size_t i{0}; i < 5; ++i) {
        std::cout << "Outer value : " << c << std::endl;
        func();
        ++c; // verandert alleen de buitenste c
    }
    return 0;
}
```
```text
Outer value : 42
Inner value : 42
Outer value : 43
Inner value : 42
Outer value : 44
Inner value : 42
Outer value : 45
Inner value : 42
Outer value : 46
Inner value : 42
```

#### Capture by value: adressen vergelijken [▶ 17:30:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63041s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

int main() {
    int c{42};

    auto func = [c](){
        std::cout << "Inner value : " << c << " &inner : " << &c << std::endl;
    };

    for (size_t i{0}; i < 3; ++i) {
        std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
        func();
        ++c;
    }
    return 0;
}
```
Voorbeeldoutput (adressen verschillen per run en systeem; binnen en buiten zijn ze **verschillend**):
```text
Outer value : 42 &outer : 0x5ffe9c
Inner value : 42 &inner : 0x5ffe98
Outer value : 43 &outer : 0x5ffe9c
Inner value : 42 &inner : 0x5ffe98
Outer value : 44 &outer : 0x5ffe9c
Inner value : 42 &inner : 0x5ffe98
```

#### Capture by reference: binnen en buiten samen [▶ 17:32:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63136s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int c{42};

    // &c: reference naar de buitenste c, geen kopie
    auto func = [&c](){
        std::cout << "Inner value : " << c << std::endl;
    };

    for (size_t i{0}; i < 5; ++i) {
        std::cout << "Outer value : " << c << std::endl;
        func();
        ++c; // zichtbaar binnen de lambda
    }
    return 0;
}
```
```text
Outer value : 42
Inner value : 42
Outer value : 43
Inner value : 43
Outer value : 44
Inner value : 44
Outer value : 45
Inner value : 45
Outer value : 46
Inner value : 46
```

#### Capture by reference: adressen vergelijken [▶ 17:32:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63136s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>

int main() {
    int c{42};

    auto func = [&c](){
        std::cout << "Inner value : " << c << " &inner : " << &c << std::endl;
    };

    for (size_t i{0}; i < 3; ++i) {
        std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
        func();
        ++c;
    }
    return 0;
}
```
Voorbeeldoutput (adressen binnen en buiten zijn nu **gelijk**):
```text
Outer value : 42 &outer : 0x5ffe9c
Inner value : 42 &inner : 0x5ffe9c
Outer value : 43 &outer : 0x5ffe9c
Inner value : 43 &inner : 0x5ffe9c
Outer value : 44 &outer : 0x5ffe9c
Inner value : 44 &inner : 0x5ffe9c
```

#### Alles capturen by value met `[=]` [▶ 17:36:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63378s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int c{42};

    // [=]: alles wat de body gebruikt, wordt als kopie gecaptured
    auto func = [=](){
        std::cout << "Inner value : " << c << std::endl;
    };

    for (size_t i{0}; i < 5; ++i) {
        std::cout << "Outer value : " << c << std::endl;
        func();
        ++c;
    }
    return 0;
}
```
```text
Outer value : 42
Inner value : 42
Outer value : 43
Inner value : 42
Outer value : 44
Inner value : 42
Outer value : 45
Inner value : 42
Outer value : 46
Inner value : 42
```

#### Alles capturen by reference met `[&]` [▶ 17:37:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63475s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

int main() {
    int c{42};
    int d{5};

    // [&]: alles wat de body gebruikt, is een reference naar het origineel
    auto func = [&](){
        std::cout << "Inner value : " << c << std::endl;
        std::cout << "Inner value (d) : " << d << std::endl; // d niet expliciet genoemd
    };

    for (size_t i{0}; i < 5; ++i) {
        std::cout << "Outer value : " << c << std::endl;
        func();
        ++c;
    }
    return 0;
}
```
```text
Outer value : 42
Inner value : 42
Inner value (d) : 5
Outer value : 43
Inner value : 43
Inner value (d) : 5
Outer value : 44
Inner value : 44
Inner value (d) : 5
Outer value : 45
Inner value : 45
Inner value (d) : 5
Outer value : 46
Inner value : 46
Inner value (d) : 5
```

### Valkuilen & veelgemaakte fouten

#### Lambda declareren maar niet aanroepen
Een lambda-definitie alleen (`[](){ ... };`) of de toekenning `auto func = [](){ ... };` voert de body **niet** uit. Pas `func()` of de directe aanroep `[](){ ... }()` doet iets. De docent laat dit expres zien: het programma print alleen "Done!".

#### Puntkomma vergeten
De lambda staat in een statement; na de afsluitende accolade (of na de aanroephaakjes) is een `;` nodig, anders krijg je een compilerfout.

#### Argumenten vergeten bij een lambda met parameters
Een lambda met parameters aanroepen met `()` geeft een compilerfout, precies zoals bij een gewone functie. Het aantal en type argumenten moet passen.

#### Returnwaarde niet opvangen
`[](double a, double b){ return a + b; }(10, 20);` berekent de som, maar je ziet niets: de returnwaarde wordt weggegooid. Sla het resultaat op in een variabele of zet de aanroep direct in een `std::cout`.

#### Ongemerkte impliciete conversies
Int-argumenten worden stilletjes naar double-parameters omgezet, en met `-> int` wordt een double-resultaat afgekapt (`6.9 + 3.5` wordt `10`, niet `10.4`). De docent waarschuwt: wees je bewust van deze conversies en zorg dat ze in je voordeel werken.

#### Buitenste variabele gebruiken zonder capture
Een lege capture list geeft geen toegang tot lokale variabelen van de omringende functie: `error: 'a' is not captured`. Zet ze in de capture list.

#### Verwachten dat een by-value capture meeverandert
Met `[c]` of `[=]` is de lambda-variabele een kopie, gemaakt bij het aanmaken van de lambda. Wijzigingen buiten de lambda zie je binnen niet terug (inner value blijft 42).

#### Onbedoelde bijwerkingen met `[&]`
Met capture by reference werken wijzigingen in beide richtingen door. De docent noemt dat "pretty nasty things": gebruik `[&]` alleen bewust.

> 💡 Aanvulling: een lambda die by reference capturet en langer leeft dan de gecapturede variabele (bijv. een lambda die uit een functie wordt teruggegeven en een lokale variabele by reference vasthoudt) bevat een **dangling reference**; aanroepen is dan undefined behavior. Dezelfde gevaren als bij dangling pointers uit hoofdstuk 8.

### Best practices
- Gebruik `auto` om een lambda een naam te geven; het werkelijke type kun je niet uitschrijven.
- Geef de lambda een handle als je hem meerdere keren nodig hebt; roep hem direct aan als je hem precies één keer nodig hebt.
- Laat de compiler het return type afleiden, tenzij je bewust een bepaald type wilt afdwingen; schrijf dan `-> type` en wees je bewust van de conversie.
- Kies bij elke capture bewust tussen value (kopie, veilig, onafhankelijk) en reference (gedeeld, wijzigingen zichtbaar in beide richtingen).
- Gebruik `[=]` en `[&]` met zorg; als je weet wat je zoekt, maakt expliciet capturen (`[a, &b]`) de code duidelijker.
- Zet bij het experimenteren een "Done!"-regel aan het eind van `main` en print adressen met `&` om te controleren wat er echt gebeurt, zoals de docent doet.
- Lambda-syntax oogt cryptisch: onthoud de volgorde **capture – parameters – (return type) – body – ;** en de rest volgt vanzelf.

### Samenvatting
- Een lambda function is een anonieme functie: `[capture](params) -> type { body };`.
- Het return type is optioneel; zonder `->` leidt de compiler het af uit de `return`.
- Geef een lambda een naam met `auto func = ...;` en roep hem aan met `func(...)`, zo vaak als je wilt.
- Zet `()` direct achter de body om de lambda meteen (eenmalig) aan te roepen.
- Parameters en returnwaarden werken als bij gewone functies; impliciete conversies treden op bij type-mismatch.
- Een aanroep van een lambda die iets teruggeeft is een waarde en kan direct in `std::cout` staan.
- De capture list geeft toegang tot variabelen buiten de lambda; zonder capture: `'x' is not captured`.
- `[c]` capturet by value (kopie, ander adres); `[&c]` by reference (zelfde variabele, zelfde adres).
- `[=]` capturet alles by value, `[&]` alles by reference; bij `[&]` werken wijzigingen in beide richtingen door.

### Oefeningen
1. Schrijf een lambda zonder parameters die `"Welkom bij lambdas!"` print. Roep hem één keer direct aan en definieer daarna een tweede lambda met handle `greet` die je drie keer aanroept.
2. Schrijf een lambda `max_of` die twee `int`-parameters neemt en de grootste teruggeeft. Print `max_of(3, 9)` en `max_of(12, 4)` rechtstreeks in een `std::cout`-statement.
3. Schrijf een lambda `average` die drie `double`-parameters neemt en het gemiddelde teruggeeft, en een tweede lambda `average_int` die hetzelfde doet maar met `-> int`. Roep beide aan met `1.5, 2.5, 4.0` en print beide resultaten en hun `sizeof`.
4. Declareer `int counter{0};` en `int step{3};`. Maak een lambda die `step` by value en `counter` by reference capturet en `counter += step;` uitvoert. Roep hem vier keer aan, wijzig tussendoor (na de tweede aanroep) `step` naar 10 en print na elke aanroep `counter`. Verklaar de uitkomst.
5. Declareer `int x{1}; int y{2};`. Maak een lambda met `[=]` die `x + y` print en een lambda met `[&]` die `x + y` print. Verhoog daarna `x` en `y` allebei met 10 en roep beide lambdas aan. Welke lambda ziet de nieuwe waarden?

<details><summary>Uitwerking</summary>

Oefening 1:
```cpp
#include <iostream>

int main() {
    // Direct aanroepen, geen handle
    [](){
        std::cout << "Welkom bij lambdas!" << std::endl;
    }();

    // Met handle, drie keer aanroepen
    auto greet = [](){
        std::cout << "Welkom bij lambdas!" << std::endl;
    };
    greet();
    greet();
    greet();
    return 0;
}
```
```text
Welkom bij lambdas!
Welkom bij lambdas!
Welkom bij lambdas!
Welkom bij lambdas!
```

Oefening 2:
```cpp
#include <iostream>

int main() {
    auto max_of = [](int a, int b){
        return (a > b) ? a : b; // return type afgeleid: int
    };
    std::cout << "max_of(3, 9) : " << max_of(3, 9) << std::endl;
    std::cout << "max_of(12, 4) : " << max_of(12, 4) << std::endl;
    return 0;
}
```
```text
max_of(3, 9) : 9
max_of(12, 4) : 12
```

Oefening 3:
```cpp
#include <iostream>

int main() {
    auto average = [](double a, double b, double c){
        return (a + b + c) / 3; // afgeleid: double
    };
    auto average_int = [](double a, double b, double c) -> int {
        return (a + b + c) / 3; // double wordt afgekapt naar int
    };

    auto r1 = average(1.5, 2.5, 4.0);
    auto r2 = average_int(1.5, 2.5, 4.0);

    std::cout << "average : " << r1 << " (sizeof " << sizeof(r1) << ")" << std::endl;
    std::cout << "average_int : " << r2 << " (sizeof " << sizeof(r2) << ")" << std::endl;
    return 0;
}
```
```text
average : 2.66667 (sizeof 8)
average_int : 2 (sizeof 4)
```

Oefening 4:
```cpp
#include <iostream>

int main() {
    int counter{0};
    int step{3};

    // step: kopie (blijft 3), counter: reference (verandert buiten mee)
    auto add = [step, &counter](){
        counter += step;
    };

    add();
    std::cout << "counter : " << counter << std::endl;
    add();
    std::cout << "counter : " << counter << std::endl;

    step = 10; // heeft geen invloed op de kopie in de lambda
    add();
    std::cout << "counter : " << counter << std::endl;
    add();
    std::cout << "counter : " << counter << std::endl;
    return 0;
}
```
```text
counter : 3
counter : 6
counter : 9
counter : 12
```
Verklaring: `step` is by value gecaptured toen de lambda werd gemaakt (waarde 3); de latere wijziging naar 10 ziet de lambda niet. `counter` is een reference, dus de ophogingen zijn buiten zichtbaar.

Oefening 5:
```cpp
#include <iostream>

int main() {
    int x{1};
    int y{2};

    auto by_value = [=](){
        std::cout << "[=] x + y : " << x + y << std::endl;
    };
    auto by_ref = [&](){
        std::cout << "[&] x + y : " << x + y << std::endl;
    };

    x += 10;
    y += 10;

    by_value(); // kopieën van toen: 1 + 2
    by_ref();   // references: 11 + 12
    return 0;
}
```
```text
[=] x + y : 3
[&] x + y : 23
```
Alleen de `[&]`-lambda ziet de nieuwe waarden.

</details>

---

<a id="h15"></a>

## Hoofdstuk 15 – Function templates (17:40:08 – 19:04:31) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63608s)

### Leerdoelen

- Begrijpen welk probleem function templates oplossen: herhaalde logica in vele function overloads.
- Een function template schrijven met `template <typename T>`.
- Inzien dat een template **geen echte C++-code** is, maar een blauwdruk waaruit de compiler *template instances* genereert – en alleen voor de types die je effectief gebruikt.
- Template instances zichtbaar maken met cppinsights.io en met de debugger (call stack).
- Weten dat de operaties in de template-body door het gebruikte type ondersteund moeten worden (bv. geen `*` op `std::string`).
- Template type deduction begrijpen en de fout "deduced conflicting types" herkennen.
- Explicit template arguments gebruiken (`maximum<double>(a, c)`) en weten dat dan impliciete conversies mogelijk worden.
- Het verschil tussen *template parameter* en *template argument* kennen.
- Template parameters by (const) reference doorgeven, en de ambiguïteit tussen een by-value- en een by-reference-template vermijden.
- Een function template opsplitsen in declaratie en definitie.
- Template specialization (`template <>`) gebruiken om bv. `const char*` correct te vergelijken met `std::strcmp`.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 13 (Function overloading):** het startpunt van dit hoofdstuk. Daar schreven we `maximum(int, int)`, `maximum(double, double)`, `maximum(std::string_view, ...)` met telkens dezelfde body. Templates halen die herhaling weg; de compiler maakt de overloads nu zelf.
- **Hoofdstuk 5 (Flow control):** de ternary operator `a > b ? a : b` is de kern van elk `maximum`-voorbeeld.
- **Hoofdstuk 3 (auto):** `auto result = maximum(c, d);` laat de compiler het returntype van de template instance afleiden.
- **Hoofdstuk 8 (Pointers) en 10 (C-strings):** `maximum(px, py)` en `maximum("wild", "animal")` vergelijken adressen in plaats van waarden; `std::strcmp` uit `<cstring>` lost dat op.
- **Hoofdstuk 9 (References) en 11 (Pass by value/reference):** `const T&` als parametertype, adressen binnen en buiten de functie vergelijken.
- **Hoofdstuk 11 (Declaratie/definitie):** ook een template kun je opsplitsen in prototype boven `main` en definitie eronder.
- **Volgend hoofdstuk 16 (Concepts):** concepts leggen beperkingen op aan template parameters – het antwoord op de "type ondersteunt de operatie niet"-problemen uit dit hoofdstuk.

### Uitleg

#### Het probleem: dezelfde logica in veel overloads

In hoofdstuk 13 had `maximum` meerdere overloads die allemaal exact hetzelfde deden: `return (a > b) ? a : b;`. Wil je `int`, `double`, `long long`, `std::string` … ondersteunen, dan kopieer je die body telkens opnieuw. Met 20 overloads, of met een body van 20–30 regels, wordt dat onderhoudbaar slecht: elke wijziging moet je overal doorvoeren.

De docent laat het eerst "op de slechte manier" zien: een `int`-versie, een `const std::string&`-versie (const reference om onnodige kopieën van strings te vermijden) en een `long long`-versie – drie keer dezelfde logica. Een alternatief zou zijn om alleen de `int`-versie te houden en de compiler `double` impliciet naar `int` te laten converteren, maar dat verliest informatie en werkt helemaal niet voor types die niet naar `int` converteerbaar zijn, zoals `std::string`.

Function templates geven je **één punt van controle**: je schrijft de logica één keer als blauwdruk, en de compiler genereert de concrete functies.

[▶ 17:40:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63621s) · [▶ 17:47:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64056s)

#### Syntax van een function template

```
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
```

- `template` opent de template-declaratie.
- Tussen de punthaken staat `typename T`: `T` is een **placeholder** voor een type. De naam `T` is conventie; elke naam mag.
- Daarna volgt de functie, geschreven in termen van `T`. Omdat het returntype én beide parameters hetzelfde `T` gebruiken, **moeten ze allemaal van hetzelfde type zijn**.
- Je mag de `template <typename T>`-regel op dezelfde regel als de functie zetten; de docent verkiest aparte regels.
- Je kunt de template ook opsplitsen in een declaratie (prototype) en een definitie, net als gewone functies – in beide moet de `template <typename T>`-kop staan.

[▶ 17:50:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64250s)

#### Templates zijn blauwdrukken, geen echte code

Dit benadrukt de docent meermaals: een function template is **geen echte C++-functie**. Het is een blauwdruk. Pas wanneer de compiler een aanroep ziet, gebeurt het volgende:

1. De compiler zoekt een gewone functie `maximum` die past. Vindt hij die niet, dan kijkt hij naar de templates.
2. Hij bekijkt de types van de argumenten (bv. `int x = 5; int y = 7;` → `int`).
3. Hij vervangt elke `T` in de blauwdruk door `int` en genereert zo een echte functie `int maximum(int a, int b)`. Dat heet een **template instance** (template instantiation).
4. Die instance wordt aangeroepen en komt in het binaire bestand terecht. Templates worden dus tijdens het compileren uitgewerkt, niet tijdens het uitvoeren.

Belangrijke gevolgen:

- **Alleen gebruikte instances worden gegenereerd.** Roep je `maximum` nooit met `std::string` aan, dan bestaat er geen string-versie.
- **Een instance wordt hergebruikt.** Roep je `maximum` twee keer met `int` aan, dan wordt de `int`-versie één keer gegenereerd en daarna hergebruikt.

[▶ 17:43:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=63814s) · [▶ 17:46:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64007s)

#### Instances bekijken met cppinsights

De docent gebruikt de webtool **cppinsights.io**: je plakt je code erin, klikt op de play-knop en rechts verschijnt de code zoals de compiler ze "ziet", inclusief de gegenereerde template instances. Tips uit de les:

- Haal `std::cout`-regels weg als je alleen in de instances geïnteresseerd bent; anders krijg je veel "ruis" van `<iostream>`.
- Met `int`-argumenten zie je `int maximum<int>(int a, int b)`; verander je de variabelen naar `double` of `long long`, dan verschijnt meteen die versie – en de `int`-versie verdwijnt.
- Met `std::string` zie je iets als `std::basic_string<char, ...>`: dat is hoe de compiler `std::string` intern noemt. De details komen later in de cursus.
- cppinsights moet de code kunnen compileren; bij een compilerfout krijg je geen instances te zien.

[▶ 17:53:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64394s)

#### Returntype en `auto`

Met `double`-variabelen (5.5 en 78.7) gaf `int result = maximum(x, y);` als output 78: de `double` die de instance teruggeeft, wordt bij het toekennen naar `int` geconverteerd. Gebruik `auto result = maximum(x, y);` zodat de compiler het type van `result` afleidt uit het returntype van de template instance – dan krijg je 78.7.

Bij `std::string` ("hello" en "world") vergelijkt `>` lexicografisch (alfabetisch): "world" is groter omdat `w` na `h` komt.

[▶ 17:56:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64586s)

#### De body moet door het type ondersteund worden

Een tweede template, `multiply`, geeft `a * b` terug. Met `int` (5 × 7 = 35) en `double` (5.1 × 7.0 = 35.7) werkt dat. Met `std::string` krijg je een compilerfout: de compiler vervangt braaf `T` door `std::string`, maar twee strings vermenigvuldigen bestaat niet. GCC meldt iets als *"in instantiation of ... required from here"* en *"no match for 'operator*'"*.

De les: zorg dat elke operatie in de template-body ondersteund wordt door de types waarmee je de template aanroept.

> 💡 Aanvulling: precies dit probleem lossen *concepts* (hoofdstuk 16) op: je kunt dan vooraf eisen dat `T` bijvoorbeeld vermenigvuldigbaar is, met een veel duidelijkere foutmelding.

[▶ 18:00:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64830s)

#### Verschillende argumenttypes bij één `T`

Roep je `maximum(x, y)` aan met `x` een `double` en `y` een `int`, dan faalt de compilatie. Omdat er maar één placeholder `T` is, moet de compiler één type kiezen voor beide parameters (en het returntype), maar hij krijgt er twee. VS Code meldt *"no instance of function template "maximum" matches the argument list"*; GCC zegt *"deduced conflicting types for parameter 'T' ('double' and 'int')"*. Een oplossing volgt verderop (explicit template arguments).

[▶ 18:05:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65118s)

#### Templates debuggen

De template-projectmap is uitgebreid met een `launch.json`, zodat je kunt debuggen. Zet een breakpoint op de aanroep van `maximum`, start de debugger (Run-tab, groene knop), en gebruik **Step Into**:

- In het *Locals*-paneel zie je de waarden van `a` en `b`, maar niet altijd hun types.
- In de **call stack** zie je wel de signatuur van de instance, bv. `maximum<int>(int a, int b)` of `maximum<double>(double a, double b)`. Zo bewijs je welke instance de compiler genereerde.
- Met de MSVC-compiler (`cl.exe`) en zijn debugger zie je vergelijkbare informatie, alleen anders gepresenteerd. Compilers en debuggers kunnen verschillende details tonen.

[▶ 18:07:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65263s)

#### Template instances doen niet altijd wat je wilt: pointers

Met `int* px = &x; int* py = &y;` en `maximum(px, py)` genereert de compiler `int* maximum(int* a, int* b)`. Die vergelijkt **adressen**, niet de waarden. In de demo stond `x` (5) op het hogere adres, dus kwam `px` terug, en `*result` gaf 5 als "maximum" van 5 en 7. Fout! In de debugger zie je dat `a` en `b` adressen bevatten en dat het grootste adres wint.

De compiler doet precies wat de blauwdruk zegt; het is aan jou om te controleren dat dat ook betekent wat je bedoelt.

> 💡 Aanvulling: volgens de standaard is het resultaat van `<`/`>` tussen pointers naar losse, ongerelateerde objecten *niet gespecificeerd*. Welke pointer "wint" kan dus per compiler, platform en zelfs per build verschillen.

[▶ 18:14:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65654s)

#### Template type deduction

**Template type deduction** is het standaardmechanisme waarmee de compiler het type voor `T` afleidt uit de argumenten van de aanroep. Er is geen andere hulp: `maximum(a, b)` met twee `int`s → `int`-instance; met `double`s → `double`-instance; met `std::string`s → string-instance. Dit gaat mis zodra de argumenten verschillende types hebben (`maximum(a, c)` met `int` en `double`): *deduced conflicting types*.

[▶ 18:19:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65990s)

#### Template parameter vs. template argument

- **Template parameter:** wat in de declaratie/definitie van de template staat, bv. `T` in `template <typename T>` (of `T` en `P` bij meerdere).
- **Template argument:** wat je bij de aanroep meegeeft – het type dat voor de parameter wordt ingevuld (afgeleid uit de functie-argumenten of expliciet tussen punthaken).

Deze terminologie komt de rest van de cursus terug.

[▶ 18:21:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=66086s)

#### Explicit template arguments

Je kunt de compiler dwingen een bepaald type te gebruiken door het tussen punthaken achter de functienaam te zetten:

```
auto max = maximum<double>(a, c);   // a is int, c is double
```

Nu wordt er geen type afgeleid: `T` is `double`. Daardoor mogen de argumenten verschillen, want de compiler voegt **impliciete conversies** in naar `double` (`a`: `int` → `double`; `c` is al `double`). Is een conversie onmogelijk, bv. `maximum<double>(a, e)` met `e` een `std::string`, dan krijg je een compilerfout. In cppinsights en in de call stack zie je dat er een `double`-instance gegenereerd is.

[▶ 18:22:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=66135s) · [▶ 18:29:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=66571s)

#### Template parameters by reference

Tot nu toe was `T maximum(T a, T b)` **pass by value**: de functie werkt op kopieën. Dat bewijs je door het adres van `a` buiten en binnen de functie te printen: buiten (voor en na de aanroep) hetzelfde, binnen een ander adres.

Je kunt ook by reference doorgeven, met dezelfde syntax als bij gewone references. Een goede gewoonte is `const T&`, zodat de functie de argumenten niet kan wijzigen:

```
template <typename T>
const T& maximum(const T& a, const T& b);
```

Bij `double`-argumenten genereert de compiler `const double& maximum(const double& a, const double& b)`. Nu zijn de adressen binnen en buiten de functie gelijk. Probeer je in de body `++a`, dan meldt GCC *"increment of read-only reference 'a'"*.

[▶ 18:35:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=66956s) · [▶ 18:42:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67339s)

#### Ambiguïteit: by-value- en by-reference-template naast elkaar

Function templates kunnen overloads zijn, maar heb je zowel `T maximum(T, T)` als `const T& maximum(const T&, const T&)`, dan passen beide even goed bij `maximum(a, b)`. Net als bij gewone overloads (hoofdstuk 13) krijg je dan *"call of overloaded 'maximum(double&, double&)' is ambiguous"*. Kies één van beide.

[▶ 18:37:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67051s) · [▶ 18:46:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67581s)

#### Template specialization

Bij `const char*`-argumenten (C-strings) genereert de standaardtemplate een instance die **pointers** vergelijkt in plaats van de tekst. Met `g = "wild"` en `h = "animal"` gaf het programma in de demo "animal" als maximum, terwijl "wild" lexicografisch groter is. In de debugger zie je dat `b` op een hoger adres stond (eindigend op 55 vs. 50), en dus won.

**Template specialization** laat je zeggen: "voor dit specifieke type niet de standaardvervanging doen, maar deze implementatie gebruiken". Syntax:

```
template <>
const char* maximum<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}
```

- `template` met een **leeg** paar punthaken.
- Dezelfde functienaam als de primaire template.
- Het type waarvoor je specialiseert als explicit template argument (`<const char*>`); returntype en parameters volgen uit `T = const char*`.
- In de body gebruik je `std::strcmp` uit `<cstring>`: die vergelijkt twee null-terminated strings lexicografisch en geeft een negatief getal (eerste komt vóór tweede), 0 (gelijk) of een positief getal (eerste komt ná tweede) terug. `> 0` betekent dus: `a` is groter.

Ziet de compiler nu een aanroep met `const char*`, dan gebruikt hij de specialisatie omdat die beter past. Resultaat: "wild".

[▶ 18:48:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67727s) · [▶ 18:52:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67920s) · [▶ 18:59:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68399s)

### Codevoorbeelden

#### Het probleem: drie overloads met dezelfde body [▶ 17:47:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64056s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

// Drie keer exact dezelfde logica: dit willen we vermijden
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

const std::string& maximum(const std::string& a, const std::string& b) {
    return (a > b) ? a : b;
}

long long maximum(long long a, long long b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maximum(5, 7) << '\n';
    std::cout << maximum(std::string{"hello"}, std::string{"world"}) << '\n';
    std::cout << maximum(10LL, 3LL) << '\n';
    return 0;
}
```

```text
7
world
10
```

#### Eerste function template [▶ 17:50:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64250s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

// Blauwdruk: T wordt door de compiler vervangen door het argumenttype
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x{5};
    int y{7};
    int result = maximum(x, y);           // genereert int maximum(int, int)
    std::cout << "result : " << result << '\n';

    double dx{5.5};
    double dy{78.7};
    int truncated = static_cast<int>(maximum(dx, dy)); // double -> int: info weg
    auto correct = maximum(dx, dy);       // auto: type = double
    std::cout << "result (int) : " << truncated << '\n';
    std::cout << "result (auto) : " << correct << '\n';

    std::string sx{"hello"};
    std::string sy{"world"};
    auto sresult = maximum(sx, sy);       // genereert std::string-versie
    std::cout << "result : " << sresult << '\n';
    return 0;
}
```

```text
result : 7
result (int) : 78
result (auto) : 78.7
result : world
```

> 💡 Aanvulling: de docent schreef `int result = maximum(x, y);` met `double`s, wat een impliciete conversie geeft. Hier staat een `static_cast` om de waarschuwing van `-Wall -Wextra` te vermijden; het effect (78) is hetzelfde.

#### Wat de compiler ervan maakt (instance) [▶ 17:53:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64394s)

Zo ziet de door de compiler gegenereerde `int`-instance er ongeveer uit (vergelijkbaar met wat cppinsights toont). Hier handmatig uitgeschreven als gewone functie:

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

// Wat de compiler intern genereert voor maximum(int, int):
// elke T is vervangen door int
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x{5};
    int y{7};
    std::cout << "result : " << maximum(x, y) << '\n';
    return 0;
}
```

```text
result : 7
```

#### `multiply`: de body moet door het type ondersteund worden [▶ 18:00:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=64830s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    int x{5};
    int y{7};
    std::cout << multiply(x, y) << '\n';   // int-instance

    double dx{5.1};
    double dy{7.0};
    std::cout << multiply(dx, dy) << '\n'; // double-instance
    return 0;
}
```

```text
35
35.7
```

Met strings faalt de instantiatie:

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: std::string heeft geen operator*
#include <iostream>
#include <string>

template <typename T>
T multiply(T a, T b) {
    return a * b;   // error: no match for 'operator*'
}

int main() {
    std::string x{"hello"};
    std::string y{"world"};
    auto result = multiply(x, y);   // in instantiation of ... required from here
    std::cout << result << '\n';
    return 0;
}
```

#### Verschillende types met één `T` [▶ 18:05:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65118s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: deduced conflicting types for parameter 'T' ('double' and 'int')
#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    double x{5.5};
    int y{7};
    auto result = maximum(x, y);   // T = double of T = int?
    std::cout << result << '\n';
    return 0;
}
```

#### Pointers: adressen in plaats van waarden [▶ 18:14:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=65654s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;   // met T = int*: vergelijkt ADRESSEN
}

int main() {
    int x{5};
    int y{7};
    int* px{&x};
    int* py{&y};

    auto result = maximum(px, py);   // genereert int* maximum(int*, int*)
    std::cout << "result : " << result << '\n';   // een adres
    std::cout << "*result : " << *result << '\n'; // 5 of 7, afhankelijk van adressen!
    return 0;
}
```

Voorbeeldoutput (de docent kreeg 5, omdat `x` op het hogere adres stond; bij jou kan het anders zijn):

```text
result : 0x5ffe9c
*result : 5
```

#### Type deduction en explicit template arguments [▶ 18:24:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=66280s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    std::string e{"hello"};
    std::string f{"world"};

    auto max1 = maximum(a, b);           // deduction: T = int
    auto max2 = maximum(c, d);           // deduction: T = double
    auto max3 = maximum(e, f);           // deduction: T = std::string
    std::cout << max1 << ' ' << max2 << ' ' << max3 << '\n';

    // auto bad = maximum(a, d);         // error: deduced conflicting types

    auto max4 = maximum<double>(c, d);   // explicit template argument
    auto max5 = maximum<double>(a, d);   // int a wordt impliciet double
    std::cout << max4 << ' ' << max5 << '\n';

    // auto bad2 = maximum<double>(a, e); // error: std::string -> double kan niet
    return 0;
}
```

```text
23 34.7 world
34.7 23.4
```

#### Pass by value: adressen verschillen [▶ 18:39:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67148s)

Hier is de template opgesplitst in declaratie (voor `main`) en definitie (na `main`).

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

// Declaratie (prototype)
template <typename T>
T maximum(T a, T b);

int main() {
    double a{23.5};
    double b{51.2};
    std::cout << "Out - &a: " << &a << '\n';
    auto result = maximum(a, b);
    std::cout << "Out - &a: " << &a << '\n';
    std::cout << "result : " << result << '\n';
    return 0;
}

// Definitie
template <typename T>
T maximum(T a, T b) {
    std::cout << "In  - &a: " << &a << '\n';   // kopie: ander adres
    return (a > b) ? a : b;
}
```

Voorbeeldoutput (adressen verschillen per systeem):

```text
Out - &a: 0x5ffe98
In  - &a: 0x5ffe60
Out - &a: 0x5ffe98
result : 51.2
```

#### Pass by const reference: adressen gelijk [▶ 18:42:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67339s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

template <typename T>
const T& maximum(const T& a, const T& b);

int main() {
    double a{23.5};
    double b{51.2};
    const double* outside = &a;
    const double* inside = nullptr;

    auto result = maximum(a, b);   // genereert const double& maximum(const double&, const double&)
    inside = &maximum(a, a);       // reference naar a zelf
    std::cout << "result : " << result << '\n';
    std::cout << std::boolalpha << "same address: " << (outside == inside) << '\n';
    return 0;
}

template <typename T>
const T& maximum(const T& a, const T& b) {
    // ++a;   // error: increment of read-only reference 'a'
    return (a > b) ? a : b;
}
```

```text
result : 51.2
same address: true
```

> 💡 Aanvulling: de docent print de adressen gewoon met `std::cout << &a` binnen en buiten de functie (bv. drie keer `...de0`). Omdat adressen per run verschillen, vergelijkt dit voorbeeld ze in code, zodat de output vast is.

#### Ambiguïteit tussen by value en by reference [▶ 18:46:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=67581s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: call of overloaded 'maximum(double&, double&)' is ambiguous
#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
const T& maximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    double a{23.5};
    double b{51.2};
    auto result = maximum(a, b);   // beide templates passen even goed
    std::cout << result << '\n';
    return 0;
}
```

#### C-strings zonder specialisatie: verkeerd resultaat [▶ 18:56:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68207s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// nocheck-output
#include <iostream>

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;   // T = const char*: vergelijkt pointers!
}

int main() {
    const char* g{"wild"};
    const char* h{"animal"};
    const char* result = maximum(g, h);
    std::cout << "max(const char*) : " << result << '\n';
    return 0;
}
```

Voorbeeldoutput (afhankelijk van waar de compiler de literals plaatst; de docent kreeg "animal"):

```text
max(const char*) : animal
```

#### Template specialization voor `const char*` [▶ 18:59:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68399s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <cstring>
#include <iostream>
#include <string>

// Primaire template
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Specialisatie: voor const char* deze implementatie gebruiken
template <>
const char* maximum<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;   // vergelijkt de tekst
}

int main() {
    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    std::string e{"hello"};
    std::string f{"world"};

    auto max_int = maximum(a, b);
    auto max_double = maximum(c, d);
    auto max_str = maximum(e, f);
    std::cout << "max_int : " << max_int << '\n';
    std::cout << "max_double : " << max_double << '\n';
    std::cout << "max_str : " << max_str << '\n';

    const char* g{"wild"};
    const char* h{"animal"};
    const char* result = maximum(g, h);   // kiest de specialisatie
    std::cout << "max(const char*) : " << result << '\n';
    return 0;
}
```

```text
max_int : 23
max_double : 34.7
max_str : world
max(const char*) : wild
```

### Valkuilen & veelgemaakte fouten

#### Denken dat een template echte code is
Een template wordt pas gecompileerd tot een functie als je hem aanroept. Fouten in de body voor een bepaald type zie je pas wanneer die instance gegenereerd wordt.

#### Operaties die het type niet ondersteunt
`multiply` met `std::string` → *no match for 'operator*'*. De foutmelding wijst naar de template-body en zegt "required from here" bij de aanroep.

#### Argumenten van verschillende types bij één `T`
`maximum(5.5, 7)` → *deduced conflicting types for parameter 'T'*. Los op met een explicit template argument (`maximum<double>(5.5, 7)`) of met gelijke types.

#### Resultaat in een te klein type opslaan
`int result = maximum(5.5, 78.7);` geeft 78. Gebruik `auto`.

#### Pointers vergelijken in plaats van waarden
`maximum(px, py)` en `maximum("wild", "animal")` vergelijken adressen. Het resultaat is willekeurig (in de demo 5 als maximum van 5 en 7, en "animal" i.p.v. "wild"). Gebruik template specialization of vergelijk de gederefereerde waarden.

#### By-value- en by-reference-template tegelijk
`T maximum(T, T)` naast `const T& maximum(const T&, const T&)` → *call of overloaded ... is ambiguous*.

#### Via een const reference wijzigen
`++a` in een functie met `const T& a` → *increment of read-only reference 'a'*.

#### Impliciete conversie die niet bestaat
`maximum<double>(a, e)` met `e` een `std::string` → compilerfout: string kan niet naar `double`.

### Best practices

- Gebruik een function template zodra meerdere overloads exact dezelfde logica hebben: één punt van controle.
- Gebruik `auto` om het resultaat van een template-aanroep op te vangen, zodat je het juiste type behoudt.
- Neem grotere types (zoals `std::string`) by `const T&` om kopieën te vermijden en wijzigingen te verbieden.
- Controleer dat elke operatie in de body werkt voor de types waarmee je de template gebruikt.
- Gebruik explicit template arguments wanneer de deduction niet doet wat je wilt of wanneer de argumenttypes verschillen.
- Schrijf een template specialization wanneer de standaardlogica voor een specifiek type (bv. `const char*`) fout is.
- Gebruik cppinsights.io en de call stack van de debugger om te zien welke instances er echt gegenereerd worden.

> 💡 Aanvulling: houd template-definities in de praktijk zichtbaar voor elke aanroeper (meestal in een header), want de compiler heeft de volledige blauwdruk nodig om een instance te genereren. In dit hoofdstuk staat alles in één bestand, dus dat speelt hier nog niet.

### Samenvatting

- Function templates zijn blauwdrukken: `template <typename T>` + een functie in termen van `T`.
- De compiler genereert template instances alleen voor de types die je effectief gebruikt, en hergebruikt ze.
- Template type deduction leidt `T` af uit de argumenten; bij verschillende types voor één `T` krijg je een fout.
- Explicit template arguments (`maximum<double>(a, c)`) leggen `T` vast en laten impliciete conversies toe.
- Template parameter = wat in de template-declaratie staat; template argument = wat bij de aanroep wordt ingevuld.
- De body moet door het type ondersteund worden (`*` op strings bestaat niet).
- Met pointers vergelijkt een generieke template adressen, niet waarden.
- `const T&` geeft parameters by reference door: zelfde adres, geen kopie, niet wijzigbaar.
- Een by-value- en een by-reference-template met dezelfde vorm naast elkaar zijn ambigu.
- Template specialization (`template <>` + `maximum<const char*>`) vervangt de standaardlogica voor één type, bv. met `std::strcmp`.

### Oefeningen

1. Schrijf een function template `minimum` die de kleinste van twee waarden teruggeeft en test hem met `int`, `double` en `std::string`.
2. Schrijf een function template `add(T a, T b)`. Roep hem aan met een `int` en een `double` met een explicit template argument zodat het resultaat 7.5 is.
3. Schrijf een function template `print_address(const T& value)` die `true` teruggeeft als het adres van de parameter gelijk is aan een meegegeven pointer, en toon zo dat de parameter by reference wordt doorgegeven.
4. Schrijf een function template `is_equal(T a, T b)` die `a == b` teruggeeft, en een specialisatie voor `const char*` die `std::strcmp` gebruikt. Toon dat twee C-strings met dezelfde inhoud maar in verschillende arrays als gelijk worden herkend.
5. Schrijf een function template `max_of_pointees(T* a, T* b)` die de **waarden** vergelijkt waar de pointers naar wijzen en de grootste waarde teruggeeft. Test met `int` 5 en 7 (antwoord moet 7 zijn, ongeacht de adressen).

<details><summary>Uitwerking</summary>

Oefening 1:

```cpp
#include <iostream>
#include <string>

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    std::cout << minimum(5, 7) << '\n';
    std::cout << minimum(5.5, 2.25) << '\n';
    std::cout << minimum(std::string{"hello"}, std::string{"world"}) << '\n';
    return 0;
}
```

```text
5
2.25
hello
```

Oefening 2:

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x{5};
    double y{2.5};
    auto result = add<double>(x, y);   // x wordt impliciet double
    std::cout << result << '\n';
    return 0;
}
```

```text
7.5
```

Oefening 3:

```cpp
#include <iostream>

template <typename T>
bool print_address(const T& value, const T* expected) {
    return &value == expected;   // zelfde adres = geen kopie
}

int main() {
    double d{3.14};
    std::cout << std::boolalpha << print_address(d, &d) << '\n';
    return 0;
}
```

```text
true
```

Oefening 4:

```cpp
#include <cstring>
#include <iostream>

template <typename T>
bool is_equal(T a, T b) {
    return a == b;
}

template <>
bool is_equal<const char*>(const char* a, const char* b) {
    return std::strcmp(a, b) == 0;   // vergelijk de tekst
}

int main() {
    char s1[]{"hello"};
    char s2[]{"hello"};
    const char* p1{s1};
    const char* p2{s2};
    std::cout << std::boolalpha;
    std::cout << is_equal(5, 5) << '\n';
    std::cout << (p1 == p2) << '\n';        // pointers: verschillend
    std::cout << is_equal(p1, p2) << '\n';  // specialisatie: gelijk
    return 0;
}
```

```text
true
false
true
```

Oefening 5:

```cpp
#include <iostream>

template <typename T>
T max_of_pointees(T* a, T* b) {
    return (*a > *b) ? *a : *b;   // vergelijk waarden, niet adressen
}

int main() {
    int x{5};
    int y{7};
    std::cout << max_of_pointees(&x, &y) << '\n';
    return 0;
}
```

```text
7
```

</details>

---

<a id="h16"></a>

## Hoofdstuk 16 – C++20 concepts (19:04:31 – 20:15:40) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68671s)

### Leerdoelen

- Begrijpen wat een *concept* is en welk probleem het oplost bij function templates.
- Het verschil kennen tussen standaard-concepts uit `<concepts>` (zoals `std::integral` en `std::floating_point`) en zelfgebouwde concepts.
- De vier syntaxen beheersen om een concept op een function template toe te passen:
  1. `requires`-clause direct na de template-declaratie,
  2. het concept in plaats van `typename` in de template-parameterlijst,
  3. het concept vóór `auto` in een parameterlijst (abbreviated function template),
  4. een *trailing* `requires`-clause na de parameterlijst.
- Zelf concepts bouwen met het keyword `concept`, op basis van een type trait of van een `requires`-expressie.
- De soorten requirements in een `requires`-expressie kennen: *simple*, *nested* en *compound* requirements, en begrijpen dat een simple requirement alleen de **syntax** controleert, niet de **waarde**.
- Concepts combineren met `&&` en `||`.
- Concepts gebruiken op variabelen die met `auto` gedeclareerd worden.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 15 (function templates)**: concepts zijn een uitbreiding op templates. In hoofdstuk 15 heb je een function template gemaakt met `template <typename T>`; de compiler genereert dan een template-instantie per type waarmee je de functie aanroept. Concepts leggen beperkingen (*constraints*) op welke types daarvoor in aanmerking komen. Daar zag je ook al type traits (`std::is_integral_v<T>`) in combinatie met `static_assert` in de functie-body – precies wat concepts netter vervangen.
- **Hoofdstuk 15 (auto-parameters)**: `auto add(auto a, auto b)` genereert achter de schermen een function template. In dit hoofdstuk zet je een concept vóór `auto`.
- **Hoofdstuk 3 en 4 (datatypes, operaties)**: kennis over `sizeof`, `char`, `int`, `long long`, `double` en *integral promotion* (een `char + char` levert een `int` op) komt terug in de `TinyType`-voorbeelden.
- **Hoofdstuk 10 (std::string)**: `std::string` dient als voorbeeld van een type dat je kunt optellen (concatenatie) maar niet kunt vermenigvuldigen of ophogen.
- **Hoofdstuk 17 (classes)** volgt hierna; de docent wijst erop dat er ook concepts bestaan die vooral bij classes nuttig zijn.

### Uitleg

#### Wat zijn concepts en waarom bestaan ze?

Een concept is een mechanisme uit C++20 om **constraints op template-parameters** te leggen. Je kunt er bijvoorbeeld mee afdwingen dat een function template alleen met integral types (`char`, `int`, `long`, ...) aangeroepen mag worden. Wie de functie met een ander type aanroept, krijgt een **compilerfout**; de template-instantie wordt dan niet gegenereerd.

Concepts zijn een van de "grote vier" nieuwe features van C++20 (naast modules, coroutines en ranges).

Het probleem dat ze oplossen: in het vorige hoofdstuk kon je iets vergelijkbaars al doen met type traits en `static_assert`:

```c++
template <typename T>
void print_number(T n) {
    static_assert(std::is_integral_v<T>, "print_number() kan alleen integrals aan");
    std::cout << n << '\n';
}
```

Dat werkt, maar de controle zit dan verstopt in de **body** van de functie. Met concepts zit de beperking in de **declaratie** (de signatuur) van de functie zelf. Dat is schoner, beter leesbaar, en de compiler kan al bij het kiezen van de functie zeggen dat de constraints niet voldaan zijn.

Er zijn twee kanten aan concepts:

1. **Standaard concepts** uit de standaardbibliotheek (header `<concepts>`), bijvoorbeeld `std::integral` en `std::floating_point`. Op cppreference staat een lange lijst; sommige zijn vooral bedoeld voor classes.
2. **Eigen concepts** die je zelf bouwt als de standaard-concepts niet volstaan.

[▶ 19:04:47](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68687s)

#### De vier syntaxen om een concept toe te passen

Om concepts te gebruiken moet je `#include <concepts>` toevoegen.

**Syntax 1 – `requires`-clause na de template-declaratie**

```c++
template <typename T>
requires std::integral<T>
T add(T a, T b) { return a + b; }
```

Na het keyword `requires` zet je het concept met de template-parameter tussen punthaken. De function template werkt alleen als het concept voldaan is. Aanroepen met `char` of `int` werkt (integral types); aanroepen met `double` geeft een compilerfout.

Belangrijk: na `requires` mag eigenlijk **elke expressie staan die tijdens het compileren geëvalueerd kan worden en een `bool` oplevert**. Je kunt er dus ook een type trait neerzetten:

```c++
template <typename T>
requires std::is_integral_v<T>
T add(T a, T b) { return a + b; }
```

Evalueert de expressie naar `true`, dan is de constraint voldaan; bij `false` krijg je een compilerfout.

**Syntax 2 – concept in plaats van `typename`**

```c++
template <std::integral T>
T add(T a, T b) { return a + b; }
```

Het concept vervangt `typename`; het geldt dan voor elk type dat op de plaats van `T` komt.

**Syntax 3 – concept vóór `auto`**

```c++
auto add(std::integral auto a, std::integral auto b) { return a + b; }
```

Bij de `auto`-syntax (die achter de schermen ook een function template genereert) zet je het concept direct vóór `auto`. Elke parameter krijgt zijn eigen constraint.

**Syntax 4 – trailing `requires`-clause**

```c++
template <typename T>
T add(T a, T b) requires std::integral<T> { return a + b; }
```

De `requires`-clause staat nu ná de parameterlijst.

De docent erkent dat vier syntaxen veel is voor een eerste kennismaking, maar elk heeft situaties waarin hij het prettigst leest. Ze doen alle vier hetzelfde.

[▶ 19:08:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=68882s)

#### De demo in VS Code en de foutmelding

De docent begint met een onbeperkte template `add` en roept die aan met twee `char`s (10 en 20), twee `int`s (11 en 5) en twee `double`s (11.1 en 1.9). Zonder constraint compileert alles en krijg je 30, 16 en 13.

Daarna voegt hij `requires std::integral<T>` toe. De `char`- en `int`-aanroepen blijven werken; de `double`-aanroep geeft een fout. VS Code meldt alleen vaag "no instance of function template add matches the argument list", maar GCC is duidelijk:

```text
error: use of function 'T add(T, T) [with T = double]' with unsatisfied constraints
note: the required expression ... 
note: required for the satisfaction of 'integral<T>' [with T = double]
```

Uit zo'n melding lees je af: kijk naar de constraints van de functie, en je ziet meteen dat ze geen niet-integral types ondersteunt. Hetzelfde soort fout krijg je bij alle vier de syntaxen.

[▶ 19:16:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69368s)

> ⚠️ Onduidelijk in opname: de exacte tekst van de GCC-melding is niet volledig voorgelezen; bovenstaande is een benadering.

#### Eigen concepts bouwen met een type trait

De algemene vorm:

```c++
template <typename T>
concept MyIntegral = std::is_integral_v<T>;
```

- Template-declaratie met de parameter die je wilt beperken.
- Keyword `concept`, een naam, een `=`-teken.
- Daarna de requirement: hier een type trait (vereist `#include <type_traits>`). Vergeet de puntkomma niet.

Het concept is voldaan als de type trait tijdens het compileren `true` oplevert. De docent merkt op dat `std::integral` in de standaardbibliotheek precies zo gebouwd is.

Een eigen concept gebruik je met alle vier de syntaxen, net als een standaard-concept: `requires MyIntegral<T>`, `template <MyIntegral T>`, `MyIntegral auto a` of een trailing `requires MyIntegral<T>`.

[▶ 19:25:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69944s)

#### Eigen concepts bouwen met een `requires`-expressie

Als je meerdere voorwaarden of een stuk syntax wilt controleren, gebruik je een `requires`-expressie met een parameterlijst en accolades:

```c++
template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;   // a * b moet geldige syntax zijn voor T
};

template <typename T>
concept Incrementable = requires(T a) {
    a += 1;
    ++a;
    a++;
};
```

- Na `requires` volgt een parameterlijst: "denkbeeldige" variabelen van type `T` waarmee je de requirements kunt opschrijven. Ze bestaan niet echt tijdens het uitvoeren.
- Tussen de accolades staan statements, elk afgesloten met een puntkomma.
- Elk statement moet **geldige C++-syntax** zijn voor het type dat op de plaats van `T` komt.

`Multipliable` is voldaan voor `int` en `double`, maar niet voor `std::string` (twee strings vermenigvuldigen heeft geen betekenis). `Incrementable` faalt eveneens voor `std::string`. GCC zegt dan bijvoorbeeld dat de "required expression `++a` is invalid".

Cruciaal, en de docent herhaalt het meerdere keren: **dit controleert alleen of de syntax geldig is, niet wat de waarde van `a * b` is.**

[▶ 19:27:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69441s)

#### Soorten requirements in een `requires`-expressie

De docent noemt vier soorten:

1. **Simple requirement** – wat je tot nu toe zag: een expressie die geldig moet zijn.
2. **Nested requirement** – een extra `requires` binnen de accolades, die de **waarde** van een compile-time expressie controleert.
3. **Compound requirement** – een expressie tussen accolades, eventueel met `noexcept` en/of een eis op het resultaattype.
4. **Type requirement** – valt buiten de scope van de cursus en wordt niet behandeld.

[▶ 19:42:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=70960s)

**Simple requirement – de valkuil**

```c++
template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) < 4;   // simple requirement: controleert ALLEEN de syntax!
};
```

Je zou verwachten dat dit types van 4 bytes of meer weigert. Maar `sizeof(T) < 4` is voor elk type geldige syntax, dus het concept is altijd voldaan – ook voor `double` (8 bytes). De docent bewijst dat: met `double` compileert het programma gewoon.

[▶ 19:43:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71010s)

**Nested requirement**

```c++
template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) < 4;            // simple requirement (syntax)
    requires sizeof(T) < 4;   // nested requirement (waarde moet true zijn)
};
```

Met het extra `requires` vooraan wordt de expressie wél geëvalueerd: is ze `false`, dan faalt het concept. Nu geeft `double` de verwachte fout ("nested requirement 'sizeof(T) < 4' is not satisfied").

[▶ 19:45:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71108s)

**Het onverwachte probleem met het return-type**

De docent gebruikt de functie

```c++
TinyType auto add(TinyType auto a, TinyType auto b) { return a + b; }
```

en roept die aan met twee `char`s (67 en 56). Toch krijgt hij een fout: "deduced return type does not satisfy placeholder constraints". De oorzaak is **integral promotion**: rekenkundige operaties op types kleiner dan `int` worden niet direct uitgevoerd. De compiler zet de `char`s eerst impliciet om naar `int`, dus `a + b` is een `int`, en het afgeleide return-type wordt `int`. Omdat het return-type ook `TinyType auto` is, moet `int` aan het concept voldoen – en `sizeof(int)` is 4, niet kleiner dan 4.

Zijn oplossing: de voorwaarde veranderen in `sizeof(T) <= 4`. Dan compileert het, en het programma print resultaat 123 met `sizeof` 4. Dat bewijst dat de functie een `int` teruggeeft, ook al gaan er `char`s in.

[▶ 19:51:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71494s)

**Compound requirement**

```c++
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<int>;
};
```

- De expressie staat tussen accolades.
- Na `->` volgt een concept waaraan het **type van het resultaat** moet voldoen; hier moet het resultaat converteerbaar zijn naar `int`.
- Je kunt hier ook `noexcept` opnemen, om te eisen dat de expressie geen exceptions gooit; de docent laat dat liggen omdat exceptions nog niet behandeld zijn.

Gedrag in de demo:
- `char + char` → `int` → converteerbaar naar `int`: voldaan, resultaat 123, `sizeof` 4.
- `double + double` → `double` → converteerbaar naar `int`: voldaan, `sizeof` 8 (de functie geeft nu een `double` terug).
- `std::string + std::string` is geldige syntax (concatenatie), maar een `std::string` is **niet** converteerbaar naar `int`: fout ("`a + b` does not satisfy return-type-requirement"). Haal je de `-> std::convertible_to<int>` weg, dan compileert het wel.

[▶ 19:54:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71643s)

#### Concepts combineren met `&&` en `||`

Een `requires`-clause is een logische expressie; je kunt concepts dus combineren:

```c++
template <typename T>
requires std::integral<T> || std::floating_point<T>   // óf integral óf floating point
T add(T a, T b) { return a + b; }

template <typename T>
requires std::integral<T> && TinyType<T>              // integral én klein
T add(T a, T b) { return a + b; }
```

- Met `||` werkt de functie voor `int` en `double`, maar niet voor `std::string`.
- Met `&&` werkt `int` (integral, 4 bytes, en `TinyType` gebruikt hier `<= 4`). `double` faalt al op `std::integral` – volgens de docent zelf een slecht voorbeeld. Een beter voorbeeld is `long long`: wel integral, maar 8 bytes, dus `TinyType` faalt ("`sizeof(T) <= 4` is not satisfied"). Hij print `sizeof(long long)` om de 8 te tonen.

Je kunt een `requires`-expressie ook **inline** in de clause zetten:

```c++
template <typename T>
requires std::integral<T> && requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
}
T add(T a, T b) { return a + b; }
```

Dit is geldige syntax en werkt precies hetzelfde, maar de docent raadt het af: functiedeclaraties worden er erg onleesbaar van. Combineren met `&&`/`||` werkt in alle vier de syntaxen.

[▶ 19:59:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71979s)

#### Concepts en `auto`

Een concept vóór `auto` kun je, naast parameters, ook gebruiken bij het declareren van **variabelen**:

```c++
std::integral auto x = add(10, 5);        // ok: add geeft een int terug
std::floating_point auto y = add(10, 5);  // fout: int is geen floating point
std::floating_point auto z = 3.9;         // ok: 3.9 is een double-literal
std::floating_point auto w = 7;           // fout: 7 is een int-literal
```

Het concept controleert het type dat `auto` afleidt uit de initializer. De docent vindt het bij literals vrij nutteloos (je weet zelf wat je erin stopt), maar bij het resultaat van een functieaanroep kan het handig zijn: een functie met een ingewikkelde return-expressie maakt het lastig te overzien welk type je terugkrijgt, en zo krijg je een compilerfout als dat niet is wat je verwacht.

[▶ 20:09:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72562s)

### Codevoorbeelden

#### Zonder constraint: alles compileert [▶ 19:13:42](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69222s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    char a_0{10};
    char a_1{20};
    auto result_a = add(a_0, a_1);   // T = char
    // static_cast<int> zodat de getalwaarde geprint wordt, niet een (onzichtbaar) teken
    std::cout << "result_a : " << static_cast<int>(result_a) << std::endl;

    int b_0{11};
    int b_1{5};
    auto result_b = add(b_0, b_1);   // T = int
    std::cout << "result_b : " << result_b << std::endl;

    double c_0{11.1};
    double c_1{1.9};
    auto result_c = add(c_0, c_1);   // T = double
    std::cout << "result_c : " << result_c << std::endl;

    return 0;
}
```

```text
result_a : 30
result_b : 16
result_c : 13
```

#### Syntax 1–4 met std::integral [▶ 19:16:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69368s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

// Syntax 1: requires-clause na de template-declaratie
template <typename T>
requires std::integral<T>
T add1(T a, T b) {
    return a + b;
}

// Syntax 2: concept in plaats van typename
template <std::integral T>
T add2(T a, T b) {
    return a + b;
}

// Syntax 3: concept voor auto
auto add3(std::integral auto a, std::integral auto b) {
    return a + b;
}

// Syntax 4: trailing requires-clause
template <typename T>
T add4(T a, T b) requires std::integral<T> {
    return a + b;
}

int main() {
    char a_0{10};
    char a_1{20};
    int b_0{11};
    int b_1{5};

    std::cout << "add1 char : " << static_cast<int>(add1(a_0, a_1)) << std::endl;
    std::cout << "add1 int  : " << add1(b_0, b_1) << std::endl;
    std::cout << "add2 int  : " << add2(b_0, b_1) << std::endl;
    std::cout << "add3 int  : " << add3(b_0, b_1) << std::endl;
    std::cout << "add4 int  : " << add4(b_0, b_1) << std::endl;

    return 0;
}
```

```text
add1 char : 30
add1 int  : 16
add2 int  : 16
add3 int  : 16
add4 int  : 16
```

#### Aanroep met double schendt het concept [▶ 19:17:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=69464s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: double voldoet niet aan std::integral
#include <iostream>
#include <concepts>

template <typename T>
requires std::integral<T>
T add(T a, T b) {
    return a + b;
}

int main() {
    double c_0{11.1};
    double c_1{1.9};
    auto result_c = add(c_0, c_1);   // error: use of function ... with unsatisfied constraints
    std::cout << "result_c : " << result_c << std::endl;
    return 0;
}
```

#### Eigen concept MyIntegral via type trait [▶ 19:30:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=70235s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>
#include <type_traits>

// Eigen concept op basis van een type trait
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

// Syntax 1
template <typename T>
requires MyIntegral<T>
T add1(T a, T b) {
    return a + b;
}

// Syntax 2
template <MyIntegral T>
T add2(T a, T b) {
    return a + b;
}

// Syntax 3
auto add3(MyIntegral auto a, MyIntegral auto b) {
    return a + b;
}

// Syntax 4
template <typename T>
T add4(T a, T b) requires MyIntegral<T> {
    return a + b;
}

int main() {
    int x{6};
    int y{7};
    std::cout << add1(x, y) << " " << add2(x, y) << " "
              << add3(x, y) << " " << add4(x, y) << std::endl;

    // double d1{6.0}, d2{7.0};
    // add1(d1, d2);  // error: required for the satisfaction of 'MyIntegral<T>' [with T = double]
    return 0;
}
```

```text
13 13 13 13
```

#### Multipliable en Incrementable met een requires-expressie [▶ 19:35:24](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=70524s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

// Alleen de syntax a * b moet geldig zijn; de waarde wordt niet gecontroleerd
template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;
};

// Meerdere statements, elk met een puntkomma
template <typename T>
concept Incrementable = requires(T a) {
    a += 1;
    ++a;
    a++;
};

template <typename T>
requires Multipliable<T>
T add_m(T a, T b) {
    return a + b;
}

template <typename T>
requires Incrementable<T>
T add_i(T a, T b) {
    return a + b;
}

int main() {
    double x{6.0};
    double y{7.0};
    std::cout << "add_m : " << add_m(x, y) << std::endl;   // double is multipliable
    std::cout << "add_i : " << add_i(x, y) << std::endl;   // double is incrementable
    return 0;
}
```

```text
add_m : 13
add_i : 13
```

#### std::string voldoet niet aan Multipliable/Incrementable [▶ 19:37:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=70671s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: strings kun je niet vermenigvuldigen of ophogen
#include <iostream>
#include <string>
#include <concepts>

template <typename T>
concept Incrementable = requires(T a) {
    a += 1;
    ++a;
    a++;
};

template <typename T>
requires Incrementable<T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::string x{"Hello"};
    std::string y{"World"};
    std::cout << add(x, y) << std::endl;   // error: the required expression '++a' is invalid
    return 0;
}
```

#### TinyType: simple requirement controleert alleen syntax [▶ 19:46:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71203s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) < 4;   // simple requirement: alleen syntax, waarde wordt NIET gecontroleerd
};

TinyType auto add(TinyType auto a, TinyType auto b) {
    return a + b;
}

int main() {
    double x{67};
    double y{56};
    // Compileert, ook al is sizeof(double) == 8!
    std::cout << "result : " << add(x, y) << std::endl;
    return 0;
}
```

```text
result : 123
```

#### TinyType met nested requirement en het return-type-probleem [▶ 19:50:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71446s)

Eerst de versie met `< 4`, die met `char`-argumenten toch faalt door integral promotion:

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: char + char geeft int (4 bytes), dus het afgeleide return-type voldoet niet aan TinyType
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) < 4;
    requires sizeof(T) < 4;   // nested requirement: waarde moet true zijn
};

TinyType auto add(TinyType auto a, TinyType auto b) {
    return a + b;   // error: deduced return type does not satisfy placeholder constraints
}

int main() {
    char x{67};
    char y{56};
    auto result = add(x, y);
    std::cout << "result : " << static_cast<int>(result) << std::endl;
    return 0;
}
```

De oplossing van de docent: `<=` in plaats van `<`.

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;            // simple requirement
    requires sizeof(T) <= 4;   // nested requirement
};

TinyType auto add(TinyType auto a, TinyType auto b) {
    return a + b;   // char + char wordt int (integral promotion)
}

int main() {
    char x{67};
    char y{56};
    auto result = add(x, y);
    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;   // 4: het is een int
    return 0;
}
```

```text
result : 123
sizeof(result) : 4
```

#### Compound requirement: Addable [▶ 19:54:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71691s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<int>;   // a + b geldig EN resultaat converteerbaar naar int
};

Addable auto add(Addable auto a, Addable auto b) {
    return a + b;
}

int main() {
    char c1{67};
    char c2{56};
    auto r1 = add(c1, c2);   // int
    std::cout << "result : " << r1 << ", sizeof : " << sizeof(r1) << std::endl;

    double d1{67};
    double d2{56};
    auto r2 = add(d1, d2);   // double (double is converteerbaar naar int)
    std::cout << "result : " << r2 << ", sizeof : " << sizeof(r2) << std::endl;
    return 0;
}
```

```text
result : 123, sizeof : 4
result : 123, sizeof : 8
```

#### Compound requirement faalt voor std::string [▶ 19:57:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=71834s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: x + y is geldig, maar std::string is niet converteerbaar naar int
#include <iostream>
#include <string>
#include <concepts>

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<int>;
};

Addable auto add(Addable auto a, Addable auto b) {
    return a + b;
}

int main() {
    std::string x{"Hello"};
    std::string y{"World"};
    auto s = x + y;   // dit op zich werkt prima (concatenatie)
    std::cout << s << std::endl;
    auto result = add(x, y);   // error: 'a + b' does not satisfy return-type-requirement
    std::cout << result << std::endl;
    return 0;
}
```

#### Concepts combineren met || en && [▶ 20:02:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72125s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

// Integral OF floating point
template <typename T>
requires std::integral<T> || std::floating_point<T>
T add_or(T a, T b) {
    return a + b;
}

// Integral EN klein
template <typename T>
requires std::integral<T> && TinyType<T>
T add_and(T a, T b) {
    return a + b;
}

// Inline requires-expressie (werkt, maar slecht leesbaar)
template <typename T>
requires std::integral<T> && requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
}
T add_inline(T a, T b) {
    return a + b;
}

int main() {
    int x{6};
    int y{4};
    std::cout << "add_or int     : " << add_or(x, y) << std::endl;

    double dx{6.5};
    double dy{4.5};
    std::cout << "add_or double  : " << add_or(dx, dy) << std::endl;

    int a{7};
    int b{5};
    std::cout << "add_and int    : " << add_and(a, b) << std::endl;
    std::cout << "add_inline int : " << add_inline(a, b) << std::endl;

    // long long is integral, maar 8 bytes: TinyType faalt
    std::cout << "sizeof(long long) : " << sizeof(long long) << std::endl;
    return 0;
}
```

```text
add_or int     : 10
add_or double  : 11
add_and int    : 12
add_inline int : 12
sizeof(long long) : 8
```

#### long long schendt TinyType [▶ 20:06:55](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72415s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: long long is integral maar sizeof == 8, dus TinyType niet voldaan
#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires(T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

template <typename T>
requires std::integral<T> && TinyType<T>
T add(T a, T b) {
    return a + b;
}

int main() {
    long long x{7};
    long long y{5};
    std::cout << add(x, y) << std::endl;   // error: nested requirement 'sizeof(T) <= 4' is not satisfied
    return 0;
}
```

#### Concepts op auto-variabelen [▶ 20:11:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72706s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <concepts>

std::integral auto add(std::integral auto a, std::integral auto b) {
    return a + b;
}

int main() {
    // add(10.9, 0.1);   // error: double-literals voldoen niet aan std::integral

    std::integral auto x = add(10, 5);   // add geeft int terug: voldaan
    std::cout << "x : " << x << std::endl;

    // std::floating_point auto y = add(10, 5);   // error: int is geen floating point

    std::floating_point auto z = 3.9;    // 3.9 is een double-literal: voldaan
    std::cout << "z : " << z << std::endl;

    // std::floating_point auto w = 7;   // error: 7 is een int-literal
    return 0;
}
```

```text
x : 15
z : 3.9
```

#### Variabele met verkeerd type wordt geweigerd [▶ 20:13:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72802s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: add geeft een int, maar de variabele eist std::floating_point
#include <iostream>
#include <concepts>

std::integral auto add(std::integral auto a, std::integral auto b) {
    return a + b;
}

int main() {
    std::floating_point auto y = add(10, 5);   // error: constraints not satisfied
    std::cout << y << std::endl;
    return 0;
}
```

### Valkuilen & veelgemaakte fouten

#### Simple requirement controleert geen waarde
`requires(T t) { sizeof(T) < 4; }` is voor elk type voldaan, omdat alleen de syntax gecontroleerd wordt. Wil je dat de expressie `true` oplevert, gebruik dan een **nested requirement**: `requires sizeof(T) < 4;`. Hetzelfde geldt voor `a * b;`: dat zegt niets over de uitkomst.

#### Integral promotion en een beperkt return-type
Bij `TinyType auto add(TinyType auto a, TinyType auto b)` moet ook het afgeleide return-type aan het concept voldoen. `char + char` wordt `int`, dus een concept dat `sizeof < 4` eist faalt, ook al geef je `char`s mee. Let op met constraints op een `auto`-return-type.

#### `<concepts>` en `<type_traits>` vergeten
Zonder `#include <concepts>` kent de compiler `std::integral` en `std::floating_point` niet. Gebruik je `std::is_integral_v` in een eigen concept, dan heb je `<type_traits>` nodig.

#### Vage foutmelding in de editor
VS Code (IntelliSense) zegt alleen "no instance of function template matches the argument list" en noemt het concept niet. Compileer met GCC: daar staat "unsatisfied constraints" en "required for the satisfaction of ...", met het concept dat faalt.

#### Puntkomma's vergeten
Een concept-definitie eindigt met een puntkomma (`concept MyIntegral = std::is_integral_v<T>;`) en elke requirement binnen de accolades ook. Bij een inline `requires`-expressie in een `requires`-clause komt er juist **geen** puntkomma na de sluitende accolade (de docent moest die weghalen).

#### Een ongeschikt testtype kiezen
Om `std::integral<T> && TinyType<T>` te testen is `double` een slecht voorbeeld: het faalt al op `std::integral`. Neem `long long` om specifiek `TinyType` te laten falen.

#### `char` printen met `std::cout`
Een functie die `char` teruggeeft, print een teken, geen getal (`char` 30 is een onzichtbaar stuurteken). Gebruik `static_cast<int>` als je de getalwaarde wilt zien.

> 💡 Aanvulling: de docent noemt in de opname bij `char` het bereik 0–255; of `char` signed (−128..127) of unsigned is, hangt af van het platform. Op GCC/x86 is `char` meestal signed.

### Best practices

- Zet constraints in de **signatuur** met concepts in plaats van `static_assert` in de body: leesbaarder, en de fout verwijst direct naar de constraint.
- Gebruik eerst de standaard-concepts uit `<concepts>` (zie cppreference); bouw pas een eigen concept als die niet volstaan.
- Kies de syntax die het leesbaarst is: `template <std::integral T>` of `std::integral auto` voor één eenvoudige constraint, een `requires`-clause voor combinaties.
- Geef een eigen concept een duidelijke naam (`Multipliable`, `Incrementable`, `TinyType`) en definieer het apart, in plaats van een `requires`-expressie inline in de functiedeclaratie te zetten.
- Gebruik een nested requirement als je een **waarde** wilt controleren en een compound requirement als je een eis stelt aan het **type van het resultaat**.
- Gebruik concepts op variabelen vooral voor het resultaat van functieaanroepen waarvan het return-type niet direct duidelijk is; bij literals voegt het weinig toe.
- Test een concept altijd met een type dat moet slagen én met een type dat moet falen.

### Samenvatting

- Een concept is een compile-time constraint op template-parameters (C++20, header `<concepts>`); wordt het geschonden, dan krijg je een compilerfout en geen template-instantie.
- Concepts vervangen type traits + `static_assert` in de body door constraints in de declaratie.
- Vier syntaxen: `requires C<T>` na `template<...>`, `template <C T>`, `C auto param` en een trailing `requires C<T>`.
- Na `requires` mag elke compile-time `bool`-expressie staan, ook een type trait.
- Eigen concept: `template <typename T> concept Naam = <bool-expressie>;` of `= requires(T a, ...) { ... };`.
- Simple requirement: controleert alleen syntax. Nested requirement (`requires expr;`): controleert de waarde. Compound requirement (`{ expr } -> concept;`): controleert ook het resultaattype.
- Concepts combineer je met `&&` en `||`; inline `requires`-expressies kunnen, maar zijn slecht leesbaar.
- `C auto x = ...;` legt een concept op het afgeleide type van een variabele.
- Pas op voor integral promotion: `char + char` is `int`.

### Oefeningen

1. Schrijf een function template `multiply` die alleen met floating-point types werkt, met syntax 2 (`template <std::floating_point T>`). Roep hem aan met twee `double`s (2.5 en 4.0) en print het resultaat.
2. Maak een eigen concept `Signed` op basis van de type trait `std::is_signed_v<T>`. Gebruik het met een trailing `requires`-clause in een functie `negate(T x)` die `-x` teruggeeft. Test met `int` (5) en `double` (2.5).
3. Bouw een concept `Dividable` met een compound requirement: `a / b` moet geldig zijn en het resultaat moet converteerbaar zijn naar `double`. Schrijf `auto divide(Dividable auto a, Dividable auto b)` en test met `int`s (7 en 2) en `double`s (7.0 en 2.0).
4. Bouw een concept `SmallIntegral` dat eist dat een type integral is **en** hoogstens 2 bytes groot (gebruik `&&` en een nested requirement). Gebruik het in `template <SmallIntegral T> int twice(T x)` die `x * 2` als `int` teruggeeft. Test met `short` (300) en `char` (21). Controleer met `static_assert` dat `SmallIntegral<int>` false is.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <concepts>

template <std::floating_point T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    std::cout << "multiply : " << multiply(2.5, 4.0) << std::endl;
    return 0;
}
```

```text
multiply : 10
```

```cpp
#include <iostream>
#include <concepts>
#include <type_traits>

template <typename T>
concept Signed = std::is_signed_v<T>;

template <typename T>
T negate(T x) requires Signed<T> {
    return -x;
}

int main() {
    std::cout << "negate(5)   : " << negate(5) << std::endl;
    std::cout << "negate(2.5) : " << negate(2.5) << std::endl;
    // negate(5u);  // fout: unsigned int voldoet niet aan Signed
    return 0;
}
```

```text
negate(5)   : -5
negate(2.5) : -2.5
```

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept Dividable = requires(T a, T b) {
    { a / b } -> std::convertible_to<double>;
};

auto divide(Dividable auto a, Dividable auto b) {
    return a / b;
}

int main() {
    std::cout << "divide(7, 2)     : " << divide(7, 2) << std::endl;      // integer-deling
    std::cout << "divide(7.0, 2.0) : " << divide(7.0, 2.0) << std::endl;
    return 0;
}
```

```text
divide(7, 2)     : 3
divide(7.0, 2.0) : 3.5
```

```cpp
#include <iostream>
#include <concepts>

template <typename T>
concept SmallIntegral = std::integral<T> && requires {
    requires sizeof(T) <= 2;   // nested requirement: waarde wordt gecontroleerd
};

template <SmallIntegral T>
int twice(T x) {
    return x * 2;   // x wordt eerst naar int gepromoveerd
}

static_assert(!SmallIntegral<int>, "int is te groot");
static_assert(SmallIntegral<short>);

int main() {
    short s{300};
    char c{21};
    std::cout << "twice(short) : " << twice(s) << std::endl;
    std::cout << "twice(char)  : " << twice(c) << std::endl;
    return 0;
}
```

```text
twice(short) : 600
twice(char)  : 42
```

</details>

---

<a id="h17"></a>

## Hoofdstuk 17 – Classes (20:15:40 – 22:52:43) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72940s)

### Leerdoelen
- Begrijpen wat een class is: een **blueprint** voor een eigen type, waaruit je **objecten** maakt.
- Een class declareren met member variables (eigenschappen) en member functions/methods (gedrag).
- Het verschil tussen `public` en `private` kennen, en weten dat class-members standaard `private` zijn.
- Constructors schrijven (zonder en met parameters) en begrijpen wanneer de compiler zelf een default constructor genereert.
- `= default` gebruiken om de compiler een lege default constructor te laten maken.
- Private member variables benaderen via **getters** en **setters**.
- Een class verdelen over meerdere bestanden (`constants.h`, `cylinder.h`, `cylinder.cpp`), include guards gebruiken en de scope resolution operator `::` toepassen.
- Objecten beheren via pointers (stack- en heap-objecten) en de pointer access operator `->` gebruiken.
- Destructors schrijven, weten wanneer ze worden aangeroepen en in welke volgorde constructors en destructors lopen.
- De `this`-pointer gebruiken: adres van het huidige object, naamconflicten oplossen, chained calls (via pointers en references).
- Het verschil tussen `class` en `struct` kennen.
- Begrijpen hoe `sizeof` van een object tot stand komt (member variables, geen functies; boundary alignment; pointers en `std::string`).

### Verband met eerdere hoofdstukken
- **Hoofdstuk 3 (Variables & data types)**: tot nu toe gebruikten we ingebouwde types zoals `int` en `double`. Een class laat je zelf zo'n type bouwen dat je op dezelfde manier gebruikt (`Cylinder cylinder1;` net als `int x;`). Brace initialization (`double height{1};`) komt hier terug voor member variables.
- **Hoofdstuk 8 (Pointers)**: `new`/`delete`, dereferencen met `*`, dangling pointers, geheugenlekken en dubbel `delete` zijn essentieel voor heap-objecten, de `->`-operator en destructors.
- **Hoofdstuk 9 (References)**: chained calls via teruggegeven references; uitleg waarom references volgens de docent geen members kunnen zijn.
- **Hoofdstuk 10 (Strings)**: `std::string` en `std::string_view` worden als member- en parametertypes gebruikt; `sizeof(std::string)` wordt in de laatste les onderzocht.
- **Hoofdstuk 11 (Functions)**: ODR, declaratie vs. definitie en code over meerdere bestanden verdelen keren hier terug, nu voor member functions (`Cylinder::volume()` in `cylinder.cpp`). Pass by value verklaart waarom een destructor wordt aangeroepen voor een kopie in een functie.
- **Hoofdstuk 12 (Getting things out of functions)**: return by value bij getters (je krijgt een kopie) en return by reference/pointer bij chained setters.
- **Hoofdstuk 13 (Function overloading)**: meerdere constructors met verschillende parameterlijsten zijn gewoon overloads; de compiler kiest de best passende.

### Uitleg

#### Wat is een class?
Tot nu toe werkten we alleen met ingebouwde types. Wil je bijvoorbeeld een persoon (naam, leeftijd, adres) of een cilinder modelleren, dan heb je een **eigen type** nodig. Daarvoor bestaan classes. Een class is een **blueprint**: een beschrijving van hoe objecten van dat type eruitzien. Met die blueprint maak je in je programma echte **objecten** (ook wel *instances*) met hun eigen runtime-data.

De docent gebruikt als voorbeeld een **cilinder**. Die wordt volledig bepaald door twee eigenschappen:
- de **base radius** `r` (straal van het grondvlak)
- de **height** `h` (hoogte)

Daarmee kun je allerlei dingen berekenen, bijvoorbeeld het grondoppervlak (`π · r²`) en het volume (`grondoppervlak · h`).

Een class bestaat uit twee delen:
1. **Member variables** – de eigenschappen (properties) die het object definiëren, hier `base_radius` en `height` van type `double`.
2. **Member functions / methods** – het gedrag (behaviors): functies die iets doen met die eigenschappen, hier `volume()`.

[▶ 20:16:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=72999s)

#### Syntax van een class
```
class Cylinder {
public:
    // member functions
    double volume() { return PI * base_radius * base_radius * height; }

    // member variables
    double base_radius{1};
    double height{1};
};   // ← puntkomma is verplicht!
```
- Keyword `class`, de naam, een paar accolades en **een puntkomma na de sluitaccolade**. Vergeet je die puntkomma, dan krijg je een compilerfout.
- Een member function is een gewone functie (return type, naam, parameterlijst, body), maar ze leeft *binnen* de class. Daardoor kan ze de member variables direct gebruiken.
- Je gebruikt een object net als elke andere variabele: `Cylinder cylinder1;`. Members benader je met de **dot-notatie**: `cylinder1.volume()`, `cylinder1.base_radius = 10;`.
- Je kunt zoveel objecten maken als je wilt; elk object heeft zijn eigen waarden voor de member variables.

[▶ 20:18:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=73098s)

#### `public` en `private` – members zijn standaard private
Members van een class zijn **standaard `private`**: ze zijn alleen bruikbaar *binnen* de class (bijvoorbeeld in `volume()`), niet van buitenaf (bijvoorbeeld in `main`). Probeer je toch `cylinder1.volume()` aan te roepen zonder `public:`, dan zegt GCC:

```
error: 'double Cylinder::volume()' is private within this context
```

Met `public:` (keyword + dubbele punt) maak je alles wat erna komt publiek, **totdat** je verderop `private:` schrijft. Vanaf `private:` is alles weer alleen intern bereikbaar.

De docent laat zien dat alles `public` maken werkt (je kunt dan in `main` `cylinder1.base_radius` lezen en wijzigen), maar noemt dat **slecht ontwerp**: gebruikers van je class hoeven de interne gegevens niet te zien; ze willen alleen iets *doen* (bijvoorbeeld het volume opvragen). In de praktijk maak je member variables daarom `private` en geef je toegang via public functies. Methods van de class hebben altijd toegang tot alle members, ongeacht of die public of private zijn.

[▶ 20:27:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=73632s)

#### Wat kunnen member variables zijn?
Volgens de docent:
- Member variables kunnen gewone (stack-achtige) variabelen zijn, zoals `double base_radius`.
- Ze kunnen ook **pointers** zijn.
- Ze kunnen **geen references** zijn, omdat een reference nooit ongeïnitialiseerd mag blijven, terwijl je member variables bij de declaratie in de class juist ongeïnitialiseerd moet kunnen laten.

> 💡 Aanvulling: strikt genomen *kan* een reference wel een member zijn, maar dan moet hij in elke constructor via de *member initializer list* worden geïnitialiseerd (bv. `Wrapper(int& r) : ref{r} {}`), en wordt de class lastiger te kopiëren/toewijzen. De docent behandelt initializer lists hier nog niet; zijn advies "gebruik geen reference-members" is in de praktijk een goede vuistregel.

[▶ 20:36:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=74163s)

#### Constructors
Een **constructor** is een speciale method die de **compiler aanroept om een object te bouwen**. Kenmerken:
- **Geen return type** (ook geen `void`).
- **Dezelfde naam als de class** (`Cylinder`).
- Mag parameters hebben, maar hoeft niet.
- Wordt meestal gebruikt om de member variables in een gewenste begintoestand te zetten.
- Moet **`public`** zijn, anders kan het object van buitenaf niet gebouwd worden.

```
Cylinder() {                                // default constructor: geen parameters
    base_radius = 2.0;
    height = 2.0;
}
Cylinder(double rad_param, double height_param) {  // constructor met parameters
    base_radius = rad_param;
    height = height_param;
}
```
De parameters worden hier **by value** doorgegeven (fundamentele types, kopiëren is goedkoop); in de body werk je dus met kopieën van de argumenten.

Hoe kiest de compiler? Bij `Cylinder cylinder1;` (geen haakjes/argumenten) zoekt de compiler een constructor zonder parameters: de **default constructor**. Bij `Cylinder cylinder1(10, 4);` kiest hij de constructor die twee `double`s neemt, omdat die het best past (net als bij function overloading).

De docent bewijst dit met de debugger: zet een breakpoint op de regel waar het object wordt gemaakt. Vóór die regel bevat het object nog rommel (junk data). Met *step into* belandt je in de constructor; daar zie je eerst `base_radius` en daarna `height` veranderen. Na het verlaten van de constructor is het object volledig opgebouwd.

[▶ 20:37:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=74258s) · debugger: [▶ 20:45:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=74734s)

#### De door de compiler gegenereerde default constructor
Maar in de eerste les hadden we geen enkele constructor, en toch werkte `Cylinder cylinder1;`. Hoe kan dat? Als je **zelf geen enkele constructor** schrijft, genereert de compiler er een: een **lege default constructor** zonder parameters en met een lege body. Die laat de member variables zoals ze zijn (dus met de beginwaarden die je in de class hebt gegeven, zoals `{1}`). Dat is dezelfde situatie alsof je zelf `Cylinder() {}` schrijft.

[▶ 20:50:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75023s)

#### Defaulted constructors: `= default`
Belangrijk detail: **zodra je zelf een constructor schrijft** (bijvoorbeeld alleen die met twee parameters), genereert de compiler **géén** default constructor meer. `Cylinder cylinder1;` geeft dan:

```
error: no matching function for call to 'Cylinder::Cylinder()'
```

Wil je toch objecten zonder argumenten kunnen maken, dan moet je zelf een default constructor toevoegen. Dat kan met een lege `Cylinder() {}`, maar korter is:

```
Cylinder() = default;   // laat de compiler de lege default constructor genereren
```

Ook deze constructor moet in de `public`-sectie staan. Zet je hem onder `private:`, dan krijg je `'Cylinder::Cylinder()' is private within this context`.

[▶ 20:53:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75218s)

#### Setters en getters
Nu de member variables `private` zijn, kun je ze van buitenaf niet meer lezen of wijzigen. Dat los je op met public methods:
- **Getters** lezen een waarde: `double get_base_radius() { return base_radius; }`
- **Setters** wijzigen een waarde: `void set_base_radius(double rad_param) { base_radius = rad_param; }`

Omdat het members van de class zijn, hebben ze toegang tot de private data; omdat ze `public` zijn, kun je ze van buitenaf aanroepen. Zo doen ze "het vuile werk" voor de gebruiker. Let op: de getters hier geven **by value** terug, je krijgt dus een **kopie** van de member variable, niet het origineel. Een getter is een functie: vergeet de haakjes niet (`get_base_radius()`).

Maak je de setters `private`, dan krijg je in `main` weer de foutmelding *"is private within this context"*.

> 💡 Aanvulling: getters die het object niet wijzigen worden in moderne C++ meestal `const` gemaakt (`double get_base_radius() const`). De docent gebruikt dat hier nog niet.

[▶ 20:59:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75556s) · demo: [▶ 21:03:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75795s)

#### Een class over meerdere bestanden verdelen
Alles in `main.cpp` proppen is onoverzichtelijk. `main.cpp` hoort de *hoge-niveau* logica te bevatten; details horen in aparte bestanden. De docent doet dit in drie stappen:

1. **Constante naar `constants.h`.** `PI` is een implementatiedetail van de cilinder; gebruikers in `main` hebben er niets mee te maken. In een apart header-bestand kun je bovendien later nog veel meer constanten kwijt.
2. **Class naar `cylinder.h`.** `main.cpp` doet dan alleen `#include "cylinder.h"`. Vergelijk met `std::string`: je wilt het type gebruiken, niet zien hoe het gebouwd is. De preprocessor plakt de inhoud van een header letterlijk op de plaats van de `#include`.
3. **Declaratie en implementatie scheiden.** `cylinder.h` bevat alleen een "preview" van de class (prototypes), `cylinder.cpp` de implementaties.

[▶ 21:09:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=76179s)

#### Include guards
Als `cylinder.h` zelf `constants.h` include't (omdat `volume()` `PI` gebruikt), én `main.cpp` include't ook `constants.h`, dan komt `PI` na de preprocessor **twee keer** in `main.cpp` terecht:

```
error: redefinition of 'const double PI'
```

Oplossing: een **include guard** rond de inhoud van elke header:

```
#ifndef CONSTANTS_H     // als CONSTANTS_H nog niet gedefinieerd is ...
#define CONSTANTS_H     // ... definieer het dan ...
const double PI {3.1415926535897932384626433832795};   // ... en neem deze code op
#endif                  // einde van het bewaakte stuk
```

De eerste keer is `CONSTANTS_H` onbekend: de preprocessor definieert het en neemt de code op. Elke volgende keer is de naam al gedefinieerd en slaat hij alles tot `#endif` over. Je kunt de header dan zelfs duizend keer includen zonder problemen. De naam kies je zelf, gebruikelijk is `BESTANDSNAAM_H` (`CYLINDER_H` voor `cylinder.h`). De docent vergiste zich eerst door `CYLINDER_H` in `constants.h` te gebruiken; elke header moet een **eigen, unieke** naam krijgen.

> 💡 Aanvulling: veel compilers ondersteunen ook `#pragma once` als kortere variant; dat is niet officieel standaard, maar wel heel gangbaar.

[▶ 21:19:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=76756s)

#### Implementatie in een `.cpp`-bestand: de scope resolution operator `::`
Lezers van de header willen weten *wat* de class kan (er is een `volume()`), niet *hoe* het volume berekend wordt. Daarom verplaats je de bodies naar `cylinder.cpp`:

```
#include "cylinder.h"

Cylinder::Cylinder(double rad_param, double height_param) { ... }
double Cylinder::volume() { ... }   // return type staat vóór Cylinder::
```

- `cylinder.cpp` include't eerst `cylinder.h`, want de implementaties hebben de declaratie nodig.
- `Cylinder::` heet de **scope resolution operator**: hij vertelt de compiler dat deze functie in de scope van de class `Cylinder` leeft en de implementatie is van het gelijknamige prototype in de header.
- Het **return type** komt vóór `Cylinder::` (`double Cylinder::volume()`); constructors hebben geen return type.
- In de header blijft alleen het prototype over (`double volume();`). De default constructor (`= default`) laat de docent gewoon in de header staan: wat je in de header houdt en wat in de `.cpp`, beslis je zelf.
- Laat je de body **ook** in de header staan, dan heb je twee definities van dezelfde functie. De docent krijgt dan `Cylinder::Cylinder(double, double)` *redefined*. Zorg dus dat er na het verplaatsen geen definities meer in de header achterblijven.

> 💡 Aanvulling: de docent noemt dit een linkerfout, maar in dit geval is het al een **compilerfout** in `cylinder.cpp` (`redefinition of 'Cylinder::Cylinder(double, double)'`), omdat `cylinder.cpp` de header mét body include't en in hetzelfde bestand nog een definitie ziet. Een echte linkerfout (*multiple definition*) krijg je bijvoorbeeld als je een gewone (niet-member, niet-`inline`) functie in een header definieert die door twee `.cpp`-bestanden wordt ge-include't.

[▶ 21:22:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=76950s)

#### Objecten beheren via pointers en de `->`-operator
Vaak, vooral bij dynamische geheugenallocatie, beheer je objecten via pointers.

**Pointer naar een stack-object:**
```
Cylinder cylinder1(10, 10);
Cylinder* p_cylinder1 = &cylinder1;
```
`p_cylinder1.volume()` werkt niet: een pointer is geen object, het is een adres. GCC zegt dan *"request for member 'volume' in 'p_cylinder1', which is of pointer type"*. Je moet eerst dereferencen: `(*p_cylinder1).volume()` (de haakjes zijn nodig omdat `.` sterker bindt dan `*`). Dat is lelijk; daarom bestaat de **pointer access operator** (de docent noemt hem ook *pointer call operator*) `->`:

```
p_cylinder1->volume();   // identiek aan (*p_cylinder1).volume()
```
`->` laat de compiler de pointer intern dereferencen en dan de member aanroepen.

**Heap-object via `new`:**
```
Cylinder* p_cylinder2 = new Cylinder(100, 2);   // ruimte op de heap, constructor met 2 params
std::cout << p_cylinder2->volume();
delete p_cylinder2;                               // zelf vrijgeven!
```
De docent schrijft het `delete` meteen nadat hij `new` heeft getypt, zodat hij het niet vergeet. VS Code zet bij een pointer bij autocompletion zelf `.` om in `->`.

[▶ 21:30:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=77430s) · demo: [▶ 21:34:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=77672s)

#### Destructors
Een **destructor** is een speciale method die de **compiler aanroept wanneer een object sterft**. Hij is vooral nuttig als de constructor resources (bijvoorbeeld heap-geheugen) aanvraagt: de destructor is dé plek om die weer vrij te geven.

Syntax: tilde `~` + classnaam + **lege parameterlijst**:
```
~Dog();                  // declaratie in de class
Dog::~Dog() { ... }      // definitie buiten de class
```
- Een destructor heeft **nooit parameters** (dat geeft een compilerfout) en geen return type. Er is er dus maar één per class.
- Je kunt de body in de class zetten of buiten de class met `Dog::~Dog()`. De docent laat hier ook zien dat je member functions buiten de class kunt definiëren *in hetzelfde bestand*.

Voorbeeld uit de les: `Dog` heeft `std::string name`, `std::string breed` en `int* p_age{nullptr}`. De constructor doet `p_age = new int; *p_age = age_param;` en de destructor `delete p_age;`. De constructor neemt `std::string_view`-parameters om onnodige kopieën te vermijden (daarvoor `#include <string_view>`). Zonder die `delete` in de destructor zou elk `Dog`-object geheugen lekken.

**Wanneer wordt een destructor aangeroepen?**
1. Een **lokaal stack-object gaat out of scope** (einde van `main`, einde van een functie).
2. Een **heap-object wordt vrijgegeven met `delete`**.
3. Een object wordt **by value doorgegeven** aan een functie: de kopie in de functie wordt vernietigd als de functie eindigt.
4. Een lokaal object wordt **by value teruggegeven**: de lokale kopie kan vernietigd worden, maar compilers optimaliseren dit vaak weg, dus je ziet het niet gegarandeerd.

In de demo maakt de docent eerst `my_dog` in `main` (destructor-melding *na* "Done", omdat het object pas bij het einde van `main` sterft), daarna verplaatst hij het object naar `some_func()` (destructor-melding *vóór* "Done"). In de debugger zie je dat *step into* eerst in de `std::string_view`-code van de standaardbibliotheek belandt (omzetten van de string literal); met *step out* / *step over* kom je dan in de constructor, en bij het verlaten van `some_func` in de destructor.

[▶ 21:42:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=78152s) · demo: [▶ 21:47:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=78440s)

#### Pass by value en het pointer-member: een recept voor rampen
Als je `some_func(Dog dog_param)` met een `Dog` aanroept, moet de compiler het object **kopiëren**. Wij hebben (nog) niet verteld hoe dat moet (dat doe je met een *copy constructor*, die later in de cursus komt). Standaard kopieert de compiler **member voor member**: `name` en `breed` worden netjes gekopieerd, maar van `p_age` wordt alleen het **adres** gekopieerd, niet de `int` waarnaar het wijst. Gevolg:
- Jouw eigen constructor wordt voor de kopie **niet** aangeroepen (je ziet geen extra constructor-melding).
- Beide objecten wijzen naar hetzelfde heap-geheugen.
- Als de functie eindigt, doet de destructor van de kopie `delete p_age`; aan het einde van `main` doet het origineel nóg eens `delete` op hetzelfde adres. **Dubbel `delete` is undefined behavior** en kan je programma laten crashen.

De docent haalt dit voorbeeld weer weg omdat het verwarrend is; het belangrijkste punt is dat een by-value parameter een kopie is die bij het einde van de functie vernietigd wordt (destructor-aanroep).

[▶ 21:58:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79119s)

#### Heap-objecten: zonder `delete` geen destructor
In `some_func` maakt de docent `Dog* p_dog = new Dog("Fluffy", "Shepherd", 2);`. Zonder `delete` zie je wel de constructor-melding, maar **nooit** de destructor-melding: de pointer `p_dog` (zelf een stack-variabele) verdwijnt bij het einde van de functie, het object op de heap blijft achter → **geheugenlek**. Met `delete p_dog;` wordt de destructor wel aangeroepen.

[▶ 22:02:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79359s)

#### Volgorde van constructor- en destructor-aanroepen
Maak je in `main` vier `Dog`-objecten `dog1` t/m `dog4`, dan worden de **constructors in volgorde van creatie** aangeroepen (1, 2, 3, 4), maar de **destructors in omgekeerde volgorde** (4, 3, 2, 1). Het object dat het laatst is gemaakt, wordt als eerste vernietigd.

Uitleg van de docent: een object dat al lang bestaat, kan objecten hebben die ervan afhankelijk zijn (die later gemaakt zijn). Door het laatst gemaakte object eerst op te ruimen, voorkom je dat je een object vernietigt waar nog iets van afhangt. Het is dezelfde logica als een stack: last in, first out.

[▶ 22:05:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79502s)

#### De `this`-pointer
`this` is een speciale pointer die C++ in elke (niet-statische) member function beschikbaar stelt. Hij wijst naar **het huidige object**: het object waarvoor de method op dat moment wordt uitgevoerd. De docent toont drie toepassingen:

**1. Het adres van het huidige object tonen.** In constructor en destructor: `std::cout << "... at " << this << std::endl;`. Zonder `this` zou je het adres alleen kunnen opvragen waar het object gemaakt wordt (bijvoorbeeld in `main`); met `this` heb je het binnen de class zelf.

**2. Naamconflicten oplossen.** Heeft een parameter dezelfde naam als een member variable, dan is
```
void set_dog_name(std::string_view name) {
    name = name;   // ❌ wijst de parameter aan zichzelf toe!
}
```
fout. De docent dacht eerst dat GCC dit automatisch als `this->name = name` interpreteert (het compileert immers), maar ontdekt bij het printen dat de naam **niet** verandert: de parameter verbergt (shadows) de member, en de regel wijst de parameter aan zichzelf toe. Dat doet niets. Correct is:
```
this->name = name;   // member = parameter
```
Voor het pointer-member `p_age` wordt het `*(this->p_age) = age;` (eerst `this->p_age` ophalen, dan dereferencen).

**3. Chained calls.** Laat elke setter het huidige object teruggeven, dan kun je setters aan elkaar rijgen:
- **Via pointers**: return type `Dog*`, `return this;`. Aanroep: `dog1.set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);` – na de eerste call heb je een pointer, dus verder met `->`.
- **Via references**: return type `Dog&`, `return *this;` (eerst dereferencen, want `this` is een pointer en je wilt het object zelf als reference teruggeven). Aanroep: `dog1.set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier").set_dog_age(4);` – overal de dot-notatie.

De docent gebruikt dit naar eigen zeggen zelf veel in zijn classes: gebruikers kunnen dan alles in één statement instellen in plaats van drie.

[▶ 22:10:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79836s) · demo: [▶ 22:17:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=80226s) · chained calls: [▶ 22:27:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=80845s)

#### `struct`
Met het keyword `struct` maak je **precies hetzelfde** als met `class`. Het **enige verschil** zit in de standaardtoegang:
- `class`: members standaard **`private`**
- `struct`: members standaard **`public`**

Met expliciete `public:`/`private:`-secties kun je die defaults in beide gevallen overschrijven; dan gedragen ze zich identiek. De docent introduceert hier ook de veelgebruikte naamconventie `m_name` (`m_` = member variable).

Gangbaar gebruik van `struct`: types die **alleen publieke data** bevatten en (bijna) geen methods, zoals een punt met `x` en `y`. Andere C++-ontwikkelaars herkennen die bedoeling meteen, wat je code leesbaarder maakt. De functie `print_point` neemt de struct als `const Point&`, zodat er niets gekopieerd wordt.

[▶ 22:33:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81180s) · Point: [▶ 22:39:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81565s)

#### Grootte van objecten (`sizeof`)
De grootte van een object wordt **alleen bepaald door de member variables**, (ongeveer) de som van hun groottes.
- **Functies tellen niet mee.** Methods horen bij de class (de blueprint), niet bij elk afzonderlijk object; ze staan één keer ergens in het geheugen. Twee extra methods toevoegen verandert `sizeof` dus niet.
- `sizeof(Dog)` en `sizeof(dog1)` (type of objectnaam) geven hetzelfde.
- Een **pointer-member** telt alleen als de grootte van de pointer zelf (8 bytes op een 64-bit systeem), ongeacht hoe groot hetgeen is waarnaar hij wijst.
- **`std::string`** is zelf een class die zijn tekst via een (char-)pointer beheert. Daarom is `sizeof` van een string altijd hetzelfde (32 bytes bij de docent), of de tekst nu `"Hello World"` of `"I am the king of the universe"` is.

Op de machine van de docent: `sizeof(size_t)` = 8, een class met één `size_t` = 8, met twee = 16, met twee `size_t` en een `int*` = 24.

**Boundary alignment**: de som klopt niet altijd. Compilers plaatsen members op adressen die een veelvoud zijn van hun grootte (een 4-byte `int` op een veelvoud van 4). Combineer je members van verschillende groottes (bijvoorbeeld 2 en 4 bytes), dan ontstaan er **gaten (padding)** tussen de members en is `sizeof` iets groter dan de optelsom. De docent toont dit alleen in de slides, niet in code.

[▶ 22:41:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81710s) · alignment: [▶ 22:44:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81854s) · demo: [▶ 22:45:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81948s)

### Codevoorbeelden

#### Je eerste class: Cylinder met public members [▶ 20:23:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=73390s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:                       // alles hieronder is van buitenaf bereikbaar
    // member function (behavior)
    double volume() {
        return PI * base_radius * base_radius * height;
    }

    // member variables (properties) - public = slecht ontwerp, alleen ter demo
    double base_radius{1};
    double height{1};
};    // puntkomma niet vergeten!

int main() {
    Cylinder cylinder1;       // object gemaakt uit de blueprint
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    std::cout << "base_radius : " << cylinder1.base_radius << std::endl;
    std::cout << "height : " << cylinder1.height << std::endl;

    // member variables wijzigen via de dot-notatie
    cylinder1.base_radius = 10;
    cylinder1.height = 3;
    std::cout << "volume : " << cylinder1.volume() << std::endl;   // pi * 100 * 3

    cylinder1.height = 8;
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    Cylinder cylinder2;       // tweede, onafhankelijk object
    std::cout << "volume cylinder2 : " << cylinder2.volume() << std::endl;
    return 0;
}
```
```text
volume : 3.14159
base_radius : 1
height : 1
volume : 942.478
volume : 2513.27
volume cylinder2 : 3.14159
```

#### Members zijn standaard private [▶ 20:27:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=73632s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: volume() en de member variables zijn private (geen public:)
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
    double volume() {                 // private: alleen binnen de class bruikbaar
        return PI * base_radius * base_radius * height;
    }
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1;
    std::cout << cylinder1.volume() << std::endl;   // error: 'double Cylinder::volume()' is private within this context
    std::cout << cylinder1.height << std::endl;     // error: 'double Cylinder::height' is private within this context
    return 0;
}
```

#### Goed ontwerp: private data, public method [▶ 20:31:12](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=73872s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:
    double volume() {
        // binnen de class mogen we private members gewoon gebruiken
        return PI * base_radius * base_radius * height;
    }

private:                      // alles hieronder is alleen intern bereikbaar
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1;
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    // cylinder1.base_radius = 10;   // zou nu een compilerfout geven
    return 0;
}
```
```text
volume : 3.14159
```

#### Constructors: default en met parameters [▶ 20:42:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=74542s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:
    // Constructors: geen return type, zelfde naam als de class
    Cylinder() {                                       // default constructor
        base_radius = 2.0;
        height = 2.0;
    }
    Cylinder(double rad_param, double height_param) {  // constructor met parameters
        base_radius = rad_param;
        height = height_param;
    }

    double volume() {
        return PI * base_radius * base_radius * height;
    }

private:
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1;           // geen argumenten -> default constructor (2, 2)
    std::cout << "volume cylinder1 : " << cylinder1.volume() << std::endl;

    Cylinder cylinder2(10, 4);    // twee doubles -> constructor met parameters
    std::cout << "volume cylinder2 : " << cylinder2.volume() << std::endl;
    return 0;
}
```
```text
volume cylinder1 : 25.1327
volume cylinder2 : 1256.64
```

#### Geen eigen constructor: de compiler genereert een lege [▶ 20:50:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75023s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:
    // Geen constructors geschreven: de compiler genereert in feite
    // Cylinder() {}  -> member variables houden hun beginwaarden {1}
    double volume() {
        return PI * base_radius * base_radius * height;
    }

private:
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1;   // gebruikt de door de compiler gegenereerde default constructor
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    return 0;
}
```
```text
volume : 3.14159
```

#### Defaulted constructor met `= default` [▶ 20:55:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75316s)
Zonder de regel `Cylinder() = default;` geeft `Cylinder cylinder1;` hier de fout *no matching function for call to 'Cylinder::Cylinder()'*, omdat er al een eigen constructor is.
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:                           // constructors moeten public zijn
    Cylinder() = default;         // compiler genereert de lege default constructor
    Cylinder(double rad_param, double height_param) {
        base_radius = rad_param;
        height = height_param;
    }

    double volume() {
        return PI * base_radius * base_radius * height;
    }

private:
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1;           // werkt dankzij = default
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    return 0;
}
```
```text
volume : 3.14159
```

#### Setters en getters [▶ 21:03:15](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=75795s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:
    // Constructors
    Cylinder() = default;
    Cylinder(double rad_param, double height_param) {
        base_radius = rad_param;
        height = height_param;
    }

    // Functions (methods)
    double volume() {
        return PI * base_radius * base_radius * height;
    }

    // Getters: geven een KOPIE terug (return by value)
    double get_base_radius() { return base_radius; }
    double get_height() { return height; }

    // Setters: wijzigen de private member variables
    void set_base_radius(double rad_param) { base_radius = rad_param; }
    void set_height(double height_param) { height = height_param; }

private:
    double base_radius{1};
    double height{1};
};

int main() {
    Cylinder cylinder1(10, 10);
    // std::cout << cylinder1.base_radius;   // fout: private
    std::cout << "base_radius : " << cylinder1.get_base_radius() << std::endl;
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    // via de setters het object wijzigen
    cylinder1.set_base_radius(100);
    cylinder1.set_height(10);
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    return 0;
}
```
```text
base_radius : 10
volume : 3141.59
volume : 314159
```

#### Class in een header met include guards [▶ 21:19:16](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=76756s)
Stap 2 van de docent: de constante in `constants.h`, de volledige class (met bodies) in `cylinder.h`. Beide headers hebben een eigen include guard, dus `constants.h` meerdere keren includen is geen probleem.
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// file: constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

const double PI{3.1415926535897932384626433832795};

#endif
```
```cpp
// file: cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"   // volume() gebruikt PI

class Cylinder {
public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param) {
        base_radius = rad_param;
        height = height_param;
    }
    double volume() { return PI * base_radius * base_radius * height; }
    double get_base_radius() { return base_radius; }
    double get_height() { return height; }
    void set_base_radius(double rad_param) { base_radius = rad_param; }
    void set_height(double height_param) { height = height_param; }

private:
    double base_radius{1};
    double height{1};
};

#endif
```
```cpp
// file: main.cpp
#include <iostream>
#include "constants.h"   // dubbel ge-include (ook via cylinder.h) ...
#include "constants.h"   // ... maar dankzij de include guard geen redefinition
#include "cylinder.h"

int main() {
    Cylinder cylinder1(10, 10);
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    std::cout << "PI : " << PI << std::endl;
    return 0;
}
```
```text
volume : 3141.59
PI : 3.14159
```

#### Declaratie in `cylinder.h`, implementatie in `cylinder.cpp` [▶ 21:23:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=76999s)
Stap 3: de header bevat alleen nog de "preview" van de class; de bodies staan in `cylinder.cpp` met `Cylinder::`. Compileer met `g++ -std=c++20 main.cpp cylinder.cpp`. (`constants.h` is ongewijzigd ten opzichte van het vorige voorbeeld.)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// file: cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder {
public:
    // Constructors
    Cylinder() = default;                        // mag in de header blijven
    Cylinder(double rad_param, double height_param);

    // Functions
    double volume();

    // Getters
    double get_base_radius();
    double get_height();

    // Setters
    void set_base_radius(double rad_param);
    void set_height(double height_param);

private:
    double base_radius{1};
    double height{1};
};

#endif
```
```cpp
// file: cylinder.cpp
#include "cylinder.h"
#include "constants.h"

// Cylinder:: = scope resolution operator: deze functies horen bij class Cylinder
Cylinder::Cylinder(double rad_param, double height_param) {
    base_radius = rad_param;
    height = height_param;
}

double Cylinder::volume() {          // return type VOOR Cylinder::
    return PI * base_radius * base_radius * height;
}

double Cylinder::get_base_radius() { return base_radius; }
double Cylinder::get_height() { return height; }

void Cylinder::set_base_radius(double rad_param) { base_radius = rad_param; }
void Cylinder::set_height(double height_param) { height = height_param; }
```
```cpp
// file: main.cpp
// multi: cylinder.cpp
#include <iostream>
#include "cylinder.h"

int main() {
    Cylinder cylinder1(10, 10);
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    cylinder1.set_height(2);
    std::cout << "height : " << cylinder1.get_height() << std::endl;
    std::cout << "volume : " << cylinder1.volume() << std::endl;
    return 0;
}
```
```text
volume : 3141.59
height : 2
volume : 628.319
```

#### Twee definities van dezelfde constructor [▶ 21:28:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=77285s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Hier in één bestand samengevat: de class (zoals in de header, mét body) en daarna nog een definitie (zoals in `cylinder.cpp`).
```cpp
// ❌ bewust fout: constructor twee keer gedefinieerd -> redefinition of 'Cylinder::Cylinder(double, double)'
class Cylinder {
public:
    Cylinder(double rad_param, double height_param) {   // body in de header laten staan ...
        base_radius = rad_param;
        height = height_param;
    }
private:
    double base_radius{1};
    double height{1};
};

Cylinder::Cylinder(double rad_param, double height_param) {   // ... en nog eens in cylinder.cpp
    base_radius = rad_param;
    height = height_param;
}

int main() {
    Cylinder c(1, 1);
    return 0;
}
```

#### Objecten beheren via pointers en `->` [▶ 21:34:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=77672s)
De docent gebruikt de bestanden uit de vorige les; hier staat de class voor het gemak in hetzelfde bestand.
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder {
public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param) {
        base_radius = rad_param;
        height = height_param;
    }
    double volume() { return PI * base_radius * base_radius * height; }
    double get_base_radius() { return base_radius; }

private:
    double base_radius{1};
    double height{1};
};

int main() {
    // 1. Stack-object, gewone dot-notatie
    Cylinder cylinder1(10, 10);
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    // 2. Pointer naar een stack-object
    Cylinder* p_cylinder1 = &cylinder1;
    // p_cylinder1.volume();                 // fout: p_cylinder1 is een pointer
    std::cout << "volume : " << (*p_cylinder1).volume() << std::endl;   // lelijk
    std::cout << "volume : " << p_cylinder1->volume() << std::endl;     // pointer access operator

    // 3. Heap-object via new
    Cylinder* p_cylinder2 = new Cylinder(100, 2);
    std::cout << "volume (cylinder2) : " << p_cylinder2->volume() << std::endl;
    std::cout << "base_radius (cylinder2) : " << p_cylinder2->get_base_radius() << std::endl;

    delete p_cylinder2;                      // heap-geheugen zelf vrijgeven
    p_cylinder2 = nullptr;
    return 0;
}
```
```text
volume : 3141.59
volume : 3141.59
volume : 3141.59
volume (cylinder2) : 62831.9
base_radius (cylinder2) : 100
```
> ⚠️ Onduidelijk in opname: de docent typt eerst `100, 100` en verandert het tweede argument dan ("let's put the two after"); hier is `(100, 2)` aangenomen.

#### Destructor: stack-object in `main` [▶ 21:47:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=78440s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();                                  // destructor: tilde + classnaam, geen parameters

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};                     // leeftijd op de heap
};

// Definities buiten de class, in hetzelfde bestand
Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;                         // heap-geheugen aanvragen
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog() {
    delete p_age;                            // heap-geheugen vrijgeven, anders lek
    std::cout << "Dog destructor called for " << name << std::endl;
}

int main() {
    Dog my_dog("Fluffy", "Shepherd", 2);
    std::cout << "Done!" << std::endl;
    return 0;
}   // my_dog gaat hier out of scope -> destructor
```
```text
Dog constructor called for Fluffy
Done!
Dog destructor called for Fluffy
```

#### Destructor: lokaal object in een functie [▶ 21:54:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=78878s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog() {
    delete p_age;
    std::cout << "Dog destructor called for " << name << std::endl;
}

void some_func() {
    Dog my_dog("Fluffy", "Shepherd", 2);     // lokaal object
}   // einde functie -> destructor van my_dog

int main() {
    some_func();
    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
Dog constructor called for Fluffy
Dog destructor called for Fluffy
Done!
```

#### Pass by value met een pointer-member: dubbel `delete` [▶ 21:58:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79119s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// ❌ bewust fout: UB-demo - de standaard kopie deelt p_age, dus delete wordt twee keer op hetzelfde adres gedaan
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
        name = name_param;
        breed = breed_param;
        p_age = new int{age_param};
        std::cout << "Dog constructor called for " << name << std::endl;
    }
    ~Dog() {
        delete p_age;                 // kopie en origineel deleten HETZELFDE adres
        std::cout << "Dog destructor called for " << name << std::endl;
    }
private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

void some_func(Dog dog_param) {       // by value: member-voor-member kopie, onze constructor wordt NIET aangeroepen
}                                     // destructor van de kopie: delete p_age (1e keer)

int main() {
    Dog dog("Fluffy", "Shepherd", 2);
    some_func(dog);
    std::cout << "Done!" << std::endl;
    return 0;
}                                     // destructor van dog: delete p_age (2e keer!) -> undefined behavior
```

#### Heap-object: destructor alleen na `delete` [▶ 22:02:39](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79359s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog() {
    delete p_age;
    std::cout << "Dog destructor called for " << name << std::endl;
}

void some_func() {
    Dog* p_dog = new Dog("Fluffy", "Shepherd", 2);   // object op de heap
    // ... zonder de volgende regel: geen destructor en een geheugenlek
    delete p_dog;                                    // roept de destructor aan
}

int main() {
    some_func();
    std::cout << "Done!" << std::endl;
    return 0;
}
```
```text
Dog constructor called for Fluffy
Dog destructor called for Fluffy
Done!
```

#### Volgorde van constructors en destructors [▶ 22:08:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=79693s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog() {
    delete p_age;
    std::cout << "Dog destructor called for " << name << std::endl;
}

int main() {
    Dog dog1("Dog1", "Shepherd", 2);
    Dog dog2("Dog2", "Shepherd", 3);
    Dog dog3("Dog3", "Shepherd", 5);
    Dog dog4("Dog4", "Shepherd", 1);
    return 0;
}   // destructors in OMGEKEERDE volgorde: dog4, dog3, dog2, dog1
```
```text
Dog constructor called for Dog1
Dog constructor called for Dog2
Dog constructor called for Dog3
Dog constructor called for Dog4
Dog destructor called for Dog4
Dog destructor called for Dog3
Dog destructor called for Dog2
Dog destructor called for Dog1
```

#### `this`: adres van het huidige object [▶ 22:17:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=80226s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
        name = name_param;
        breed = breed_param;
        p_age = new int{age_param};
        // this = adres van het object dat nu gebouwd wordt
        std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
    }
    ~Dog() {
        delete p_age;
        std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
    }

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

int main() {
    Dog dog1("Fluffy", "Shepherd", 2);
    std::cout << "address of dog1 in main : " << &dog1 << std::endl;   // zelfde adres als this
    std::cout << "Done!" << std::endl;
    return 0;
}
```
Voorbeeldoutput (adressen verschillen per run/systeem):
```text
Dog constructor called for Fluffy at 0x5ffe60
address of dog1 in main : 0x5ffe60
Done!
Dog destructor called for Fluffy at 0x5ffe60
```

#### Naamconflict: `name = name` doet niets [▶ 22:20:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=80418s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. Het adres is in `print_info` weggelaten zodat de output vast is.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
        name = name_param;
        breed = breed_param;
        p_age = new int{age_param};
    }
    ~Dog() { delete p_age; }

    // FOUT: parameter verbergt de member; dit wijst de parameter aan zichzelf toe
    void set_dog_name_wrong(std::string_view name) {
        name = name;
    }
    // GOED: this->name is de member variable
    void set_dog_name(std::string_view name) {
        this->name = name;
    }

    void print_info() {
        std::cout << "Dog : [ name : " << name << ", breed : " << breed
                  << ", age : " << *p_age << " ]" << std::endl;
    }

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

int main() {
    Dog dog1("Fluffy", "Shepherd", 2);
    dog1.print_info();

    dog1.set_dog_name_wrong("Pumba");
    dog1.print_info();          // naam is NIET veranderd

    dog1.set_dog_name("Pumba");
    dog1.print_info();          // nu wel
    return 0;
}
```
```text
Dog : [ name : Fluffy, breed : Shepherd, age : 2 ]
Dog : [ name : Fluffy, breed : Shepherd, age : 2 ]
Dog : [ name : Pumba, breed : Shepherd, age : 2 ]
```

#### Chained calls via pointers en via references [▶ 22:27:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=80845s)
In de les zijn dit twee versies van dezelfde setters (de ene uitgecommentarieerd). Hier staan ze naast elkaar met verschillende namen zodat beide in één programma te zien zijn.
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
        name = name_param;
        breed = breed_param;
        p_age = new int{age_param};
    }
    ~Dog() { delete p_age; }

    // Chained calls via POINTERS: geef this terug
    Dog* set_dog_name(std::string_view name) {
        this->name = name;
        return this;
    }
    Dog* set_dog_breed(std::string_view breed) {
        this->breed = breed;
        return this;
    }
    Dog* set_dog_age(int age) {
        *(this->p_age) = age;           // pointer-member: eerst dereferencen
        return this;
    }

    // Chained calls via REFERENCES: geef *this terug
    Dog& set_name_ref(std::string_view name) {
        this->name = name;
        return *this;                   // this dereferencen -> het object zelf
    }
    Dog& set_breed_ref(std::string_view breed) {
        this->breed = breed;
        return *this;
    }
    Dog& set_age_ref(int age) {
        *(this->p_age) = age;
        return *this;
    }

    void print_info() {
        std::cout << "Dog : [ name : " << name << ", breed : " << breed
                  << ", age : " << *p_age << " ]" << std::endl;
    }

private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

int main() {
    Dog dog1("Fluffy", "Shepherd", 2);
    dog1.print_info();

    // pointers: na de eerste call verder met ->
    dog1.set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);
    dog1.print_info();

    // references: overal de dot-notatie
    dog1.set_name_ref("Rex").set_breed_ref("Labrador").set_age_ref(7);
    dog1.print_info();

    // ook via een pointer naar een heap-object
    Dog* p_dog = new Dog("Bello", "Poodle", 1);
    p_dog->set_dog_name("Max")->set_dog_age(3);
    p_dog->print_info();
    delete p_dog;
    return 0;
}
```
```text
Dog : [ name : Fluffy, breed : Shepherd, age : 2 ]
Dog : [ name : Pumba, breed : Wire Fox Terrier, age : 4 ]
Dog : [ name : Rex, breed : Labrador, age : 7 ]
Dog : [ name : Max, breed : Poodle, age : 3 ]
```

#### `class` vs. `struct` [▶ 22:36:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81373s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>
#include <string>

class Dog {
public:                       // zonder deze regel: m_name private -> compilerfout in main
    std::string m_name;       // m_ = member variable (naamconventie)
};

struct Cat {
    std::string m_name;       // struct: standaard public
};

int main() {
    Dog dog1;
    Cat cat1;

    dog1.m_name = "Fluffy";   // kan alleen dankzij public: in Dog
    cat1.m_name = "Johnny";   // kan altijd: struct is standaard public

    std::cout << dog1.m_name << std::endl;
    std::cout << cat1.m_name << std::endl;
    return 0;
}
```
```text
Fluffy
Johnny
```

#### `struct Point` voor pure data [▶ 22:39:25](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81565s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
#include <iostream>

struct Point {                // alleen publieke data, geen methods
    double x;
    double y;
};

void print_point(const Point& point) {      // const reference: geen kopie
    std::cout << "Point [ x : " << point.x << ", y : " << point.y << " ]" << std::endl;
}

int main() {
    Point point1;
    point1.x = 10;
    point1.y = 55.5;
    print_point(point1);

    point1.x = 20;
    point1.y = 2.7;
    print_point(point1);
    return 0;
}
```
```text
Point [ x : 10, y : 55.5 ]
Point [ x : 20, y : 2.7 ]
```
> ⚠️ Onduidelijk in opname: de nieuwe waarde voor `x` is niet verstaanbaar; hier is 20 gekozen.

#### Grootte van objecten [▶ 22:45:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81948s)
> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.
```cpp
// nocheck-output
#include <iostream>
#include <string>
#include <cstddef>

class Dog {
public:
    Dog() = default;
    void print_info() {}          // functies tellen NIET mee in sizeof
    void do_something() {}

private:
    size_t leg_count;
    size_t arm_count;
    int* p_age;                   // telt als 8 bytes (grootte van de pointer), niet wat erachter zit
};

int main() {
    Dog dog1;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
    std::cout << "sizeof(Dog) : " << sizeof(Dog) << std::endl;
    std::cout << "sizeof(dog1) : " << sizeof(dog1) << std::endl;   // type of object: zelfde

    std::string name{"Hello World"};
    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;
    name = "I am the king of the universe";
    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;   // onveranderd!
    return 0;
}
```
Voorbeeldoutput (64-bit GCC, zoals bij de docent):
```text
sizeof(size_t) : 8
sizeof(int*) : 8
sizeof(Dog) : 24
sizeof(dog1) : 24
sizeof(name) : 32
sizeof(name) : 32
```

#### Boundary alignment (aanvulling) [▶ 22:44:14](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=81854s)
> 💡 Aanvulling: de docent legt boundary alignment alleen in de slides uit. Dit voorbeeld laat het effect zien: dezelfde members in een andere volgorde geven een andere `sizeof`.
```cpp
// nocheck-output
#include <iostream>

struct Padded {
    char a;    // 1 byte + 3 bytes padding (int moet op een veelvoud van 4 staan)
    int  b;    // 4 bytes
    char c;    // 1 byte + 3 bytes padding (totale grootte veelvoud van 4)
};

struct Compact {
    int  b;    // 4 bytes
    char a;    // 1 byte
    char c;    // 1 byte + 2 bytes padding
};

int main() {
    std::cout << "som van de members : " << sizeof(char) + sizeof(int) + sizeof(char) << std::endl;
    std::cout << "sizeof(Padded) : " << sizeof(Padded) << std::endl;
    std::cout << "sizeof(Compact) : " << sizeof(Compact) << std::endl;
    return 0;
}
```
Voorbeeldoutput (typisch op x86-64):
```text
som van de members : 6
sizeof(Padded) : 12
sizeof(Compact) : 8
```

### Valkuilen & veelgemaakte fouten

#### Puntkomma na de class vergeten
`class Cylinder { ... }` zonder `;` geeft verwarrende foutmeldingen, vaak pas op de regel ná de class. Altijd `};`.

#### Members zijn standaard private
Zonder `public:` is alles in een `class` private, inclusief methods en constructors. Foutmelding: *"... is private within this context"*. Bij `struct` is het andersom.

#### Constructor (of setters) per ongeluk private
Een constructor in de `private`-sectie maakt het onmogelijk om objecten van buitenaf te bouwen. Hetzelfde geldt voor getters/setters die je van buitenaf wilt gebruiken.

#### Eigen constructor schrijven en de default constructor kwijtraken
Zodra je één constructor schrijft, genereert de compiler geen default constructor meer. `Cylinder c;` faalt dan met *no matching function for call to 'Cylinder::Cylinder()'*. Oplossing: `Cylinder() = default;`.

#### Haakjes vergeten bij een getter
`p_cylinder2->get_base_radius` zonder `()` is geen functieaanroep en geeft een compilerfout.

#### Dot-notatie op een pointer
`p_cylinder1.volume()` werkt niet. Gebruik `p_cylinder1->volume()` of `(*p_cylinder1).volume()`. Let op: `*p_cylinder1.volume()` zonder haakjes is ook fout, omdat `.` sterker bindt dan `*`.

#### Header zonder include guard
Een header die via meerdere wegen in hetzelfde `.cpp`-bestand terechtkomt, geeft *redefinition*-fouten. Geef elke header een include guard met een **eigen** naam; kopieer niet gedachteloos `CYLINDER_H` naar `constants.h`.

#### Definitie zowel in header als in `.cpp`
Na het verplaatsen van een body naar `cylinder.cpp` moet de body uit de header weg, anders heb je twee definities (*redefinition* / *multiple definition*).

#### `new` zonder `delete`
Een object dat je met `new` maakt, wordt nooit automatisch opgeruimd: geen destructor-aanroep, geheugenlek. Ook geheugen dat de constructor aanvraagt, moet de destructor vrijgeven.

#### Object met raw pointer-member by value doorgeven
De standaardkopie kopieert alleen het adres. Twee objecten delen dan hetzelfde heap-geheugen, en beide destructors doen `delete` → dubbel `delete`, undefined behavior, mogelijk crash. Geef zulke objecten by reference door (of schrijf een copy constructor, komt later in de cursus).

#### Parameter met dezelfde naam als een member
`name = name;` compileert, maar wijst de parameter aan zichzelf toe en verandert de member niet. Gebruik `this->name = name;` (of andere parameternamen zoals `name_param`).

#### `return this` bij een reference-return type
Als de setter `Dog&` teruggeeft, moet je `return *this;` schrijven. `return this;` geeft een `Dog*` en levert een compilerfout op.

#### `sizeof` verkeerd interpreteren
`sizeof` telt geen functies en niet de data waarnaar een pointer wijst. `sizeof(std::string)` zegt dus niets over de lengte van de tekst (gebruik daarvoor `.size()`). Door padding kan `sizeof` groter zijn dan de som van de members.

### Best practices
- Maak member variables **`private`** en geef gecontroleerde toegang via public getters en setters (of andere methods); maak alleen iets public als daar een goede reden voor is.
- Geef member variables een beginwaarde met brace initialization (`double height{1};`, `int* p_age{nullptr};`).
- Zet `public`/`private` netjes uitgelijnd en groepeer members (constructors, functions, getters, setters, member variables) met korte commentaarkopjes, zoals de docent doet.
- Gebruik `= default` als je naast eigen constructors een lege default constructor wilt.
- Verdeel classes over een header (declaratie) en een `.cpp` (implementatie); houd `main.cpp` hoog-niveau.
- Gebruik altijd include guards met een unieke naam per header (bijv. `CYLINDER_H`).
- Schrijf `delete` direct nadat je `new` hebt geschreven, zodat je het niet vergeet; geef in de destructor alles vrij wat de constructor heeft aangevraagd.
- Gebruik `->` in plaats van `(*p).` bij pointers naar objecten.
- Gebruik `std::string_view`-parameters in constructors/setters om onnodige string-kopieën te vermijden, en `const T&` om objecten zonder kopie door te geven.
- Gebruik `this->` bij naamconflicten tussen parameters en members, of kies verschillende namen (`m_name` / `name_param`).
- Bied chained setters aan (return `*this` als reference of `this` als pointer) als dat de class prettiger in gebruik maakt.
- Gebruik `struct` voor eenvoudige types met alleen publieke data (zoals `Point`), `class` voor types met verborgen toestand en gedrag.

> 💡 Aanvulling: in modern C++ vermijd je raw `new`/`delete` in classes waar mogelijk (bijv. met `std::unique_ptr` of door de waarde direct als member op te slaan, zoals `int age;`). Dan heb je vaak geen eigen destructor nodig en ontstaat het dubbel-`delete`-probleem niet. Ook initialiseer je members bij voorkeur in de *member initializer list* van de constructor (`Cylinder(double r, double h) : base_radius{r}, height{h} {}`).

### Samenvatting
- Een **class** is een blueprint voor een eigen type; **objecten** zijn instances met eigen runtime-data. Een class bevat member variables (eigenschappen) en member functions/methods (gedrag) en eindigt met `};`.
- Members van een `class` zijn standaard **private**; met `public:`/`private:` bepaal je de toegang. Methods hebben altijd toegang tot alle members. Bij `struct` zijn members standaard **public**; dat is het enige verschil.
- **Constructors** hebben geen return type, dezelfde naam als de class en moeten public zijn. De compiler kiest de best passende constructor. Zonder eigen constructor genereert de compiler een lege default constructor; met een eigen constructor niet meer, tenzij je `ClassName() = default;` schrijft.
- **Getters** en **setters** geven gecontroleerde toegang tot private member variables; getters by value geven een kopie terug.
- Een class over bestanden verdelen: declaratie in `.h` (met **include guard**), implementatie in `.cpp` met de **scope resolution operator** `ClassName::`. Voorkom dubbele definities.
- Via een pointer benader je members met **`->`** (gelijk aan `(*p).member`). Heap-objecten (`new`) moet je zelf met `delete` vrijgeven.
- Een **destructor** (`~ClassName()`, geen parameters) wordt aangeroepen als een object sterft: out of scope, `delete`, kopie van een by-value parameter (en soms bij return by value). Ruim daar resources op.
- Constructors lopen in volgorde van creatie, **destructors in omgekeerde volgorde**.
- **`this`** wijst naar het huidige object: voor het adres, voor `this->member = param` bij naamconflicten, en voor **chained calls** (`return this;` met `Dog*` of `return *this;` met `Dog&`).
- **`sizeof`** van een object is (ongeveer) de som van de member variables; functies tellen niet mee, pointers tellen alleen zelf mee (vandaar dat `sizeof(std::string)` constant is), en **boundary alignment** kan padding toevoegen.

### Oefeningen
1. **Rectangle.** Schrijf een `class Rectangle` met private members `width` en `height` (`double`, beginwaarde 1), een default constructor via `= default`, een constructor met twee parameters, getters, setters en een method `area()`. Maak in `main` een rectangle met de default constructor en een met `(3, 4)`, print beide oppervlaktes, verander de breedte van de tweede naar 10 en print opnieuw.
2. **Point en afstand.** Maak een `struct Point` met `double x` en `double y` en een functie `double distance(const Point& a, const Point& b)` die de afstand tussen twee punten berekent (`std::sqrt` uit `<cmath>`). Test met (0, 0) en (3, 4).
3. **Levensduur volgen.** Schrijf een `class Tracker` met een `std::string`-member, een constructor die `"Created <naam>"` print en een destructor die `"Destroyed <naam>"` print. Maak in `main` eerst `a` en `b` op de stack, roep daarna een functie aan die een lokale `Tracker` `"local"` maakt, maak dan een `Tracker` `"heap"` met `new` en geef die vrij met `delete`, en print als laatste `"End of main"`. Voorspel eerst de volledige output.
4. **Chained setters.** Schrijf een `class Account` met private members `owner` (`std::string`) en `balance` (`double`). Geef setters `set_owner` en `deposit` die een `Account&` teruggeven (gebruik `this->` en `return *this;`; laat de parameter van `set_owner` ook `owner` heten), plus een method `print()`. Stel in één statement de eigenaar in op `"Ann"` en stort 100 en 50.

<details><summary>Uitwerking</summary>

```cpp
// Oefening 1
#include <iostream>

class Rectangle {
public:
    Rectangle() = default;
    Rectangle(double width_param, double height_param) {
        width = width_param;
        height = height_param;
    }

    double area() { return width * height; }

    double get_width() { return width; }
    double get_height() { return height; }
    void set_width(double width_param) { width = width_param; }
    void set_height(double height_param) { height = height_param; }

private:
    double width{1};
    double height{1};
};

int main() {
    Rectangle r1;
    Rectangle r2(3, 4);
    std::cout << "r1 area : " << r1.area() << std::endl;
    std::cout << "r2 area : " << r2.area() << std::endl;

    r2.set_width(10);
    std::cout << "r2 width : " << r2.get_width() << ", area : " << r2.area() << std::endl;
    return 0;
}
```
```text
r1 area : 1
r2 area : 12
r2 width : 10, area : 40
```

```cpp
// Oefening 2
#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double distance(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1{0, 0};
    Point p2{3, 4};
    std::cout << "distance : " << distance(p1, p2) << std::endl;
    return 0;
}
```
```text
distance : 5
```

```cpp
// Oefening 3
#include <iostream>
#include <string>
#include <string_view>

class Tracker {
public:
    Tracker(std::string_view name_param) {
        name = name_param;
        std::cout << "Created " << name << std::endl;
    }
    ~Tracker() {
        std::cout << "Destroyed " << name << std::endl;
    }

private:
    std::string name;
};

void make_local() {
    Tracker local("local");
}   // local wordt hier vernietigd

int main() {
    Tracker a("a");
    Tracker b("b");
    make_local();

    Tracker* p_heap = new Tracker("heap");
    delete p_heap;              // destructor direct

    std::cout << "End of main" << std::endl;
    return 0;
}   // b en a in omgekeerde volgorde
```
```text
Created a
Created b
Created local
Destroyed local
Created heap
Destroyed heap
End of main
Destroyed b
Destroyed a
```

```cpp
// Oefening 4
#include <iostream>
#include <string>
#include <string_view>

class Account {
public:
    Account& set_owner(std::string_view owner) {
        this->owner = owner;     // this-> nodig: parameter heet hetzelfde als de member
        return *this;
    }
    Account& deposit(double amount) {
        this->balance += amount;
        return *this;
    }
    void print() {
        std::cout << "Account [ owner : " << owner << ", balance : " << balance << " ]" << std::endl;
    }

private:
    std::string owner;
    double balance{0};
};

int main() {
    Account acc;
    acc.set_owner("Ann").deposit(100).deposit(50);
    acc.print();
    return 0;
}
```
```text
Account [ owner : Ann, balance : 150 ]
```
</details>

---

<a id="h18"></a>

## Hoofdstuk 18 – Inheritance (22:52:43 – 26:21:03) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=82363s)

### Leerdoelen

- Begrijpen wat inheritance (overerving) is, welk probleem het oplost (hergebruik van code, "is-een"-relaties) en hoe een inheritance-hiërarchie eruitziet.
- Een afgeleide klasse (derived class) maken met de syntax `class Player : public Person`.
- Weten dat elk object van een afgeleide klasse een volledig basisdeel (base part) in zich draagt, en dat aantonen met de debugger.
- Het verschil kennen tussen de member access specifiers `public`, `protected` en `private` in een basisklasse.
- De drie base class access specifiers (`public`, `protected`, `private` inheritance) en hun effect op de toegankelijkheid van geërfde members kunnen uitleggen en voorspellen.
- Begrijpen waarom private inheritance "egoïstisch" is en wat dat betekent voor klassen verderop in de hiërarchie.
- Members met `using Base::naam;` weer toegankelijk maken ("resurrecting") en de grenzen daarvan kennen.
- De volgorde van constructor- en destructoraanroepen in een hiërarchie kennen.
- Custom constructors en copy constructors correct naar de basisklasse laten doorgeven via de initializer list.
- Base constructors erven met `using Person::Person;` en de beperkingen daarvan kennen.
- Begrijpen wat er gebeurt als een afgeleide klasse dezelfde namen gebruikt als de basisklasse (name hiding) en hoe je met `Base::` toch de basisversie bereikt.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 17 (Classes)** is de directe basis: constructors, default constructors, initializer lists, getters/setters, klassen over meerdere bestanden (`.h` + `.cpp`), destructors, de volgorde van constructie/destructie, copy constructors (met de waarschuwing over shallow vs. deep copy bij dynamisch geheugen) en friend-functies zoals de stream output operator `operator<<`. Al deze ideeën worden hier uitgebreid naar meerdere lagen.
- **Hoofdstuk 9 (References)** en **hoofdstuk 11 (pass by reference)**: parameters worden waar mogelijk als `const` reference of als `std::string_view` doorgegeven om kopieën te vermijden; bij copy constructors is pass by reference verplicht.
- **Hoofdstuk 10 (strings)**: `std::string` en `std::string_view` worden overal als type voor namen en adressen gebruikt.
- **Hoofdstuk 13 (Function overloading)**: bij het "resurrecten" van members met `using` komen alle overloads van een naam tegelijk mee.
- **Hoofdstuk 8 (Pointers, dynamisch geheugen)**: de docent noemt dynamische geheugenallocatie als reden om zelf copy constructors te schrijven.
- **Vooruitblik hoofdstuk 19 (Polymorphism)**: daar gebruik je een base pointer om afgeleide objecten te beheren; dit hoofdstuk legt daarvoor het fundament.

### Uitleg

#### Wat is inheritance en waarom bestaat het?

Inheritance is een mechanisme om nieuwe klassen te bouwen **in termen van bestaande klassen**. De nieuwe klasse "steelt" als het ware de eigenschappen van de bestaande klasse en voegt er eigen dingen aan toe. Het klassieke voorbeeld: een `Person`-type met de basisgegevens van een persoon. Een ingenieur, een dokter en een speler zijn allemaal ook personen. In plaats van voor elk van die types opnieuw naam, leeftijd, enzovoort te programmeren, laat je ze afleiden van `Person`. Op die laag bouw je dan weer verder: een civiel ingenieur of een elektrotechnisch ingenieur is een ingenieur.

Zo ontstaat een **inheritance-hiërarchie** (inheritance tree): bovenaan de meest fundamentele klasse (de basisklasse), naar onderen steeds gespecialiseerdere afgeleide klassen. Een ander voorbeeld van de docent: `Vehicle` bovenaan, met daaronder auto, minivan, truck, pick-up, ...

```text
            Person
           /      \
     Engineer    Doctor
        |
  CivilEngineer
```

Het grote voordeel is **hergebruik van code**: de basislaag hoeft maar één keer gebouwd te worden. De docent benadrukt dat inheritance een van de bepalende eigenschappen van objectgeoriënteerd programmeren is: klassen definiëren dingen (een auto, een huis, een ruimteschip), inheritance laat klassen op elkaar voortbouwen zodat je ontwerp overzichtelijker wordt.

[▶ 22:52:43](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=82363s)

#### Eerste kennismaking: `class Player : public Person`

Het eerste voorbeeld: een basisklasse `Person` met twee private member variables `first_name` en `last_name` (type `std::string`, standaard `"Mysterious"` en `"Person"`), een default constructor, een constructor met twee parameters, getters en een stream output operator. Daarvan wordt `Player` afgeleid, die er één eigen member bij krijgt: `m_game`, het spel dat de speler speelt.

De syntax om af te leiden:

```c++
class Player : public Person {
    // ...
};
```

Na de klassenaam schrijf je een dubbele punt, dan de **base class access specifier** (hier `public`) en dan de klasse waarvan je erft. Vanaf dat moment heeft elk `Player`-object een `Person`-deel ingebakken. In `Player` zelf staan dus géén members voor voor- en achternaam; die komen uit het basisdeel.

Wat de docent onderweg laat zien:

- De constructorparameter van `Player` nam eerst een `std::string&`; dan kun je geen letterlijke tekst als `"Basketball"` meegeven (een tijdelijk object bindt niet aan een non-const reference). Hij lost het op met `std::string_view` by value.
- Een gedeclareerde maar niet gedefinieerde destructor geeft een linkerfout (`undefined reference to Player::~Player()`). Omdat er geen dynamisch geheugen is, haalt hij de destructor gewoon weg en laat hij de compiler er een genereren.
- Omdat `Player` geen data voor de namen meekreeg, print het programma de default-waarden van het `Person`-deel: "Mysterious Person".

**Onder de motorkap**: met een breakpoint in de debugger van VS Code toont de docent dat het object `p1` onder "Locals" een deel heeft dat als base class `Person` gemarkeerd is, met daarin `first_name` en `last_name`, en daarnaast het eigen member `m_game`. Elk object van een afgeleide klasse bevat dus fysiek een compleet basisobject als fundament.

[▶ 22:55:27](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=82527s) · [▶ debugger 23:11:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=83496s)

#### Public inheritance en private members van de basisklasse

Bij public inheritance geldt:

- De afgeleide klasse kan de **public** members van de basisklasse gebruiken. Ze worden als public geërfd, dus ook code buiten de klasse (bv. `main`) kan ze op een `Player`-object aanroepen.
- De afgeleide klasse kan **niet rechtstreeks** aan de **private** members van de basisklasse. Ze zitten wél in het object, maar de toegang is verboden.
- Hetzelfde geldt voor **friends van de afgeleide klasse**: die hebben toegang tot de private members van de afgeleide klasse, maar niet tot de private members van de basisklasse.

De docent probeert in `operator<<` en daarna in de constructor van `Player` rechtstreeks `first_name = "John"` te schrijven. GCC geeft dan `'std::string Person::first_name' is private within this context`. De oplossing in dit stadium: via **public** member functions van de basisklasse werken, zoals getters, en setters `set_first_name(std::string_view)` en `set_last_name(std::string_view)` toevoegen (niet `const`, want ze wijzigen het object). Die setters worden vervolgens vanuit `main` op het `Player`-object aangeroepen. Dat bewijst dat public members van de basis bruikbaar zijn op een afgeleid object.

[▶ 23:14:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=83642s) · [▶ setters 23:17:11](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=83831s)

#### Protected members

Soms wil je dat members van de basisklasse **wel** bruikbaar zijn in afgeleide klassen, maar **niet** van buitenaf. Daarvoor bestaat de access specifier `protected`. Zet je `first_name` en `last_name` in een `protected`-sectie, dan:

- kunnen member functions van afgeleide klassen (die public erven) ze lezen en schrijven, bijvoorbeeld in de constructor van `Player`;
- gedragen ze zich voor de buitenwereld (bijvoorbeeld `main`) nog steeds alsof ze private zijn.

De docent breidt de constructor van `Player` uit naar `Player(std::string_view game, std::string_view first_name_param, std::string_view last_name_param)` en kent de namen toe **in de body** van de constructor (een initializer list kan hier niet, omdat die members niet van `Player` zijn; zie verder). Daarna `p1.first_name = "Daniel";` in `main` proberen geeft een compilerfout: protected members zijn alleen bereikbaar vanuit de (member functions van de) afgeleide klasse.

> 💡 Aanvulling: verderop in het hoofdstuk leer je dat het netter is om basisdata via een constructor van de basisklasse in de initializer list te laten initialiseren, in plaats van protected data in de body te overschrijven.

[▶ 23:21:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=84070s) · [▶ uitbreiding constructor 23:27:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=84451s)

#### Base class access specifiers: public, protected en private inheritance

Het woord `public` in `class Player : public Person` heet de **base class access specifier**. Die bepaalt hoe toegankelijk de geërfde members in de afgeleide klasse worden. Je kunt er toegang alleen mee **beperken**, nooit ruimer maken. Neem een basisklasse met `m1` public, `m2` protected en `m3` private:

| Inheritance | `m1` (public in base) | `m2` (protected in base) | `m3` (private in base) |
|---|---|---|---|
| `public` | public | protected | blijft private **aan de basis**, niet bereikbaar |
| `protected` | protected | protected | blijft private aan de basis |
| `private` | private | private | blijft private aan de basis |

Je kunt het zo onthouden: de specifier is het **hoogste** toegangsniveau dat geërfde members in de afgeleide klasse nog kunnen hebben. Bij public inheritance blijft alles zoals het was. Bij protected inheritance wordt protected het plafond. Bij private inheritance wordt alles private.

Belangrijk punt dat de docent meerdere keren herhaalt: wat **private in de basisklasse** is, is **nooit** rechtstreeks bereikbaar vanuit een afgeleide klasse, welke inheritance je ook gebruikt. "Blijft private" betekent dus: private aan de basisklasse, niet private aan de afgeleide klasse. Wil je er toch bij, dan moet je via public (of protected) members van de basis gaan, zoals getters.

[▶ 23:31:32](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=84692s)

#### Demo: Player (public), Nurse (protected) en Engineer (private)

In de demo krijgt `Person` drie members met elk een ander toegangsniveau: `m_full_name` (public), `m_age` (protected) en `m_address` (private), plus getters, een default constructor en een constructor `Person(std::string_view fullname, int age, std::string_view address)`. Daarvan worden drie klassen afgeleid:

- **`Player : public Person`**: in een member function van `Player` kun je `m_full_name` en `m_age` gebruiken, `m_address` niet. Van buitenaf (`main`) kan `player.m_full_name = "Samwell Jackson";`, maar `player.m_age` niet (protected) en `player.m_address` al helemaal niet (private aan `Person`).
- **`Nurse : protected Person`**: binnen `Nurse` zijn `m_full_name` en `m_age` bruikbaar (beide nu protected), `m_address` niet. Van buitenaf is **niets** meer bereikbaar, ook `m_full_name` niet, dat in `Person` nog public was. GCC: `'std::string Person::m_full_name' is inaccessible within this context`.
- **`Engineer : private Person`**: binnen `Engineer` zijn `m_full_name` en `m_age` bruikbaar (nu private aan `Engineer`), `m_address` niet. Van buitenaf niets.

Een vraag die de docent zelf opwerpt: in de `operator<<` van `Nurse` roep je `nurse.get_full_name()` aan met de puntoperator op een object. Is dat niet "van buitenaf"? Nee: `operator<<` is een **friend** van `Nurse` en heeft daarom toegang tot alles wat private of protected is in `Nurse`, dus ook tot de getters die door protected inheritance protected geworden zijn. Hetzelfde geldt voor de friend `operator<<` van `Engineer`.

[▶ 23:36:26](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=84986s) · [▶ Nurse 23:51:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=85905s) · [▶ Engineer 23:58:08](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=86288s)

#### Private inheritance onder de loep: de "egoïstische" klasse

Private inheritance maakt alles wat de klasse van boven erft private **aan zichzelf**. De docent noemt zo'n klasse egoïstisch: "ik neem alles wat ik kan krijgen van mijn ouder, maar niemand mag het van mij overnemen". Het probleem merk je pas als iemand van die klasse erft:

```text
Person          (m_full_name public, m_age protected, m_address private)
  ^ private
Engineer        (m_full_name, m_age en alle getters nu private aan Engineer)
  ^ public
CivilEngineer   (kan aan NIETS van Person meer)
```

Ook al erft `CivilEngineer` public van `Engineer`, de members uit `Person` zijn private aan `Engineer` en dus onbereikbaar. Zelfs de friend `operator<<` van `CivilEngineer` kan `get_full_name()` niet aanroepen. GCC meldt dat de functie `inaccessible within this context` is. Dat lijkt vreemd, want een friend heeft toegang tot alles van `CivilEngineer`, maar `get_full_name` is van `Engineer` en daar private.

Met de debugger toont de docent dat een `CivilEngineer`-object nog steeds een `Engineer`-deel heeft, dat zelf weer een `Person`-deel heeft. De data is er dus wel, je hebt er alleen geen toegang meer toe door ontwerpkeuzes hogerop.

Je kunt het oplossen door in `Engineer` public getters te zetten die de data doorgeven, maar de docent vindt dat een teken van slecht ontwerp: wil je dat de members naar beneden doorgegeven worden, gebruik dan gewoon protected of public inheritance. Gebruik private inheritance alleen als je echt dit gedrag wilt.

[▶ 24:07:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=86820s) · [▶ CivilEngineer 24:16:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=87400s)

#### Members terughalen met `using` ("resurrecting")

De docent merkt op dat C++ je soms hard tegenhoudt en je daarna toch een achterdeur geeft. Ook al erft `Engineer` private, je kunt individuele members weer op een ruimer toegangsniveau zetten met een **using-declaratie**:

```c++
class Engineer : private Person {
protected:
    using Person::get_full_name;   // nu protected in Engineer
    using Person::get_age;
    using Person::get_address;
public:
    using Person::add;             // alle overloads van add, nu public
    // ...
};
```

Regels:

- Het teruggehaalde member krijgt het toegangsniveau van de **sectie waarin de using-declaratie staat** (public of protected).
- Je haalt terug **op naam**. Heeft `Person` meerdere overloads van `add` (twee en drie parameters), dan brengt `using Person::add;` ze allemaal mee.
- Je kunt ook member variables terughalen, maar **niet** iets wat al private is in de klasse waar het vandaan komt. `using Person::m_address;` in `Engineer` geeft `'std::string Person::m_address' is private within this context`.
- Evenmin kan `CivilEngineer` een member terughalen dat door de private inheritance van `Engineer` al private aan `Engineer` geworden is, zoals `using Engineer::do_something;`.

De docent raadt dit zelf af: wie private inheritance ziet, verwacht dat alles private is. Als je toch zaken naar beneden wilt doorgeven, kies dan meteen voor protected of public inheritance. Dat is directer en makkelijker te lezen.

Terzijde: de docent definieerde `do_something()` eerst inline in de header met `std::cout` zonder `<iostream>` te includen, wat een fout gaf. Hij verplaatst de definitie naar `person.cpp`, waar `<iostream>` wél geïncludeerd is.

[▶ 24:26:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=87979s) · [▶ using 24:34:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=88463s) · [▶ overloads 24:36:03](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=88563s) · [▶ grenzen 24:40:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=88854s)

#### Default constructors en de bouwvolgorde

Vanaf hier gebruikt de hiërarchie weer public inheritance: `Person` ← `Engineer` ← `CivilEngineer`. Als je een `CivilEngineer` maakt, bouwt C++ het object **in lagen**: eerst het meest basale deel (`Person`), dan de `Engineer`-laag erop en tot slot de `CivilEngineer`-laag. Elke laag wordt opgebouwd door een constructor. Geef je niet aan welke basisconstructor gebruikt moet worden, dan roept de compiler de **default constructor** van de basis aan.

Output van zo'n programma:

```text
Default constructor for Person called
Default constructor for Engineer called
Default constructor for CivilEngineer called
```

Conclusie van de docent: **zorg altijd voor een default constructor** in je klassen. De compiler kan die op onverwachte plaatsen aanroepen, zeker als een klasse deel uitmaakt van een hiërarchie. Ontbreekt hij in `Person`, dan geeft het bouwen van een `CivilEngineer` een compilerfout. Met de debugger laat hij opnieuw zien dat het `CivilEngineer`-object een `Engineer`-deel bevat, dat zelf een `Person`-deel bevat.

[▶ 24:46:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=89190s)

#### Custom constructors: data doorgeven aan de basisklasse

Je wilt natuurlijk niet altijd default-data. Het doel is:

```c++
Person person1("Daniel Gray", 27, "Blue Sky St. 233 #56");
Engineer engineer1("Daniel Gray", 41, "Green Bronx St. 87 #44", 12);
CivilEngineer civil_engineer1("John Travolta", 51, "Tiny Dog 42 Str. #89", 31, "Road Strength");
```

De data moet naar de laag waar het hoort: naam, leeftijd en adres naar het `Person`-deel, `contract_count` naar het `Engineer`-deel, `speciality` naar het `CivilEngineer`-deel. De docent laat eerst twee **foute** aanpakken zien:

1. **Toewijzen in de body** (`m_full_name = fullname; m_age = age; m_address = address;`): `m_full_name` en `m_age` zijn bereikbaar, maar `m_address` is private aan `Person`, dus compilerfout. Laat je die regel weg, dan blijft het adres op de default-waarde staan en gaat je data verloren.
2. **Basis-members in de initializer list** (`: m_full_name{fullname}, m_age{age}, m_address{address}`): een initializer list mag alleen members initialiseren die **van de klasse zelf** zijn. GCC: `class 'CivilEngineer' does not have any field named 'm_full_name'`. Het is niet de taak van `Engineer` of `CivilEngineer` om de members van `Person` op te zetten.

De **juiste** aanpak: roep in de initializer list de **constructor van de directe basisklasse** aan en initialiseer daarna je eigen members:

```c++
Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
    : Person(fullname, age, address), m_contract_count(contract_count_param) {}

CivilEngineer::CivilEngineer(std::string_view fullname, int age, std::string_view address,
                             int contract_count, std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality) {}
```

`CivilEngineer` geeft de eerste vier gegevens door aan `Engineer`, die op zijn beurt de eerste drie doorgeeft aan `Person`. De aanroepvolgorde blijft van basis naar meest gespecialiseerd: "Custom constructor for Person called", dan Engineer, dan CivilEngineer. De docent geeft de parameter de naam `contract_count_param` om verwarring met het member te vermijden, en zet de derde parameter van de `Person`-constructor om van `const std::string&` naar `std::string_view`.

[▶ 24:56:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=89818s) · [▶ foute aanpakken 25:00:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=90054s) · [▶ basisconstructor aanroepen 25:02:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=90150s) · [▶ in code 25:17:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=91068s)

#### Copy constructors met inheritance

`Engineer engineer2{engineer1};` werkt ook zonder eigen copy constructor: de compiler genereert er een die **memberwise** kopieert (inclusief het basisdeel), en zolang er geen dynamisch geheugen in het spel is, gaat dat goed. Bij pointer-members (zie de discussie over shallow/deep copy in hoofdstuk 17) moet je hem zelf schrijven.

Voor `Person` is dat bekend terrein:

```c++
Person::Person(const Person& source)
    : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address) {}
```

De parameter **moet** een reference zijn, anders zou het doorgeven by value zelf weer de copy constructor aanroepen, eindeloos.

Voor `Engineer` toont de docent weer twee foute versies en één goede:

1. **Alleen het eigen member kopiëren**: `Engineer(const Engineer& source) : m_contract_count(source.m_contract_count) {}`. Het `Person`-deel wordt dan met de **default constructor** opgebouwd: de kopie krijgt "None", 0, "None" in plaats van de echte gegevens.
2. **De andere basisconstructor aanroepen**: `: Person(source.m_full_name, source.m_age, source.m_address)`. Dat geeft een compilerfout omdat `m_address` private is aan `Person`. Met `source.get_address()` compileert het wel, maar het blijft slecht ontwerp: je hergebruikt de copy constructor van `Person` niet (codeduplicatie), je bent misschien gedwongen een getter te maken die alleen hier gebruikt wordt, en volgens de docent ontstaat er een tijdelijke kopie.
3. **Goed**: geef het bronobject rechtstreeks door aan de copy constructor van de basis:

```c++
Engineer::Engineer(const Engineer& source)
    : Person(source), m_contract_count(source.m_contract_count) {}
```

**Onder de motorkap**: je geeft een `Engineer` door waar een `const Person&` verwacht wordt. Een `Engineer` is een `Person`, dus de reference bindt aan het `Person`-deel ervan. De docent beschrijft het als twee lagen: de compiler "slicet" de buitenste `Engineer`-laag eraf en gebruikt alleen het binnenste `Person`-deel om het `Person`-deel van het nieuwe object te kopiëren. Er is geen tijdelijk object nodig en de copy constructor van `Person` wordt hergebruikt. `CivilEngineer` doet hetzelfde met `: Engineer(source), m_speciality(source.m_speciality)`. Bij het kopiëren van een `CivilEngineer` zie je dan de custom copy constructors van Person, Engineer en CivilEngineer in die volgorde.

[▶ 25:26:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=91595s) · [▶ slicing-uitleg 25:31:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=91888s) · [▶ fout: default aangeroepen 25:40:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=92418s) · [▶ goede versie 25:45:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=92709s)

#### Base constructors erven met `using Person::Person;`

Standaard worden constructors **niet** geërfd. Je kunt de compiler wel opdragen om dat te doen:

```c++
class Engineer : public Person {
public:
    using Person::Person;   // erf de constructors van Person
    // ...
};
```

De compiler genereert dan voor `Engineer` constructors met dezelfde parameters als die van `Person`, die al het werk doorschuiven naar `Person`. In feite iets als `Engineer(std::string_view fullname, int age, std::string_view address) : Person(fullname, age, address) {}`. Het zijn "base-achtige" constructors: ze initialiseren **alleen het basisdeel**. Members van `Engineer` zelf krijgen hun default-waarde.

Aandachtspunten:

- **Copy constructors worden niet geërfd.** Dat merk je meestal niet, omdat de compiler er toch een genereert, maar bij dynamisch geheugen leidt dat tot gekopieerde pointers.
- De geërfde constructor behoudt het **toegangsniveau dat hij in de basisklasse had** (public blijft public; protected kan niet van buitenaf; private is zelfs voor de afgeleide klasse onbruikbaar). Waar de using-declaratie staat, maakt niet uit.
- Een enkele `using Person::Person;` brengt **alle** constructors mee (behalve de copy constructors).
- Je kunt er **eigen constructors** naast zetten. Een aanroep met vier argumenten (`Engineer e("Daniel Gray", 23, "...", 45)`) faalt eerst met `no matching function for call to 'Engineer::Engineer(...)'`. Als de docent zijn eigen vierparameter-constructor weer activeert, werkt zowel de drieparameter-versie (geërfd) als de vierparameter-versie (eigen).

De docent raadt het gebruik ervan sterk af: mensen zien een `Engineer`-constructor en denken dat die ook de `Engineer`-members initialiseert, wat niet zo is. Dat geeft verwarring en mogelijk ernstige bugs. Je moet het wel herkennen als je het in andermans code tegenkomt.

[▶ 25:51:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93095s) · [▶ syntax 25:52:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93142s) · [▶ eigen constructor erbij 26:03:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93821s)

#### Destructors en inheritance

Constructors worden aangeroepen van de basis naar de meest gespecialiseerde klasse: Person, Engineer, CivilEngineer. **Destructors** worden in **omgekeerde volgorde** aangeroepen: eerst die van `CivilEngineer`, dan die van `Engineer` en als laatste die van `Person`. Het object wordt laag voor laag afgebroken, van buiten naar binnen. De docent benadrukt dat je dit moet begrijpen, omdat je code soms van die volgorde afhangt.

[▶ 26:05:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93919s) · [▶ omgekeerde volgorde 26:06:57](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94017s)

#### Hergebruikte namen in een hiërarchie (name hiding)

Een afgeleide klasse mag members hebben met **exact dezelfde naam** als in de basisklasse: zowel member variables (bv. `int m_member_var`) als member functions met dezelfde signatuur (bv. `print_var()`). C++ staat dat toe. Wat gebeurt er dan?

- Het member in de afgeleide klasse **verbergt** (hides) dat van de basis. Roep je `child.print_var()` aan, dan krijg je de `Child`-versie. Op een `Parent`-object krijg je de `Parent`-versie.
- Het `Parent`-deel en zijn data bestaan nog steeds. Je kunt de basisversie expliciet bereiken met de scope resolution operator:
  - van buitenaf: `child.Parent::print_var();`
  - binnen de afgeleide klasse: `Parent::m_member_var` (als het member toegankelijk is, daarom is het in het voorbeeld `protected`).

In het voorbeeld heeft `Parent` `m_member_var = 100` en `Child` zijn eigen `m_member_var = 1000`. Met de constructor `Child(int value)` geeft de docent 33 mee. De constructor van `Child` roept geen basisconstructor aan, dus de compiler gebruikt de default constructor van `Parent` en het `Parent`-deel houdt 100. Onderweg weer de bekende fout: een gedeclareerde destructor zonder definitie geeft `undefined reference to Child::~Child()`. De oplossing is `~Child() = default;`.

> 💡 Aanvulling: de docent gebruikt hier het woord "override", maar technisch heet dit *hiding*. Echt overriden (met `virtual`) komt in hoofdstuk 19. Let ook op: een functie met dezelfde naam in de afgeleide klasse verbergt **alle** overloads met die naam in de basis, niet alleen die met dezelfde signatuur.

[▶ 26:11:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94305s) · [▶ Parent:: syntax 26:14:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94450s)

### Codevoorbeelden

> De docent werkt telkens met aparte `.h`- en `.cpp`-bestanden per klasse. Om elk voorbeeld als één compileerbaar programma te tonen, staan de klassen hier samen in één bestand. De werking is identiek.

#### Eerste overerving: Player erft van Person [▶ 22:59:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=82770s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
public:
    Person() = default;
    Person(std::string_view first_name_param, std::string_view last_name_param)
        : first_name(first_name_param), last_name(last_name_param) {}

    // getters (const: wijzigen het object niet)
    std::string get_first_name() const { return first_name; }
    std::string get_last_name() const { return last_name; }

    // setters (niet const: wijzigen het object)
    void set_first_name(std::string_view fn) { first_name = fn; }
    void set_last_name(std::string_view ln) { last_name = ln; }

private:
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << "Person : [" << person.first_name << " " << person.last_name << "]";
    return out;
}

// Player erft PUBLIC van Person: heeft een Person-deel ingebakken
class Player : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player() = default;
    Player(std::string_view game_param) : m_game(game_param) {}  // string_view: ook letterlijke tekst ok
private:
    std::string m_game{"None"};
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
    // private namen van Person: alleen via public getters
    out << "Player : [ game : " << player.m_game
        << ", names : " << player.get_first_name() << " " << player.get_last_name() << "]";
    return out;
}

int main() {
    Player p1("Basketball");
    std::cout << p1 << std::endl;       // default-namen uit het Person-deel

    p1.set_first_name("John");          // public member van de basis, aangeroepen op een Player
    p1.set_last_name("Snow");
    std::cout << p1 << std::endl;
    return 0;
}
```

```text
Player : [ game : Basketball, names : Mysterious Person]
Player : [ game : Basketball, names : John Snow]
```

#### Fout: private members van de basis gebruiken in de afgeleide klasse [▶ 23:14:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=83642s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: first_name en last_name zijn private in Person
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    std::string get_first_name() const { return first_name; }
private:
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};

class Player : public Person {
public:
    Player(std::string_view game_param) : m_game(game_param) {
        first_name = "John";   // error: 'std::string Person::first_name' is private within this context
        last_name = "Snow";    // error: idem
    }
private:
    std::string m_game;
};

int main() {
    Player p1("Basketball");
    return 0;
}
```

#### Protected members: toegankelijk in de afgeleide klasse, niet van buitenaf [▶ 23:25:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=84307s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person() = default;
    std::string get_first_name() const { return first_name; }
    std::string get_last_name() const { return last_name; }
protected:                                // was private, nu protected
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};

class Player : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player(std::string_view game_param, std::string_view first_name_param,
           std::string_view last_name_param) {
        m_game = game_param;
        first_name = first_name_param;    // OK: protected in de basis, public inheritance
        last_name = last_name_param;      // OK
    }
private:
    std::string m_game{"None"};
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player : [ game : " << player.m_game
        << ", names : " << player.get_first_name() << " " << player.get_last_name() << "]";
    return out;
}

int main() {
    Player p1("Basketball", "John", "Snow");
    std::cout << p1 << std::endl;
    // p1.first_name = "Daniel";  // compilerfout: protected, niet bereikbaar van buitenaf
    return 0;
}
```

```text
Player : [ game : Basketball, names : John Snow]
```

#### Demo base class access specifiers: Player, Nurse en Engineer [▶ 23:39:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=85176s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. De regels die volgens de docent compilerfouten geven, staan als commentaar.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
public:
    Person() = default;
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {}

    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }

public:
    std::string m_full_name{"None"};
protected:
    int m_age{0};
private:
    std::string m_address{"None"};
};

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << "Person [Full name : " << person.get_full_name()
        << ", age : " << person.get_age()
        << ", address : " << person.get_address() << "]";
    return out;
}

// ---------- public inheritance ----------
class Player : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player() = default;
    void play() {
        m_full_name = "John Snow";   // OK: public geërfd
        m_age = 55;                  // OK: protected geërfd
        // m_address = "...";        // compilerfout: private aan Person
    }
private:
    int m_best_score{0};
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player [Full name : " << player.get_full_name()
        << ", age : " << player.get_age()
        << ", address : " << player.get_address()
        << ", best score : " << player.m_best_score << "]";
    return out;
}

// ---------- protected inheritance ----------
class Nurse : protected Person {
    friend std::ostream& operator<<(std::ostream& out, const Nurse& nurse);
public:
    Nurse() = default;
    void treat_unwell_person() {
        m_full_name = "John Snow";   // OK: nu protected in Nurse
        m_age = 23;                  // OK: protected
        // m_address = "...";        // compilerfout: private aan Person
    }
private:
    int m_certificate_id{0};
};

// friend van Nurse: mag de (nu protected) getters gebruiken
std::ostream& operator<<(std::ostream& out, const Nurse& nurse) {
    out << "Nurse [Full name : " << nurse.get_full_name()
        << ", age : " << nurse.get_age()
        << ", address : " << nurse.get_address()
        << ", certificate id : " << nurse.m_certificate_id << "]";
    return out;
}

// ---------- private inheritance ----------
class Engineer : private Person {
    friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);
public:
    Engineer() = default;
    void build_something() {
        m_full_name = "John Snow";   // OK: nu private in Engineer
        m_age = 23;                  // OK: nu private in Engineer
        // m_address = "...";        // compilerfout: private aan Person
    }
private:
    int m_contract_count{0};
};

std::ostream& operator<<(std::ostream& out, const Engineer& engineer) {
    out << "Engineer [Full name : " << engineer.get_full_name()
        << ", age : " << engineer.get_age()
        << ", address : " << engineer.get_address()
        << ", contract count : " << engineer.m_contract_count << "]";
    return out;
}

int main() {
    Person person1("Daniel Gray", 27, "Blue Sky St. 233 #56");
    std::cout << person1 << std::endl;
    std::cout << "--------" << std::endl;

    Player player;
    player.m_full_name = "Samwell Jackson";   // OK: public in Player
    // player.m_age = 55;                     // compilerfout: protected
    // player.m_address = "...";              // compilerfout: private aan Person
    std::cout << player << std::endl;
    player.play();
    std::cout << player << std::endl;
    std::cout << "--------" << std::endl;

    Nurse nurse1;
    // nurse1.m_full_name = "Davy Jones";     // compilerfout: nu protected in Nurse
    // nurse1.m_age = 51;                     // compilerfout: protected
    nurse1.treat_unwell_person();
    std::cout << nurse1 << std::endl;
    std::cout << "--------" << std::endl;

    Engineer engineer1;
    // engineer1.m_full_name = "Olivier Godson"; // compilerfout: private in Engineer
    // engineer1.m_age = 33;                     // compilerfout: private in Engineer
    engineer1.build_something();
    std::cout << engineer1 << std::endl;
    return 0;
}
```

```text
Person [Full name : Daniel Gray, age : 27, address : Blue Sky St. 233 #56]
--------
Player [Full name : Samwell Jackson, age : 0, address : None, best score : 0]
Player [Full name : John Snow, age : 55, address : None, best score : 0]
--------
Nurse [Full name : John Snow, age : 23, address : None, certificate id : 0]
--------
Engineer [Full name : John Snow, age : 23, address : None, contract count : 0]
```

#### Fout: toegang van buitenaf bij protected en private inheritance [▶ 23:55:44](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=86144s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: members zijn na protected/private inheritance niet meer van buitenaf bereikbaar
#include <string>

class Person {
public:
    std::string m_full_name{"None"};
protected:
    int m_age{0};
private:
    std::string m_address{"None"};
};

class Nurse : protected Person {};
class Engineer : private Person {};

int main() {
    Nurse nurse1;
    nurse1.m_full_name = "Davy Jones";        // error: 'std::string Person::m_full_name' is inaccessible within this context
    nurse1.m_age = 51;                        // error: 'int Person::m_age' is protected within this context

    Engineer engineer1;
    engineer1.m_full_name = "Olivier Godson"; // error: inaccessible within this context
    engineer1.m_address = "Junk";             // error: 'std::string Person::m_address' is private within this context
    return 0;
}
```

#### Fout: de egoïstische private inheritance doorbreekt de keten [▶ 24:15:53](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=87353s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: alles uit Person is private aan Engineer, CivilEngineer kan er niet meer bij
#include <iostream>
#include <string>

class Person {
public:
    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string m_full_name{"None"};
protected:
    int m_age{0};
private:
    std::string m_address{"None"};
};

class Engineer : private Person {   // "egoïstisch"
protected:
    int m_contract_count{0};
};

class CivilEngineer : public Engineer {
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce);
public:
    void build_road() {
        get_full_name();            // error: private aan Engineer
        m_full_name = "Daniel Gray"; // error: private aan Engineer
        m_age = 45;                  // error: private aan Engineer
    }
};

std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce) {
    // zelfs een friend van CivilEngineer kan get_full_name niet aanroepen
    out << ce.get_full_name();      // error: 'Person::get_full_name' is inaccessible within this context
    return out;
}

int main() {
    CivilEngineer ce1;
    std::cout << ce1 << std::endl;
    return 0;
}
```

#### Members terughalen met using (incl. overloads) [▶ 24:34:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=88463s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person() = default;
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {}

    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }

    int add(int a, int b) const { return a + b; }            // twee overloads
    int add(int a, int b, int c) const { return a + b + c; }

    void do_something() const { std::cout << "Hello" << std::endl; }

    std::string m_full_name{"None"};
protected:
    int m_age{0};
private:
    std::string m_address{"None"};
};

class Engineer : private Person {
public:
    Engineer() = default;
    int get_contract_count() const { return m_contract_count; }

    using Person::add;              // ALLE overloads van add, nu public
protected:
    using Person::get_full_name;    // terug naar protected niveau
    using Person::get_age;
    using Person::get_address;
    // using Person::m_address;     // compilerfout: private aan Person, niet terug te halen
private:
    int m_contract_count{0};
};

class CivilEngineer : public Engineer {
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce);
public:
    CivilEngineer() = default;
    void build_road() {
        std::cout << "add(10, 2)     : " << add(10, 2) << std::endl;
        std::cout << "add(10, 2, 3)  : " << add(10, 2, 3) << std::endl;
    }
    // using Engineer::do_something; // compilerfout: do_something is al private aan Engineer
};

std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce) {
    // werkt weer: get_* zijn nu protected in Engineer
    out << "CivilEngineer [Full name : " << ce.get_full_name()
        << ", age : " << ce.get_age()
        << ", address : " << ce.get_address()
        << ", contract count : " << ce.get_contract_count() << "]";
    return out;
}

int main() {
    CivilEngineer ce1;
    std::cout << ce1 << std::endl;
    ce1.build_road();
    std::cout << "van buitenaf   : " << ce1.add(1, 2) << std::endl; // add is public
    return 0;
}
```

```text
CivilEngineer [Full name : None, age : 0, address : None, contract count : 0]
add(10, 2)     : 12
add(10, 2, 3)  : 15
van buitenaf   : 3
```

#### Fout: private members kun je niet terughalen [▶ 24:40:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=88854s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: resurrecten van iets wat al private is in de klasse erboven
#include <iostream>
#include <string>

class Person {
public:
    void do_something() const { std::cout << "Hello" << std::endl; }
private:
    std::string m_address{"None"};
};

class Engineer : private Person {
protected:
    using Person::m_address;   // error: 'std::string Person::m_address' is private within this context
};

class CivilEngineer : public Engineer {
public:
    using Engineer::do_something;  // error: do_something is private aan Engineer (inaccessible)
};

int main() {
    CivilEngineer ce;
    return 0;
}
```

#### Volgorde van default constructors [▶ 24:51:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=89483s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>

class Person {
public:
    Person() { std::cout << "Default constructor for Person called" << std::endl; }
private:
    std::string m_full_name{"None"};
};

class Engineer : public Person {
public:
    Engineer() { std::cout << "Default constructor for Engineer called" << std::endl; }
private:
    int m_contract_count{0};
};

class CivilEngineer : public Engineer {
public:
    CivilEngineer() { std::cout << "Default constructor for CivilEngineer called" << std::endl; }
private:
    std::string m_speciality{"None"};
};

int main() {
    CivilEngineer ce1;   // bouwt Person-deel, dan Engineer-laag, dan CivilEngineer-laag
    return 0;
}
```

```text
Default constructor for Person called
Default constructor for Engineer called
Default constructor for CivilEngineer called
```

#### Custom constructors: data doorgeven via de initializer list [▶ 25:07:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=90439s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
public:
    Person() { std::cout << "Default constructor for Person called" << std::endl; }
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {
        std::cout << "Custom constructor for Person called" << std::endl;
    }
    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }
protected:
    std::string m_full_name{"None"};
    int m_age{0};
private:
    std::string m_address{"None"};
};

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << "Person [Full name : " << p.m_full_name << ", age : " << p.m_age
        << ", address : " << p.m_address << "]";
    return out;
}

class Engineer : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Engineer& e);
public:
    Engineer() { std::cout << "Default constructor for Engineer called" << std::endl; }
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
        : Person(fullname, age, address),          // basisconstructor eerst
          m_contract_count(contract_count_param) { // dan eigen member
        std::cout << "Custom constructor for Engineer called" << std::endl;
    }
    int get_contract_count() const { return m_contract_count; }
private:
    int m_contract_count{0};
};

std::ostream& operator<<(std::ostream& out, const Engineer& e) {
    out << "Engineer [Full name : " << e.get_full_name() << ", age : " << e.get_age()
        << ", address : " << e.get_address()
        << ", contract count : " << e.m_contract_count << "]";
    return out;
}

class CivilEngineer : public Engineer {
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce);
public:
    CivilEngineer() { std::cout << "Default constructor for CivilEngineer called" << std::endl; }
    CivilEngineer(std::string_view fullname, int age, std::string_view address,
                  int contract_count, std::string_view speciality)
        : Engineer(fullname, age, address, contract_count), // directe basis
          m_speciality(speciality) {
        std::cout << "Custom constructor for CivilEngineer called" << std::endl;
    }
private:
    std::string m_speciality{"None"};
};

std::ostream& operator<<(std::ostream& out, const CivilEngineer& ce) {
    out << "CivilEngineer [Full name : " << ce.get_full_name() << ", age : " << ce.get_age()
        << ", address : " << ce.get_address()
        << ", contract count : " << ce.get_contract_count()
        << ", speciality : " << ce.m_speciality << "]";
    return out;
}

int main() {
    Person person1("John Snow", 27, "Winterfell Cold Str. #1");
    std::cout << person1 << std::endl << "--------" << std::endl;

    Engineer engineer1("Daniel Gray", 41, "Green Bronx St. 87 #44", 12);
    std::cout << engineer1 << std::endl << "--------" << std::endl;

    CivilEngineer civil_engineer1("John Travolta", 51, "Tiny Dog 42 Str. #89", 31, "Road Strength");
    std::cout << civil_engineer1 << std::endl;
    return 0;
}
```

```text
Custom constructor for Person called
Person [Full name : John Snow, age : 27, address : Winterfell Cold Str. #1]
--------
Custom constructor for Person called
Custom constructor for Engineer called
Engineer [Full name : Daniel Gray, age : 41, address : Green Bronx St. 87 #44, contract count : 12]
--------
Custom constructor for Person called
Custom constructor for Engineer called
Custom constructor for CivilEngineer called
CivilEngineer [Full name : John Travolta, age : 51, address : Tiny Dog 42 Str. #89, contract count : 31, speciality : Road Strength]
```

#### Fout: basis-members zelf initialiseren [▶ 25:17:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=91068s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: m_address is private aan Person; initializer list mag alleen eigen members bevatten
#include <string>
#include <string_view>

class Person {
public:
    Person() = default;
protected:
    std::string m_full_name{"None"};
    int m_age{0};
private:
    std::string m_address{"None"};
};

class Engineer : public Person {
public:
    // Slechte manier 1: toewijzen in de body
    Engineer(std::string_view fullname, int age, std::string_view address, int cc) {
        m_full_name = fullname;   // compileert (protected)
        m_age = age;              // compileert (protected)
        m_address = address;      // error: 'std::string Person::m_address' is private within this context
        m_contract_count = cc;
    }
    // Slechte manier 2: basis-members in de initializer list
    Engineer(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {}
        // error: class 'Engineer' does not have any field named 'm_full_name' (idem m_age, m_address)
private:
    int m_contract_count{0};
};

int main() {
    Engineer e("Daniel Gray", 41, "Somewhere", 12);
    return 0;
}
```

#### Copy constructor, slechte versie: basisdeel wordt default opgebouwd [▶ 25:38:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=92320s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm. GCC geeft met `-Wextra` hier terecht een waarschuwing dat de basisklasse in de copy constructor expliciet geïnitialiseerd zou moeten worden.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person() { std::cout << "Default constructor for Person called" << std::endl; }
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {
        std::cout << "Custom constructor for Person called" << std::endl;
    }
    Person(const Person& source)
        : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address) {
        std::cout << "Custom copy constructor called for Person" << std::endl;
    }
    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }
private:
    std::string m_full_name{"None"};
    int m_age{0};
    std::string m_address{"None"};
};

class Engineer : public Person {
public:
    Engineer(std::string_view fullname, int age, std::string_view address, int cc)
        : Person(fullname, age, address), m_contract_count(cc) {
        std::cout << "Custom constructor for Engineer called" << std::endl;
    }
    // SLECHT: alleen het eigen member; Person-deel krijgt de default constructor
    Engineer(const Engineer& source) : m_contract_count(source.m_contract_count) {
        std::cout << "Custom copy constructor called for Engineer" << std::endl;
    }
    void print() const {
        std::cout << "Engineer [Full name : " << get_full_name() << ", age : " << get_age()
                  << ", address : " << get_address()
                  << ", contract count : " << m_contract_count << "]" << std::endl;
    }
private:
    int m_contract_count{0};
};

int main() {
    Engineer engineer1("Daniel Gray", 41, "Green Bronx St. 87 #44", 12);
    std::cout << "--------" << std::endl;
    Engineer engineer2{engineer1};
    engineer2.print();   // persoonsgegevens zijn verloren
    return 0;
}
```

```text
Custom constructor for Person called
Custom constructor for Engineer called
--------
Default constructor for Person called
Custom copy constructor called for Engineer
Engineer [Full name : None, age : 0, address : None, contract count : 12]
```

#### Copy constructors, goede versie: `Person(source)` en `Engineer(source)` [▶ 25:45:09](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=92709s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {
        std::cout << "Custom constructor for Person called" << std::endl;
    }
    Person(const Person& source)   // const reference: anders eindeloze kopieerketen
        : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address) {
        std::cout << "Custom copy constructor called for Person" << std::endl;
    }
    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }
private:
    std::string m_full_name{"None"};
    int m_age{0};
    std::string m_address{"None"};
};

class Engineer : public Person {
public:
    Engineer(std::string_view fullname, int age, std::string_view address, int cc)
        : Person(fullname, age, address), m_contract_count(cc) {
        std::cout << "Custom constructor for Engineer called" << std::endl;
    }
    Engineer(const Engineer& source)
        : Person(source),                          // alleen het Person-deel van source wordt gebruikt
          m_contract_count(source.m_contract_count) {
        std::cout << "Custom copy constructor called for Engineer" << std::endl;
    }
    int get_contract_count() const { return m_contract_count; }
private:
    int m_contract_count{0};
};

class CivilEngineer : public Engineer {
public:
    CivilEngineer(std::string_view fullname, int age, std::string_view address,
                  int cc, std::string_view speciality)
        : Engineer(fullname, age, address, cc), m_speciality(speciality) {
        std::cout << "Custom constructor for CivilEngineer called" << std::endl;
    }
    CivilEngineer(const CivilEngineer& source)
        : Engineer(source), m_speciality(source.m_speciality) {
        std::cout << "Custom copy constructor called for CivilEngineer" << std::endl;
    }
    void print() const {
        std::cout << "CivilEngineer [Full name : " << get_full_name() << ", age : " << get_age()
                  << ", address : " << get_address()
                  << ", contract count : " << get_contract_count()
                  << ", speciality : " << m_speciality << "]" << std::endl;
    }
private:
    std::string m_speciality{"None"};
};

int main() {
    CivilEngineer eng1("Daniel Gray", 41, "Green Bronx St. 87 #44", 12, "Road Strength");
    std::cout << "--------" << std::endl;
    CivilEngineer eng2{eng1};   // copy constructors in de hele keten
    eng2.print();
    return 0;
}
```

```text
Custom constructor for Person called
Custom constructor for Engineer called
Custom constructor for CivilEngineer called
--------
Custom copy constructor called for Person
Custom copy constructor called for Engineer
Custom copy constructor called for CivilEngineer
CivilEngineer [Full name : Daniel Gray, age : 41, address : Green Bronx St. 87 #44, contract count : 12, speciality : Road Strength]
```

#### Base constructors erven met `using Person::Person;` [▶ 25:58:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93528s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person() { std::cout << "Default constructor for Person called" << std::endl; }
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {
        std::cout << "Custom constructor for Person called" << std::endl;
    }
    Person(const Person& source)
        : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address) {
        std::cout << "Custom copy constructor called for Person" << std::endl;
    }
    std::string get_full_name() const { return m_full_name; }
    int get_age() const { return m_age; }
    std::string get_address() const { return m_address; }
private:
    std::string m_full_name{"None"};
    int m_age{0};
    std::string m_address{"None"};
};

class Engineer : public Person {
public:
    using Person::Person;   // erft alle constructors van Person (behalve copy constructors)

    // eigen constructor ernaast, voor de vierde parameter
    Engineer(std::string_view fullname, int age, std::string_view address, int cc)
        : Person(fullname, age, address), m_contract_count(cc) {
        std::cout << "Custom constructor for Engineer called" << std::endl;
    }
    void print() const {
        std::cout << "Engineer [Full name : " << get_full_name() << ", age : " << get_age()
                  << ", address : " << get_address()
                  << ", contract count : " << m_contract_count << "]" << std::endl;
    }
private:
    int m_contract_count{0};   // geërfde constructors raken dit niet aan
};

int main() {
    Engineer eng1;                                      // default constructor
    eng1.print();
    std::cout << "--------" << std::endl;

    Engineer eng2("Daniel Gray", 23, "Junk address");   // geërfde 3-parameter constructor
    eng2.print();
    std::cout << "--------" << std::endl;

    Engineer eng3("Daniel Gray", 23, "Junk address", 4); // eigen 4-parameter constructor
    eng3.print();
    return 0;
}
```

```text
Default constructor for Person called
Engineer [Full name : None, age : 0, address : None, contract count : 0]
--------
Custom constructor for Person called
Engineer [Full name : Daniel Gray, age : 23, address : Junk address, contract count : 0]
--------
Custom constructor for Person called
Custom constructor for Engineer called
Engineer [Full name : Daniel Gray, age : 23, address : Junk address, contract count : 4]
```

#### Fout: vier argumenten met alleen geërfde constructors [▶ 26:02:02](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=93722s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: geërfde constructors kennen geen vierde parameter
#include <string>
#include <string_view>

class Person {
public:
    Person() = default;
    Person(std::string_view fullname, int age, std::string_view address)
        : m_full_name(fullname), m_age(age), m_address(address) {}
private:
    std::string m_full_name{"None"};
    int m_age{0};
    std::string m_address{"None"};
};

class Engineer : public Person {
public:
    using Person::Person;
private:
    int m_contract_count{0};
};

int main() {
    Engineer eng("Daniel Gray", 23, "Junk address", 45); // error: no matching function for call to 'Engineer::Engineer(...)'
    return 0;
}
```

#### Volgorde van constructors en destructors [▶ 26:08:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94113s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Person {
public:
    Person(std::string_view fullname) : m_full_name(fullname) {
        std::cout << "Custom constructor for Person called" << std::endl;
    }
    ~Person() { std::cout << "Destructor for Person called" << std::endl; }
private:
    std::string m_full_name;
};

class Engineer : public Person {
public:
    Engineer(std::string_view fullname, int cc) : Person(fullname), m_contract_count(cc) {
        std::cout << "Custom constructor for Engineer called" << std::endl;
    }
    ~Engineer() { std::cout << "Destructor for Engineer called" << std::endl; }
private:
    int m_contract_count;
};

class CivilEngineer : public Engineer {
public:
    CivilEngineer(std::string_view fullname, int cc, std::string_view speciality)
        : Engineer(fullname, cc), m_speciality(speciality) {
        std::cout << "Custom constructor for CivilEngineer called" << std::endl;
    }
    ~CivilEngineer() { std::cout << "Destructor for CivilEngineer called" << std::endl; }
private:
    std::string m_speciality;
};

int main() {
    {
        CivilEngineer ce1("Daniel Gray", 12, "Road Strength");
        std::cout << "--- object in gebruik ---" << std::endl;
    }   // hier eindigt de levensduur van ce1
    return 0;
}
```

```text
Custom constructor for Person called
Custom constructor for Engineer called
Custom constructor for CivilEngineer called
--- object in gebruik ---
Destructor for CivilEngineer called
Destructor for Engineer called
Destructor for Person called
```

#### Hergebruikte namen: Parent en Child [▶ 26:14:59](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94499s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

class Parent {
public:
    Parent() = default;
    Parent(int member_var) : m_member_var(member_var) {}
    ~Parent() = default;
    void print_var() const {
        std::cout << "The value in parent is : " << m_member_var << std::endl;
    }
protected:                 // protected zodat Child er via Parent:: bij kan
    int m_member_var{100};
};

class Child : public Parent {
public:
    Child() = default;
    Child(int member_var) : m_member_var(member_var) {}   // Parent-deel: default constructor
    ~Child() = default;    // zonder definitie: undefined reference to Child::~Child()

    void print_var() const {   // verbergt Parent::print_var
        std::cout << "The value in child is : " << m_member_var << std::endl;
    }
    void show_values() const {
        std::cout << "The value in child is : " << m_member_var << std::endl;
        std::cout << "The value in parent is : " << Parent::m_member_var << std::endl;
    }
private:
    int m_member_var{1000};    // verbergt Parent::m_member_var
};

int main() {
    Parent p1;
    p1.print_var();
    std::cout << "--------" << std::endl;

    Child c1(33);
    c1.print_var();            // Child-versie
    c1.Parent::print_var();    // expliciet de Parent-versie
    std::cout << "--------" << std::endl;
    c1.show_values();
    return 0;
}
```

```text
The value in parent is : 100
--------
The value in child is : 33
The value in parent is : 100
--------
The value in child is : 33
The value in parent is : 100
```

### Valkuilen & veelgemaakte fouten

#### Private van de basis betekent: nooit rechtstreeks bereikbaar
Welke inheritance je ook kiest, private members van de basisklasse zijn niet direct te gebruiken in afgeleide klassen of hun friends. Ze zitten wel in het object (zie debugger). Gebruik public/protected getters, of beter: laat een basisconstructor ze initialiseren.

#### "Blijft private" in de tabel is misleidend
Bij public inheritance "blijft private private", maar dan private **aan de basisklasse**, niet private aan de afgeleide klasse. De afgeleide klasse kan er dus zelf ook niet bij.

#### Protected/private inheritance sluit ook de oorspronkelijk public members af
Na `class Nurse : protected Person` is `nurse1.m_full_name` niet meer bruikbaar in `main`, hoewel het in `Person` public was. De base class access specifier beperkt altijd, hij versoepelt nooit.

#### Private inheritance blokkeert de hele rest van de keten
Een klasse die van een privaat erfende klasse afleidt, kan niets van de oorspronkelijke basis gebruiken, zelfs niet in een friend-functie. Je kunt het met `using` niet terughalen in de kleinkindklasse, omdat het al private is in de klasse erboven.

#### `using` kan niets terughalen wat al private is
`using Person::m_address;` mislukt als `m_address` private is in `Person`. Je kunt alleen members terughalen die in de directe basis bereikbaar waren (public of protected).

#### Basis-members initialiseren in de initializer list of body van de afgeleide klasse
Een initializer list mag alleen eigen members bevatten (`does not have any field named ...`). In de body toewijzen faalt voor private basis-members en negeert data stilletjes als je die regel weglaat. Roep de basisconstructor aan.

#### Copy constructor die het basisdeel vergeet
Als je in een zelfgeschreven copy constructor geen `Base(source)` aanroept, gebruikt de compiler de **default** constructor van de basis. De kopie heeft dan default-data in het basisdeel. GCC waarschuwt hiervoor met `-Wextra`.

#### Geen default constructor in de basisklasse
Als een afgeleide constructor geen basisconstructor aanroept, zoekt de compiler de default constructor van de basis. Ontbreekt die, dan krijg je een compilerfout.

#### Geërfde constructors initialiseren alleen het basisdeel
Met `using Person::Person;` lijkt `Engineer("Daniel Gray", 23, "...")` een volwaardige engineer-constructor, maar `m_contract_count` krijgt alleen zijn default-waarde. Copy constructors worden bovendien nooit geërfd.

#### Gedeclareerde maar niet gedefinieerde destructor
`~Player();` in de header zonder definitie in de `.cpp` geeft een linkerfout (`undefined reference to ...::~Player()`). Definieer hem, gebruik `= default`, of laat hem weg.

#### Non-const reference-parameter en letterlijke tekst
`Player(std::string& game)` accepteert geen `"Basketball"` (tijdelijk object). Gebruik `std::string_view` by value of `const std::string&`.

#### Name hiding verwarren met overriding
Een member met dezelfde naam in de afgeleide klasse verbergt het basismember. Op een `Child` krijg je de `Child`-versie. De basisversie bereik je alleen expliciet met `Parent::`.

### Best practices

- Gebruik standaard **public inheritance**. Protected en vooral private inheritance alleen als je dat afschermende gedrag echt bewust wilt.
- Wil je dat afgeleide klassen bij data kunnen maar de buitenwereld niet, gebruik dan `protected` in de basisklasse.
- Initialiseer basisdata **altijd via een constructor van de directe basisklasse** in de initializer list: `: Person(fullname, age, address), m_contract_count(cc)`. Initialiseer daarna alleen je eigen members.
- Schrijf copy constructors in een hiërarchie als `Derived(const Derived& source) : Base(source), m_eigen(source.m_eigen) {}`. Zo hergebruik je de copy constructor van de basis zonder extra getters of tijdelijke objecten.
- Voorzie klassen in een hiërarchie altijd van een default constructor, of zorg dat elke afgeleide constructor expliciet een basisconstructor aanroept.
- Vermijd volgens de docent het "resurrecten" van members met `using` na private inheritance, en het erven van constructors met `using Base::Base;`: beide maken code verwarrend. Herken ze wel in andermans code.
- Geef parameters door als `std::string_view` of `const` reference om kopieën te vermijden. Geef parameters een andere naam dan de members (bv. `contract_count_param`).
- Gebruik de debugger (Locals) om te zien dat een afgeleid object zijn basisdelen bevat.
- Laat de compiler de destructor genereren (of gebruik `= default`) als je geen dynamisch geheugen beheert.

> 💡 Aanvulling: bij een copy constructor hoort meestal ook een copy assignment operator (`operator=`), die in een hiërarchie op dezelfde manier de basisversie moet aanroepen (`Base::operator=(source);`). Dat behandelt de docent in dit hoofdstuk niet.

### Samenvatting

- Inheritance bouwt nieuwe klassen op bestaande ("is-een"-relatie) met `class Derived : public Base`. Elk afgeleid object bevat een volledig basisdeel.
- Public members van de basis zijn bruikbaar in en via afgeleide klassen. Private members van de basis zijn nooit rechtstreeks bereikbaar, ook niet voor friends van de afgeleide klasse.
- `protected` members zijn bruikbaar in afgeleide klassen, maar niet van buitenaf.
- De base class access specifier (`public`/`protected`/`private`) bepaalt het hoogste toegangsniveau van geërfde members. Hij kan beperken, maar nooit versoepelen.
- Private inheritance maakt alles private aan de afgeleide klasse. Klassen verderop in de keten kunnen dan niets meer van de oorspronkelijke basis gebruiken.
- Met `using Base::naam;` haal je members (inclusief alle overloads) terug op het niveau van de sectie waarin de declaratie staat, maar nooit iets wat al private is.
- Constructors lopen van basis naar meest afgeleid. Zonder expliciete keuze wordt de default constructor van de basis gebruikt.
- Geef data door met een aanroep van de basisconstructor in de initializer list. Bij copy constructors gebruik je `Base(source)`.
- `using Base::Base;` erft constructors (niet de copy constructors) die alleen het basisdeel initialiseren. De docent raadt het af.
- Destructors lopen in omgekeerde volgorde. Een gelijknamig member in de afgeleide klasse verbergt het basismember, en `Base::` bereikt de basisversie.

### Oefeningen

1. **Vehicle en Car.** Maak een klasse `Vehicle` met een protected member `m_wheels` (standaard 4) en een public getter `get_wheels()`. Leid `Car` public af met een eigen private member `m_brand`. Geef `Car` een constructor `Car(std::string_view brand)` en een member function `print()` die het merk en (rechtstreeks via het protected member) het aantal wielen print. Maak in `main` een `Car("Volvo")`, roep `print()` aan en print daarna `get_wheels()` vanuit `main`.

2. **Voorspel de toegang.** Gegeven `class Base { public: int a{1}; protected: int b{2}; private: int c{3}; };` en drie klassen `PubD : public Base`, `ProtD : protected Base` en `PrivD : private Base`. Schrijf een programma dat in elke afgeleide klasse een member function `sum()` heeft die alles optelt wat daar bereikbaar is. Print in `main` voor elke klasse `sum()` en, waar het van buitenaf mag, ook `a`. Zet de regels die niet zouden compileren als commentaar.

3. **Constructorketen.** Bouw `Animal(std::string_view name)` ← `Dog(std::string_view name, int age)` ← `Puppy(std::string_view name, int age, std::string_view toy)`. Elke constructor geeft de data door aan zijn directe basis via de initializer list en print welke constructor aangeroepen wordt. Geef elke klasse ook een destructor met een melding, en een `print()` in `Puppy`. Maak een `Puppy` in een eigen blok `{ }`.

4. **Copy constructor in de hiërarchie.** Voeg aan oefening 3 copy constructors toe aan alle drie de klassen (met melding), op de juiste manier met `Animal(source)` en `Dog(source)`. Kopieer in `main` een `Puppy` en print de kopie.

<details><summary>Uitwerking</summary>

**Oefening 1**

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Vehicle {
public:
    int get_wheels() const { return m_wheels; }
protected:
    int m_wheels{4};
};

class Car : public Vehicle {
public:
    Car(std::string_view brand) : m_brand(brand) {}
    void print() const {
        // m_wheels is protected in Vehicle: bruikbaar in de afgeleide klasse
        std::cout << "Car : " << m_brand << ", wheels : " << m_wheels << std::endl;
    }
private:
    std::string m_brand;
};

int main() {
    Car car("Volvo");
    car.print();
    std::cout << "Wheels from main : " << car.get_wheels() << std::endl;  // public getter
    // car.m_wheels = 3;  // compilerfout: protected
    return 0;
}
```

```text
Car : Volvo, wheels : 4
Wheels from main : 4
```

**Oefening 2**

```cpp
#include <iostream>

class Base {
public:
    int a{1};
protected:
    int b{2};
private:
    int c{3};
};

class PubD : public Base {
public:
    int sum() const { return a + b; /* + c: compilerfout, private aan Base */ }
};

class ProtD : protected Base {
public:
    int sum() const { return a + b; }
};

class PrivD : private Base {
public:
    int sum() const { return a + b; }
};

int main() {
    PubD pub;
    ProtD prot;
    PrivD priv;
    std::cout << "PubD sum  : " << pub.sum() << ", a : " << pub.a << std::endl;
    std::cout << "ProtD sum : " << prot.sum() << std::endl;  // prot.a: compilerfout (protected)
    std::cout << "PrivD sum : " << priv.sum() << std::endl;  // priv.a: compilerfout (private)
    return 0;
}
```

```text
PubD sum  : 3, a : 1
ProtD sum : 3
PrivD sum : 3
```

**Oefening 3**

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view name) : m_name(name) {
        std::cout << "Constructor for Animal called" << std::endl;
    }
    ~Animal() { std::cout << "Destructor for Animal called" << std::endl; }
    std::string get_name() const { return m_name; }
private:
    std::string m_name;
};

class Dog : public Animal {
public:
    Dog(std::string_view name, int age) : Animal(name), m_age(age) {
        std::cout << "Constructor for Dog called" << std::endl;
    }
    ~Dog() { std::cout << "Destructor for Dog called" << std::endl; }
    int get_age() const { return m_age; }
private:
    int m_age;
};

class Puppy : public Dog {
public:
    Puppy(std::string_view name, int age, std::string_view toy)
        : Dog(name, age), m_toy(toy) {
        std::cout << "Constructor for Puppy called" << std::endl;
    }
    ~Puppy() { std::cout << "Destructor for Puppy called" << std::endl; }
    void print() const {
        std::cout << "Puppy [name : " << get_name() << ", age : " << get_age()
                  << ", toy : " << m_toy << "]" << std::endl;
    }
private:
    std::string m_toy;
};

int main() {
    {
        Puppy puppy("Rex", 1, "Ball");
        puppy.print();
    }
    return 0;
}
```

```text
Constructor for Animal called
Constructor for Dog called
Constructor for Puppy called
Puppy [name : Rex, age : 1, toy : Ball]
Destructor for Puppy called
Destructor for Dog called
Destructor for Animal called
```

**Oefening 4**

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view name) : m_name(name) {}
    Animal(const Animal& source) : m_name(source.m_name) {
        std::cout << "Copy constructor for Animal called" << std::endl;
    }
    std::string get_name() const { return m_name; }
private:
    std::string m_name;
};

class Dog : public Animal {
public:
    Dog(std::string_view name, int age) : Animal(name), m_age(age) {}
    Dog(const Dog& source) : Animal(source), m_age(source.m_age) {   // Animal-deel van source
        std::cout << "Copy constructor for Dog called" << std::endl;
    }
    int get_age() const { return m_age; }
private:
    int m_age;
};

class Puppy : public Dog {
public:
    Puppy(std::string_view name, int age, std::string_view toy) : Dog(name, age), m_toy(toy) {}
    Puppy(const Puppy& source) : Dog(source), m_toy(source.m_toy) {
        std::cout << "Copy constructor for Puppy called" << std::endl;
    }
    void print() const {
        std::cout << "Puppy [name : " << get_name() << ", age : " << get_age()
                  << ", toy : " << m_toy << "]" << std::endl;
    }
private:
    std::string m_toy;
};

int main() {
    Puppy original("Rex", 1, "Ball");
    Puppy copy{original};
    copy.print();
    return 0;
}
```

```text
Copy constructor for Animal called
Copy constructor for Dog called
Copy constructor for Puppy called
Puppy [name : Rex, age : 1, toy : Ball]
```

</details>

---

<a id="h19"></a>

## Hoofdstuk 19 – Polymorphism (26:21:03 – 31:07:29) [▶ link](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94863s)

### Leerdoelen

- Uitleggen wat polymorphism is: base-class pointers en references gebruiken om derived objecten te beheren, en welke ontwerpproblemen (één functie, één collectie) het oplost.
- Het verschil kennen tussen **static binding** (standaard; het type van de pointer/reference beslist) en **dynamic binding** (met `virtual`; het type van het werkelijke object beslist, at runtime).
- Weten dat polymorphic objecten groter zijn, en herkennen wanneer **object slicing** optreedt (toewijzing aan een base object, arrays van objecten).
- Weten welke soorten elementen je in een polymorphic collectie kunt bewaren (objecten, references, raw en smart pointers).
- `override` en `final` correct gebruiken, en begrijpen hoe overloading, overriding en hiding samenspelen.
- Polymorphism op verschillende niveaus van een hiërarchie toepassen, en static members correct combineren met inheritance.
- De valkuilen kennen van default arguments bij virtual functions en van virtual calls in constructors/destructors.
- Weten waarom een base class een **virtual destructor** nodig heeft.
- Veilig downcasten met `dynamic_cast` (pointers, references, nullptr-controle).
- Pure virtual functions, abstract classes en interfaces (abstracte klassen zonder data) opzetten en gebruiken.

### Verband met eerdere hoofdstukken

- **Hoofdstuk 18 (Inheritance)** is de directe basis: is-a-relaties, public inheritance, `protected` members, het doorgeven van constructordata via de initializer list en de volgorde van constructors/destructors komen hier constant terug. Polymorphism bouwt daarop voort: een derived object *bevat* een base part, en daarom mag een base pointer ernaar wijzen.
- **Hoofdstuk 17 (Classes)**: constructors, destructors, `this`, `const` member functions, static members, klassen opsplitsen in `.h`/`.cpp`, en de `->`-operator.
- **Hoofdstuk 8 (Pointers)** en **hoofdstuk 9 (References)**: polymorphism werkt enkel via pointers en references; `new`/`delete`, dangling pointers, memory leaks en `nullptr`-controles zijn nodig bij `delete` via een base pointer en bij `dynamic_cast`. Smart pointers (`std::unique_ptr`, `std::shared_ptr`, header `<memory>`) worden als bekend verondersteld.
- **Hoofdstuk 7 (Arrays)**: een array bevat één type, en elementen worden gekopieerd; dat verklaart waarom slicing in collecties optreedt.
- **Hoofdstuk 13 (Function overloading)**: nodig om te begrijpen hoe overloads van een virtual functie verborgen worden.
- **Hoofdstuk 10 (Strings)**: constructorparameters worden overal `std::string_view`.
- **Hoofdstuk 11 (Functions)**: default arguments.

### Uitleg

#### Wat is polymorphism en waarom wil je het?

De docent vertrekt van een inheritance-hiërarchie met `Shape` als base class, `Oval` die van `Shape` erft en `Circle` die van `Oval` erft (en in gedachten nog `Rectangle`, `Triangle`, ...). Het kernidee van polymorphism: **een base-class pointer of base-class reference gebruiken om derived objecten te beheren**.

```c++
Shape* p1 = new Circle(...);     // base pointer beheert een Circle
Shape* p2 = new Rectangle(...);  // ... of een Rectangle
Shape& r1 = circle1;             // base reference beheert een Circle
```

Dat is geldige C++: een `Circle` *is een* `Shape` (is-a-relatie uit hoofdstuk 18), dus het adres van een `Circle` past in een `Shape*`.

Waarom zou je dat willen? Twee problemen die anders onoplosbaar zijn:

1. **Eén functie voor alle types.** Zonder polymorphism heb je per shape een eigen functie nodig (`draw_circle(Circle&)`, `draw_oval(Oval&)`, ...). Een functie die een `Oval` verwacht weigert een `Circle` niet, maar een functie voor `Circle` weigert een `Rectangle` wél (compilerfout). Met 100 shapes heb je 100 functies. Met polymorphism schrijf je één `draw_shape(Shape*)` of `draw_shape(const Shape&)` en geef je er elk derived object aan.
2. **Eén collectie voor alle types.** Een array bevat per definitie maar één type: in een `int`-array kun je geen `std::string` stoppen, en in een array van `Circle` geen `Oval`. Zonder polymorphism heb je een array per shape-type en een aparte loop per array. Met een array van `Shape*` kun je circles, ovals, rectangles ... samen bewaren en in één loop `draw()` aanroepen.

"Polymorphism" betekent letterlijk *meerdere vormen*: de base pointer/reference kan op het ene moment een `Circle`, op een ander moment een `Rectangle` of `Oval` beheren — één pointer, meerdere vormen.

[▶ 26:21:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=94881s)

#### De voorbeeldklassen Shape, Oval en Circle

De klassen die de rest van het hoofdstuk terugkomen:

- `Shape`: één member `m_description` (de docent past de constructorparameter aan naar `std::string_view` "want we gebruiken modern C++") en een methode `draw()` die enkel de beschrijving print.
- `Oval : public Shape`: extra members `m_x_radius` en `m_y_radius`, een constructor die de twee radii plus de beschrijving doorgeeft, en een eigen `draw()` die beschrijving én radii print. De getters `get_x_rad()` / `get_y_rad()` zet hij in een **protected** sectie (bruikbaar in derived klassen, niet van buitenaf), en `const` omdat ze het object niet wijzigen.
- `Circle : public Oval`: een oval met gelijke radii. Geen eigen members; de constructor neemt één `radius` en stuurt die als x- én y-radius door naar het `Oval`-deel. `draw()` print beschrijving en radius (via `get_x_rad()`).

In de opname staan de klassen in aparte `.h`/`.cpp`-bestanden; in de voorbeelden hieronder zijn ze samengevoegd tot één bestand zodat elk programma op zichzelf compileert.

[▶ 26:26:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=95214s)

#### Static binding: het standaardgedrag

Wat we *willen*: roep je `draw()` aan via een `Shape*` die naar een `Oval` wijst, dan moet `Oval::draw()` lopen — de **meest specifieke** versie voor het echte object.

Wat we *krijgen* (zonder extra werk): telkens `Shape::draw()`. Dat heet **static binding**. De compiler kijkt naar het **type van de pointer of reference** (hier `Shape`) en beslist daarmee al bij het compileren welke functie wordt aangeroepen. Het werkelijke object waar de pointer naar wijst speelt geen rol. Hetzelfde gebeurt met een `Shape&`.

De docent demonstreert dit stap voor stap: rechtstreeks via de objecten (`shape1.draw()`, `oval1.draw()`, `circle1.draw()`) krijg je wel de juiste versies, maar zodra je via `shape_ptr` of `shape_ref` werkt, zie je drie keer "Shape::draw() called" — met wél de beschrijving van het echte object ("Drawing Oval1"), omdat `m_description` in het `Shape`-deel zit.

Dat je een `Oval*` of `Circle*` in een `Shape*` mag stoppen is logisch: een `Oval` bevat een `Shape`-deel, een `Circle` bevat een `Oval`-deel dat op zijn beurt een `Shape`-deel bevat.

Het gevolg voor het ontwerp: om toch de juiste `draw()` te krijgen, moet je aparte functies (`draw_circle`, `draw_oval`) en aparte arrays (`Circle circles[]`, `Oval ovals[]`) maken. Bij veel shapes wordt dat onbeheersbaar — "slecht ontwerp", aldus de docent.

[▶ 26:29:19](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=95359s) · demo in VS Code [▶ 26:38:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=95893s)

#### Dynamic binding met virtual functions

De oplossing is verrassend klein: markeer de methode die dynamisch opgelost moet worden met het keyword **`virtual`**, in `Shape`, in `Oval` en in `Circle`.

```c++
class Shape {
public:
    virtual void draw() const;
};
```

Vanaf dan doet de compiler **dynamic binding** (ook *late binding* genoemd): bij een aanroep via een base pointer of base reference kijkt hij niet meer naar het type van de pointer, maar naar het **type van het werkelijke object** dat beheerd wordt, en die keuze gebeurt **at runtime**. Resultaat:

- `shape_ptr = &oval1; shape_ptr->draw();` → `Oval::draw()`
- `Shape& shape_ref = circle1; shape_ref.draw();` → `Circle::draw()`
- één functie `draw_shape(Shape*)` of `draw_shape(const Shape&)` tekent elke shape correct;
- één array `Shape* shapes[]{&shape1, &oval1, &circle1}` en één range-based for-loop roept telkens de juiste `draw()` aan.

**Beperking:** dynamic binding geldt alleen voor functies die virtual zijn en in de hiërarchie gedeclareerd zijn. Maakt de docent `get_x_rad()` public in `Oval` en probeert hij `shape_ptr->get_x_rad()`, dan faalt de build: *"class Shape has no member named get_x_rad"*. Voor een niet-virtual functie doet de compiler gewoon static binding op het pointertype, en `Shape` kent die functie niet.

[▶ 26:55:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=96945s) · demo [▶ 26:59:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=97186s)

#### De grootte van polymorphic objecten

Dynamic binding is **niet gratis**: je betaalt in geheugen. Een klasse met virtual functions moet informatie bijhouden waarmee het programma at runtime de juiste functie kan kiezen. Die informatie zit in zogenaamde **virtual tables**; de docent gaat daar bewust niet dieper op in ("buiten de scope van deze cursus").

Zijn meting (GCC, 64-bit):

| klasse | met `virtual` (dynamic) | zonder `virtual` (static) |
|---|---|---|
| `Shape` | 40 | 32 |
| `Oval` | 56 | 48 |
| `Circle` | 56 | 48 |

Om te vergelijken zet hij het keyword `virtual` gewoon in commentaar (`/*virtual*/`) in plaats van het te verwijderen, zodat hij het later terug kan aanzetten.

> 💡 Aanvulling: het verschil van 8 bytes is typisch één verborgen pointer per object (de *vptr*) die naar de virtual table van de klasse wijst. Een `std::string` neemt bij libstdc++ 32 bytes in; de exacte getallen zijn compiler- en platformafhankelijk.

[▶ 27:14:20](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98060s) · demo [▶ 27:19:58](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98398s)

#### Object slicing

Wijs je een derived **object** (geen pointer, geen reference) toe aan een base **object**, dan heeft de linkerkant enkel plaats voor het `Shape`-deel:

```c++
Circle circle1(3.3, "Circle1");
Shape shape = circle1;   // compileert: een Circle is een Shape
shape.draw();            // Shape::draw() -- ook al is draw() virtual!
```

De compiler "strip" de buitenste lagen: eerst het `Circle`-deel, dan het `Oval`-deel, en enkel de `Shape`-kern wordt gekopieerd. Dat heet **slicing**. Omdat er geen base pointer of base reference in het spel is, is er ook geen polymorphism: `shape` *is* gewoon een `Shape`. Wie hoopt op dynamic binding zonder pointers of references "wordt teleurgesteld", zegt de docent.

[▶ 27:16:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98205s) · demo [▶ 27:23:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98587s)

#### Polymorphic objecten in collecties

Slicing kan ook **verborgen** gebeuren. Een array `Shape shapes1[]{circle1, oval1, ...}` slaat **kopieën** op, en elke kopie in een plek voor `Shape` wordt gesliced. Een loop `for (Shape& s : shapes1) s.draw();` roept dus overal `Shape::draw()` aan. De docent bewijst het met `sizeof`: `sizeof(circle1)` is 56, maar `sizeof(s)` in de loop is 40. In de debugger zie je bij de array-elementen enkel `m_description`, terwijl `circle1` nog een `Oval`- en `Shape`-deel toont.

Belangrijk: **gesliced is voorgoed weg**. Neem je achteraf een pointer of reference naar zo'n array-element, dan krijg je nog steeds `Shape::draw()`; de derived data is permanent verloren.

Drie varianten:

1. **Array van objecten** → slicing (compileert, maar verkeerd gedrag).
2. **Array van references** (`Shape& shapes2[]{...}`) → compileert niet: *"declaration of 'shapes2' as array of references"*. Reden volgens de docent: elementen van een collectie moeten **left-assignable** zijn (je moet er later iets anders aan kunnen toewijzen), en een reference kan na initialisatie nooit naar iets anders gaan verwijzen. `int a{56}; int& ref{a}; ref = 20;` wijzigt de *waarde* van `a`, niet waar `ref` naar verwijst.
3. **Array van pointers** (raw `Shape*` of smart pointers zoals `std::shared_ptr<Shape>` / `std::unique_ptr<Shape>`, header `<memory>`) → werkt: dit is precies waarvoor polymorphism ontworpen is. Een smart pointer is een wrapper rond een raw pointer, dus ook daarmee krijg je dynamic binding.

[▶ 27:26:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98778s) · demo [▶ 27:33:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=99213s)

#### De override-specifier

Een **override** is een specifiekere versie van een virtual functie in een derived klasse. Een kleine typfout (`void Draw() const` met hoofdletter W in `Oval`) maakt er stilletjes een **nieuwe, aparte functie** van: het compileert zonder fout, maar `Oval` overschrijft `draw()` niet meer, en via een `Shape*` zie je voor ovals weer `Shape::draw()`. Zulke fouten zijn moeilijk te vinden.

Oplossing: zet **`override`** achter de functieheader:

```c++
virtual void draw() const override;
```

Nu controleert de compiler dat er in een base class echt een virtual functie met precies die signatuur bestaat. Zo niet: *"marked 'override', but does not override"*. De docent raadt aan `override` altijd te gebruiken in hiërarchieën met virtual functions.

[▶ 27:45:35](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=99935s) · demo [▶ 27:48:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=100084s)

#### Overloading, overriding en hiding

Stel `Shape` heeft twee **overloads** van een virtual functie: `draw()` en `draw(int color_depth)`.

- Overschrijft geen enkele derived klasse ze, dan erven `Oval` en `Circle` beide en kun je `circle1.draw()` en `circle1.draw(44)` aanroepen (beide lopen in `Shape`).
- Overschrijf je in `Oval` **één** overload (`draw()`), dan worden **alle andere overloads met die naam verborgen** (*hiding*) — in `Oval` en in alle klassen eronder. `circle1.draw(44)` geeft dan een compilerfout. Wil je ze allemaal beschikbaar houden, dan moet je ze **allemaal expliciet overriden**.
- Een **nieuwe** overload die pas in `Oval` verschijnt (bv. `draw(int color_depth, std::string_view color)`) doet **niet mee aan Shape-polymorphism**: via een `Shape*` is ze onbekend, want enkel functies die in de base class gedeclareerd én virtual zijn, doen mee. Wel kan ze meedoen aan "Oval-polymorphism" (zie volgende sectie).
- Bij slicing (derived object toegewezen aan base object) verdwijnen ook de derived overrides en overloads.

> 💡 Aanvulling: met `using Shape::draw;` in de derived klasse haal je de verborgen overloads van de base class weer binnen, zonder ze allemaal opnieuw te moeten schrijven. Dit behandelt de docent hier niet.

[▶ 27:52:04](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=100324s) · demo [▶ 27:58:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=100714s)

#### Polymorphism op verschillende niveaus

Polymorphism hoeft niet altijd via de **top-level** klasse te lopen. De docent gebruikt een nieuwe hiërarchie:

```
                Animal            virtual breathe()
              /        \
          Feline        Bird      Feline: virtual run()   Bird: virtual fly()
          /    \       /    \
        Dog    Cat  Pigeon  Crow
```

- **Animal polymorphism**: een array `Animal*` met een dog, cat, pigeon en crow; `breathe()` roept per object de meest specifieke versie aan (`Dog::breathe`, `Cat::breathe`, ...).
- **Feline polymorphism**: een array `Feline*` met enkel felines (dog, cat); `run()` is pas op `Feline`-niveau gedeclareerd. Een `Pigeon` of zelfs een `Animal` in die array stoppen geeft een compilerfout (*"cannot convert 'Pigeon*' to 'Feline*'"*, *"invalid conversion from 'Animal*' to 'Feline*'"*): een pigeon is geen feline, en een animal is een *parent* van feline die de feline-specialisaties mist.
- **Bird polymorphism**: een array `Bird*` met pigeon en crow, `fly()` aanroepen. Zolang `Pigeon` en `Crow` `fly()` niet overriden, krijg je twee keer `Bird::fly()`; voegt de docent overrides toe, dan zie je `Pigeon::fly()` en `Crow::fly()`.

Onderweg zet de docent de destructors **virtual** ("goede gewoonte zodra je virtual functions hebt"; uitgewerkt in een latere sectie) en past hij constructorparameters aan naar `std::string_view` (geen onnodige kopieën, string literals rechtstreeks doorgeven).

[▶ 28:07:23](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=101243s) · demo [▶ 28:12:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=101533s)

#### Static members bij inheritance en polymorphism

Herhaling (hoofdstuk 17): een **static member** hoort bij het type, niet bij een object. `Shape` heeft een `static int m_count` die in de constructor verhoogd wordt, en een `virtual int get_count() const`. De docent declareert `m_count` niet `inline`, dus de definitie (`int Shape::m_count{0};`) staat apart in het `.cpp`-bestand.

`Ellipse : public Shape` erft die static member. Gevolg:

- Na drie shapes en één ellipse geven `Shape::m_count` **én** `Ellipse::m_count` beide **4**: het is dezelfde variabele.
- Een bug die de docent tegenkomt: zijn `Ellipse`-constructor verhoogde `m_count` ook nog eens, terwijl de `Shape`-constructor (via de initializer list) dat al deed → er werd dubbel geteld (de telling sprong naar 5).

Oplossing: geef `Ellipse` een **eigen** `static int m_count` met dezelfde naam (die verbergt die van `Shape`), verhoog die in de `Ellipse`-constructor, en override `get_count()` om de eigen telling terug te geven. Nu: 4 shapes, 1 ellipse. Met een array `std::shared_ptr<Shape>` erbij (extra ellipses) wordt het 6 shapes en 3 ellipses.

Via **shape polymorphism** (`Shape* shapes[]{&shape1, &ellipse1}` en `s->get_count()`) krijg je per object de juiste telling: voor de shape die van `Shape`, voor de ellipse die van `Ellipse`.

[▶ 28:33:01](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=102781s) · demo [▶ 28:38:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=103121s)

#### De final-specifier

`final` heeft twee toepassingen:

1. **Een virtual functie final maken**: verdere overrides in afgeleide klassen verbieden. `Dog` overschrijft `run()` als `void run() const override final;`; probeert `BullDog` (afgeleid van `Dog`) `run()` opnieuw te overriden, dan: *"virtual function ... overriding final function"*.
2. **Een klasse final maken**: verder erven verbieden. `class Cat final : public Feline`; dan geeft `class WildCat : public Cat` de fout *"cannot derive from 'final' base 'Cat'"*.

Enkele "interessante feiten" die de docent toont:

- Je kunt een klasse meteen bij het aanmaken `final` maken (`class Plane final { ... };`); niemand kan er ooit van erven. (Hij vergat eerst de puntkomma na de klassedefinitie, wat een andere fout gaf.)
- Een **nieuwe virtual functie in een final klasse** (`virtual void miaw() const` in `Cat`) is toegestaan maar nutteloos: niemand kan haar ooit overriden. Het compileert gewoon; de docent hoopt dat een toekomstige standaard dit verbiedt.
- **Overriden in een final klasse** mag wel en is zinvol: `Cat` specialiseert `run()` uit `Feline`.
- `virtual void fly() const final` in één declaratie: tegenstrijdig, maar toegestaan. `final` wint: een override in `Pigeon` geeft een compilerfout.

> 💡 Aanvulling: `override` en `final` zijn *contextuele keywords*; ze hebben enkel een speciale betekenis op die plek en mogen elders als naam gebruikt worden. De volgorde `override final` of `final override` maakt niet uit.

[▶ 28:49:07](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=103747s) · demo [▶ 28:54:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=104080s)

#### Virtual functions met default arguments

Opzet: `Base` heeft `virtual double add(double a = 5, double b = 5) const` die `a + b + 1` teruggeeft; `Derived` overschrijft dit met **andere** defaults, `add(double a = 10, double b = 10) const override`, en geeft `a + b + 2` terug.

De valkuil: **default arguments worden at compile time ingevuld, met static binding**, terwijl de virtual functie at runtime gekozen wordt. De compiler kijkt dus naar het **statische type** (pointer-, reference- of objecttype) om te beslissen welke defaults hij invult:

| aanroep | uitgevoerde body | gebruikte defaults | resultaat |
|---|---|---|---|
| `Base* p = new Derived; p->add()` | `Derived` | `Base` (5, 5) | 5 + 5 + 2 = **12** |
| `Base& r = derived; r.add()` | `Derived` | `Base` (5, 5) | **12** |
| `Base base3; base3.add()` | `Base` | `Base` (5, 5) | 5 + 5 + 1 = **11** |
| `Derived derived; derived.add()` | `Derived` | `Derived` (10, 10) | 10 + 10 + 2 = **22** |
| `Base b = derived; b.add()` (slicing) | `Base` | `Base` (5, 5) | **11** |

De docent toont dat je in VS Code door over de aanroep te hoveren ziet welke defaults de compiler heeft ingevuld. Zijn advies: **vermijd default arguments bij virtual functions**; het maakt code verwarrend voor wie er later aan werkt.

[▶ 29:07:33](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=104853s) · demo [▶ 29:12:21](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=105141s)

#### Virtual destructors

Hiërarchie: `Animal` → `Feline` → `Dog`, elk met een destructor die een melding print.

- Een gewoon object `Dog dog1;` wordt correct opgeruimd in de bekende volgorde: `Dog`-destructor, dan `Feline`, dan `Animal` (van meest specifiek naar meest basis, zie hoofdstuk 18).
- Maar `Animal* p_animal = new Dog; delete p_animal;` met **niet-virtual** destructors roept enkel `~Animal()` aan. De compiler doet static binding op het pointertype. Geheugen dat de `Feline`- of `Dog`-constructor dynamisch reserveerde, lekt dan weg. Erger nog: de C++-standaard noemt dit **undefined behavior** (een derived object deleten via een base pointer zonder virtual destructor), dus het gedrag kan per compiler/OS verschillen.

Oplossing: maak de destructor **virtual** (`virtual ~Animal();`). Dan wordt bij `delete` via een base pointer de meest specifieke destructor gekozen, en die roept in de vertrouwde volgorde de destructors van de base parts aan. Advies van de docent: **zodra een klasse een virtual functie heeft, maak de destructor ook virtual**.

> 💡 Aanvulling: het volstaat de destructor in de base class virtual te maken; destructors van derived klassen zijn dan automatisch virtual (je mag er `override` bij zetten). Met `virtual ~Animal() = default;` hoef je geen lege body te schrijven.

[▶ 29:22:40](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=105760s) · demo [▶ 29:27:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=106049s)

#### dynamic_cast: downcasting at runtime

Via een base pointer/reference kun je enkel **virtual** functies aanroepen die in de base class bekend zijn. Wil je een **niet-polymorphic** functie van een derived klasse aanroepen (bv. `Feline::do_some_feline_thingy()`), dan geeft `animal_ptr->do_some_feline_thingy()` een compilerfout: *"class Animal has no member named ..."*.

`dynamic_cast` zet een base pointer of reference **at runtime** om naar een derived pointer of reference (*downcast*):

```c++
Feline* fel_ptr = dynamic_cast<Feline*>(animal_ptr);   // pointer -> pointer
Feline& fel_ref = dynamic_cast<Feline&>(animal_ref);   // reference -> reference
Feline* fel_ptr2 = dynamic_cast<Feline*>(&animal_ref); // reference -> pointer
```

Tussen de punthaken staat het gewenste type (output), tussen de haakjes de input.

Een cast kan **mislukken**: wijst `animal_ptr` naar een `Feline`, dan heeft dat object geen `Dog`-deel, en `dynamic_cast<Dog*>(animal_ptr)` lukt niet.

- Bij **pointers** krijg je dan `nullptr`. Controleer dus altijd: `if (dog_ptr) { ... } else { std::cout << "Couldn't cast ...\n"; }`. Zonder controle crashte het programma van de docent toen `do_some_dog_thingy()` `m_speed` probeerde te printen.
- Bij **references** bestaat er geen "null reference", dus je kunt niet controleren. De docent ziet het programma eindigen met een `bad_cast`-melding, nog voor "Done" en voordat het geheugen vrijgegeven werd. Daarom geeft hij de voorkeur aan pointers.
- **Beste van beide werelden:** heb je een reference, cast dan het *adres* naar een pointer (`dynamic_cast<Dog*>(&animal_ref)`) en controleer die op `nullptr`.

> 💡 Aanvulling: een mislukte `dynamic_cast` naar een reference gooit een exception van het type `std::bad_cast` (header `<typeinfo>`); wordt die niet opgevangen, dan roept het programma `std::terminate` aan. Een mislukte pointer-cast geeft precies `nullptr` (geen "rommel", zoals in de opname even gesuggereerd wordt); de crash komt doordat je via een null pointer een member probeert te lezen.

Typisch gebruik: in een functie die een `Animal*` of `const Animal&` als parameter krijgt en toch een niet-virtual functie van een derived klasse moet aanroepen.

**Waarschuwing van de docent:** veel downcasting is een teken van **slecht ontwerp**. Als je het vaak nodig hebt, maak de functie dan beter virtual.

**Beperking:** `dynamic_cast` werkt enkel tussen pointers/references binnen dezelfde **polymorphic** hiërarchie (met minstens één virtual functie). `dynamic_cast<std::string>(data)` met een `int`, of `dynamic_cast<std::string*>(&data)`, geven een compilerfout (*"cannot dynamic_cast ..."*).

Tussendoor merkt de docent op dat hij een `delete` vergeten was voor een met `new` gemaakt object ("goede leerervaring"): met virtual destructors zie je bij het opruimen per niveau een destructor-melding.

[▶ 29:35:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=106536s) · demo [▶ 29:44:31](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=107071s)

#### Nooit virtual functions aanroepen vanuit constructors of destructors

De waarschuwing van de docent, nadrukkelijk herhaald: **roep nooit virtual (polymorphic) functies aan vanuit een constructor of destructor**.

Opzet: `Base` met `protected` member `m_value`, `virtual void setup()` (zet `m_value` op 10), `virtual void clean_up()` en `get_value()`. De `Base`-constructor roept `setup()` aan, de `Base`-destructor `clean_up()`. `Derived` overschrijft `setup()` (zet `m_value` op 100) en `clean_up()`, en heeft een virtual destructor.

Bij `Base* p_base = new Derived;` gebeurt het volgende:

- **Constructie** gaat van binnen naar buiten: eerst wordt het `Base`-deel gebouwd, dan het `Derived`-deel. Tijdens de `Base`-constructor **bestaat het `Derived`-deel nog niet**, dus er is geen meer specifieke versie om naar te springen: `Base::setup()` wordt aangeroepen en de waarde is 10, niet 100.
- **Destructie** gaat omgekeerd: eerst wordt het `Derived`-deel afgebroken, dan het `Base`-deel. In de `Base`-destructor is het `Derived`-deel **al weg**, dus `Base::clean_up()` wordt aangeroepen.

Samengevat: een aanroep vanuit een constructor of destructor gaat nooit naar een klasse die "meer derived" is dan de constructor/destructor die op dat moment loopt; je krijgt **static-binding-resultaten**.

Tijdens de demo vergeet de docent eerst `delete p_base;`, waardoor er helemaal geen destructor-melding verschijnt. Hij merkt ook een "junk"-waarde op, omdat `m_value` niet geïnitialiseerd was.

**Oplossing:** roep `setup()` aan op het object **nadat** het volledig geconstrueerd is (`p_base->setup();`) en `clean_up()` **voordat** je het verwijdert (`p_base->clean_up(); delete p_base;`). Dan werkt dynamic binding normaal en krijg je 100 en `Derived::clean_up()`.

[▶ 30:07:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=108458s) · demo [▶ 30:14:48](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=108888s)

> ⚠️ Onduidelijk in opname: aan het einde van deze les kondigt de docent een les over de `typeid`-operator aan, en in de volgende les verwijst hij ernaar ("we learned about that in the last lecture"). Die les zelf zit niet in dit fragment van het transcript; `typeid` komt hieronder enkel voor zoals de docent het in de demo over abstracte klassen gebruikt.

#### Pure virtual functions en abstract classes

Een `Shape` is een **abstract** idee: zonder te weten of het een cirkel of rechthoek is, kun je de omtrek of oppervlakte niet berekenen. Het is dus logisch om `perimeter()` en `surface()` in `Shape` enkel te **declareren** en de implementatie aan de derived klassen (`Circle`, `Rectangle`) over te laten, die wel de concrete gegevens hebben.

Dat doe je met een **pure virtual function**: zet `= 0` achter de declaratie.

```c++
class Shape {
public:
    virtual double perimeter() const = 0;   // pure virtual
    virtual double surface() const = 0;
};
```

Gevolgen:

- Een klasse met **minstens één** pure virtual functie wordt een **abstract class**: je kunt er **geen objecten** van maken. `new Shape` geeft *"invalid new expression of abstract class type 'Shape'"* (VS Code: *"object of abstract class type 'Shape' is not allowed"*), met als noot welke functies pure zijn.
- Je kunt wél een `Shape*` of `Shape&` gebruiken om derived objecten te beheren: `Shape* shape_rect = new Rectangle(10, 10, "rect1"); shape_rect->surface();` geeft 100.
- De docent print met `typeid(*shape_rect).name()` het **dynamic type** van het beheerde object (header `<typeinfo>`): eerst rectangle, daarna circle.
- Een **derived klasse moet alle** pure virtual functions overriden. Vergeet je er één (in de demo `Circle::surface()` in commentaar), dan is ook die klasse abstract: *"invalid new expression of abstract class type 'Circle'"*. Dat is verwarrend voor beginners, want je hebt zelf geen enkele `= 0` geschreven.
- Een definitie *in de klasse* combineren met `= 0` geeft de fout *"pure-specifier on function-definition"*.
- De constructor van een abstracte klasse wordt enkel door derived klassen gebruikt om het base part te bouwen; vanuit die constructor mag je de pure virtual functies niet aanroepen.

> 💡 Aanvulling: een pure virtual functie *mag* technisch toch een definitie hebben, maar dan buiten de klasse (`double Shape::surface() const { ... }`); de klasse blijft abstract. Een pure virtual rechtstreeks vanuit de constructor aanroepen geeft bij GCC een waarschuwing en meestal een linkerfout (of runtime "pure virtual method called"), afhankelijk van hoe de aanroep gebeurt.

[▶ 30:24:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=109462s) · demo [▶ 30:31:41](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=109901s)

#### Abstract classes als interfaces

Een **interface** is in C++ een abstracte klasse met **enkel pure virtual functions en geen member variables** (helperfuncties zoals een friend-operator mogen erbij). Heeft ze een member variable, dan is het geen interface meer.

Je kunt een interface zien als:

- een **specificatie** die in de derived klasse volledig geïmplementeerd wordt;
- iets dat je aan je types **vastmaakt** om ze "superkrachten" te geven.

Voorbeeld van de docent: `StreamInsertable`, met als enige taak objecten printbaar maken met `std::cout <<`.

```c++
class StreamInsertable {
    friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);
public:
    virtual void stream_insert(std::ostream& out) const = 0;
};

std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand) {
    operand.stream_insert(out);   // polymorphic call via reference
    return out;                   // maakt chaining mogelijk
}
```

**Hoe werkt het?** Je "hangt" de interface aan een type door ervan te **erven**: `class Point : public StreamInsertable`. `Point` moet dan `stream_insert()` overriden (anders is `Point` abstract en geeft `Point p1(10, 20);` een compilerfout). De interface neemt de taak "printen naar een stream" over; de derived klasse bepaalt in `stream_insert()` **wat** en **hoe** er geprint wordt (bv. `Point [x : 10, y : 20]`). Omdat de `operator<<` zijn tweede operand **by reference** krijgt, wordt `stream_insert()` met dynamic binding opgelost. `std::cout << p1` is in feite `operator<<(std::cout, p1)`.

Je hoeft dus **geen** `operator<<` meer in `Point` te overloaden.

**Hele hiërarchie:** laat de base class `Animal` erven van `StreamInsertable`, dan erven alle animals mee. Elke klasse in de hiërarchie overschrijft `stream_insert()` met haar eigen formaat (Dog print "Dog", fur style, ...; Bird print beschrijving en wing color). Je kunt dan via `std::unique_ptr<Animal>` of een array `std::shared_ptr<Animal>` een dog, cat, crow en pigeon polymorphisch printen in één loop.

> 💡 Aanvulling: een interface hoort normaal ook een `virtual` destructor te hebben (bv. `virtual ~StreamInsertable() = default;`), zodat je objecten veilig kunt verwijderen via een pointer naar de interface.

[▶ 30:43:45](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=110625s) · demo [▶ 30:52:36](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=111156s)

### Codevoorbeelden

#### Static binding met base pointers en references [▶ 26:38:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=95893s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Shape {
public:
    Shape() = default;
    Shape(std::string_view description) : m_description(description) {}
    void draw() const {   // NIET virtual -> static binding
        std::cout << "Shape::draw() called. Drawing " << m_description << '\n';
    }
protected:
    std::string m_description{""};
};

class Oval : public Shape {
public:
    Oval() = default;
    Oval(double x_radius, double y_radius, std::string_view description)
        : Shape(description), m_x_radius(x_radius), m_y_radius(y_radius) {}
    void draw() const {
        std::cout << "Oval::draw() called. Drawing " << m_description
                  << " with m_x_radius : " << m_x_radius
                  << " and m_y_radius : " << m_y_radius << '\n';
    }
protected:
    double get_x_rad() const { return m_x_radius; }
    double get_y_rad() const { return m_y_radius; }
private:
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};

class Circle : public Oval {
public:
    Circle() = default;
    Circle(double radius, std::string_view description)
        : Oval(radius, radius, description) {}   // x- en y-radius gelijk
    void draw() const {
        std::cout << "Circle::draw() called. Drawing " << m_description
                  << " with radius : " << get_x_rad() << '\n';
    }
};

// Zonder polymorphism: één functie per type nodig
void draw_circle(const Circle& c) { c.draw(); }
void draw_oval(const Oval& o) { o.draw(); }

int main() {
    Shape shape1("Shape1");
    Oval oval1(2.0, 3.5, "Oval1");
    Circle circle1(3.3, "Circle1");

    std::cout << "--- rechtstreeks via objecten ---\n";
    shape1.draw();
    oval1.draw();
    circle1.draw();

    std::cout << "--- via base pointer ---\n";
    Shape* shape_ptr = &shape1;
    shape_ptr->draw();
    shape_ptr = &oval1;      // Oval is een Shape: toegestaan
    shape_ptr->draw();       // toch Shape::draw(): type van de pointer beslist
    shape_ptr = &circle1;
    shape_ptr->draw();

    std::cout << "--- via base reference ---\n";
    Shape& shape_ref = circle1;
    shape_ref.draw();        // ook hier Shape::draw()

    std::cout << "--- aparte functies (slecht ontwerp) ---\n";
    draw_circle(circle1);
    draw_oval(oval1);
}
```

```text
--- rechtstreeks via objecten ---
Shape::draw() called. Drawing Shape1
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
Circle::draw() called. Drawing Circle1 with radius : 3.3
--- via base pointer ---
Shape::draw() called. Drawing Shape1
Shape::draw() called. Drawing Oval1
Shape::draw() called. Drawing Circle1
--- via base reference ---
Shape::draw() called. Drawing Circle1
--- aparte functies (slecht ontwerp) ---
Circle::draw() called. Drawing Circle1 with radius : 3.3
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
```

#### Dynamic binding met virtual: één functie, één collectie [▶ 26:59:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=97186s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Shape {
public:
    Shape() = default;
    Shape(std::string_view description) : m_description(description) {}
    virtual void draw() const {   // virtual -> dynamic binding
        std::cout << "Shape::draw() called. Drawing " << m_description << '\n';
    }
protected:
    std::string m_description{""};
};

class Oval : public Shape {
public:
    Oval() = default;
    Oval(double x_radius, double y_radius, std::string_view description)
        : Shape(description), m_x_radius(x_radius), m_y_radius(y_radius) {}
    virtual void draw() const {
        std::cout << "Oval::draw() called. Drawing " << m_description
                  << " with m_x_radius : " << m_x_radius
                  << " and m_y_radius : " << m_y_radius << '\n';
    }
protected:
    double get_x_rad() const { return m_x_radius; }
    double get_y_rad() const { return m_y_radius; }
private:
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};

class Circle : public Oval {
public:
    Circle() = default;
    Circle(double radius, std::string_view description)
        : Oval(radius, radius, description) {}
    virtual void draw() const {
        std::cout << "Circle::draw() called. Drawing " << m_description
                  << " with radius : " << get_x_rad() << '\n';
    }
};

// Eén functie voor alle shapes (pointer-versie)
void draw_shape(const Shape* s) { s->draw(); }
// ... en de reference-versie
void draw_shape_v1(const Shape& sr) { sr.draw(); }

int main() {
    Shape shape1("Shape1");
    Oval oval1(2.0, 3.5, "Oval1");
    Circle circle1(3.3, "Circle1");

    std::cout << "--- base pointer ---\n";
    Shape* shape_ptr = &oval1;
    shape_ptr->draw();           // Oval::draw(): type van het object beslist
    shape_ptr = &circle1;
    shape_ptr->draw();

    std::cout << "--- base reference ---\n";
    Shape& shape_ref = oval1;
    shape_ref.draw();

    std::cout << "--- een functie ---\n";
    draw_shape(&shape1);
    draw_shape(&oval1);
    draw_shape_v1(circle1);

    std::cout << "--- een collectie ---\n";
    Shape* shapes[]{&shape1, &oval1, &circle1};
    for (Shape* s : shapes) {
        s->draw();
    }
}
```

```text
--- base pointer ---
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
Circle::draw() called. Drawing Circle1 with radius : 3.3
--- base reference ---
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
--- een functie ---
Shape::draw() called. Drawing Shape1
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
Circle::draw() called. Drawing Circle1 with radius : 3.3
--- een collectie ---
Shape::draw() called. Drawing Shape1
Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
Circle::draw() called. Drawing Circle1 with radius : 3.3
```

#### Niet-virtual functie via base pointer: compilerfout [▶ 27:09:28](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=97768s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: get_x_rad() bestaat niet in Shape -> "class Shape has no member named get_x_rad"
#include <iostream>

class Shape {
public:
    virtual void draw() const { std::cout << "Shape::draw()\n"; }
};

class Oval : public Shape {
public:
    virtual void draw() const { std::cout << "Oval::draw()\n"; }
    double get_x_rad() const { return m_x_radius; }   // public, maar niet in Shape
private:
    double m_x_radius{2.0};
};

int main() {
    Oval oval1;
    Shape* shape_ptr = &oval1;
    shape_ptr->draw();        // OK: virtual, dynamic binding
    shape_ptr->get_x_rad();   // FOUT: static binding op type Shape
}
```

#### sizeof met en zonder virtual, en slicing [▶ 27:20:46](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=98446s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

De getallen gelden voor GCC op 64-bit (zoals in de opname); `ShapeS`/`OvalS`/`CircleS` zijn de varianten waarin `virtual` in commentaar staat.

```cpp
#include <iostream>
#include <string>
#include <string_view>

// --- dynamic binding (virtual) ---
class Shape {
public:
    Shape(std::string_view d) : m_description(d) {}
    virtual void draw() const { std::cout << "Shape::draw() called. Drawing " << m_description << '\n'; }
protected:
    std::string m_description;
};
class Oval : public Shape {
public:
    Oval(double x, double y, std::string_view d) : Shape(d), m_x_radius(x), m_y_radius(y) {}
    virtual void draw() const { std::cout << "Oval::draw() called. Drawing " << m_description << '\n'; }
private:
    double m_x_radius, m_y_radius;
};
class Circle : public Oval {
public:
    Circle(double r, std::string_view d) : Oval(r, r, d) {}
    virtual void draw() const { std::cout << "Circle::draw() called. Drawing " << m_description << '\n'; }
};

// --- static binding (virtual in commentaar) ---
class ShapeS {
public:
    ShapeS(std::string_view d) : m_description(d) {}
    /*virtual*/ void draw() const {}
protected:
    std::string m_description;
};
class OvalS : public ShapeS {
public:
    OvalS(double x, double y, std::string_view d) : ShapeS(d), m_x_radius(x), m_y_radius(y) {}
    /*virtual*/ void draw() const {}
private:
    double m_x_radius, m_y_radius;
};
class CircleS : public OvalS {
public:
    CircleS(double r, std::string_view d) : OvalS(r, r, d) {}
    /*virtual*/ void draw() const {}
};

int main() {
    std::cout << "sizeof(Shape)  dynamic : " << sizeof(Shape) << '\n';
    std::cout << "sizeof(Oval)   dynamic : " << sizeof(Oval) << '\n';
    std::cout << "sizeof(Circle) dynamic : " << sizeof(Circle) << '\n';
    std::cout << "sizeof(Shape)  static  : " << sizeof(ShapeS) << '\n';
    std::cout << "sizeof(Oval)   static  : " << sizeof(OvalS) << '\n';
    std::cout << "sizeof(Circle) static  : " << sizeof(CircleS) << '\n';

    // Slicing: derived object -> base object
    Circle circle1(3.3, "Circle1");
    Shape shape = circle1;   // Circle- en Oval-deel worden afgesneden
    shape.draw();            // Shape::draw(), geen polymorphism zonder pointer/reference
}
```

```text
sizeof(Shape)  dynamic : 40
sizeof(Oval)   dynamic : 56
sizeof(Circle) dynamic : 56
sizeof(Shape)  static  : 32
sizeof(Oval)   static  : 48
sizeof(Circle) static  : 48
Shape::draw() called. Drawing Circle1
```

#### Polymorphic objecten in een array: objecten, pointers, smart pointers [▶ 27:34:22](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=99262s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class Shape {
public:
    Shape(std::string_view d) : m_description(d) {}
    virtual void draw() const { std::cout << "Shape::draw() called. Drawing " << m_description << '\n'; }
protected:
    std::string m_description;
};
class Oval : public Shape {
public:
    Oval(double x, double y, std::string_view d) : Shape(d), m_x_radius(x), m_y_radius(y) {}
    virtual void draw() const { std::cout << "Oval::draw() called. Drawing " << m_description << '\n'; }
private:
    double m_x_radius, m_y_radius;
};
class Circle : public Oval {
public:
    Circle(double r, std::string_view d) : Oval(r, r, d) {}
    virtual void draw() const { std::cout << "Circle::draw() called. Drawing " << m_description << '\n'; }
};

int main() {
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");

    std::cout << "sizeof(circle1) : " << sizeof(circle1) << '\n';

    // 1. Array van objecten: kopieën -> slicing
    Shape shapes1[]{circle1, oval1, circle2};
    for (Shape& s : shapes1) {             // reference: geen extra kopie in de loop
        std::cout << "sizeof(object) : " << sizeof(s) << " -> ";
        s.draw();                          // altijd Shape::draw()
    }

    // 2. Array van references: compileert NIET
    // Shape& shapes2[]{circle1, oval1, circle2};   // error: array of references

    // 3. Array van raw pointers: polymorphism werkt
    std::cout << "--- raw pointers ---\n";
    Shape* shapes3[]{&circle1, &oval1, &circle2};
    for (Shape* s : shapes3) {
        s->draw();
    }

    // 4. Array van smart pointers: werkt ook
    std::cout << "--- shared_ptr ---\n";
    std::shared_ptr<Shape> shapes4[]{
        std::make_shared<Circle>(12.2, "Circle4"),
        std::make_shared<Oval>(10.0, 20.0, "Oval4")};
    for (auto& s : shapes4) {
        s->draw();
    }
}
```

```text
sizeof(circle1) : 56
sizeof(object) : 40 -> Shape::draw() called. Drawing circle1
sizeof(object) : 40 -> Shape::draw() called. Drawing Oval1
sizeof(object) : 40 -> Shape::draw() called. Drawing circle2
--- raw pointers ---
Circle::draw() called. Drawing circle1
Oval::draw() called. Drawing Oval1
Circle::draw() called. Drawing circle2
--- shared_ptr ---
Circle::draw() called. Drawing Circle4
Oval::draw() called. Drawing Oval4
```

#### Array van references: compilerfout [▶ 27:41:38](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=99698s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: references zijn niet left-assignable -> "declaration of 'shapes2' as array of references"
#include <iostream>

struct Shape { virtual void draw() const { std::cout << "Shape\n"; } };
struct Circle : Shape { void draw() const override { std::cout << "Circle\n"; } };

int main() {
    Circle c1, c2;
    Shape& shapes2[]{c1, c2};   // FOUT
}
```

#### Typfout zonder en met override [▶ 27:48:52](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=100132s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

Eerst de verraderlijke versie: `Draw` met hoofdletter compileert gewoon, maar ovals worden als shape getekend.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Shape {
public:
    Shape(std::string_view d) : m_description(d) {}
    virtual void draw() const { std::cout << "Shape::draw() called. Drawing " << m_description << '\n'; }
protected:
    std::string m_description;
};
class Oval : public Shape {
public:
    Oval(double x, double y, std::string_view d) : Shape(d), m_x_radius(x), m_y_radius(y) {}
    virtual void Draw() const {   // typfout: nieuwe functie, GEEN override van draw()
        std::cout << "Oval::draw() called. Drawing " << m_description << '\n';
    }
private:
    double m_x_radius, m_y_radius;
};
class Circle : public Oval {
public:
    Circle(double r, std::string_view d) : Oval(r, r, d) {}
    virtual void draw() const override {   // override: compiler controleert
        std::cout << "Circle::draw() called. Drawing " << m_description << '\n';
    }
};

int main() {
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Shape* shapes[]{&circle1, &oval1};
    for (Shape* s : shapes) {
        s->draw();
    }
}
```

```text
Circle::draw() called. Drawing circle1
Shape::draw() called. Drawing Oval1
```

Met `override` vangt de compiler de typfout:

```cpp
// ❌ bewust fout: "virtual void Oval::Draw() const marked 'override', but does not override"
#include <iostream>

class Shape {
public:
    virtual void draw() const { std::cout << "Shape::draw()\n"; }
};
class Oval : public Shape {
public:
    virtual void Draw() const override { std::cout << "Oval::draw()\n"; }   // FOUT
};

int main() {
    Oval oval1;
    oval1.draw();
}
```

#### Overloads van een virtual functie en hiding [▶ 27:58:34](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=100714s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

Situatie 1: `Shape` heeft twee overloads, `Oval` en `Circle` overschrijven niets → beide overloads zijn bruikbaar.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Shape {
public:
    Shape(std::string_view d) : m_description(d) {}
    virtual void draw() const {
        std::cout << "Shape::draw() called. Drawing " << m_description << '\n';
    }
    virtual void draw(int color_depth) const {   // overload
        std::cout << "Shape::draw(int) called. Drawing with color depth : " << color_depth << '\n';
    }
protected:
    std::string m_description;
};
class Oval : public Shape {
public:
    Oval(double x, double y, std::string_view d) : Shape(d), m_x_radius(x), m_y_radius(y) {}
    // geen overrides: beide draw-overloads worden geërfd
private:
    double m_x_radius, m_y_radius;
};
class Circle : public Oval {
public:
    Circle(double r, std::string_view d) : Oval(r, r, d) {}
};

int main() {
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    oval1.draw();
    oval1.draw(54);
    circle1.draw();
    circle1.draw(44);
}
```

```text
Shape::draw() called. Drawing Oval1
Shape::draw(int) called. Drawing with color depth : 54
Shape::draw() called. Drawing circle1
Shape::draw(int) called. Drawing with color depth : 44
```

Situatie 2: `Oval` overschrijft enkel `draw()` → `draw(int)` is verborgen voor `Oval` en `Circle`.

```cpp
// ❌ bewust fout: Oval::draw() verbergt Shape::draw(int) -> "no matching function for call to 'Circle::draw(int)'"
#include <iostream>

class Shape {
public:
    virtual void draw() const { std::cout << "Shape::draw()\n"; }
    virtual void draw(int color_depth) const { std::cout << "Shape::draw(int) " << color_depth << '\n'; }
};
class Oval : public Shape {
public:
    void draw() const override { std::cout << "Oval::draw()\n"; }   // verbergt ALLE andere draw-overloads
};
class Circle : public Oval {};

int main() {
    Circle circle1;
    circle1.draw();     // OK
    circle1.draw(44);   // FOUT: verborgen
}
```

Situatie 3: alle overloads expliciet overriden, plus een extra overload pas op `Oval`-niveau. Die laatste is via `Shape*` onbekend, maar wel bruikbaar via een `Oval`-object.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Shape {
public:
    Shape(std::string_view d) : m_description(d) {}
    virtual void draw() const { std::cout << "Shape::draw() called\n"; }
    virtual void draw(int color_depth) const {
        std::cout << "Shape::draw(int) called, color depth : " << color_depth << '\n';
    }
protected:
    std::string m_description;
};
class Oval : public Shape {
public:
    Oval(double x, double y, std::string_view d) : Shape(d), m_x_radius(x), m_y_radius(y) {}
    void draw() const override { std::cout << "Oval::draw() called. Drawing " << m_description << '\n'; }
    void draw(int color_depth) const override {
        std::cout << "Oval::draw(int) called. Drawing with color depth : " << color_depth << '\n';
    }
    // nieuwe overload, enkel bekend vanaf Oval
    virtual void draw(int color_depth, std::string_view color) const {
        std::cout << "Oval::draw(int, color) called. Color depth : " << color_depth
                  << ", color : " << color << '\n';
    }
private:
    double m_x_radius, m_y_radius;
};
class Circle : public Oval {
public:
    Circle(double r, std::string_view d) : Oval(r, r, d) {}
    void draw() const override { std::cout << "Circle::draw() called. Drawing " << m_description << '\n'; }
    void draw(int color_depth) const override {
        std::cout << "Circle::draw(int) called. Drawing with color depth : " << color_depth << '\n';
    }
};

int main() {
    Circle circle1(10, "Circle1");
    Shape* shape_ptr = &circle1;
    shape_ptr->draw();
    shape_ptr->draw(44);
    // shape_ptr->draw(45, "red");   // FOUT: Shape kent deze overload niet

    Oval* oval_ptr = &circle1;     // via Oval-pointer is ze wel zichtbaar
    oval_ptr->draw(45, "red");     // Circle overschrijft hem niet -> Oval-versie
}
```

```text
Circle::draw() called. Drawing Circle1
Circle::draw(int) called. Drawing with color depth : 44
Oval::draw(int, color) called. Color depth : 45, color : red
```

#### Animal-, Feline- en Bird-polymorphism [▶ 28:21:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=102110s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view description) : m_description(description) {}
    virtual ~Animal() = default;   // virtual destructor: goede gewoonte
    virtual void breathe() const {
        std::cout << "Animal::breathe called for : " << m_description << '\n';
    }
protected:
    std::string m_description;
};

class Feline : public Animal {
public:
    Feline(std::string_view fur_style, std::string_view description)
        : Animal(description), m_fur_style(fur_style) {}
    virtual void run() const {   // pas vanaf Feline
        std::cout << "Feline " << m_description << " is running\n";
    }
protected:
    std::string m_fur_style;
};

class Dog : public Feline {
public:
    Dog(std::string_view fur_style, std::string_view description) : Feline(fur_style, description) {}
    void breathe() const override { std::cout << "Dog::breathe called for : " << m_description << '\n'; }
    void run() const override { std::cout << "Dog " << m_description << " is running\n"; }
};

class Cat : public Feline {
public:
    Cat(std::string_view fur_style, std::string_view description) : Feline(fur_style, description) {}
    void breathe() const override { std::cout << "Cat::breathe called for : " << m_description << '\n'; }
    void run() const override { std::cout << "Cat " << m_description << " is running\n"; }
};

class Bird : public Animal {
public:
    Bird(std::string_view wing_color, std::string_view description)
        : Animal(description), m_wing_color(wing_color) {}
    virtual void fly() const {   // pas vanaf Bird
        std::cout << "Bird " << m_description << " is flying\n";
    }
protected:
    std::string m_wing_color;
};

class Pigeon : public Bird {
public:
    Pigeon(std::string_view wing_color, std::string_view description) : Bird(wing_color, description) {}
    void breathe() const override { std::cout << "Pigeon::breathe called for : " << m_description << '\n'; }
    void fly() const override { std::cout << "Pigeon " << m_description << " is flying\n"; }
};

class Crow : public Bird {
public:
    Crow(std::string_view wing_color, std::string_view description) : Bird(wing_color, description) {}
    void breathe() const override { std::cout << "Crow::breathe called for : " << m_description << '\n'; }
    void fly() const override { std::cout << "Crow " << m_description << " is flying\n"; }
};

int main() {
    Dog dog1("dark gray", "dog1");
    Cat cat1("black stripes", "cat1");
    Pigeon pigeon1("white", "pigeon1");
    Crow crow1("black", "crow1");

    std::cout << "--- Animal polymorphism ---\n";
    Animal* animals[]{&dog1, &cat1, &pigeon1, &crow1};
    for (const auto& a : animals) a->breathe();

    std::cout << "--- Feline polymorphism ---\n";
    Feline* felines[]{&dog1, &cat1};   // &pigeon1 zou een compilerfout geven
    for (const auto& f : felines) f->run();

    std::cout << "--- Bird polymorphism ---\n";
    Bird* birds[]{&pigeon1, &crow1};
    for (const auto& b : birds) b->fly();
}
```

```text
--- Animal polymorphism ---
Dog::breathe called for : dog1
Cat::breathe called for : cat1
Pigeon::breathe called for : pigeon1
Crow::breathe called for : crow1
--- Feline polymorphism ---
Dog dog1 is running
Cat cat1 is running
--- Bird polymorphism ---
Pigeon pigeon1 is flying
Crow crow1 is flying
```

#### Een niet-feline in een Feline-array: compilerfout [▶ 28:25:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=102300s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: "cannot convert 'Pigeon*' to 'Feline*'" en "invalid conversion from 'Animal*' to 'Feline*'"
#include <iostream>

struct Animal { virtual ~Animal() = default; virtual void breathe() const {} };
struct Feline : Animal { virtual void run() const { std::cout << "run\n"; } };
struct Dog : Feline {};
struct Bird : Animal {};
struct Pigeon : Bird {};

int main() {
    Dog dog1;
    Pigeon pigeon1;
    Animal animal1;
    Feline* felines[]{&dog1, &pigeon1, &animal1};   // FOUT: geen felines
}
```

#### Static members: gedeelde en eigen telling [▶ 28:40:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=103218s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class Shape {
public:
    Shape() = default;
    Shape(std::string_view description) : m_description(description) { ++m_count; }
    virtual ~Shape() = default;
    virtual int get_count() const { return m_count; }
    static int m_count;   // declaratie (niet inline)
protected:
    std::string m_description;
};
int Shape::m_count{0};    // definitie

class Ellipse : public Shape {
public:
    Ellipse() = default;
    Ellipse(double x_radius, double y_radius, std::string_view description)
        : Shape(description), m_x_radius(x_radius), m_y_radius(y_radius) {
        ++m_count;   // verhoogt Ellipse::m_count (Shape-constructor deed Shape::m_count al)
    }
    int get_count() const override { return m_count; }
    static int m_count;   // eigen static member, verbergt Shape::m_count
private:
    double m_x_radius{};
    double m_y_radius{};
};
int Ellipse::m_count{0};

int main() {
    Shape shape1("shape1");
    std::cout << "shape count : " << Shape::m_count << '\n';
    Shape shape2("shape2");
    std::cout << "shape count : " << Shape::m_count << '\n';
    Shape shape3("shape3");
    std::cout << "shape count : " << Shape::m_count << '\n';

    Ellipse ellipse1(10, 12, "ellipse1");
    std::cout << "shape count : " << Shape::m_count << '\n';
    std::cout << "ellipse count : " << Ellipse::m_count << '\n';

    std::shared_ptr<Shape> shapes[]{std::make_shared<Ellipse>(10, 20, "ellipse2"),
                                    std::make_shared<Ellipse>(30, 40, "ellipse3")};
    std::cout << "shape count : " << Shape::m_count << '\n';
    std::cout << "ellipse count : " << Ellipse::m_count << '\n';

    std::cout << "--- shape polymorphism ---\n";
    Shape* shape_ptrs[]{&shape1, &ellipse1};
    for (auto& s : shape_ptrs) {
        std::cout << "count : " << s->get_count() << '\n';
    }
}
```

```text
shape count : 1
shape count : 2
shape count : 3
shape count : 4
ellipse count : 1
shape count : 6
ellipse count : 3
--- shape polymorphism ---
count : 6
count : 3
```

Zonder de eigen `static int m_count` in `Ellipse` (en zonder `++m_count` in de `Ellipse`-constructor) zou de regel "ellipse count" gewoon dezelfde waarde als "shape count" tonen, omdat `Ellipse::m_count` dan naar de geërfde `Shape::m_count` verwijst.

#### final op een virtual functie en op een klasse [▶ 28:55:29](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=104129s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view description) : m_description(description) {}
    virtual ~Animal() = default;
    virtual void breathe() const { std::cout << "Animal::breathe : " << m_description << '\n'; }
protected:
    std::string m_description;
};

class Feline : public Animal {
public:
    Feline(std::string_view description) : Animal(description) {}
    virtual void run() const { std::cout << "Feline::run : " << m_description << '\n'; }
};

class Dog : public Feline {
public:
    Dog(std::string_view description) : Feline(description) {}
    void run() const override final {   // geen verdere overrides toegestaan
        std::cout << "Dog::run : " << m_description << '\n';
    }
};

class BullDog : public Dog {
public:
    BullDog(std::string_view description) : Dog(description) {}
    // void run() const override {}   // FOUT: overriding final function
};

class Cat final : public Feline {   // van Cat kan niet meer geërfd worden
public:
    Cat(std::string_view description) : Feline(description) {}
    void run() const override { std::cout << "Cat::run : " << m_description << '\n'; }  // override in final klasse: OK
    virtual void miaw() const { std::cout << "Cat::miaw\n"; }  // nieuwe virtual in final klasse: toegestaan, nutteloos
};

class Bird : public Animal {
public:
    Bird(std::string_view description) : Animal(description) {}
    virtual void fly() const final { std::cout << "Bird::fly : " << m_description << '\n'; }  // virtual + final
};

class Pigeon : public Bird {
public:
    Pigeon(std::string_view description) : Bird(description) {}
    // void fly() const override {}   // FOUT: Bird::fly is final
};

class Plane final {   // meteen final
public:
    void fly() const { std::cout << "Plane::fly\n"; }
};

int main() {
    BullDog bull("bull1");
    Feline* f = &bull;
    f->run();          // Dog::run, want BullDog kan run() niet overriden

    Cat cat1("cat1");
    f = &cat1;
    f->run();
    cat1.miaw();

    Pigeon pigeon1("pigeon1");
    pigeon1.fly();

    Plane plane1;
    plane1.fly();
}
```

```text
Dog::run : bull1
Cat::run : cat1
Cat::miaw
Bird::fly : pigeon1
Plane::fly
```

#### Overtredingen van final: compilerfouten [▶ 28:57:51](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=104271s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: "overriding final function 'virtual void Dog::run() const'" en "cannot derive from 'final' base 'Cat'"
#include <iostream>

struct Feline { virtual ~Feline() = default; virtual void run() const {} };
struct Dog : Feline { void run() const override final {} };
struct BullDog : Dog { void run() const override {} };   // FOUT 1
struct Cat final : Feline {};
struct WildCat : Cat {};                                 // FOUT 2

int main() {
    std::cout << "Hello\n";
}
```

#### Default arguments: static binding op de defaults [▶ 29:13:56](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=105236s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

class Base {
public:
    virtual ~Base() = default;
    virtual double add(double a = 5, double b = 5) const {
        std::cout << "Base::add() called\n";
        return a + b + 1;
    }
};

class Derived : public Base {
public:
    double add(double a = 10, double b = 10) const override {   // andere defaults!
        std::cout << "Derived::add() called\n";
        return a + b + 2;
    }
};

int main() {
    Base* base_ptr1 = new Derived;
    double result = base_ptr1->add();   // body Derived, defaults Base (5,5)
    std::cout << "Result (base ptr) : " << result << '\n';

    std::cout << "------\n";
    Derived derived1;
    Base& base_ref1 = derived1;
    result = base_ref1.add();           // idem via reference
    std::cout << "Result (base ref) : " << result << '\n';

    std::cout << "------\n";
    Base base3;
    result = base3.add();               // alles Base
    std::cout << "Result (raw base) : " << result << '\n';

    std::cout << "------\n";
    Derived derived2;
    result = derived2.add();            // alles Derived (10,10)
    std::cout << "Result (raw derived) : " << result << '\n';

    std::cout << "------\n";
    Base base4 = derived2;              // slicing
    result = base4.add();
    std::cout << "Result (sliced) : " << result << '\n';

    delete base_ptr1;
}
```

```text
Derived::add() called
Result (base ptr) : 12
------
Derived::add() called
Result (base ref) : 12
------
Base::add() called
Result (raw base) : 11
------
Derived::add() called
Result (raw derived) : 22
------
Base::add() called
Result (sliced) : 11
```

#### Zonder virtual destructor: enkel ~Animal() [▶ 29:28:18](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=106098s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

Dit programma deletet een `Dog` via een `Animal*` zonder virtual destructor: undefined behavior volgens de standaard (in de opname werd enkel de `Animal`-destructor aangeroepen).

```cpp
// ❌ bewust fout: UB-demo, delete van derived object via base pointer zonder virtual destructor
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view description = "") : m_description(description) {}
    /*virtual*/ ~Animal() { std::cout << "Animal destructor called\n"; }
    virtual void breathe() const {}
protected:
    std::string m_description;
};
class Feline : public Animal {
public:
    Feline(std::string_view fur_style = "", std::string_view description = "")
        : Animal(description), m_fur_style(fur_style) {}
    /*virtual*/ ~Feline() { std::cout << "Feline destructor called\n"; }
private:
    std::string m_fur_style;
};
class Dog : public Feline {
public:
    Dog(std::string_view fur_style = "", std::string_view description = "")
        : Feline(fur_style, description) {}
    /*virtual*/ ~Dog() { std::cout << "Dog destructor called\n"; }
};

int main() {
    Animal* p_animal = new Dog;
    delete p_animal;   // static binding: enkel ~Animal() -> lek + UB
}
```

```text
Animal destructor called
```

#### Met virtual destructors: correcte volgorde [▶ 29:33:10](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=106390s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view description = "") : m_description(description) {}
    virtual ~Animal() { std::cout << "Animal destructor called\n"; }
    virtual void breathe() const {}
protected:
    std::string m_description;
};
class Feline : public Animal {
public:
    Feline(std::string_view fur_style = "", std::string_view description = "")
        : Animal(description), m_fur_style(fur_style) {}
    virtual ~Feline() { std::cout << "Feline destructor called\n"; }
private:
    std::string m_fur_style;
};
class Dog : public Feline {
public:
    Dog(std::string_view fur_style = "", std::string_view description = "")
        : Feline(fur_style, description) {}
    virtual ~Dog() { std::cout << "Dog destructor called\n"; }
};

int main() {
    {
        Dog dog1;   // gewoon object
    }               // hier: Dog, Feline, Animal
    std::cout << "------\n";
    Animal* p_animal = new Dog;
    delete p_animal;   // dynamic binding op de destructor
}
```

```text
Dog destructor called
Feline destructor called
Animal destructor called
------
Dog destructor called
Feline destructor called
Animal destructor called
```

#### dynamic_cast met pointers en references [▶ 29:46:06](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=107166s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Animal {
public:
    Animal(std::string_view description = "") : m_description(description) {}
    virtual ~Animal() { std::cout << "Animal destructor called for " << m_description << '\n'; }
    virtual void breathe() const { std::cout << "Animal::breathe\n"; }
protected:
    std::string m_description;
};

class Feline : public Animal {
public:
    Feline(std::string_view fur_style = "", std::string_view description = "")
        : Animal(description), m_fur_style(fur_style) {}
    virtual ~Feline() { std::cout << "Feline destructor called for " << m_description << '\n'; }
    virtual void run() const { std::cout << "Feline::run\n"; }
    void do_some_feline_thingy() const {   // NIET virtual
        std::cout << "Doing some feline thingy for " << m_description << '\n';
    }
private:
    std::string m_fur_style;
};

class Dog : public Feline {
public:
    Dog(std::string_view fur_style = "", std::string_view description = "")
        : Feline(fur_style, description) {}
    virtual ~Dog() { std::cout << "Dog destructor called for " << m_description << '\n'; }
    virtual void bark() const { std::cout << "Dog::bark\n"; }
    void do_some_dog_thingy() const {
        std::cout << "Doing some dog thingy, speed : " << m_speed << '\n';
    }
private:
    double m_speed{0.0};   // extra dog-data
};

void do_something_with_animal_ptr(Animal* animal) {
    std::cout << "In function taking base pointer...\n";
    Feline* feline_ptr = dynamic_cast<Feline*>(animal);
    if (feline_ptr) {
        feline_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't cast to Feline pointer, sorry\n";
    }
}

void do_something_with_animal_ref(Animal& animal) {
    std::cout << "In function taking base reference...\n";
    Feline* feline_ptr = dynamic_cast<Feline*>(&animal);   // reference -> pointer: controleerbaar
    if (feline_ptr) {
        feline_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't cast to Feline reference, sorry\n";
    }
}

int main() {
    Animal* animal1 = new Feline("stripes", "feline1");
    // animal1->do_some_feline_thingy();   // FOUT: Animal kent deze functie niet

    // Pointer -> pointer
    Feline* fel_ptr = dynamic_cast<Feline*>(animal1);
    if (fel_ptr) {
        fel_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't do the transformation from Animal* to Feline*\n";
    }

    // Mislukte cast naar Dog*: nullptr, dus controleren!
    Dog* dog_ptr = dynamic_cast<Dog*>(animal1);
    if (dog_ptr) {
        dog_ptr->do_some_dog_thingy();
    } else {
        std::cout << "Couldn't do the transformation from Animal* to Dog*\n";
    }

    std::cout << "------\n";
    // Reference -> reference (geen controle mogelijk)
    Feline feline2("stripes", "feline2");
    Animal& animal_ref = feline2;
    Feline& feline_ref = dynamic_cast<Feline&>(animal_ref);
    feline_ref.do_some_feline_thingy();

    // Reference -> pointer: wel controle mogelijk
    Dog* dog_ptr2 = dynamic_cast<Dog*>(&animal_ref);
    if (dog_ptr2) {
        dog_ptr2->do_some_dog_thingy();
    } else {
        std::cout << "Couldn't cast to Dog reference, sorry\n";
    }

    std::cout << "------\n";
    do_something_with_animal_ptr(animal1);
    do_something_with_animal_ref(animal_ref);

    delete animal1;   // niet vergeten!
    std::cout << "Done\n";
}
```

```text
Doing some feline thingy for feline1
Couldn't do the transformation from Animal* to Dog*
------
Doing some feline thingy for feline2
Couldn't cast to Dog reference, sorry
------
In function taking base pointer...
Doing some feline thingy for feline1
In function taking base reference...
Doing some feline thingy for feline2
Feline destructor called for feline1
Animal destructor called for feline1
Done
Feline destructor called for feline2
Animal destructor called for feline2
```

#### Mislukte dynamic_cast naar een reference: bad_cast [▶ 29:58:05](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=107885s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

In de opname eindigt het programma hier abrupt met een `bad_cast`-melding; "Done" wordt nooit geprint. De exacte foutmelding verschilt per platform.

```cpp
// nocheck-output
#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;
};
class Feline : public Animal {};
class Dog : public Feline {
public:
    void do_some_dog_thingy() const { std::cout << "Doing some dog thingy\n"; }
};

int main() {
    Feline feline1;
    Animal& animal_ref = feline1;
    std::cout << "Casting to Dog&...\n";
    Dog& dog_ref = dynamic_cast<Dog&>(animal_ref);   // mislukt: gooit std::bad_cast
    dog_ref.do_some_dog_thingy();                     // wordt nooit bereikt
    std::cout << "Done\n";
}
```

```text
voorbeeldoutput:
Casting to Dog&...
terminate called after throwing an instance of 'std::bad_cast'
  what():  std::bad_cast
```

#### dynamic_cast buiten een polymorphic hiërarchie: compilerfout [▶ 30:05:13](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=108313s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: "cannot 'dynamic_cast' 'data' (of type 'int') to type 'std::string'" (en idem voor int* -> std::string*)
#include <iostream>
#include <string>

int main() {
    int data{45};
    std::string str = dynamic_cast<std::string>(data);         // FOUT
    int* data_ptr = &data;
    std::string* str_ptr = dynamic_cast<std::string*>(data_ptr); // FOUT: geen polymorphic hiërarchie
}
```

#### Virtual functions vanuit constructor en destructor [▶ 30:15:37](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=108937s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called\n";
        setup();      // static binding: altijd Base::setup()
    }
    virtual ~Base() {
        clean_up();   // static binding: altijd Base::clean_up()
        std::cout << "Base destructor called\n";
    }
    virtual void setup() {
        std::cout << "Base::setup() called\n";
        m_value = 10;
    }
    virtual void clean_up() { std::cout << "Base::clean_up() called\n"; }
    int get_value() const { return m_value; }
protected:
    int m_value{};
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor called\n"; }
    virtual ~Derived() { std::cout << "Derived destructor called\n"; }
    void setup() override {
        std::cout << "Derived::setup() called\n";
        m_value = 100;
    }
    void clean_up() override { std::cout << "Derived::clean_up() called\n"; }
};

int main() {
    Base* p_base = new Derived;
    std::cout << "value : " << p_base->get_value() << '\n';   // 10, niet 100

    std::cout << "--- setup/clean_up na constructie ---\n";
    p_base->setup();       // nu dynamic binding
    std::cout << "value : " << p_base->get_value() << '\n';
    p_base->clean_up();    // vóór delete
    std::cout << "--- delete ---\n";
    delete p_base;
}
```

```text
Base constructor called
Base::setup() called
Derived constructor called
value : 10
--- setup/clean_up na constructie ---
Derived::setup() called
value : 100
Derived::clean_up() called
--- delete ---
Derived destructor called
Base::clean_up() called
Base destructor called
```

#### Abstract class Shape met Rectangle en Circle [▶ 30:32:30](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=109950s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

`typeid(...).name()` geeft een implementatie-afhankelijke naam (GCC: *mangled*, bv. `9Rectangle`), daarom wordt deze output niet vergeleken.

```cpp
// nocheck-output
#include <iostream>
#include <string>
#include <string_view>
#include <typeinfo>

class Shape {
public:
    Shape() = default;
    Shape(std::string_view description) : m_description(description) {}
    virtual ~Shape() = default;
    virtual double perimeter() const = 0;   // pure virtual
    virtual double surface() const = 0;     // pure virtual
protected:
    std::string m_description;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height, std::string_view description)
        : Shape(description), m_width(width), m_height(height) {}
    double perimeter() const override { return 2 * m_width + 2 * m_height; }
    double surface() const override { return m_width * m_height; }
private:
    double m_width{};
    double m_height{};
};

class Circle : public Shape {
public:
    Circle(double radius, std::string_view description)
        : Shape(description), m_radius(radius) {}
    double perimeter() const override { return 2 * PI * m_radius; }
    double surface() const override { return PI * m_radius * m_radius; }
private:
    double m_radius{};
    inline static const double PI{3.14159};
};

int main() {
    // Shape* shape_ptr = new Shape;   // FOUT: abstract class

    const Shape* shape_rect = new Rectangle(10, 10, "rect1");
    std::cout << "dynamic type of shape_rect : " << typeid(*shape_rect).name() << '\n';
    std::cout << "The surface of shape_rect is : " << shape_rect->surface() << '\n';

    std::cout << "------\n";
    const Shape* shape_circle = new Circle(10, "circle1");
    std::cout << "dynamic type of shape_circle : " << typeid(*shape_circle).name() << '\n';
    std::cout << "The surface of shape_circle is : " << shape_circle->surface() << '\n';

    delete shape_rect;
    delete shape_circle;
}
```

```text
voorbeeldoutput (GCC):
dynamic type of shape_rect : 9Rectangle
The surface of shape_rect is : 100
------
dynamic type of shape_circle : 6Circle
The surface of shape_circle is : 314.159
```

#### Abstracte klassen: de compilerfouten [▶ 30:34:54](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=110094s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: "invalid new expression of abstract class type 'Shape'" en idem voor 'Circle' (surface() niet overschreven)
#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double perimeter() const = 0;
    virtual double surface() const = 0;
};

class Circle : public Shape {
public:
    double perimeter() const override { return 2 * 3.14159 * m_radius; }
    // double surface() const override { ... }   // vergeten -> Circle is ook abstract
private:
    double m_radius{10};
};

int main() {
    Shape* p1 = new Shape;    // FOUT 1
    Shape* p2 = new Circle;   // FOUT 2
}
```

```cpp
// ❌ bewust fout: "pure-specifier on function-definition"
class Shape {
public:
    virtual double surface() const = 0 { return 0.0; }   // FOUT: = 0 en body samen
};

int main() {}
```

#### Interface StreamInsertable met Point en een Animal-hiërarchie [▶ 30:55:00](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=111300s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

// ----- de interface -----
class StreamInsertable {
    friend std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand);
public:
    virtual ~StreamInsertable() = default;
    virtual void stream_insert(std::ostream& out) const = 0;
};

std::ostream& operator<<(std::ostream& out, const StreamInsertable& operand) {
    operand.stream_insert(out);   // dynamic binding via reference
    return out;
}

// ----- Point: interface aan een losse klasse hangen -----
class Point : public StreamInsertable {
public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y) {}
    void stream_insert(std::ostream& out) const override {
        out << "Point [x : " << m_x << ", y : " << m_y << "]";
    }
private:
    double m_x{};
    double m_y{};
};

// ----- Animal-hiërarchie: interface aan de base class -----
class Animal : public StreamInsertable {
public:
    Animal(std::string_view description) : m_description(description) {}
    void stream_insert(std::ostream& out) const override {
        out << "Animal [description : " << m_description << "]";
    }
protected:
    std::string m_description;
};

class Feline : public Animal {
public:
    Feline(std::string_view fur_style, std::string_view description)
        : Animal(description), m_fur_style(fur_style) {}
    void stream_insert(std::ostream& out) const override {
        out << "Feline [description : " << m_description << ", fur_style : " << m_fur_style << "]";
    }
protected:
    std::string m_fur_style;
};

class Dog : public Feline {
public:
    Dog(std::string_view fur_style, std::string_view description) : Feline(fur_style, description) {}
    void stream_insert(std::ostream& out) const override {
        out << "Dog [description : " << m_description << ", fur_style : " << m_fur_style << "]";
    }
};

class Cat : public Feline {
public:
    Cat(std::string_view fur_style, std::string_view description) : Feline(fur_style, description) {}
    void stream_insert(std::ostream& out) const override {
        out << "Cat [description : " << m_description << ", fur_style : " << m_fur_style << "]";
    }
};

class Bird : public Animal {
public:
    Bird(std::string_view wing_color, std::string_view description)
        : Animal(description), m_wing_color(wing_color) {}
    void stream_insert(std::ostream& out) const override {
        out << "Bird [description : " << m_description << ", wing_color : " << m_wing_color << "]";
    }
protected:
    std::string m_wing_color;
};

class Pigeon : public Bird {
public:
    Pigeon(std::string_view wing_color, std::string_view description) : Bird(wing_color, description) {}
    void stream_insert(std::ostream& out) const override {
        out << "Pigeon [description : " << m_description << ", wing_color : " << m_wing_color << "]";
    }
};

class Crow : public Bird {
public:
    Crow(std::string_view wing_color, std::string_view description) : Bird(wing_color, description) {}
    void stream_insert(std::ostream& out) const override {
        out << "Crow [description : " << m_description << ", wing_color : " << m_wing_color << "]";
    }
};

int main() {
    Point p1(10, 20);
    operator<<(std::cout, p1);   // wat de compiler eigenlijk doet
    std::cout << '\n';
    std::cout << p1 << '\n';     // leesbare vorm

    std::cout << "------\n";
    std::unique_ptr<Animal> animal1 = std::make_unique<Dog>("stripes", "dog1");
    std::cout << *animal1 << '\n';
    std::unique_ptr<Animal> bird1 = std::make_unique<Bird>("blue", "bird1");
    std::cout << *bird1 << '\n';

    std::cout << "------\n";
    std::shared_ptr<Animal> animals[]{
        std::make_shared<Dog>("stripes", "dog2"),
        std::make_shared<Cat>("black stripes", "cat2"),
        std::make_shared<Crow>("black", "crow2"),
        std::make_shared<Pigeon>("white", "pigeon2")};
    for (const auto& a : animals) {
        std::cout << *a << '\n';
    }
}
```

```text
Point [x : 10, y : 20]
Point [x : 10, y : 20]
------
Dog [description : dog1, fur_style : stripes]
Bird [description : bird1, wing_color : blue]
------
Dog [description : dog2, fur_style : stripes]
Cat [description : cat2, fur_style : black stripes]
Crow [description : crow2, wing_color : black]
Pigeon [description : pigeon2, wing_color : white]
```

#### Interface niet geïmplementeerd: Point is abstract [▶ 30:55:50](https://www.youtube.com/watch?v=8jLOx1hD3_o&t=111350s)

> ℹ️ Gereconstrueerd uit uitleg, code stond op scherm.

```cpp
// ❌ bewust fout: "cannot declare variable 'p1' to be of abstract type 'Point'"
#include <iostream>

class StreamInsertable {
public:
    virtual ~StreamInsertable() = default;
    virtual void stream_insert(std::ostream& out) const = 0;
};

class Point : public StreamInsertable {
public:
    Point(double x, double y) : m_x(x), m_y(y) {}
    // stream_insert niet overschreven
private:
    double m_x, m_y;
};

int main() {
    Point p1(10, 20);   // FOUT
}
```

### Valkuilen & veelgemaakte fouten

#### `virtual` vergeten → static binding
Zonder `virtual` kiest de compiler de functie op basis van het type van de pointer of reference. `Shape* p = &oval1; p->draw();` roept dan `Shape::draw()` aan. Er komt geen fout en geen waarschuwing; je ziet het pas aan de output.

#### Polymorphism verwachten zonder pointer of reference
`Shape s = circle1; s.draw();` is slicing: `s` *is* een `Shape`. Hetzelfde geldt voor parameters **by value** (`void f(Shape s)`) en voor arrays van objecten (`Shape shapes[]{circle1, oval1}`). Gesliced data krijg je nooit meer terug, ook niet via een pointer naar de kopie.

#### Array van references
`Shape& shapes[]{...}` compileert niet; references zijn niet left-assignable. Gebruik raw of smart pointers.

#### Typfout in een override zonder `override`
`void Draw() const` in plaats van `draw()` maakt een nieuwe functie, en de base-versie wordt gewoon aangeroepen. Met `override` wordt dit een compilerfout.

#### Eén overload overriden verbergt de andere
Overschrijf je in een derived klasse één overload van `draw`, dan zijn alle andere `draw`-overloads van de base class verborgen voor die klasse en haar afstammelingen.

#### Nieuwe functie op een lager niveau via een base pointer aanroepen
Functies die enkel in een derived klasse bestaan (nieuwe overload, niet-virtual getter zoals `get_x_rad()`) zijn via een `Shape*` onbekend: *"class Shape has no member named ..."*.

#### Gedeelde static member
Een static member van de base class wordt gedeeld met derived klassen: `Ellipse::m_count` is dan gewoon `Shape::m_count`. Wie in de derived constructor ook nog eens verhoogt, telt dubbel. Wil je een aparte telling, declareer dan een eigen static member in de derived klasse.

#### Default arguments bij virtual functions
De body komt van het dynamic type, maar de defaults van het statische type: via een `Base*` krijg je `Derived::add()` met de defaults van `Base` (resultaat 12 in plaats van 22).

#### Geen virtual destructor
`delete base_ptr;` op een derived object zonder virtual destructor is undefined behavior. In de praktijk wordt enkel de base-destructor aangeroepen en lekt het geheugen van de derived delen.

#### Resultaat van `dynamic_cast` niet controleren
Een mislukte pointer-cast geeft `nullptr`; zonder `if`-controle crasht je programma. Een mislukte reference-cast beëindigt het programma met `bad_cast`; cast een reference daarom naar een pointer als je wilt controleren. Gebruik `dynamic_cast` enkel binnen een polymorphic hiërarchie.

#### Virtual function aanroepen in constructor of destructor
Je krijgt altijd de versie van de klasse waarvan de constructor/destructor op dat moment loopt (static-binding-resultaat), nooit de override van een derived klasse.

#### Niet alle pure virtual functions overriden
Dan is de derived klasse zelf abstract, en `new Circle` of `Point p1(10, 20);` faalt, ook al heb je zelf geen `= 0` geschreven.

#### `delete` vergeten
In meerdere demo's vergat de docent `delete` voor objecten die met `new` gemaakt waren: dan verschijnen er geen destructor-meldingen en lekt geheugen.

### Best practices

- Gebruik polymorphism via **base pointers of base references**, nooit via objecten by value.
- Zet `override` bij **elke** override; de compiler controleert dan de signatuur.
- Geef een klasse met minstens één virtual functie ook een **virtual destructor**.
- Bewaar polymorphic objecten in collecties als **pointers**, bij voorkeur smart pointers (`std::unique_ptr`, `std::shared_ptr`).
- Gebruik `final` bewust: op een functie om verdere overrides te verbieden, op een klasse om erven te verbieden. Vermijd tegenstrijdige combinaties (nieuwe virtual in een final klasse, `virtual ... final` in één declaratie).
- **Vermijd default arguments** bij virtual functions.
- Roep **geen virtual functions** aan in constructors/destructors; roep `setup()` aan na constructie en `clean_up()` vóór `delete`.
- `dynamic_cast` spaarzaam gebruiken; liefst naar een **pointer** en altijd controleren op `nullptr`. Veel downcasting wijst op een ontwerpfout; maak de functie dan beter virtual.
- Gebruik **pure virtual functions** voor operaties die op base-niveau niet zinvol te implementeren zijn, en **interfaces** (abstracte klassen zonder data) om types extra functionaliteit te geven, zoals printbaarheid.
- Geef constructorparameters door als `std::string_view` (geen onnodige kopieën, string literals rechtstreeks bruikbaar).

### Samenvatting

- **Polymorphism** = een base pointer/reference die op verschillende momenten verschillende derived objecten beheert. Je krijgt één functie en één collectie voor alle types in een hiërarchie.
- Standaard doet C++ **static binding**: het type van de pointer/reference bepaalt de functie. Met **`virtual`** krijg je **dynamic binding**: at runtime beslist het type van het werkelijke object.
- Polymorphic objecten zijn **groter** (extra administratie voor de virtual tables): 40/56/56 tegen 32/48/48 bytes in de demo.
- **Slicing**: derived object → base object kopiëert enkel het base part; ook in arrays van objecten. References kunnen niet in arrays; pointers (raw/smart) wel.
- **`override`** laat de compiler controleren dat je echt overschrijft; **`final`** verbiedt verdere overrides of verder erven.
- Eén overload overriden **verbergt** de andere; functies die pas lager in de hiërarchie verschijnen, doen niet mee aan polymorphism van de top-level klasse, maar je kunt polymorphism op **elk niveau** (Feline, Bird, Oval) gebruiken.
- Static members worden **gedeeld** met derived klassen, tenzij die een eigen static member met dezelfde naam declareren.
- Default arguments worden **statisch** gebonden; virtual calls in constructors/destructors geven **static-binding-resultaten**.
- Een base class met virtual functions heeft een **virtual destructor** nodig, anders lekt geheugen en is het gedrag undefined.
- **`dynamic_cast`** downcast at runtime: bij pointers `nullptr` bij falen, bij references `bad_cast`.
- **Pure virtual** (`= 0`) maakt een klasse **abstract**; derived klassen moeten alle pure virtuals implementeren. Een **interface** is een abstracte klasse met enkel pure virtual functions en geen data, bv. `StreamInsertable`.

### Oefeningen

1. **Static vs. dynamic binding.** Schrijf een klasse `Instrument` met `void play() const` die "Instrument plays" print, en een derived klasse `Guitar` die "Guitar strums" print. Roep `play()` aan via een `Instrument*` die naar een `Guitar` wijst, eerst zonder en daarna met `virtual` (gebruik twee varianten van de klassen in één programma: `Instrument`/`Guitar` en `VInstrument`/`VGuitar`).

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>

class Instrument {
public:
    void play() const { std::cout << "Instrument plays\n"; }   // niet virtual
};
class Guitar : public Instrument {
public:
    void play() const { std::cout << "Guitar strums\n"; }
};

class VInstrument {
public:
    virtual ~VInstrument() = default;
    virtual void play() const { std::cout << "Instrument plays\n"; }
};
class VGuitar : public VInstrument {
public:
    void play() const override { std::cout << "Guitar strums\n"; }
};

int main() {
    Guitar g;
    Instrument* p = &g;
    p->play();    // static binding

    VGuitar vg;
    VInstrument* vp = &vg;
    vp->play();   // dynamic binding
}
```

```text
Instrument plays
Guitar strums
```
</details>

2. **Polymorphic collectie met smart pointers.** Maak een abstracte klasse `Shape` met pure virtual `double area() const` en `std::string_view name() const`. Implementeer `Square` (zijde) en `Triangle` (basis, hoogte). Bewaar een `Square(3)`, een `Triangle(4, 5)` en een `Square(1.5)` in een `std::vector<std::unique_ptr<Shape>>` en print naam en oppervlakte, plus de totale oppervlakte.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string_view name() const = 0;
};

class Square : public Shape {
public:
    explicit Square(double side) : m_side(side) {}
    double area() const override { return m_side * m_side; }
    std::string_view name() const override { return "Square"; }
private:
    double m_side;
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : m_base(base), m_height(height) {}
    double area() const override { return m_base * m_height / 2; }
    std::string_view name() const override { return "Triangle"; }
private:
    double m_base, m_height;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Square>(3));
    shapes.push_back(std::make_unique<Triangle>(4, 5));
    shapes.push_back(std::make_unique<Square>(1.5));

    double total{};
    for (const auto& s : shapes) {
        std::cout << s->name() << " : " << s->area() << '\n';
        total += s->area();
    }
    std::cout << "Total : " << total << '\n';
}
```

```text
Square : 9
Triangle : 10
Square : 2.25
Total : 21.25
```
</details>

3. **Slicing en virtual destructor.** Gegeven `Base` met `virtual std::string_view id() const` ("Base") en `Derived` die "Derived" teruggeeft, beide met een destructor die een melding print. (a) Toon met een functie `void by_value(Base b)` en `void by_ref(const Base& b)` het verschil. (b) Maak een `Derived` met `new`, beheer hem via `Base*` en verwijder hem; zorg dat beide destructors lopen.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <string_view>

class Base {
public:
    Base() = default;
    Base(const Base&) = default;
    virtual ~Base() { std::cout << "~Base\n"; }
    virtual std::string_view id() const { return "Base"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "~Derived\n"; }
    std::string_view id() const override { return "Derived"; }
};

void by_value(Base b) { std::cout << "by_value : " << b.id() << '\n'; }   // slicing
void by_ref(const Base& b) { std::cout << "by_ref : " << b.id() << '\n'; }

int main() {
    Derived d;
    by_value(d);   // kopie van het Base-deel; ~Base bij einde van de functie
    by_ref(d);

    std::cout << "------\n";
    Base* p = new Derived;
    delete p;      // virtual destructor: ~Derived en ~Base
    std::cout << "------\n";
}
```

```text
by_value : Base
~Base
by_ref : Derived
------
~Derived
~Base
------
~Derived
~Base
```
</details>

4. **Veilig downcasten.** Maak een hiërarchie `Employee` (virtual `work()`), `Manager` (extra niet-virtual `hold_meeting()`) en `Engineer`. Schrijf `void try_meeting(Employee& e)` die met `dynamic_cast` naar een **pointer** controleert of `e` een `Manager` is, en dan `hold_meeting()` aanroept, anders "Not a manager" print. Test met een manager en een engineer.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Employee {
public:
    explicit Employee(std::string_view name) : m_name(name) {}
    virtual ~Employee() = default;
    virtual void work() const { std::cout << m_name << " works\n"; }
protected:
    std::string m_name;
};

class Manager : public Employee {
public:
    using Employee::Employee;   // constructor overnemen
    void hold_meeting() const { std::cout << m_name << " holds a meeting\n"; }
};

class Engineer : public Employee {
public:
    using Employee::Employee;
    void work() const override { std::cout << m_name << " writes code\n"; }
};

void try_meeting(Employee& e) {
    e.work();
    if (auto* m = dynamic_cast<Manager*>(&e)) {   // reference -> pointer: controleerbaar
        m->hold_meeting();
    } else {
        std::cout << "Not a manager\n";
    }
}

int main() {
    Manager anna("Anna");
    Engineer bob("Bob");
    try_meeting(anna);
    try_meeting(bob);
}
```

```text
Anna works
Anna holds a meeting
Bob writes code
Not a manager
```
</details>

5. **Interface + default-argument-valkuil.** (a) Schrijf een interface `Printable` met pure virtual `void print(std::ostream&) const` en een friend `operator<<`, en laat `Book` (titel, jaar) en `Movie` (titel, minuten) die implementeren; print ze via een array `const Printable*`. (b) Voeg aan een klasse `Greeter` een `virtual void greet(std::string_view who = "world") const` toe en aan `LoudGreeter` een override met default `"WORLD"`. Voorspel en controleer wat `Greeter* g = &loud; g->greet();` print.

<details><summary>Uitwerking</summary>

```cpp
#include <iostream>
#include <string>
#include <string_view>

class Printable {
    friend std::ostream& operator<<(std::ostream& out, const Printable& p) {
        p.print(out);
        return out;
    }
public:
    virtual ~Printable() = default;
    virtual void print(std::ostream& out) const = 0;
};

class Book : public Printable {
public:
    Book(std::string_view title, int year) : m_title(title), m_year(year) {}
    void print(std::ostream& out) const override { out << "Book [" << m_title << ", " << m_year << "]"; }
private:
    std::string m_title;
    int m_year;
};

class Movie : public Printable {
public:
    Movie(std::string_view title, int minutes) : m_title(title), m_minutes(minutes) {}
    void print(std::ostream& out) const override { out << "Movie [" << m_title << ", " << m_minutes << " min]"; }
private:
    std::string m_title;
    int m_minutes;
};

class Greeter {
public:
    virtual ~Greeter() = default;
    virtual void greet(std::string_view who = "world") const { std::cout << "Hello, " << who << '\n'; }
};

class LoudGreeter : public Greeter {
public:
    void greet(std::string_view who = "WORLD") const override { std::cout << "HELLO, " << who << "!\n"; }
};

int main() {
    Book b("Dune", 1965);
    Movie m("Alien", 117);
    const Printable* items[]{&b, &m};
    for (const auto* item : items) {
        std::cout << *item << '\n';
    }

    LoudGreeter loud;
    Greeter* g = &loud;
    g->greet();      // body van LoudGreeter, default van Greeter
    loud.greet();    // body en default van LoudGreeter
}
```

```text
Book [Dune, 1965]
Movie [Alien, 117 min]
HELLO, world!
HELLO, WORLD!
```
</details>

---

<a id="cheatsheet"></a>

## C++ Cheatsheet

Compacte syntax per onderwerp. Fragmenten, geen volledige programma's (daarom ```c++ en niet gecompileerd); zie de hoofdstukken voor werkende voorbeelden.

### Programma, I/O en compileren ([h01](#h01), [h02](#h02))
```c++
#include <iostream>
int main() {
    int age{};
    std::cout << "Age: ";          // output (stdout)
    std::cin >> age;               // input, stopt bij whitespace
    std::string name;
    std::getline(std::cin, name);  // hele regel (#include <string>)
    std::cerr << "error\n";        // foutstroom (stderr)
    std::cout << age << std::endl; // endl = '\n' + flush
    return 0;                      // 0 = succes
}
// g++ -std=c++20 -Wall -Wextra main.cpp -o rooster
// // regelcommentaar   /* blokcommentaar (niet nesten) */
```

### Types en variabelen ([h03](#h03))
```c++
int i{10};            // brace init: weigert narrowing
int j = 10;           // copy init
int k(10);            // functional init
double d{3.14};  float f{3.14f};  long double ld{3.14L};
bool b{true};    char c{'A'};
unsigned int u{5u};   short s;  long l;  long long ll{5LL};
auto x{42};           // type afgeleid: int
int bin = 0b1010, oct = 012, hex = 0xFF;  // 10, 10, 255
sizeof(int)           // grootte in bytes (platformafhankelijk, meestal 4)
const int MAX{100};   constexpr int N{10};   // compile-time constante
```

### Operatoren ([h04](#h04))
```c++
+ - * / %             // int / int = int (fractie weg), % alleen integers
++i  i++  --i  i--    // prefix: eerst wijzigen; postfix: eerst oude waarde
+= -= *= /= %=        // compound assignment
== != < > <= >=       // relational -> bool
&& || !               // logical (short-circuit)
// Precedence: * / % voor + -, voor vergelijken, voor &&, voor ||. Bij twijfel: haakjes.
#include <iomanip>
std::cout << std::setw(10) << std::left << std::setfill('-') << x;
std::cout << std::fixed << std::setprecision(2) << 3.14159;  // 3.14
std::cout << std::boolalpha << true;      // true i.p.v. 1
std::cout << std::hex << std::showbase << 255;  // 0xff
#include <limits>
std::numeric_limits<int>::max();  std::numeric_limits<double>::lowest();
#include <cmath>
std::floor(x) std::ceil(x) std::abs(x) std::sqrt(x) std::pow(b, e) std::round(x) std::exp(x) std::log(x)
```

### Control flow ([h05](#h05), [h06](#h06))
```c++
if (a > b) { ... } else if (a == b) { ... } else { ... }
switch (tool) {               // alleen integrale types / enum
    case PEN: ...; break;     // break vergeten = fall-through
    case ERASER: ...; break;
    default: ...;
}
int max = (a > b) ? a : b;    // ternary
for (size_t i{0}; i < 10; ++i) { ... }
while (cond) { ... }
do { ... } while (cond);      // puntkomma! draait min. 1x
for (auto v : array) { ... }  // range-based for
break; continue;
```

### Arrays ([h07](#h07))
```c++
int scores[5];                // ongeïnitialiseerd
int nums[] {1, 2, 3};         // grootte afgeleid: 3
int zeros[5] {};              // allemaal 0
std::size(nums)               // 3 (C++17, <iterator>)
sizeof(nums) / sizeof(nums[0])
char msg[] {"Hello"};         // 6 chars incl. '\0'
// Index 0..N-1; buiten de grenzen = undefined behaviour
```

### Pointers en dynamisch geheugen ([h08](#h08))
```c++
int x{5};
int* p{&x};          // p bevat adres van x
*p = 10;             // dereference: x wordt 10
int* q{nullptr};     // wijst nergens naar; check vóór gebruik: if (q) ...
const char* s{"Hi"}; // pointer naar string literal
int* h{new int{42}}; // heap
delete h; h = nullptr;            // vrijgeven + dangling voorkomen
int* arr{new int[n]{}};           // dynamische array
delete[] arr; arr = nullptr;      // delete[] bij new[]
int* safe{new(std::nothrow) int[huge]};   // nullptr i.p.v. exception (<new>)
try { new int[huge]; } catch (std::exception& e) { e.what(); }
```

### References ([h09](#h09))
```c++
int x{5};
int& r{x};            // alias; moet direct geïnitialiseerd; kan niet herbinden
r = 7;                // x wordt 7
const int& cr{x};     // alleen lezen via cr
// pointer: kan nullptr zijn, kan herwijzen, *p nodig.  reference: altijd gebonden, geen * nodig.
```

### Characters en strings ([h10](#h10))
```c++
#include <cctype>   std::isalnum(c) std::isalpha(c) std::isdigit(c) std::isblank(c)
                    std::isupper(c) std::islower(c) std::toupper(c) std::tolower(c)
#include <cstring>  std::strlen(s)  std::strcmp(a, b)  std::strncmp(a, b, n)
                    std::strchr(s, c)  std::strrchr(s, c)
                    std::strcpy(d, s)  std::strncpy(d, s, n)  std::strcat(d, s)  std::strncat(d, s, n)
#include <string>
std::string name{"John"};   std::string e(4, 'e');   // "eeee"
name.size();  name + " Doe";  name[0];  name == "John";
```

### Functions ([h11](#h11)–[h13](#h13))
```c++
int max(int a, int b);                 // declaratie (prototype), vaak in .h
int max(int a, int b) { return a > b ? a : b; }  // definitie, in .cpp (ODR: één keer)
void by_value(int x);                  // kopie
void by_pointer(int* x);               // aanroep: f(&v); in f: *x = ...
void by_reference(int& x);             // aanroep: f(v); wijzigt origineel
void read_only(const std::string& s);  // geen kopie, niet wijzigbaar
void out_param(int& result);           // "output parameter"
std::string make() { return "abc"; }   // return by value (copy elision)
int max(double a, double b);           // overloading: andere parameterlijst
// Return type alleen verschillen is GEEN geldige overload.
#include "eigen.h"                     // eigen header: aanhalingstekens
```

### Lambdas ([h14](#h14))
```c++
auto f = [](int a, int b) -> int { return a + b; };
f(1, 2);
[](){ std::cout << "direct\n"; }();     // direct aanroepen
int c{5};
[c]()  { return c; };     // capture by value (kopie bij aanmaken)
[&c]() { ++c; };          // capture by reference
[=]() {...};  [&]() {...};  // alles by value / by reference
```

### Function templates ([h15](#h15))
```c++
template <typename T>
T maximum(T a, T b) { return (a > b) ? a : b; }
maximum(1, 2);                   // T = int (deduction)
maximum<double>(1, 2.5);         // explicit template argument
template <typename T> const T& maximum(const T& a, const T& b);  // by reference
template <>                      // specialization
const char* maximum<const char*>(const char* a, const char* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}
```

### C++20 concepts ([h16](#h16))
```c++
#include <concepts>
template <typename T> requires std::integral<T>   T add(T a, T b);
template <std::integral T>                         T add(T a, T b);
auto add(std::integral auto a, std::integral auto b);
template <typename T> T add(T a, T b) requires std::integral<T>;

template <typename T>
concept MyIntegral = std::is_integral_v<T>;
template <typename T>
concept Multipliable = requires(T a, T b) { a * b; };       // simple requirement
template <typename T>
concept Addable = requires(T a) {
    { a + a } -> std::convertible_to<int>;                   // compound requirement
    requires sizeof(T) <= 4;                                 // nested requirement
    typename T::value_type;                                  // type requirement
};
template <typename T> requires std::integral<T> || std::floating_point<T> ...  // combineren
```

### Classes ([h17](#h17))
```c++
class Cylinder {
public:
    Cylinder() = default;                                   // defaulted constructor
    Cylinder(double r, double h) : m_radius{r}, m_height{h} {}  // initializer list
    ~Cylinder() { }                                          // destructor
    double volume() const { return 3.14159 * m_radius * m_radius * m_height; }
    void set_radius(double r) { this->m_radius = r; }        // setter, this-pointer
    double radius() const { return m_radius; }               // getter
private:
    double m_radius{1.0};
    double m_height{1.0};
};                                // puntkomma!
Cylinder c1;  Cylinder c2{10, 2};
Cylinder* p{new Cylinder{1, 2}};  p->volume();  (*p).volume();  delete p;
struct Point { double x; double y; };   // struct: members standaard public
// Header: #pragma once of #ifndef X_H / #define X_H / #endif
```

### Inheritance ([h18](#h18))
```c++
class Person { protected: std::string m_name; public: Person(std::string n); };
class Player : public Person {          // public / protected / private inheritance
public:
    Player(std::string n, int t) : Person{n}, m_team{t} {}   // basisconstructor aanroepen
    Player(const Player& o) : Person{o}, m_team{o.m_team} {}  // copy constructor
    using Person::Person;               // inheriting constructors
private:
    int m_team;
};
class Engineer : private Person {
public:
    using Person::get_name;             // member "terughalen" in public scope
};
// Volgorde: constructors basis -> afgeleid; destructors afgeleid -> basis.
// private members van de basis: nooit direct toegankelijk in de afgeleide klasse.
```

### Polymorphism ([h19](#h19))
```c++
class Shape {
public:
    virtual ~Shape() = default;                   // virtual destructor!
    virtual void draw() const { ... }             // dynamic binding
    virtual double area() const = 0;              // pure virtual -> abstracte klasse
};
class Circle : public Shape {
public:
    void draw() const override { ... }            // override: compiler controleert
    double area() const override final { ... }    // final: niet verder overridebaar
};
class Square final : public Shape { ... };        // final class: geen afgeleiden
Shape* s{new Circle{}};  s->draw();  delete s;    // roept Circle::draw aan
std::unique_ptr<Shape> u{std::make_unique<Circle>()};   // <memory>
Shape* arr[] {&c1, &c2};                           // polymorfe collectie: pointers
Shape sliced = circle;                             // slicing: afgeleid deel weg
Circle* c = dynamic_cast<Circle*>(s);  if (c) ...  // nullptr als het geen Circle is
// Default argumenten van virtual functions: bepaald door het STATISCHE type.
// Virtual call in constructor/destructor: geen polymorf gedrag.
```

### STL en standaardbibliotheek die in de cursus voorkomt
```c++
#include <string>    std::string
#include <iomanip>   std::setw std::setprecision std::fixed ...
#include <limits>    std::numeric_limits<T>
#include <cmath>     wiskundige functies
#include <cstring>   C-string functies
#include <cctype>    karakterfuncties
#include <concepts>  std::integral std::floating_point std::convertible_to ...
#include <type_traits> std::is_integral_v<T>
#include <memory>    std::unique_ptr std::make_unique std::shared_ptr
```
> 💡 Aanvulling: containers (`std::vector`, `std::array`, `std::map`) en algoritmen (`<algorithm>`) worden in dit deel van de cursus nauwelijks behandeld. Kort ter oriëntatie:
```c++
#include <vector>     std::vector<int> v{1, 2, 3};  v.push_back(4);  v.size();  v[0];
#include <array>      std::array<int, 3> a{1, 2, 3};
#include <algorithm>  std::sort(v.begin(), v.end());  std::find(v.begin(), v.end(), 2);
                      std::max_element(v.begin(), v.end());  std::count_if(v.begin(), v.end(), pred);
```

---

<a id="begrippenlijst"></a>

## Begrippenlijst

| Term | Uitleg | Hoofdstuk |
|---|---|---|
| `#include` | Preprocessor-directive die de inhoud van een header in het bestand plakt; `<...>` voor standaardbibliotheek, `"..."` voor eigen headers. | [2](#h02), [11](#h11) |
| `#pragma once` / include guard | Voorkomt dat een header twee keer in dezelfde vertaaleenheid terechtkomt (`#ifndef X_H` / `#define X_H` / `#endif`). | [17](#h17) |
| Abstracte klasse | Klasse met minstens één pure virtual function; je kunt er geen object van maken, alleen van afgeleide klassen. Dient als interface. | [19](#h19) |
| Access specifier | `public`, `protected` of `private`: bepaalt wie een member mag gebruiken. | [17](#h17), [18](#h18) |
| Alias | Andere naam voor hetzelfde object; zo werkt een reference. | [9](#h09) |
| Argument | De waarde die je bij een aanroep aan een function meegeeft. | [11](#h11) |
| Array | Vast aantal elementen van hetzelfde type, aaneengesloten in het geheugen, geïndexeerd vanaf 0. | [7](#h07) |
| Arrow-operator (`->`) | Member benaderen via een pointer: `p->f()` is `(*p).f()`. | [17](#h17) |
| Assignment | Een nieuwe waarde aan een bestaande variabele geven met `=`. | [3](#h03) |
| Associativity | Volgorde (links→rechts of rechts→links) waarin operatoren met dezelfde precedence worden geëvalueerd. | [4](#h04) |
| `auto` | Laat de compiler het type afleiden uit de initializer. | [3](#h03), [16](#h16) |
| Base class | Klasse waarvan een andere klasse erft. | [18](#h18) |
| `bool` | Type met de waarden `true` en `false`. | [3](#h03) |
| Brace initialization | Initialiseren met `{}`; weigert narrowing conversions. | [3](#h03) |
| `break` | Verlaat direct een loop of een `switch`. | [5](#h05), [6](#h06) |
| Capture list | Het `[...]`-deel van een lambda: welke variabelen uit de omgeving de lambda mag gebruiken (by value of by reference). | [14](#h14) |
| `char` | Type voor één teken (1 byte); wordt intern als getal opgeslagen. | [3](#h03), [10](#h10) |
| C-string | `char`-array afgesloten met `'\0'`. | [7](#h07), [10](#h10) |
| `cin` / `cout` / `cerr` / `clog` | Standaardstromen voor invoer, uitvoer, foutmeldingen en logging (`<iostream>`). | [2](#h02) |
| Class | Door de gebruiker gedefinieerd type dat data (member variables) en gedrag (member functions) bundelt. | [17](#h17) |
| Compiler | Vertaalt broncode naar machinecode (GCC, Clang, MSVC). | [1](#h01), [2](#h02) |
| Compound assignment | `+=`, `-=`, `*=`, `/=`, `%=`: bewerking en toewijzing in één. | [4](#h04) |
| Concept | C++20: benoemde set eisen aan een template-parameter, gecontroleerd bij compilatie. | [16](#h16) |
| `const` | Waarde mag na initialisatie niet meer veranderen. | [3](#h03), [9](#h09), [11](#h11) |
| `constexpr` | Waarde of function die al tijdens compilatie berekend kan worden. | [2](#h02), [3](#h03) |
| Constructor | Speciale member function die een object initialiseert; zelfde naam als de klasse, geen return type. | [17](#h17), [18](#h18) |
| `continue` | Slaat de rest van de huidige loop-iteratie over. | [6](#h06) |
| Copy constructor | Constructor die een object maakt als kopie van een ander object van hetzelfde type. | [18](#h18) |
| Dangling pointer | Pointer die naar geheugen wijst dat niet meer geldig is (bv. na `delete`). | [8](#h08) |
| Declaratie | Introduceert een naam en zijn type, zonder (noodzakelijk) een definitie. | [11](#h11) |
| Default constructor | Constructor zonder parameters; `= default` laat de compiler hem maken. | [17](#h17), [18](#h18) |
| Definitie | De volledige implementatie van een function of de aanmaak van een variabele/klasse. | [11](#h11) |
| `delete` / `delete[]` | Geeft heapgeheugen vrij dat met `new` / `new[]` is gereserveerd. | [8](#h08) |
| Dereference (`*p`) | Het object benaderen waar een pointer naar wijst. | [8](#h08) |
| Derived class | Klasse die van een base class erft. | [18](#h18) |
| Destructor | Speciale member function (`~Naam`) die wordt aangeroepen als een object ophoudt te bestaan. | [17](#h17), [18](#h18), [19](#h19) |
| `do-while` | Loop die de voorwaarde pas na de body controleert; draait dus minstens één keer. | [6](#h06) |
| `double` / `float` / `long double` | Floating-point types met toenemende precisie (meestal 8, 4 en 8–16 bytes). | [3](#h03) |
| Dynamic binding | Bij `virtual` functions bepaalt het werkelijke type van het object (runtime) welke function wordt aangeroepen. | [19](#h19) |
| `dynamic_cast` | Veilige cast binnen een polymorfe hiërarchie; geeft `nullptr` (pointer) of een exception (reference) als het niet past. | [19](#h19) |
| `else if` | Extra voorwaarde in een `if`-keten. | [5](#h05) |
| `endl` | Schrijft een newline en flusht de stroom. | [2](#h02), [4](#h04) |
| Executable | Het uitvoerbare programma dat de compiler en linker maken. | [1](#h01), [2](#h02) |
| `final` | Verbiedt verder overriden van een virtual function of erven van een klasse. | [19](#h19) |
| `for` | Loop met initialisatie, voorwaarde en increment in de kop. | [6](#h06) |
| Function | Benoemd stuk code met parameters en een return type. | [2](#h02), [11](#h11) |
| Function hiding | Een function in de afgeleide klasse met dezelfde naam verbergt alle overloads van de basisklasse. | [18](#h18), [19](#h19) |
| Function template | Blauwdruk waaruit de compiler functions voor concrete types genereert. | [15](#h15) |
| Heap | Geheugengebied voor dynamische allocatie met `new`; levensduur bepaal je zelf. | [8](#h08) |
| `if` | Voert code uit als een voorwaarde waar is. | [5](#h05) |
| Inheritance | Een klasse bouwt voort op een bestaande klasse en neemt haar members over. | [18](#h18) |
| Inheriting constructors | `using Base::Base;` maakt de constructors van de basis beschikbaar in de afgeleide klasse. | [18](#h18) |
| Initializer list | `: m_a{a}, m_b{b}` in een constructor: members direct initialiseren. | [17](#h17), [18](#h18) |
| `int` en modifiers | Geheel getal; `short`, `long`, `long long`, `signed`, `unsigned` wijzigen bereik/grootte. | [3](#h03) |
| Lambda | Naamloze function-object, ter plekke gedefinieerd: `[capture](params) -> ret { body }`. | [14](#h14) |
| Linker | Combineert gecompileerde objectbestanden tot een executable; meldt ontbrekende of dubbele definities. | [2](#h02), [11](#h11) |
| Memory leak | Heapgeheugen dat nooit wordt vrijgegeven omdat geen pointer er meer naar wijst. | [8](#h08) |
| Memory map | Indeling van het programmageheugen (o.a. stack, heap, code-/datasegment). | [2](#h02), [8](#h08) |
| Member function / member variable | Function of variabele die bij een klasse hoort. | [17](#h17) |
| Narrowing conversion | Conversie waarbij informatie verloren kan gaan (bv. `double` → `int`). | [3](#h03) |
| `new` | Reserveert geheugen op de heap en geeft een pointer terug; gooit `std::bad_alloc` bij falen. | [8](#h08) |
| `nothrow` | `new(std::nothrow)` geeft `nullptr` terug in plaats van een exception. | [8](#h08) |
| `nullptr` | Literal voor een pointer die nergens naar wijst. | [8](#h08) |
| `numeric_limits` | `<limits>`: min/max en eigenschappen van numerieke types. | [4](#h04) |
| One Definition Rule (ODR) | Elke function/variabele mag in het hele programma maar één definitie hebben (klassen: één per vertaaleenheid). | [11](#h11), [17](#h17) |
| Output parameter | Parameter (pointer of non-const reference) waarlangs een function een resultaat teruggeeft. | [12](#h12) |
| Overloading | Meerdere functions met dezelfde naam maar een andere parameterlijst. | [13](#h13) |
| `override` | Markeert dat een function een virtual function van de basis overschrijft; de compiler controleert dat. | [19](#h19) |
| Parameter | Variabele in de functiedefinitie die het argument ontvangt. | [11](#h11) |
| Pass by pointer | Het adres doorgeven; de function kan via `*` het origineel wijzigen. | [11](#h11) |
| Pass by reference | Een reference doorgeven; de function werkt direct op het origineel, zonder kopie. | [11](#h11) |
| Pass by value | Een kopie doorgeven; wijzigingen raken het origineel niet. | [11](#h11) |
| Pointer | Variabele die een geheugenadres bevat. | [8](#h08) |
| Polymorphism | Via een basis-pointer/-reference objecten van verschillende afgeleide types uniform behandelen, met het juiste gedrag per type. | [19](#h19) |
| Postfix / prefix | `i++` geeft de oude waarde en verhoogt; `++i` verhoogt en geeft de nieuwe waarde. | [4](#h04) |
| Precedence | Prioriteit van operatoren (bv. `*` vóór `+`). | [4](#h04) |
| Preprocessor | Verwerkt `#`-directives vóór de eigenlijke compilatie. | [2](#h02), [17](#h17) |
| Private inheritance | Alle geërfde public/protected members worden private in de afgeleide klasse. | [18](#h18) |
| `protected` | Toegankelijk voor de klasse zelf en afgeleide klassen, niet van buitenaf. | [18](#h18) |
| Pure virtual function | `virtual f() = 0;` zonder implementatie in de basis; maakt de klasse abstract. | [19](#h19) |
| Range-based for | `for (auto x : container)`: loopt over alle elementen. | [6](#h06), [7](#h07) |
| Reference | Alias voor een bestaand object; moet bij declaratie gebonden worden en kan niet herbonden worden. | [9](#h09) |
| `requires` | C++20-clause/expressie die eisen aan template-parameters uitdrukt. | [16](#h16) |
| Return by value | Een function geeft een (eventueel door de compiler weggeoptimaliseerde) kopie terug. | [12](#h12) |
| Scope | Het deel van de code waar een naam zichtbaar is (meestal het `{}`-blok). | [6](#h06), [11](#h11) |
| `size_t` | Unsigned type voor groottes en indexen. | [6](#h06), [7](#h07) |
| `sizeof` | Grootte van een type of object in bytes. | [3](#h03), [7](#h07), [17](#h17) |
| Slicing | Bij kopiëren van een afgeleid object naar een basisobject gaat het afgeleide deel verloren. | [18](#h18), [19](#h19) |
| Stack | Geheugengebied voor lokale variabelen; automatisch opgeruimd aan het einde van de scope. | [8](#h08) |
| Standard library / STL | Bibliotheek die bij C++ hoort (`std::`); de STL is het deel met containers, iterators en algoritmen. | [2](#h02) |
| Statement | Eén instructie, afgesloten met `;`. | [2](#h02) |
| Static binding | Bij niet-virtual functions bepaalt het statische type (van de pointer/reference) welke function wordt aangeroepen. | [19](#h19) |
| `static` member | Member die bij de klasse hoort in plaats van bij één object. | [11](#h11), [19](#h19) |
| `static_cast` | Expliciete compile-time conversie tussen verwante types. | [3](#h03), [4](#h04) |
| `std::string` | Klasse voor tekst die zelf haar geheugen beheert (`<string>`). | [10](#h10) |
| `struct` | Als `class`, maar members zijn standaard `public`. | [17](#h17) |
| `switch` | Kiest een tak op basis van een integrale waarde; `break` voorkomt fall-through. | [5](#h05) |
| Template specialization | Aparte implementatie van een template voor één specifiek type. | [15](#h15) |
| Template type deduction | De compiler leidt de template-argumenten af uit de functieargumenten. | [15](#h15) |
| Ternary operator | `cond ? a : b`: compacte if/else die een waarde oplevert. | [5](#h05) |
| `this` | Pointer naar het huidige object binnen een member function. | [17](#h17) |
| Undefined behaviour (UB) | Gedrag waar de standaard niets over zegt (bv. buiten array-grenzen schrijven, `nullptr` dereferencen); alles kan gebeuren. | [7](#h07), [8](#h08) |
| `using` (in een klasse) | Haalt een member van de basis terug in een gekozen access-niveau, of erft constructors. | [18](#h18) |
| `virtual` | Maakt een member function polymorf: aanroep via basis-pointer/-reference kiest de afgeleide versie. | [19](#h19) |
| Virtual destructor | Zorgt dat bij `delete` via een basis-pointer ook de afgeleide destructor draait. | [19](#h19) |
| vtable | Tabel met function-pointers die de compiler per polymorfe klasse aanlegt; verklaart waarom polymorfe objecten groter zijn. | [19](#h19) |
| Warning | Melding van de compiler over verdachte code die wel compileert. | [2](#h02) |
| `while` | Loop die blijft draaien zolang de voorwaarde waar is. | [6](#h06) |

---

<a id="valkuilen"></a>

## Overzicht valkuilen

Alle valkuilen uit de hoofdstukken gebundeld, per hoofdstuk. Klik op het hoofdstuk voor de volledige uitleg en codevoorbeelden.

### [Hoofdstuk 1 – Introductie en tools instellen](#h01)

- **`-std=c++20` vergeten** — Zonder deze vlag (of met een oudere standaard) kent de compiler `<=>` niet, en mislukt de build van het testprogramma.
- **Compiler niet gevonden (`PATH`)** — `'g++' is not recognized...` of `command not found` betekent dat de `bin`-map van de compiler niet in `PATH` staat, of dat je terminal (of VS Code) nog vóór de wijziging was geopend.
- **`cl.exe` werkt niet in een gewone terminal** — Dat is normaal.
- **Verkeerd bestand actief bij Run Task** — De standaardtask gebruikt variabelen als `${fileDirname}`.
- **Ongeldige JSON in tasks.json** — Een vergeten komma tussen twee argumenten, of tussen twee tasks, maakt het bestand ongeldig.
- **Verkeerde vlag in een online compiler** — In Compiler Explorer ben je zelf verantwoordelijk voor de vlaggen.
- **Pad- en naamverschillen tussen platforms** — Op Windows heet de binary `rooster.exe` en gebruik je `\\` in de JSON-paden.
- **Verkeerde Clang op macOS** — `/usr/bin/clang++` is Apple Clang en niet de Homebrew-LLVM.
- **Oude GCC uit de pakketbron** — Ubuntu 20.04 levert standaard geen GCC 11.

### [Hoofdstuk 2 – Diving in](#h02)

- **Puntkomma vergeten** — Bijna elk statement moet met `;` eindigen.
- **Puntkomma achter `#include`** — `#include <iostream>` krijgt géén puntkomma.
- **`#include` vergeten** — Zonder `#include <iostream>` zijn `std::cout` en `std::endl` onbekend ("namespace std has no member cout").
- **`std::endl` vergeten** — Zonder nieuwe regel plakken opeenvolgende uitvoerstatements tegen elkaar ("Number2Number3").
- **Blokcommentaar nesten** — `/* ...
- **Warnings negeren** — Een warning stopt de build niet, maar kan een runtime-probleem aankondigen, zoals `7 / 0`: het programma bouwt, maar crasht tijdens het uitvoeren.
- **`>>` met tekst die spaties bevat** — `std::cin >> name` stopt bij de eerste spatie; de rest blijft in de invoer en verpest de volgende `>>`.
- **Functie gebruiken vóór de definitie** — Een functie die onder `main` staat (en niet vooraf gedeclareerd is) is op het moment van aanroepen onbekend: compileerfout.
- **Niet-geïnitialiseerde variabele** — `int c;` bevat een rommelwaarde tot je er iets aan toekent.

### [Hoofdstuk 3 – Variables and data types](#h03)

- **Niet-geïnitialiseerde variabelen** — `int x;` bevat een garbage value.
- **Octale voorloopnul** — `017` is octaal en dus 15, niet 17.
- **Stille narrowing bij () en =** — `int x(2.9);` en `int x = 2.9;` geven stil `2`.
- **Vergeten float-suffix of foute suffix** — Zonder `f` is een kommaliteral een `double`.
- **Precisie van float overschatten** — Een `float` heeft maar ~7 significante cijfers (inclusief die vóór de komma).
- **Negatieve waarde in unsigned** — Met accolades geeft `unsigned int x{-5};` een fout, maar een latere toekenning `x = -22;` (ook via `auto` met `u`-suffix) compileert zonder fout en geeft een enorm getal (4294967274).
- **auto verbergt het type** — Bij `auto` zie je het type niet in de declaratie.
- **nan en inf negeren** — Delen door 0.0 crasht niet, maar geeft `inf` of `nan`.
- **Modifiers op kommagetallen** — `short`, `long`, `unsigned` enz.
- **char zonder enkele quotes** — `char c{a};` zoekt een variabele `a`; je bedoelt `'a'`.
- **Groottes zijn platformafhankelijk** — `long` is 4 bytes op Windows maar 8 op 64-bit Linux; `long double` kan 8, 12 of 16 bytes zijn.

### [Hoofdstuk 4 – Operations on data](#h04)

- **Integer-deling gooit de fractie weg** — `7 / 2` is `3`, niet `3.5`.
- **Modulus op floating-point getallen** — `%` werkt alleen voor integral types; `7.5 % 2` compileert niet.
- **`=` in plaats van `==`** — `=` kent toe, `==` vergelijkt.
- **Vergelijking zonder haakjes in `std::cout`** — `std::cout << a < b;` geeft een cryptische compilerfout omdat `<<` sterker bindt dan `<`.
- **Postfix vs. prefix verwarren** — `std::cout << x++;` print de **oude** waarde; `std::cout << ++x;` print de **nieuwe**.
- **Sticky manipulators vergeten te resetten** — `std::hex`, `std::oct`, `std::left`, `std::setfill`, `std::setprecision`, `std::fixed`, `std::boolalpha`, `std::showpos`, ...
- **Te veel precisie vragen** — `std::setprecision(50)` op een `double` levert cijfers op die niet bij je getal horen ("garbage").
- **`std::fixed` maakt kleine getallen nul** — `1.34e-10` met `std::fixed` wordt `0.000000`.
- **`numeric_limits<float>::min()` is niet het meest negatieve getal** — Voor floating-point types is `min()` het **kleinste positieve** getal.
- **Kleine integer-types worden `int` bij rekenen** — `short + short` en `char + char` geven een `int`.

### [Hoofdstuk 5 – Flow control](#h05)

- **`=` in plaats van `==`** — `if (tool = pen)` is een toekenning, geen vergelijking.
- **`break` vergeten in een switch** — Zonder `break` vallen alle volgende cases (inclusief `default`) mee door.
- **Copy-paste-fouten tussen cases** — De docent liet het zelf zien: bij `case ellipse` stond nog de tekst van `pen`.
- **switch op een niet-integraal type** — `switch (name)` met een `std::string` (of een `double`) compileert niet: "expression must have an integral or enum type".
- **Niet-gedeclareerde namen** — Een case of vergelijking met een naam die nergens gedeclareerd is (`bird`) geeft "was not declared in this scope".
- **Incompatibele opties in de ternary operator** — Beide opties moeten van hetzelfde type zijn of naar elkaar converteerbaar: `int` en `const char*` gaan niet samen.
- **Verrassend resultaattype van `? :`** — Bij `a : 22.5f` is het resultaat `float`, niet `int`.
- **Denken dat meerdere takken van een keten draaien** — In een `if` / `else if` / `else`-keten wordt hoogstens één tak uitgevoerd: de eerste die slaagt.

### [Hoofdstuk 6 – Loops](#h06)

- **Iterator gebruiken buiten de scope van de for-loop** — Een iterator die in de kop van de `for`-loop gedeclareerd is, bestaat na de sluitende accolade niet meer → compilerfout `'i' was not declared in this scope`.
- **Hardgecodeerde lusgrenzen** — `i < 10` op tien plekken in je code betekent tien plekken om aan te passen (en te vergeten).
- **Incrementatie vergeten in while en do-while** — Bij `while` en `do-while` staat de incrementatie niet in de kop.
- **Do-while draait altijd minstens één keer** — De test komt pas na de body.
- **Komma's in plaats van puntkomma's in de for-kop** — De drie delen van een `for`-kop worden gescheiden door `;`.
- **Puntkomma na while(...) van een do-while vergeten** — `} while (i < COUNT);` eindigt met een puntkomma; zonder krijg je een compilerfout.
- **Accolades weglaten bij meer dan één statement** — Zonder accolades hoort alleen het eerstvolgende statement bij de loop.
- **Negatieve waarden in size_t** — `size_t` is unsigned.

### [Hoofdstuk 7 – Arrays](#h07)

- **Tellen vanaf 1 in plaats van 0** — Het eerste element is `arr[0]`, het laatste `arr[N-1]`.
- **Ongeïnitialiseerde arrays gebruiken** — `int scores[10];` bevat junk data.
- **Hardgecodeerde grootte in loops** — Verandert het aantal elementen, dan klopt `i < 10` niet meer: je mist elementen of leest buiten de grenzen.
- **Grootte weglaten zonder initializer** — `int arr[];` compileert niet: de compiler weet niet hoeveel ruimte hij moet reserveren.
- **Een `const` array proberen te wijzigen** — `birds[2] = 8;` op een `const` array geeft een compilerfout ("expression must be a modifiable lvalue").
- **Dezelfde naam twee keer declareren** — Bij het experimenteren in één `main` krijg je "redeclaration of 'scores'".
- **Character array zonder null terminator printen** — `char msg[] {'H','e','l','l','o'};` heeft grootte 5 en geen `'\0'`; `std::cout << msg` print door tot het ergens een 0-byte vindt, met garbage of erger als gevolg.
- **Te weinig ruimte voor de terminator** — `char msg[5] {"Hello"};` of 6 tekens in `char msg[5]` geeft "too many initializers": "Hello" heeft 6 plekken nodig (5 tekens + `'\0'`).
- **Verwachten dat `std::cout << intArray` de elementen print** — Alleen `char`-arrays worden als tekst geprint; bij andere arrays zie je een adres.
- **Buiten de grenzen lezen of schrijven** — C++ controleert het niet.
- **Index kwijt in een range-based for loop** — `for (auto i : scores)` geeft waarden, geen indexen.

### [Hoofdstuk 8 – Pointers](#h08)

- **Meerdere declaraties op één regel** — `int* a {}, b {};` maakt alleen `a` een pointer; `b` is een gewone `int`.
- **Pointers van verschillende types door elkaar toewijzen** — Een `int*` kan geen adres van een `double` bevatten: compilerfout.
- **Niet-geïnitialiseerde pointer gebruiken** — Een pointer zonder initializer bevat een junkadres.
- **nullptr dereferencen** — `*p = 33;` terwijl `p == nullptr` is undefined behavior.
- **`char*` naar een string literal** — Een string literal is een array van `const char`.
- **Een `char*` dereferencen in plaats van printen** — `std::cout << p_message` print de hele string, `std::cout << *p_message` slechts het eerste teken.
- **Geheugen gebruiken na `delete`** — Na `delete` is het geheugen niet meer van jou.
- **Twee keer `delete`** — Hetzelfde geheugen twee keer vrijgeven laat het programma afbreken.
- **Meerdere pointers naar hetzelfde geheugen** — Na `delete` via de ene pointer wijst de andere nog steeds naar vrijgegeven geheugen.
- **Memory leaks** — De pointer overschrijven, opnieuw `new` op dezelfde pointer doen zonder eerst `delete`, of een scope verlaten waarin de enige pointer leefde: het geheugen is dan onbereikbaar.
- **`delete` in plaats van `delete[]`** — Geheugen dat met `new[]` aangevraagd is, geef je vrij met `delete[]`.
- **`std::size` en range-based `for` op een dynamische array** — Een dynamische array is via een pointer bereikbaar en weet zijn eigen grootte niet.
- **Niet controleren of `new` slaagt** — Zeldzaam, maar zonder `try`/`catch` of `std::nothrow` crasht het programma als de heap op is.

### [Hoofdstuk 9 – References](#h09)

- **Denken dat `ref = andere;` de reference opnieuw bindt** — `ref_double_value = some_other_double_value;` kopieert alleen de waarde naar het object waar de reference al naar verwees.
- **Reference declareren zonder initialisatie** — `int& r;` is een compilerfout.
- **Een niet-const reference aan een letterlijke waarde binden** — `int& r{33};` werkt niet: een niet-`const` reference moet aan een lvalue (een bestaande variabele) gebonden worden ("initial value of reference to non-const must be an lvalue").
- **`&` in declaratie verwarren met address-of** — In `int& r{x};` betekent `&` "reference naar".
- **`*` vergeten bij een pointer** — `std::cout << p_double_value;` print het adres, niet de waarde.
- **Denken dat `const` op de originele variabele slaat** — `const int& ref_age{age};` maakt `age` niet `const`.
- **`const int& const` schrijven** — Bestaat niet; een reference is al "niet herbindbaar".

### [Hoofdstuk 10 – Character manipulation and strings](#h10)

- **Verwachten dat `<cctype>`-functies `1` teruggeven** — De functies geven een `int` terug die alleen "niet-nul" of "nul" is.
- **Vertrouwen op indirecte includes** — Bij de docent compileert `std::isalnum` zonder `<cctype>`, omdat `<iostream>` het meebrengt.
- **`int` gebruiken voor tellers en groottes** — Een aantal karakters is nooit negatief.
- **`sizeof` gebruiken als stringlengte** — `sizeof` op een array telt de `'\0'` mee (17 i.p.v.
- **Vergeten dat `strlen` de `'\0'` niet telt** — Wie een buffer maakt met `new char[std::strlen(src)]` en daarin kopieert, schrijft één byte te veel.
- **Een array opnieuw willen toewijzen** — `char arr[] {"Alabama"}; arr = "Blabama";` geeft een compilerfout.
- **De `strchr`-loop die nooit verspringt** — Als je het resultaat van `strchr` niet terugzet in de zoekpositie (en `str` maar met één ophoogt), vind je dezelfde treffer keer op keer: 25 iteraties in plaats van 2.
- **De oorspronkelijke pointer verschuiven** — Als je `str` zelf ophoogt tijdens het zoeken, ben je het begin van je bericht kwijt.
- **`strcat`/`strcpy` naar een te kleine bestemming** — `strcat` en `strcpy` controleren niets.
- **Een `const` bestemming meegeven** — De bestemming van `strcat`/`strcpy` moet wijzigbaar zijn:
- **`strncpy` laat de null-terminator weg** — Als de bron minstens `count` karakters heeft, kopieert `strncpy` **geen** `'\0'`.
- **Exacte waarde van `strcmp` gebruiken** — `-1`, `0`, `1` is wat de docent ziet, maar de standaard belooft alleen negatief/nul/positief.
- **`{}` versus `()` bij `std::string(4, 'e')`** — 

### [Hoofdstuk 11 – Functions](#h11)

- **Return type vergeten** — Een functie zonder return type is in C++ een compilerfout.
- **Een functie gebruiken vóór de declaratie** — Als de aanroep boven de declaratie staat, kent de compiler de functie nog niet (`'max' was not declared in this scope`).
- **Alleen een declaratie, geen definitie** — Dit geeft geen compilerfout maar een **linkerfout**: `undefined reference to ...` (GCC, herkenbaar aan `ld returned 1 exit status`) of `unresolved external symbol` (MSVC).
- **Dubbele definities (ODR)** — In één bestand: *redefinition* (compilerfout).
- **Denken dat return type of parameternamen de signature uniek maken** — `int max(int, int)` en `void max(int c, int d)` hebben dezelfde signature.
- **Een variabele dezelfde naam geven als een functie** — `int max = max(34, 56);` verwart de compiler, omdat de lokale variabele `max` de functie verbergt.
- **Ongemerkte impliciete conversies** — Een `double` doorgeven aan een `int`-parameter gooit de decimalen weg, zonder foutmelding (met `-Wall -Wextra` zelfs zonder waarschuwing).
- **Verwachten dat pass by value het origineel wijzigt** — Bij `void f(int x)` werk je op een kopie; wijzigingen zijn na de aanroep weg.
- **Dereferencen vergeten bij pass by pointer** — `++age;` op een `int*` verhoogt de **pointer**, niet de waarde, en `std::cout << age` print een adres.
- **Postfix in plaats van prefix** — `a++ * ++b` gebruikt de oude waarde van `a`.
- **Eigen header met punthaken includen** — Gebruik `#include "compare.h"` voor je eigen headers en `#include <iostream>` voor standaardheaders.

### [Hoofdstuk 12 – Getting things out of functions](#h12)

- **Output parameter by value doorgeven** — Vergeet je de `&` bij de output parameter (`void max_int(int a, int b, int output)`), dan schrijft de functie in een **kopie**.
- **Const op een output parameter** — Een output parameter met `const` (`const std::string& output`) kan niet beschreven worden: de toekenning geeft een compilerfout.
- **Pointer-output: dereferencen of adres vergeten** — Bij een pointer-parameter moet je in de functie `*output = ...` schrijven, niet `output = ...` (dan wijzig je alleen de lokale pointer-kopie, of krijg je een typefout).
- **Lokale variabele en variabele in main door elkaar halen** — `result` in `sum` en `result` in `main` hebben dezelfde naam, maar het zijn **verschillende variabelen** in verschillende scopes.
- **Ervan uitgaan dat return by value altijd kopieert** — Bij `add_strings` blijkt het adres binnen en buiten gelijk.
- **Een reference naar een lokale variabele teruggeven** — De docent benadrukt dat de compiler-optimalisatie *geen* echte return by reference is, omdat een reference naar een lokale variabele na de return naar een dode variabele zou wijzen.
- **Labels in de debug-output niet aanpassen** — Klein maar herkenbaar: de docent kopieert de print-regel van "in" en vergeet twee keer "In" te veranderen in "Out".

### [Hoofdstuk 13 – Function overloading](#h13)

- **Alleen het return type veranderen** — `int max(int, int)` en `double max(int, int)` naast elkaar is een compilerfout.
- **Volgorde veranderen bij gelijke types helpt niet** — 
- **Ambigue aanroepen** — Oplossing: zorg dat de argumenten exact passen (bv.
- **Verwachten dat de "logische" overload wordt gekozen bij literals** — De literal `5.4` is een `double`, `5.4f` een `float`, `4` een `int` en `"Hello"` een `const char`-array (geen `std::string` of `std::string_view`!).
- **Ongebruikte parameters in een "demo-overload"** — 

### [Hoofdstuk 14 – Lambda functions](#h14)

- **Lambda declareren maar niet aanroepen** — Een lambda-definitie alleen (`[](){ ...
- **Puntkomma vergeten** — De lambda staat in een statement; na de afsluitende accolade (of na de aanroephaakjes) is een `;` nodig, anders krijg je een compilerfout.
- **Argumenten vergeten bij een lambda met parameters** — Een lambda met parameters aanroepen met `()` geeft een compilerfout, precies zoals bij een gewone functie.
- **Returnwaarde niet opvangen** — `[](double a, double b){ return a + b; }(10, 20);` berekent de som, maar je ziet niets: de returnwaarde wordt weggegooid.
- **Ongemerkte impliciete conversies** — Int-argumenten worden stilletjes naar double-parameters omgezet, en met `-> int` wordt een double-resultaat afgekapt (`6.9 + 3.5` wordt `10`, niet `10.4`).
- **Buitenste variabele gebruiken zonder capture** — Een lege capture list geeft geen toegang tot lokale variabelen van de omringende functie: `error: 'a' is not captured`.
- **Verwachten dat een by-value capture meeverandert** — Met `[c]` of `[=]` is de lambda-variabele een kopie, gemaakt bij het aanmaken van de lambda.
- **Onbedoelde bijwerkingen met `[&]`** — Met capture by reference werken wijzigingen in beide richtingen door.

### [Hoofdstuk 15 – Function templates](#h15)

- **Denken dat een template echte code is** — Een template wordt pas gecompileerd tot een functie als je hem aanroept.
- **Operaties die het type niet ondersteunt** — `multiply` met `std::string` → *no match for 'operator*'*.
- **Argumenten van verschillende types bij één `T`** — `maximum(5.5, 7)` → *deduced conflicting types for parameter 'T'*.
- **Resultaat in een te klein type opslaan** — `int result = maximum(5.5, 78.7);` geeft 78.
- **Pointers vergelijken in plaats van waarden** — `maximum(px, py)` en `maximum("wild", "animal")` vergelijken adressen.
- **By-value- en by-reference-template tegelijk** — `T maximum(T, T)` naast `const T& maximum(const T&, const T&)` → *call of overloaded ...
- **Via een const reference wijzigen** — `++a` in een functie met `const T& a` → *increment of read-only reference 'a'*.
- **Impliciete conversie die niet bestaat** — `maximum<double>(a, e)` met `e` een `std::string` → compilerfout: string kan niet naar `double`.

### [Hoofdstuk 16 – C++20 concepts](#h16)

- **Simple requirement controleert geen waarde** — `requires(T t) { sizeof(T) < 4; }` is voor elk type voldaan, omdat alleen de syntax gecontroleerd wordt.
- **Integral promotion en een beperkt return-type** — Bij `TinyType auto add(TinyType auto a, TinyType auto b)` moet ook het afgeleide return-type aan het concept voldoen.
- **`<concepts>` en `<type_traits>` vergeten** — Zonder `#include <concepts>` kent de compiler `std::integral` en `std::floating_point` niet.
- **Vage foutmelding in de editor** — VS Code (IntelliSense) zegt alleen "no instance of function template matches the argument list" en noemt het concept niet.
- **Puntkomma's vergeten** — Een concept-definitie eindigt met een puntkomma (`concept MyIntegral = std::is_integral_v<T>;`) en elke requirement binnen de accolades ook.
- **Een ongeschikt testtype kiezen** — Om `std::integral<T> && TinyType<T>` te testen is `double` een slecht voorbeeld: het faalt al op `std::integral`.
- **`char` printen met `std::cout`** — Een functie die `char` teruggeeft, print een teken, geen getal (`char` 30 is een onzichtbaar stuurteken).

### [Hoofdstuk 17 – Classes](#h17)

- **Puntkomma na de class vergeten** — `class Cylinder { ...
- **Members zijn standaard private** — Zonder `public:` is alles in een `class` private, inclusief methods en constructors.
- **Constructor (of setters) per ongeluk private** — Een constructor in de `private`-sectie maakt het onmogelijk om objecten van buitenaf te bouwen.
- **Eigen constructor schrijven en de default constructor kwijtraken** — Zodra je één constructor schrijft, genereert de compiler geen default constructor meer.
- **Haakjes vergeten bij een getter** — `p_cylinder2->get_base_radius` zonder `()` is geen functieaanroep en geeft een compilerfout.
- **Dot-notatie op een pointer** — `p_cylinder1.volume()` werkt niet.
- **Header zonder include guard** — Een header die via meerdere wegen in hetzelfde `.cpp`-bestand terechtkomt, geeft *redefinition*-fouten.
- **Definitie zowel in header als in `.cpp`** — Na het verplaatsen van een body naar `cylinder.cpp` moet de body uit de header weg, anders heb je twee definities (*redefinition* / *multiple definition*).
- **`new` zonder `delete`** — Een object dat je met `new` maakt, wordt nooit automatisch opgeruimd: geen destructor-aanroep, geheugenlek.
- **Object met raw pointer-member by value doorgeven** — De standaardkopie kopieert alleen het adres.
- **Parameter met dezelfde naam als een member** — `name = name;` compileert, maar wijst de parameter aan zichzelf toe en verandert de member niet.
- **`return this` bij een reference-return type** — Als de setter `Dog&` teruggeeft, moet je `return *this;` schrijven.
- **`sizeof` verkeerd interpreteren** — `sizeof` telt geen functies en niet de data waarnaar een pointer wijst.

### [Hoofdstuk 18 – Inheritance](#h18)

- **Private van de basis betekent: nooit rechtstreeks bereikbaar** — Welke inheritance je ook kiest, private members van de basisklasse zijn niet direct te gebruiken in afgeleide klassen of hun friends.
- **"Blijft private" in de tabel is misleidend** — Bij public inheritance "blijft private private", maar dan private **aan de basisklasse**, niet private aan de afgeleide klasse.
- **Protected/private inheritance sluit ook de oorspronkelijk public members af** — Na `class Nurse : protected Person` is `nurse1.m_full_name` niet meer bruikbaar in `main`, hoewel het in `Person` public was.
- **Private inheritance blokkeert de hele rest van de keten** — Een klasse die van een privaat erfende klasse afleidt, kan niets van de oorspronkelijke basis gebruiken, zelfs niet in een friend-functie.
- **`using` kan niets terughalen wat al private is** — `using Person::m_address;` mislukt als `m_address` private is in `Person`.
- **Basis-members initialiseren in de initializer list of body van de afgeleide klasse** — Een initializer list mag alleen eigen members bevatten (`does not have any field named ...`).
- **Copy constructor die het basisdeel vergeet** — Als je in een zelfgeschreven copy constructor geen `Base(source)` aanroept, gebruikt de compiler de **default** constructor van de basis.
- **Geen default constructor in de basisklasse** — Als een afgeleide constructor geen basisconstructor aanroept, zoekt de compiler de default constructor van de basis.
- **Geërfde constructors initialiseren alleen het basisdeel** — Met `using Person::Person;` lijkt `Engineer("Daniel Gray", 23, "...")` een volwaardige engineer-constructor, maar `m_contract_count` krijgt alleen zijn default-waarde.
- **Gedeclareerde maar niet gedefinieerde destructor** — `~Player();` in de header zonder definitie in de `.cpp` geeft een linkerfout (`undefined reference to ...::~Player()`).
- **Non-const reference-parameter en letterlijke tekst** — `Player(std::string& game)` accepteert geen `"Basketball"` (tijdelijk object).
- **Name hiding verwarren met overriding** — Een member met dezelfde naam in de afgeleide klasse verbergt het basismember.

### [Hoofdstuk 19 – Polymorphism](#h19)

- **`virtual` vergeten → static binding** — Zonder `virtual` kiest de compiler de functie op basis van het type van de pointer of reference.
- **Polymorphism verwachten zonder pointer of reference** — `Shape s = circle1; s.draw();` is slicing: `s` *is* een `Shape`.
- **Array van references** — `Shape& shapes[]{...}` compileert niet; references zijn niet left-assignable.
- **Typfout in een override zonder `override`** — `void Draw() const` in plaats van `draw()` maakt een nieuwe functie, en de base-versie wordt gewoon aangeroepen.
- **Eén overload overriden verbergt de andere** — Overschrijf je in een derived klasse één overload van `draw`, dan zijn alle andere `draw`-overloads van de base class verborgen voor die klasse en haar afstammelingen.
- **Nieuwe functie op een lager niveau via een base pointer aanroepen** — Functies die enkel in een derived klasse bestaan (nieuwe overload, niet-virtual getter zoals `get_x_rad()`) zijn via een `Shape*` onbekend: *"class Shape has no member named ..."*.
- **Gedeelde static member** — Een static member van de base class wordt gedeeld met derived klassen: `Ellipse::m_count` is dan gewoon `Shape::m_count`.
- **Default arguments bij virtual functions** — De body komt van het dynamic type, maar de defaults van het statische type: via een `Base*` krijg je `Derived::add()` met de defaults van `Base` (resultaat 12 in plaats van 22).
- **Geen virtual destructor** — `delete base_ptr;` op een derived object zonder virtual destructor is undefined behavior.
- **Resultaat van `dynamic_cast` niet controleren** — Een mislukte pointer-cast geeft `nullptr`; zonder `if`-controle crasht je programma.
- **Virtual function aanroepen in constructor of destructor** — Je krijgt altijd de versie van de klasse waarvan de constructor/destructor op dat moment loopt (static-binding-resultaat), nooit de override van een derived klasse.
- **Niet alle pure virtual functions overriden** — Dan is de derived klasse zelf abstract, en `new Circle` of `Point p1(10, 20);` faalt, ook al heb je zelf geen `= 0` geschreven.
- **`delete` vergeten** — In meerdere demo's vergat de docent `delete` voor objecten die met `new` gemaakt waren: dan verschijnen er geen destructor-meldingen en lekt geheugen.

---

<a id="samenhang"></a>

## Samenhang

Hoe de onderwerpen op elkaar voortbouwen. Een pijl `A → B` betekent: B gebruikt of verdiept A.

```text
h01 Tools ──► h02 Eerste programma (I/O, statements, functions)
                 │
                 ▼
h03 Types & variabelen ──► h04 Operaties (rekenen, vergelijken, formatteren)
                 │                    │
                 ▼                    ▼
           h07 Arrays ◄──── h05 Flow control ──► h06 Loops
                 │
                 ▼
           h08 Pointers & dynamisch geheugen ──► h09 References
                 │                                   │
                 ▼                                   │
           h10 Characters & strings (C-string = char-array + pointer)
                 │                                   │
                 ▼                                   ▼
           h11 Functions (pass by value / pointer / reference) ──► h12 Output params & return
                 │
                 ├──► h13 Overloading ──► h15 Function templates ──► h16 C++20 concepts
                 └──► h14 Lambdas
                 │
                 ▼
           h17 Classes (members = variabelen, member functions = functions, this = pointer)
                 │
                 ▼
           h18 Inheritance ──► h19 Polymorphism (virtual, override, abstracte classes)
```

### Belangrijkste verbanden

- **Types → alles.** De fundamentele types uit [h03](#h03) en hun grootte (`sizeof`) komen terug bij arrays ([h07](#h07)), pointer-aritmetiek en dynamische allocatie ([h08](#h08)), templates ([h15](#h15)) en de grootte van objecten ([h17](#h17), [h19](#h19)).
- **Flow control + arrays → algoritmen.** `if`/`switch` ([h05](#h05)) en loops ([h06](#h06)) zijn de gereedschappen om over arrays ([h07](#h07)) en strings ([h10](#h10)) te itereren.
- **Arrays → pointers → strings.** Een arraynaam gedraagt zich als een pointer naar het eerste element; een C-string is een `char`-array met `'\0'`. Daarom komen pointers ([h08](#h08)) vóór C-string-functies ([h10](#h10)), en `std::string` als veiliger alternatief.
- **Pointers & references → functions.** Pass by pointer en pass by reference ([h11](#h11)) en output parameters ([h12](#h12)) zijn alleen te begrijpen met [h08](#h08) en [h09](#h09). Hetzelfde geldt voor `const T&`-parameters bij templates ([h15](#h15)).
- **Functions → overloading → templates → concepts.** Overloading ([h13](#h13)) schrijft dezelfde function meerdere keren voor verschillende types; templates ([h15](#h15)) laten de compiler dat doen; concepts ([h16](#h16)) beperken welke types een template mag accepteren.
- **Functions → lambdas.** Lambdas ([h14](#h14)) zijn naamloze functions die variabelen uit hun omgeving kunnen capturen (by value of by reference: opnieuw [h09](#h09)).
- **Alles → classes.** Een class ([h17](#h17)) bundelt variabelen en functions; constructors en destructors regelen de levensduur, wat terugkoppelt naar `new`/`delete` ([h08](#h08)); de `this`-pointer is een pointer; meerdere bestanden volgen het compilatiemodel uit [h11](#h11).
- **Classes → inheritance → polymorphism.** Inheritance ([h18](#h18)) hergebruikt classes en introduceert `protected` en de volgorde van constructor-/destructoraanroepen. Polymorphism ([h19](#h19)) bouwt daarop: via een basis-pointer of -reference wordt met `virtual` de juiste afgeleide function aangeroepen; slicing laat zien waarom je daarvoor pointers/references ([h08](#h08)/[h09](#h09)) nodig hebt.
