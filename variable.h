#pragma once
#include <string>
#include <sstream>
#include <iostream>
public class variable
{
public:
	variable();
	variable(double c, double myPowerX = 0.0, double myPowerY = 0.0);
	~variable();

	enum symbol
	{
		x,
		y
	};

	//係數
	double coefficient;
	//x的次方數
	double powerX;
	//y的次方數
	double powerY;

	//對s做偏微分
	variable PartialDifferentiation(symbol s);

	double getValue(double x, double y);

	void zerolization();

	bool isConstant();

	std::string toString();

private:

};

