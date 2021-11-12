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

#include "Contact.h"
#include "PhoneBook.h"

// ===========================================================================
// class Phonebook - helper classes providing functors for STL algorithms

void Phonebook::Printer::operator() (const Contact& contact)
{
    m_os << contact << std::endl;
}

bool Phonebook::Comparer::operator() (const Contact& contact1, const Contact& contact2)
{
    if (contact1.getLastName() == contact2.getLastName()) {
        return contact1.getFirstName() < contact2.getFirstName();
    }
    else {
        return contact1.getLastName() < contact2.getLastName();
    }
}

bool Phonebook::SearcherContact::operator() (const Contact& contact)
{
    if (contact.getFirstName() == m_firstName && contact.getLastName() == m_lastName) {
        return true;
    }
    else {
        return false;
    }
}

bool Phonebook::SearcherLastName::operator() (const Contact& contact)
{
    if (contact.getLastName() == m_lastName) {
        return true;
    }
    else {
        return false;
    }
}

void Phonebook::Inserter::operator() (const Contact& contact)
{
    m_book.insert(contact);
};

std::string Phonebook::Appender::operator() (const std::string& first, const Contact& next)
{
    std::ostringstream ss;
    ss << next.getFirstName() << ", "
        << next.getLastName() << ": "
        << next.getNumber() << std::endl;

    return first + ss.str();
}

bool Phonebook::SearcherFullNameAndNumber::operator() (const Contact& contact) {

    if (contact.getFirstName() == m_firstName &&
        contact.getLastName() == m_lastName &&
        contact.getNumber() == m_number) {
        return true;
    }
    else {
        return false;
    }
}

// ===========================================================================
// class Phonebook - public interface

size_t Phonebook::size()
{
    return m_vec.size();
}

bool Phonebook::insert(const std::string& firstName, const std::string& lastName, long number)
{
    if (contains(firstName, lastName)) {
        return false;
    }

    Contact contact(firstName, lastName, number);
    m_vec.push_back(contact);
    return true;
}

bool Phonebook::insert(const Contact& contact)
{
    return insert(contact.getFirstName(), contact.getLastName(), contact.getNumber());
}

bool Phonebook::contains(const std::string& firstName, const std::string& lastName)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        SearcherContact(firstName, lastName)
    );

    if (result != m_vec.end()) {
        return true;
    }
    else {
        return false;
    }
}

bool Phonebook::find(const std::string& firstName, const std::string& lastName, long& number)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        SearcherContact(firstName, lastName)
    );

    if (result != m_vec.end()) {
        number = result->getNumber();
        return true;
    }
    else {
        return false;
    }
}

std::vector<Contact> Phonebook::findAll(const std::string& lastName) {

    std::vector<Contact> matches;

    std::copy_if(
        m_vec.begin(),
        m_vec.end(),
        std::back_inserter(matches),
        SearcherLastName(lastName)
    );

    return matches;
}

bool Phonebook::remove(const std::string& firstName, const std::string& lastName, long number)
{
    std::vector<Contact>::iterator it = std::remove_if (
        m_vec.begin(),
        m_vec.end(),
        SearcherFullNameAndNumber(firstName, lastName, number)
    );

    bool success = it != m_vec.end();
    if (success) {
        m_vec.erase(it, m_vec.end());
    }

    return success;
}

bool Phonebook::update(const std::string& firstName, const std::string& lastName, long number)
{
    std::vector<Contact>::iterator result = std::find_if(
        m_vec.begin(),
        m_vec.end(),
        SearcherContact(firstName, lastName)
    );

    if (result != m_vec.end()) {
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
        m_vec.begin(),
        m_vec.end(),
        Comparer()
    );
}

std::string Phonebook::toString()
{
    std::string result = std::accumulate(
        m_vec.begin(),
        m_vec.end(),
        std::string(), // first element
        Appender()
    );

    return result;
}

void Phonebook::import(const Phonebook& book)
{
    std::for_each(
        book.m_vec.begin(),
        book.m_vec.end(),
        Inserter(*this)
    );
}

std::ostream& operator<<(std::ostream& os, const Phonebook& book)
{
    std::for_each(
        book.m_vec.begin(),
        book.m_vec.end(),
        Phonebook::Printer(os)
    );

    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================
