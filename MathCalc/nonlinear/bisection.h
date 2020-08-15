#ifndef _MATH_CALC_BISECTION_H_
#define _MATH_CALC_BISECTION_H_
#pragma once

#include <iostream>
#include "strategy.h"

class Bisection : public Strategy {
public:
	Bisection(int it);
	~Bisection();

	void apply(std::string& equation, int xl, int xh) override;
	double get_xr(double xl, double xh, double fxl = 0, double fxh = 0) override;
};

#endif // !_MATH_CALC_BISECTION_H_
