// ===========================================================================
// HashMapIterator.h // HashMap Interface & Implementation
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


    template <typename HashMap>
    class hash_map_iterator : public const_hash_map_iterator<HashMap>
    {
        // The hash_map class needs access to all members of the hash_map_iterator
        friend HashMap;

    public:
        using value_type = typename const_hash_map_iterator<HashMap>::value_type;
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;
        using pointer = value_type*;
        using reference = value_type&;
        using list_iterator_type = typename HashMap::ListType::iterator;

        hash_map_iterator() = default;

        hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap)
            : const_hash_map_iterator<HashMap>(bucket, listIt, hashmap)
        {}

        // Return a reference to the actual element.
        value_type& operator*()
        {
            return const_cast<value_type&>(*this->mListIterator);
        }


        // Return a pointer to the actual element, so the compiler can
        // apply -> to it to access the actual desired field.
        value_type* operator->()
        {
            return const_cast<value_type*>(&(*this->mListIterator));
        }

        // Defer the details to the increment() helper in the base class.
        hash_map_iterator<HashMap>& operator++()
        {
            this->increment();
            return *this;
        }

        // Defer the details to the increment() helper in the base class.
        hash_map_iterator<HashMap> operator++(int)
        {
            auto oldIt = *this;
            this->increment();
            return oldIt;
        }
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
