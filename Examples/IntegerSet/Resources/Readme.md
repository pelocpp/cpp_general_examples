# Beispiel "IntegerSet"

## Motivation

An der Klasse `IntegerSet` lassen sich mehrere Aspekte betrachten:

  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" / Variante 3 und 4)
  * Betrachtung des Swap-Idioms als eine Möglichkeit zur Umsetzung der Move-Semantik

Um vor die beiden Themenbereich an einem *Real-World*-Beispiel zu betrachten, finden Sie nachfolgenden
eine Spezifikation der öffentlichen Schnittstelle der Klasse wieder.


## Spezifikation der Klasse `IntegerSet`

Erstellen Sie eine Klasse `IntegerSet`, die eine Menge ganzer Zahlen mit zentralen Operationen wie das Einfügen oder Löschen von Elementen realisiert.
Arrays gibt es in C++ in Gestalt von `std::vector`-Objekten.
Verwenden Sie deshalb ein `std::vector<int>`-Objekt, um die Elemente der Menge intern in einem `IntegerSet`-Objekt zu verwalten.
Beachten Sie dabei: Listen dieses Typs sind streng typisiert, d.h.,
alle Methoden zum Einfügen oder Entfernen von Elementen erlauben in diesem Beispiel nur `int`-Werte – was in
Bezug auf die Aufgabenstellung ja keinen Nachteil darstellt.
Der C++-Präcompiler meldet bereits zur Übersetzungszeit Fehler, wenn Sie aktuelle Parameter falschen Typs verwenden.

Damit kommen wir auf die öffentliche Schnittstelle der `IntegerSet`-Klasse zu sprechen. Die Konstruktoren der Klasse haben wir in Tabelle 1 zusammengestellt:

| Konstruktor    | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Default-Konstruktor | `IntegerSet();`<br/> Der Standardkonstruktor legt eine leere Menge an.|
| Kopier-Konstruktor | `IntegerSet(const IntegerSet&)`<br/> Dient zum Erstellen einer Kopie eines bereits existierenden `IntegerSet`-Objekts. |
| benutzerdefinierter Konstruktor | `IntegerSet(int elems[], int count);`<br/> Mit dem Parameter `elems` wird ein Array ganzer Zahlen übergeben. Vor der Aufnahme der Werte in das Mengenobjekt ist zu überprüfen, ob diese alle verschieden sind.|

Tabelle 1. Konstruktoren der Klasse `IntegerSet`.

Die öffentlichen Methoden der Klasse `IntegerSet` finden Sie in Tabelle 2 vor:

| Methode        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| `contains`   | `bool contains(int n);`<br/> Prüft das Vorhandensein eines Elements *n* in der Menge. Der Rückgabewert true bedeutet „Element ist in der Menge vorhanden“, false das Gegenteil.|
| `insert`     | `bool insert (int n);`<br/> Fügt eine ganze Zahl *n* in die Menge ein. Ist die Zahl in der Menge bereits enthalten, liefert Insert den Wert `false` zurück, andernfalls `true`.|
| `remove`     | `bool remove (int n);`<br/> Entfernt ein Element *n* aus der Menge. Ist die ganze Zahl in der Menge nicht enthalten, liefert Remove den Wert `false` zurück, andernfalls `true`.|
| `clear`     | `void clear();`<br/> Entfernt alle Elemente aus der Menge. |

Tabelle 2. Öffentliche Methoden der Klasse `IntegerSet`.

Die zwei Eigenschaften (getter) `size` und `isEmpty` der Klasse `IntegerSet` sind in Tabelle 3 erläutert:

| getter        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| `size`   | `int size() const;`<br/> Liefert die Anzahl der in der Menge enthaltenen Elemente zurück. |
| `isEmpty`   | `bool isEmpty() const`<br/> Liefert bei einer leeren Menge `true` zurück, andernfalls `false`.|

Tabelle 3. Öffentliche Eigenschaften (getter) der Klasse `IntegerSet`.

Für die Wertzuweisung von `IntegerSet`-Objekten ist der operator= zu implementieren.
Ferner lassen sich Mengen auf Gleichheit und Ungleichheit vergleichen, 
die `==`- und `!=`Vergleichsoperator sind geeignet zu realisieren.

