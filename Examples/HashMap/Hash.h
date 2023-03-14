// ===========================================================================
// Hash.h // Hash Function
// ===========================================================================

#pragma once

#include <string>

namespace BasicHashMap {

	// primary template - default hash function object
	template <typename T>
	class Hash
	{
	public:
		size_t operator()(const T& key) const;
	};

	// template specialization for std::string objects
	//template <>
	//class Hash<std::string>
	//{
	//public:
	//	size_t operator()(const std::string& key) const;
	//};

	// TODO: Was ist mit const char*
	
}

#include "hash.hpp"

// ===========================================================================
// End-of-File
// ===========================================================================
