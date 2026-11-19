# OOP midterm – complexe getallen (19-11-2026)

**Status:** midterm gemaakt op do 19-11-2026, 12:00, lab B320 (verplaatst van 10:00 i.v.m. botsing met ander tentamen).
Stap 1 t/m 7 gedaan, ging goed. Code (zelfde als ingeleverd per mail aan prof. Sikora): [`main.cpp`](main.cpp).

**Thema:** complexe getallen (real + imaginary part). Zelfde opbouw als het voorbeeld van de prof
([voorbeeld van de prof, breuken](https://github.com/finngerrekens236/Object-Oriented-Programming/blob/main/oefententamens/00_Origineel_Sikora_Breuken.md)),
maar met complexe getallen in plaats van breuken en met `absolute value` (modulus, `sqrt(re² + im²)`) in plaats van decimale waarde.
Controle bij inlezen in deze opdracht: imaginary value mag niet kleiner dan 0 zijn.

Toetsvorm: mondeling/praktisch in het lab. De stappen die je niet op de midterm deed, doe je op het **final exam**.
Cijfer hangt af van hoeveel stappen je haalt en hoeveel hulp je nodig hebt.

---

## Gedaan (stap 1–7)

| Stap | Inhoud |
|---|---|
| 1 | Twee `double`-arrays (real, imaginary) |
| 2 | Inlezen met controle (imaginary ≥ 0) |
| 3 | Dynamische allocatie, gebruiker kiest grootte (`new[]`/`delete[]`) |
| 4 | Absolute value berekenen en printen |
| 5 | Commentaar |
| 6 | Functies: inlezen via **references**, berekenen via **values** + return |
| 7 | `class Complex` met `private` members, code omgebouwd naar de class |

## Nog te doen voor de volgende keer (stap 8–12)

Werk verder vanuit de stap-7-code in `main.cpp` (stap 1–6 staan erboven als commentaar). Oefenen kan ook in [`../oefententamen/`](../oefententamen/).

### Stap 8 – overloaded `operator>>` (en `<<`)
*Opdracht:* create overloaded operator `>>` and use it in the code; rework the code accordingly.
- `operator>>` vervangt de functie `readInComplexNumber()`; de controle imaginary ≥ 0 moet erin blijven.
- Signatuur: `std::istream& operator>>(std::istream& in, Complex& c)`; geef de stream terug (chaining).
- Toegang tot private members: als `friend` declareren in de class, of via de setters.
- Voor de zekerheid ook `operator<<` (`std::ostream&`) maken; in het voorbeeld van de prof hoort die bij deze stap.
- Aantekeningen: H18/H19 (`operator<<` als `friend`). `operator>>` zit **niet** in de cursus, dus apart leren.

### Stap 9 – container van array naar `std::list`
*Opdracht:* change the container from array to list.
- `#include <list>`, `std::list<Complex>`, vullen met `push_back`.
- Geen `new[]`/`delete[]` meer nodig.
- `std::list` heeft geen indexering (`[i]`), dus doorlopen met range-based for of iterators.
- Zit **niet** in de cursus (STL-containers), dus apart leren.

### Stap 10 – inherited class met boven- en ondergrens van de absolute value
*Opdracht:* make the inherited class that has upper and lower limit of the absolute value of the complex number.
- Bijvoorbeeld `class LimitedComplex : public Complex` met members voor lower/upper limit.
- Base-members zijn `private`, dus gebruik getters/setters of maak ze `protected`.
- Constructor van de derived class roept de base-constructor aan in de initializer list.
  Tip: `Complex` heeft nu geen constructor en de members worden niet geïnitialiseerd; maak er eerst een.
- Bedenk waar je de limieten controleert (bij zetten/inlezen) en wat er gebeurt als de waarde buiten de grenzen valt.
- Aantekeningen: H18 (Inheritance).

### Stap 11 – template van een `square`-functie
*Opdracht:* make a template of a square function that works for all data types.
- Function template met `template <typename T>`.
- Test met `int`, `double` **én** `Complex`. Voor `Complex` werkt het alleen als je `operator*` overloadt.
  Dat is waarschijnlijk het punt van "works for all data types".
- Aantekeningen: H15 (Function templates), optioneel H16 (concepts).

### Stap 12 – virtual functions
*Opdracht (nog niet precies uitgelegd door de prof):* iets met **virtual functions**, een class waarin/waarmee andere classes werken.
- Waarschijnlijk: polymorphism. De base class `Complex` krijgt een `virtual` functie (bv. print of controle),
  de derived class `override`t die, en je roept hem aan via een base-pointer/reference
  (bv. een `std::list<Complex*>` met zowel `Complex`- als `LimitedComplex`-objecten).
- Denk aan een `virtual` destructor in de base class.
- **Actie:** bij de volgende check-in (donderdag 10:00, lab B320) aan prof. Sikora vragen wat stap 12 precies inhoudt.
- Aantekeningen: H19 (Polymorphism: `virtual`, `override`, dynamic binding, abstract classes).

---

## Aandachtspunten uit de stap-7-code (handig voor stap 8–12)
- `realValue`/`imaginaryValue` hebben geen beginwaarde: voeg een (default) constructor toe.
- `GetAbsolute()` verandert niets, dus maak hem `const`.
- `setImaginary()` print een fout bij < 0 maar laat de waarde dan ongeïnitialiseerd.
- De code compileert zonder warnings met `g++ -std=c++20 -Wall`.
