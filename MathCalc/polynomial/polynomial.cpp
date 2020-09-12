#include "polynomial.h"

// TODO -> check structure of strategy, the context must save equation and then passed to method
Polynomial::Polynomial(const PolynomialType& type)
	: _strategy(nullptr), _type(type)
{
	set_strategy(get_type());
}

Polynomial::~Polynomial()
{
	delete _strategy;
}

void Polynomial::set_strategy(const PolynomialType& type)
{
	delete _strategy;
	switch (type) {
	case PolynomialType::Newton:
		_strategy = new PolynomialMethods::Newton();
		_cmethod = "newton";
		break;
	default:
		;
	}
}

void Polynomial::apply(void)
{
	// std::cout << "Applying " << _cmethod << " method to " << _equation << std::endl;
	_strategy->apply(_points);
}

std::vector<std::vector<std::string>> Polynomial::get_grid_header() const
{
	return _strategy->get_grid_header();
}

std::vector<std::vector<double>> Polynomial::get_grid() const
{
	return _strategy->get_gridd();
}

void Polynomial::show_grid(void)
{
	_strategy->print_gridd();
}

void Polynomial::set_points(const PolynomialCommon::PointSet p)
{
	_points = p;
}

const grid_d_t Polynomial::get_grid_d(void)
{
	return _strategy->get_grid_d();
}

const grid_s_t Polynomial::get_grid_s(void)
{
	return _strategy->get_grid_s();
}

double Polynomial::get_result_d() const
{
	return _strategy->get_resultd();
}

std::string Polynomial::get_polynomial() const
{
	return _strategy->get_result();
}

void Polynomial::set_type(const PolynomialType& type)
{
	_type = type;
}

const PolynomialType Polynomial::get_type(void) const
{
	return _type;
}
