// ===========================================================================
// TestHashMap_03_STL_Compliance.cpp // Testing Hash Function
// ===========================================================================

import hash_map;

import std;

// function prototypes
static void testHashMap_01();
static void testHashMap_02();

static void testHashMap_01()
{
    using namespace BasicHashMap;

    std::cout << "Test HashMap - 03:" << std::endl;

    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    for (auto it = map.begin(); it != map.end(); ++it) {
        // Use both -> and * to test the operations
        std::cout << it->first << " maps to " << (*it).second << std::endl;
    }


    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        // Use both -> and * to test the operations
        std::cout << it->first << " maps to " << (*it).second << std::endl;
    }
}

static void testHashMap_02()
{
    using namespace BasicHashMap;

    std::cout << "Test HashMap - 03:" << std::endl;

    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));
    
    std::vector<std::string> names;

    std::transform(
        map.begin(),
        map.end(),
        std::back_inserter(names),
        [](const auto& entry) {
            std::cout << entry.first << std::endl;
            return entry.first;

        }
    ); 
}

static void testHashMap_03()
{
    using namespace BasicHashMap;

    std::cout << "Test HashMap - 03:" << std::endl;

    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    // std::vector<std::string> names;
    HashMap<std::string, size_t> map2{};

    //std::copy_if(
    //    map.begin(),
    //    map.end(),
    //    std::insert_iterator(map2),
    //    [](const auto& entry) {

    //        return true;
    //    }
    //);
}

void testHashMap_Compliance() {

   // testHashMap_01();
    testHashMap_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
