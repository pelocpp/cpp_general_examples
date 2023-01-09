// =======================================================================
// Test05.cpp
// =======================================================================

#include <iostream>
#include <complex>

#include "Calculator.h"

/*
 * Demonstrating creation of objects of a Class Template
 */

void test05()
{
    // T = int
    Calculator<int> intCalc;
    int n{ 1 };
    int m{ 4 };
    int value = intCalc.div(n, m);
    std::cout << n << " / " << m << " = " << value << std::endl;
    n = 3;
    value = intCalc.div(n, m);
    std::cout << n << " / " << m << " = " << value << std::endl;

    // T = double
    Calculator<float> floatCalc;
    float x{ 1.0F };
    float y{ 4.0F };
    float doubleValue = floatCalc.div(x, y);
    std::cout << x << " / " << y << " = " << doubleValue << std::endl;
    x = 3.0F;
    doubleValue = floatCalc.div(x, y);
    std::cout << x << " / " << y << " = " << doubleValue << std::endl;

    // T = long, U = size_t
    Calculator<long, size_t> anotherCalc;
    long ln{ 1 };
    long lm{ 4 };
    long lvalue = anotherCalc.div(ln, lm);
    std::cout << ln << " / " << lm << " = " << lvalue << std::endl;
    ln = 3;
    lvalue = anotherCalc.div(ln, lm);
    std::cout << ln << " / " << lm << " = " << lvalue << std::endl;
}

// =======================================================================
// End-of-File
// =======================================================================
