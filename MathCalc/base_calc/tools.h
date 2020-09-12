#ifndef _MATH_CALC_BASE_CALC_TOOLS_H_
#define _MATH_CALC_BASE_CALC_TOOLS_H_
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Tools {
private:
	// Generates a pair of values of the type {variable : value}
	inline std::pair<std::string, std::vector<long double>> gen_var_val_pair(std::string var, double val) const
	{
		return std::pair<std::string, std::vector<long double>>(var, { val });
	}

	inline std::pair<std::string, std::vector<std::string>> gen_var_val_pair(std::string var, const std::vector<std::string>& val) const
	{
		return std::pair<std::string, std::vector<std::string>>(var, val);
	}

	inline std::pair<std::string, std::vector<char*>> gen_var_val_pair(std::string var, const std::vector<char*>& val) const
	{
		return std::pair<std::string, std::vector<char*>>(var, val);
	}

	inline const std::vector<std::string> get_val_as_vec(double val) const
	{
		return { std::to_string(val) };
	}

	inline const char get_hex_digit(unsigned char digit)
	{
		switch (digit) {
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
		default: return '0' + digit;
		}
	}

public:
	Tools();
	~Tools();

	// FIX: FACTORIAL CRASHES > 20
	inline unsigned long long int factorial(int x)
	{
		unsigned long long int x_ = x;
		if (x_ == 0) return 1;
		for (int i = x - 1; i > 0; --i) x_ *= i;
		return x_;
	}

	int replace_v(const char* src, char* dest, int var, const char* val);
	int replace_v(const std::string& src, std::string& dest, int var, const std::string& val);
	void replace_var(std::string& m, const char var, std::vector<char*>& val);
	void replace_var(std::string& m, const char var, std::vector<std::string>& val);
	double summation(const std::string& equation, int from, int to);
	double prod_sec(const std::string& equation, int from, int to);
	int shift(int num, int bits_count, const std::string type);
	
	inline const std::string dec_to_hex_str(unsigned int num)
	{
		std::string hex = { get_hex_digit(num & 15) };
		while (num > 1)
			hex.insert(hex.begin(), get_hex_digit((num >>= 4) & 15));
		return hex;
	}

	inline const std::string dec_to_bin_str(unsigned int num)
	{
		std::string bin = { std::to_string((num & 1)) };
		while (num > 1)	bin.insert(bin.begin(), ((num >>= 1) & 1));
		return bin;
	}

	inline const std::vector<bool> dec_to_bin_arr(size_t num, int bits = 0)
	{
		std::vector<bool> bin = { (bool)(num & 1) };
		while (num > 1) bin.insert(bin.begin(), ((num >>= 1) & 1));
		while (bin.size() < bits) bin.insert(bin.begin(), 0);
		return bin;
	}

	int bin_to_dec(std::string num);
	int dec_to_oct(double num);
	int oct_to_dec(double num);
	
	inline std::map<std::string, std::vector<std::string>> gen_var_val_tab(std::string var, std::string val) noexcept
	{
		return { gen_var_val_pair(var, { val }) };
	}

	inline std::map<std::string, std::vector<std::string>> gen_var_val_tab(std::string var, double val) noexcept
	{
		return { gen_var_val_pair(var, get_val_as_vec(val)) };
	}
};

#endif // !_MATH_CALC_BASE_CALC_TOOLS_H_
