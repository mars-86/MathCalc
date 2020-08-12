#ifndef _MATH_CALC_INTERPRETER_H_
#define _MATH_CALC_INTERPRETER_H_
#pragma once

#include <iostream>
#include "parse_tree.h"

class Interpreter {
public:
	Interpreter();
	~Interpreter();

	int interpret(ParseTree& tree);
	const std::string get_result(void) const;
private:
	void resolv(ParseTree& tree, Binop* root);
	bool is_operator(const char* c);
	int check_variables(const Binop* root) const;
	std::string _result;
};

#endif // !_MATH_CALC_INTERPRETER_H_
