// ===========================================================================
// Phonebook.cpp // class Phonebook - Implementation
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <memory>
#include <functional>
#include <numeric>
#include <iomanip> 

#include "Contact.h"
#include <sstream>

namespace PhonebookDemo {

    // =======================================================================

    /*
     *  global typedef's
     */

    using Phonebook = std::vector<std::unique_ptr<Contact>>;

    // =======================================================================

    /*
     *  global data
     */

    Phonebook myContacts;
    
    // =======================================================================

    /*
     *  helper functions for Phonebook
     */

    size_t size(const Phonebook& phonebook);

    void insert(
        Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        size_t phonenumber);

    void insert(
        Phonebook& phonebook,
        std::string&& firstName,
        std::string&& lastName,
        std::string&& email,
        size_t phonenumber);

    void listContactsClassic(const Phonebook& phonebook);

    void listContactsModern(const Phonebook& phonebook);

    bool containsClassic(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName);

    bool containsModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName);

    bool containsModernEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName);

    std::pair<bool, int> getClassic(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName);

    bool getModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber);

    bool getModernEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber);

    bool getModernExEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber);

    bool updatePhoneNumberModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t phonenumber);

    bool remove(
        Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName);

    void sortByName(Phonebook& phonebook);
    void sortByNumber(Phonebook& phonebook);

    void safeContacts(const Phonebook& from, Phonebook& to);

    void saveTo(const Phonebook& phonebook, const std::string& filename);
    void readFrom(Phonebook& phonebook, const std::string& filename);

    std::string toString(const Phonebook& phonebook);

    // =======================================================================

    std::string toString(const Phonebook& phonebook) {

       int counter = 0;

       std::string s = std::accumulate(
           std::begin(phonebook), 
           std::end(phonebook),
           std::string(""), // first element
           [counter = 0] (const std::string& first, const auto& next) mutable {
                counter++;
                std::ostringstream ss;
                ss << std::setfill('0') << std::setw(2) << counter  << ": "
                << std::setfill(' ') << std::setw(10) << std::right
                << next->getFirstName() << ' ' << std::setw(10)
                << std::left << next->getLastName() << " - ";
                ss << "Phone: " << next->getPhonenumber() << std::endl;

                return first + ss.str();
           }
        );

        return s;
    }


    /*
     *  implementation of helper functions
     */

    size_t size(const Phonebook& phonebook) {
        return phonebook.size();
    }

    void insert(
        Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        size_t phonenumber) {
    
        std::unique_ptr<Contact> pContact = std::make_unique<Contact>(
            firstName,
            lastName,
            email,
            phonenumber);

        phonebook.push_back(std::move(pContact));
    }

    void insert(
        Phonebook& phonebook,
        std::string&& firstName,
        std::string&& lastName,
        std::string&& email,
        size_t phonenumber) {

        std::unique_ptr<Contact> pContact = std::make_unique<Contact>(
            std::move(firstName),
            std::move(lastName),
            std::move(email),
            std::move(phonenumber)
            );

        phonebook.push_back(std::move(pContact));
    }

    bool containsClassic(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName) {

        Phonebook::const_iterator iter = phonebook.begin();
        Phonebook::const_iterator end = phonebook.end();

        while (iter != end) {
            const std::unique_ptr<Contact>& contact = *iter;
            if (contact->nameEquals(firstName, lastName))
                return true;

            ++iter;
        }

        return false;
    }

    bool containsModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName) {

        for (const auto& contact : phonebook) {
            if (contact->nameEquals(firstName, lastName))
                return true;
        }

        return false;
    }

    bool containsModernEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName) {

        Phonebook::const_iterator result = std::find_if(
            std::begin(phonebook),
            std::end(phonebook),
            [&](const auto& contact) {
                return contact->nameEquals(firstName, lastName); 
            }
        );

       return result != std::end(phonebook);
    }

    class NameComparer {
    private:
        std::string m_firstName;
        std::string m_lastName;

    public:

        NameComparer(const std::string& firstName, const std::string& lastName)
            : m_firstName(firstName), m_lastName(lastName) {};

        bool operator()(const std::unique_ptr<Contact>& ptrContact) {
            Contact* pContact = ptrContact.get();
            return ptrContact->nameEquals(m_firstName, m_lastName);
        }
    };

    std::pair<bool, int> getClassic(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName)
    {
        NameComparer condition(firstName, lastName);

        std::pair<bool, int > result(false, -1);

        Phonebook::const_iterator resIt = std::find_if(
            std::begin(phonebook),
            std::end(phonebook),
            condition
        );

        if (resIt != std::end(phonebook)) {
            result.first = true;
            const std::unique_ptr<Contact>& contact = *resIt;
            Contact* ptrContact = contact.get();
            result.second = ptrContact->getPhonenumber();
        }

        return result;
    }

    bool getModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber)
    {
        bool result = false;
        phonenumber = 0;

        Phonebook::const_iterator resIter = std::find_if(
            std::begin(phonebook),
            std::end(phonebook),
            [&] (const std::unique_ptr<Contact>& val) {
                Contact* pContact = val.get();
                return val->nameEquals(firstName, lastName);
            }
        );

        if (resIter != std::end(phonebook)) {
            result = true;
            const std::unique_ptr<Contact>& contact = *resIter;
            Contact* ptrContact = contact.get();
            phonenumber = ptrContact->getPhonenumber();
        }

        return result;
    }

    bool getModernEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber)
    {
        bool result = false;
        phonenumber = 0;

        Phonebook::const_iterator resIter = std::find_if(
            std::begin(phonebook),
            std::end(phonebook),
            [&](const auto& contact) {
                return contact->nameEquals(firstName, lastName);
            }
        );

        if (resIter != std::end(phonebook)) {
            result = true;
            const auto& contact = *resIter;
            Contact* ptrContact = contact.get();
            phonenumber = ptrContact->getPhonenumber();
        }

        return result;
    }

    bool getModernExEx(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t& phonenumber)
    {
        phonenumber = 0;

        for (const auto& contact : phonebook) {
            if (contact->nameEquals(firstName, lastName)) {
                phonenumber = contact->getPhonenumber();
                return true;
            }
        }

        return false;
    }

    bool updatePhoneNumberModern(
        const Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName,
        size_t phonenumber) {

        Phonebook::const_iterator resIter = std::find_if(
            std::begin(phonebook),
            std::end(phonebook),
            [&](const auto& contact) {
                if (contact->nameEquals(firstName, lastName)) {
                    contact->setPhonenumber(phonenumber);
                    return true;
                }
                else {
                    return false;
                }
            }
        );

        return (resIter != std::end(phonebook)) ? true : false;
    }

    bool remove(
        Phonebook& phonebook,
        const std::string& firstName,
        const std::string& lastName) {

        // declaring iterator to a vector 
        std::vector<std::unique_ptr<Contact>>::iterator it;

        // displaying vector elements using begin() and end() 
        for (it = std::begin(phonebook); it != std::end(phonebook); ++it) {

            std::unique_ptr<Contact>& tmp = *it;
            Contact* pContact = tmp.get();

            if (pContact->nameEquals(firstName, lastName)) {
                phonebook.erase(it);
                return true;
            }
        }

        return false;
    }

    bool compareByName(
        const std::unique_ptr<Contact>& a, 
        const std::unique_ptr<Contact>& b) {

        const Contact* pContact1 = a.get();
        const Contact* pContact2 = b.get();

        int diff = pContact1->getLastName().compare(pContact2->getLastName());
        if (diff == 0) {
            int diff2 = 
                pContact1->getFirstName().compare(pContact2->getFirstName());

            return (diff2 >= 0) ? false : true;
        }
        else {
            return (diff >= 0) ? false : true;
        }
    }

    void sortByName(Phonebook& phonebook) {

        std::sort(
            std::begin(phonebook),
            std::end(phonebook),
            [](const std::unique_ptr<Contact>& a, 
                const std::unique_ptr<Contact>& b) {
                return compareByName(a, b);
            }
        );
    }

    void sortByNumber(Phonebook& phonebook) {

        std::sort(
            std::begin(phonebook),
            std::end(phonebook), 
            [](const std::unique_ptr<Contact>& a,
                const std::unique_ptr<Contact>& b) {
                const Contact* pContact1 = a.get();
                const Contact* pContact2 = b.get();
                size_t leftNumber = pContact1->getPhonenumber();
                size_t rightNumber = pContact2->getPhonenumber();
                return (leftNumber < rightNumber) ? true : false;
            }
        );
    }

    void safeContacts(const Phonebook& from, Phonebook& to) {

        // preallocate the space we need - so push_back doesn't have to do that
        to.reserve(from.size());

        // traversing vector: C++11 style
        for (const auto& pContact : from) {
            to.push_back(std::make_unique<Contact>(*pContact));
            // or
            // std::unique_ptr<Contact> tmp = std::make_unique<Contact>(*pContact);
            // to.push_back(std::move(tmp));
        }
    }

    void listContactsClassic(const Phonebook& phonebook) {

        std::cout << "Phonebook:" << std::endl;
        if (phonebook.size() == 0) {
            std::cout << "<empty>" << std::endl;
            return;
        }
        std::vector<std::unique_ptr<Contact>>::const_iterator it;
        for (it = std::begin(phonebook); it != std::end(phonebook); ++it) {
            const std::unique_ptr<Contact>& contact = *it;
            Contact* ptrContact = contact.get();
            std::cout << *ptrContact << std::endl;
        }
        std::cout << std::endl;
    }

    void listContactsModern(const Phonebook& phonebook) {

        // displaying vector elements: C++17 style
        std::cout << "Phonebook:" << std::endl;
        if (phonebook.size() == 0) {
            std::cout << "<empty>" << std::endl;
            return;
        }
        for (const auto& contact : phonebook) {
            std::cout << *contact << std::endl;
        }
        std::cout << std::endl;
    }

    void saveTo(const Phonebook& phonebook, const std::string& filename) {

        std::ofstream outfile(filename);
        for (const auto& pContact : phonebook) {
            outfile << *pContact;
        }
        outfile.close();
    }

    void readFrom(Phonebook& phonebook, const std::string& filename) {

        std::ifstream infile(filename);
        while (!infile.eof()) {
            Contact contact;
            infile >> contact;

            // simple verification test
            if (contact.getFirstName().empty() || contact.getLastName().empty())
                break;

            phonebook.push_back(std::make_unique<Contact>(contact));
        }
        infile.close();
    }

    void inAndOutFromVector(Phonebook& phonebook) {

        listContactsModern(phonebook);
        std::unique_ptr<Contact> outside = std::move(phonebook[0]);
        Contact* pContact = outside.get();
        pContact->setPhonenumber(pContact->getPhonenumber() + 1);
        phonebook[0] = std::move(outside);
        listContactsModern(phonebook);
    }

    // =======================================================================

    /*
     *  testing functions
     */

    void test_01() {

        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 1234);
        insert(myContacts, "Franz", "Meier", "franz@gmx.de", 5678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 11111);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 88888);

        listContactsClassic(myContacts);

        std::string susanFirst("Susan");
        std::string susanLast("Schmidt");
        std::string susanEmail("susan@gmx.de");
        size_t susanPhone{ 13579 };
        insert(myContacts, susanFirst, susanLast, susanEmail, susanPhone);

        listContactsClassic(myContacts);
    }

    void test_02() {

        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 1234);
        insert(myContacts, "Franz", "Meier", "franz@gmx.de", 5678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 54321);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 88888);
        listContactsClassic(myContacts);

        bool found = containsClassic(myContacts, "Hans", "Meier");
        std::cout << (found ? "Found." : "Not found!") << std::endl;
        found = containsClassic(myContacts, "Franz", "Meier");
        std::cout << (found ? "Found." : "Not found!") << std::endl;

        found = containsModern(myContacts, "Hans", "Hofmann");
        std::cout << (found ? "Found." : "Not found!") << std::endl;
        found = containsModern(myContacts, "Werner", "Hofmann");
        std::cout << (found ? "Found." : "Not found!") << std::endl;

        found = containsModernEx(myContacts, "Werner", "Mueller");
        std::cout << (found ? "Found." : "Not found!") << std::endl;
        found = containsModernEx(myContacts, "Werner", "Hofmann");
        std::cout << (found ? "Found." : "Not found!") << std::endl;
    }

    void test_03() {

        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 1234);
        insert(myContacts, "Franz", "Meier", "franz@gmx.de", 5678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 11111);
        listContactsClassic(myContacts);

        std::pair<bool, int> result = getClassic(myContacts, "Hans", "Meier");
        std::cout 
            << (result.first ? "Found: " : "Not found!") 
            << (result.first ? std::to_string(result.second) : "") << std::endl;

        size_t phonenumber;
        bool found = getModern(myContacts, "Hans", "Meier", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;

        found = getModernEx(myContacts, "Hans", "Meier", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;

        found = getModernExEx(myContacts, "Hans", "Meier", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;

        result = getClassic(myContacts, "Werner", "Hofmann");
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(result.second) : "") << std::endl;

        found = getModern(myContacts, "Werner", "Hofmann", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;

        found = getModernEx(myContacts, "Werner", "Hofmann", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;

        found = getModernExEx(myContacts, "Werner", "Hofmann", phonenumber);
        std::cout
            << (result.first ? "Found: " : "Not found!")
            << (result.first ? std::to_string(phonenumber) : "") << std::endl;
    }

    void test_04() {

        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 1234);
        insert(myContacts, "Franz", "Meier", "franz@gmx.de", 5678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 11111);
        listContactsModern(myContacts);

        bool result = updatePhoneNumberModern(
            myContacts,
            "Franz",
            "Meier",
            875433
        );
        std::cout << (result ? "Updated!" : "Not found!")<< std::endl;
        listContactsModern(myContacts);

        result = updatePhoneNumberModern(
            myContacts,
            "Hans",
            "Hofmann",
            12345
        );
        std::cout << (result ? "Updated!" : "Not found!") << std::endl;
        listContactsModern(myContacts);
    }

    void test_05() {

        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 1234);
        insert(myContacts, "Franz", "Meier", "franz@gmx.de", 5678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 11111);
        listContactsModern(myContacts);

        bool result = remove(myContacts, "Franz", "Meier");
        std::cout << (result ? "Removed!" : "Not found!") << std::endl;
        listContactsModern(myContacts);

        result = remove(myContacts, "Hans", "Mueller");
        std::cout << (result ? "Removed!" : "Not found!") << std::endl;
        listContactsModern(myContacts);

        result = remove(myContacts, "Werner", "Hofmann");
        std::cout << (result ? "Removed!" : "Not found!") << std::endl;
        listContactsModern(myContacts);
    }

    void test_06() {

        insert(myContacts, "Franz", "Schneider", "franzschneider@gmx.de", 123456);
        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 435261);
        insert(myContacts, "Franz", "Meier", "franzmeier@gmx.de", 545678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 111111);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 888888);

        listContactsModern(myContacts);
        sortByName(myContacts);
        listContactsModern(myContacts);
        sortByNumber(myContacts);
        listContactsModern(myContacts);
    }

    void test_07() {

        insert(myContacts, "Franz", "Schneider", "franzschneider@gmx.de", 123456);
        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 435261);
        insert(myContacts, "Franz", "Meier", "franzmeier@gmx.de", 545678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 111111);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 888888);

        Phonebook myContactsSave;
        safeContacts(myContacts, myContactsSave);
        listContactsModern(myContacts);
        listContactsModern(myContactsSave);
    }

    void test_08() {

        insert(myContacts, "Franz", "Schneider", "franzschneider@gmx.de", 123456);
        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 435261);
        insert(myContacts, "Franz", "Meier", "franzmeier@gmx.de", 545678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 111111);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 888888);
        listContactsModern(myContacts);

        saveTo(myContacts, std::string("phonebook.txt"));
        myContacts.clear();
        listContactsModern(myContacts);

        readFrom(myContacts, std::string("phonebook.txt"));
        listContactsModern(myContacts);
    }

    void test_09() {

        Contact contact;
        std::cin >> contact;

        myContacts.push_back(std::make_unique<Contact>(contact));
        listContactsModern(myContacts);
    }

    void test_10() {

        insert(myContacts, "Franz", "Schneider", "franzschneider@gmx.de", 123456);
        insert(myContacts, "Hans", "Mueller", "hans@gmx.de", 435261);
        insert(myContacts, "Franz", "Meier", "franzmeier@gmx.de", 545678);
        insert(myContacts, "Werner", "Hofmann", "werner@gmx.de", 111111);
        insert(myContacts, "Andreas", "Diehler", "andreas@gmx.de", 888888);
        listContactsModern(myContacts);

        std::cout << toString(myContacts) << std::endl;
    }

    void test_11() {
        insert(myContacts, "Franz", "Schneider", "franzschneider@gmx.de", 123456);
        inAndOutFromVector(myContacts);
    }
}

void main_phonebook() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    using namespace PhonebookDemo;
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    test_09();
    test_10();
    test_11();
}

// =======================================================================
// End-of-File
// =======================================================================
