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
    struct Tuple {};

    template <class T, class... Ts>
    struct Tuple<T, Ts...> : Tuple<Ts...> {
        Tuple(T t, Ts... ts) : Tuple<Ts...>(ts...), tail(t) {}

        T tail;
    };

    template <size_t, class>
    struct TypeHolder;

    template <class T, class... Ts>
    struct TypeHolder<0, Tuple<T, Ts...>> {
        using type = T;
    };

    template <size_t k, class T, class... Ts>
    struct TypeHolder<k, Tuple<T, Ts...>> {
        using type = typename TypeHolder<k - 1, Tuple<Ts...>>::type;
    };

    template <size_t k, class... Ts>
    typename std::enable_if<
        k == 0, typename TypeHolder<0, Tuple<Ts...>>::type&>::type
        get(Tuple<Ts...>& t) {
        return t.tail;
    }

    template <size_t k, class T, class... Ts>
    typename std::enable_if<
        k != 0, typename TypeHolder<k, Tuple<T, Ts...>>::type&>::type
        get(Tuple<T, Ts...>& t) {
        Tuple<Ts...>& base = t;
        return get<k - 1>(base);
    }
}

void main_mytuple_alternate()
{
    using namespace AlternateCustomTuple;

    Tuple<int, double, std::string> aTuple (123, 99.99, std::string("ABCDE"));

    int n = get<0>(aTuple);
    std::cout << "n = " << n << std::endl;

    double d = get<1>(aTuple);
    std::cout << "d = " << d << std::endl;

    std::string s = get<2>(aTuple);
    std::cout << "s = " << s << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
