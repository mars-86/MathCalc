#include "arithmetic_geometric_mean.h"
#include <cmath>

ArithmeticGeometricMean::ArithmeticGeometricMean()
	: _x(0), _y(0)
{
}

ArithmeticGeometricMean::ArithmeticGeometricMean(double x, double y)
	: _x(x), _y(y)
{
	apply();
}

ArithmeticGeometricMean::~ArithmeticGeometricMean() {}

void ArithmeticGeometricMean::apply(void)
{
	int i = 0;
	double x = get_x(), y = get_y(), xt, yt;
	grid_insert_row({ std::to_string(i), std::to_string(x), std::to_string(y) });
	do {
		xt = (x + y) / 2;
		yt = sqrt(x * y);
		grid_insert_row({ std::to_string(++i), std::to_string(xt), std::to_string(yt) });
	} while (std::to_string(x = xt) != std::to_string(y = yt));
	_result = std::to_string(x);
}

void ArithmeticGeometricMean::set_x(double x)
{
	_x = x;
}

void ArithmeticGeometricMean::set_y(double y)
{
	_y = y;
}

double ArithmeticGeometricMean::get_x(void)
{
	return _x;
}

double ArithmeticGeometricMean::get_y(void)
{
	return _y;
}