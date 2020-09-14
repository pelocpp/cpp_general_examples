// ===============================================================================
// IAccount.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

namespace AccountsAndBank {

    class IAccount
    {
    public:
        virtual ~IAccount() = default;

        // getter/setter
        virtual double getAccountNumber() = 0;
        virtual double getBalance() = 0;

        // public interface
        virtual void deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
        virtual void print(std::ostream& os) = 0;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
