#include "bisection.h"

Bisection::Bisection(int it)
{
	set_iterations(it);
}

Bisection::~Bisection() {}

void Bisection::apply(int xl, int xh)
{
	for (int i = 0; i < iterations; ++i) {
		double xlt = (double)xl, xht = (double)xh, xr = (xlt + xht) / 2, fxl = 0, fxh = 0, fxr = 0;
		std::vector<double> row = {
			xlt, // xlo
			xht, // xhi
			fxl, // f(xlo)
			fxh, // f(xhi)
			xr,  // (xlo + xhi) / 2
			fxr, // f(xr)
			xht - xr // e (xhi - xr)
		};
		grid.push_back(row);
	}
}

int Bisection::get_iterations(void) const
{
	return iterations;
}

void Bisection::set_iterations(int it)
{
	iterations = it;
}

std::vector<std::vector<double>> Bisection::get_grid(void) const
{
	return grid;
}