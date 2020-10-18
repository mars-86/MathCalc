#include "exponential.h"
using namespace ApproximationMethods;

Exponential::Exponential()
{
	grid_set_header({ "| it", "| y" });
}

Exponential::~Exponential() {}

void Exponential::apply(std::string& equation, double x)
{
	// 1 + x + (x^2 / 2!) + (x^3 / 3!) + ...
	long double sum = 0;
	auto factarr = _base_calc.factorial_array(_it);
	for (int i = 0; i < _it; ++i) {
		sum += (pow(x, i) / factarr[i]);
		grid_insert_row({(double)i, (double)sum});
	}
	set_result(sum);
}