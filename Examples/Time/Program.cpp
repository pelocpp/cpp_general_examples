// ===========================================================================
// Program.cpp
// ===========================================================================

#include "Time.h"

void TestCtors()
{
    Time t1;
    std::cout << t1 << std::endl;
    Time t2(0, 30, 12);
    std::cout << t2 << std::endl;
    Time t3("09:30:00");
    std::cout << t3 << std::endl;
    Time t4(24 * 60 * 60 - 1);
    std::cout << t4 << std::endl;
}

void TestAdd()
{
    // testing 'Add'
    Time t1(0, 0, 12);
    Time t2(33, 33, 3);
    for (int i = 0; i < 5; i++)
    {
        t1.Add(t2);
        std::cout << t1 << std::endl;
    }
}

void TestDiff()
{
    // testing 'Diff'
    Time t1;
    Time t2("23:59:59");
    Time t3 = t1.Diff(t2);
    std::cout << t3 << std::endl;
    t3 = t2.Diff(t1);
    std::cout << t3 << std::endl;
}

void TestArithmeticOperators()
{
    // testing operators
    Time t1(15, 30, 6);
    Time t2 = t1 + t1;
    std::cout << t2 << std::endl;
    t2 += t1;
    std::cout << t2 << std::endl;
    t2 -= 120;
    std::cout << t2 << std::endl;
    t2 -= t1;
    std::cout << t2 << std::endl;
}

void TestIncrementOperators()
{
    // testing 'Increment'
    Time t(55, 59, 23);
    for (int i = 0; i < 8; i++)
    {
        t.Increment();
        std::cout << t << std::endl;
    }
}

void TestIncrementDecrementOperators()
{
    // testing increment/decrement operator
    Time t1(0, 0, 12);
    Time t2 = t1++;
    std::cout << t2 << std::endl;
    t2 = ++t1;
    std::cout << t2 << std::endl;
    t2 = t1--;
    std::cout << t2 << std::endl;
    t2 = --t1;
    std::cout << t2 << std::endl;
}

void TestConversion()
{
    Time t;
    t = 60 * 60 + 60 + 1;
    std::cout << "Time:    " << t << std::endl;
    std::cout << "Seconds: " << (int)t << std::endl;
}

void TestInputOutput()
{
    Time t;
    std::cin >> t;
    std::cout << t << std::endl;
}

int main ()
{
    TestCtors();
    TestAdd();
    TestDiff();
    TestArithmeticOperators();
    TestIncrementOperators();
    TestIncrementDecrementOperators();
    TestConversion();
    TestInputOutput();

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================



