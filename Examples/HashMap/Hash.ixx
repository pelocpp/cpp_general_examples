// ===========================================================================
// Hash.h // Hash Function & Implementation
// ===========================================================================

export module hash_map:hash_function;

import std;

namespace BasicHashMap {

	// primary template - default hash function object
    export
	template <typename T>
	class Hash
	{
	public:
		size_t operator()(const T& key) const
		{
			const size_t bytes{ sizeof(key) };
			size_t sum{};

			for (size_t i{}; i != bytes; ++i)
			{
				unsigned char b = *((reinterpret_cast<const unsigned char*>(&key)) + i);
				sum += b;
			}

			return sum;
		}
	};

	// template specialization for std::string
	template <>
	class Hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const
		{
			size_t sum{};
			for (auto ch : key) {
				sum += static_cast<unsigned char>(ch);
			}

			return sum;
		}
	};
}

// ===========================================================================
// End-of-File
// ===========================================================================

    // Calculate a hash by treating the key as a sequence
    // of bytes and summing the ASCII values of the bytes.
    //template <typename T>
    //size_t Hash<T>::operator() (const T& key) const
    //{
    //    const size_t bytes{ sizeof(key) };

    //    size_t sum{};

    //    for (size_t i{}; i != bytes; ++i) {

    //        unsigned char b{};
    //        // unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);

    //       // std::cout << "  b: " << static_cast<unsigned int>(b) << std::endl;

    //        // std::cout << "  b: " << (int) b << std::endl;

    //        // To be Done: Dasselbe mit Shifting Operators

    //        // Da gibt es offenbar 2 Methoden
    //        
    //        // https://codereview.stackexchange.com/questions/199935/reinterpret-cast-vs-bit-shifts-for-extracting-32-bit-integers-from-bytes-with-e



    //        sum += b;
    //    }

    //    return sum;
    //}

    // =================================================
    // Rest


    //template <typename T>
    //size_t Hash<T>::operator() (const T& key, int dummy) const
    //{
    //    const size_t bytes{ sizeof(key) };

    //    size_t sum{};

    //    uint8_t value{};

    //    for (size_t i{}; i != bytes; ++i) {

    //        // To be Done:  Benötige Maske für FF, FF00, FF0000, .... 

    //        //uint8_t byte{ static_cast<uint8_t>((value & 0x00FF0000) >> 16) };

    //        unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);

    //        //std::cout << "  b: " << static_cast<unsigned int>(b) << std::endl;
    //        // std::cout << "  b: " << (int) b << std::endl;

    //        // To be Done: Dasselbe mit Shifting Operators

    //        // Da gibt es offenbar 2 Methoden

    //        // https://codereview.stackexchange.com/questions/199935/reinterpret-cast-vs-bit-shifts-for-extracting-32-bit-integers-from-bytes-with-e

    //        sum += b;
    //    }
    //    return sum;
    //}

    // Calculate a hash by summing the ASCII values of all characters.
    //size_t Hash<std::string>::operator()(const std::string& key) const
    //{
    //    size_t sum = 0;
    //    for (auto c : key) {
    //        sum += static_cast<unsigned char>(c);
    //    }
    //    return sum;
    //}