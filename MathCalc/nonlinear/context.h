#ifndef _MATH_CALC_NONLINEAR_CONTEXT_H_
#define _MATH_CALC_NONLINEAR_CONTEXT_H_
#pragma once

#include <iostream>
#include "nonlinear_strategy.h"
#include "bisection.h"
#include "regula_falsi.h"
#include "newton_raphson.h"
#include "secant.h"

// TODO -> delete _function prop
class NonlinearContext {
private:
	NonlinearStrategy* _strategy;
	std::string _function;
public:
	NonlinearContext(NonlinearStrategy* strategy = nullptr)
		: _strategy(strategy) {}
	~NonlinearContext() { delete _strategy; }

	void set_strategy(NonlinearStrategy* strategy)
	{
        	delete _strategy;
	        _strategy = strategy;
	}

	void apply(std::string equation, int xl, int xh)
	{
		_strategy->apply(equation, xl, xh);
	}

	std::vector<std::vector<double>> get_grid(void) const
	{
		return _strategy->get_grid();
	}
	/*void apply(int x) // close method
	{
		//_strategy->apply(x);
	}*/
};

#endif // !_MATH_CALC_NONLINEAR_CONTEXT_H_
