// ===========================================================================
// CustomTuple04.cpp // Benutzerdefinierte Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Zusammenfassung der Ideen aus den ersten drei Dateien
// ===========================================================================

#include <iostream>
#include <string>
#include <type_traits>

#define UseVariadicMemberVariable
// #define UseVariadicInheritance

namespace CustomTuple_RecursiveMembership
{
    // ------------------------------------------------
    // elements of tuple are added as instance variable

    // primary template
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
}

namespace CustomTuple_RecursiveInheritance
{
    // ------------------------------------------------
    // elements of tuple are added as base class variable

    // primary template
    template <typename... T>
    struct Tuple {};

    // recursive specialisation
    template <typename T, typename... TRest>
    struct Tuple<T, TRest...> : Tuple<TRest...> 
    {
        Tuple(const T& first, const TRest&... rest)
            : Tuple<TRest...>{ rest... }, m_first{ first } {}

        T m_first;
    };
}

namespace CustomTuple_RecursiveMembership
{
    // ------------------------------------------------
    // get

    // primary template
    template<size_t N, typename T>
    struct GetHelper;

    template<typename T, typename... TRest>
    struct GetHelper<0, Tuple<T, TRest...>> 
    {
        static T get(const Tuple<T, TRest...>& tuple) {
            return tuple.m_first;
        }
    };

    // TESTEN, geht das --- Reihenfolge ....
    template<size_t N, typename T, typename... TRest>
    struct GetHelper<N, Tuple<T, TRest...>> 
    {
        static auto get(const Tuple<T, TRest...>& tuple) {
            return GetHelper<N - 1, Tuple<TRest...>>::get(tuple.m_rest);
        }
    };

//    // Note: Dieses Template haben wir doppelt
    template<
        size_t N, 
        typename... TArgs,
        template <typename... > typename T
    >
    auto get(const T<TArgs...>& tuple) {
        return GetHelper<N, T<TArgs...>>::get(tuple);
    }
}

namespace CustomTuple_RecursiveInheritance
{
    // ------------------------------------------------
    // get

    // primary template
    template<size_t N, typename T>
    struct GetHelper;

    template<typename T, typename... TRest>
    struct GetHelper<0, Tuple<T, TRest...>> 
    {
        static T get(const Tuple<T, TRest...>& tuple) {
            return tuple.m_first;
        }
    };

    // TESTEN, geht das --- Reihenfolge ....
    template<size_t N, typename T, typename... TRest>
    struct GetHelper<N, Tuple<T, TRest...>> 
    {
        static auto get(const Tuple<T, TRest...>& tuple) {
            return GetHelper<N - 1, Tuple<TRest...>>::get(tuple);
        }
    };

    // Note: Dieses Template haben wir doppelt
    template<
        size_t N,
        typename... TArgs,
        template <typename... > typename T
    >
    auto get(const T<TArgs...>& tuple) {
        return GetHelper<N, T<TArgs...>>::get(tuple);
    }
}

// ===========================================================================

namespace CustomTuple_Print
{
#if defined (UseVariadicMemberVariable)
    using namespace CustomTuple_RecursiveMembership;
#elif defined (UseVariadicInheritance)
    using namespace CustomTuple_RecursiveInheritance;
#endif

    // ------------------------------------------------
    // print

    template<std::size_t N, typename T>
    struct TuplePrintHelper 
    {
        static void print(T t) {
            TuplePrintHelper<N - 1, T>::print(t);
            std::cout << ", " << get<N - 1>(t);
        }
    };

    template<typename T>
    struct TuplePrintHelper<1, T> {
        static void print(T t) {
            std::cout << get<0>(t);
        }
    };

    template<typename... TArgs>
    void print(const Tuple<TArgs...>& t) {
        std::cout << "[" << std::boolalpha;
        TuplePrintHelper<sizeof...(TArgs), Tuple<TArgs ...>>::print(t);
        std::cout << "]" << std::endl;
    }

    template <
        typename... TArgs,
        template <typename...> typename T
    >
    void printEx(const T<TArgs...>& t)
    {
        std::cout << "[" << std::boolalpha;
        TuplePrintHelper<sizeof...(TArgs), T<TArgs...>>::print(t);
        std::cout << "]" << std::endl;
    }
}

// ===========================================================================

namespace CustomTuple_Folding
{
#if defined (UseVariadicMemberVariable)
    using namespace CustomTuple_RecursiveMembership;
#elif defined (UseVariadicInheritance)
    using namespace CustomTuple_RecursiveInheritance;
#endif

    // ------------------------------------------------
    // print

    // Template recursion
    template <size_t i, typename... Args>
    struct printer 
    {
        static void print(const Tuple<Args...>& t) {
           // std::cout << get<i>(t) << std::endl;
#pragma message("111")
            printer<i + 1, Args...>::print(t);
        }
    };

    // Terminating template specialisation
    template <typename... Args>
    struct printer< sizeof...(Args) , Args ...> 
    {
#pragma message("222a")
        static void print(const Tuple<Args...>&) {
#pragma message("222b")
        }
    };

    template <typename... Args>
    void print(const Tuple<Args...>& t) {
#pragma message("333")
        printer<0, Args...>::print(t);
    }

}


