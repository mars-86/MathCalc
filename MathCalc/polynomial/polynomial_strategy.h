#ifndef _MATH_CALC_POLYNOMIAL_STRATEGY_H_
#define _MATH_CALC_POLYNOMIAL_STRATEGY_H_
#pragma once

#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

namespace PolynomialCommon {
	typedef std::vector<std::pair<int, int>> PointSet;
};

class PolynomialStrategy : public CommonStrategy {
public:
	virtual ~PolynomialStrategy() {};
	virtual void apply(const PolynomialCommon::PointSet& p) = 0;

};

#endif // !_MATH_CALC_POLYNOMIAL_STRATEGY_H_
