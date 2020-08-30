#include "nonlinear.h"
#include <iomanip>

// TODO -> check structure of strategy, the context must save equation and then passed to method
inline void print_line(int columns)
{
	for (int i = 0; i < 16 * columns; ++i)
		std::cout << '-';
	std::cout << std::endl;
}

inline void print_head(const std::vector<std::vector<std::string>>& head)
{
	print_line(head[0].size());
	for (auto i : head)
		for (auto j : i)
			std::cout << std::left << std::setw(16) << j;
	std::cout << "|" << std::endl;
	print_line(head[0].size());
}

Nonlinear::Nonlinear(NonlinearStrategy* strategy)
	: _strategy(strategy), _type(NonLinearType::Secant)
{
	// set_strategy(get_type());
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

std::vector<std::vector<std::string>> Nonlinear::get_grid_header() const
{
	return _strategy->get_grid_header();
}

std::vector<std::vector<double>> Nonlinear::get_grid() const
{
	return _strategy->get_gridd();
}

void Nonlinear::show_grid(void)
{
	auto hd = get_grid_header();
	auto gd = get_grid();

	print_head(hd);
	for (auto i : gd) {
		for (int j = 0; j < i.size(); ++j)
			std::cout << "| " << std::left << std::setw(14) << i.at(j);
		std::cout << "|" << std::endl;
		print_line(hd[0].size());
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
