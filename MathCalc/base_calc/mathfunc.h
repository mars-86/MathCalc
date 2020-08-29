#ifndef _MATH_CALC_MATH_FUNC_H
#define _MATH_CALC_MATH_FUNC_H
#pragma once

#include <map>
#include <string>
/*
inline long double factorial(double x)
{
	long double x_ = x;
	if (x == 0) return 1;
	for (int i = x - 1; i > 0; --i) x_ *= i;
	return x_;
}

std::map<std::string, long double (*)(double)> _funcs = {
	{"fact", factorial }

};
*/
const char* _functions[] = {
	"cos",
	"cosec",
	"cotg",
	"exp",
	"fact",
	"mod",
	"log",
	"ln",
	"sec",
	"sin",
	"sinh",
	"sqrt",
	"tan",
	"tanh",
	"tg",
	"tgn"
};

#endif // _MATH_CALC_MATH_FUNC_H