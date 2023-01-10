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

    // testing memory functions of class Calculator<Fraction>
    fractionCalc.memoryStore({ 1, 6 });
    fractionCalc.memoryAdd({ 2, 6 });
    fractionCalc.memoryAdd({ 3, 6 });
    result = fractionCalc.memoryRecall();
    std::cout << "{ 1, 6 } + { 2, 6 } + { 3, 6 } = " << result << std::endl;

    // testing NThPower
    Fraction f = { 1, 2 };
    Fraction power = fractionCalc.NThPower<5>(f);
    std::cout << f << " ^ 5 = " << power << std::endl;
    f = { 3, 2 };
    power = fractionCalc.NThPower<3>(f);
    std::cout << f << " ^ 3 = " << power << std::endl;
}

// =======================================================================
// End-of-File
// =======================================================================
