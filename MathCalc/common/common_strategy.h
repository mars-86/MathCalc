#ifndef _MATH_CALC_COMMON_STRATEGY_H_
#define _MATH_CALC_COMMON_STRATEGY_H_
#pragma once

#include <iostream> 
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"

class CommonStrategy {
public:
	virtual ~CommonStrategy() {};
	void grid_set_header(const std::vector<std::string>& header)
	{
		_grid.insert(_grid.begin(), header);
	}

	void grid_insert_row(std::vector<std::string> row)
	{
		_grid.push_back(row);
	}

	void grid_insert_row(std::vector<double> row)
	{
		_gridd.push_back(row);
	}
	
	std::vector<std::vector<std::string>> get_grid(void) const
	{
		return _grid;
	}

	std::vector<std::vector<double>> get_gridd(void) const
	{
		return _gridd;
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

	void set_iterations(int it)
	{
		_iterations = it;
	}
	
	int get_iterations(void) const
	{
		return _iterations;
	}

	void set_result(const std::string& result)
	{
		_result = result;
	}

	std::string get_result(void) const
	{
		return _result;
	}

	void set_result(double result)
	{
		_resultd = result;
	}

	double get_resultd(void) const
	{
		return _resultd;
	}

protected:
	BaseCalc _base_calc;
	int _iterations;
	std::vector<std::vector<std::string>> _grid; // grid holds iterations
	std::vector<std::vector<double>> _gridd;
	std::string _result;
	double _resultd;
};

#endif // !_MATH_CALC_COMMON_STRATEGY_H_
