#ifndef _MATH_CALC_PARSE_TREE_H
#define _MATH_CALC_PARSE_TREE_H
#pragma once

#include <string>

typedef struct _Binop {
	char* val;
	_Binop* variable;
	_Binop* left;
	_Binop* right;
} Binop;

class ParseTree {
public:
	ParseTree();
	ParseTree(const char *val);
	~ParseTree();
	int insert_node(Binop* node);
	Binop* create_node(const char *val);
	void traverse(const char* mode) const;
	Binop* get_parse_tree(void);
	const std::string get_result_as_string(void);
	void prune(void);
private:
	Binop* root = nullptr;
	void traverse_prefix(Binop* root) const;
	void traverse_infix(Binop *root) const;
	void traverse_postfix(Binop* root) const;
	void prune(Binop* root);
};

#endif // _MATH_CALC_PARSE_TREE_H