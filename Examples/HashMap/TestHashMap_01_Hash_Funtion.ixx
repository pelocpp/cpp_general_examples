// ===========================================================================
// TestHashMap_01_Hash_Funtion.cpp // Testing Hash Function
// ===========================================================================

export module hash_map_test:test_hash_function;

import hash_map;
import std;

// internal function prototypes
void test_hashFunction_01();

void test_hashFunction_01() {

    using namespace BasicHashMap;

    std::cout << "Test Hash Function:" << std::endl;

    Hash<unsigned int> function{};

    // dec: 12345 - hex: 0x3039
    size_t hash{ function(12345) };

    std::cout << hash << std::endl;
    std::cout << "Done." << std::endl;
}

export void testHashFunction() {

    test_hashFunction_01();
}

// ===========================================================================
// End-of-File
// ===========================================================================
