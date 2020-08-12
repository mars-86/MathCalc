#include "nonlinear.h"

// TODO -> check structure of strategy, the context must save equation and then passed to method

Nonlinear::Nonlinear(const std::string& equation, const std::string& method, int iterations)
	: _equation(equation), _method(method)
{
	if (_method == "regula_falsi")
		_context = new Context(_equation, new RegulaFalsi(iterations));
	else
		_context = new Context(_equation, new Bisection(iterations));
}

Nonlinear::~Nonlinear()
{
	delete _context;
}

void Nonlinear::apply(int xl, int xh)
{
	if (_method == "")
		;
	else
		_context->apply(xl, xh);
}

std::vector<std::vector<double>> Nonlinear::get_grid() const
{
	return _context->get_grid();
}

void Nonlinear::show_grid(void)
{
	auto gd = get_grid();

	for (auto i : gd) {
		for (int j = 0; j < i.size(); ++j)
			std::cout << i.at(j) << ' ';
		std::cout << std::endl;
	}
}

void Nonlinear::set_method(const std::string& method)
{
	_method = method;
}

const std::string& Nonlinear::get_method(void) const
{
	return _method;
}