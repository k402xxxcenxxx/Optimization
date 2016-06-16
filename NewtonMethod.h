#pragma once
#include <vector>
#include <iostream>
#include <limits>
#include <iomanip>
#include "Expression.h"
#include "Point2d.h"
public class NewtonMethod
{
public:
	typedef std::numeric_limits< double > dbl;
	std::vector<Point2d> Newton(Expression f, Point2d initPoint, std::string* processLog);

	NewtonMethod();
};

