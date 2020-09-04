#include "newton_raphson.h"
using namespace NonLinear::Open;

NewtonRaphson::NewtonRaphson(int it)
	: _differential(nullptr)
{
	set_iterations(it);
	grid_set_header({ "| it", "| x", "| f(x)", "| f'(x)", "| E" });
	_differential = new Differential();
}

NewtonRaphson::~NewtonRaphson()
{
	delete _differential;
}

void NewtonRaphson::apply(std::string& equation, int x, int xh)
{
	_differential->set_equation(equation);
	double xt = (double)x;
	for (int i = 1; i <= get_iterations(); ++i) {
		double fx = resolv_eq(equation, _base_calc.gen_var_val_tab("x", xt));
		_differential->apply(xt);
		double fx_d = std::stod(_differential->get_result());
		double xr = get_xr(xt, fx, fx_d);
		grid_insert_row({
			(double)i,	// it
			xt,			// x
			fx,			// f(x)
			fx_d,		// f'(x)
			// xr		// (x - (f(x) / f'(x)))
			// e		// xht - xr // e (xhi - xr)
		});
		xt = xr;
	}
	set_result(xt);
}

double NewtonRaphson::get_xr(double x, double fx, double fx_d, double _)
{
	return (x - ( fx / fx_d));
}