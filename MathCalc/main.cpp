#include <iostream>
#include "base_calc/base_calc.h"
#include "nonlinear/nonlinear.h"
#include "differential/differential.h"
#include "integration/integration.h"
#include "approximation/approximation.h"
#include "polynomial/polynomial.h"
#include "least_squares/least_squares.h"
#include <string>
#include "misc/misc.h"
#include <iomanip>

// TODO
// float numbers
// variables
// functions
// steps
// malformed expressions
// function for decimal formating

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
    std::cout << std::setprecision(9);
    // CHECK: simpson 1/3
    /*
    Integration integ(IntegrationType::Romberg);
    //integ.set_strategy(IntegrationType::Simpson_1_3);
    auto func = integ.set_equation("2.718281^((x)^2)");
    integ.apply(0, 1);
    
    std::cout << func.size() << std::endl;
    for (int i = 0; i < func.size(); ++i)
        std::cout << "x = " << func.at(i).x << " " << "y = " << func.at(i).y << std::endl;
    
    integ.show_grid();
    // auto g = integ.get_grid();
    // std::cout << g.size() << std::endl;

    std::cout << integ.get_result_d() << std::endl;
    return 0;
    */
    /*
    PolynomialCommon::PointSet xy = {
        std::make_pair(1,2),
        std::make_pair(3,3),
        std::make_pair(4,2),
        std::make_pair(8,10)
    };
    Polynomial newton;
    newton.set_strategy(PolynomialType::Newton);
    newton.set_points(xy);
    newton.apply();
    newton.show_grid();
    f2d_t fu;
    std::cout << newton.get_polynomial(fu) << std::endl;

    for (int i = 0; i < fu.size(); ++i)
        std::cout << "x = " << fu.at(i).x << " " << "y = " << fu.at(i).y << std::endl;

    return 0;
    */
    /*
    LeastSquaresCommon::PointSet xy2 = {
        std::make_pair(1, 1.3),
        std::make_pair(2, 3.5),
        std::make_pair(3, 4.2),
        std::make_pair(4, 5),
        std::make_pair(5, 7),
        std::make_pair(6, 8.8),
        std::make_pair(7, 10.1),
        std::make_pair(8, 12.5),
        std::make_pair(9, 13),
        std::make_pair(10, 15.6)
    };
    LeastSquares ls;
    ls.set_strategy(LeastSquaresType::LSApproximation);
    ls.apply(xy2);
    ls.show_grid();
    auto fu = ls.get_function();
    // for (int i = 0; i < fu.size(); ++i)
    //    std::cout << "x = " << fu.at(i).x << " " << "y = " << fu.at(i).y << std::endl;
    return 0;
    */
    // std::cout << std::scientific;
    // FIX: bad resuts with so much decimals i.e. 0.00000001 -> 0
    // std::cout << calc.resolv("((2.718281^(-(0.000000+0.00000001))-(0.000000+0.00000001))-(2.718281^(-0.000000)-0.000000))/0.00000001").get_result() << std::endl;
    // return 0;
    // Nonlinear nonlinear("2.718281^(-x)-x", "newton_raphson"); // TODO: calc lexer must analyse expresion, not an isolate function, this throws error
    // check this expression "(2.718281^(-1x)-1x" bad analysis because of x
    /*Nonlinear nonlinear;
    nonlinear.set_strategy(NonLinearType::RegulaFalsi);
    auto xy = nonlinear.set_equation("(-1/3)*(x)^2+(8/3)*(x)+4");
    //auto xy = nonlinear.set_equation("2.718281^(x)-3*x");
    //nonlinear.apply(0, 1);
    // FIX: bisecction must throw exception because doesn't satisfy f(xi)*f(xs) < 0
    //nonlinear.set_strategy(NonLinearType::Bisection);
    nonlinear.apply(-2, -1);
    nonlinear.show_grid();

    std::cout << "x " << "y" << std::endl;
    for (int i = 0; i < xy.first.size(); ++i)
        std::cout << xy.first[i] << "   " << xy.second[i] << std::endl;

    return 0;*/
    // BaseCalc bc;
    // FIX: pass only a number throws error
    // std::cout << bc.resolv("2").get_result();

    // Differential dif("(-1/3)*(x)^2+(8/3)*(x)+4", "trapezoidal", 1);
    // FIX: if x is replaced by a negative value calculus is wrong build (i.e. --2)
    // Differential dif("2.718281^(-x)-3x", "trapezoidal", 1); 
    // dif.apply(-2, 5, 16);

    //double n = 3.14252525952156333;

    //std::cout << n;

    //return 0;

    Approximation approx(new Logarithmic());
    approx.apply(5);
    // std::cout << approx.get_result() << std::endl;
    // std::cout << std::setprecision(9);
    approx.show_grid();
    std::cout << approx.get_result() << std::endl;
    return 0;
    /*
    Differential dif("2.718281^((x)^2)");

    dif.apply(0, 1, 16);

    std::cout << std::stod(dif.get_result()) << std::endl;

    return 0;*/
}