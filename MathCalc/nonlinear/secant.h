#ifndef _MATH_CALC_SECANT_H_
#define _MATH_CALC_SECANT_H_
#pragma once

#include <iostream>
#include "nonlinear_strategy.h"

class Secant : public NonlinearStrategy {
public:
	Secant(int it);
	~Secant();

	void apply(std::string& equation, int xl, int xh) override;
	double get_xr(double xl, double xh, double fxl, double fxh) override;
};

#endif // !_MATH_CALC_SECANT_H_
