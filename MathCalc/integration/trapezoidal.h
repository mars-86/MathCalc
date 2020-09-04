#ifndef _MATH_CALC_TRAPEZOIDAL_H_
#define _MATH_CALC_TRAPEZOIDAL_H_
#pragma once

#include <iostream>
#include "integration_strategy.h"

namespace IntegrationMethods {

	class Trapezoidal : public IntegrationStrategy {
	public:
		Trapezoidal(int n);
		~Trapezoidal();

		void apply(std::string& equation, double a, double b) override;
		//double get_xr(double xl, double xh, double fxl, double fxh) override;
	private:
		int _n;
	};

}

#endif // !_MATH_CALC_TRAPEZOIDAL_H_
