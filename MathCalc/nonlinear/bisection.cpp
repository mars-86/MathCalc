#include "bisection.h"
using namespace NonLinear::Close;

Bisection::Bisection(int it)
{
	set_iterations(it);
}

Bisection::~Bisection() {}

void Bisection::apply(std::string& equation, int xl, int xh)
{
	double xlt = (double)xl, xht = (double)xh, xr = get_xr(xlt, xht);
	for (int i = 0; i < get_iterations(); ++i) {
		double fxl = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xlt));
		double fxh = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xht));
		double fxr = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xr));
		std::vector<double> row = {
			xlt, // xlo
			xht, // xhi
			fxl, // f(xlo)
			fxh, // f(xhi)
			xr,  // (xlo + xhi) / 2
			fxr, // f(xr)
			xht - xr // e (xhi - xr)
		};
		grid_insert_row(row);
		(fxr < 0) ? xht = xr : xlt = xr;
		xr = get_xr(xlt, xht);
	}
}

double Bisection::get_xr(double xl, double xh, double fxl, double fxh)
{
	return (xl + xh) / 2;
}