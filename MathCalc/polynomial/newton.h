#ifndef _MATH_CALC_NEWTON_POLYNOMIAL_H_
#define _MATH_CALC_NEWTON_POLYNOMIAL_H_
#pragma once

#include <iostream>
#include "polynomial_strategy.h"

namespace PolynomialMethods {

	class Newton : public PolynomialStrategy {
	public:
		Newton();
		~Newton();

		void apply(const PolynomialCommon::PointSet p) override;
	};

}

#endif // !_MATH_CALC_NEWTON_POLYNOMIAL_H_
