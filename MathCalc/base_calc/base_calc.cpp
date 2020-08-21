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
/*
void replace_var(std::vector<char*>& m, const std::string& var, std::vector<char*>& val)
{
	for (int i = 0; i < m.size(); ++i)
		if (m[i] == var) {
			for (auto j : val)
				m.insert(m.begin() + i, (char*)j);
			m.erase(m.begin() + i + val.size()); // remove var
		}
}
*/
/*
void replace_var(std::string& m, const char var, std::vector<char*>& val)
{
	for (int i = 0; i < m.size(); ++i)
		if (m[i] == var) {
			int len = 0;
			for (auto j : val) {
				// this way we insert in correct order, otherwise vals are inserted backwards
				m.insert((int)(i + len), (char*)j);
				len += strlen(j);
			}
			i += len;
			m.erase(m.begin() + i); // remove var
		}
}
*/
BaseCalc& BaseCalc::resolv(std::string& equation, const std::map<std::string, std::vector<char*>> var_val)
{
	if (!var_val.empty())
		for (auto i : var_val)
			replace_var(equation, i.first[0], i.second);
	_lexer.tokenize(equation.c_str());
	_parser.parse((std::vector<Token*>&)_lexer.get_tokens());
	_interpreter.interpret(_parser.get_parse_tree());
	_result = _interpreter.get_result();
	return *this;
}

const std::string& BaseCalc::get_result(void) const
{
	return _result;
}