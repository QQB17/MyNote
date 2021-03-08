//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"

std::string Sum::AddChar(const char* c1, const char* c2) {
	std::string s = std::string(c1) + std::string(c2);
	return s;
 }

int Sum::Add(int x, int y) {
	return x + y;
}