| Element        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| `=`-Operator | `IntegerSet& operator= (const IntegerSet&);`<br/> Wertzuweisung von `IntegerSet`-Objekten. |
| `[]`-Operator | `const int operator[] (size_t) const;`<br/> Ermöglicht den indizierten, lesenden Zugriff auf ein Mengenobjekt. Veränderungen an einem Mengenobjekt sollten konzeptionell nur mit Hilfe der beiden Methoden `insert` und `remove` erfolgen, aus diesem Grund ist der Operator `const` definiert. |
| `==`-Operator | `bool operator== (const IntegerSet&, const IntegerSet&);`<br/> Testet zwei `IntegerSet`-Objekte auf Gleichheit. Zu beachten ist: Die beiden Mengen `{ 1, 3, 5 }` und `{ 5, 3, 1 }` sind im Sinne der Mengentheorie gleich, die Reihenfolge ihrer Elemente spielt keine Rolle. |
| `!=`-Operator | `bool operator!= (const IntegerSet&, const IntegerSet&);`<br/> Testet zwei `IntegerSet`-Objekte auf Ungleichheit. Es gilt derselbe Hinweis wie beim `==`-Operator. |

Tabelle 4. Wertzuweisung, Index-Operator und Vergleichsoperatoren.

Für elementare mengentheoretische Operationen wie das Bilden einer Vereinigungs- und Schnittmenge oder das Testen der Teilmengenrelation bietet sich die Realisierung durch Operatoren an. Tabelle 5 beschreibt die gängigsten Operatoren im Umfeld der elementaren Mengenlehre:

| Operator        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| `+`-Operator | `IntegerSet operator +(const IntegerSet&);`<br/> Das Resultatobjekt ist die Vereinigungsmenge des aktuellen Objekts mit dem Objekt `s`. |
| `-`-Operator | `IntegerSet operator -(const IntegerSet&);`<br/>  Das Resultatobjekt ist die Differenzmenge zwischen dem aktuellen Objekt und dem Objekt `s`. |
| `^`-Operator | `IntegerSet operator ^(const IntegerSet&);`<br/>  Das Resultatobjekt ist die Schnittmenge des aktuellen Objekts mit dem Objekt `s`. |
| `<=`-Operator | `bool operator <=(const IntegerSet&);`<br/> Prüft, ob die Menge des aktuellen Objekts in der Menge des Objekts s enthalten ist (Rückgabewert `true`) oder nicht (Rückgabewert `false`). |
| `>=`-Operator | `bool operator >=(const IntegerSet&);`<br/> Prüft, ob die Menge des aktuellen Objekts eine Obermenge des Objekts s ist (Rückgabewert `true`) oder nicht (Rückgabewert `false`). |
| `<`-Operator | `bool operator <(const IntegerSet&);`<br/> Prüft, ob die Menge des aktuellen Objekts in der Menge des Objekts s **echt** enthalten ist (Rückgabewert `true`) oder nicht (Rückgabewert `false`). |
| `>`-Operator | `bool operator >(const IntegerSet&);`<br/> Prüft, ob die Menge des aktuellen Objekts eine **echte** Obermenge des Objekts s ist (Rückgabewert `true`) oder nicht (Rückgabewert `false`). |

Tabelle 5. Mengentheoretische Operationen der Klasse `IntegerSet`.

Alternativ lassen sich die mengentheoretische Operationen auch in Methoden abbilden, siehe Tabelle 6:

| Methode | Mengentheoretische Operationen |
|:-------------- |-----------------------------------------|
| `unionset` | `IntegerSet unionset(const IntegerSet&) const;`<br/> Vereinigungsmenge. |
| `difference` | `IntegerSet difference(const IntegerSet&) const;`<br/>  Differenzmenge. |
| `intersection` | `IntegerSet intersection(const IntegerSet&) const;`<br/>  Schnittmenge. |
| `isPartial` | `IntegerSet isPartial(const IntegerSet&) const;`<br/> Teilmengen-Prädikat. |

Tabelle 6. Mengentheoretische Operationen der Klasse `IntegerSet` (Methoden-Schreibweise).

Zur Behandlung eines `IntegerSet` durch ein `ostream`-Objekt gibt es den `<<`-Operator:

