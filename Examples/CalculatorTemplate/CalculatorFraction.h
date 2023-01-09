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
    Fraction add(const Fraction& x, const Fraction& y) { return x.add(y); }
    Fraction sub(const Fraction& x, const Fraction& y) { return x.sub(y); }
    Fraction mul(const Fraction& x, const Fraction& y) { return x.mul(y); }
    Fraction div(const Fraction& x, const Fraction& y) { return x.div(y); }

    //// memory functions
    //void memoryStore(const std::unique_ptr<T>& up) { m_memory = *up; }

    //void memoryClear() {
    //    m_memory = {};
    //}   // geht auch m_memory = {};  //  m_memory = T{};

    //std::unique_ptr<T> memoryRecall() { return std::make_unique<T>(m_memory); }

    //void memoryAdd(const std::unique_ptr<T>& up) { m_memory += *up; }

    //void memorySub(const std::unique_ptr<T>& up) { m_memory -= *up; }


    //// tbd
    //T NThRoot() {}
    //T NThPower() {}
    //T Inverse() {}
};

// =======================================================================
// End-of-File
// =======================================================================
