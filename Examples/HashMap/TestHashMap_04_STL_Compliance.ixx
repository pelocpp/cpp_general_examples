// ===========================================================================
// TestHashMap_04_STL_Compliance.ixx // Testing Hash Function
// ===========================================================================

export module hash_map_test:test_hashmap_stl_compliance;

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
        // use both -> and * to test the operations
        std::cout << it->first << " maps to " << (*it).second << std::endl;
    }

    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        // use both -> and * to test the operations
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


    // using value_type = std::pair<const Key, T>;

    // user written output iterator

    // https://brevzin.github.io/c++/2022/02/06/output-iterators/

    // https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp



    std::copy_if(
        map.begin(),
        map.end(),
        // std::insert_iterator<HashMap<std::string, size_t>>(map2),
        // std::insert_iterator<HashMap<std::string, size_t>>(map2, std::next(map2.begin())),
        // std::inserter(map2, std::next(map2.begin())),

        std::inserter(map2, map2.end()),

        // map2.begin(),

        [](const auto& entry) {

            return true;
        }
    );
}

static void testHashMap_04()
{
    using namespace BasicHashMap;

    std::cout << "Test HashMap - 04:" << std::endl;

    HashMap<std::string, size_t> map{};
    map.insert(std::make_pair(std::string{ "Meier" }, 123456));
    map.insert(std::make_pair(std::string{ "Mueller" }, 54321));
    map.insert(std::make_pair(std::string{ "Schneider" }, 14234));
    map.insert(std::make_pair(std::string{ "Fischer" }, 32452));
    map.insert(std::make_pair(std::string{ "Wagner" }, 98234));

    ConstHashMapIterator<HashMap<std::string, size_t>> iter;
}

export void testHashMap_Compliance() {

    testHashMap_01();
    testHashMap_02();
    testHashMap_03();
    testHashMap_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
