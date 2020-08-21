#ifndef _MATH_CALC_DIFFERENTIATION_H_
#define _MATH_CALC_DIFFERENTIATION_H_
#pragma once

#include <iostream>
#include "differential_strategy.h"

class Differentiation : public DifferentialStrategy {
public:
	Differentiation(std::string h = "0.001");
	~Differentiation();

	void apply(std::string& equation, double xh) override;
	//double get_xr(double xl, double xh, double fxl = 0, double fxh = 0) override;
private:
	std::string _h;
	const std::string get_equation(std::string& equation, double val);
};

#endif // !_MATH_CALC_DIFFERENTIATION_H_
