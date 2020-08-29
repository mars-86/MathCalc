#ifndef _MATH_CALC_ARITHMETIC_GEOMETRIC_MEAN_H_
#define _MATH_CALC_ARITHMETIC_GEOMETRIC_MEAN_H_
#pragma once

#include <iostream>
#include "misc_common.h"

class ArithmeticGeometricMean : public MiscCommon {
public:
	ArithmeticGeometricMean();
	ArithmeticGeometricMean(double x, double y);
	~ArithmeticGeometricMean();

	void apply(void);
	void set_x_y(double x, double y);
	void set_x(double x);
	void set_y(double y);
	double get_x(void);
	double get_y(void);	
private:
	double _x, _y;
};

#endif // !_MATH_CALC_ARITMETIC_GEOMETRIC_MEAN_H_
