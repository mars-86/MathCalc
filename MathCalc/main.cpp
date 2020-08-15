#include <iostream>
#include "base_calc/base_calc.h"
#include "nonlinear/nonlinear.h"
#include <string>

// TODO
// float numbers
// variables
// functions
// steps
// malformed expressions

int replace_v(const char* src, char* dest, int var, const char* val)
{
    while (*src != '\0') {
        if (*src == var) {
            *dest++ = '*';
            const char* tval = val;
            while (*tval != '\0')
                *dest++ = *tval++;
        }
        else
            *dest++ = *src;
        ++src;
    }
    *dest = '\0';

    return 0;
}

int replace_v(const std::string& src, std::string& dest, int var, const std::string& val)
{
    for (auto i = src.begin(); i != src.end(); ++i) {
        if (*i == var) {
            dest.push_back('*');
            for (auto i2 = val.begin(); i2 != val.end(); ++i2) dest.push_back(*i2);
        }
        else
            dest.push_back(*i);
    }
    return 0;
}

int main(int argc, char* argv[])
{
    //Lexer tknr("(1432 + 50x (3.4^2) - 112) / sin90xy * pi/2");
    //Lexer tknr("((50) / 25)");
    //Lexer tknr("((3*5+8/2+1)/4)*250");
    //Lexer tknr("-5^2+(-25)/5");
    //Lexer tknr("-(5^2)*(-5)!"); // FIX: Factorial 
    //Lexer tknr("-(5^2)+-5");
    //Lexer tknr("5.2+5.5");
    //Lexer tknr("5/5+5*5");
    //Lexer tknr("(1+3x)");
    /*if (argc < 2) {
        fprintf(stderr, "%s\n", "Args missing");
        return 1;
    }
    Lexer tknr(argv[1]);
    */
    //Lexer tknr("(6/(-2))");
    //Lexer tknr("6x+2x");
    //Lexer tknr("5^2^2^2"); // FIX: This kind of expression or else 5^2^2^2 -> 625 BAD!
    //Lexer tknr("((5^2)^(2^2))"); // -> Throws error
    /*Lexer tknr("6*5+2*5^2"); // FIX -> Bad parse
    
    std::vector<Token*> tk = tknr.get_tokens();

    for (auto i : tk)
        std::cout << i->type << " " << i->value << std::endl;

    Parser parser;
    parser.parse(tk);
    //parser.show_expresion();

    std::cout << "INTERPRETER" << std::endl;
    Interpreter interpreter;
    interpreter.interpret(parser.get_parse_tree());*/

    /*Calculator calc;
    //calc.resolv("(6*5+2)^(5^2)");

    std::string eq;
    replace_v("6x+2x^2", eq, 'x', "12.654");

    std::cout << eq << std::endl;

    calc.resolv(eq.c_str());
    */
    Nonlinear nonlinear("2.718281^(-1x)-1x", "regula_falsi"); // TODO: calc lexer must analyse expresion, not an isolate function, this throws error

    nonlinear.apply(0, 1);

    nonlinear.show_grid();

    return 0;
}
