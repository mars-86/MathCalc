#ifndef _MATH_CALC_NONLINEAR_H_
#define _MATH_CALC_NONLINEAR_H_
#pragma once

#include <iostream>
#include <string>
#include "context.h"

class Nonlinear {
public:
	Nonlinear(const std::string& equation, const std::string& method = "bisection", int iterations = 10); // bisection by default
	~Nonlinear();

	void apply(int xl, int xh);
	void set_method(const std::string& method);
	const std::string& get_method(void) const;
	void show_grid(void);
	std::vector<std::vector<double>> get_grid() const;
private:
	NonlinearContext* _context;
	std::string _method;
	std::string _equation;
};

#endif // !_MATH_CALC_NONLINEAR_H_
