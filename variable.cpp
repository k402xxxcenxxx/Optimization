#include "variable.h"
variable::variable()
{
	coefficient = 0.0;
	powerX = 0.0;
	powerY = 0.0;
}

variable::variable(double c,double myPowerX,double myPowerY)
{
	coefficient = c;
	powerX = myPowerX;
	powerY = myPowerY;
}

variable::~variable()
{
}

variable variable::PartialDifferentiation(symbol s)
{
	variable v = variable(coefficient, powerX, powerY);

	if (s == symbol::x) {
		v.coefficient = coefficient * powerX;
		v.powerX = powerX - 1;

		v.zerolization();
	}
	else if (s == symbol::y) {
		v.coefficient = coefficient * powerY;
		v.powerY = powerY - 1;

		v.zerolization();
	}

	return v;
}

void variable::zerolization() {
	if (std::abs(coefficient) <= 1.0e-31) {
		coefficient = 0.0;
		powerX = 0.0;
		powerY = 0.0;
	}
}

bool variable::isConstant() {
	return(powerX == 0.0 && powerY == 0.0);
}

std::string variable::toString() {
	std::ostringstream strs;

	if (coefficient != 0.0) {
		strs << coefficient;
	}

	if (powerX > 0) {
		if (powerX == 1.0) {
			strs << "x";
		}
		else {
			strs << "x^" << powerX;
		}
	}

	if (powerY > 0) {
		if (powerY == 1.0) {
			strs << "y";
		}
		else {
			strs << "y^" << powerY;
		}
	}

	return strs.str();
}

double variable::getValue(double x, double y) {
	double result = coefficient * std::pow(x, powerX) * std::pow(y, powerY);

	//std::cout << result << std::endl;

	return result;
}