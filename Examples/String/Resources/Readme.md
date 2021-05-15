# Beispiel Klasse `String`

===================================================================================


*Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Vielen der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

## Einf�hrung

In einer objektorientierten Sprache wie C++ geh�rt eine Klasse String f�r den komfortablen Umgang mit Zeichenketten zum Pflichtbestandteil der Klassenbibliothek eines jeden C++-Compilers. Da in C++ auch standardisierte Klassenbibliotheken existieren, finden wir die gesuchte Klasse � unter dem Namen string � tats�chlich auch in der STL (�Standard Template Library�) vor. Um �bung in der Anwendung der Programmiersprache C++ zu erlangen, besch�ftigen wir uns im folgenden mit der Realisierung unserer eigenen Klasse String, siehe dazu die Beschreibung der �ffentlichen Schnittstelle dieser String-Klasse in Tabelle 1.

Bei der Implementierung der Klasse String ist der Speicherbereich f�r die einzelnen Zeichen der Zeichenkette dynamisch zu allokieren. Der Einfachheit halber legen wir zus�tzlich zu Grunde, dass der Umfang dieses Speicherbereichs exakt an die L�nge der Zeichenkette angepasst wird, siehe Abbildung 1. Den Overhead im Arbeitsaufwand der einzelnen Methoden nehmen wir in billigend Kauf, da wir mit dieser Vorschrift eine einfachere Realisierung verbuchen k�nnen.

<img src="String.png" width="250">

Abbildung 1. Instanzdatenbereich eines String-Objekts mit dynamisch allokiertem Datenpuffer.

## M�gliche Spezifikation einer Klasse `String`

Die Klassenelemente in Tabelle 1 m�gen eine Orientierung f�r Ihre Realisierung der Klasse `String` darstellen:

| Konstruktor    | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Konstruktor | `String();`<br/> Standard-Konstruktor zum Anlegen einer leeren Zeichenkette.|
| Benutzerdefinierter Konstruktor | `String(const char*);`<br/> Benutzerdefinierter Konstruktor. Als Argument wird eine Folge von `char`-Elementen erwartet, die mit `'\0'` abgeschlossen ist, sprich eine klassische �C-Zeichenkette�. |
| Methode `length` | `int length() const;`<br/> Liefert die L�nge der Zeichenkette zur�ck. |
| Methode `insert` | `bool insert(const String& s, int ofs);`<br/> F�gt die Zeichenkette `s` in die aktuelle Zeichenketten-Instanz an der Position `ofs` ein. |
| Methode `append` | `void append(const String& s);`<br/> H�ngt die Zeichenkette `s` am Ende des aktuellen Zeichenkettenobjekts an. |
| Methode `remove` | `bool remove (int ofs, int num);`<br/> Entfernt `num` Zeichen an der Position `ofs` des aktuellen Zeichenkettenobjekts. |
| Methode `subString` | `String subString(int ofs, int num) const;`<br/> Extrahiert eine Teilzeichenkette (beginnend an der Position `ofs` mit `num` Zeichen) aus dem aktuellen Zeichenkettenobjekt. Das Ergebnis wird in Gestalt eines `String`-Objekts zur�ckgeliefert. |
| Methode `find` | `int find(const String&) const;`<br/> Sucht nach der Zeichenkette `s` im aktuellen Zeichenkettenobjekt. Wird die Zeichenkette gefunden, wird der Index (ihres ersten Vorkommens) innerhalb des aktuellen Zeichenkettenobjekts zur�ckgeliefert, andernfalls der Wert -1. |
| Methode `toUpper` | `void toUpper();`<br/> Wandelt alle Kleinbuchstaben im aktuellen Zeichenkettenobjekt in Gro�buchstaben um. |
| Methode `toLower` | `void toLower();`<br/> Wandelt alle Kleinbuchstaben im aktuellen Zeichenkettenobjekt in Kleinbuchstaben um. |
| Methode `left` | `String left (int num);`<br/> Liefert die ersten `num` Zeichen des aktuellen Zeichenkettenobjekts in Gestalt eines eigenst�ndigen Zeichenkettenobjekts zur�ck. |
| Methode `right` | `String right (int num);`<br/> Liefert die letzten `num` Zeichen des aktuellen Zeichenkettenobjekts in Gestalt eines eigenst�ndigen Zeichenkettenobjekts zur�ck. |
| operator `[]` | `char operator[] (int n) const;`<br/> Indexoperator, liefert das *n*.-te Zeichen aus der Zeichenkette zur�ck. |
| operator `+` | `friend String operator+ (const String& s1, const String& s2);`<br/> Verkn�pfung von zwei Zeichenketten in Operatorenschreibweise als Alternative zur `append`-Methode. Der `+`&ndash;Operator liefert als Resultatobjekt die Verkettung der zwei Zeichenketten `s1` und `s2` zur�ck, d.h. ihre Hintereinanderschreibung. Die Objekte `s1` und `s2` bleiben bei dieser Operation unver�ndert. |
| operator `+=` | `friend String& operator+= (String& s, const String& s1);`<br/> Verkn�pfung von zwei Zeichenketten in Operatorenschreibweise als Alternative zur `append`-Methode. Der `+=`-Operator h�ngt die Zeichenkette `s1` an `s` an, das Ergebnis der Verkettung kommt folglich in Objekt `s1` zum Tragen. |
| operator `==` | `friend bool operator== (const String& s1, const String& s2);`<br/> Der ==-Operator vergleicht zwei Zeichenkettenobjekte auf inhaltliche Gleichheit, der !=-Operator auf ihre Ungleichheit. |
| operator `!=` | `friend bool operator!= (const String& s1, const String& s2);`<br/> Der ==-Operator vergleicht zwei Zeichenkettenobjekte auf inhaltliche Gleichheit, der !=-Operator auf ihre Ungleichheit. |
| Ausgabe | `friend std::ostream & operator<< (std::ostream&, const String&);` <br/> Ein- und Ausgabe einer Zeichenkette in der Konsole. Bei der Eingabe darf man in der Implementierung eine maximale Anzahl f�r die einzulesenden Zeichen voraussetzen. Die Ausgabe der Zeichenkette "ABC" sollte wiederum im Format "ABC"[3] erfolgen, die L�nge der Zeichenkette ist in eckigen Klammern aufzuf�hren. |
| Eingabe | `friend std::istream & operator>> (std::istream&, String&);` <br/> Ein- und Ausgabe einer Zeichenkette in der Konsole. Bei der Eingabe darf man in der Implementierung eine maximale Anzahl f�r die einzulesenden Zeichen voraussetzen. Die Ausgabe der Zeichenkette "ABC" sollte wiederum im Format "ABC"[3] erfolgen, die L�nge der Zeichenkette ist in eckigen Klammern aufzuf�hren. |

