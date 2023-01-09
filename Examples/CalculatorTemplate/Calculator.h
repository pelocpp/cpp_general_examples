// =======================================================================
// Calculator.h
// =======================================================================

#pragma once

#include <type_traits>

// Primary Class Template
template <typename T, typename U = int>
class Calculator
{
private:
    T m_memory;

public:
    Calculator () : m_memory{} {}

    // arithmetic methods
    T add(T x, T y) { return x + y; }
    T sub(T x, T y) { return x - y; }
    T mul(T x, T y) { return x * y; }
    T div(T x, T y) { return x / y; }

    // memory methods
    void memoryStore(T x) { m_memory = x; }
    void memoryClear() { m_memory = T{}; }
    T memoryRecall() { return m_memory; }
    void memoryAdd(T x) { m_memory += x; }
    void memorySub(T x) { m_memory -= x; }

    // some more functions
    T NThRoot () {}

    template <size_t TN>
    T NThPower(T x) {
        T result{ 1 };
        for (size_t i{}; i != TN; ++i) {
            result *= x;
        }
        return result;
    }

    T Inverse(T x) { return 1 / x; }

    U factorial (int n) {
        static_assert(std::is_unsigned<U>::value);

        U facul{ 1 };
        for (int i{ 1 }; i <= n; ++i) {
            facul *= i;
        }

        return facul;
    }
};

 // Template specialization of a single method from a class template
template <>
int inline Calculator<int>::div(int n, int m) {
    // rounding instead of truncation
    std::cout << "rounding ..." << std::endl;
    return static_cast<int>(((n / (double)m) + 0.5));
}

// =======================================================================
// End-of-File
// =======================================================================
