// ===========================================================================
// Fraction.h
// ===========================================================================

#pragma once

#include <iostream>

class Fraction
{
    friend std::ostream& operator<< (std::ostream&, const Fraction&);

private:
    // private member data
    int m_num;    // numerator
    int m_denom;  // denominator

public:
    // c'tors
    Fraction();
    Fraction(int, int);

    // getter
    int getNum() const { return m_num; }
    int getDenom() const { return m_denom; }

    // binary arithmetic methods
    Fraction add (const Fraction&) const;
    Fraction sub (const Fraction&) const;
    Fraction mul (const Fraction&) const;
    Fraction div (const Fraction&) const;

private:
    // private helper methods
    void checkSigns();
    void reduce();

    // private class helper method
    static int gcd(int n, int m);
};

// ===========================================================================
// End-of-File
// ===========================================================================