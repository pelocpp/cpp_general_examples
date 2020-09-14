// ===========================================================================
// StudentsAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>

#include "IAccount.h"
#include "Account.h"
#include "StudentsAccount.h"

namespace AccountsAndBank {

    StudentsAccount::StudentsAccount(int accountNumber)
        : Account(accountNumber) {}

    bool StudentsAccount::withdraw(double amount) {
        if (m_balance < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    void StudentsAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const StudentsAccount& ca) {
        os << "StudentsAccount [Nr. " << ca.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << ca.m_balance << ";" << std::endl;
        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
