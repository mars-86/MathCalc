#include "regula_falsi.h"

RegulaFalsi::RegulaFalsi(int it)
{
	set_iterations(it);
}

RegulaFalsi::~RegulaFalsi() {}

void RegulaFalsi::apply(std::string& equation, int xl, int xh)
{
	double xlt = (double)xl, xht = (double)xh;
	for (int i = 0; i < iterations; ++i) {
		double fxl = resolv_eq(equation, { base_calc.gen_var_val_pair("x", std::to_string(xlt).c_str()) });
		double fxh = resolv_eq(equation, { base_calc.gen_var_val_pair("x", std::to_string(xht).c_str()) });
		double xr = get_xr(xlt, xht, fxl, fxh);
		double fxr = resolv_eq(equation, { base_calc.gen_var_val_pair("x", std::to_string(xr).c_str()) });
		std::vector<double> row = {
			xlt, // xlo
			xht, // xhi
			fxl, // f(xlo)
			fxh, // f(xhi)
			xr,  // ((xh * fxl - xl * fxh) / (fxl - fxh))
			fxr, // f(xr)
			xht - xr // e (xhi - xr)
		};
		grid.push_back(row);
		xht = xr;
		xr = get_xr(xlt, xht, fxl, fxh);
	}
}

double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}