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
	void replace_var(std::string& m, const char var, std::vector<std::string>& val);
	double summation(const std::string& equation, int from, int to);
	double prod_sec(const std::string& equation, int from, int to);
	int shift(int num, int bits_count, const std::string type);
	int dec_to_hex(double num);
	int hex_to_dec(double num);
	const std::string dec_to_bin(double num);
	int bin_to_dec(std::string num);
	int dec_to_oct(double num);
	int oct_to_dec(double num);
	std::pair<std::string, std::vector<std::string>> gen_var_val_pair(std::string var, const std::vector<std::string>& val) const;
	std::pair<std::string, std::vector<char*>> gen_var_val_pair(std::string var, const std::vector<char*>& val) const;
private:

};

#endif // !_MATH_CALC_BASE_CALC_TOOLS_H
