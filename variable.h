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

	//�Y��
	double coefficient;
	//x�������
	double powerX;
	//y�������
	double powerY;

	//��s�����L��
	variable PartialDifferentiation(symbol s);

	double getValue(double x, double y);

	void zerolization();

	bool isConstant();

	std::string toString();

private:

};

