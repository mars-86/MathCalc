#ifndef _MATH_CALC_BASE_CALC_TOOLS_H
#define _MATH_CALC_BASE_CALC_TOOLS_H
#pragma once

#include <string>

class Tools {
public:
	Tools();
	~Tools();

	int replace_v(const char* src, char* dest, int var, const char* val);
	int replace_v(const std::string& src, std::string& dest, int var, const std::string& val);
private:

};

#endif // !_MATH_CALC_BASE_CALC_TOOLS_H
