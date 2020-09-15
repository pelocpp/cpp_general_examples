# �bung zu Templates und C++-17 Features

Wir betrachten in dieser �bung eine Spreadsheet-Anwendung
in Anlehnung an die Microsoft-Applikation "Excel".

Im Mittelpunkt der �berlegungen stehen zwei Klassen:

  * Klasse `SpreadsheetCell`
  * Klasse `Spreadsheet` (oder `Grid`).

Unter einem `Spreadsheet`-Objekt verstehen wir ein zwei-dimensionales Gitter aus `SpreadsheetCell`-Objekten.

Ein `SpreadsheetCell`-Objekt soll entweder eine Zahl (`int`, `float`, `double`)
oder eine Zeichenkette (`std::string` oder `std::string_view`) enthalten / beschreiben.

�berlegen Sie, ob bzw. wie Sie die C++-17-Klasse `std::variant` hierf�r einsetzen k�nnen.

Es sollte zur Laufzeit der Anwendung m�glich sein, zwischen den beiden Modi *Zahl* und *Zeichenkette*
hin und her zu wechseln. Der Weg von einer Zahl zu einer Zeichenkette ist trivial, 
der Wert der Zahl ist in eine Zeichenkette umzuwandeln. Die andere Richtung k�nnte funktionieren,
wenn die Zeichenkette eine Zahl korrekt beschreibt. Andernfalls k�nnte die Umwandlung abgelehnt werden,
zum Beispiel mit der Fehlermeldung "Falsches Format".

Wie in einer Excel-Anwendung k�nnen die Zellen - zum Beispiel nach dem Anlegen
eines neuen Arbeitsblattes - zun�chst leer sein. �berlegen Sie, ob Sie die C++-17-Klasse
`std::optional` deshalb verwenden k�nnen.

Die Spreadsheet-Klasse sollte ihre Zellen mit einem STL-Container verwalten. 
Ein m�glicher Ansatz k�nnte sein:

```cpp
std::vector<std::vector<std::optional<T>>> mCells;
```

Etwas ausf�hrlicher:

```cpp
template <typename T>
class Spreadsheet
{
public:
    explicit Spreadsheet(size_t width = 10, size_t height = 10);
    virtual ~Spreadsheet() = default;

    size_t getHeight() const { return m_height; }
    size_t getWidth() const { return m_width; }

private:
    size_t m_width;
    size_t m_height;

    std::vector<std::vector<std::optional<T>>> mCells;
};
```

Alternativ w�re auch ein statisches - also ein zur �bersetzungszeit in seinen Gr��en
bekanntes - Feld ein gangbarer Weg, zum Beispiel:

```cpp
template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10>
class Spreadsheet
{
public:
    Spreadsheet() = default;
    virtual ~Spreadsheet() = default;

    size_t getHeight() const { return HEIGHT; }
    size_t getWidth() const { return WIDTH; }

private:
    std::optional<T> mCells[WIDTH][HEIGHT];
};
```

Weitere Hinweise zur Realisierung:

**Zugriff auf eine Zelle**:</br>
F�r den lesenden und schreibenden Zugriff auf eine Zelle k�nnten Sie eine Methode `at` implementieren:

```cpp
std::optional<T>& at(size_t x, size_t y);
```

Wenn Sie im Umgang mit C++-Referenzen vertraut sind, m�sste *eine* Methode f�r den lesenden 
und schreibenden Zugriff ausreichen.

**Arithmetik**:</br>
In einem Spreadsheet lassen sich bestimmte Abschnitte einer Zeile oder einer Spalte
mit arithmetischen Funktionen bearbeiten, zum Beispiel:

  * Summe aller Zellen in Spalte X von Zeile N bis Zeile M
  * Durchschnittswert aller Zellen in Spalte X von Zeile N bis Zeile M

�berlegen Sie, wie Sie diese Anforderungen implementieren k�nnen?

**Zeilen / Spalten kopieren**</br>
In Excel kann man Zeilen oder Spalten kopieren. �berlegen Sie, wie entsprechende Methoden
an der Klasse `Spreadsheet` aussehen m�ssen. Prinzipiell ist an dieser Stelle zu erw�hnen,
dass Standard-C++-Features wie Kopier-Konstruktoren oder Wertzuweisungs-Operatoren 
zum Einsatz kommen sollten.

**Tausch-Operationen**:</br>
In einer Excel-Anwendung lassen sich zwei Spalten oder Zeilen vertauschen.
Implementieren Sie hierf�r eine oder zwei Methoden `swap`.

**Arbeitsblatt kopieren**:</br>
Erstellen Sie f�r die Klasse `Spreadsheet` einen Kopier-Konstruktor. *Bildlich* gesprochen
dient er dem Zweck, das aktuelle Arbeitsblatt zu kopieren.

---

[Zur�ck](../../../Readme.md)

