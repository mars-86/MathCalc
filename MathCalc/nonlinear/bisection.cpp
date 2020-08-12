#include "bisection.h"

Bisection::Bisection(int it)
{
	set_iterations(it);
}

Bisection::~Bisection() {}

void Bisection::apply(std::string& equation, int xl, int xh)
{
	base_calc.resolv(equation.c_str());
	std::cout << "BISECTION RES: " << std::stod(base_calc.get_result()) << std::endl;
	return;
	//base_calc.replace_v();
	base_calc.resolv("-(5^2)+-5");
	std::cout << "BISECTION RES: " << std::stod(base_calc.get_result()) << std::endl;
	base_calc.resolv("2-1");
	std::cout << "BISECTION RES: " << std::stod(base_calc.get_result()) << std::endl;
	base_calc.resolv("3*8-10/2");
	std::cout << "BISECTION RES: " << std::stod(base_calc.get_result()) << std::endl;
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