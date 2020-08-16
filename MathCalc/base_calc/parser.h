#ifndef _MATH_CALC_PARSER_H
#define _MATH_CALC_PARSER_H
#pragma once

#include <stack>
#include <vector>
#include <map>
#include "lexer.h"
#include "parse_tree.h"

class Parser  {
public:
	Parser();
	Parser(std::vector<Token*>& tks);
	Parser(std::vector<Token*>& tks, std::map<std::string, std::vector<char*>>& var_val);
	~Parser();

	ParseTree& parse(std::vector<Token*>& tks);
	void show_expresion(void) const;
	ParseTree& get_parse_tree(void);
	void set_var_val(std::map<std::string, std::vector<char*>> var_val);
private:
	ParseTree parse_tree;
	//std::map<std::string, const char*> _var_val;
	std::map<std::string, std::vector<char*>> _var_val;
	std::vector<char*> mathexp;
	std::vector<std::string> _mathexp;
	std::stack<Binop*> node_stack;
	int check_expresion(std::vector<Token*>& tks);
	int eval(std::vector<Token*>& tks);
	//Binop* generate_parse_tree(Binop* root, std::vector<char*>::iterator ptr, std::vector<char*>::iterator end, std::vector<char*>*);
	int generate_parse_tree_it(std::vector<char*> mvec);
	const char* getResult(std::vector<char*> mvtemp, int it);
	void insert_data(int pcount, const char* val);
	void insert_parens(int count, const char* paren);
	bool is_operator(const char* c);
};

#endif // _MATH_CALC_PARSER_H
