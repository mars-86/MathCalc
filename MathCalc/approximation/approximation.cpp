#include "approximation.h"
#include <iomanip>
// TODO -> check structure of strategy, the context must save equation and then passed to method
Approximation::Approximation(const ApproximationType& type)
	: _strategy(nullptr), _type(type)
{
	set_strategy(get_type());
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
		_strategy = new ApproximationMethods::Logarithmic();
		_cmethod = "logarithmic";
		break;
	case ApproximationType::Exponential:
		_strategy = new ApproximationMethods::Exponential();
		_cmethod = "exponential";
		break;
	case ApproximationType::Trigonometric:
		_strategy = new ApproximationMethods::Trigonometric();
		_cmethod = "trigonometric";
		break;
	default:
		;
	}
}

void Approximation::apply(double v1, double v2, int v3)
{
	std::cout << "Applying " << _cmethod << " method to " << _equation << std::endl;
	_strategy->apply(_equation, v1);	
}

std::vector<std::vector<std::string>> Approximation::get_grid_header() const
{
	return _strategy->get_grid_header();
}

std::vector<std::vector<double>> Approximation::get_grid() const
{
	return _strategy->get_gridd();
}

void Approximation::show_grid(void)
{
	_strategy->print_gridd();
}

double Approximation::get_result_d(void) const
{
	return _strategy->get_resultd();
}

std::string Approximation::get_result_s(void) const
{
	return _strategy->get_result();
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