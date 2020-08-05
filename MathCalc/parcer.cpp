#include "parser.h"
#include <iostream>
#include <string>
#include <cmath>

Parser::Parser()
{
}

Parser::Parser(std::vector<Token*>& tks)
{
	parse(tks);
}

Parser::~Parser()
{
}

ParseTree& Parser::parse(std::vector<Token*>& tks)
{
	check_expresion(tks);
	eval(tks);
	generate_parse_tree_it(mathexp);
	//parse_tree.traverse("infix");
	return get_parse_tree();
}

int Parser::generate_parse_tree_it(std::vector<char*> mvtemp)
{
	for (int i = 0; i < mvtemp.size(); ++i) {
		int it = i - 2;
		if (mvtemp[i] == "(") continue;
		if (mvtemp[i] == ")") {
			mvtemp.erase(mvtemp.begin() + i);
			//std::cout << mvtemp[it] << std::endl;
			if (is_operator(mvtemp[it])) {
				// Don't want to remove lparen while successive operations (op_count > 0)
				int op_count = 0;
				Binop* op;
				do {
					//std::cout << "CALC: " << mvtemp[it - 1] << mvtemp[it] << mvtemp[it + 1] << std::endl;
					op = parse_tree.create_node(mvtemp[it]);
					// _NODE_ +- _NODE_
					if (strcmp(mvtemp[it - 1], "_NODE_") == 0 && strcmp(mvtemp[it + 1], "_NODE_") == 0) {
						op->right = node_stack.top(), node_stack.pop();
						op->left = node_stack.top(), node_stack.pop();
					}
					else if (strcmp(mvtemp[it - 1], "_NODE_") == 0) { // _NODE_ +- num
						op->right = parse_tree.create_node((char*)mvtemp[it + 1]);
						op->left = node_stack.top(), node_stack.pop();
					}
					else if (strcmp(mvtemp[it + 1], "_NODE_") == 0) { // num +- _NODE_
						op->right = node_stack.top(), node_stack.pop();
						op->left = parse_tree.create_node((char*)mvtemp[it - 1]);
					}
					/*else if (strcmp(mvtemp[it + 1], "x") == 0) { // num +- var
						op->val = (char*)mvtemp[it - 1];
						op->variable = parse_tree.create_node((char*)mvtemp[it + 1]);
					}*/
					else { // num +- num
						op->left = parse_tree.create_node((char*)mvtemp[it - 1]);
						op->right = parse_tree.create_node((char*)mvtemp[it + 1]);
					}
					/*char* buff;
					size_t len = strlen(buff_temp) + 1;
					buff = (char*)malloc(len * sizeof(char));
					memcpy(buff, buff_temp, len);*/
					mvtemp.insert(mvtemp.begin() + it - 1, (char*)"_NODE_"); //insert new value
					mvtemp.erase(mvtemp.begin() + it, mvtemp.begin() + it + 3); // erase pre-operator operator post-operator

					if (op_count == 0/* && !is_operator((mvtemp[0 + it - 2]))*/) mvtemp.erase(mvtemp.begin() + it - 2);
					i = (it - 2) < 0 ? 0 : it - 2;
					it = (it - 3) < 0 ? 0 : it - 3;
					// std::cout << "OP: " << mvtemp[it] << std::endl;
					// store node in stack
					node_stack.push(op);
					++op_count;
					std::cout << mvtemp[it] << std::endl;
				} while (is_operator(mvtemp[it]));
				// store node in stack
				// node_stack.push(op);
			}
			else {
				// erase (
				mvtemp.erase(mvtemp.begin() + it);
				i = it;
			}
			for (int i = 0; i < mvtemp.size(); ++i)
				std::cout << mvtemp[i];
			std::cout << std::endl;
		}
		else if (is_operator(mvtemp[it + 2]) && is_operator(mvtemp[it])) { // i.e. 3*3* or 3+3+ resolves same precedence cases
			Binop* op;
			op = parse_tree.create_node(mvtemp[it]);
			// _NODE_ +- _NODE_
			if (strcmp(mvtemp[it - 1], "_NODE_") == 0 && strcmp(mvtemp[it + 1], "_NODE_") == 0) {
				op->right = node_stack.top(), node_stack.pop();
				op->left = node_stack.top(), node_stack.pop();
			}
			else if (strcmp(mvtemp[it - 1], "_NODE_") == 0) { // _NODE_ +- num
				op->right = parse_tree.create_node((char*)mvtemp[it + 1]);
				op->left = node_stack.top(), node_stack.pop();
			}
			else if (strcmp(mvtemp[it - 1], "_NODE_") == 0) { // num +- _NODE_
				op->right = node_stack.top(), node_stack.pop();
				op->left = parse_tree.create_node((char*)mvtemp[it + 1]);
			}
			/*else if (strcmp(mvtemp[it + 1], "x") == 0) { // num +- var
				op->val = (char*)mvtemp[it - 1];
				op->variable = parse_tree.create_node((char*)mvtemp[it + 1]);
			}*/
			else { // num +- num
				op->left = parse_tree.create_node((char*)mvtemp[it - 1]);
				op->right = parse_tree.create_node((char*)mvtemp[it + 1]);
			}
			mvtemp.insert(mvtemp.begin() + it - 1, (char*)"_NODE_"); //insert new value
			mvtemp.erase(mvtemp.begin() + it, mvtemp.begin() + it + 3);

			node_stack.push(op);
		}
		//if (mvtemp.size() == 1) break;
	}
	parse_tree.insert_node(node_stack.top());
	node_stack.pop();
	return 0;
}

