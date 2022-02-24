// ===========================================================================
// Account.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>

#include "IAccount.h"
#include "Account.h"

namespace AccountsAndBank {

    Account::Account(int accountNumber) 
        : m_accountNumber(accountNumber), m_balance(0) {}

    void Account::deposit(double amount) {
        m_balance += amount;
    }

    double Account::getAccountNumber() {
        return m_accountNumber;
    }

    double Account::getBalance() {
        return m_balance;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
