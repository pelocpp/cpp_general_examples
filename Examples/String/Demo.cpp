#include <iostream>
using namespace std;

#include "String.h"

void Demo01 ()
{
    String s1 ("ABC");
    String s2 ("12345");
    s1 = s2;
}

void Demo02 ()
{
    String s1("abcdef");
    String s2 = s1.ToUpperCase();
    //s2 = s1.ToUpperCase();
    //s2.Print ();
}

void Demo03 ()
{
    String s1("abcdef");
    String s2;
    s2 = s1.ToUpperCase();
}

void main ()
{
    Demo03 ();
}