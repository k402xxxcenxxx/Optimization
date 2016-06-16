#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Expression.h"
#include "NewtonMethod.h"
#include "powellMethod.h"
public class CGMethod
{
public:
	CGMethod();

	std::vector<Point2d> CG(Expression f, Point2d initPoint, std::string* processLog , double maxValueX = 0, double minValueX = 0, double maxValueY = 0, double minValueY = 0);


};
