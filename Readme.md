# C++ General Examples

In diesem Repository sind zahlreiche kleinere C++ -Programme abgelegt,
um diverse Features von C++ zu demonstrieren. Im Großen und Ganzen wurde dabei versucht,
die Beispiele auf dem Niveau für C++-Einsteiger (mit Kenntnissen anderer Programmiersprachen) zu halten.

In der Regel sind diese Beispiele etwas umfangreicher im Vergleich zu einem einfachen Code-Snippet,
deshalb erfolgt die Ablage der Beispiele in diesem Repository.

## Inhaltsverzeichnis:

#### [Realisierung der Standardklasse `std::tuple<>`](Examples/CustomTuple/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Templates im Allgemeinen
  * Variadische Templates
  * Exemplarische Implementierung der Klasse `std::tuple<>`

---

#### [Klassenhierarchie mit geometrischen Figuren (Shapes)](Examples/Shapes/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Vererbung
  * Neue Schlüsselwörter `final` und `override` (ergänzend zu `virtual`)
  * Delegation von Konstruktoren
  * Modellierung des `interface`-Konzepts anderer Programmiersprachen wie Java und C#

---

#### [Demonstration von partieller Template Spezialisierung (Beispiel *SubRange*)](Examples/SubRange/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Klassentemplates
  * Templates mit value-Parametern
  * Template-Spezialisierung von Funktionstemplates
  * Template Metaprogrammierung 

---

#### [Einfache Realisierung einer *SmartPointer*-Klasse](Examples/SmartPointer/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Exemplarische Implementierung eines Smart Pointers</br>(zum besseren Verständnis der Standardklassen `std::unique_ptr`, `std::shared_ptr` und `std::weak_ptr`)
  * Entwicklung eines einfachen Klassentemplates

---

#### [Klasse `Phonebook`](Examples/Phonebook/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit STL-Container (`std::vector`)
  * Zusammenspiel von `std::vector`-Objekt und Einträgen vom Typ `std::unique_ptr`
  * Anwendung von `std::move`
  * Dateiein- und -ausgabe (`std::ofstream` und `std::ifstream`)
  * Lambda-Funktionen
  * Sortieren (`std::sort`)

---

#### [Template-Klasse für eine Stapel (Stack)](Examples/TemplateStack/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Erstellung eines einfachen Klassentemplates
  * *Move*-Semantik (Anwendung von `std::move`)
  * Klassentemplate mit non-type Parameter
  * Templateparameter mit Default-Wert
  * Exception Handling (`throw`, `try`, `catch`, `what`)

---

#### [Realisierung von Callback-Funktionen in C++ (*EventSource* und *EventSink*)](Examples/EventsSourceAndSink/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Umsetzung zweier Klassen *EventSource* und *EventSink* zum ereignisbasierten Nachrichtenaustausch
  * Umsetzung von Delegates (Callback-Funktionen) à la C# in C++ mit Lambda-Funktionen
  * Anwendungsbeispiel für Klassenschablone `std::function` 
  * Anwendungsbeispiel für Funktionsschablone `std::bind` 

---

#### [Ein *Reverse Polish Notation (RPN) Calculator*](Examples/RPNCalculator/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Klassentemplates
  * Anwendung für das Klassentemplates `Stack` aus Unterverzeichnis '*TemplateStack*'

---

#### [Eine benutzerdefinierte Iterator-Klasse](Examples/CustomIterator/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Implementierung einer Custom Iterator Klasse (hier: Klasse `RangeIterator`)
  * Implementierung eines korrespondierenden Containers (hier: Klasse `Range`)
  * Templates

---

#### [Bankkonten und -institut](Examples/AccountsAndBank/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Übung zum Thema "Vererbung"
  * Die Konzepte zum Vererben und Überschreiben von Methoden werden an einem realistischen Beispiel demonstriert.
  * STL-Container `std::vector`

---

#### [Eine Klasse *KeywordsFrequency*](Examples/KeywordsFrequency/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * STL-Container (`std::vector`, `std::map` und `std::multimap`)
  * Dateiein- und -ausgabe (`std::ofstream` und `std::ifstream`)
  * Iteratoren (`iterator`, `const_iterator` und `reverse_iterator`)

---

#### [Eine Klasse *IntegerSet*](Examples/IntegerSet/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container (`std::vector`) im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" / Variante 3 und 4)
  * Betrachtung des *Swap-Idioms* als eine Möglichkeit zur Umsetzung der Move-Semantik

---

#### [Linked List mit `std::unique_ptr<>`](Examples/LinkedList/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Implementierung einer verketteten Liste (*linked list*) mit `std::unique_ptr`-Objekten

---

