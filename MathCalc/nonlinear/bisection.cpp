#include "bisection.h"

Bisection::Bisection(int it)
{
	set_iterations(it);
}

Bisection::~Bisection() {}

void Bisection::apply(std::string& equation, int xl, int xh)
{
	double xlt = (double)xl, xht = (double)xh, xr = get_xr(xlt, xht);
	for (int i = 0; i < iterations; ++i) {
		std::string s1 = std::to_string(xlt);
		std::vector<char*> fxls{ (char*)s1.c_str() };
		std::string s2 = std::to_string(xht);
		std::vector<char*> fxhs{ (char*)s2.c_str() };
		std::string s3 = std::to_string(xr);
		std::vector<char*> fxrs{ (char*)s3.c_str() };

		double fxl = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxls) });
		double fxh = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxhs) });
		double fxr = resolv_eq(equation, { base_calc.gen_var_val_pair("x", fxrs) });
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
		(fxr < 0) ? xht = xr : xlt = xr;
		xr = get_xr(xlt, xht);
	}
}

double Bisection::get_xr(double xl, double xh, double fxl, double fxh)
{
	return (xl + xh) / 2;
}