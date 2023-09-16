# Beispiel: Klassen-Template f�r einen Taschenrechner

---

[Zur�ck](../../../Readme.md)

---

In dieser Fallstudie geht es darum, wesentliche Techniken der generischen Programmierung
an einem Beispiel in der Praxis aufzuzeigen.
Zu diesem Zweck betrachten wir die Funktionalit�t eines Taschenrechners und
demonstrieren folgende Template-Techniken:

  * #### Klassen-Template definieren
  * #### Erzeugung von Objekten eines Klassen-Templates
  * #### Klassen-Templates mit mehreren Parametern
  * #### Definition von Methoden eines Klassen-Templates
  * #### Eine Methode eines Klassen-Templates �berschreiben
  * #### Partielle und explizite Template Spezialisierung
  * #### Member Function Templates
  * #### Klassen-Templates und Non-Type Parameter
  * #### Default-Werte f�r Template-Parameter

---

Grob skizziert k�nnte der Taschenrechner folgende (�ffentliche) Schnittstelle haben:

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

Das Feature &ldquo;*Eine Methode eines Klassen-Templates �berschreiben*&rdquo; k�nnen wir am Beispiel
der ganzzahligen Division betrachten: Per C/C++-Sprachdefinition schneidet die ganzzahlige Division
einen &ndash; m�glicherweise vorhandenen &ndash; Rest ab bzw. verwirft ihn.
Das Ergebnis des Werts `5/7` ist folglich `0` und nicht `1`.

Das k�nnte man auch anders gestalten:
Spezialisieren bzw. �berschreiben Sie die Divisions-Methode des Taschenrechner Klassen-Templates
f�r die Datentypen `int` und `long` so,
dass die ganzzahlige Division eine Rundung vornimmt. Somit w�rde `5/7` das Ergebnis `1` liefern.

---

Die **partielle** Spezialisierung k�nnen wir ganz allgemein f�r einen Datentyp `T` betrachten,
und zwar f�r den Fall, dass wir es mit Zeigerwerten zu tun haben. Betrachten Sie hierzu
folgendes Anwendungsbeispiel:

```cpp
Calculator<int*> intCalc;
std::unique_ptr<int> ip1 = std::make_unique<int>(1);
std::unique_ptr<int> ip2 = std::make_unique<int>(2);
std::unique_ptr<int> ivalue = intCalc.add(ip1, ip2);
std::cout << *ip1 << " + " << *ip2 << " = " << *ivalue << std::endl;
```

---

F�r eine **explizite** Spezialisierung (&ldquo;**full specialization**&rdquo;) ben�tigen wir eine Klasse,
die keine der vier arithmetischen Operatoren (`+`, `-`, `*` und `/`) unterst�tzt.
Wir erinnern uns an unsere Schulzeiten und hier im Speziellen an die Bruchrechnung.
Im Begleitmaterial ist eine Klasse `Fraction` beigef�gt. 
Spezialieren Sie Ihre Realisierung des Taschenrechner Klassen-Templates f�r die Klasse `Fraction`.

---

Das Feature &ldquo;**Member Function Templates**&rdquo; demonstrieren wir am Beispiel
der Potenzfunktion. Die *n*-te Potenz ist eine Operation, bei der eine Zahl *n*-mal
mit sich multipliziert wird. Dazu ben�tigen wir den Wert *n*:
Man k�nnte diesen als Paramter der Potenzfunktion definieren,
oder aber als *Non-Type Template Parameter* der Potenzfunktion.
Der zweite Weg f�hrt uns zu einer Realisierung der Potenzfunktion
als &ldquo;*Member Function Template*&rdquo;.

---

[Zur�ck](../../../Readme.md)

---
