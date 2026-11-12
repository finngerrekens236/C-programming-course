# Aantekeningen – C++ Programming Course (Beginner to Advanced)

Nederlandstalige studieaantekeningen bij de freeCodeCamp-cursus van Daniel Gakwaya
([YouTube, 31 uur](https://www.youtube.com/watch?v=8jLOx1hD3_o)). Bedoeld om C++ te leren en na te slaan zonder de video te kijken.

## Waar begin ik?

| Wil je… | Open |
|---|---|
| alles in één document lezen | [`cpp_cursus_aantekeningen.md`](cpp_cursus_aantekeningen.md) — inhoudsopgave, alle hoofdstukken, cheatsheet, begrippenlijst, valkuilen |
| één onderwerp bestuderen | een bestand in [`hoofdstukken/`](hoofdstukken/) (zelfde tekst als in het grote document) |
| zien of de code klopt | [`verificatie.md`](verificatie.md) |
| het originele (automatische) transcript nalezen | [`bron/`](bron/) |

## Inhoud van de map

```text
aantekeningen/
├── cpp_cursus_aantekeningen.md   alles samen: overzicht + h01–h19 + cheatsheet, begrippen, valkuilen, samenhang
├── hoofdstukken/h01.md … h19.md  één bestand per hoofdstuk
├── verificatie.md                resultaat van het compileren/draaien van alle codevoorbeelden
├── tools/verify.py               script om de codevoorbeelden zelf opnieuw te testen
└── bron/
    ├── transcript_volledig.md    hele transcript met [uu:mm:ss] per alinea
    ├── chunks/h01.md … h19.md    transcript per hoofdstuk (bron voor de aantekeningen)
    └── meta.json                 titel, duur, beschrijving en hoofdstukken van de video
```

## Hoofdstukken

| # | Onderwerp | Video |
|---|---|---|
| [1](hoofdstukken/h01.md) | Introductie en tools instellen (compilers, VS Code) | 0:00:00 |
| [2](hoofdstukken/h02.md) | Diving in: eerste programma, comments, errors, I/O | 1:43:01 |
| [3](hoofdstukken/h03.md) | Variables and data types | 3:00:47 |
| [4](hoofdstukken/h04.md) | Operations on data | 4:46:46 |
| [5](hoofdstukken/h05.md) | Flow control | 7:01:58 |
| [6](hoofdstukken/h06.md) | Loops | 7:53:49 |
| [7](hoofdstukken/h07.md) | Arrays | 8:47:08 |
| [8](hoofdstukken/h08.md) | Pointers en dynamisch geheugen | 9:53:23 |
| [9](hoofdstukken/h09.md) | References | 12:11:04 |
| [10](hoofdstukken/h10.md) | Characters en strings | 12:44:29 |
| [11](hoofdstukken/h11.md) | Functions | 14:12:47 |
| [12](hoofdstukken/h12.md) | Getting things out of functions | 16:03:20 |
| [13](hoofdstukken/h13.md) | Function overloading | 16:32:35 |
| [14](hoofdstukken/h14.md) | Lambda functions | 16:49:00 |
| [15](hoofdstukken/h15.md) | Function templates | 17:40:08 |
| [16](hoofdstukken/h16.md) | C++20 concepts | 19:04:31 |
| [17](hoofdstukken/h17.md) | Classes | 20:15:40 |
| [18](hoofdstukken/h18.md) | Inheritance | 22:52:43 |
| [19](hoofdstukken/h19.md) | Polymorphism | 26:21:03 |

## Hoe is elk hoofdstuk opgebouwd?

Leerdoelen → verband met eerdere hoofdstukken → uitleg per concept (met tijdlinks naar de video) →
codevoorbeelden (volledige programma's + verwachte output) → valkuilen → best practices → samenvatting →
oefeningen (uitwerking in een uitklapblok, eerst zelf proberen!).

**Markeringen in de tekst**

| Markering | Betekenis |
|---|---|
| `> 💡 Aanvulling:` | toegevoegd door de schrijver, niet door de docent behandeld (bv. modern alternatief, correctie) |
| `> ⚠️ Onduidelijk in opname:` | stuk dat in de opname/ondertitels niet goed te volgen was |
| `> ℹ️ Gereconstrueerd uit uitleg` | de code stond alleen op het scherm; nagebouwd op basis van wat de docent zegt |
| `// ❌ bewust fout:` | voorbeeld dat expres niet compileert of undefined behaviour laat zien |

## Code zelf testen

Elk ```` ```cpp ````-blok is een compleet programma. Kopieer het naar `main.cpp` in een van de oefenmappen en bouw het
met de VS Code-task (zie de [README in de hoofdmap](../README.md)), of test alles in één keer:

```bash
cd aantekeningen
python tools/verify.py hoofdstukken/h05.md      # één hoofdstuk
python tools/verify.py hoofdstukken/*.md        # alle hoofdstukken
```

Het script compileert elk voorbeeld met `g++ -std=c++20 -Wall -Wextra`, draait het en vergelijkt de output met het
` ```text `-blok eronder. Bij de laatste controle: **383 voorbeelden, 0 mislukt** (details in [`verificatie.md`](verificatie.md)).

## Kanttekeningen

- Bron is het **automatische** Engelse transcript; termen als `cout`, `std::`, `constexpr` zijn op basis van de context gecorrigeerd.
- De meeste code is **gereconstrueerd** (stond alleen op het scherm). De werking is getest, maar namen en details kunnen afwijken van wat je in de video ziet.
- Adressen in output-blokken (bv. `0x61fe14`) zijn voorbeelden; bij jou zijn ze anders.
- De cursus stopt na polymorfisme; containers als `std::vector` en de STL-algoritmen komen in deze 31 uur nauwelijks aan bod.
