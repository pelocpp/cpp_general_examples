// ===========================================================================
// Contact.h
// ===========================================================================

#pragma once

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

std::ostream& operator<< (std::ostream&, const Contact&);

// ===========================================================================
// End-of-File
// ===========================================================================
