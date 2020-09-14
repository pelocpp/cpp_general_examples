// ===============================================================================
// IntegerSet: Variant 2 - Modern Approach (STL container class 'std::vector')
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
#include <vector>

#include "IntegerSet_02_Vector.h"

namespace IntegerSetVector {

    void test_ctors_dtor()
    {
        std::cout << "Testing c'tors / d'tor: " << std::endl;

        using namespace IntegerSetVector;

        IntegerSet is1;
        std::cout << "is1: " << is1 << std::endl;

        std::vector<int> vec1 = { -2, -1, 0, 1, 2, -1, -2 };
        IntegerSet is2(vec1);
        std::cout << "is2: " << is2 << std::endl;

        std::vector<int> vec2 = { -1, 1, 2, 3, 1, 2, 3, 1, 2, 3, -1 };
        IntegerSet is3(vec2);
        std::cout << "is3: " << is3 << std::endl;

        IntegerSet is4(is3);
        std::cout << "is4: " << is4 << std::endl;

        std::cout << "is1.isEmpty: " << is1.isEmpty() << std::endl;
        std::cout << "is2.isEmpty: " << is2.isEmpty() << std::endl;
        std::cout << "is3.isEmpty: " << is3.isEmpty() << std::endl;
        std::cout << "is4.isEmpty: " << is4.isEmpty() << std::endl;
    }

    void test_methods()
    {
        using namespace IntegerSetVector;

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
        using namespace IntegerSetVector;

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
        using namespace IntegerSetVector;

        IntegerSet is;
        for (int i = 0; i < 16; i++)
            is.insert(i);

        std::cout << "is: " << is << std::endl;

        is.insert(16);
        std::cout << "is: " << is << std::endl;
    }

    void test_operators()
    {
        using namespace IntegerSetVector;

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
        using namespace IntegerSetVector;

        std::vector<int> vec1 = { 1, 2, 3 };
        IntegerSet is1(vec1);
        std::cout << "is1: " << is1 << std::endl;

        std::vector<int> vec2 = { 4, 5, 6 };
        IntegerSet is2(vec2);
        std::cout << "is2: " << is2 << std::endl;

        std::vector<int> vec3 = { 7, 8, 9 };
        IntegerSet is3(vec3);
        std::cout << "is3: " << is3 << std::endl;

        is1 += is2 += is3;

        std::cout << "is1: " << is1 << std::endl;
        std::cout << "is2: " << is2 << std::endl;
        std::cout << "is3: " << is3 << std::endl;
    }

    void test_subscript_operator()
    {
        using namespace IntegerSetVector;

        std::vector<int> vec = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        IntegerSet is(vec);

        for (int i = 0; i < is.size(); i++)
            std::cout << "Element at " << i << ": " << is[i] << std::endl;
    }
}

void main_variant_02()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    using namespace IntegerSetVector;

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
