// ===========================================================================
// Hash.h // Hash Function & Implementation
// ===========================================================================

#pragma once

#include <string>

namespace BasicHashMap {

	// primary template - default hash function object
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
