// ===========================================================================
// Phonebook.h
// ===========================================================================

#pragma once

class Phonebook
{
private:
    std::vector<Contact> m_vec;

public:
    // public helper class - providing functor for STL algorithms
    class Printer
    {
    private:
        std::ostream& m_os;

    public:
        Printer(std::ostream& os) : m_os(os) {}
        void operator() (const Contact& contact);
    };

private:
    // private helper classes - providing functors for STL algorithms
    class SearcherContact
    {
    private:
        const std::string& m_firstName;
        const std::string& m_lastName;

    public:
        SearcherContact(const std::string& firstName, const std::string& lastName)
            : m_firstName(firstName), m_lastName(lastName) {}
        bool operator() (const Contact& contact);
    };

    class SearcherLastName
    {
    private:
        const std::string& m_lastName;

    public:
        SearcherLastName(const std::string& lastName) : m_lastName(lastName) {}
        bool operator() (const Contact& contact);
    };

    class SearcherFullNameAndNumber
    {
    private:
        const std::string& m_firstName;
        const std::string& m_lastName;
        const long m_number;

    public:
        SearcherFullNameAndNumber(const std::string& firstName, const std::string& lastName, long number)
            : m_firstName(firstName), m_lastName(lastName), m_number(number) {}
        bool operator() (const Contact& contact);
    };

    class Inserter
    {
    private:
        Phonebook& m_book;

    public:
        Inserter(Phonebook& book) : m_book(book) {}
        void operator() (const Contact& book);
    };

    struct Appender
    {
    public:
        std::string operator() (const std::string& first, const Contact& next);
    };

    struct Comparer
    {
        bool operator() (const Contact&, const Contact&);
    };

private:
    // wrapping a Standard Library container
    std::vector<Contact>::iterator begin() { return m_vec.begin(); }
    std::vector<Contact>::iterator end() { return m_vec.end(); }

public:
    // public interface
    size_t size();
    bool insert(const std::string& firstName, const std::string& lastName, long number);
    bool insert(const Contact&);
    bool contains(const std::string& firstName, const std::string& lastName);
    bool find(const std::string& firstName, const std::string& lastName, long& number);
    std::vector<Contact> findAll(const std::string& lastName);
    bool remove(const std::string& firstName, const std::string& lastName, long number);
    bool update(const std::string& firstName, const std::string& lastName, long number);
    void import(const Phonebook& book);
    std::string toString();
    void sort();

    friend std::ostream& operator<<(std::ostream&, const Phonebook&);
};

// ===========================================================================
// End-of-File
// ===========================================================================
