//// ===========================================================================
//// CustomTuple03.cpp // Implementierung von std::tuple<>
//// ===========================================================================
//
//// ===========================================================================
//// Variadische Templates am Beispiel von std::tuple<>
//// Alternative Realisierung - angelehnt an den Blogger Vishal Chovatiya:
//// http://www.vishalchovatiya.com/variadic-template-cpp-implementing-unsophisticated-tuple/
//// ===========================================================================
//
//#include <iostream>
//#include <string>
//
//namespace UnsophisticatedTuple {
//
//    // =================================
//    // Die Unterelemente werden als Member
//    // rekursiv der Klasse hinzugefügt
//
//    // primary template
//    template <typename... T>
//    struct Tuple {};
//
//    // recursive specialisation
//    template<
//        typename T, 
//        typename... TRest
//    >
//    struct Tuple<T, TRest...> 
//    {
//        T m_first;
//        Tuple<TRest...> m_rest;
//
//        Tuple(const T& f, const TRest& ... r)
//            : m_first{ f }, m_rest{ r... } {}
//    };
//
//    // =================================
//    // Die Unterelemente werden via Vererbung
//    // rekursiv in Basisklassen hinzugefügt
//
//    // primary template
//    template <class... T>
//    struct TupleEx {};
//
//    // recursive specialisation
//    template <class T, class... TRest>
//    struct TupleEx<T, TRest...> : TupleEx<TRest...> {
//        TupleEx(T t, TRest... ts) : TupleEx<TRest...>{ ts... }, m_tail{ t } {}
//
//        // TODO: Ist das nicht besser m_first ???
//        T m_tail;
//    };
//
//    // =================================
//    // get für TupleEx
// 
//    // primary template
//    template<size_t idx, typename T>
//    struct GetHelperEx;
//
//    template<typename T, typename... TRest>
//    struct GetHelperEx<0, TupleEx<T, TRest...>> {
//        static T getEx(TupleEx<T, TRest...>& data) {
//            return data.m_tail;
//        }
//    };
//
//    template<size_t idx, typename T, typename... TRest>
//    struct GetHelperEx<idx, TupleEx<T, TRest...>> {
//        static auto getEx(TupleEx<T, TRest...>& data) {
//            return GetHelperEx<idx - 1, TupleEx<TRest...>>::getEx(data);
//        }
//    };
//
//    // Klären: In diesem Template ist TupleEx doch nur ein Parameter Name .. sollte man anders benennen
//    template<
//        size_t idx,
//        typename... Args,
//        template <typename ... Args> class Tup
//    >
//    auto getEx(Tup<Args...>& t) {
//        return GetHelperEx<idx, Tup<Args...>>::getEx(t);
//    }
//
//    // =================================
//    // get für Tuple
//
//    //// primary template
//    template<size_t idx, typename T>
//    struct GetHelper;
//
//    template<typename T, typename... TRest>
//    struct GetHelper<0, Tuple<T, TRest...>> {
//        static T get(Tuple<T, TRest...>& data) {
//            return data.m_first;
//        }
//    };
//
//    template<size_t idx,typename T,typename... TRest>
//    struct GetHelper<idx, Tuple<T, TRest...>> {
//        static auto get(Tuple<T, TRest...>& data) {
//            return GetHelper<idx - 1, Tuple<TRest...>>::get(data.m_rest);
//        }
//    };
//
//    // SIEHE HIER
//    // https://stackoverflow.com/questions/9662632/variadic-variadic-template-templates
//
//    // ODER HIER:
//    // https://arne-mertz.de/2016/11/more-variadic-templates/
//
//    // ODER HIER:
//    // https://stackoverflow.com/questions/24812913/template-template-parameters-with-variadic-templates
//
//     // Klären: In diesem Template ist Tuple doch nur ein Parameter Name .. sollte man anders benennen
//    template<
//        size_t idx,
//        typename... Args,
//        template <typename ... Args> class Tup
//    >
//    auto get(Tup<Args...>& t) {
//        return GetHelper<idx, Tup<Args...>>::get(t);
//    }
//}
//
//void main_mytuple_unsophisticatedTuple_00()
//{
//    using namespace UnsophisticatedTuple;
//
//    Tuple<bool>                      t1(false);           // Case 1
//    Tuple<int, char, std::string>    t2(1, 'a', "ABC");   // Case 2
//    std::cout << get<0>(t2) << std::endl;
//    std::cout << get<1>(t2) << std::endl;
//    std::cout << get<2>(t2) << std::endl;
//
//    Tuple<int, char, std::string> t(500, 'a', "ABC");
//    std::cout << get<1>(t) << std::endl;
//}
//
//void main_mytuple_unsophisticatedTuple_00_Ex()
//{
//    using namespace UnsophisticatedTuple;
//
//    TupleEx<bool>                      t1(false);           // Case 1
//    TupleEx<int, char, std::string>    t2(1, 'a', "ABC");   // Case 2
//    std::cout << getEx<0>(t2) << std::endl;
//    std::cout << getEx<1>(t2) << std::endl;
//    std::cout << getEx<2>(t2) << std::endl;
//
//    TupleEx<int, char, std::string> t(500, 'a', "ABC");
//    std::cout << getEx<1>(t) << std::endl;
//}
//
//void main_mytuple_unsophisticatedTuple()
//{
//    main_mytuple_unsophisticatedTuple_00();
//    main_mytuple_unsophisticatedTuple_00_Ex();
//}
//
//// ===========================================================================
//// End-of-File
//// ===========================================================================
