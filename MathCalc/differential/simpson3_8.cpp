#include "simpson3_8.h"

Simpson3_8::Simpson3_8(int it)
{
	set_iterations(it);
}

Simpson3_8::~Simpson3_8() {}

void Simpson3_8::apply(std::string& equation, double a, double b, int _)
{
	double a_ = 0, h = (b - a) / _n;
	std::vector<double> fa_acc;
	for (int i = 0; i <= _n; ++i) {
		a_ = a + (h * i); // a + (h * n)
		fa_acc.push_back(resolv_eq(equation, _base_calc.gen_var_val_tab("x", a_) ));
		_grid.push_back({
			std::to_string(_n),				// it
			std::to_string(a_),							// a
			std::to_string(fa_acc.back())	// fa
		});
	}
	// 3/8 * h * (fa_i0 + 3 * fa_i1 + 3 * fa_i2 + fa_i3)
	_result = std::to_string(
		(3.0 / 8.0) * h * (fa_acc[0] + 3 * fa_acc[1] + 3 * fa_acc[2] + fa_acc[3])
	);
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/