namespace CustomTuple_PrintEx_Stroustrup
{
#if defined (UseVariadicMemberVariable)
    using namespace CustomTuple_RecursiveMembership;
#elif defined (UseVariadicInheritance)
    using namespace CustomTuple_RecursiveInheritance;
#endif

    // =================================
    // print für Tuple

    template<std::size_t N>
    struct TuplePrintHelper
    {
        template<typename T>
        static void print(T t) {
            std::cout << get<0>(t);
        }

        template<typename... T>
        static void print(T... t) {
            TuplePrintHelper<N - 1>::print(t ...);
            std::cout << ", " << get<N - 1>(t ...);
        }
    };

    template<typename... TArgs>
    static void print(const Tuple<TArgs...>& tuple) {
        std::cout << "[" << std::boolalpha;
        TuplePrintHelper<0>::print(tuple);
        std::cout << "]" << std::endl;
    }

    template <
        typename... TArgs,
        template <typename... > typename T
    >
    void printEx(const T<TArgs...>& t)
    {
        std::cout << "[" << std::boolalpha;
        TuplePrintHelper<sizeof...(TArgs)>::print(t);
        std::cout << "]" << std::endl;
    }
}

namespace CustomTuple_TypeHolder
{
#if defined (UseVariadicMemberVariable)
    using namespace CustomTuple_RecursiveMembership;
#elif defined (UseVariadicInheritance)
    using namespace CustomTuple_RecursiveInheritance;
#endif

    template <size_t, typename>
    struct TypeHolder;

    template <typename T, typename... TRest>
    struct TypeHolder<0, Tuple<T, TRest...>> {
        using type = T;
    };

    template <size_t N, typename T, typename... TRest>
    struct TypeHolder<N, Tuple<T, TRest...>> {
        using type = typename TypeHolder<N - 1, Tuple<TRest...>>::type;
    };
}

namespace CustomTuple_StreamingOutput
{
    using namespace CustomTuple_Print;

    std::ostream& operator << (std::ostream& os, const Tuple<>&)
    {
        os << "{}";
        return os;
    }

    template <typename T, typename ... TRest>
    std::ostream& operator << (std::ostream& os, const Tuple<T, TRest...>& t)
    {
        os << "{ " << get<0>(t);
        TuplePrintHelper<1 + sizeof...(TRest), Tuple<T, TRest...>>::print(t);
        os << " }";
        return os;
    }
}

// ===========================================================================

void custom_tuple_00()
{
#if defined (UseVariadicMemberVariable)
    using namespace CustomTuple_RecursiveMembership;
#elif defined (UseVariadicInheritance)
    using namespace CustomTuple_RecursiveInheritance;
#endif

    Tuple<bool> t1(false);
    std::cout << std::boolalpha << get<0>(t1) << std::endl;

    Tuple<int, char, bool, std::string> t2(1, 'a', true, "ABC");

    std::cout << get<0>(t2) << ' ';
    std::cout << get<1>(t2) << ' ';
    std::cout << get<2>(t2) << ' ';
    std::cout << get<3>(t2) << std::endl;
}

void custom_tuple_01()
{
    using namespace CustomTuple_Print;

    Tuple<bool> t1(false);
    print(t1);
    printEx(t1);

    Tuple<int, char, bool, std::string> t2(1, 'a', true, "ABC");
    print(t2);
    printEx(t2);
}

void custom_tuple_02()
{
    using namespace CustomTuple_TypeHolder;

    Tuple<int, char, bool, std::string> t2(1, 'a', true, "ABC");
    TypeHolder<1, Tuple<int, char, bool, std::string>>::type ch = get<1>(t2);
    std::cout << ch << std::endl;

    TypeHolder<1, Tuple<int, char, bool, std::string>>::type ch2 = 'A';
    std::cout << ch2 << std::endl;
}


// FEHLER: Hier wird immer nur das erste Element ausgegeben ...
void custom_tuple_03()
{
    using namespace CustomTuple_PrintEx_Stroustrup;

    Tuple<int, char, bool, std::string> t(123, 'A', true, "ABC");
    TuplePrintHelper<0>::print(t);
    TuplePrintHelper<1>::print(t);
    TuplePrintHelper<2>::print(t);
    TuplePrintHelper<3>::print(t);
}



// Bis hier her ist es getestet ........

// Unter Gcc testen 

// Viushal nachschauen: Was ist dort noch vorhanden ... Folding ....



void custom_tuple_04()
{
    using namespace CustomTuple_StreamingOutput;

    Tuple<int, char, bool, std::string> tuple{ 1, 'a', true, "ABC" };
    std::cout << tuple << std::endl;
}

void custom_tuple_05()
{
    //using namespace CustomTuple_Folding;

    //Tuple<double> t1(123.456);
    //print(t1);

    //Tuple<int, char, bool, std::string> t2(123, 'a', true, "ABC");
    //print(t2);
}



void main_custom_tuple()
{
    //custom_tuple_00();
    //custom_tuple_01();
    //custom_tuple_02();
    custom_tuple_03();
    //custom_tuple_04();
    //custom_tuple_05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
