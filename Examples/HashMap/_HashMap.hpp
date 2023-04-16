// ===========================================================================
// HashMap.hpp // HashMap Implementation
// ===========================================================================

#include <iostream>
#include <algorithm>
#include <list>
#include <stdexcept>

#include <vector>
#include <list>
#include <string>
#include <utility>
#include <functional>

//#include <string>
//#include <cstdint>

namespace BasicHashMap {

    template <typename T>
    size_t Hash<T>::operator() (const T& key) const
    {
        const size_t bytes{ sizeof(key) };

        size_t sum{};

        for (size_t i{}; i != bytes; ++i) {

            unsigned char b{};
            // unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);

           // std::cout << "  b: " << static_cast<unsigned int>(b) << std::endl;

            // std::cout << "  b: " << (int) b << std::endl;

            // To be Done: Dasselbe mit Shifting Operators

            // Da gibt es offenbar 2 Methoden

            // https://codereview.stackexchange.com/questions/199935/reinterpret-cast-vs-bit-shifts-for-extracting-32-bit-integers-from-bytes-with-e



            sum += b;
        }

        return sum;
    }

    // c'tor
    template <typename Key, typename T>
    HashMap<Key, T>::HashMap(size_t countBuckets) : m_buckets(countBuckets)
    {
        if (countBuckets == 0) {
            throw std::invalid_argument("Number of buckets must be positive");
        }

        m_size = 0;
        m_hash = Hash<T>{};
    }

    // std::pair<std::list<std::pair<Key, T>>::iterator, size_t>

    template <typename Key, typename T>
    std::pair<typename HashMap<Key, T>::ListType::iterator, size_t>
        HashMap<Key, T>::findElement(const Key& k)
    {
        // compute hash of key to get index of bucket
        size_t bucket = m_hash(k) % m_buckets.size();

       // typename std::list<std::pair<Key, T>>::iterator iter{};

        // search for the key in the bucket
        auto iter = std::find_if(
            begin(m_buckets[bucket]),
            end(m_buckets[bucket]),
            [=](const auto& element) {
                //return m_equal(element.first, k);

                return element.first == k;  // Was ist, wenn der == Operator nicht definiert ist ?????

                //return true;
            }
        );

        // return a pair of the iterator and the bucket index
        return std::make_pair(iter, bucket);
    }

    template <typename Key, typename T>
    void HashMap<Key, T>::insert(const value_type& x)
    {
        // try to find the element.
        auto [it, bucket] = findElement(x.first);

        if (it != end(m_buckets[bucket])) {
            // The element already exists.
            return;
        }
        else {
            // We didn't find the element, so insert a new one.
            m_size++;
            m_buckets[bucket].push_back(x);
        }
    }

}

// ===========================================================================
// End-of-File
// ===========================================================================
