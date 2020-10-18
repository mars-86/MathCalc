#include "logarithmic.h"
#include <cmath>
using namespace ApproximationMethods;

Logarithmic::Logarithmic(const LogType& log_type)
	: _log_type(log_type)
{
	grid_set_header({});
}

Logarithmic::~Logarithmic() {}

void Logarithmic::apply(std::string& equation, double x)
{
	const double m = 16;
	agm.set_x_y(1 ,pow(2, 2 - m) / x), agm.apply();
	set_result(( PI / ( 2.0 * std::stod( agm.get_result() ) ) - m * NLOG2 ));
}