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
		std::string s1 = std::to_string(xlt);
		std::vector<char*> fxls{ (char*)s1.c_str() };
		std::string s2 = std::to_string(xht);
		std::vector<char*> fxhs{ (char*)s1.c_str() };
		double fxl = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxls) });
		double fxh = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxhs) });
		double xr = get_xr(xlt, xht, fxl, fxh);
		std::string s3 = std::to_string(xht);
		std::vector<char*> fxrs{ (char*)s1.c_str() };
		double fxr = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxrs) });
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