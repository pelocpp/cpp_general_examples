// ===========================================================================
// Fraction.cpp
// ===========================================================================

#include <iostream>

#include "Fraction.h"

// c'tors
Fraction::Fraction() : m_num{}, m_denom{ 1 } { }

Fraction::Fraction(int num, int denom) 
    : m_num{ num }, m_denom{ (denom == 0) ? 1 : denom }
{
    checkSigns();
    reduce();
}

// implementation of binary arithmetic methods
Fraction Fraction::add (const Fraction& f) const
{
    int num = m_num * f.m_denom + m_denom * f.m_num;
    int denom = m_denom * f.m_denom;
    return { num, denom };
}

Fraction Fraction::sub (const Fraction& f) const
{
    int num = m_num * f.m_denom - m_denom * f.m_num;
    int denom = m_denom * f.m_denom;
    return { num, denom };
}

Fraction Fraction::mul (const Fraction& f) const
{
    int num = m_num * f.m_num;
    int denom = m_denom * f.m_denom;
    return { num, denom };
}

Fraction Fraction::div (const Fraction& f) const
{
    int num = m_num * f.m_denom;
    int denom = m_denom * f.m_num;
    return { num, denom };
}

// private helper method
void Fraction::checkSigns()
{
    // normalize fraction
    if (m_denom < 0)
    {
        m_num *= -1;
        m_denom *= -1;
    }
}

void Fraction::reduce()
{
    int sign{ (m_num < 0) ? -1 : 1 };
    int gcd{ Fraction::gcd(sign * m_num, m_denom) };
    m_num /= gcd;
    m_denom /= gcd;
}

int Fraction::gcd(int n, int m)
{
    // calculate greatest common divisor of numerator and denominator
    if (n != m)
    {
        while (m > 0)
        {
            int rem{ n % m };
            n = m;
            m = rem;
        }
    }

    return n;
}

// output operator
std::ostream& operator<< (std::ostream& os, const Fraction& f)
{
    os << f.m_num << '/' << f.m_denom;
    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================