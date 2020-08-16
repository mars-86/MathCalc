#include "base_calc.h"

BaseCalc::BaseCalc()
{
}

BaseCalc::BaseCalc(const char* equation)
{
	resolv(equation);
}

BaseCalc::~BaseCalc()
{

}

BaseCalc& BaseCalc::resolv(const char* equation)
{
	_lexer.tokenize(equation);
	_parser.parse((std::vector<Token*>&)_lexer.get_tokens());
	_interpreter.interpret(_parser.get_parse_tree());
	_result = _interpreter.get_result();
	return *this;
}

BaseCalc& BaseCalc::resolv(const char* equation, const std::map<std::string, const char*> var_val)
{
	_lexer.tokenize(equation);
	_parser.set_var_val(var_val);
	_parser.parse((std::vector<Token*>&)_lexer.get_tokens());
	_interpreter.interpret(_parser.get_parse_tree());
	_result = _interpreter.get_result();
	return *this;
}

const std::string& BaseCalc::get_result(void) const
{
	return _result;
}