#include "roots_range.h"
using namespace NonLinear;

RootRange::RootRange(const std::string& equation)
	:_equation(equation)
{
	find_ranges();
}

RootRange::~RootRange()
{
}

const std::vector<std::pair<int, int>>& RootRange::get_ranges() const
{
	return _ranges;
}

void RootRange::find_ranges(void)
{

	double p_val = 0, c_val = 0;
	_base_calc.resolv(_equation, _base_calc.gen_var_val_tab("x", -100));
	p_val = c_val = std::stod(_base_calc.get_result());
	for (int i = -100 + 1; i < 100; ++i) {
		std::cout << c_val << std::endl;
		_base_calc.resolv(_equation, _base_calc.gen_var_val_tab("x", i));
		c_val = std::stod(_base_calc.get_result());
		if (p_val < 0 && c_val >= 0 || c_val < 0 && p_val >= 0)
			_ranges.push_back({ p_val, c_val });
		p_val = c_val;
	}
}
