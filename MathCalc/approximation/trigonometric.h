#ifndef _MATH_CALC_TRIGONOMETRIC_H_
#define _MATH_CALC_TRIGONOMETRIC_H_
#pragma once

#include <iostream>
#include "approximation_strategy.h"
#include "../misc/arithmetic_geometric_mean.h"

enum class TrgType {
	Sin,
	Cos
};

class Trigonometric : public ApproximationStrategy {
public:
	Trigonometric();
	~Trigonometric();

	void apply(std::string& equation, double x) override;

private:
	TrgType _trg_type;
	const int _it = 10;
};

#endif // !_MATH_CALC_TRIGONOMETRIC_H_
