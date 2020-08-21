#include <iostream>
#include "base_calc/base_calc.h"
#include "nonlinear/nonlinear.h"
#include "differential/differential.h"
#include <string>

// TODO
// float numbers
// variables
// functions
// steps
// malformed expressions

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

    //BaseCalc calc;
    //calc.resolv("(6*5+2)^(5^2)");
    //std::cout << calc.gen_var_val_pair("x", "33").first << calc.gen_var_val_pair("x", "33").second << std::endl;
    //calc.resolv("2x+3x", { calc.gen_var_val_pair("x", "33") });
    //std::cout << calc.get_result() << std::endl;
    /*
    std::string eq;
    replace_v("6x+2x^2", eq, 'x', "12.654");

    std::cout << eq << std::endl;

    calc.resolv(eq.c_str());
    */
    BaseCalc calc;
    // FIX: bad resuts with so much decimals i.e. 0.00000001 -> 0
    //std::cout << calc.resolv("((2.718281^(-(0.000000+0.00000001))-(0.000000+0.00000001))-(2.718281^(-0.000000)-0.000000))/0.00000001").get_result() << std::endl;
    //return 0;
    // Nonlinear nonlinear("2.718281^(-x)-x", "newton_raphson"); // TODO: calc lexer must analyse expresion, not an isolate function, this throws error
    // check this expression "(2.718281^(-1x)-1x" bad analysis because of x
    Nonlinear nonlinear("(-1/3)*(x)^2+(8/3)*(x)+4", "secant");

    nonlinear.apply(-2, -1);

    nonlinear.show_grid();

    return 0;
    /*
    const char* cn = "0.00000001";
    double n = 0.00000001;
    double n2 = 0.00000001;
    std::cout << std::stod(cn) << std::endl;
    */

    // Differential dif("2.718281^(-x)-x");

    // Differential dif;

    // dif.apply(0.56714329);

    // std::cout << dif.get_result() << std::endl;

    return 0;
}
