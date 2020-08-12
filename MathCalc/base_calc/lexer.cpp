#include "lexer.h"
#include "mathfunc.h"
#include "mathconst.h"
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>

enum class Type {
	FUNCTION,
	VARIABLE,
	NUMBER,
	OPERAND,
	SEPARATOR
};

enum {
	PAREN_LEFT = '(',
	PAREN_RIGHT = ')',
	BRACK_LEFT = '[',
	BRACK_RIGHT = ']'
};

enum OPERATOR {
};

Lexer::Lexer()
{
}

Lexer::Lexer(const char* str)
{
	tokenize(str);
}

Lexer::~Lexer()
{
	free_token_vector();
}

int Lexer::tokenize(const char* str)
{
	std::cout << str << std::endl;
	const char* s = str;
	char buff[128];
	free_token_vector(); // clean token vector
	while (*s != NULL) {
		memset(buff, 0, sizeof(buff[0]));
		if (*s == ' ');
		else if (isdigit(*s)) {
			int i = 0;
			do {
				buff[i++] = *s++;
			} while (isdigit(*s) || *s == '.');
			buff[i] = '\0', s--; // s-- -> back one char
			add_token("number", buff);
		}
		else if (isalpha(*s)) {
			int i = 0;
			do {
				buff[i++] = *s++;
			} while (isalpha(*s));
			buff[i] = '\0', s--; // s-- -> back one char
			add_token(check_symbol(buff), buff);
		}
		else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '^' || *s == '!') {
			buff[0] = *s, buff[1] = '\0';
			add_token("operator", buff);
		}
		else if (*s == '(') {
			buff[0] = *s, buff[1] = '\0';
			add_token("parenl", buff);
		}
		else if (*s == ')') {
			buff[0] = *s, buff[1] = '\0';
			add_token("parenr", buff);
		}
		else if (*s == '[') {
			buff[0] = *s, buff[1] = '\0';
			add_token("brackl", buff);
		}
		else if (*s == ']') {
			buff[0] = *s, buff[1] = '\0';
			add_token("brackr", buff);
		}
		++s;
	}
	return 0;
}

const std::vector<Token*>& Lexer::get_tokens(void) const
{
	return _tokens;
}

void Lexer::free_token_vector(void)
{
	/*for (int i = 0; i < _tokens.size(); ++i) {
		free(_tokens[i]->value);
		free(_tokens[i]);
	}*/
	while (!_tokens.empty()) {
		free(_tokens[_tokens.size() - 1]->value);
		free(_tokens[_tokens.size() - 1]);
		_tokens.pop_back();
	}
	//_tokens.clear();
	std::cout << _tokens.size();
}

int Lexer::add_token(const char* type, const char* value)
{
	int len = strlen(value) + 1; // len + \0
	Token* tk = (Token*)malloc(sizeof(Token));
	if (!tk) return -1;
	tk->value = (char*)malloc(len * sizeof(char));
	tk->type = (char*)type;
#ifdef _WIN32
	sprintf_s(tk->value, len, "%s", value);
#else
	sprintf(tk->value, "%s", value);
#endif // _WIN32
	_tokens.push_back(tk);
	return 0;
}

const char* Lexer::check_symbol(const char* sym)
{
	if (is_constant(sym)) return "constant";
	if (is_function(sym)) return "function";
	return "variable";
}

int Lexer::is_constant(const char* c)
{
	const char** s = _constants;
	while (*s != NULL) {
		if (strcmp(c, *s) == 0)
			return 1;
		s++;
	}
	return 0;
}

int Lexer::is_function(const char* f)
{
	const char** s = _functions;
	while (*s != NULL) {
		if (strcmp(f, *s) == 0)
			return 1;
		s++;
	}
	return 0;
}