#ifndef _MATH_CALC_BASE_CALC_TOOLS_H
#define _MATH_CALC_BASE_CALC_TOOLS_H
#pragma once

#include <string>
#include <vector>

class Tools {
public:
	Tools();
	~Tools();

	int replace_v(const char* src, char* dest, int var, const char* val);
	int replace_v(const std::string& src, std::string& dest, int var, const std::string& val);
	void replace_var(std::string& m, const char var, std::vector<char*>& val);
	std::pair<std::string, std::vector<char*>> gen_var_val_pair(std::string var, std::vector<char*>& val);
private:

};

#endif // !_MATH_CALC_BASE_CALC_TOOLS_H
