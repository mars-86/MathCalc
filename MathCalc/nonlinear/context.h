#ifndef _MATH_CALC_NONLINEAR_CONTEXT_H_
#define _MATH_CALC_NONLINEAR_CONTEXT_H_
#pragma once

#include <iostream>
#include "strategy.h"
#include "bisection.h"
#include "regula_falsi.h"

class Context {
private:
	Strategy* _strategy;
	std::string _function;

public:
	Context(const std::string& function, Strategy* strategy = nullptr)
		: _function(function), _strategy(strategy) {}
	~Context() { delete _strategy; }

	void set_strategy(Strategy* strategy)
	{
        	delete _strategy;
	        _strategy = strategy;
	}

	void apply(int xl, int xh) // open method
	{
		_strategy->apply(_function, xl, xh);
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
