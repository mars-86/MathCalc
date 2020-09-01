#include "nonlinear.h"
#include <iomanip>

// TODO -> check structure of strategy, the context must save equation and then passed to method
Nonlinear::Nonlinear(NonlinearStrategy* strategy)
	: _strategy(strategy), _type(NonLinearType::Secant)
{
	set_strategy(get_type());
}

Nonlinear::~Nonlinear()
{
	delete _strategy;
}

void Nonlinear::set_strategy(const NonLinearType& type, int it)
{
	delete _strategy;
	switch (type) {
	case NonLinearType::Bisection:
		_strategy = new NonLinear::Close::Bisection(it);
		_cmethod = "bisection";
		break;
	case NonLinearType::RegulaFalsi:
		_strategy = new NonLinear::Close::RegulaFalsi(it);
		_cmethod = "regula falsi";
		break;
	case NonLinearType::NewtonRaphson:
		_strategy = new NonLinear::Open::NewtonRaphson(it);
		_cmethod = "newton raphson";
		break;
	case NonLinearType::Secant:
		_strategy = new NonLinear::Open::Secant(it);
		_cmethod = "secant";
		break;
	default:
		;
	}
}

void Nonlinear::apply(int xl, int xh)
{
	std::cout << "Applying " << _cmethod << " method to " << _equation << std::endl;
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
	_strategy->print_gridd();
}

void Nonlinear::set_equation(const std::string& equation)
{
	_equation = equation;
}

double Nonlinear::get_result_d() const
{
	return _strategy->get_resultd();
}

std::string Nonlinear::get_result_s() const
{
	return _strategy->get_result();
}

void Nonlinear::set_type(const NonLinearType& type)
{
	_type = type;
}

const NonLinearType Nonlinear::get_type(void) const
{
	return _type;
}
