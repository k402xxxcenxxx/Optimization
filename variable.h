#pragma once
public class variable
{
public:
	variable();
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

	void zerolization();

	bool isConstant();

private:

};

