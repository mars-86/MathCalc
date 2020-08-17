#include "differential.h"
#include <iomanip>
// TODO -> check structure of strategy, the context must save equation and then passed to method
inline void print_line(void)
{
	for (int i = 0; i < 16 * 7; ++i)
		std::cout << '-';
	std::cout << std::endl;
}

inline void print_head(void)
{
	print_line();
	std::cout <<
		std::left << std::setw(16) << "| xlo" <<
		std::left << std::setw(16) << "| xhi" <<
		std::left << std::setw(16) << "| f(xlo)" <<
		std::left << std::setw(16) << "| f(xhi)" <<
		std::left << std::setw(16) << "| xr" <<
		std::left << std::setw(16) << "| f(xr)" <<
		std::left << std::setw(16) << "| E" <<
		"|" << std::endl;
	print_line();
}

Differential::Differential(const std::string& equation, const std::string& method, int iterations)
	: _equation(equation), _method(method)
{
	if (_method == "regula_falsi")
		_context = nullptr; // new Context(new RegulaFalsi(iterations));
	else
		_context = new Context(new Differentiation());
}

Differential::~Differential()
{
	delete _context;
}

void Differential::apply(double val)
{
	if (_method == "")
		;
	else
		_context->apply(_equation, val);
}

std::vector<std::vector<std::string>> Differential::get_grid() const
{
	return _context->get_grid();
}

std::string Differential::get_result(void) const
{
	return _context->get_result();
}

void Differential::show_grid(void)
{
	auto gd = get_grid();

	print_head();
	for (auto i : gd) {
		for (int j = 0; j < i.size(); ++j)
			std::cout << "| " << std::left << std::setw(14) << i.at(j);
		std::cout << "|" << std::endl;
		print_line();
	}
}

void Differential::set_method(const std::string& method)
{
	_method = method;
}

const std::string& Differential::get_method(void) const
{
	return _method;
}