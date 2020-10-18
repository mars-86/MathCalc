#ifndef _MATH_CALC_EXPONENTIAL_H_
#define _MATH_CALC_EXPONENTIAL_H_
#pragma once

#include <iostream>
#include "approximation_strategy.h"
#include "../misc/arithmetic_geometric_mean.h"

namespace ApproximationMethods {

	class Exponential : public ApproximationStrategy {
	public:
		Exponential();
		~Exponential();

		void apply(std::string& equation, double x) override;

	private:
		const int _it = 21;
	};

}

#endif // !_MATH_CALC_EXPONENTIAL_H_
