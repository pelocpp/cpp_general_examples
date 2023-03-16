// ===========================================================================
// TestHash.cpp // Testing Hash Function
// ===========================================================================

#include <iostream>

#include "Hash.h"

// function prototypes
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

void testHashFunction() {

    test_hashFunction_01();
}

// ===========================================================================
// End-of-File
// ===========================================================================
