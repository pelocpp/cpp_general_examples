// ===========================================================================
// CustomTuple04.cpp // Benutzerdefinierte Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Zusammenfassung der Ideen aus den ersten drei Dateien
// ===========================================================================

#include <iostream>
#include <string>

namespace CustomTuple_RecursiveMembership
{
    // =================================
    // Die Unterelemente werden als Member
    // rekursiv der Klasse hinzugefügt

    // primary template
    template <typename... T>
    struct Tuple {};

    // recursive specialisation
    template<
        typename T,
        typename... TRest
    >
    struct Tuple<T, TRest...>
    {
        T m_first;
        Tuple<TRest...> m_rest;

        Tuple(const T& f, const TRest& ... r)
            : m_first{ f }, m_rest{ r... } {}
    };
}

namespace CustomTuple_RecursiveInheritance
{
    // =================================
    // Die Unterelemente werden via Vererbung
    // rekursiv in Basisklassen hinzugefügt

    // primary template
    template <class... T>
    struct Tuple {};

    // recursive specialisation
    template <class T, class... TRest>
    struct Tuple<T, TRest...> : Tuple<TRest...> {
        Tuple(T t, TRest... ts) : Tuple<TRest...>{ ts... }, m_tail{ t } {}

        // TODO: Ist das nicht besser m_first ???
        T m_tail;
    };
}

namespace CustomTuple_Get_BasedOnRecursiveMembership
{
    using namespace CustomTuple_RecursiveMembership;

    // =================================
    // get für Tuple

    // primary template
    template<size_t idx, typename T>
    struct GetHelper;

    template<typename T, typename... TRest>
    struct GetHelper<0, Tuple<T, TRest...>> {
        static T get(Tuple<T, TRest...>& data) {
            return data.m_first;
        }
    };

    template<size_t idx, typename T, typename... TRest>
    struct GetHelper<idx, Tuple<T, TRest...>> {
        static auto get(Tuple<T, TRest...>& data) {
            return GetHelper<idx - 1, Tuple<TRest...>>::get(data.m_rest);
        }
    };

    // Klären: In diesem Template ist Tuple doch nur ein Parameter Name .. sollte man anders benennen
    // Hmmm: Das haben wir doppelt
    template<
        size_t idx,
        typename... Args,
        template <typename ... Args> class Tup
    >
    auto get(Tup<Args...>& t) {
        return GetHelper<idx, Tup<Args...>>::get(t);
    }
}

namespace CustomTuple_Get_BasedOnRecursiveInheritance
{
    using namespace CustomTuple_RecursiveInheritance;

    // =================================
    // get für TupleEx

    // primary template
    template<size_t idx, typename T>
    struct GetHelper;

    template<typename T, typename... TRest>
    struct GetHelper<0, Tuple<T, TRest...>> {
        static T get(Tuple<T, TRest...>& data) {
            return data.m_tail;
        }
    };

    template<size_t idx, typename T, typename... TRest>
    struct GetHelper<idx, Tuple<T, TRest...>> {
        static auto get(Tuple<T, TRest...>& data) {
            return GetHelper<idx - 1, Tuple<TRest...>>::get(data);
        }
    };

    // Klären: In diesem Template ist TupleEx doch nur ein Parameter Name .. sollte man anders benennen
        // Hmmm: Das haben wir doppelt
    template<
        size_t idx,
        typename... Args,
        template <typename ... Args> class T
    >
    auto get(T<Args...>& t) {
        return GetHelper<idx, T<Args...>>::get(t);
    }
}

namespace CustomTuple_PrintAll
{
    //using namespace CustomTuple_RecursiveMembership;
    //using namespace CustomTuple_Get_BasedOnRecursiveMembership;

    using namespace CustomTuple_RecursiveInheritance;
    using namespace CustomTuple_Get_BasedOnRecursiveInheritance;

    // =================================
    // print für Tuple

    template<std::size_t N, typename T>
    struct ShowTupleImpl {
        static void print(T t) {
            ShowTupleImpl<N - 1, T>::print(t);
            std::cout << ", " << get<N - 1>(t);
        }
    };

    template<typename T>
    struct ShowTupleImpl<1, T> {
        static void print(T t) {
            std::cout << get<0>(t);
        }
    };

    template<typename ... TArgs>
    void printTuple(Tuple<TArgs ...> t) {
        std::cout << "[";
        ShowTupleImpl<sizeof...(TArgs), Tuple<TArgs ...>>::print(t);
        std::cout << "]" << std::endl;
    }


    // Hier ist das Tuple mit enthalten .....
    template <
        typename ... TArgs,
        template <typename ...TArgs> typename Tup
    >
    void printTupleEx(Tup<TArgs...>& container)
    {
        std::cout << "[";
        ShowTupleImpl<sizeof...(TArgs), Tup<TArgs...>>::print(container);
        std::cout << "]" << std::endl;
    }

}







void custom_tuple_00()
{
    //using namespace CustomTuple_RecursiveMembership;
    //using namespace CustomTuple_Get_BasedOnRecursiveMembership;
    //using namespace CustomTuple_PrintAll;

    using namespace CustomTuple_RecursiveInheritance;
    using namespace CustomTuple_Get_BasedOnRecursiveInheritance;
    using namespace CustomTuple_PrintAll;

    Tuple<bool> t1(false);
    std::cout << std::boolalpha << get<0>(t1) << std::endl;
    printTuple(t1);
    printTupleEx(t1);

    Tuple<int, char, bool, std::string> t2(1, 'a', true, "ABC");

    std::cout << get<0>(t2) << std::endl;
    std::cout << get<1>(t2) << std::endl;
    std::cout << get<2>(t2) << std::endl;
    std::cout << get<3>(t2) << std::endl;
    printTuple(t2);
    printTupleEx(t1);
}



void main_custom_tuple()
{
    custom_tuple_00();
}

// ===========================================================================
// End-of-File
// ===========================================================================
