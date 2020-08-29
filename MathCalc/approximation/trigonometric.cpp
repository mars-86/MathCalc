#include "trigonometric.h"

Trigonometric::Trigonometric()
{
}

Trigonometric::~Trigonometric() {}

void Trigonometric::apply(std::string& equation, double x)
{
	double sum = 0;
	//std::cout << _base_calc.factorial(20) << std::endl;
	for (int i = 0; i < _it; ++i) {
		int h = (2 * i) + 1;
		sum += (pow(-1, i) / _base_calc.factorial(h)) * pow(x, h);
		grid_insert_row({(double)i, sum});
	}
	set_result(sum);
}