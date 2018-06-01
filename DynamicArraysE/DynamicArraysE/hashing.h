#pragma once

#include "stdafx.h"
#include <functional>
#include "includes.h"


namespace HashFunction {

	
	typedef function< unsigned int(const char*, unsigned int)> HashFunc;

	//implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);
	
	//ADD YOUR FUNCTIONS HERE
	unsigned int RSHash(const char* str, unsigned int length);

	// a helper to access a default hash function
	static HashFunc m_default1 = badHash;
	static HashFunc m_default2 = RSHash;

}