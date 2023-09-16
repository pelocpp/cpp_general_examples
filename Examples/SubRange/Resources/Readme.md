# Beispiel "Teilbereichsdatentyp" / Klasse `SubRange`


---

[Zurück](../../../Readme.md)

---

In diesem Beispiel werden mehrere Realisierungen einer Klasse `SubRange` betrachtet.

Welchen Sinn verfolgt diese Klasse? In der Programmiersprache Pascal gibt es einen sogenannten *TeilbereichsDatentyp*,
auch unter der Bezeichnung *Unterbereichstyp* geläufig. 
Dieser legt ein Intervall für ganze Zahlen fest. Die Werte eines Unterbereichstyps müssen stets zwischen den angegebenen Grenzen
liegen einschließlich der beiden Intervallgrenzen.

Variablen dieses Typs - zum Beispiel ganze Zahlen - dürfen den Wertebereich,
der durch das Intervall vorgegeben ist, nicht verletzen.

Syntaktisch korrekte Deklarationen eines Teilbereich-Datentyps sehen in Pascal beispielsweise so aus:

```pascal
type hundert = 1..100;
     zehn = 1..10;
```

Wir versuchen nun in mehreren Ansätzen, einen vergleichbaren Datentyp in C++ nachzuahmen.

*Hinweis*:

Beachten Sie in der Entwicklung der einzelnen Varianten von `SubRange` den Zuwachs
an Effizienz bzgl. der Überprüfung der Intervallgrenzen:

  * Variante 1: Klasse `SubRange` ohne Template-Mechanismus.
  
    Es sind bei jedem Kopier-Vorgang (Wertzuweisung, Kopier-Konstruktor) von `SubRange`-Objekten die Intervallgrenzen zu überprüfen.

    Beachte bzgl. der implementierten **Funktionalität**:
    Es können durchaus Objekte mit unterschiedlichen Intervallgrenzen einander
    zugewiesen werden, solange die Zuweisung (Kopie) "*plausibel*" ist. Sprich ein Wert (m_value) eines `SubRange`-Objekts
    kann dem Wert m_value eines anderen `SubRange`-Objekts zugewiesen werden, wenn die Zuweisung kompatibel mit den Intervallgrenzen ist.

    Lange Rede, kurzer Sinn: Es können Werte zwischen `SubRange`-Objekten mit unterschiedlichen Intervallgrenzen transportiert werden.

  * Variante 2: Klasse `SubRange` mit Template-Mechanismus.
  
    Die Intervallgrenzen wurden zu - so genannten - *Value*-Parametern des Templates.
    Die beiden Instanzvariablen `m_min` und `m_max`
    sind völlig aus dem Instanzvariablenbereich der Klasse `SubRange` verschwunden. 
    Eine Überprüfung der Intervallgrenzen wird jetzt bereits zur Übersetzungszeit vorgenommen, da pro unterschiedlichen Intervallgrenzen
    jeweils ein eigener (anonymer) Datentyp der Klasse `SubRange` vom Compiler  erzeugt wird. Auf Basis dieses Datentyps erfolgen 
    Typüberprüfungen zur Übersetzungszeit.

    Beachte bzgl. der implementierten **Funktionalität**:
    Im Vergleich zu Variante 1 haben wir an Freizügigkeit bzgl. der Zuweisung von `SubRange`-Objekten verloren.
    Es lassen sich in dieser Variante nun nur solche Werte (Objekte) kopieren, bei denen die Intervallgrenzen (sowohl obere als auch untere Grenze) übereinstimmen!

* Variante 3: Klasse `SubRange` mit Template-Mechanismus und Template-MetaProgramming

    Beachte bzgl. der implementierten **Funktionalität**:

    Es wird in der implementierten Funktionalität versucht, einen Mittelweg zwischen Variante 1 und 2 anzustreben.
    Am besten lassen sich die neuen Regeln an einem Beispiel erläutern:

    ```cpp
    SubRange<10, 20> range1(15);
    SubRange<11, 19> range2(16);
    SubRange<15, 25> range3(25);
    SubRange<10, 20> range4(16);

    std::cerr << range1 << std::endl;
    range1 = range2;
    std::cerr << range1 << std::endl;
    range1 = range3;  // Error !!!
    std::cerr << range1 << std::endl;
    range1 = range4;
    std::cerr << range1 << std::endl;
    ```

    Wertzuweisung "`range1 = range4;`":<br/>
    Identische Wertebereiche - hier kann es keine Probleme geben - Überprüfung (`check`-Methodenaufruf) überflüssig!

    Wertzuweisung "`range1 = range2;`":<br/>
    Wertebereiche unterschiedlich, **aber**: Wertebereich von `range2` ist Teilmenge des Wertebereichs von `range1` - auch
    hier kann es keine Probleme geben - Überprüfung (`check`-Methodenaufruf) überflüssig!
    
    Wertzuweisung "`range1 = range3;`":<br/>
    Wertebereiche unterschiedlich: Hier kann es Probleme geben, da der Wertebereich von `range3` die Grenzen des Wertebereichs von `range1` überschreitet - 
    Überprüfung (check-Methodenaufruf) *notwendig*!

    *Hinweis*:

    Der Konstruktor

    ```cpp
    template <int MIN_OTHER, int MAX_OTHER>
    SubRange(SubRange<MIN_OTHER, MAX_OTHER> const& other)
    {
        check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.m_value, MIN, MAX);
        // or - without friend declaration
        // check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.getValue(), MIN, MAX);
        m_value = other.getValue();
    }
    ```

    ist per se nicht übersetzungsfähig, da für die neu generierte Klassenschablone `SubRange<MIN_OTHER, MAX_OTHER>`
    der Zugriff auf private Instanzvariablen nicht erlaubt ist. Quasi ist der Parameter
    `other` des Typs `SubRange<MIN_OTHER, MAX_OTHER>` von einem anderen Typ als die aktuelle Klasse
    des Typs `SubRange<int MIN, int MAX>`.
    
    Lösen lässt sich dieses Problem mit einer `friend`-Deklaration:

    `template <int, int> friend class SubRange;`



Ausgabe des Programms von *Variante 1*:

```cpp
calling check ...
calling check ...
calling check ...
10
calling check ...
8
8
calling check ...
```

Ausgabe des Programms von *Variante 2*:

```cpp
calling check ...
calling check ...
calling check ...
calling check ...
10
15
calling check ...
```

Ausgabe des Programms von *Variante 3*:

```cpp
calling check ...
calling check ...
calling check ...
calling check ...
15
16
16
16
calling check ...
calling check ...
```

---

[Zurück](../../../Readme.md)

---
