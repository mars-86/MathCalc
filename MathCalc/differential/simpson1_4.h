#ifndef _MATH_CALC_SIMPSON_1_4_H_
#define _MATH_CALC_SIMPSON_1_4_H_
#pragma once

#include <iostream>
#include "differential_strategy.h"

class Simpson1_4 : public DifferentialStrategy {
public:
	Simpson1_4(int it);
	~Simpson1_4();

	void apply(std::string& equation, double val);
	//double get_xr(double xl, double xh, double fxl, double fxh) override;
};

#endif // !_MATH_CALC_SIMPSON_1_4_H_
