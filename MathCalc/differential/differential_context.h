#ifndef _MATH_CALC__CONTEXT_H_
#define _MATH_CALC__CONTEXT_H_
#pragma once

#include <iostream>
#include "differential_strategy.h"
#include "differentiation.h"
#include "simpson1_3.h"

// TODO -> delete _function prop
class DifferentialContext {
private:
	DifferentialStrategy* _strategy;
	std::string _function;

public:
	DifferentialContext(DifferentialStrategy* strategy = nullptr)
		: _strategy(strategy) {}
	~DifferentialContext() { delete _strategy; }

	void set_strategy(DifferentialStrategy* strategy)
	{
        	delete _strategy;
	        _strategy = strategy;
	}

	void apply(std::string equation, double v1, double v2, int v3)
	{
		_strategy->apply(equation, v1, v2, v3);
	}

	std::vector<std::vector<std::string>> get_grid(void) const
	{
		return _strategy->get_grid();
	}

	std::string get_result(void) const
	{
		return _strategy->get_result();
	}

	void apply(int x) // close method
	{
		//_strategy->apply(x);
	}
};

#endif // !_MATH_CALC_NONLINEAR_CONTEXT_H_
