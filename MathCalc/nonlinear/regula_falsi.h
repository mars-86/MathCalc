#ifndef _MATH_CALC_REGULA_FALSI_H_
#define _MATH_CALC_REGULA_FALSI_H_
#pragma once

#include <iostream>
#include "nonlinear_strategy.h"

class RegulaFalsi : public NonlinearStrategy {
public:
	RegulaFalsi(int it);
	~RegulaFalsi();

	void apply(std::string& equation, int xl, int xh) override;
	double get_xr(double xl, double xh, double fxl, double fxh) override;
};

#endif // !_MATH_CALC_REGULA_FALSI_H_
