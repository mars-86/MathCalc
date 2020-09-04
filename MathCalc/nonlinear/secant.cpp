#include "secant.h"
using namespace NonLinear::Open;

Secant::Secant(int it)
{
	set_iterations(it);
	grid_set_header({ "| it", "| x0", "| x1", "| f(x0)", "| f(x1)", "| x2", "| E" });
}

Secant::~Secant()
{
}

void Secant::apply(std::string& equation, int x0, int x1)
{
	double x0t = (double)x0, x1t = (double)x1, x2 = 0;
	for (int i = 1; i <= get_iterations(); ++i) {
		double fx0 = resolv_eq(equation, _base_calc.gen_var_val_tab("x", x0t));
		double fx1 = resolv_eq(equation, _base_calc.gen_var_val_tab("x", x1t));
		x2 = get_xr(x0t, x1t, fx0, fx1);
		grid_insert_row({
			(double)i,	// it
			x0t,		// x0
			x1t,		// x1
			fx0,		// f(x0)
			fx1,		// f(x1)
			x2			// ((( x1 * fx0) - ( x0 * fx1 )) / ( fx0 - fx1 ))
			// e		// xht - xr // e (xhi - xr)
		});
		x0t = x1t;
		x1t = x2;
	}
	set_result(x2);
}

double Secant::get_xr(double x0, double x1, double fx0, double fx1)
{
	return ((( x1 * fx0) - ( x0 * fx1 )) / ( fx0 - fx1 ));
}