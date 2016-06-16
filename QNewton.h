#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Expression.h"
#include "NewtonMethod.h"
#include "powellMethod.h"
ref class QNewton
{
public:
	std::vector<Point2d> QuasiNewton(Expression f, Point2d initPoint, double maxValue, double minValue, std::string* processLog);

	QNewton();
};

