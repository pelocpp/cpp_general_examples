# Beispiel "Häufigkeitsliste für C++ Schlüsselwörter"


---

[Zurück](../../../Readme.md)

---

Erstellen Sie ein Programm, das zu einer C++-Quelldatei eine Häufigkeitsliste (*frequency list*) aller verwendeten C++ Schlüsselwörter generiert.
Darunter verstehen wir eine alphabetisch sortierte Liste aller Schlüsselwörter,
die in einer C++-Quelldatei auftreten. Die Ausgabe des Programms könnte so aussehen:

```cpp
List of Keywords Frequency:
===========================

             void - 11
            const - 11
               if - 10
             bool - 10
             char - 9
           return - 8
              int - 8
            while - 6
             true - 5
        namespace - 4
            false - 4
             else - 4
            using - 3
         unsigned - 3
            throw - 3
      static_cast - 3
           static - 3
          private - 3
              for - 3
              try - 2
           public - 2
          default - 2
            class - 2
            catch - 2
          wchar_t - 1
         volatile - 1
          virtual - 1
            union - 1
         typename - 1
           typeid - 1
          typedef - 1
             this - 1
         template - 1
           switch - 1
           struct - 1
           sizeof - 1
           signed - 1
            short - 1
 reinterpret_cast - 1
         register - 1
        protected - 1
         operator - 1
              new - 1
          mutable - 1
             long - 1
           inline - 1
             goto - 1
           friend - 1
            float - 1
           extern - 1
           export - 1
         explicit - 1
             enum - 1
     dynamic_cast - 1
           double - 1
               do - 1
           delete - 1
         continue - 1
       const_cast - 1
             case - 1
            break - 1
             auto - 1
              asm - 1
```

Sie dürfen für Ihre Realisierung natürlich einige vereinfachende Annahmen zu Grunde legen,
da wir sonst bereits die Gefilde der lexikalischen Analyse eines Compilers betreten würden.
So dürfen Sie in einer ersten Version Ihres Programms das "Problem von Kommentaren" übergehen.
Sprich sind in der C++-Quelldatei einzeilige (`//`) oder mehrzeilige (`/*` ... `*/`) Kommentare enthalten,
so wird ihr Inhalt bei der Analyse ebenfalls mit erfasst.

Ferner gibt es mehrere Möglichkeiten, wie Sie in einer Zeile des Quellcodes einzelne Schlüsselwörter lokalisieren.
Die C++-Standardfunktion `find` (aus der Klasse `std::string`) ist ein erster Kandidat.
Auch hier werden Sie auf Probleme stoßen, die Sie erst bei der Umsetzung der Details wahrnehmen.
Ich denke da zum Beispiel an das Schlüssenwort `const`, das auch in den Schlüsselwörtern `constexpr` oder `const_cast` enthalten ist.
Möglicherweise lassen sich falsche Suchtreffer hier durch eine geschickte Umstellung der 
Schlüsselwörter in der programm-internen Liste aller Schlüsselwörter beheben.

Etwas schwieriger wird es, wenn Sie Schlüsselwörter in regulären Bezeichnern im Quellcode vorfinden,
beispielsweise das Schlüsselwort `for` in der Funktion `std::transform` (definiert durch die Header-Datei *"algorithm"*).
In meiner Lösung habe ich deshalb einen anderen Ansatz gewählt, man könnte ihn als "progressive search" bezeichnen.
Sie sehen bereits an diesen Erläuterungen, dass diese Aufgabe viel Freiraum für eine ganze Reihe kreativer Ergänzungen besitzt! 

---

[Zurück](../../../Readme.md)

---
