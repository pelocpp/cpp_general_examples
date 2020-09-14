// ===============================================================================
// IntegerSet: Variant 3 - Classic Approach with Move Semantics
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

#include "IntegerSet_03_Classic_MoveSemantics.h"

namespace IntegerSetClassic_MoveSemantics {

    void test_01_move_semantics()
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

        IntegerSet set1{};
        set1.insert(1);
        set1.insert(2);
        set1.insert(3);
        set1.insert(4);

        IntegerSet set2;
        set2.insert(3);
        set2.insert(4);
        set2.insert(5);
        set2.insert(6);

        IntegerSet result1(set1);
        IntegerSet result2 = set1;

        IntegerSet result;
        result = set1 + set2;
        std::cout << result << std::endl;

        IntegerSet set3;
        set3.insert(5);
        set3.insert(6);
        set3.insert(7);
        set3.insert(8);
        result = set1 + set2 + set3;
        std::cout << result << std::endl;
    }
}

void main_variant_03()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    using namespace IntegerSetClassic_MoveSemantics;

    test_01_move_semantics();
}

// ===============================================================================
// End-of-File
// ===============================================================================
