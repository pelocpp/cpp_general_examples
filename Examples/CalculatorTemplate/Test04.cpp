// =======================================================================
// Test04.cpp
// =======================================================================

#include <iostream>
#include <complex>

#include "Calculator.h"

/*
 * Demonstrating Member Function Templates
 */

void test04()
{
    // T = int
    Calculator<int> intCalc;
    int result = intCalc.NThPower<5>(2);
    std::cout << "2 ^ 5 = " << result << std::endl;

    // T = std::complex<double>
    Calculator<std::complex<double>> complexCalc;
    using namespace std::complex_literals;
    std::complex<double> z = 1.0 + 2i;
    std::complex<double> result2 = complexCalc.NThPower<5>(z);
    std::cout << z << " ^ 5 = " << result2 << std::endl;

    std::complex<double> result3;
    result3 = complexCalc.mul(z, z);
    result3 = complexCalc.mul(result3, z);
    result3 = complexCalc.mul(result3, z);
    result3 = complexCalc.mul(result3, z);
    std::cout << "Check: " << result3 << std::endl;
}

// =======================================================================
// End-of-File
// =======================================================================
