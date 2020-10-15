#ifndef _MATH_CALC_FUNCTION_2D_H_
#define _MATH_CALC_FUNCTION_2D_H_
#pragma once

#include<vector>

struct F2D
{
	double x;
	double y;
};

typedef struct std::vector<F2D> f2d_t;

class Function2D {
public:
	Function2D();
	~Function2D();

	void add_point(double x, double y);
	const f2d_t get_function(void) const;
private:
	f2d_t* _function;
};

#endif // !_MATH_CALC_FUNCTION_2D_H_
