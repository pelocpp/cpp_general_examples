// ===========================================================================
// Contact.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <vector>

#include "Contact.h"
#include "PhoneBook.h"

std::ostream& operator<< (std::ostream& os, const Contact& contact) {

    os << contact.getFirstName() << ", "
       << contact.getLastName() << ": "
       << contact.getNumber();

    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================

