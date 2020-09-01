#ifndef _MATH_CALC_SIMPSON_1_3_H_
#define _MATH_CALC_SIMPSON_1_3_H_
#pragma once

#include <iostream>
#include "integration_strategy.h"

namespace IntegrationMethods {

	class Simpson1_3 : public IntegrationStrategy {
	public:
		Simpson1_3(int it);
		~Simpson1_3();

		void apply(std::string& equation, double a, double b) override;
		//double get_xr(double xl, double xh, double fxl, double fxh) override;
	};

}

#endif // !_MATH_CALC_SIMPSON_1_4_H_