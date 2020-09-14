// ===========================================================================
// DepositAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>

#include "IAccount.h"
#include "Account.h"
#include "DepositAccount.h"

namespace AccountsAndBank {

    DepositAccount::DepositAccount(int accountNumber)
        : Account(accountNumber), m_interestRate(3.0) {}

    DepositAccount::DepositAccount(int accountNumber, double interestRate)
        : Account(accountNumber), m_interestRate(interestRate) {}

    bool DepositAccount::withdraw(double amount) {
        if (m_balance < amount)
            return false;

        m_balance -= amount;
        return true;
    }

    void DepositAccount::computeInterest(int days) {
        double interest =
            (days * m_interestRate * m_balance) / 365.0 / 100.0;

        m_balance += interest;
    }

    double DepositAccount::getInterestRate() {
        return m_interestRate;
    }

    void DepositAccount::print(std::ostream& os) {
        os << *this;
    }

    std::ostream& operator<< (std::ostream& os, const DepositAccount& da) {
        os << "DepositAccount [Nr. " << da.m_accountNumber << "]:" << std::endl;
        os << "   Balance=" << da.m_balance << ";" << std::endl;
        os << "   InterestRate=" << da.m_interestRate << "." << std::endl;
        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
