#include <stdio.h>

#include <iostream>
using namespace std;

#include "String.h"

// c'tors and d'tor
String::String ()
{
    cout << "c'tor ()" << endl;

    m_len = 0;
    m_ptr = (char*) 0;
}

String::String (const char* s)
{
    cout << "c'tor (char*)" << endl;

    // length of string
    m_len = 0;
    while (s[m_len] != '\0')
        m_len ++;

    // allocate buffer
    m_ptr = new char[m_len];

    // copy argument
    for (int i = 0; i < m_len; i ++)
        m_ptr[i] = s[i];
}


// Nur zu Testzwecken: shallow copy
//String::String (const String& s)
//{
//    cout << "c'tor (const String&)" << endl;
//
//    // shallow copy
//    m_len = s.m_len;
//    m_ptr = s.m_ptr;
//}

String::String (const String& s)
{
    // allocate new buffer
    m_len = s.m_len;
    m_ptr = new char[m_len];

    // deep copy
    for (int i = 0; i < m_len; i ++)
        m_ptr[i] = s.m_ptr[i];
}

String::~String ()
{
    cout << "d'tor" << endl;
    delete[] m_ptr;
}

// assignment operator
String& String::operator= (const String& s)
{
    if (this != &s)
    {
        // delete old string
        delete[] m_ptr;

        // allocate new buffer
        m_len = s.m_len;
        m_ptr = new char[m_len];

        // deep copy
        for (int i = 0; i < m_len; i ++)
            m_ptr[i] = s.m_ptr[i];
    }

    return *this;
}

String String::ToUpperCase ()
{
    char* buffer = new char[m_len + 1];
    for (int i = 0; i < m_len; i++)
        buffer[i] = (m_ptr[i] >= 'a' && m_ptr[i] <= 'z') ?
            m_ptr[i] + ('A' - 'a') : m_ptr[i];
    buffer[m_len] = '\0';

    String s(buffer);
    delete[] buffer;
    return s;
}

void String::Print ()
{
    for (int i = 0; i < m_len; i++)
        printf ("%c", m_ptr[i]);
    printf ("\n");
}

