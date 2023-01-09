// =======================================================================
// Test02.cpp
// =======================================================================

#include <iostream>
#include <complex>

#include "Calculator.h"
#include "CalculatorPtr.h"

/*
 * Demonstrating Class Template Partial Specialization
 */

//void test01a()
//{
//    // T = int*
//    Calculator<int*> intCalc;
//    int* np = new int{ 1 };
//    int* mp = new int{ 2 };
//    int value = intCalc.add(np, mp);  // Error: '+': cannot add two pointers
//}

void test02_ArithmeticFuntions()
{
    // T = int*
    Calculator<int*> intCalc;
    auto ip1 = std::make_unique<int>(1);
    auto ip2 = std::make_unique<int>(2);
    std::unique_ptr<int> ivalue = intCalc.add(ip1, ip2);
    std::cout << *ip1 << " + " << *ip2 << " = " << *ivalue << std::endl;
}

void test02_MemoryFuntions()
{
    // T = int*
    Calculator<int*> intCalc;
    std::unique_ptr<int> up1 = std::make_unique<int>(10);
    std::unique_ptr<int> up2 = std::make_unique<int>(11);

    intCalc.memoryStore(up1);
    intCalc.memoryAdd(up2);
    std::unique_ptr<int> result = intCalc.memoryRecall();
    std::cout << *up1 << " + " << *up2 << " = " << *result << std::endl;
}

void test02()
{
    test02_ArithmeticFuntions();
    test02_MemoryFuntions();
}

// =======================================================================
// End-of-File
// =======================================================================
