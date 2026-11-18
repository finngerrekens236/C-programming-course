# Codeverificatie

Compiler: g++ 16.2.0 (MSYS2 UCRT64, Rev4). Commando per voorbeeld: `g++ -std=c++20 -Wall -Wextra main.cpp [extra .cpp] -o a.exe`, daarna uitvoeren (timeout 10 s) en stdout+stderr vergelijken met het direct volgende ```text-blok (alleen trailing whitespace genormaliseerd).

Legenda: **voorbeelden** = programma's met `main` (incl. uitwerkingen van oefeningen) · **geslaagd** = output exact gelijk · **zonder vergelijking** = gecompileerd en gedraaid, output niet vergeleken (adressen, platformafhankelijke `sizeof`, of geen output-blok) · **bewust fout** = gemarkeerd met `// ❌ bewust fout`, overgeslagen · **hulpbestanden** = headers/.cpp voor voorbeelden met meerdere bestanden · **fragmenten** = syntaxfragmenten in ```c++ zonder `main`, niet gecompileerd · **gecorrigeerd** = wat tijdens het schrijven na een mislukte check is aangepast.

| h | voorbeelden | geslaagd | zonder vergelijking | bewust fout | hulpbestanden | fragmenten | FAIL | gecorrigeerd |
|---|---|---|---|---|---|---|---|---|
| h01 | 8 | 8 | 0 | 0 | 1 | 0 | 0 | — |
| h02 | 21 | 17 | 0 | 4 | 0 | 0 | 0 | — |
| h03 | 22 | 15 | 4 | 3 | 0 | 0 | 0 | — |
| h04 | 23 | 22 | 0 | 1 | 0 | 0 | 0 | 1 tijdlink |
| h05 | 21 | 18 | 0 | 3 | 0 | 0 | 0 | — |
| h06 | 16 | 15 | 0 | 1 | 0 | 0 | 0 | — |
| h07 | 23 | 15 | 1 | 7 | 0 | 0 | 0 | — |
| h08 | 26 | 14 | 5 | 7 | 0 | 0 | 0 | std::cerr→std::cout (volgorde stdout/stderr); new-fails-demo deterministisch gemaakt |
| h09 | 16 | 11 | 1 | 4 | 0 | 0 | 0 | — |
| h10 | 28 | 22 | 2 | 4 | 0 | 0 | 0 | 4 tijdlinks, 1 label (sizeof→strlen), 1 verwachte output |
| h11 | 21 | 15 | 3 | 3 | 9 | 0 | 0 | 2 warnings (ongebruikte parameter) verholpen |
| h12 | 11 | 8 | 2 | 1 | 0 | 0 | 0 | — |
| h13 | 10 | 8 | 0 | 2 | 0 | 0 | 0 | — |
| h14 | 19 | 16 | 2 | 1 | 0 | 0 | 0 | — |
| h15 | 18 | 12 | 3 | 3 | 0 | 0 | 0 | — |
| h16 | 19 | 13 | 0 | 6 | 0 | 15 | 0 | — |
| h17 | 27 | 21 | 3 | 3 | 4 | 0 | 0 | — |
| h18 | 21 | 15 | 0 | 6 | 0 | 7 | 0 | — |
| h19 | 33 | 20 | 2 | 11 | 0 | 7 | 0 | — |
| **totaal** | **383** | **285** | **28** | **70** | **14** | | **0** | |

## Mislukt

Geen.

Opmerking: de schrijvers hebben de bewust-foute blokken ook apart gecompileerd om te controleren dat de beschreven compilerfout echt optreedt. Warnings: alleen bewuste (fall-through in h05, ongeïnitialiseerde basis in een slechte copy constructor in h18).