Tabelle 1. Elemente der Klasse `String`.


Hinweis: Klassenelemente wie der Kopierkonstruktor oder der Destruktor fehlen in Tabelle 1, da sie in einer korrekten Realisierung ohnehin vorhanden sein m�ssen.

Die in der L�sung vorgestellte Implementierung der Klasse String verzichtet auf jegliche Unterst�tzung aus der C Runtime Library (CRT). Dies erfolgt zu Lehrzwecken, um die Realisierung einer Klasse ohne jegliche Unterst�tzung durch eine externe Bibliothek zu betrachten. In der Praxis w�rde man zur Realisierung die CRT mit einbeziehen, um das Rad f�r eine Reihe elementarer Operationen wie Zeichenkette kopieren, vergleichen, usw. nicht zweimal erfinden zu m�ssen.

Zum Testen Ihrer Implementierung schreiben Sie f�r jede Methode oder zusammengeh�rige Gruppe von Klassenelementen eine separate Testfunktion. Die Regel �weniger ist mehr� gilt an dieser Stelle nicht, ganz im Gegenteil: Um �nderungen in Ihrer Implementierung auch im Nachhinein seri�s praktizieren zu k�nnen, ben�tigen Sie einen robusten Testrahmen. Eine sehr ausf�hrliche Anregung dazu finden Sie hier:




















===================================================================================


## Einf�hrung

In dieser �bung wollen wir uns der Klasse `Fraction` in einer zusammenfassenden Betrachtung annehmen.
Folgenden Eigenschaften sollen in Ihrer Realisierung der Klasse `Fraction` Ber�cksichtigung finden:

  * Objekte der Klasse `Fraction` sollen die von ihr verwaltete rationale Zahl immer in einer
    optimal gek�rzten Form verwalteten. Schreiben Sie dazu eine Methode `reduce`, die den
    Bruch optimal k�rzt.

  * Rationale Zahlen k�nnen sowohl positiv als auch negativ sein. Um die klasseninterne
    Arbeitsweise der einzelnen Methoden zu vereinfachen, soll die Regel gelten, dass der
    Nenner einer rationalen Zahl immer positiv ist. Damit kann der Z�hler eines
    `Fraction`-Objekts in Abh�ngigkeit vom Vorzeichen der rationalen Zahl entweder positiv
    oder negativ sein. Achten Sie darauf, dass bei allen �nderungen am Objektzustand (zum
    Beispiel nach einer Subtraktion) der Nenner positiv ist.

  * G�ngige Konstruktoren zur Objekterzeugung.

  * Implementieren Sie die folgenden mathematischen Rechenoperationen:
    * Grundrechenoperationen (`+`, `-`, `*` und `/`).
    * Grundrechenoperationen in Verbindung mit dem Zuweisungsoperator (`+=`, `-=`, `*=`, `/=`).
    * Inkrement- und Dekrementoperator (`++` und `--`).
    * Inverse einer rationalen Zahl (Operator `~`).
    * Un�rer Minus-Operator (`-`).
    * Vergleichsoperatoren (`==`, `!=`, `<`, `<=`, `>` und `>=`).

  * Methode `gcd` (*greatest common divisor*) zur Bestimmung des gr��ten gemeinsamen Teilers von Z�hler und Nenner (*ggT*).
    Die `gcd`-Methode kann von der `reduce`-Methode verwendet werden.

  * Operatoren zur Typumwandlung: Ein `Fraction`-Objekt soll in einem arithmetischen
    Ausdruck auch dann verwendet werden k�nnen, wenn auf Grund des Kontextes ein `float` oder
    `double`-Wert erwartet wird.

  * Ein- und Ausgabe: Eine rationale Zahl soll in der Form &ldquo;Z�hler / Nenner&ldquo; ausgegeben werden.
    F�r Eingaben ist dasselbe Format zu Grunde zu legen. Zwischen den numerischen
    Werten und dem Schr�gstrich sind beliebige Leerzeichen und Tabulatoren erlaubt.

*Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Vielen der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

---

[Zur�ck](../../../Readme.md)
