#ifndef _MATH_CALC_APPROXIMATION_STRATEGY_H_
#define _MATH_CALC_APPROXIMATION_STRATEGY_H_
#pragma once

#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

class ApproximationStrategy : public CommonStrategy {
public:
	virtual ~ApproximationStrategy() {};
	virtual void apply(std::string& equation, double x) = 0;
};

#endif // !_MATH_CALC_APPROXIMATION_STRATEGY_H_
