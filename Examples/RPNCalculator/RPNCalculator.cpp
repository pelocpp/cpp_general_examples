// ===========================================================================
// RPNCalculator.cpp // Reverse Polish Notation Calculator
// ===========================================================================

#include <iostream>
#include <stack>
#include <iterator> 
#include <vector>
#include <sstream>
#include <iterator>
#include <stdexcept>

// #define MyStackTemplate 1

#if defined (MyStackTemplate)
#include "..\\TemplateStack\\TemplateStack.hpp"
#endif

namespace ReversePolishNotationCalculator {

#if defined (MyStackTemplate)
    using namespace TemplateStack;
#endif

    template <typename IT, typename T>
    class RPNCalculator {
    private:

#if ! defined (MyStackTemplate)
        std::stack<T> m_valueStack;  // use STL standard stack
#else
        Stack <T> m_valueStack; // use self written stack template
#endif

    public:
        T evaluate(IT it, IT end) {

            while (it != end) {

                std::string nextToken = *it;
                std::stringstream ss(nextToken);
                T value = 0.0;

                // read next token
                ss >> value;
                if (!ss.fail()) {
                    m_valueStack.push(value);
                }
                else {

                    const T rightOperand = m_valueStack.top();
                    m_valueStack.pop();

                    const T leftOperand = m_valueStack.top();
                    m_valueStack.pop();

                    try {
                        // input should be an operator right now
                        // because stringstream failed before
                        std::string op = *it;

                        T result = 0.0;
                        if (op == "+") {
                            result = leftOperand + rightOperand;
                        }
                        else if (op == "-") {
                            result = leftOperand - rightOperand;
                        }
                        else if (op == "*") {
                            result = leftOperand * rightOperand;
                        }
                        else if (op == "/") {
                            result = leftOperand / rightOperand;
                        }

                        m_valueStack.push(result);
                    }
                    catch (const std::out_of_range&) {
                        throw std::invalid_argument(*it);
                    }
                }

                ++it;
            }

            return m_valueStack.top();
        }
    };

    void test_01() {
        using namespace ReversePolishNotationCalculator;

        RPNCalculator <std::istream_iterator<std::string>, double> myCalc;

        std::string input{ "3.5 22.99 1 + * 2 /" };   // 4.5
        std::stringstream ss(input);

        std::istream_iterator<std::string> begin{ ss };
        std::istream_iterator<std::string> end{};

        double result = myCalc.evaluate(begin, end);
        std::cout << "Result: " << result << std::endl;
    }

    void test_02() {
        using namespace ReversePolishNotationCalculator;

        std::vector<std::string> input{ "30", "20", "1", "+", "*", "2", "/" };

        RPNCalculator <std::vector<std::string>::iterator, double> myCalc;

        std::vector<std::string>::iterator begin = input.begin();
        std::vector<std::string>::iterator end = input.end();

        double result = myCalc.evaluate(begin, end);
        std::cout << "Result: " << result << std::endl;
    }

    void test_03() {
        using namespace ReversePolishNotationCalculator;

        RPNCalculator <std::istream_iterator<std::string>, double> myCalc;

        // terminate input from console (cin) with ^Z 
        std::istream_iterator<std::string> begin{ std::cin };
        std::istream_iterator<std::string> end{};

        double result = myCalc.evaluate(begin, end);
        std::cout << "Result: " << result << std::endl;
    }
}

void main_rpn_calculator()
{
    using namespace ReversePolishNotationCalculator;

    test_01();
    test_02();
    test_03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
