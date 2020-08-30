#include "differentiation.h"

Differentiation::Differentiation(std::string h)
	: _h(h)
{
}

Differentiation::~Differentiation() {}

const std::string Differentiation::get_equation(std::string& equation, double val)
{
	std::string eq_temp = equation, sv = std::to_string(val);
	std::vector<char*> v = { (char*)"(", (char*)sv.c_str(), (char*)"+", (char*)_h.c_str(), (char*)")" };
	_base_calc.replace_var(equation, 'x', v);
	return "((" + equation + ")-(" + eq_temp + "))/" + _h;
}

void Differentiation::apply(std::string& equation, double val, double _, int __)
{
	set_result(
		std::to_string(resolv_eq(get_equation(equation, val), _base_calc.gen_var_val_tab("x", val) ))
	);
}

//double Differentiation::get_xr(double xl, double xh, double fxl, double fxh) { return 0.0; }