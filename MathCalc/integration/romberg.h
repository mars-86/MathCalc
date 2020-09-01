#ifndef _MATH_CALC_ROMBERG_H_
#define _MATH_CALC_ROMBERG_H_
#pragma once

#include <iostream>
#include "integration_strategy.h"

namespace IntegrationMethods {

	class Romberg : public IntegrationStrategy {
	public:
		Romberg(int it);
		~Romberg();

		void apply(std::string& equation, double a, double b) override;
		//double get_xr(double xl, double xh, double fxl, double fxh) override;
	private:
		const int _n;
	};

}

#endif // !_MATH_CALC_ROMBERG_H_
