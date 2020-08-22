#ifndef _MATH_CALC_TRAPEZOIDAL_H_
#define _MATH_CALC_TRAPEZOIDAL_H_
#pragma once

#include <iostream>
#include "differential_strategy.h"

class Trapezoidal : public DifferentialStrategy {
public:
	Trapezoidal(int n);
	~Trapezoidal();

	void apply(std::string& equation, double a, double b, int = 0) override;
	//double get_xr(double xl, double xh, double fxl, double fxh) override;
private:
	int _n;
};

#endif // !_MATH_CALC_TRAPEZOIDAL_H_
