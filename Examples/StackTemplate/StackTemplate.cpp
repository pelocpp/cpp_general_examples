// ===========================================================================
// StackTemplate.cpp // Templated class Stack
// ===========================================================================

#include <iostream>
#include <stdexcept>
#include <string>

#include "TemplateStack.hpp"

namespace TemplateStack {

    void test_01() {

        Stack<int, 3> intStack;
        intStack.push(1);
        intStack.push(2);
        intStack.push(3); 

        // print contents of stack 
        for (int i = 0; i < intStack.size(); i++) {
            int value = intStack.pop();
            std::cout << value << std::endl;
        }
    }

    void test_02() {

        Stack<int, 3> intStack1;
        Stack<int, 3> intStack2;
        Stack<int, 6> intStack3;

        intStack1 = intStack2;    // compiles   
        // intStack1 = intStack3; // doesn't compile

        Stack<double> doubleStack1;
        Stack<double, 10> doubleStack2;
        doubleStack1 = doubleStack2;  // compiles   
    }

    void test_03() {

        Stack<int, 3> intStack;
        for (int n = 0; n < 5; n++) {
            try {
                intStack.push(10 * (n+1));
            }
            catch (const std::out_of_range & ex) {
                std::cout << "Exception: " << ex.what() << std::endl;
            }
            catch (...) {
                std::cout << "Unexpected Exception: " << std::endl;
            }
        }

        // print contents of stack 
        for (int i = 0; i < intStack.size(); i++) {
            int value = intStack.pop();
            std::cout << value << std::endl;
        }
    }

    void test_04() {

        constexpr int Max = 6;
        Stack<std::string, Max> stringStack;
        for (size_t n = 0; n < Max; n++) {
            stringStack.push(std::to_string(11111 * (n + 1)));
        }

        // print contents of stack 
        for (int i = 0; i < stringStack.size(); i++) {
            std::string value = stringStack.pop();
            std::cout << value << std::endl;
        }
    }

    void test_05() {

        // testing default size
        Stack<std::string> stringStack;

        int n = 0;
        while (!stringStack.isFull()) {
            stringStack.push(std::to_string(n * 11111));
            n++;
        }

        while (!stringStack.isEmpty()) {
            std::string value = stringStack.pop();
            std::cout << value << std::endl;
        }
    }

    void test_06() {

        Stack<char, 24> charStack;
        char ch = 'A';
        while (ch != 'K') {
            charStack.pushEx(ch);
            ++ch;
        }

        while (charStack.popEx(ch)) {
            std::cout << ch << std::endl;
        }
    }
}

void main_template_stack ()
{
    using namespace TemplateStack;
    test_01();
    test_02();
    test_03();  // throws exception (intentionally)
    test_04();
    test_05();
    test_06();
}

// ===========================================================================
// End-of-File
// ===========================================================================
