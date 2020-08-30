#include "bisection.h"
using namespace NonLinear::Close;

Bisection::Bisection(int it)
{
	set_iterations(it);
	grid_set_header({ "| it", "| xlo", "| xhi", "| f(xlo)", "| f(xhi)", "| xr", "| f(xr)", "| E" });
}

Bisection::~Bisection() {}

void Bisection::apply(std::string& equation, int xl, int xh)
{
	double xlt = (double)xl, xht = (double)xh, xr = get_xr(xlt, xht);
	for (int i = 1; i <= get_iterations(); ++i) {
		double fxl = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xlt));
		double fxh = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xht));
		double fxr = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xr));
		grid_insert_row({
			(double)i,	// it
			xlt,		// xlo
			xht,		// xhi
			fxl,		// f(xlo)
			fxh,		// f(xhi)
			xr,			// (xlo + xhi) / 2
			fxr,		// f(xr)
			xht - xr	// e (xhi - xr)
		});
		(fxr < 0) ? xht = xr : xlt = xr;
		xr = get_xr(xlt, xht);
		if (fxl * fxh >= 0) break;
	}
	set_result(xr);
}

double Bisection::get_xr(double xl, double xh, double fxl, double fxh)
{
	return (xl + xh) / 2;
}