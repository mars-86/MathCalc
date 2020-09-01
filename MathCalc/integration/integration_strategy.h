#ifndef _MATH_CALC_INTEGRATION_STRATEGY_H_
#define _MATH_CALC_INTEGRATION_STRATEGY_H_
#pragma once

#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

class IntegrationStrategy : public CommonStrategy {
public:
	virtual ~IntegrationStrategy() {};
	virtual void apply(std::string& equation, double a, double b) = 0;
};

#endif // !_MATH_CALC_INTEGRATION_STRATEGY_H_
