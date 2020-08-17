#ifndef _MATH_CALC_NONLINEAR_CONTEXT_H_
#define _MATH_CALC_NONLINEAR_CONTEXT_H_
#pragma once

#include <iostream>
#include "strategy.h"
#include "differentiation.h"
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

	void apply(std::string equation, double val)
	{
		_strategy->apply(equation, val);
	}

	std::vector<std::vector<std::string>> get_grid(void) const
	{
		return _strategy->get_grid();
	}

	std::string get_result(void) const
	{
		return _strategy->get_result();
	}

	/*void apply(int x) // close method
	{
		//_strategy->apply(x);
	}*/
};

#endif // !_MATH_CALC_NONLINEAR_CONTEXT_H_
