#ifndef _MATH_CALC_NONLINEAR_CONTEXT_H_
#define _MATH_CALC_NONLINEAR_CONTEXT_H_
#pragma once

#include <iostream>
#include "strategy.h"
#include "bisection.h"
#include "regula_falsi.h"

// TODO -> delete _function prop
class Context {
private:
	Strategy* _strategy;
	std::string _function;

public:
	Context(Strategy* strategy = nullptr)
		: _strategy(strategy) {}
	~Context() { delete _strategy; }

	void set_strategy(Strategy* strategy)
	{
        	delete _strategy;
	        _strategy = strategy;
	}

	void apply(std::string equation, int xl, int xh) // open method
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
