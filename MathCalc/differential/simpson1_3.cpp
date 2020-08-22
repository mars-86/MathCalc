#include "simpson1_3.h"

Simpson1_3::Simpson1_3(int it)
{
	set_iterations(it);
}

Simpson1_3::~Simpson1_3() {}

void Simpson1_3::apply(std::string& equation, double a, double b, int n)
{
	double a_ = 0, h = (b - a) / n;
	std::vector<double> fa_acc;
	for (int i = 0; i <= n; ++i) {
		std::string sa_ = std::to_string(a_ = a + (h * i)); // a + (h * n)
		std::vector<char*> v = { (char*)sa_.c_str() };
		fa_acc.push_back(resolv_eq(equation, { base_calc.gen_var_val_pair("x", v) }));
		_grid.push_back({
			std::to_string(n),				// it
			sa_,							// a
			std::to_string(fa_acc.back())	// fa
		});
	}
	// 1/3 * h * (fa_begin + 4 * (SUM(fa_odd)) + 2 * (SUM(fa_even)) + fa_last)
	double sum_odd = 0, sum_even = 0;
	for (int i = 0; i < fa_acc.size(); ++i)
		(i % 2) == 0 ? sum_even += fa_acc[i] : sum_odd += fa_acc[i];

	_result = std::to_string(
		(1.0 / 3.0) * h * (fa_acc.front() + ( 4 * sum_odd ) + ( 2 * sum_even ) + fa_acc.back())
	);
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/