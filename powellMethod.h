#pragma once
#include <vector>
#include <iostream>
#include "Expression.h"
#include "Point2d.h"
#include "GMethod.h"
public class powellMethod
{
public:
	double phi = (1 + std::sqrt(5)) / 2;
	double resphi = 2 - phi;

	powellMethod();
	powellMethod(Expression exp);

	Expression myExpression;

	double goldenSectionSearch(double a, double b, double c, double tau, std::vector<Expression> x_next, double preValue = 1.0e+18);

	double getAlpha();
};

