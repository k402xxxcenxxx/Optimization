#pragma once
#include <vector>
#include <iostream>
#include "Expression.h"
#include "Point2d.h"
public class NewtonMethod
{
public:
	Point2d Newton(Expression f, Point2d initPoint, std::string processLog = "");

	NewtonMethod();
};

