// ===========================================================================
// Program.cpp // Phonebook Main Program
// ===========================================================================

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

#include "Contact.h"
#include "IPhoneBook.h"
#include "PhoneBook.h"

// function prototypes
void main_phonebook_01();
void main_phonebook_02();
void main_phonebook_03();
void main_phonebook_04();
void main_phonebook_05();
void main_phonebook_06();
void main_phonebook_07();
void main_phonebook_08();

void initPhoneBook(Phonebook& book)
{
    book.insert("Hans", "Mueller", 12345);
    book.insert("Sepp", "Wagner", 54321);
    book.insert("Georg", "Huber", 13579);
    book.insert("Anton", "Meier", 86420);
    book.insert("Peter", "Wagner", 95735);
}

void main_phonebook_01()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    bool found = book.contains("Sepp", "Wagner");
    std::cout << std::boolalpha << "Sepp found: " << found << std::endl;

    found = book.contains("Seppp", "Wagner");
    std::cout << std::boolalpha << "Seppp found: " << found << std::endl;
}

void main_phonebook_02()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.find("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    std::vector<Contact> results = book.findAll("Wagner");

    std::cout << "Following 'Wagner' found: " << std::endl;

    std::for_each(
        results.begin(),
        results.end(), 
        Phonebook::Printer(std::cout)
    );
}

void main_phonebook_03()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.find("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    bool result = book.remove("Sepp", "Wagner", number);
    std::cout << "Removed Sepp: " << std::boolalpha << result << std::endl << std::endl;

    std::cout << book << std::endl;
}

void main_phonebook_04()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.find("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    bool result = book.remove("Sepp", "Wagner", number);
    std::cout << "Removed Sepp: " << std::boolalpha << result << std::endl << std::endl;

    std::cout << book << std::endl;
}

void main_phonebook_05()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.find("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    book.update("Sepp", "Wagner", 1122334455);
    std::cout << "Updated number of Sepp" << std::endl;

    found = book.find("Sepp", "Wagner", number);
    std::cout << "Sepp now has number " << number << std::endl;
}

void main_phonebook_06()
{
    Phonebook book;
    initPhoneBook(book);
    std::cout << book.toString() << std::endl;
}

void main_phonebook_07()
{
    Phonebook book;
    initPhoneBook(book);
    std::cout << book.toString() << std::endl;
    book.sort();
    std::cout << book.toString() << std::endl;
}

void main_phonebook_08()
{
    Phonebook book1;
    book1.insert("Hans", "Mueller", 12345);
    book1.insert("Sepp", "Wagner", 54321);
    book1.insert("Georg", "Huber", 13579);
    std::cout << book1 << std::endl;

    Phonebook book2;
    book2.insert("Anton", "Meier", 86420);
    book2.insert("Peter", "Wagner", 95735);
    book2.insert("Georg", "Huber", 13579);
    book2.insert("Manfred", "Schmidt", 6452353);
    std::cout << book2 << std::endl;

    book1.import(book2);
    std::cout << book1 << std::endl;
}

int main()
{
    main_phonebook_01();
    main_phonebook_02();
    main_phonebook_03();
    main_phonebook_04();
    main_phonebook_05();
    main_phonebook_06();
    main_phonebook_07();
    main_phonebook_08();

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
