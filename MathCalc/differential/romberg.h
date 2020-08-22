#ifndef _MATH_CALC_ROMBERG_H_
#define _MATH_CALC_ROMBERG_H_
#pragma once

#include <iostream>
#include "differential_strategy.h"

class Romberg : public DifferentialStrategy {
public:
	Romberg(int it);
	~Romberg();

	void apply(std::string& equation, double a, double b, int = 0) override;
	//double get_xr(double xl, double xh, double fxl, double fxh) override;
private:
	const int _n = 3;
};

#endif // !_MATH_CALC_ROMBERG_H_
