#ifndef _MATH_CALC_LEAST_SQUARES_STRATEGY_H_
#define _MATH_CALC_LEAST_SQUARES_STRATEGY_H_
#pragma once

#include "../base_calc/base_calc.h"
#include "../common/common_strategy.h"

namespace LeastSquaresCommon {
	typedef std::vector<std::pair<double, double>> PointSet;
};

class LeastSquaresStrategy : public CommonStrategy {
public:
	virtual ~LeastSquaresStrategy() {};
	virtual void apply(const LeastSquaresCommon::PointSet& p) = 0;

};

#endif // !_MATH_CALC_LEAST_SQUARES_STRATEGY_H_
