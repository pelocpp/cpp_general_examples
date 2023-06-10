// ===========================================================================
// TestHashMap_02_Basics.ixx // Testing Hash Function
// ===========================================================================

export module hash_map_test:test_hashmap_basics;

import hash_map;
import std;

// function prototypes
static void testHashMap_01();
static void testHashMap_02();
static void testHashMap_03();
static void testHashMap_04();
static void testHashMap_05();
static void testHashMap_06();

static void testHashMap_01() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 01:" << std::endl;
    HashMap<int, int> map{};
    map.insert(std::make_pair(4, 40));
    map.insert(std::make_pair(6, 60));
    std::cout << "Done." << std::endl;
}

static void testHashMap_02() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 02:" << std::endl;
    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    std::cout << "Done." << std::endl;
}

static void testHashMap_03() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 03:" << std::endl;
    HashMap<const char*, int> map{};
    map.insert(std::make_pair("Meier", 123456));
    map.insert(std::make_pair("Mueller", 54321));
    std::cout << "Done." << std::endl;
}

static void testHashMap_04() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 04:" << std::endl;
    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));

    // warning: discarding return value of function with 'nodiscard' attribute
    // map.find(std::string{ "Mueller" });   

    HashMap<std::string, size_t>::EntryType* entry{
        map.find(std::string{ "Mueller" })
    };

    if (entry != nullptr) {
        std::cout << "Mueller maps to " << entry->second << std::endl;
    }

    entry = map.find(std::string{ "Huber" });
    if (entry == nullptr) {
        std::cout << "Huber not found in map!" << std::endl;
    }

    const auto* constEntry{ map.find(std::string{ "Mueller" }) };
    if (constEntry != nullptr) {
        std::cout << "Mueller maps to " << constEntry->second << std::endl;
    }

    std::cout << "Done." << std::endl;
}

static void testHashMap_05() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 05:" << std::endl;
    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    HashMap<std::string, size_t>::EntryType* entry{ map.find(std::string{ "Schneider" }) };
    if (entry != nullptr) {
        std::cout << "Schneider maps to " << entry->second << std::endl;
    }

    map.erase("Schneider");

    entry = map.find(std::string{ "Schneider" });
    if (entry == nullptr) {
        std::cout << "Schneider not found in map!" << std::endl;
    }

    std::cout << "Size of map: " << map.size() << std::endl;
    map.clear();
    std::cout << "Size of map: " << map.size() << std::endl;

    std::cout << "Done." << std::endl;
}

static void testHashMap_06() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 06:" << std::endl;
    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    size_t phone = map[{ "Schneider" }];
    std::cout << "Phone Number of Schneider: " << phone << std::endl;

    phone = map[{ "Fischer" }];
    std::cout << "Phone Number of Fischer:  " << phone << std::endl;

    map[{ "Fischer" }] = 291823;

    phone = map[{ "Fischer" }];
    std::cout << "Phone Number of Fischer:  " << phone << std::endl;

    map[{ "Meierhofer" }] = 291823;

    std::cout << "Done." << std::endl;
}

static void testHashMap_07() {

    using namespace BasicHashMap;

    std::cout << "Test HashMap - 07:" << std::endl;
    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    map.print();

    std::cout << "Done." << std::endl;
}

export void testHashMap_Basic() {

    testHashMap_01();
    testHashMap_02();
    testHashMap_03();
    testHashMap_04();
    testHashMap_05();
    testHashMap_06();
    testHashMap_07();
}

// ===========================================================================
// End-of-File
// ===========================================================================
