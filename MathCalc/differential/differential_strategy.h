#ifndef _MATH_CALC_DIFFERENTIAL_STRATEGY_H_
#define _MATH_CALC_DIFFERENTIAL_STRATEGY_H_
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

class DifferentialStrategy : public CommonStrategy {
public:
	virtual ~DifferentialStrategy() {};
	virtual void apply(std::string& equation, double , double , int ) = 0;
};

#endif // !_MATH_CALC_DIFFERENTIAL_STRATEGY_H_
