#pragma once
#include <vector>
#include "variable.h"
public class Expression
{
public:

	Expression();

	//��ܦ����ܼ�
	std::vector<variable> variables;

	Expression PartialDifferentiation(variable::symbol s);

	void add(variable v);
	bool remove(variable v);
	void clear();

	double getConstant();

	double getValue(double x,double y);

	std::string toString();

};

