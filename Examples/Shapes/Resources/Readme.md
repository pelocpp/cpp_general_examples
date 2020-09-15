# Beispiel "Klassenhierarchie mit geometrischen Figuren (Shapes)"

Am klassischen Beispiel der "geometrischen Figuren" werden in dieser Fallstudie
alle Features und Merkmale des Themas "Vererbung in C++" aufgezeigt.

Diese sind, von den den klassischen Aspekten einmal abgesehen: 

  * neue Schlüsselwörter `final` und `override` (ergänzend zu `virtual`)
  * Delegation von Konstruktoren 
  * Modellierung des interface-Konzepts anderen Programmiersprachen wie Java und C#

Für das Programmbeispiel "*Eine Klassenhierarchie geometrischer Figuren*" selbst
legen wir folgende Spezifikation zu Grunde:

Implementieren Sie eine Hierarchie mit Klassen, die zwei- und dreidimensionale geometrische Figuren repräsentieren.
Bei den zweidimensionalen Figuren sollten ein Dreieck (Klasse `Triangle`), ein Viereck (Klasse `Rectangle`)
und ein Kreis (Klasse `Circle`) nicht fehlen.
Zu den dreidimensionalen Figuren gehört ein Würfel (Klasse `Cube`), eine Kugel (Klasse `Sphere`),
ein Kegel (Klasse `Cone`) sowie ein `Quader` (Klasse `Cuboid`).

<img src="ShapesInheritance.png" width="350">

Abbildung 1: Klassenhierarchie geometrischer Figuren.

Überlegen Sie, welche Instanzvariablen zur Beschreibung der jeweiligen geometrischen Figur notwendig sind.
Neben offensichtlichen Instanzvariablen wie der Radius eines Kreises oder die Seitenlänge
eines Würfels soll jede Figur eine Positionsangabe besitzen,
also einen *x*- und *y*-Wert für eine zweidimensionale Figur bzw. ein Tripel (*x*,*y*,*z*)
bei einer dreidimensionalen Figur. Welcher Klasse in der Klassenhierarchie sind diese
Positionsvariablen am besten zuzuordnen?

Konzipieren Sie für jede Klasse einen geeigneten Konstruktor.
Ziehen Sie, soweit möglich, auch den Basisklassenkonstruktor bei der Erzeugung eines Objekts mit ein.

Überlegen Sie, welchen Klassen Sie die Methoden `Circumference` (Umfang), `Volume` (Volumen),
`Area` (Fläche) und `Surface` (Oberfläche) zuordnen können.
Natürlich sollten alle Klassen den Ausgabeoperator `<<` unterstützen und eine
Methode `MoveTo` besitzen.

Das Schnittstellenkonzept, wie es C#, Java und andere Programmiersprachen bieten (Schlüsselwort interface),
ist in dieser direkten Form nicht Bestandteil der Programmiersprache C++. Dennoch ist es möglich,
Schnittstellen auch in C++ zu definieren (Hinweis: "*pure virtual functions*"). Überlegen Sie,
wie Sie eine Klasse `AbstractShape` als Interface definieren könnten.

---

Die Programmausgabe studieren Sie am folgenden Codefragment:

*Beispiel*:

```cpp
void main() {

    Triangle tria(1, 1, 2, 3, 4);
    tria.draw(std::cout);
    Rectangle rect(10, 10, 20, 40);
    rect.draw(std::cout);
    Circle circle(20, 20, 10);
    circle.draw(std::cout);
    Cube cube(30, 30, 20, 10);
    cube.draw(std::cout);
    Cuboid cuboid(50, 50, 40, 10, 20, 30);
    cuboid.draw(std::cout);
    Sphere sphere(40, 40, 30, 15);
    sphere.draw(std::cout);
    Cone cone(60, 60, 50, 20, 30);
    cone.draw(std::cout);
}
```

*Ausgabe*:

```cpp
Shape: Triangle
  TwoDimensional
  Position: 1.00, 1.00
    A: 2.00
    B: 3.00
    C: 4.00
    Area: 2.90
    Circumference: 9.00
Shape: Rectangle
  TwoDimensional
  Position: 10.00, 10.00
    Width: 20.00
    Height: 40.00
    Area: 800.00
    Circumference: 120.00
Shape: Circle
  TwoDimensional
  Position: 20.00, 20.00
Shape: Cube
  ThreeDimensional
  Position: 30.00, 30.00, 20.00
    Size: 10.00
    Volume: 1000.00
    Surface: 600.00
Shape: Cuboid
  ThreeDimensional
  Position: 50.00, 50.00, 40.00
    Width: 10.00
    Height: 20.00
    Depth: 30.00
    Volume: 6000.00
    Surface: 2200.00
Shape: Sphere
  ThreeDimensional
  Position: 40.00, 40.00, 30.00
    Radius: 15.00
    Volume: 14137.17
    Surface: 2827.43
Shape: Cone
  ThreeDimensional
  Position: 60.00, 60.00, 50.00
    Radius:  20.00
    Height:  30.00
    Volume:  12566.37
    Surface: 3522.07
```
