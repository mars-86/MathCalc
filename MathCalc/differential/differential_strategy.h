#ifndef _MATH_CALC_DIFFERENTIAL_STRATEGY_H_
#define _MATH_CALC_DIFFERENTIAL_STRATEGY_H_
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"

class DifferentialStrategy {
public:
	virtual ~DifferentialStrategy() {};
	virtual void apply(std::string& equation, double , double , int ) = 0;
	
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
		base_calc.resolv(f, var_val), f.clear();
		return std::stod(base_calc.get_result());
	}

	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<char*>> var_val)
	{
		std::string f = eq;
		base_calc.resolv(f, var_val), f.clear();
		return std::stod(base_calc.get_result());
	}
protected:
	BaseCalc base_calc;
	int iterations;
	std::vector<std::vector<std::string>> _grid; // grid holds iterations
	std::string _result;
	int get_iterations(void) const
	{
		return iterations;
	}
	
	void set_iterations(int it)
	{
		iterations = it; 
	}
};

#endif // !_MATH_CALC_DIFFERENTIAL_STRATEGY_H_
