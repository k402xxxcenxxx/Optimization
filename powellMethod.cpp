#include "powellMethod.h"

powellMethod::powellMethod()
{
}
powellMethod::powellMethod(Expression exp)
{
	myExpression = exp;
}
double powellMethod::goldenSectionSearch(double a, double b, double c, double tau, std::vector<Expression> x_next,double preValue) {
	double x;
	double valueX, valueB;

	b = (a + c) / 2;

	if (b < c)
		x = b + resphi * (c - b);
	else
		x = b - resphi * (b - a);

	//std::cout << "a = " << a << std::endl;
	//std::cout << "c = " << c << std::endl;
	//std::cout << "x = " << x << std::endl;
	//std::cout << " " << std::endl;

	if ((std::abs(c - a) < tau * (std::abs(b) + std::abs(x))) || std::abs(preValue - x) <= tau ) {
		return (c + a) / 2;
	}

	if (x_next.size() == 1) {
		valueX = myExpression.getValue(x_next[0].getValue(x), 0);
		valueB = myExpression.getValue(x_next[0].getValue(b), 0);
	}
	else if (x_next.size() == 2) {
		valueX = myExpression.getValue(x_next[0].getValue(x), x_next[1].getValue(x));
		valueB = myExpression.getValue(x_next[0].getValue(b), x_next[1].getValue(b));
	}

	//std::cout << "f(x) = " << valueX << std::endl;
	//std::cout << "f(b) = " << valueB << std::endl;
	//std::cout << "---"  << std::endl;

	if (valueX < valueB) {
		return (b < c) ? goldenSectionSearch(b, x, c, tau, x_next, x) : goldenSectionSearch(a, x, b, tau, x_next, x);
	}
	else {
		return (b < c) ? goldenSectionSearch(a, b, x, tau, x_next, x) : goldenSectionSearch(x, b, c, tau, x_next, x);
	}

	//if (x_next.size() == 1) {
	//	if (myExpression.getValue(x_next[0].getValue(x), 0) < myExpression.getValue(x_next[0].getValue(b), 0))
	//		return (b < c) ? goldenSectionSearch(b, x, c, tau, x_next, x) : goldenSectionSearch(a, x, b, tau, x_next,x);
	//	else
	//		return (b < c) ? goldenSectionSearch(a, b, x, tau, x_next, x) : goldenSectionSearch(x, b, c, tau, x_next, x);
	//}
	//else if (x_next.size() == 2) {
	//	if (myExpression.getValue(x_next[0].getValue(x), x_next[1].getValue(x)) < myExpression.getValue(x_next[0].getValue(b), x_next[1].getValue(b)))
	//		return (b < c) ? goldenSectionSearch(b, x, c, tau, x_next, x) : goldenSectionSearch(a, x, b, tau, x_next, x);
	//	else
	//		return (b < c) ? goldenSectionSearch(a, b, x, tau, x_next, x) : goldenSectionSearch(x, b, c, tau, x_next, x);
	//}
	
}

double powellMethod::getAlpha() {
	return 0;
}