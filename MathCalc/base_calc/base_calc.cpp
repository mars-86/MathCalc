#include "base_calc.h"

BaseCalc::BaseCalc()
{
}

BaseCalc::BaseCalc(const char* ecuation)
{

}

BaseCalc::~BaseCalc()
{

}

void BaseCalc::resolv(const char* equation)
{
	_lexer.tokenize(equation);
	_parser.parse((std::vector<Token*>&)_lexer.get_tokens());
	_interpreter.interpret(_parser.get_parse_tree());
	_result = _interpreter.get_result();
}

const std::string& BaseCalc::get_result(void) const
{
	return _result;
}