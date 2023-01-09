# C++ General Examples

In diesem Repository sind zahlreiche kleinere C++ -Programme abgelegt,
um diverse Features von C++ zu demonstrieren. 

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
  * Templates mit *value*-Parametern
  * Template-Spezialisierung von Funktionstemplates
  * Template Metaprogrammierung 

---

#### [Einfache Realisierung einer *SmartPointer*-Klasse](Examples/SmartPointer/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Exemplarische Implementierung eines Smart Pointers</br>(zum besseren Verständnis der Standardklassen `std::unique_ptr`, `std::shared_ptr` und `std::weak_ptr`)
  * Entwicklung eines einfachen Klassentemplates

---

#### [Klassen-Template für einen Taschenrechner](Examples/CalculatorTemplate/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Definition eines Klassen Templates
  * Erzeugung von Objekten eines Klassen-Templates
  * Klassen-Templates mit mehreren Parametern
  * Definition von Methoden eines Klassen-Templates
  * Eine Methode eines Klassen-Templates Überschreiben/spezialisieren
  * *Member Function Templates*
  * Klassen-Templates und Non-Type Parameter
  * Default-Werte für Template-Parameter

---

#### [Klassen-Template für einen Stapel (Stack)](Examples/StackTemplate/Resources/Readme.md)

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

#### [Eine Klasse *KeywordsFrequency*](Examples/KeywordsFrequency/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * STL-Container (`std::vector`, `std::map` und `std::multimap`)
  * Dateiein- und -ausgabe (`std::ofstream` und `std::ifstream`)
  * Iteratoren (`iterator`, `const_iterator` und `reverse_iterator`)

---

#### [Linked List mit `std::unique_ptr<>`](Examples/LinkedList/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Implementierung einer verketteten Liste (*linked list*) mit `std::unique_ptr`-Objekten

---
