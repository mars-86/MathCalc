#ifndef _MATH_CALC_CALCULATOR_H
#define _MATH_CALC_CALCULATOR_H
#pragma once

#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

class Calculator {
public:
	Calculator();
	Calculator(const char* ecuation);
	~Calculator();

	void resolv(const char* ecuation);
private:
	Lexer lexer;
	Parser parser;
	Interpreter interpreter;
};

#endif // !_MATH_CALC_CALCULATOR_H