void Parser::show_expresion(void) const
{
	for (auto i : mathexp)
		std::cout << (char*)i;
	std::cout << std::endl;
}

ParseTree& Parser::get_parse_tree(void)
{
	return parse_tree;
}

int Parser::check_expresion(std::vector<Token*>& tks)
{
	return 0;
}

int Parser::eval(std::vector<Token*>& tks)
{
	insert_parens(4, "(");
	int i_prev, extra_paren_cntr = 0; // extra_paren_cntr counts paren that we don't want to insert at index position but at end
	for (int i = 0; i < tks.size(); ++i) {
		i_prev = i - 1;
		if (strcmp(tks[i]->type, "number") == 0)
			mathexp.push_back((char*)tks[i]->value);
		/*if (strcmp(tks[i]->type, "variable") == 0) {
			if (i > 0 && (strcmp(tks[i_prev]->type, "number") == 0)) {
				insert_data(2, "*");
				mathexp.push_back((char*)tks[i]->value);
			}
			else { // if previous val is an operator, paren, etc
				mathexp.insert(mathexp.end(), { (char*)"(", (char*)"1", (char*)")", (char*)")", (char*)"*", (char*)"(", (char*)"(", (char*)tks[i]->value, (char*)")" });
				//mathexp.push_back((char*)tks[i]->value);
			}
		}*/
		if (strcmp(tks[i]->type, "operator") == 0) {
			if (strcmp(tks[i]->value, "+") == 0)
				insert_data(3, tks[i]->value);
			else if (strcmp(tks[i]->value, "-") == 0) {
				if (strcmp(tks[i + 1]->type, "number") == 0) { // Precedence: i.e. -5 ^ 2 -> -1 * (5 ^ 2)
					// We need to insert rparen at end to balance.
					// If we insert rparen behind the value we'll lost * level of precedence and
					// in a case such as -5^2 where ^ presedence is higher than * the calculator
					// result would be 25 instead of -25.
					mathexp.insert(mathexp.end(), { (char*)"(", (char*)"-1", (char*)")", (char*)")", (char*)"*", (char*)"(", (char*)"(", (char*)tks[++i]->value/*, (char*)")"*/ });
					extra_paren_cntr++;
				}
				else if (i == 0 || (strcmp(tks[i_prev]->type, "number") && (strcmp(tks[i_prev]->type, "parenr") != 0)))
					mathexp.push_back((char*)"-1"), insert_data(2, "*");
				else
					insert_data(3, tks[i]->value);
			}
			else if (strcmp(tks[i]->value, "*") == 0 || strcmp(tks[i]->value, "/") == 0)
				insert_data(2, tks[i]->value);
			else if (strcmp(tks[i]->value, "^") == 0)
				insert_data(1, tks[i]->value);
			/*else if (strcmp(tks[i]->value, "!") == 0) {
				mathexp.pop_back();
				mathexp.insert(mathexp.end(), { (char*)"fact(", tks[i_prev]->value, (char*)")" });
			}*/
			else
				mathexp.push_back((char*)tks[i]->value);
		}
		if (strcmp(tks[i]->type, "parenl") == 0)
			insert_parens(4, "(");
		if (strcmp(tks[i]->type, "parenr") == 0)
			insert_parens(4, ")");
	}
	insert_parens(4 + extra_paren_cntr, ")");

	return 1;
}

void Parser::insert_data(int pcount, const char* val)
{
	insert_parens(pcount, ")");
	mathexp.push_back((char*)val);
	insert_parens(pcount, "(");
}

void Parser::insert_parens(int count, const char *paren)
{
	for (int i = 0; i < count; ++i)
		mathexp.push_back((char*)paren);
}

bool Parser::is_operator(const char *c)
{
	if ((strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0 || strcmp(c, "^") == 0))
		return true;
	return false;
}