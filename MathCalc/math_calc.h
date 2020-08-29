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

class MathCalc {
public:
	MathCalc();
	~MathCalc();


	void derive();
	void integrate();
};

}; // namespace MathCalc

#endif // !_MATH_CALC_H_