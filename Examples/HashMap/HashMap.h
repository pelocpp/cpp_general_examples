// ===========================================================================
// HashMap.h // HashMap Interface & Implementation
// ===========================================================================

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <functional>
#include <type_traits>

#include "ConstHashMapIterator.h"
#include "HashMapIterator.h"

namespace BasicHashMap {

    // Besser: TKey, TValue

    template <typename Key, typename T>
    class HashMap
    {
    public:
        using EntryType = std::pair<const Key, T>;
        using ListType = std::list<EntryType>;

        using value_type = std::pair<const Key, T>;

        // benutzt in der Iterator Klasse 
        // Die Namen sind stilistisch alle sehr verschieden ...
        using list_iterator_type = typename HashMap::ListType::const_iterator;

        using hash_map_type = HashMap<Key, T>;
        using iterator = hash_map_iterator<hash_map_type>;
        using const_iterator = const_hash_map_iterator<hash_map_type>;


    // private:  TO BE FIXED must be private
    public:
        static const size_t HashTableSize = 23;  // or 101

        std::vector<std::list<EntryType>> m_buckets;
        size_t      m_size;
        Hash<Key>   m_hash;

    public:
        // c'tor
        explicit HashMap(size_t countBuckets = HashTableSize) : m_buckets{}, m_size{}
        {
            if (countBuckets == 0) {
                throw std::invalid_argument("Number of buckets must be positive");
            }

            m_buckets.resize(countBuckets);
            m_hash = Hash<Key>{};
        }

        // copy constructor
        HashMap(const HashMap& src) = default;

        // move constructor
        HashMap(HashMap&& src) noexcept {
            swap(*this, src);
        }

        // getter
        size_t size() const noexcept { return m_size; }

        // iterator methods
        iterator begin() {

            if (m_size == 0) {
                // Special case: there are no elements, so return the end iterator.
                return end();
            }

            // We know there is at least one element. Find the first element.
            for (size_t i = 0; i < m_buckets.size(); ++i) {
                if (!m_buckets[i].empty()) {
                    return hash_map_iterator<hash_map_type>(i, std::begin(m_buckets[i]), this);
                }
            }
            // Should never reach here, but if we do, return the end iterator.
            return end();
        }
        
        iterator end() {

            // The end iterator is the end iterator of the list of the last bucket.
            size_t bucket = m_buckets.size() - 1;
            return hash_map_iterator<hash_map_type>(bucket, std::end(m_buckets[bucket]), this);
        }

        const_iterator begin() const
        {
            // Use const_cast to call the non-const version of begin(). That
            // one returns an iterator which is convertible to a const_iterator.
            return const_cast<hash_map_type*>(this)->begin();
        }

        const_iterator end() const
        {
            // Use const_cast to call the non-const version of end(). That
            // one returns an iterator which is convertible to a const_iterator.
            return const_cast<hash_map_type*>(this)->end();
        }

        const_iterator cbegin() const
        {
            return begin();
        }

        const_iterator cend() const
        {
            return end();
        }

        // public interface

        // inserting key-value pair
        bool insert(const EntryType& entry)
        {
            // try to find the element.
            auto [iter, index] = findElement(entry.first);

            if (iter != std::end(m_buckets[index])) {
                // element already exists
                return false;  
            }
            else {
                // element not found, insert a new one
                ++ m_size;
                m_buckets[index].push_back(entry);
                return true;
            }
        }

        bool erase(const Key& key)
        {
            // First, try to find the element.
            auto [iter, index] = findElement(key);

            if (iter != std::end(m_buckets[index])) {
                // The element exists -- erase it.
                m_buckets[index].erase(iter);
                --m_size;
                return true;
            }
            else {
                return false;
            }
        }

        void clear() noexcept  // why noexcept
        {
            for (auto& bucket : m_buckets) {
                bucket.clear();
            }
            m_size = 0;
        }

        [[nodiscard]] EntryType* find(const Key& key)
        {
             const auto&[iter, index] = findElement(key);

             if (iter == std::end(m_buckets[index])) {
                  return nullptr;
             }

             return &(*iter);  // element found, return a pointer to it
        }

        [[nodiscard]] const EntryType* find(const Key& key) const
        {
            return const_cast<HashMap<Key, T>*>(this) -> find(key);
        }

        T& operator[] (const Key& key)
        {
            auto [iter, index] = findElement(key);

            if (iter == std::end(m_buckets[index])) {
                ++m_size;
                m_buckets[index].push_back(std::make_pair(key, T{}));
                return m_buckets[index].back().second;
            }
            else {
                return iter->second;
            }
        }

        // to_string has no overload taking std::string
        std::string keyToString(const std::string& value)
        {
            return value;
        }

        template <typename TValue>
        void keyToString(const TValue& value)
        {
            using namespace std;
            std::cout << to_string(value) << std::endl;
        }

        // So nicht --- wieder löschen
        //HashMap& operator= (const HashMap& other) = default;
        //HashMap& operator= (HashMap&& other) noexcept = default;

        // assignment
        HashMap& operator= (const HashMap& other) {

            // prevent self-assignment
            if (this == &other) {
                return *this;
            }

            auto copy = other;
            swap(copy);

            return *this;
        }

        HashMap& operator= (HashMap&& other) noexcept {

            swap(other);
            return *this;
        }

        void print()
        {
            std::cout << "HashMap  (" << m_size << " entries):" << std::endl;

            for (const auto& bucket : m_buckets) {

                typename std::list<EntryType>::const_iterator begin = bucket.begin();
                typename std::list<EntryType>::const_iterator end = bucket.end();

                while (begin != end) {

                    const auto& [key, value]  = *begin;
                    std::string skey{ keyToString(key) + ":" };
                    std::cout << std::left << std::setw(12) << skey << value << std::endl;
                    ++begin;
                }
            }
        }

    private:
        void swap(HashMap& other) {

            using std::swap;

            swap(m_buckets, other.m_buckets);
            swap(m_size, other.m_size);
            swap(m_hash, other.m_hash);
        }

        void swap(HashMap& first, HashMap& second) noexcept
        {
            first.swap(second);
        }

        std::pair<typename ListType::iterator, size_t> findElement(const Key& key)
        {
            // compute hash of key to get index of bucket
            size_t index{ m_hash(key) % m_buckets.size() };

            // search for the key in the bucket
            auto iter{ std::find_if(
                std::begin(m_buckets[index]),
                std::end(m_buckets[index]),
                [=](const auto& element) {
                                                  // wie wäre das mit einem Concept  
                    return element.first == key;  // Was ist, wenn der == Operator nicht definiert ist ?????  // auf std::equal umstellen ....
                }
            )};

            // return a pair of the iterator and the bucket index
            return std::make_pair(iter, index);
        }
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
