#ifndef _MATH_CALC_H_
#define _MATH_CALC_H_
#pragma once

#include "base_calc/base_calc.h"
#include "nonlinear/nonlinear.h"
#include "differential/differential.h"
#include "approximation/approximation.h"
#include "misc/misc.h"
#include <iomanip>

namespace MathCalc {

enum class NonLinear {
	BISECTION,
	REGULA_FALSI,
	NEWTHON_RAPHSON,
	SECANT
};

enum class Differential {
	FINITE_DIFFERENCES
};

enum class Integration {
	TRAPEZOIDAL,
	SIMPSON_1_3,
	SIMPDON_3_8,
	ROMBERG
};

enum class Approximation {
	LOGARITMIC,
	EXPONENTIAL,
	TRIGONOMETRIC
};

class MathCalc {
public:
	MathCalc();
	~MathCalc();

	void set_precision(int precision);
	void nonlinear();
	void derive();
	void integrate();
	void approximation();

private:
	std::string _equation;
	double _result;
};

}; // namespace MathCalc

#endif // !_MATH_CALC_H_