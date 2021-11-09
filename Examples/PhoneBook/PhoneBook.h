// ===========================================================================
// Phonebook.h
// ===========================================================================

class Phonebook
{
private:
    std::vector<Contact> m_phonebookVec;

private:
    struct OutputCallable
    {
        std::ostream& m_os;
        OutputCallable(std::ostream& os) : m_os(os) {}
        void operator() (const Contact& contact);
    };

    struct SearchNameCallable
    {
    private:
        std::string m_firstName;
        std::string m_lastName;

    public:
        SearchNameCallable(const std::string& firstName, const std::string& lastName)
            : m_firstName(firstName), m_lastName(lastName) {}

        bool operator() (const Contact& contact) {

            if (contact.getFirstName() == m_firstName && contact.getLastName() == m_lastName) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    struct SearchNameAndNumberCallable
    {
    private:
        std::string m_firstName;
        std::string m_lastName;
        long m_number;

    public:
        SearchNameAndNumberCallable(
            const std::string& firstName, const std::string& lastName, long number)
            : m_firstName(firstName), m_lastName(lastName), m_number(number) {}

        bool operator() (const Contact& contact) {

            if (contact.getFirstName() == m_firstName &&
                contact.getLastName() == m_lastName &&
                contact.getNumber() == m_number) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    struct ComparerCallable
    {
        bool operator() (const Contact& contact1, const Contact& contact2) {
            if (contact1.getLastName() == contact2.getLastName()) {
                return contact1.getFirstName() < contact2.getFirstName();
            }
            else {
                return contact1.getLastName() < contact2.getLastName();
            }
        }
    };

public:
    size_t size();
    bool insert(const std::string& firstName, const std::string& lastName, long number);
    bool insert(const Contact& contact);
    bool contains(const std::string& firstName, const std::string& lastName);
    bool find(const std::string& firstName, const std::string& lastName, long& number);
    std::vector<Contact> findAll(const std::string& firstName, const std::string& lastName);
    bool remove(const std::string& firstName, const std::string& lastName, long number);
    bool update(const std::string& firstName, const std::string& lastName, long number);
    std::string toString();
    void sort();

    friend std::ostream& operator<<(std::ostream&, const Phonebook&);
};
 
// ===========================================================================
// End-of-File
// ===========================================================================
