// ===========================================================================
// Phonebook.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

#include "PhoneBook.h"

class Contact
{
public:
    Contact(const std::string& firstName, const std::string& lastName, long number)
        : m_firstName(firstName), m_lastName(lastName), m_number(number) {}

private:
    std::string m_firstName;
    std::string m_lastName;
    long m_number;

public:
    // getter / setter
    const std::string& getFirstName() const { return m_firstName; }
    const std::string& getLastName()  const { return m_lastName; }
    long getNumber() const { return m_number; }
    void setNumber(long number) { m_number = number; }
};

class IPhonebook
{
    // to be done
};

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

void Phonebook::OutputCallable::operator() (const Contact& contact) {
    m_os
        << contact.getFirstName() << ", "
        << contact.getLastName() << ": "
        << contact.getNumber() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Phonebook& book)
{
    std::for_each(
        book.m_phonebookVec.begin(),
        book.m_phonebookVec.end(),
        Phonebook::OutputCallable(os)
    );

    return os;
}

size_t Phonebook::size()
{
    return m_phonebookVec.size();
}

bool Phonebook::insert(const std::string& firstName, const std::string& lastName, long number)
{
    if (contains(firstName, lastName)) {
        return false;
    }

    Contact contact(firstName, lastName, number);
    insert(contact);
    return true;
}

bool Phonebook::insert(const Contact& contact)
{
    if (contains(contact.getFirstName(), contact.getLastName())) {
        return false;
    }

    insert(contact);
    return true;
}

bool Phonebook::contains(const std::string& firstName, const std::string& lastName)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        SearchNameCallable(firstName, lastName)
    );

    if (result != m_phonebookVec.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool Phonebook::find(const std::string& firstName, const std::string& lastName, long& number)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        SearchNameCallable(firstName, lastName)
    );

    if (result != m_phonebookVec.end()) {
        number = result->getNumber();
        return true;
    }
    else {
        return false;
    }
}

std::vector<Contact> Phonebook::findAll(const std::string& firstName, const std::string& lastName) {

    std::vector<Contact> matches;

    std::copy_if(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        std::back_inserter(matches),
        SearchNameCallable(firstName, lastName)
    );

    return matches;
}

bool Phonebook::remove(const std::string& firstName, const std::string& lastName, long number)
{
    std::vector<Contact>::iterator it = std::remove_if(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        SearchNameAndNumberCallable(firstName, lastName, number)
    );

    bool success = it != m_phonebookVec.end();
    if (success) {
        m_phonebookVec.erase(it, m_phonebookVec.end());
    }

    return success;
}

bool Phonebook::update(const std::string& firstName, const std::string& lastName, long number)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        SearchNameCallable(firstName, lastName)
    );

    if (result != m_phonebookVec.end()) {
        result->setNumber(number);
        return true;
    }
    else {
        return false;
    }
}

void Phonebook::sort()
{
    std::sort(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        ComparerCallable()
    );
}

std::string Phonebook::toString()
{
    struct AppendContactCallable
    {
    public:
        std::string operator() (const std::string& first, const Contact& next) {

            std::ostringstream ss;
            ss << next.getFirstName() << ", "
                << next.getLastName() << ": "
                << next.getNumber() << std::endl;

            return first + ss.str();
        }
    };

    std::string s;

    s = std::accumulate(
        m_phonebookVec.begin(),
        m_phonebookVec.end(),
        std::string(), // first element
        AppendContactCallable()
    );

    return s;
}

// mergeWithAnotherPhoneBoolk


void initPhoneBook(Phonebook& book)
{
    book.insert("Hans", "Mueller", 12345);
    book.insert("Sepp", "Maier", 12345);
    book.insert("Georg", "Huber", 12345);
    book.insert("Sepp", "Stefan", 12345);
    book.insert("Sepp", "Trollinger", 12345);
}

void test_05()
{
    Phonebook book;

    initPhoneBook(book);

    ////   searchPhoneBook("Sepp");
    //getPhoneBookEntries("Sepppp");

    std::cout << book << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
