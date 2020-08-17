#ifndef _MATH_CALC_DIFFERENTIAL_H_
#define _MATH_CALC_DIFFERENTIAL_H_
#pragma once

#include <iostream>
#include <string>
#include "context.h"

class Differential {
public:
	Differential(const std::string& equation, const std::string& method = "bisection", int iterations = 10); // bisection by default
	~Differential();

	void apply(double val);
	void set_method(const std::string& method);
	const std::string& get_method(void) const;
	void show_grid(void);
	std::vector<std::vector<std::string>> get_grid() const;
	std::string get_result(void) const;
private:
	Context* _context;
	std::string _method;
	std::string _equation;
};

#endif // !_MATH_CALC_DIFFERENTIAL_H_
