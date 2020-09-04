#include "romberg.h"
#include "trapezoidal.h"
using namespace IntegrationMethods;

Romberg::Romberg(int n)
	:_n(n)
{
	set_iterations(n);
}

Romberg::~Romberg() {}

void Romberg::apply(std::string& equation, double a, double b)
{
	std::vector<double> lvl_acc;
	for (int i = 0, j = 1; i < _n; i++, j *= 2) {
		// TODO: make Trapezoidal a fixed var when the method set_iterations can be used
		Trapezoidal trapezoidal(j);
		trapezoidal.apply(equation, a, b);
		lvl_acc.push_back(trapezoidal.get_resultd());
	}
	double lvl = 4;
	while (lvl_acc.size() > 1) {
		for (auto i = lvl_acc.begin(); i < lvl_acc.end() - 1; i++)
			*i = ( ( lvl / (lvl - 1) ) * ( *(i + 1) ) ) - ( ( 1 / (lvl - 1) ) * ( *i ) );
		lvl_acc.pop_back(); // pop_last
		lvl *= lvl; // pow
	}
	set_result(lvl_acc[0]);
}

/*
double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}
*/