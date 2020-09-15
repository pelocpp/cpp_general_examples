// ===============================================================================
// Contact.h // class Contact - Interface Definition
// ===============================================================================

namespace PhonebookDemo {

    class Contact {
    public:
        // c'tor(s) and d'tor
        Contact();  // default c'tor
        Contact(const Contact&) = default;  // copy c'tor
        Contact(std::string firstName, std::string lastName); // user-def. c'tor
        Contact(
            std::string firstName,
            std::string lastName,
            std::string email, 
            size_t phonenumber);

        virtual ~Contact();

        // move-assignment and move-copy
        Contact(Contact&&) = default;
        Contact& operator= (Contact&&) = default;

        // getter / setter
        const std::string& getFirstName() const { return m_firstName; }
        const std::string& getLastName() const { return m_lastName; }
        size_t getPhonenumber() const { return m_phonenumber; }
        void setPhonenumber(size_t phonenumber) { m_phonenumber = phonenumber; }

        // comparison operator(s) - needed for std::find
        friend bool operator== (const Contact&, const Contact&);

        // assignment operator
        Contact& operator= (const Contact& contact) = default;

        // public helper method
        bool nameEquals(
            const std::string& firstName, 
            const std::string& lastName) const;

        // input and output
        friend std::ostream& operator<< (std::ostream& os, const Contact& obj);
        friend std::istream& operator >> (std::istream& in, Contact& obj);

    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_email;
        size_t m_phonenumber;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
