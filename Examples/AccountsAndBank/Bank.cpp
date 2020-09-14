// ===========================================================================
// Bank.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===========================================================================

#include <iostream>
#include <string>
#include <vector>

#include "IAccount.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "DepositAccount.h"
#include "StudentsAccount.h"
#include "Bank.h"

namespace AccountsAndBank {

    int Bank::g_availableAccountNumber = 10000;

    // c'tors/d'tor
    Bank::Bank() = default;

    Bank::Bank(std::string name) : m_name(name) {}

    Bank::~Bank()
    {
        deleteAllAccounts();
    }

    int Bank::createCurrentAccount(double limit) {
        g_availableAccountNumber++;
        IAccount* account =
            new CurrentAccount(g_availableAccountNumber, limit);
        m_accounts.push_back(account);
        return g_availableAccountNumber;
    }

    int Bank::createDepositAccount(double interestRate) {
        g_availableAccountNumber++;
        IAccount* account =
            new DepositAccount(g_availableAccountNumber, interestRate);
        m_accounts.push_back(account);
        return g_availableAccountNumber;
    }

    int Bank::createStudentsAccount() {
        g_availableAccountNumber++;
        IAccount* account =
            new StudentsAccount(g_availableAccountNumber);
        m_accounts.push_back(account);
        return g_availableAccountNumber;
    }

    bool Bank::deleteAccount(int accountNumber) {
        std::vector<IAccount*>::iterator iter;
        IAccount* pIAccount = nullptr;

        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            if ((*iter)->getAccountNumber() == accountNumber) {
                pIAccount = *iter;
                break;
            }
        }

        if (pIAccount != nullptr) {
            m_accounts.erase(iter);
            delete pIAccount;
            return true;
        }
        else {
            return false;
        }
    }

    bool Bank::deposit(int accountNumber, double amount) {
        std::vector<IAccount*>::iterator iter;
        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            if ((*iter)->getAccountNumber() == accountNumber) {
                (*iter)->deposit(amount);
                return true;
            }
        }
        return false;
    }

    bool Bank::withdraw(int accountNumber, double amount) {
        std::vector<IAccount*>::iterator iter;
        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            if ((*iter)->getAccountNumber() == accountNumber) {
                bool succeeded = (*iter)->withdraw(amount);
                return succeeded;
            }
        }
        return false;
    }

    bool Bank::transfer(int from, int to, double amount) {
        bool succeeded = false;
        std::vector<IAccount*>::iterator iter;
        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            if ((*iter)->getAccountNumber() == from) {
                succeeded = (*iter)->withdraw(amount);
                break;
            }
        }

        if (succeeded) {
            for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
                if ((*iter)->getAccountNumber() == to) {
                    (*iter)->deposit(amount);
                    return true;
                }
            }
        }
        return false;
    }

    double Bank::getTotalBalance() {
        double total = 0.0;
        std::vector<IAccount*>::iterator iter;
        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            total += (*iter)->getBalance();
        }
        return total;
    }

    // private helper methods
    void Bank::deleteAllAccounts()
    {
        std::vector<IAccount*>::iterator iter;
        for (iter = m_accounts.begin(); iter != m_accounts.end(); ++iter) {
            delete (*iter);
        }
    }

    std::ostream& operator<< (std::ostream& os, const Bank& bank) {
        os << "Bank '" << bank.m_name << "\':" << std::endl;

        std::vector<IAccount*>::const_iterator iter;
        for (iter = bank.m_accounts.begin(); 
            iter != bank.m_accounts.end(); 
            ++iter) {
                IAccount* pIAccount = *iter;
                pIAccount->print(os);
        }

        return os;
    }
}

// ===========================================================================

namespace AccountsAndBank {

    void test_01() {
        std::cout << "Testing accounts:" << std::endl;

        CurrentAccount ca(123456, 1000);
        ca.deposit(100);
        ca.withdraw(40);
        std::cout << ca << std::endl;

        StudentsAccount sa(343434);
        sa.deposit(50);
        sa.withdraw(25);
        std::cout << sa << std::endl;

        DepositAccount da(654321, 4.0);
        da.deposit(200);
        da.withdraw(120);
        da.computeInterest(31);
        std::cout << da << std::endl;
    }

    void test_02() {
        std::cout << "Testing bank:" << std::endl;

        Bank bank("Sparkasse");

        int account = bank.createCurrentAccount(1000);
        bank.deposit(account, 100);
        bank.withdraw(account, 40);

        int anotherAccount = bank.createDepositAccount(3.5);
        bank.deposit(anotherAccount, 200);
        bank.withdraw(anotherAccount, 80);
        std::cout << bank << std::endl;

        bank.transfer(anotherAccount, account, 80);
        std::cout << bank << std::endl;

        double totalBalance = bank.getTotalBalance();
        std::cout << "Bank: Balance=" << bank.getTotalBalance() << std::endl;

        bank.deleteAccount(account);
        bank.deleteAccount(anotherAccount);

        std::cout << "Bank: Balance=" << bank.getTotalBalance() << std::endl;
    }
}

void main_accounts_and_bank()
{
    using namespace AccountsAndBank;
    test_01();
    test_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
