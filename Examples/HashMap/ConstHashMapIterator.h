// ===========================================================================
// ConstHashMapIterator.h // HashMap Interface & Implementation
// ===========================================================================

#pragma once

//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <cstddef>
//#include <vector>
//#include <list>
//#include <string>
//#include <utility>
//#include <functional>
//#include <type_traits>

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <utility>

namespace BasicHashMap {

    // const_hash_map_iterator class definition
    template <typename HashMap>
    class const_hash_map_iterator
    {
        // The hash_map class needs access to all members of the const_hash_map_iterator
       //friend HashMap;

    public:
        using value_type = typename HashMap::value_type;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::const_iterator;

    protected:
        size_t mBucketIndex = 0;
        list_iterator_type mListIterator;
        const HashMap* mHashmap = nullptr;

    public:
        // Bidirectional iterators must supply a default constructor.
        // Using an iterator constructed with the default constructor
        // is undefined, so it doesn't matter how it's initialized.
        const_hash_map_iterator() = default;

        const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap)
            : mBucketIndex(bucket), mListIterator(listIt), mHashmap(hashmap)
        {
        }

        // Don't need to define a copy constructor or operator= because the
        // default behavior is what we want.

        // Don't need destructor because the default behavior
        // (not deleting mHashmap) is what we want!

        const value_type& operator*() const
        {
            return *mListIterator;
        }

        // Return type must be something to which -> can be applied.
        // Return a pointer to a pair<const Key, T>, to which the compiler
        // will apply -> again.
        const value_type* operator->() const
        {
            return &(*mListIterator);
        }

        const_hash_map_iterator<HashMap>& operator++()
        {
            increment();
            return *this;
        }


        const_hash_map_iterator<HashMap> operator++(int)
        {
            auto oldIt = *this;
            increment();
            return oldIt;
        }

        //const_hash_map_iterator<HashMap>& operator--();
        //const_hash_map_iterator<HashMap> operator--(int);

        // The following are ok as member functions because we don't
        // support comparisons of different types to this one.
        bool operator==(const const_hash_map_iterator<HashMap>& rhs) const
        {
            // All fields, including the hash_map to which the iterators refer, must be equal
            return (mHashmap == rhs.mHashmap &&
                mBucketIndex == rhs.mBucketIndex &&
                mListIterator == rhs.mListIterator);
        }

        bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const
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
            ++mListIterator;

            // If we're at the end of the current bucket,
            // find the next bucket with elements.
            auto& buckets = mHashmap->m_buckets;
            if (mListIterator == end(buckets[mBucketIndex])) {
                for (size_t i = mBucketIndex + 1; i < buckets.size(); i++) {
                    if (!buckets[i].empty()) {
                        // We found a non-empty bucket.
                        // Make mListIterator refer to the first element in it.
                        mListIterator = begin(buckets[i]);
                        mBucketIndex = i;
                        return;
                    }
                }

                // No more non-empty buckets. Set mListIterator to refer to the
                // end iterator of the last list.
                mBucketIndex = buckets.size() - 1;
                mListIterator = end(buckets[mBucketIndex]);
            }
        }
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