| Element        | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| `<<`-Operator | `friend std::ostream& operator<< (std::ostream&, const IntegerSet&);`<br/> Ausgabe eines `IntegerSet`-Objekts auf der Konsole. |

Tabelle 7. Ausgabe.

### Testrahmen

Testen Sie Ihre Implementierung mit einem möglichst umfangreichen Testrahmen. Das nachfolgende Code-Fragment soll eine Anregung darstellen:

```cpp
void test_ctors_dtor()
{
    std::cout << "Testing c'tors / d'tor: " << std::endl;

    IntegerSet is1;
    std::cout << "is1: " << is1 << std::endl;

    int elems1[7] = { -2, -1, 0, 1, 2, -1, -2 };
    IntegerSet is2(elems1, 7);
    std::cout << "is2: " << is2 << std::endl;

    int elems2[11] = { -1, 1, 2, 3, 1, 2, 3, 1, 2, 3, -1 };
    IntegerSet is3(elems2, 11);
    std::cout << "is3: " << is3 << std::endl;

    IntegerSet is4(is3);
    std::cout << "is4: " << is4 << std::endl;

    std::cout << "is1.IsEmpty: " << is1.isEmpty() << std::endl;
    std::cout << "is2.IsEmpty: " << is2.isEmpty() << std::endl;
    std::cout << "is3.IsEmpty: " << is3.isEmpty() << std::endl;
    std::cout << "is4.IsEmpty: " << is4.isEmpty() << std::endl;
}

void test_methods()
{
    std::cout << "Testing methods: " << std::endl;

    IntegerSet is;
    std::cout << "is: " << is << std::endl;

    // testing 'Insert'
    is.insert(1);
    is.insert(2);
    is.insert(3);
    is.insert(4);
    is.insert(5);
    is.insert(6);
    std::cout << "is: " << is << std::endl;

    // testing 'Remove'
    is.remove(3);
    is.remove(4);
    is.remove(5);
    is.remove(6);
    std::cout << "is: " << is << std::endl;

    is.insert(10);
    is.insert(11);
    is.insert(12);

    is.insert(13);
    is.insert(14);
    is.insert(15);
    is.insert(16);
    is.insert(17);
    is.insert(18);
    is.insert(19);
    is.insert(20);
    is.insert(21);
    is.insert(22);
    is.insert(23);
    std::cout << "is: " << is << std::endl;

    is.insert(24);
    std::cout << "is: " << is << std::endl;

    is.remove(11);
    std::cout << "is: " << is << std::endl;

    // testing 'Contains'
    std::cout << "Contains(1): " << is.contains(1) << std::endl;
    std::cout << "Contains(5): " << is.contains(5) << std::endl;
    std::cout << "Contains(10): " << is.contains(10) << std::endl;
}

void test_remove()
{
    IntegerSet is;
    for (int i = 0; i < 20; i++)
        is.insert(i);
    std::cout << "is: " << is << std::endl;

    is.remove(5);
    is.remove(1);
    is.remove(8);
    std::cout << "is: " << is << std::endl;

    is.remove(11);
    std::cout << "is: " << is << std::endl;

    is.remove(16);
    std::cout << "is: " << is << std::endl;

    is.remove(19);
    std::cout << "is: " << is << std::endl;
}

void test_insert()
{
    IntegerSet is;
    for (int i = 0; i < 16; i++)
        is.insert(i);

    std::cout << "is: " << is << std::endl;

    is.insert(16);
    std::cout << "is: " << is << std::endl;
}

void test_operators()
{
    // testing union set
    IntegerSet is1;
    IntegerSet is2;
    for (int i = 0; i < 7; i++)
        is1.insert(i);
    for (int i = 2; i < 9; i++)
        is2.insert(i);
    std::cout << "is1: " << is1 << std::endl;
    std::cout << "is2: " << is2 << std::endl;
    std::cout << "is1+is2: " << (is1 + is2) << std::endl;

    // testing difference set
    std::cout << "is1-is2: " << (is1 - is2) << std::endl;

    // testing intersection set
    std::cout << "is1^is2: " << (is1 ^ is2) << std::endl;

    // testing ==-operator
    std::cout << "is1 == is2: " << (is1 == is2) << std::endl;
    is2.insert(0);
    is2.insert(1);
    is2.remove(7);
    is2.remove(8);
    std::cout << "is2: " << is2 << std::endl;
    std::cout << "is1 == is2: " << (is1 == is2) << std::endl;
    std::cout << "is1 != is2: " << (is1 != is2) << std::endl;

    // testing subset operator
    std::cout << "is1: " << is1 << std::endl;
    std::cout << "is2: " << is2 << std::endl;
    std::cout << "is1 <= is2: " << (is1 <= is2) << std::endl;
    is1.insert(7);
    std::cout << "is1: " << is1 << std::endl;
    std::cout << "is1 <= is2: " << (is1 <= is2) << std::endl;

    // testing assignment operator
    is1 = is2;
    std::cout << "is1: " << is1 << std::endl;
    is1 = is1;
    std::cout << "is1: " << is1 << std::endl;
}

void test_arithmetic_assignment_operators()
{
    int elems1[3] = { 1, 2, 3 };
    IntegerSet is1(elems1, 3);
    std::cout << "is1: " << is1 << std::endl;

    int elems2[3] = { 4, 5, 6 };
    IntegerSet is2(elems2, 3);
    std::cout << "is2: " << is2 << std::endl;

    int elems3[3] = { 7, 8, 9 };
    IntegerSet is3(elems3, 3);
    std::cout << "is3: " << is3 << std::endl;

    is1 += is2 += is3;

    std::cout << "is1: " << is1 << std::endl;
    std::cout << "is2: " << is2 << std::endl;
    std::cout << "is3: " << is3 << std::endl;
}

void test_subscript_operator()
{
    int elems[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    IntegerSet is(elems, 9);

    for (int i = 0; i < is.size(); i++)
        std::cout << "Element at " << i << ": " << is[i] << std::endl;
}
```

