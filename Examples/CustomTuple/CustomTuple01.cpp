// ===========================================================================
// CustomTuple01.cpp // Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Variadische Templates am Beispiel von std::tuple<>
// Realisierung angelehnt an
// "C++ Templates: The Complete Guide (2nd Edition)" von
// David Vandevoorde, Nicolai M. Josuttis und Douglas Gregor
// ===========================================================================

#include <iostream>
#include <string>

namespace CustomTuple {

    template<typename... Types>
    class Tuple;

    // recursive case:
    template<typename Head, typename... Tail>
    class Tuple<Head, Tail...>
    {
    private:
        Head head;
        Tuple<Tail...> tail;
    public:
        // constructors:
        Tuple() {
        }
        Tuple(Head const& head, Tuple<Tail...> const& tail)
            : head(head), tail(tail) {
        }

        Tuple(Head&& head, Tail&&... tail) :
            head(std::forward<Head>(head)),
            tail(std::forward<Tail>(tail)...) {
        }

        Head& getHead() { return head; }
        Head const& getHead() const { return head; }
        Tuple<Tail...>& getTail() { return tail; }
        Tuple<Tail...> const& getTail() const { return tail; }
    };

    // basis case:
    template<>
    class Tuple<> {
        // no storage required
    };

    template<unsigned N>
    struct TupleGet {
        template<typename Head, typename... Tail>
        static auto apply(Tuple<Head, Tail...> const& t) {
            return TupleGet<N - 1>::apply(t.getTail());
        }
    };

    // basis case:
    template<>
    struct TupleGet<0> {
        template<typename Head, typename... Tail>
        static Head const& apply(Tuple<Head, Tail...> const& t) {
            return t.getHead();
        }
    };

    template<unsigned N, typename... Types>
    auto get(Tuple<Types...> const& t) {
        return TupleGet<N>::apply(t);
    }
}

void main_mytuple()
{
    using namespace CustomTuple;

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

