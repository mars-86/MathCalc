#ifndef _MATH_CALC_NEWTON_RAPHSON_H_
#define _MATH_CALC_NEWTON_RAPHSON_H_
#pragma once

#include <iostream>
#include "nonlinear_strategy.h"
#include "../differential/differential.h"

class NewtonRaphson : public NonlinearStrategy {
public:
	NewtonRaphson(int it);
	~NewtonRaphson();

	void apply(std::string& equation, int xl, int xh) override;
	double get_xr(double x, double fx, double fx_d, double = 0) override;
private:
	Differential *_differential;
};

#endif // !_MATH_CALC_NEWTON_RAPHSON_H_
