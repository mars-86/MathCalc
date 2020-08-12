#include "regula_falsi.h"

RegulaFalsi::RegulaFalsi(int it)
{
	set_iterations(it);
}

RegulaFalsi::~RegulaFalsi() {}

void RegulaFalsi::apply(std::string& equation, int xl, int xh)
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