// =======================================================================
// Test03.cpp
// =======================================================================

#include <iostream>
#include <complex>

#include "CalculatorFraction.h"

/*
 * Demonstrating Class Template Full Specialization (Explicit Specialization)
 */

void test03()
{
    // T = Fraction
    Calculator<Fraction> fractionCalc;     // uses specialized Calculator template
    Fraction f1{ 1, 7 };
    Fraction f2{ 3, 7 };
    Fraction result = fractionCalc.add(f1, f2);
    std::cout << f1 << " + " << f2 << " = " << result << std::endl;

    // T = int
    Calculator<int> intCalc;               // uses original Calculator template
    int n{ 1 };
    int m{ 2 };
    int value = intCalc.add(n, m);
    std::cout << n << " + " << m << " = " << value << std::endl;
}

// =======================================================================
// End-of-File
// =======================================================================
