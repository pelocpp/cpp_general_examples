// ===========================================================================
// CustomTuple.cpp // Demo Implementation of standard class std::tuple<>
// Note: Solution uses C++ 17 Folding
// ===========================================================================

#include <iostream>
#include <string>
#include <type_traits>

namespace CustomTuple_ReproducingCompilerEndlessLoop {

    // ------------------------------------------------
    // tuple

    // simple custom tuple definition
    template <typename... T>
    struct Tuple {};

    // recursive specialisation
    template<typename T, typename... TRest>
    struct Tuple<T, TRest...>
    {
        Tuple(const T& first, const TRest&... rest)
            : m_first{ first }, m_rest{ rest... } {}

        T m_first;
        Tuple<TRest...> m_rest;
    };

    // ------------------------------------------------
    // print

    template <std::size_t i, typename... Args>
    struct printer
    {
        static void print(const Tuple<Args...>& t) {
            // TBD: get needs to be implemented
            // std::cout << get<i>(t) << std::endl;
#pragma message("called endless !!!")
            printer<i + 1, Args...>::print(t);
        }
    };

    // terminating template specialisation
    template <typename... Args>
    struct printer<sizeof...(Args), Args ...>
    {
#pragma message("called once")
        static void print(const Tuple<Args...>&) {
        }
    };

    template <typename... Args>
    void print(const Tuple<Args...>& t) {
#pragma message("also called once")
        printer<0, Args...>::print(t);
    }
}

int main()
{
    using namespace CustomTuple_ReproducingCompilerEndlessLoop;

    Tuple<double> t1(123.456);
    print(t1);

    Tuple<int, char, bool, std::string> t2(123, 'a', true, "ABC");
    print(t2);

    return 1;
}
