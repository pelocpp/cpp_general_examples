# Beispiel "Template-Klasse für eine Stapel (Stack)"

Wir stellen die Realisierung einer Template-Klasse für eine Stapel (Stack) vor.
Bei einer Implementierung der Klasse bleibt der konkrete Typ offen, es wird ein Stellvertreterbezeichner benutzt
(in der Regel `T`).

*Hinweis*:

Die Klasse `Stack` stellt Methoden auf Basis der Move-Semantik bereit. Auf diese Weise wird zum
Beispiel bei der `Pop`-Operation verhindert, dass eine Kopie des zu entfernenden Elements (Objekts) im Stapel verbleibt!

Schnittstelle der `Stack`-Klasse:

```cpp
template<typename T, int Max = 10>
class Stack {
private:
    int m_index;    // stack pointer 
    T m_data[Max];  // data

public:
    Stack();
    virtual ~Stack();

    // using exception handling in case of overflow / underflow
    bool push(const T&);
    bool push(T&&);
    T pop();

    // indicating overflow / underflow with return value
    bool pushEx(const T&);
    bool pushEx(T&&);
    bool popEx(T&);

    T top();

    int size() const noexcept;  //  maximum stack size
    int count() const noexcept; // number of elements
    bool isEmpty() const noexcept;
    bool isFull() const noexcept;
};
```

---

[Zurück](../../../Readme.md)
