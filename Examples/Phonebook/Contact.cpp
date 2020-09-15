// ===========================================================================
// Contact.cpp // class Contact - Implementation
// ===========================================================================

#include <iostream>
#include <fstream>
#include <iomanip> 

#include "Contact.h"

namespace PhonebookDemo {

    // default c'tor
    Contact::Contact()
        : m_firstName(""), m_lastName(""), m_email(""), m_phonenumber(0) {
        std::cout << "c'tor Contact()" << std::endl;
    }

    // user-defined c'tors
    Contact::Contact(std::string firstName, std::string lastName) :
        m_firstName(firstName), m_lastName(lastName),
        m_email(""), m_phonenumber(0) {
        std::cout << "c'tor Contact(std::string, std::string)" << std::endl;
    }

    Contact::Contact(
        std::string firstName, 
        std::string lastName,
        std::string email,
        size_t phonenumber) : 
            m_firstName(firstName), m_lastName(lastName),
            m_email(email), m_phonenumber(phonenumber) {
            std::cout 
                << "c'tor Contact(string, string, string, size_t)"
                << std::endl;
    }

    Contact::~Contact() {
        std::cout << "d'tor Contact()" << std::endl;
    }

    bool Contact::nameEquals(
        const std::string& firstName,
        const std::string& lastName) const
    {
        return m_firstName == firstName && m_lastName == lastName;
    }

    bool operator== (const Contact& lhs, const Contact& rhs) {

        return lhs.nameEquals(rhs.getFirstName(), rhs.getLastName());
    }

    std::ostream& operator<< (std::ostream& os, const Contact& obj) {

        const std::type_info& ti1 = typeid(os);
        const std::type_info& ti2 = typeid(std::ostream);
        const std::type_info& ti3 = typeid(std::ofstream);

        if (ti1.hash_code() == ti2.hash_code()) {
            // output to screen
            os << "Contact: " << std::setw(10) << std::right 
                << obj.m_firstName << ' ' << std::setw(10) 
                << std::left << obj.m_lastName << " - ";
            os << "Phone: " << obj.m_phonenumber << ".";
        }
        else if (ti1.hash_code() == ti3.hash_code()) {
            // output to file
            os << obj.m_firstName << std::endl;
            os << obj.m_lastName << std::endl;
            os << obj.m_email << std::endl;
            os << obj.m_phonenumber << std::endl;
        }
        return os;
    }

    std::istream& operator >> (std::istream& in, Contact& obj)
    {
        const std::type_info& ti1 = typeid(in);
        const std::type_info& ti2 = typeid(std::istream);
        const std::type_info& ti3 = typeid(std::ifstream);

        if (ti1.hash_code() == ti2.hash_code()) {
            // input from screen
            std::cout << "Enter First Name: ";
            in >> obj.m_firstName;
            std::cout << "Enter Last Name: ";
            in >> obj.m_lastName;
            std::cout << "Enter E-Mail: ";
            in >> obj.m_email;
            std::cout << "Enter Private Number: ";
            in >> obj.m_phonenumber;
        }
        else if (ti1.hash_code() == ti3.hash_code()) {
            // input from file
            in >> obj.m_firstName;
            in >> obj.m_lastName;
            in >> obj.m_email;
            in >> obj.m_phonenumber;
        }
        return in;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
