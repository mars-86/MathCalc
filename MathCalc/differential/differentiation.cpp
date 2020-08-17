#include "differentiation.h"

Differentiation::Differentiation(std::string h)
	: _h(h)
{
}

Differentiation::~Differentiation() {}

void Differentiation::apply(std::string& equation, double val)
{
	std::string eq_temp = equation;
	std::string sv = std::to_string(val);
	std::vector<char*> v = { (char*)"(", (char*)sv.c_str(), (char*)"+", (char*)_h.c_str(), (char*)")" };
	base_calc.replace_var(equation, 'x', v);
	std::vector<char*> v2 = { (char*)sv.c_str() };
	_result = std::to_string(resolv_eq("((" + equation + ")-(" + eq_temp + "))/" + _h, { base_calc.gen_var_val_pair("x", v2) }));
}

double Differentiation::get_xr(double xl, double xh, double fxl, double fxh) { return 0.0; }