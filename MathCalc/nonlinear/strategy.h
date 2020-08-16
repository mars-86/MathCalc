#ifndef _MATH_CALC_NONLINEAR_STRATEGY_H_
#define _MATH_CALC_NONLINEAR_STRATEGY_H_
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"

class Strategy {
public:
	virtual ~Strategy() {};
	virtual void apply(std::string& equation, int xl, int xh) = 0;
	virtual double get_xr(double xl, double xh, double fxl, double fxh) = 0;

	std::vector<std::vector<double>> get_grid(void) const { return grid; }
	double resolv_eq(const std::string& eq, const std::map<std::string, std::vector<char*>> var_val)
	{
		std::string f = eq;
		base_calc.resolv(f, var_val), f.clear();
		return std::stod(base_calc.get_result());
	}
protected:
	BaseCalc base_calc;
	int iterations;
	std::vector<std::vector<double>> grid; // grid holds iterations
	int get_iterations(void) const { return iterations; }
	void set_iterations(int it) { iterations = it; }
};

#endif // !_MATH_CALC_NONLINEAR_STRATEGY_H_
