// ===========================================================================
// HashMap.h // HashMap Interface & Implementation
// ===========================================================================

#pragma once

#include <iostream>
#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <functional>

namespace BasicHashMap {

	// Besser: TKey, TValue

	template <typename Key, typename T>
	class HashMap
	{
	public:
		using EntryType = std::pair<const Key, T>;
		using ListType = std::list<EntryType>;

	private:
		static const size_t HashTableSize = 19;  // or 101

		std::vector<std::list<EntryType>> m_buckets;
		size_t      m_size;
		Hash<Key>   m_hash;

	public:
		// c'tor
		explicit HashMap(size_t countBuckets = HashTableSize) : m_buckets{}
		{
			if (countBuckets == 0) {
				throw std::invalid_argument("Number of buckets must be positive");
			}

			m_buckets.resize(countBuckets);
			m_size = 0;
			m_hash = Hash<Key>{};
		}

		// getter
		size_t size() const noexcept { return m_size; }

		// inserting key-value pair
		bool insert(const EntryType& entry)
		{
			// try to find the element.
			auto [iter, bucket] = findElement(entry.first);

			if (iter != std::end(m_buckets[bucket])) {
				// element already exists
				return false;  
			}
			else {
				// element not found, insert a new one
				++ m_size;
				m_buckets[bucket].push_back(entry);
				return true;
			}
		}

		bool erase(const Key& key)
		{
			// First, try to find the element.
			auto [it, bucket] = findElement(key);

			if (it != end(m_buckets[bucket])) {
				// The element exists -- erase it.
				m_buckets[bucket].erase(it);
				--m_size;
				return true;
			}
			else {
				return false;
			}
		}


		void clear() noexcept  // why noexcept
		{
			// Call clear on each bucket.
			for (auto& bucket : m_buckets) {
				bucket.clear();
			}
			m_size = 0;
		}

		[[nodiscard]] EntryType* find(const Key& key)
		{
			 auto[iter, bucket] = findElement(key);

			 if (iter == std::end(m_buckets[bucket])) {
				  return nullptr;
			 }

			 return &(*iter);  // element found, return a pointer to it
		}

		[[nodiscard]] const EntryType* find(const Key& key) const
		{
			return const_cast<HashMap<Key, T>*>(this) -> find(key);
		}



	private:
		std::pair<typename ListType::iterator, size_t> findElement(const Key& key)
		{
			// compute hash of key to get index of bucket
			size_t index{ m_hash(key) % m_buckets.size() };

			// search for the key in the bucket
			auto iter{ std::find_if(
				std::begin(m_buckets[index]),
				std::end(m_buckets[index]),
				[=](const auto& element) {
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
