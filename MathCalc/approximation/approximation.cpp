#include "approximation.h"
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

Approximation::Approximation(ApproximationStrategy* strategy)
	:_strategy(strategy), _type(ApproximationType::Logarithmic)
{
}

Approximation::~Approximation()
{
	delete _strategy;
}

void Approximation::set_strategy(const ApproximationType& type)
{
	delete _strategy;
	switch (type) {
	case ApproximationType::Logarithmic:
		_strategy = new Logarithmic();
		break;
	case ApproximationType::Exponential:
		_strategy = new Exponential();
		break;
	case ApproximationType::Trigonometric:
		_strategy = new Trigonometric();
		break;
	default:
		;
	}
}

void Approximation::apply(double v1, double v2, int v3)
{
	_strategy->apply(_equation, v1);	
}

std::vector<std::vector<double>> Approximation::get_grid() const
{
	return  _strategy->get_gridd();
}

double Approximation::get_result(void) const
{
	return  _strategy->get_resultd();
}

std::string Approximation::get_result_as_string(void) const
{
	return  _strategy->get_result();
}

void Approximation::show_grid(void)
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

void Approximation::set_equation(const std::string& equation)
{
	_equation = equation;
}

void Approximation::set_type(const ApproximationType& type)
{
	_type = type;
}

const ApproximationType Approximation::get_type(void) const
{
	return _type;
}