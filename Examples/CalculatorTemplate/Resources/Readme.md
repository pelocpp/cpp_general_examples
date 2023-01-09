# Beispiel: Ein Taschenrechner Klassen-Templates

---

In dieser Fallstudie geht es darum, wesentliche Techniken der generischen Programmierung
an einem Beispiel in der Praxis aufzuzeigen.

Zu diesem Zweck betrachten wir die Funktionalit�t eines Taschenrechners und
demonstrieren folgende Template-Techniken:

  * #### [Klassen-Templates definieren](#Definition-eines-Klassen-Templates)
  * #### [Erzeugung von Objekten eines Klassen-Templates](#Objekte-aus-Klassen-Templates-erzeugen)
  * #### [Klassen-Templates mit mehreren Parametern](#Klassen-Templates-mit-mehreren-formalen-Datentypen)
  * #### [Definition von Methoden eines Klassen-Templates](#Definition-von-Methoden-von-Klassen-Templates)
  * #### [Eine Methode eines Klassen-Templates �berschreiben](#Methoden-eines-Klassen-Templates-spezialisieren)
  * #### [Member Function Templates (kurz: Member Templates)](#Member-Function-Templates)
  * #### [Klassen-Templates und Non-Type Parameter](#Klassen-Templates-mit-Non-Type-Parametern)
  * #### [Ein Template mit Template-Parametern](#Template-Template-Parameter)
  * #### [Default-Werte f�r Template-Parameter](#Default-Template-Parameter)

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
    T NThRoot ();
    T NThPower(T x);
    T Inverse(T x);
};
```

---

Einige Hinweise zur Realisierung:

Das Feature &ldquo;Member Function Template&rdquo; k�nnen wir am Beispiel
der ganzzahligen Division betrachten: Per C/C++-Sprachdefinition schneidet die ganzzahlige Division
einen &ndash; m�glicherweise vorhandenen &ndash; Rest ab bzw. verwirft ihn.
Das Ergbnis des Werts `5/7` ist folgich `0` und damit nicht `1`.

Das k�nnte man auch anders gestalten:
Spezialisieren bzw. �berschreiben Sie die Divisions-Methode des Taschenrechner Klassen-Templates so,
dass die ganzzahligen Division eine Rundung vornimmt. Somit w�rde `5/7` das Ergebnis `1` haben.

---

Die partielle Spezialisierung k�nnen wir ganz allgemein f�r den Datentyp `T` betrachten,
und zwar f�r den Fall, dass wir es mit Zeigerwerten zu tun haben:

```cpp
Calculator<int*> intCalc;
auto ip1 = std::make_unique<int>(1);
auto ip2 = std::make_unique<int>(2);
std::unique_ptr<int> ivalue = intCalc.add(ip1, ip2);
std::cout << *ip1 << " + " << *ip2 << " = " << *ivalue << std::endl;
```

---

F�r eine explizite Spezialisierung (&ldquo;Full Specialization&rdquo;) ben�tigen wir eine Klasse,
die in der STL am besten nicht vorhanden ist und die keine der vier arithmetischen Operatoren (+, -, * und /*) besitzt.
Wir erinnern uns an unsere Schulzeiten und hier im Speziellen an die Bruchrechnung.
Im Begleitmaterial ist eine Klasse `Fraction` beigef�gt. 
Spezialieren Sie das Klassentemplate f�r die Klasse `Fraction`.


