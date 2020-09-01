#ifndef _MATH_CALC_SIMPSON_3_8_H_
#define _MATH_CALC_SIMPSON_3_8_H_
#pragma once

#include <iostream>
#include "integration_strategy.h"

namespace IntegrationMethods {

	class Simpson3_8 : public IntegrationStrategy {
	public:
		Simpson3_8(int it);
		~Simpson3_8();

		void apply(std::string& equation, double a, double b) override;
		//double get_xr(double xl, double xh, double fxl, double fxh) override;
	private:
		const int _n = 3;
	};

}

#endif // !_MATH_CALC_SIMPSON_3_8_H_
