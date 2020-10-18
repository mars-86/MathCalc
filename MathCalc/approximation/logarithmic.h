#ifndef _MATH_CALC_LOGARITHMIC_H_
#define _MATH_CALC_LOGARITHMIC_H_
#pragma once

#include <iostream>
#include "approximation_strategy.h"
#include "../misc/arithmetic_geometric_mean.h"

namespace ApproximationMethods {

	enum class LogType {
		LogN
	};

	class Logarithmic : public ApproximationStrategy {
	public:
		Logarithmic(const LogType& log_type = LogType::LogN);
		~Logarithmic();

		void apply(std::string& equation, double x) override;

	private:
		LogType _log_type;
		ArithmeticGeometricMean agm;
	};

}

#endif // !_MATH_CALC_LOGARITHMIC_H_
