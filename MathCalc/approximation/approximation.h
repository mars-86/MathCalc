#ifndef _MATH_CALC_APPROXIMATION_H_
#define _MATH_CALC_APPROXIMATION_H_
#pragma once

#include <iostream>
#include <string>
#include "approximation_strategy.h"
#include "logarithmic.h"
#include "exponential.h"
#include "trigonometric.h"

enum class ApproximationType {
	Logarithmic,
	Exponential,
	Trigonometric
};

class Approximation {
private:
	ApproximationStrategy* _strategy;

public:
	// Approximation(ApproximationStrategy* strategy = nullptr);
	Approximation(const ApproximationType& type);
	// Approximation(const std::string& equation, const ApproximationType& type, int iterations = 10);
	~Approximation();

	void set_strategy(const ApproximationType& type);
	void apply(double v1, double v2 = 0, int v3 = 0);
	void set_type(const ApproximationType& type);
	const ApproximationType get_type(void) const;
	void show_grid(void);
	void set_equation(const std::string& equation);
	std::vector<std::vector<std::string>> get_grid_header() const;
	std::vector<std::vector<double>> get_grid() const;
	double get_result_d(void) const;
	std::string get_result_s(void) const;

private:
	ApproximationType _type;
	std::string _equation;
	std::string _cmethod; // current method
};

#endif // !_MATH_CALC_APPROXIMATION_H_
