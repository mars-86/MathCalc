#include <iostream>
#include "calculator.h"
#include "nonlinear/bisection.h"
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

// TODO
// float numbers
// variables
// functions
// steps
// malformed expressions

int replace_v(const char* src, char* dest, int var, int val)
{
    while (*src != '\0') {
        if (*src == var) {
            *dest++ = '*';
            *dest = val;
        }
        else
            *dest = *src;
        ++src, ++dest;
    }
    *dest = '\0';

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
    
    //Calculator calc;
    //calc.resolv("5.2+5.5");

    /*
    char eq[20];
    replace_v("6x+2x^2", eq, 'x', '5');

    std::cout << eq << std::endl;

    calc.resolv("6*5+2*5^2");
    */
    /*Bisection bs(10);

    bs.apply(0, 1);
    auto gd = bs.get_grid();

    for (auto i : gd) {
        for (int j = 0; j < i.size(); ++j)
            std::cout << i.at(j) << ' ';
        std::cout << std::endl;
    }*/

    return 0;
}
