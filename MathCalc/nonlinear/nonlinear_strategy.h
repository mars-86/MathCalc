#ifndef _MATH_CALC_NONLINEAR_STRATEGY_H_
#define _MATH_CALC_NONLINEAR_STRATEGY_H_
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

class NonlinearStrategy : public CommonStrategy {
public:
	virtual ~NonlinearStrategy() {};
	virtual void apply(std::string& equation, int xl, int xh) = 0;
	virtual double get_xr(double xl, double xh, double fxl, double fxh) = 0;
};

#endif // !_MATH_CALC_NONLINEAR_STRATEGY_H_
