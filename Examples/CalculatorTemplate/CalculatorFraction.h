// =======================================================================
// CalculatorFraction.h
// =======================================================================

#pragma once

#include "Fraction.h"
#include "Calculator.h"

// Class Template Full Specialization (Explicit Specialization)
template <>
class Calculator<Fraction>
{
private:
    Fraction m_memory;

public:
    Calculator() : m_memory{} {}

    // arithmetic functions
    Fraction add(const Fraction& f1, const Fraction& f2) { return f1.add(f2); }
    Fraction sub(const Fraction& f1, const Fraction& f2) { return f1.sub(f2); }
    Fraction mul(const Fraction& f1, const Fraction& f2) { return f1.mul(f2); }
    Fraction div(const Fraction& f1, const Fraction& f2) { return f1.div(f2); }

    // memory functions
    void memoryStore(const Fraction& f) { m_memory = f; }
    void memoryClear() { m_memory = Fraction{}; }
    Fraction memoryRecall() { return m_memory; }
    void memoryAdd(const Fraction& f) { m_memory = m_memory.add(f); }
    void memorySub(const Fraction& f) { m_memory = m_memory.sub(f); }

    template <size_t TN>
    Fraction NThPower(const Fraction& f) {
        Fraction result{ 1, 1 };
        for (size_t i{}; i != TN; ++i) {
            result = result.mul(f);
        }
        return result;
    }

    //// tbd
    //T NThRoot() {}
    //T NThPower() {}
    //T Inverse() {}
};

// =======================================================================
// End-of-File
// =======================================================================
