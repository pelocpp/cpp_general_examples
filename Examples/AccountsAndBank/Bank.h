// ===============================================================================
// Bank.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

namespace AccountsAndBank {

    constexpr int MaxAccounts = 100;

    class Bank
    {
        friend std::ostream& operator<< (std::ostream&, const Bank&);

    private:
        std::string m_name;
        std::vector<IAccount*> m_accounts;

    private:
        static int g_availableAccountNumber;

    public:
        // c'tors
        Bank() = default;
        Bank(std::string name);

        // public interface
        int createCurrentAccount(double limit);
        int createDepositAccount(double interestRate);
        int createStudentsAccount();
        bool deleteAccount(int accountNumber);

        bool deposit(int accountNumber, double amount);
        bool withdraw(int accountNumber, double amount);
        bool transfer(int from, int to, double amount);

        // getter / setter
        double getTotalBalance();
    };
}
    
// ===============================================================================
// End-of-File
// ===============================================================================
