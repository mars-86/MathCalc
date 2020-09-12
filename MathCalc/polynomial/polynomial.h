#ifndef _MATH_CALC_POLYNOMIAL_H_
#define _MATH_CALC_POLYNOMIAL_H_
#pragma once

#include <iostream>
#include <string>
#include "polynomial_strategy.h"
#include "newton.h"

enum class PolynomialType {
	Newton
};

class Polynomial {
private:
	PolynomialStrategy* _strategy;

public:
	Polynomial(const PolynomialType& type = PolynomialType::Newton);
	~Polynomial();

	void set_strategy(const PolynomialType& type);
	void apply(void);
	void set_type(const PolynomialType& type);
	const PolynomialType get_type(void) const;
	void show_grid(void);
	void set_points(const PolynomialCommon::PointSet p);
	double get_result_d() const;
	std::string get_polynomial() const;
	const grid_d_t get_grid_d(void);
	const grid_s_t get_grid_s(void);
	std::vector<std::vector<std::string>> get_grid_header() const;
	std::vector<std::vector<double>> get_grid() const;
private:
	PolynomialType _type;
	PolynomialCommon::PointSet _points;
	std::string _cmethod; // current method
};

#endif // !_MATH_CALC_POLYNOMIAL_H_
