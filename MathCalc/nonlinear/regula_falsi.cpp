#include "regula_falsi.h"
using namespace NonLinear::Close;

RegulaFalsi::RegulaFalsi(int it)
{
	set_iterations(it);
	grid_set_header({ "| it", "| xlo", "| xhi", "| f(xlo)", "| f(xhi)", "| xr", "| f(xr)", "| E" });
}

RegulaFalsi::~RegulaFalsi() {}

void RegulaFalsi::apply(std::string& equation, int xl, int xh)
{
	double xlt = (double)xl, xht = (double)xh, xr = 0;
	for (int i = 1; i <= get_iterations(); ++i) {
		double fxl = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xlt));
		double fxh = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xht));
		xr = get_xr(xlt, xht, fxl, fxh);
		double fxr = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xr));
		grid_insert_row({
			(double)i,	// it
			xlt,		// xlo
			xht,		// xhi
			fxl,		// f(xlo)
			fxh,		// f(xhi)
			xr,			// ((xh * fxl - xl * fxh) / (fxl - fxh))
			fxr,		// f(xr)
			xht - xr	// e (xhi - xr)
		});
		xht = xr;
		xr = get_xr(xlt, xht, fxl, fxh);
		if (fxl * fxh >= 0) break;
	}
	set_result(xr);
}

double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}