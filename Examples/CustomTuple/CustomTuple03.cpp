// ===========================================================================
// CustomTuple03.cpp // Implementierung von std::tuple<>
// ===========================================================================

// ===========================================================================
// Variadische Templates am Beispiel von std::tuple<>
// Alternative Realisierung - angelehnt an den Blogger Vishal Chovatiya:
// http://www.vishalchovatiya.com/variadic-template-cpp-implementing-unsophisticated-tuple/
// ===========================================================================

#include <iostream>
#include <string>

namespace UnsophisticatedTuple {

    // base-case
    template <typename... T>
    struct Tuple{};

    template<typename T, typename... Rest>
    struct Tuple<T, Rest...> {      // Class parameter pack
        T first;
        Tuple<Rest...> rest;        // Parameter pack expansion
        Tuple(const T& f, const Rest& ... r)
            : first(f)
            , rest(r...) {
        }
    };

    template<
        size_t idx,
        typename T
    >
    struct GetHelper;

    template<
        typename T,
        typename... Rest
    >
    struct GetHelper<0, Tuple<T, Rest...>> {
        static T get(Tuple<T, Rest...>& data) {
            return data.first;
        }
    };

    template<
        size_t idx,
        typename T,
        typename... Rest
    >
    struct GetHelper<idx, Tuple<T, Rest...>> {
        static auto get(Tuple<T, Rest...>& data) {
            return GetHelper<idx - 1, Tuple<Rest...>>::get(data.rest);
        }
    };

    // SIEHE HIER
    // https://stackoverflow.com/questions/9662632/variadic-variadic-template-templates

    // ODER HIER:
    // https://arne-mertz.de/2016/11/more-variadic-templates/

    // ODER HIER:
    // https://stackoverflow.com/questions/24812913/template-template-parameters-with-variadic-templates


    template<
        size_t idx,
        template <typename... > class Tuple,
        typename... Args
    >
    auto get(Tuple<Args...>& t) {
        return GetHelper<idx, Tuple<Args...>>::get(t);
    }

    // ============================


    //template<typename T>
    //struct GetHelperEx {};

    ////template<
    ////    typename T,
    ////    typename... Rest
    ////>
    ////struct GetHelperEx<Tuple<T, Rest...>> {
    ////    static T get(int index, Tuple<T, Rest...>& data) {
    ////        return data.first;
    ////    }
    ////};

    //template<
    //    typename T,
    //    typename... Rest
    //>
    //struct GetHelperEx<Tuple<T, Rest...>> {
    //    static auto getEx(int index, Tuple<T, Rest...>& data) {

    //        if (index == 0) {
    //            return data.first;
    //        }
    //        else {
    //            return GetHelperEx<Tuple<Rest...>>::getEx(index - 1, data.rest);
    //        }
    //    }
    //};

    //template<
    //    template <typename...> class Tuple,
    //    typename... Args
    //>
    //auto getEx(int index, Tuple<Args...>& t) {
    //    return GetHelperEx<Tuple<Args...>>::getEx(index, t);
    //}

}

void main_mytuple_unsophisticatedTuple_00()
{
    using namespace UnsophisticatedTuple;

    Tuple<bool>                 t1(false);           // Case 1
    Tuple<int, char, std::string>    t2(1, 'a', "ABC");   // Case 2

    Tuple<int, char, std::string> t(500, 'a', "ABC");
    std::cout << get<1>(t) << std::endl;

  //  std::cout << getEx(2, t) << std::endl;
}


void main_mytuple_unsophisticatedTuple()
{
    main_mytuple_unsophisticatedTuple_00();
}

// ===========================================================================
// End-of-File
// ===========================================================================
