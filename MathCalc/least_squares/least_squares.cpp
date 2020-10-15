#include "least_squares.h"

// TODO -> check structure of strategy, the context must save equation and then passed to method
LeastSquares::LeastSquares(const LeastSquaresType& type)
	: _strategy(nullptr), _type(type)
{
	set_strategy(get_type());
}

LeastSquares::~LeastSquares()
{
	delete _strategy;
}

void LeastSquares::set_strategy(const LeastSquaresType& type)
{
	delete _strategy;
	switch (type) {
	case LeastSquaresType::LSApproximation:
		_strategy = new LeastSquaresMethods::LSApproximation();
		_cmethod = "ls_approximation";
		break;
	default:
		;
	}
}

void LeastSquares::apply(const LeastSquaresCommon::PointSet& p)
{
	std::cout << "Applying " << _cmethod << " method to point set ";
	for (auto i : p)
		std::cout << '(' << i.first << ',' << i.second << ')' << ',';
	std::cout << std::endl;
	_strategy->apply(p);
}

std::vector<std::vector<std::string>> LeastSquares::get_grid_header() const
{
	return _strategy->get_grid_header();
}

std::vector<std::vector<double>> LeastSquares::get_grid() const
{
	return _strategy->get_gridd();
}

void LeastSquares::show_grid(void)
{
	_strategy->print_gridd();
}

const grid_d_t LeastSquares::get_grid_d(void)
{
	return _strategy->get_grid_d();
}

const grid_s_t LeastSquares::get_grid_s(void)
{
	return _strategy->get_grid_s();
}

double LeastSquares::get_result_d() const
{
	return _strategy->get_resultd();
}

f2d_t LeastSquares::get_function(void) const
{
	return _strategy->gen_function(_strategy->get_slope_eq());
}

void LeastSquares::set_type(const LeastSquaresType& type)
{
	_type = type;
}

const LeastSquaresType LeastSquares::get_type(void) const
{
	return _type;
}
