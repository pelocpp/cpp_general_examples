// ===========================================================================
// CustomTuple05.cpp // Benutzerdefinierte Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Tuple ohne variadische Templates
// ===========================================================================

#include <iostream>
#include <string>
#include <type_traits>

template <typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void>
struct MyTuple : MyTuple<T2, T3, T4>
{
    T1 m_x;

    using Base = MyTuple<T2, T3, T4>;

    Base* base()
    {
        return static_cast<Base*>(this);
    }

    const Base* base() const 
    {
        return static_cast<const Base*>(this);
    }

    MyTuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
        : Base{ t2, t3, t4 }, m_x{ t1 } {}
};

template <>
struct MyTuple<>
{
    MyTuple() {}
};

template <typename T1>
struct MyTuple<T1> : MyTuple<>
{
    T1 m_x;

    using Base = MyTuple<>;

    Base* base()
    {
        return static_cast<Base*>(this);
    }

    const Base* base() const
    {
        return static_cast<const Base*>(this);
    }

    MyTuple(const T1& t1) : Base{ }, m_x{ t1 } {}
};

template <typename T1, typename T2>
struct MyTuple<T1, T2> : MyTuple<T2>
{
    T1 m_x;

    using Base = MyTuple<T2>;

    Base* base()
    {
        return static_cast<Base*>(this);
    }

    const Base* base() const
    {
        return static_cast<const Base*>(this);
    }

    MyTuple(const T1& t1, const T2& t2) : Base{ t2 }, m_x{ t1 } {}
};

template <typename T1, typename T2, typename T3>
struct MyTuple<T1, T2, T3> : MyTuple<T2, T3>
{
    T1 m_x;

    using Base = MyTuple<T2, T3>;

    Base* base()
    {
        return static_cast<Base*>(this);
    }

    const Base* base() const
    {
        return static_cast<const Base*>(this);
    }

    MyTuple(const T1& t1, const T2& t2, const T3& t3) : Base{ t2, t3 }, m_x{ t1 } {}
};

void main_simple_tuple()
{
   MyTuple<int, int, int, int> tuple { 1, 2, 3, 4 };
}

// ===========================================================================
// End-of-File
// ===========================================================================
