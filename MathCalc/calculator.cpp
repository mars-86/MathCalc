#include "calculator.h"

Calculator::Calculator()
{
}

Calculator::Calculator(const char* ecuation)
{

}

Calculator::~Calculator()
{

}

void Calculator::resolv(const char* ecuation)
{
	lexer.tokenize(ecuation);
	parser.parse((std::vector<Token*>&)lexer.get_tokens());
	interpreter.interpret(parser.get_parse_tree());
}