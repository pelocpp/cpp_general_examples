// ===========================================================================
// ConstHashMapIterator.h // Const Forward Iterator Interface & Implementation
// ===========================================================================

export module hash_map:const_hash_map_iterator;

import std;

namespace BasicHashMap {

    // const_hash_map_iterator class definition
    export
    template <typename HashMap>
    class ConstHashMapIterator
    {
    public:
        using value_type = typename HashMap::value_type;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::const_iterator;

    protected:
        size_t m_bucketIndex = 0;
        list_iterator_type m_listIterator;
        const HashMap* m_hashmap = nullptr;

    public:
        // Forward iterators must supply a default constructor.
        // Using an iterator constructed with the default constructor
        // is undefined, so it doesn't matter how it's initialized.
        ConstHashMapIterator() = default;

        ConstHashMapIterator(size_t bucket, list_iterator_type iter, const HashMap* hashmap)
            : m_bucketIndex{ bucket }, m_listIterator{ iter }, m_hashmap{ hashmap }
        {}

        // Don't need to define a copy constructor or operator= because the
        // default behavior is what we want.

        // Don't need destructor because the default behavior
        // (not deleting mHashmap) is what we want!

        const value_type& operator*() const
        {
            return *m_listIterator;
        }

        // Return type must be something to which -> can be applied.
        // Return a pointer to a pair<const Key, T>, to which the compiler
        // will apply -> again.
        const value_type* operator->() const
        {
            return &(*m_listIterator);
        }

        ConstHashMapIterator<HashMap>& operator++()
        {
            increment();
            return *this;
        }


        ConstHashMapIterator<HashMap> operator++(int)
        {
            auto oldIt = *this;
            increment();
            return oldIt;
        }

        // The following are ok as member functions because we don't
        // support comparisons of different types to this one.
        bool operator==(const ConstHashMapIterator<HashMap>& rhs) const
        {
            // All fields, including the hash_map to which the iterators refer, must be equal
            return (m_hashmap == rhs.m_hashmap &&
                m_bucketIndex == rhs.m_bucketIndex &&
                m_listIterator == rhs.m_listIterator);
        }

        bool operator!=(const ConstHashMapIterator<HashMap>& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        // Helper methods for operator++ and operator--
        // void increment();
        // void decrement();

        // Behavior is undefined if mListIterator already refers to the past-the-end
        // element, or is otherwise invalid.
        void increment()
        {
            // mListIterator is an iterator into a single bucket. Increment it.
            ++m_listIterator;

            // If we're at the end of the current bucket,
            // find the next bucket with elements.
            auto& buckets = m_hashmap->m_buckets;
            if (m_listIterator == end(buckets[m_bucketIndex])) {
                for (size_t i = m_bucketIndex + 1; i < buckets.size(); i++) {
                    if (!buckets[i].empty()) {
                        // We found a non-empty bucket.
                        // Make m_listIterator refer to the first element in it.
                        m_listIterator = begin(buckets[i]);
                        m_bucketIndex = i;
                        return;
                    }
                }

                // No more non-empty buckets. Set m_listIterator to refer to the
                // end iterator of the last list.
                m_bucketIndex = buckets.size() - 1;
                m_listIterator = end(buckets[m_bucketIndex]);
            }
        }
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
