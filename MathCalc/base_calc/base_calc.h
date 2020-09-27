#ifndef _MATH_CALC_BASE_CALC_H
#define _MATH_CALC_BASE_CALC_H
#pragma once

#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"
#include "tools.h"
#include <map>

class BaseCalc : public Tools {
public:
	BaseCalc();
	BaseCalc(const char* equation);
	~BaseCalc();

	BaseCalc& resolv(const char* equation);
	BaseCalc& resolv(std::string& equation, std::map<std::string, std::vector<std::string>> var_val);
	BaseCalc& resolv(std::string& equation, const std::map<std::string, std::vector<char*>> var_val);
	double summation_eq(const std::string& equation, int from, int to) override;
	double summation_eq(const std::string& eq, const std::vector<double>& val) override;
	const std::string& get_result(void) const;
private:
	Lexer _lexer;
	Parser _parser;
	Interpreter _interpreter;
	std::string _result; // store the results history TODO: modify type to string of strings
};

#endif // !_MATH_CALC_BASE_CALC_H
