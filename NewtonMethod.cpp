#include "NewtonMethod.h"

NewtonMethod::NewtonMethod()
{
}

Point2d NewtonMethod::Newton(Expression f, Point2d initPoint, std::string processLog) {
	Point2d result;

	//f ªº ±×²v
	std::vector<Expression> gradientF;
	
	gradientF.push_back(f.PartialDifferentiation(variable::x));
	gradientF.push_back(f.PartialDifferentiation(variable::y));
	std::cout << "gradientF : " << std::endl;
	std::cout << gradientF[0].toString() << std::endl;
	std::cout << gradientF[1].toString() << std::endl;

	//Hessian Matrix
	double* H = new double[4];
	H[0] = gradientF[0].PartialDifferentiation(variable::x).getConstant();
	H[1] = gradientF[0].PartialDifferentiation(variable::y).getConstant();
	H[2] = gradientF[1].PartialDifferentiation(variable::x).getConstant();
	H[3] = gradientF[1].PartialDifferentiation(variable::y).getConstant();

	std::cout << "Hessian Matrix : " << std::endl;
	std::cout << H[0] << " " << H[1] << std::endl;
	std::cout << H[2] << " " << H[3] << std::endl;

	//inverse Hessian Matrix
	double* inverseH = new double[4];
	double det = 1 / (H[0] * H[3] - H[1] * H[2]);
	inverseH[0] = det * H[3];
	inverseH[1] = -1 * det * H[1];
	inverseH[2] = -1 * det * H[2];
	inverseH[3] = det * H[0];

	std::cout << "inverse Hessian Matrix : " << std::endl;
	std::cout << inverseH[0] << " " << inverseH[1] << std::endl;
	std::cout << inverseH[2] << " " << inverseH[3] << std::endl;

	result.x = -1 * (inverseH[0] * gradientF[0].getValue(initPoint.x, initPoint.y) + inverseH[1] * gradientF[1].getValue(initPoint.x, initPoint.y)) + initPoint.x;
	result.y = -1 * (inverseH[2] * gradientF[0].getValue(initPoint.x, initPoint.y) + inverseH[3] * gradientF[1].getValue(initPoint.x, initPoint.y)) + initPoint.y;

	std::cout << "result point : " << std::endl;
	std::cout << " ( " << result.x << " , " << result.y << " ) " << std::endl;

	return result;
}
