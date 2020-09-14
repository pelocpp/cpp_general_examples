// ===============================================================================
// CurrentAccount.cpp // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

namespace AccountsAndBank {

    class CurrentAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const CurrentAccount&);

    private:
        double m_limit;

    public:
        // c'tors
        CurrentAccount(int account);
        CurrentAccount(int account, double limit);

        // getter / setter
        double getLimit();
        void setLimit(double limit);

        // public interface
        bool withdraw(double amount) override;
        void print(std::ostream& os) override;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
