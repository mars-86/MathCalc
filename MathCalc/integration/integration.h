#ifndef _MATH_CALC_INTEGRATION_H_
#define _MATH_CALC_INTEGRATION_H_
#pragma once

#include <iostream>
#include <string>
#include "integration_strategy.h"
#include "trapezoidal.h"
#include "simpson_1_3.h"
#include "simpson_3_8.h"
#include "romberg.h"

enum class IntegrationType {
	Trapezoidal,
	Simpson_1_3,
	Simpson_3_8,
	Romberg
};

class Integration {
private:
	IntegrationStrategy* _strategy;

public:
	Integration(const IntegrationType& type = IntegrationType::Romberg);
	Integration(const IntegrationType& type, int it);
	~Integration();

	void set_strategy(const IntegrationType& type, int it = 10);
	void apply(int a, int b);
	void set_type(const IntegrationType& type);
	const IntegrationType get_type(void) const;
	void show_grid(void);
	void set_equation(const std::string& equation);
	double get_result_d() const;
	std::string get_result_s() const;
	std::vector<std::vector<std::string>> get_grid_header() const;
	std::vector<std::vector<double>> get_grid() const;
private:
	IntegrationType _type;
	std::string _equation;
	std::string _cmethod; // current method
};

#endif // !_MATH_CALC_INTEGRATION_H_
