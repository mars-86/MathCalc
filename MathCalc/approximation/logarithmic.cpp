#include "logarithmic.h"
#include <cmath>

Logarithmic::Logarithmic()
{
}

Logarithmic::~Logarithmic() {}

void Logarithmic::apply(std::string& equation, double x)
{
	const double ln_2 = 0.69314718056, m = 16;
	agm.set_x_y(1 ,pow(2, 2 - m) / x), agm.apply();
	set_result(std::to_string(
		( 3.141592653589793 / ( 2.0 * std::stod( agm.get_result() ) ) - m * ln_2 )
	));
}