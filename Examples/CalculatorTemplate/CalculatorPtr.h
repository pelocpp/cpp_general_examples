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
    std::unique_ptr<T> add(const std::unique_ptr<T>& up1, const std::unique_ptr<T>& up2) {
        return std::make_unique<T>(*up1 + *up2);
    }

    T sub(const std::unique_ptr<T>& up1, const std::unique_ptr<T>& up2) {
        return std::make_unique<T>(*up1 - *up2);
    }

    T mul(const std::unique_ptr<T>& up1, const std::unique_ptr<T>& up2) {
        return std::make_unique<T>(*up1 * *up2);
    }

    T div(const std::unique_ptr<T>& up1, const std::unique_ptr<T>& up2) {
        return std::make_unique<T>(*up1 / *up2);
    }

    // memory functions
    void memoryStore(const std::unique_ptr<T>& up) { m_memory = *up; }
    void memoryClear() { m_memory = T{}; } 
    std::unique_ptr<T> memoryRecall() { return std::make_unique<T>(m_memory); }
    void memoryAdd(const std::unique_ptr<T>& up) { m_memory += *up; }
    void memorySub(const std::unique_ptr<T>& up) { m_memory -= *up; }

    // tbd
    T NThPower() {}
    T Inverse(const std::unique_ptr<T>& up) { return 1 / *up; }
};

// =======================================================================
// End-of-File
// =======================================================================
