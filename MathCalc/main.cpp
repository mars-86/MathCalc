#include <iostream>
#include "base_calc/base_calc.h"
#include "nonlinear/nonlinear.h"
#include "differential/differential.h"
#include <string>
#include "misc/misc.h"
// TODO
// float numbers
// variables
// functions
// steps
// malformed expressions
// decimal length

int main(int argc, char* argv[])
{
    //"(1432 + 50x (3.4^2) - 112) / sin90xy * pi/2"
    //"-(5^2)*(-5)!" // FIX: Factorial 
    /*
    if (argc < 2) {
        fprintf(stderr, "%s\n", "Args missing");
        return 1;
    }
    */
    // "5^2^2^2" // FIX: This kind of expression or else 5^2^2^2 -> 625 BAD!
    // "((5^2)^(2^2))" // -> Throws error
    // "6*5+2*5^2" // FIX -> Bad parse

    // FIX: bad resuts with so much decimals i.e. 0.00000001 -> 0
    // std::cout << calc.resolv("((2.718281^(-(0.000000+0.00000001))-(0.000000+0.00000001))-(2.718281^(-0.000000)-0.000000))/0.00000001").get_result() << std::endl;
    // return 0;
    // Nonlinear nonlinear("2.718281^(-x)-x", "newton_raphson"); // TODO: calc lexer must analyse expresion, not an isolate function, this throws error
    // check this expression "(2.718281^(-1x)-1x" bad analysis because of x

    // Nonlinear nonlinear("(-1/3)*(x)^2+(8/3)*(x)+4", "secant");
    // nonlinear.apply(-2, -1);
    // nonlinear.show_grid();

    // BaseCalc bc;
    // FIX: pass only a number throws error
    // std::cout << bc.resolv("2").get_result();

    // FIX: decimal length
    // Differential dif("(-1/3)*(x)^2+(8/3)*(x)+4", "trapezoidal", 1);
    // FIX: if x is replaced by a negative value calculus is wrong build (i.e. --2)
    // Differential dif("2.718281^(-x)-3x", "trapezoidal", 1); 
    // dif.apply(-2, 5, 16);
    ArithmeticGeometricMean agm(25, 5);
    std::vector<std::vector<std::string>> g = agm.get_grid();
    for (auto i : g) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }

    std::cout << std::stod(agm.get_result()) << std::endl;

    return 0;
    Differential dif("2.718281^((x)^2)", "romberg", 4);

    dif.apply(0, 1, 16);

    std::cout << std::stod(dif.get_result()) << std::endl;

    return 0;
}