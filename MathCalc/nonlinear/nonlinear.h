#ifndef _MATH_CALC_NONLINEAR_H_
#define _MATH_CALC_NONLINEAR_H_
#pragma once

#include <iostream>
#include <string>
#include "nonlinear_strategy.h"
#include "bisection.h"
#include "regula_falsi.h"
#include "newton_raphson.h"
#include "secant.h"

enum class NonLinearType {
	Bisection,
	RegulaFalsi,
	NewtonRaphson,
	Secant
};

class Nonlinear {
private:
	NonlinearStrategy* _strategy;

public:
	Nonlinear(NonlinearStrategy* strategy = nullptr);
	~Nonlinear();

	void set_strategy(const NonLinearType& type, int it = 10);
	void apply(int xl, int xh);
	void set_type(const NonLinearType& type);
	const NonLinearType get_type(void) const;
	void show_grid(void);
	const f2d_t set_equation(const std::string& equation);
	double get_result_d() const;
	std::string get_result_s() const;
	std::vector<std::vector<std::string>> get_grid_header() const;
	std::vector<std::vector<double>> get_grid() const;

private:
	NonLinearType _type;
	std::string _equation;
	std::string _cmethod; // current method
};

#endif // !_MATH_CALC_NONLINEAR_H_
