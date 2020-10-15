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
	void set_slope_eq(const std::string& slope_eq) { _slope_eq = slope_eq; }
	std::string get_slope_eq(void) const { return _slope_eq; }
protected:
	std::string _slope_eq;
};

#endif // !_MATH_CALC_LEAST_SQUARES_STRATEGY_H_
