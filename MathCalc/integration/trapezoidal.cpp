#include "trapezoidal.h"
using namespace IntegrationMethods;

Trapezoidal::Trapezoidal(int n)
	: _n(n)
{
	if (_n < 1) _n = 1;
	set_iterations(n);
}

Trapezoidal::~Trapezoidal() {}

void Trapezoidal::apply(std::string& equation, double a, double b)
{
	double a_ = a, h = (b - a) / get_iterations();
	std::vector<double> fa_acc;
	fa_acc.push_back(resolv_eq(equation, _base_calc.gen_var_val_tab("x", a) ));
	for (int i = 1; i < get_iterations(); ++i) {
		fa_acc.push_back(resolv_eq(equation, _base_calc.gen_var_val_tab("x", a_ += h) ));
		grid_insert_row({
			std::to_string(i),						// it
			std::to_string(i / get_iterations()),	// a
			std::to_string(fa_acc.back())			// fa
		});
	}
	fa_acc.push_back(resolv_eq(equation, _base_calc.gen_var_val_tab("x", b)) ); // last
	//
	double sum = 0;
	for (int i = 1; i < fa_acc.size() - 1; ++i)
		sum += fa_acc[i];
	set_result( (h / 2.0) * (fa_acc.front() + 2 * sum + fa_acc.back()) );
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/