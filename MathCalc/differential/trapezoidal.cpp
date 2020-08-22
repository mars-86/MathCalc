#include "trapezoidal.h"

Trapezoidal::Trapezoidal(int n)
	: _n(n)
{
	if (_n < 1) _n = 1;
	set_iterations(n);
}

Trapezoidal::~Trapezoidal() {}

const std::vector<std::string> get_val_as_vec(double val)
{
	return { std::to_string(val) };
}

void Trapezoidal::apply(std::string& equation, double a, double b, int n)
{
	double a_ = a, h = (b - a) / _n;
	std::vector<double> fa_acc;
	fa_acc.push_back(resolv_eq(equation, { base_calc.gen_var_val_pair("x", get_val_as_vec(a)) }));
	for (int i = 1; i < _n; ++i) {
		fa_acc.push_back(resolv_eq(equation, { base_calc.gen_var_val_pair("x", get_val_as_vec(a_ += h)) }));
		_grid.push_back({
			std::to_string(_n),				// it
			std::to_string(i / _n),			// a
			std::to_string(fa_acc.back())	// fa
		});
		//std::cout << i / _n << std::endl;
	}
	fa_acc.push_back(resolv_eq(equation, { base_calc.gen_var_val_pair("x", get_val_as_vec(b)) })); // last
	// 
	double sum = 0;
	for (int i = 1; i < fa_acc.size() - 1; ++i)
		sum += fa_acc[i];
	_result = std::to_string(
		(h / 2.0) * (fa_acc.front() + 2 * sum + fa_acc.back())
	);
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/