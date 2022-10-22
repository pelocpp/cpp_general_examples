// ===========================================================================
// CustomTuple01.cpp // Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Variadische Templates am Beispiel von std::tuple<>
// Realisierung angelehnt an
// "C++ Templates: The Complete Guide (2nd Edition)" von
// David Vandevoorde, Nicolai M. Josuttis und Douglas Gregor
// Seite 577 ff.
// ===========================================================================

#include <iostream>
#include <string>

namespace CustomTupleVandevoorde {

    template<typename... Types>
    class MyTuple;

    // recursive case
    template<typename Head, typename... Tail>
    class MyTuple<Head, Tail...>
    {
    private:
        Head m_head;
        MyTuple<Tail...> m_tail;

    public:
        // c'tors
        MyTuple() {}

        MyTuple(const Head& head, const MyTuple<Tail...>& tail)
            : m_head(head), m_tail(tail) {
        }

        MyTuple(Head&& head, Tail&&... tail) :
            m_head(std::forward<Head>(head)),
            m_tail(std::forward<Tail>(tail)...) {
        }

        // getter / setter
        Head& getHead() { 
            return m_head;
        }

        const Head& getHead() const {
            return m_head; 
        }

        MyTuple<Tail...>& getTail() {
            return m_tail;
        }

        const MyTuple<Tail...>& getTail() const {
            return m_tail; 
        }
    };

    // basis case
    template<>
    class MyTuple<> {};

    // --------------------------------------------------------

    template<unsigned N>
    struct MyTupleGet {
        template<typename Head, typename... Tail>
        static auto apply(const MyTuple<Head, Tail...>& t) {
            return MyTupleGet<N - 1>::apply(t.getTail());
        }
    };

    // basis case:
    template<>
    struct MyTupleGet<0> {
        template<typename Head, typename... Tail>
        static const Head& apply(const MyTuple<Head, Tail...>& t) {
            return t.getHead();
        }
    };

    template<unsigned N, typename... Types>
    auto get(const MyTuple<Types...>& t) {
        return MyTupleGet<N>::apply(t);
    }
}

void main_mytuple_01()
{
    using namespace CustomTupleVandevoorde;

    MyTuple<int, double, std::string> aTuple (123, 99.99, std::string("ABCDE"));

    int n = get<0>(aTuple);
    std::cout << "n = " << n << std::endl;

    double d = get<1>(aTuple);
    std::cout << "d = " << d << std::endl;

    std::string s = get<2>(aTuple);
    std::cout << "s = " << s << std::endl;
}

void main_mytuple_02()
{
    using namespace CustomTupleVandevoorde;

    MyTuple<int, double, std::string> aTuple(123, 99.99, std::string("ABCDE"));

    int n = get<0, int, double, std::string>(aTuple);
    std::cout << "n = " << n << std::endl;

    double d = get<1, int, double, std::string>(aTuple);
    std::cout << "d = " << d << std::endl;

    std::string s = get<2, int, double, std::string>(aTuple);
    std::cout << "s = " << s << std::endl;
}

void main_mytuple()
{
    main_mytuple_01();
    main_mytuple_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
