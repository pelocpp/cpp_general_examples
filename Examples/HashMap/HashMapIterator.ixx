// ===========================================================================
// HashMapIterator.h // Forward Iterator Interface & Implementation
// ===========================================================================

export module hash_map:hash_map_iterator;

import std;

export import :const_hash_map_iterator;

namespace BasicHashMap {

 //   export
    template <typename HashMap>
    class HashMapIterator : public ConstHashMapIterator<HashMap>
    {
    public:
        using value_type = typename ConstHashMapIterator<HashMap>::value_type;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::iterator;

        // take care of "two-phase name lookup" in this class template
        using ConstHashMapIterator<HashMap>::increment;
        using ConstHashMapIterator<HashMap>::m_listIterator;

        HashMapIterator() = default;

        HashMapIterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap)
            : ConstHashMapIterator<HashMap>{ bucket, listIt, hashmap }
        {}

        // return a reference to the actual element
        value_type& operator*()
        {
            return const_cast<value_type&>(*m_listIterator);
        }


        // return a pointer to the actual element, so the compiler can
        // apply -> to it to access the actual desired field
        value_type* operator->()
        {
            return const_cast<value_type*>(&(*m_listIterator));
        }

        // defer the details to the increment() helper in the base class
        HashMapIterator<HashMap>& operator++()
        {
            increment();
            return *this;
        }

        // Defer the details to the increment() helper in the base class.
        HashMapIterator<HashMap> operator++(int)
        {
            auto oldIt = *this;
            increment();
            return oldIt;
        }
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
