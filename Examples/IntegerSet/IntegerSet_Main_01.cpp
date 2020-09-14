// ===============================================================================
// IntegerSet: Variant 1 - Classic Approach (using raw pointer with new / delete)
// ===============================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>

#include "IntegerSet_01_Classic.h"

namespace IntegerSetClassic {

    void test_ctors_dtor()
    {
        std::cout << "Testing c'tors / d'tor: " << std::endl;

        IntegerSet is1;
        std::cout << "is1: " << is1 << std::endl;

        int elems1[7] = { -2, -1, 0, 1, 2, -1, -2 };
        IntegerSet is2(elems1, 7);
        std::cout << "is2: " << is2 << std::endl;

        int elems2[11] = { -1, 1, 2, 3, 1, 2, 3, 1, 2, 3, -1 };
        IntegerSet is3(elems2, 11);
        std::cout << "is3: " << is3 << std::endl;

        IntegerSet is4(is3);
        std::cout << "is4: " << is4 << std::endl;

        std::cout << "is1.IsEmpty: " << is1.isEmpty() << std::endl;
        std::cout << "is2.IsEmpty: " << is2.isEmpty() << std::endl;
        std::cout << "is3.IsEmpty: " << is3.isEmpty() << std::endl;
        std::cout << "is4.IsEmpty: " << is4.isEmpty() << std::endl;
    }

    void test_methods()
    {
        std::cout << "Testing methods: " << std::endl;

        IntegerSet is;
        std::cout << "is: " << is << std::endl;

        // testing 'Insert'
        is.insert(1);
        is.insert(2);
        is.insert(3);
        is.insert(4);
        is.insert(5);
        is.insert(6);
        std::cout << "is: " << is << std::endl;

        // testing 'Remove'
        is.remove(3);
        is.remove(4);
        is.remove(5);
        is.remove(6);
        std::cout << "is: " << is << std::endl;

        is.insert(10);
        is.insert(11);
        is.insert(12);

        is.insert(13);
        is.insert(14);
        is.insert(15);
        is.insert(16);
        is.insert(17);
        is.insert(18);
        is.insert(19);
        is.insert(20);
        is.insert(21);
        is.insert(22);
        is.insert(23);
        std::cout << "is: " << is << std::endl;

        is.insert(24);
        std::cout << "is: " << is << std::endl;

        is.remove(11);
        std::cout << "is: " << is << std::endl;

        // testing 'Contains'
        std::cout << "Contains(1): " << is.contains(1) << std::endl;
        std::cout << "Contains(5): " << is.contains(5) << std::endl;
        std::cout << "Contains(10): " << is.contains(10) << std::endl;
    }

    void test_remove()
    {
        IntegerSet is;
        for (int i = 0; i < 20; i++)
            is.insert(i);
        std::cout << "is: " << is << std::endl;

        is.remove(5);
        is.remove(1);
        is.remove(8);
        std::cout << "is: " << is << std::endl;

        is.remove(11);
        std::cout << "is: " << is << std::endl;

        is.remove(16);
        std::cout << "is: " << is << std::endl;

        is.remove(19);
        std::cout << "is: " << is << std::endl;
    }

    void test_insert()
    {
        IntegerSet is;
        for (int i = 0; i < 16; i++)
            is.insert(i);

        std::cout << "is: " << is << std::endl;

        is.insert(16);
        std::cout << "is: " << is << std::endl;
    }

    void test_operators()
    {
        // testing union set
        IntegerSet is1;
        IntegerSet is2;
        for (int i = 0; i < 7; i++)
            is1.insert(i);
        for (int i = 2; i < 9; i++)
            is2.insert(i);
        std::cout << "is1: " << is1 << std::endl;
        std::cout << "is2: " << is2 << std::endl;
        std::cout << "is1+is2: " << (is1 + is2) << std::endl;

        // testing difference set
        std::cout << "is1-is2: " << (is1 - is2) << std::endl;

        // testing intersection set
        std::cout << "is1^is2: " << (is1 ^ is2) << std::endl;

        // testing ==-operator
        std::cout << "is1 == is2: " << (is1 == is2) << std::endl;
        is2.insert(0);
        is2.insert(1);
        is2.remove(7);
        is2.remove(8);
        std::cout << "is2: " << is2 << std::endl;
        std::cout << "is1 == is2: " << (is1 == is2) << std::endl;
        std::cout << "is1 != is2: " << (is1 != is2) << std::endl;

        // testing subset operator
        std::cout << "is1: " << is1 << std::endl;
        std::cout << "is2: " << is2 << std::endl;
        std::cout << "is1 <= is2: " << (is1 <= is2) << std::endl;
        is1.insert(7);
        std::cout << "is1: " << is1 << std::endl;
        std::cout << "is1 <= is2: " << (is1 <= is2) << std::endl;

        // testing assignment operator
        is1 = is2;
        std::cout << "is1: " << is1 << std::endl;
        is1 = is1;
        std::cout << "is1: " << is1 << std::endl;
    }

    void test_arithmetic_assignment_operators()
    {
        int elems1[3] = { 1, 2, 3 };
        IntegerSet is1(elems1, 3);
        std::cout << "is1: " << is1 << std::endl;

        int elems2[3] = { 4, 5, 6 };
        IntegerSet is2(elems2, 3);
        std::cout << "is2: " << is2 << std::endl;

        int elems3[3] = { 7, 8, 9 };
        IntegerSet is3(elems3, 3);
        std::cout << "is3: " << is3 << std::endl;

        is1 += is2 += is3;

        std::cout << "is1: " << is1 << std::endl;
        std::cout << "is2: " << is2 << std::endl;
        std::cout << "is3: " << is3 << std::endl;
    }

    void test_subscript_operator()
    {
        int elems[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        IntegerSet is(elems, 9);

        for (int i = 0; i < is.size(); i++)
            std::cout << "Element at " << i << ": " << is[i] << std::endl;
    }
}

void main_variant_01()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    using namespace IntegerSetClassic;

    test_ctors_dtor();
    test_methods();
    test_remove();
    test_insert();
    test_operators();
    test_arithmetic_assignment_operators();
    test_subscript_operator();
}

// ===============================================================================
// End-of-File
// ===============================================================================
