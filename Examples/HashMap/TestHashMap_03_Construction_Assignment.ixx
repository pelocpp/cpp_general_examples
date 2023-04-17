// ===========================================================================
// TestHashMap_02_Construction_Assignment.cpp // Testing Hash Function
// ===========================================================================

export module hash_map_test:test_hashmap_construction_assignment;

import hash_map;
import std;

// function prototypes
static void testHashMap_01();
static void testHashMap_02();

static void testHashMap_01() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 01:" << std::endl;

    HashMap<std::string, size_t> map1{};
    map1.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map1.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map1.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map1.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map1.insert(std::make_pair(std::string{ "Wagner" }, 98234));
    map1.print();
    std::cout << std::endl;

    HashMap<std::string, size_t> map2{ map1 };
    map2.print();
    std::cout << std::endl;

    HashMap<std::string, size_t> map3;
    map3 = map1;
    map3.print();

    std::cout << "Done." << std::endl;
}

static void testHashMap_02() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 02:" << std::endl;

    HashMap<std::string, size_t> map1{};
    map1.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map1.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map1.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map1.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map1.insert(std::make_pair(std::string{ "Wagner" }, 98234));
    map1.print();
    std::cout << std::endl;

    HashMap<std::string, size_t> map2{ std::move(map1) };
    map1.print();
    std::cout << std::endl;
    map2.print();
    std::cout << std::endl;

    HashMap<std::string, size_t> map3;
    map3 = std::move(map2);

    map2.print();
    std::cout << std::endl;
    map3.print();
    std::cout << std::endl;

    std::cout << "Done." << std::endl;
}

export void testHashMap_Construction_Assignment() {

    testHashMap_01();
    testHashMap_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
