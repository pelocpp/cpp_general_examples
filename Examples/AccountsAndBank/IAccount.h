// ===============================================================================
// IAccount.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

namespace AccountsAndBank {

    class IAccount
    {
    public:
        // getter / setter
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
