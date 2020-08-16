#ifndef _MATH_CALC_BASE_CALC_H
#define _MATH_CALC_BASE_CALC_H
#pragma once

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
	BaseCalc& resolv(const char* equation, std::map<std::string, const char*> var_val);
	const std::string& get_result(void) const;
private:
	Lexer _lexer;
	Parser _parser;
	Interpreter _interpreter;
	std::string _result; // store the results history TODO: modify type to string of strings
};

#endif // !_MATH_CALC_BASE_CALC_H
