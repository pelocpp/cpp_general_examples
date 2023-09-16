# Beispiel: Klassen-Template für einen Taschenrechner

---

[Zurück](../../../Readme.md)

---

In dieser Fallstudie geht es darum, wesentliche Techniken der generischen Programmierung
an einem Beispiel in der Praxis aufzuzeigen.
Zu diesem Zweck betrachten wir die Funktionalität eines Taschenrechners und
demonstrieren folgende Template-Techniken:

  * #### Klassen-Template definieren
  * #### Erzeugung von Objekten eines Klassen-Templates
  * #### Klassen-Templates mit mehreren Parametern
  * #### Definition von Methoden eines Klassen-Templates
  * #### Eine Methode eines Klassen-Templates überschreiben
  * #### Partielle und explizite Template Spezialisierung
  * #### Member Function Templates
  * #### Klassen-Templates und Non-Type Parameter
  * #### Default-Werte für Template-Parameter

---

Grob skizziert könnte der Taschenrechner folgende (öffentliche) Schnittstelle haben:

```cpp
template <typename T>
class Calculator
{
public:
    // arithmetic methods
    T add(T x, T y);
    T sub(T x, T y);
    T mul(T x, T y);
    T div(T x, T y);

    // memory methods
    void memoryStore(T x);
    void memoryClear();
    T memoryRecall();
    void memoryAdd(T x);
    void memorySub(T x);

    // some more functions
    T NThPower(T x);
    T Inverse(T x);
};
```

Realisieren Sie auf dieser Grundlage die Methoden des Templates.

---

**Einige Hinweise zur Realisierung**:

Das Feature &ldquo;*Eine Methode eines Klassen-Templates überschreiben*&rdquo; können wir am Beispiel
der ganzzahligen Division betrachten: Per C/C++-Sprachdefinition schneidet die ganzzahlige Division
einen &ndash; möglicherweise vorhandenen &ndash; Rest ab bzw. verwirft ihn.
Das Ergebnis des Werts `5/7` ist folglich `0` und nicht `1`.

Das könnte man auch anders gestalten:
Spezialisieren bzw. überschreiben Sie die Divisions-Methode des Taschenrechner Klassen-Templates
für die Datentypen `int` und `long` so,
dass die ganzzahlige Division eine Rundung vornimmt. Somit würde `5/7` das Ergebnis `1` liefern.

---

Die **partielle** Spezialisierung können wir ganz allgemein für einen Datentyp `T` betrachten,
und zwar für den Fall, dass wir es mit Zeigerwerten zu tun haben. Betrachten Sie hierzu
folgendes Anwendungsbeispiel:

```cpp
Calculator<int*> intCalc;
std::unique_ptr<int> ip1 = std::make_unique<int>(1);
std::unique_ptr<int> ip2 = std::make_unique<int>(2);
std::unique_ptr<int> ivalue = intCalc.add(ip1, ip2);
std::cout << *ip1 << " + " << *ip2 << " = " << *ivalue << std::endl;
```

---

Für eine **explizite** Spezialisierung (&ldquo;**full specialization**&rdquo;) benötigen wir eine Klasse,
die keine der vier arithmetischen Operatoren (`+`, `-`, `*` und `/`) unterstützt.
Wir erinnern uns an unsere Schulzeiten und hier im Speziellen an die Bruchrechnung.
Im Begleitmaterial ist eine Klasse `Fraction` beigefügt. 
Spezialieren Sie Ihre Realisierung des Taschenrechner Klassen-Templates für die Klasse `Fraction`.

---

Das Feature &ldquo;**Member Function Templates**&rdquo; demonstrieren wir am Beispiel
der Potenzfunktion. Die *n*-te Potenz ist eine Operation, bei der eine Zahl *n*-mal
mit sich multipliziert wird. Dazu benötigen wir den Wert *n*:
Man könnte diesen als Paramter der Potenzfunktion definieren,
oder aber als *Non-Type Template Parameter* der Potenzfunktion.
Der zweite Weg führt uns zu einer Realisierung der Potenzfunktion
als &ldquo;*Member Function Template*&rdquo;.

---

[Zurück](../../../Readme.md)

---
