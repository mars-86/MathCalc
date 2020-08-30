#include "secant.h"
using namespace NonLinear::Open;

Secant::Secant(int it)
{
	set_iterations(it);
}

Secant::~Secant()
{
}

void Secant::apply(std::string& equation, int x0, int x1)
{
	double x0t = (double)x0, x1t = (double) x1;
	for (int i = 0; i < get_iterations(); ++i) {
		double fx0 = resolv_eq(equation, _base_calc.gen_var_val_tab("x", x0t));
		double fx1 = resolv_eq(equation, _base_calc.gen_var_val_tab("x", x1t));
		double x2 = get_xr(x0t, x1t, fx0, fx1);
		std::vector<double> row = {
			x0t, // x0
			x1t, // x1
			fx0, // f(x0)
			fx1, // f(x1)
			x2  // ((( x1 * fx0) - ( x0 * fx1 )) / ( fx0 - fx1 ))
			// e // xht - xr // e (xhi - xr)
		};
		grid_insert_row(row);
		x0t = x1t;
		x1t = x2;
	}
}

double Secant::get_xr(double x0, double x1, double fx0, double fx1)
{
	return ((( x1 * fx0) - ( x0 * fx1 )) / ( fx0 - fx1 ));
}