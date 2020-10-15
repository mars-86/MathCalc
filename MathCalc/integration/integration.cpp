#include "integration.h"

// TODO -> check structure of strategy, the context must save equation and then passed to method
Integration::Integration(const IntegrationType& type)
	: _strategy(nullptr), _type(type)
{
	set_strategy(get_type());
}

Integration::Integration(const IntegrationType& type, int it)
	: _strategy(nullptr), _type(type)
{
	set_strategy(get_type(), it);
}

Integration::~Integration()
{
	delete _strategy;
}

void Integration::set_strategy(const IntegrationType& type, int it)
{
	delete _strategy;
	switch (type) {
	case IntegrationType::Trapezoidal:
		_strategy = new IntegrationMethods::Trapezoidal(it);
		_cmethod = "trapezoidal";
		break;
	case IntegrationType::Simpson_1_3:
		_strategy = new IntegrationMethods::Simpson1_3(it);
		_cmethod = "simpson 1/3";
		break;
	case IntegrationType::Simpson_3_8:
		_strategy = new IntegrationMethods::Simpson3_8(it);
		_cmethod = "simpson 3/8";
		break;
	case IntegrationType::Romberg:
		_strategy = new IntegrationMethods::Romberg(it);
		_cmethod = "romberg";
		break;
	default:
		;
	}
}

void Integration::apply(int a, int b)
{
	std::cout << "Applying " << _cmethod << " method to " << _equation << std::endl;
	_strategy->apply(_equation, a, b);
}

std::vector<std::vector<std::string>> Integration::get_grid_header() const
{
	return _strategy->get_grid_header();
}

std::vector<std::vector<double>> Integration::get_grid() const
{
	return _strategy->get_gridd();
}

void Integration::show_grid(void)
{
	_strategy->print_gridd();
}

/*void Integration::set_equation(const std::string& equation)
{
	_equation = equation;
}*/

const f2d_t Integration::set_equation(const std::string& equation)
{
	_equation = equation;
	return _strategy->gen_function(_equation);
}

const grid_d_t Integration::get_grid_d(void)
{
	return _strategy->get_grid_d();
}

const grid_s_t Integration::get_grid_s(void)
{
	return _strategy->get_grid_s();
}

double Integration::get_result_d() const
{
	return _strategy->get_resultd();
}

std::string Integration::get_result_s() const
{
	return _strategy->get_result();
}

void Integration::set_type(const IntegrationType& type)
{
	_type = type;
}

const IntegrationType Integration::get_type(void) const
{
	return _type;
}
