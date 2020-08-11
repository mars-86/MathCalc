#ifndef _MATH_CALC_BISECTION_H_
#define _MATH_CALC_BISECTION_H_
#pragma once

#include <iostream>
#include <vector>

class Bisection {
public:
	Bisection(int it);
	~Bisection();

	int get_iterations(void) const;
	void set_iterations(int it);
	void apply(int xl, int xh);
	std::vector<std::vector<double>> get_grid(void) const;
private:
	int iterations;
	std::vector<std::vector<double>> grid; // grid holds iterations
	
};

#endif // !_MATH_CALC_BISECTION_H_
