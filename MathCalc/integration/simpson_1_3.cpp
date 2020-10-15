#include "simpson_1_3.h"
using namespace IntegrationMethods;

Simpson1_3::Simpson1_3(int it)
{
	set_iterations(it);
	grid_set_header({ "| it", "| x", "| f(x)" });
}

Simpson1_3::~Simpson1_3() {}

void Simpson1_3::apply(std::string& equation, double a, double b)
{
	double a_ = 0, h = (b - a) / get_iterations();
	std::vector<double> fa_acc;
	for (int i = 0; i <= get_iterations(); ++i) {
		a_ = a + (h * i); // a + (h * n)
		fa_acc.push_back(resolv_eq(equation, _base_calc.gen_var_val_tab("x", a_) ));
		grid_insert_row({
			(double)i,		// it
			a_,				// a
			fa_acc.back()	// fa
		});
	}
	// 1/3 * h * (fa_begin + 4 * (SUM(fa_odd)) + 2 * (SUM(fa_even)) + fa_last)
	double sum_odd = 0, sum_even = 0;
	for (int i = 0; i < fa_acc.size(); ++i)
		(i % 2) == 0 ? sum_even += fa_acc[i] : sum_odd += fa_acc[i];

	set_result(
		(1.0 / 3.0) * h * (fa_acc.front() + ( 4 * sum_odd ) + ( 2 * sum_even ) + fa_acc.back())
	);
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/