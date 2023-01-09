// =======================================================================
// CalculatorPtr.h
// =======================================================================

#pragma once

#include "Calculator.h"

#include <memory>

// Class Template Partial Specialization
template <typename T, typename U>
class Calculator<T*, U>
{
private:
    T m_memory;

public:
    Calculator() : m_memory{} {}

    // arithmetic functions
    std::unique_ptr<T> add(const std::unique_ptr<T>& ux, const std::unique_ptr<T>& uy) {
        return std::make_unique<T>(*ux + *uy);
    }


    // tbd
    T sub(T x, T y) { return x - y; }
    T mul(T x, T y) { return x * y; }
    T div(T x, T y) { return x / y; }

    // memory functions
    void memoryStore(const std::unique_ptr<T>& up) { m_memory = *up; }

    void memoryClear() {
        m_memory = {};
    }   // geht auch m_memory = {};  //  m_memory = T{};

    std::unique_ptr<T> memoryRecall() { return std::make_unique<T>(m_memory); }

    void memoryAdd(const std::unique_ptr<T>& up) { m_memory += *up; }

    void memorySub(const std::unique_ptr<T>& up) { m_memory -= *up; }


    // tbd
    T NThRoot() {}
    T NThPower() {}
    T Inverse() {}
};

// =======================================================================
// End-of-File
// =======================================================================
