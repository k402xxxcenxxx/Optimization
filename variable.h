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

	//�Y��
	double coefficient;
	//x�������
	double powerX;
	//y�������
	double powerY;

	//��s�����L��
	variable PartialDifferentiation(symbol s);

	void zerolization();

	bool isConstant();

private:

};

