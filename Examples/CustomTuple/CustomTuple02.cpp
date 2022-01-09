// ===========================================================================
// CustomTuple02.cpp // Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Variadische Templates am Beispiel von std::tuple<>
// Alternative Realisierung - angelehnt an
// https://eli.thegreenplace.net/2014/variadic-templates-in-c/
// ===========================================================================

#include <iostream>
#include <string>

namespace AlternateCustomTuple {

    template <class... Ts>
    struct MyTuple {};

    template <class T, class... Ts>
    struct MyTuple<T, Ts...> : MyTuple<Ts...> {
        MyTuple(T t, Ts... ts) : MyTuple<Ts...>(ts...), tail(t) {}

        T tail;
    };

    template <size_t, class>
    struct TypeHolder;

    template <class T, class... Ts>
    struct TypeHolder<0, MyTuple<T, Ts...>> {
        using type = T;
    };

    template <size_t k, class T, class... Ts>
    struct TypeHolder<k, MyTuple<T, Ts...>> {
        using type = typename TypeHolder<k - 1, MyTuple<Ts...>>::type;
    };

    template <size_t k, class... Ts>
    typename std::enable_if<
        k == 0, typename TypeHolder<0, MyTuple<Ts...>>::type&>::type
        get(MyTuple<Ts...>& t) {
        return t.tail;
    }

    template <size_t k, class T, class... Ts>
    typename std::enable_if<
        k != 0, typename TypeHolder<k, MyTuple<T, Ts...>>::type&>::type
        get(MyTuple<T, Ts...>& t) {
        MyTuple<Ts...>& base = t;
        return get<k - 1>(base);
    }
}

void main_mytuple_alternate_01()
{
    using namespace AlternateCustomTuple;

    MyTuple<int, double, std::string> aTuple(123, 99.99, std::string("ABCDE"));

    int n = get<0>(aTuple);
    std::cout << "n = " << n << std::endl;

    double d = get<1>(aTuple);
    std::cout << "d = " << d << std::endl;

    std::string s = get<2>(aTuple);
    std::cout << "s = " << s << std::endl;
}

void main_mytuple_alternate_02()
{
    using namespace AlternateCustomTuple;

    MyTuple<int, double, std::string> aTuple(123, 99.99, std::string("ABCDE"));

    int n = get<0, int, double, std::string>(aTuple);
    std::cout << "n = " << n << std::endl;

    double d = get<1, int, double, std::string>(aTuple);
    std::cout << "d = " << d << std::endl;

    std::string s = get<2, int, double, std::string>(aTuple);
    std::cout << "s = " << s << std::endl;
}

void main_mytuple_alternate()
{
    main_mytuple_alternate_01();
    main_mytuple_alternate_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