**Ausgabe**:

```cpp
Testing c'tors / d'tor:
is1: {} [0]
is2: {-2,-1,0,1,2} [5]
is3: {-1,1,2,3} [4]
is4: {-1,1,2,3} [4]
is1.IsEmpty: 1
is2.IsEmpty: 0
is3.IsEmpty: 0
is4.IsEmpty: 0
Testing methods:
is: {} [0]
is: {1,2,3,4,5,6} [6]
is: {1,2} [2]
is: {1,2,10,11,12,13,14,15,16,17,18,19,20,21,22,23} [16]
is: {1,2,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24} [17]
is: {1,2,10,12,13,14,15,16,17,18,19,20,21,22,23,24} [16]
Contains(1): 1
Contains(5): 0
Contains(10): 1
is: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19} [20]
is: {0,2,3,4,6,7,9,10,11,12,13,14,15,16,17,18,19} [17]
is: {0,2,3,4,6,7,9,10,12,13,14,15,16,17,18,19} [16]
is: {0,2,3,4,6,7,9,10,12,13,14,15,17,18,19} [15]
is: {0,2,3,4,6,7,9,10,12,13,14,15,17,18} [14]
is: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} [16]
is: {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} [17]
is1: {0,1,2,3,4,5,6} [7]
is2: {2,3,4,5,6,7,8} [7]
is1+is2: {0,1,2,3,4,5,6,7,8} [9]
is1-is2: {0,1} [2]
is1^is2: {2,3,4,5,6} [5]
is1 == is2: 0
is2: {2,3,4,5,6,0,1} [7]
is1 == is2: 1
is1 != is2: 0
is1: {0,1,2,3,4,5,6} [7]
is2: {2,3,4,5,6,0,1} [7]
is1 <= is2: 1
is1: {0,1,2,3,4,5,6,7} [8]
is1 <= is2: 0
is1: {2,3,4,5,6,0,1} [7]
is1: {2,3,4,5,6,0,1} [7]
is1: {1,2,3} [3]
is2: {4,5,6} [3]
is3: {7,8,9} [3]
is1: {1,2,3,4,5,6,7,8,9} [9]
is2: {4,5,6,7,8,9} [6]
is3: {7,8,9} [3]
Element at 0: 9
Element at 1: 8
Element at 2: 7
Element at 3: 6
Element at 4: 5
Element at 5: 4
Element at 6: 3
Element at 7: 2
Element at 8: 1
```

---

[Zurück](../../../Readme.md)
