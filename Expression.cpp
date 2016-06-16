#include "Expression.h"
Expression::Expression()
{
}

void Expression::add(variable v) {
	variables.push_back(v);
}

bool Expression::remove(variable v) {
	std::vector<variable>::iterator iter;

	/*iter = std::find(variables.begin(), variables.end(), v);
	if (iter != variables.end()) {
		variables.erase(iter);
		return true;
	}
	else {
		return false;
	}*/

	return true;
}

void Expression::clear() {
	variables.clear();
}


Expression Expression::PartialDifferentiation(variable::symbol s) {
	Expression resultEquation;

	for each(variable v in variables) {
		variable tempv = v.PartialDifferentiation(s);
		if(tempv.coefficient != 0.0)
			resultEquation.add(tempv);
	}

	return resultEquation;
}

std::string Expression::toString() {
	std::string s = "";
	for each (variable v in variables) {
		if (v.coefficient > 0)
			s += "+";
		s += v.toString();
		
		s += " ";
	}
	return s;
}

double Expression::getConstant() {
	for each(variable v in variables) {
		if (v.isConstant())
			return v.coefficient;
	}

	return 0.0;

}

double Expression::getValue(double x, double y) {
	double result = 0;
	for each(variable v in variables) {
		result += v.getValue(x, y);
	}
	return result;
}