#include "nonlinear.h"
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

Nonlinear::Nonlinear(NonlinearStrategy* strategy)
	: _strategy(strategy), _type(NonLinearType::Secant)
{
	set_strategy(get_type());
}

Nonlinear::~Nonlinear()
{
	delete _strategy;
}

void Nonlinear::set_strategy(const NonLinearType& type)
{
	delete _strategy;
	switch (type) {
	case NonLinearType::Bisection:
		_strategy = new NonLinear::Close::Bisection(10);
		break;
	case NonLinearType::RegulaFalsi:
		_strategy = new NonLinear::Close::RegulaFalsi(10);
		break;
	case NonLinearType::NewtonRaphson:
		_strategy = new NonLinear::Open::NewtonRaphson(10);
		break;
	case NonLinearType::Secant:
		_strategy = new NonLinear::Open::Secant(10);
		break;
	default:
		;
	}
}

void Nonlinear::apply(int xl, int xh)
{
	_strategy->apply(_equation, xl, xh);
}

std::vector<std::vector<double>> Nonlinear::get_grid() const
{
	return _strategy->get_gridd();
}

void Nonlinear::show_grid(void)
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

void Nonlinear::set_equation(const std::string& equation)
{
	_equation = equation;
}

void Nonlinear::set_type(const NonLinearType& type)
{
	_type = type;
}

const NonLinearType Nonlinear::get_type(void) const
{
	return _type;
}
