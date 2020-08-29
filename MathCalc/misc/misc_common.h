#ifndef _MATH_CALC_MISC_COMMON_H_
#define _MATH_CALC_MISC_COMMON_H_
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"

class MiscCommon {
public:
	virtual ~MiscCommon() {};
	// virtual void apply(std::string& equation, double , double , int ) = 0;
	
	std::vector<std::vector<std::string>> get_grid(void) const
	{
		return _grid;
	}
	
	std::string get_result(void) const
	{
		return _result;
	}

	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<std::string>> var_val)
	{
		std::string f = eq;
		_base_calc.resolv(f, var_val), f.clear();
		return std::stod(_base_calc.get_result());
	}

	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<char*>> var_val)
	{
		std::string f = eq;
		_base_calc.resolv(f, var_val), f.clear();
		return std::stod(_base_calc.get_result());
	}

	int get_iterations(void) const
	{
		return _iterations;
	}

	void set_iterations(int it)
	{
		_iterations = it;
	}

	void grid_insert_row(const std::vector<std::string>& v)
	{
		_grid.insert(_grid.end(), v);
	}
protected:
	BaseCalc _base_calc;
	int _iterations;
	std::vector<std::vector<std::string>> _grid; // grid holds iterations
	std::string _result;
};

#endif // !_MATH_CALC_MISC_COMMON_H_
