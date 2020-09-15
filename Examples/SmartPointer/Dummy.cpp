// ===========================================================================
// Dummy.cpp // Dummy Class for Testing Purposes
// ===========================================================================

#include <iostream>
#include <string>

#include "Dummy.h"

std::ostream& operator<< (std::ostream& os, const Dummy& dummy) {
    os << "Dummy [" << dummy.m_dummy << ']';
    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================
