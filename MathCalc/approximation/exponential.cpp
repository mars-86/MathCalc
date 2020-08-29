#include "exponential.h"

Exponential::Exponential()
{
}

Exponential::~Exponential() {}

void Exponential::apply(std::string& equation, double x)
{
	// 1 + x + (x^2 / 2!) + (x^3 / 3!) + ...
	long double sum = 0;
	for (int i = 0; i < _it; ++i) {

		sum += (pow(x, i) / _base_calc.factorial(i));
		grid_insert_row({(double)i, (double)sum});
	}
	set_result(sum);
}