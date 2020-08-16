#include "regula_falsi.h"

RegulaFalsi::RegulaFalsi(int it)
{
	set_iterations(it);
}

RegulaFalsi::~RegulaFalsi() {}

void RegulaFalsi::apply(std::string& equation, double val)
{

}

double RegulaFalsi::get_xr(double xl, double xh, double fxl, double fxh)
{
	return ((xh * fxl - xl * fxh) / (fxl - fxh));
}