#include "function_2d.h"

Function2D::Function2D()
	:_function(new f2d_t)
{
}

Function2D::~Function2D()
{
	delete _function;
}

void Function2D::add_point(double x, double y)
{
	_function->push_back({ x, y });
}

const f2d_t Function2D::get_function(void) const
{
	return *_function;
}