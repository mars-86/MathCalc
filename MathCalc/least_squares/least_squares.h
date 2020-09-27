#ifndef _MATH_CALC_LEAST_SQUARES_H_
#define _MATH_CALC_LEAST_SQUARES_H_
#pragma once

#include <iostream>
#include <string>
#include "least_squares_strategy.h"
#include "ls_approximation.h"

enum class LeastSquaresType {
	LSApproximation
};

class LeastSquares {
private:
	LeastSquaresStrategy* _strategy;

public:
	LeastSquares(const LeastSquaresType& type = LeastSquaresType::LSApproximation);
	~LeastSquares();

	void set_strategy(const LeastSquaresType& type);
	void apply(const LeastSquaresCommon::PointSet& p);
	void set_type(const LeastSquaresType& type);
	const LeastSquaresType get_type(void) const;
	void show_grid(void);

	double get_result_d() const;

	const grid_d_t get_grid_d(void);
	const grid_s_t get_grid_s(void);
	std::vector<std::vector<std::string>> get_grid_header() const;
	std::vector<std::vector<double>> get_grid() const;
private:
	LeastSquaresType _type;
	std::string _cmethod; // current method
};

#endif // !_MATH_CALC_LEAST_SQUARES_H_
