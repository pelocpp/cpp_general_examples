// =======================================================================
// Test01.cpp
// =======================================================================

#include <iostream>
#include <complex>

#include "Calculator.h"

/*
 * Demonstrating creation of objects of a Class Template 
 */

void test01_arithmeticMemoryFuntions()
{
    // T = int
    Calculator<int> intCalc;
    int n{ 1 };
    int m{ 2 };
    int value = intCalc.add(n, m);
    std::cout << n << " + " << m << " = " << value << std::endl;

    intCalc.memoryStore(9);
    intCalc.memoryAdd(8);
    value = intCalc.memoryRecall();
    std::cout << "8 + 9 = " << value << std::endl;

    // T = double
    Calculator<double> doubleCalc;
    double x{ 1.3 };
    double y{ 2.3 };
    double doubleValue = doubleCalc.add(x, y);
    std::cout << x << " + " << y << " = " << doubleValue << std::endl;

    doubleCalc.memoryStore(123.456);
    doubleCalc.memoryAdd(654.321);
    doubleValue = doubleCalc.memoryRecall();
    std::cout << "123.456 + 654.321 = " << doubleValue << std::endl;

    // T = std::complex<double>
    Calculator<std::complex<double>> complexCalc;
    using namespace std::complex_literals;
    std::complex<double> z1 = 1.0 + 2i;
    std::complex<double> z2 = 2.0 - 4i;
    std::complex<double> complexResult = complexCalc.add(z1, z2);
    std::cout << z1 << " + " << z2 << " = " << complexResult << std::endl;

    complexCalc.memoryStore(z1);
    complexCalc.memorySub(z2);
    complexResult = complexCalc.memoryRecall();
    std::cout << z1 << " - " << z2 << " = " << complexResult << std::endl;
}

void test01_factorial()
{
    // T = int, U = unsigned long
    Calculator<int, unsigned long> calc;
    for (int i{}; i != 10; ++i) {
        unsigned long facul = calc.Factorial(i);
        std::cout << i << "! = " << facul << std::endl;
    }
}

void test01()
{
    test01_arithmeticMemoryFuntions();
    test01_factorial();
}

// =======================================================================
// End-of-File
// =======================================================================
