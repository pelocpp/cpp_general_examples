// ===========================================================================
// Program.cpp
// ===========================================================================

#include "Fraction.h"

void DemoUnaryOperators()
{
    Fraction f(1, 2);
    std::cout << "f  = " << f << std::endl;
    f = -f;
    std::cout << "-f = " << f << std::endl;
    f = ~f;
    std::cout << "~f = " << f << std::endl;
}

void DemoBinaryOperators()
{
    Fraction a(1, 7);
    Fraction b(3, 7);
    Fraction c;

    std::cout << "a  = " << a << std::endl;
    std::cout << "b  = " << b << std::endl;

    c = a + b;
    std::cout << "a + b = " << c << std::endl;

    c = a + a + a;
    std::cout << "a + a + a = " << c << std::endl;

    c = a - b - a;
    std::cout << "a - b - a = " << c << std::endl;

    c = a * b;
    std::cout << "a * b = " << c << std::endl;

    c = a / b;
    std::cout << "a / b = " << c << std::endl;
}

void DemoArithmeticAssigmentOperators()
{
    Fraction a(1, 7);
    Fraction b(3, 7);
    Fraction c(5, 7);

    std::cout << "a  = " << a << std::endl;
    std::cout << "b  = " << b << std::endl;
    std::cout << "c  = " << c << std::endl;

    a += b += c;
    std::cout << "a += b += c:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    c -= b -= a;
    std::cout << "c -= b -= a:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

void DemoComparisonOperators()
{
    Fraction f(1, 2);
    Fraction g(1, 3);

    std::cout << "f  = " << f << std::endl;
    std::cout << "g  = " << g << std::endl;

    std::cout << "f < g:  " << (f < g) << std::endl;
    std::cout << "f <= g: " << (f <= g) << std::endl;
    std::cout << "f > g:  " << (f > g) << std::endl;
    std::cout << "f >= g: " << (f >= g) << std::endl;
    std::cout << "f == g: " << (f == g) << std::endl;
    std::cout << "f != g: " << (f != g) << std::endl;
}

void DemoTypeConversionOperators()
{
    Fraction a;

    a = 1;
    std::cout << a << std::endl;

    a = a + (Fraction)1;
    a = 1 + (int)(double)a;
    std::cout << a << std::endl;
}

void DemoTypeConversionOperator02()
{
    Fraction f(1, 7);
    double d = f;
    std::cout << "d: " << d << std::endl;
}

void DemoIncrementOperators()
{
    Fraction f(1, 2);
    Fraction g;

    std::cout << "f: " << f << std::endl;

    g = f++;
    std::cout << "g: " << g << std::endl;

    g = ++f;
    std::cout << "g: " << g << std::endl;

    g = f--;
    std::cout << "g: " << g << std::endl;

    g = --f;
    std::cout << "g: " << g << std::endl;
}

void DemoInputOutput()
{
    Fraction f(1, 2);
    std::cout << "f: " << f << std::endl;

    Fraction g;
    std::cout << "enter num and denom:" << std::endl;

    std::cin >> g;
    std::cout << "g: " << g << std::endl;
}

int main ()
{
    DemoUnaryOperators();
    DemoBinaryOperators();
    DemoArithmeticAssigmentOperators();
    DemoComparisonOperators();
    DemoTypeConversionOperators();
    DemoTypeConversionOperator02();
    DemoIncrementOperators();
    DemoInputOutput();

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
