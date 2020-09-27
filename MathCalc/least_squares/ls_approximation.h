#ifndef _MATH_CALC_LS_APPROXIMATION_H_
#define _MATH_CALC_LS_APPROXIMATION_H_
#pragma once

#include <iostream>
#include "least_squares_strategy.h"

namespace LeastSquaresMethods {

	class LSApproximation : public LeastSquaresStrategy {
	public:
		LSApproximation();
		~LSApproximation();

		void apply(const LeastSquaresCommon::PointSet& p) override;
	};

}

#endif // !_MATH_CALC_LS_APPROXIMATION_H_
