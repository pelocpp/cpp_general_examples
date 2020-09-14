# C++ General Examples

In diesem Repository sind zahlreiche kleinere C++ -Programme abgelegt,
um diverse Features von C++ zu demonstrieren. Im Gro�en und Ganzen wurde dabei versucht,
die Beispiele auf dem Niveau f�r C++-Einsteiger (mit Kenntnissen anderer Programmiersprachen) zu halten.

In der Regel sind diese Beispiele etwas umfangreicher im Vergleich zu einem einfachen Code-Snippet,
deshalb erfolgt die Ablage der Beispiele in diesem Repository.

## Inhaltsverzeichnis:

#### Beispiel *Tuple* (Unterverzeichnis *MyTuple*):

Folgende Aspekte werden betrachtet:
  * Templates allgemein
  * Variadische Templates

---

#### Beispiel *Shapes*:

Folgende Aspekte werden betrachtet:
  * Vererbung
  * Neue Schl�sselw�rter `final` und `override` (erg�nzend zu `virtual`)
  * Delegation von Konstruktoren
  * Modellierung des `interface`-Konzepts anderer Programmiersprachen wie Java und C#

---

#### Beispiel *SubRange*:

Folgende Aspekte werden betrachtet:
  * Klassentemplates
  * Templates mit value-Parametern
  * Template-Spezialisierung von Funktionstemplates
  * Template Metaprogrammierung 

---

#### Beispiel *SmartPointer*:

Folgende Aspekte werden betrachtet:
  * Exemplarische Implementierung eines Smart Pointers</br>(zum besseren Verst�ndnis der Standardklassen `std::unique_ptr`, `std::shared_ptr` und `std::weak_ptr`)
  * Entwicklung eines einfachen Klassentemplates

---

#### Beispiel *Phonebook*:

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit STL-Container (`std::vector`)
  * Zusammenspiel von `std::vector`-Objekt und Eintr�gen vom Typ `std::unique_ptr`
  * Anwendung von `std::move`
  * Dateiein- und -ausgabe (`std::ofstream` und `std::ifstream`)
  * Lambda-Funktionen
  * Sortieren (std::sort)

---

#### Beispiel *Stack* (Unterverzeichnis *TemplateStack*):

Folgende Aspekte werden betrachtet:
  * Erstellung eines einfachen Klassentemplates
  * *Move*-Semantik (Anwendung von `std::move`)
  * Klassentemplate mit non-type Parameter
  * Templateparameter mit Default-Wert
  * Exception Handling (`throw`, `try`, `catch`, `what`)

---

#### Realisierung von Callback-Funktionen in C++ (*EventSource* und *EventSink*):

Folgende Aspekte werden betrachtet:
  * Umsetzung zweier Klassen *EventSource* und *EventSink* zum ereignisbasierten Nachrichtenaustausch
  * Umsetzung von Delegates (Callback-Funktionen) � la C# in C++ mit Lambda-Funktionen
  * Anwendungsbeispiel f�r Klassenschablone `std::function` 
  * Anwendungsbeispiel f�r Funktionsschablone `std::bind` 

## [Beispiel *EventSource* und *EventSink*](Examples/EventsSourceAndSink/Resources/Readme.md)


#### Beispiel *Reverse Polish Notation (RPN) Calculator*<br/>(Unterverzeichnis *RPNCalculator*):

Folgende Aspekte werden betrachtet:
  * Klassentemplates
  * Anwendung f�r das Klassentemplates `Stack` aus Unterverzeichnis '*TemplateStack*'

---

#### Beispiel *CustomIterator*:

Folgende Aspekte werden betrachtet:
  * Implementierung einer Custom Iterator Klasse (hier: Klasse `RangeIterator`)
  * Implementierung eines korrespondierenden Containers (hier: Klasse `Range`)
  * Templates

---


#### Beispiel *Bank*:

Folgende Aspekte werden betrachtet:
  * �bung zum Thema "Vererbung"
  * Die Konzepte zum Vererben und �berschreiben von Methoden werden an einem realistischen Beispiel demonstriert.
  * STL-Container `std::vector`

---

#### Beispiel *KeywordsFrequency*:

Folgende Aspekte werden betrachtet:
  * STL-Container (`std::vector`, `std::map` und `std::multimap`)
  * Dateiein- und -ausgabe (`std::ofstream` und `std::ifstream`)
  * Iteratoren (`iterator`, `const_iterator` und `reverse_iterator`)

---


#### Beispiel *IntegerSet*:

Folgende Aspekte werden betrachtet:
  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container (`std::vector`) im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" / Variante 3 und 4)
  * Betrachtung des *Swap-Idioms* als eine M�glichkeit zur Umsetzung der Move-Semantik

---

#### Beispiel *LinkedList*:

Folgende Aspekte werden betrachtet:
  * Implementierung einer verketteten Liste (*linked list*) mit `std::unique_ptr`-Objekten




# // REST ... nur als Vorlage gedacht !!!


# C++ Design Patterns

Design Patterns (Entwurfsmuster) sind bew�hrte L�sungswege f�r wiederkehrende Entwurfsprobleme
in der Softwareentwicklung. Sie beschreiben die zentralen Entwurfsentscheidungen (Klassen, Objekte, deren Beziehungen zueinander).
Durch den Einsatz von Software Entwurfsmustern wird ein Entwurf flexibel, wiederverwendbar, erweiterbar, einfacher zu verwenden und 
stabiler im Falle von �nderungen.

<img src="Resources/DesignPattern_HeardAbout.png" width="400">

Abbildung 1: *Relax*!


In den Entwurfsmustern manifestiert sich die jahrelange Entwicklungserfahrung vieler Softwareentwickler. 
Dieses Wissen l�sst sich durch die Verwendung von Entwurfsmustern reaktivierbar und nutzbar machen,
ohne vorher den teuren Prozess der Entwurfsentwicklung erneut durchlaufen zu m�ssen.

Zeitgleich schulen Design Pattern die F�higkeit zur effektiven objektorientierten Modellierung.

## [Geschichtlicher �berblick](Resources/Readme_01_History.md)

## [Was ist ein Entwurfsmuster?](Resources/Readme_02_Description.md)

## [Entwurfsprinzipien](Resources/Readme_03_Design_Principles.md)

## [Kritik](Resources/Readme_04_Criticism.md)

## [Katalog der Entwurfsmuster](Resources/Readme_05_Catalog.md)

## [Katalog der Anti-Pattern](Resources/Readme_06_Catalog_AntiPattern.md)

## [Literatur](Resources/Readme_07_Literature.md)

---
