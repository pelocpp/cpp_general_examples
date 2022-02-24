// ===========================================================================
// CurrentAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>

#include "IAccount.h"
#include "Account.h"
#include "CurrentAccount.h"

namespace AccountsAndBank {

    CurrentAccount::CurrentAccount(int accountNumber)
        : CurrentAccount(accountNumber, 1000.0) {}

    CurrentAccount::CurrentAccount(int account, double limit)
        : Account(account), m_limit(limit) {}

    bool CurrentAccount::withdraw(double amount) {
        if (m_balance + m_limit < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    double CurrentAccount::getLimit() {
        return m_limit;
    }

    void CurrentAccount::setLimit(double limit) {
        m_limit = limit;
    }

    void CurrentAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const CurrentAccount& ca) {
        os << "CurrentAccount [Nr. " << ca.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << ca.m_balance << ";" << std::endl;
        os << "   Limit=" << ca.m_limit << "." << std::endl;
        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
