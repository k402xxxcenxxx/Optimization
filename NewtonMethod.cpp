#include "NewtonMethod.h"

NewtonMethod::NewtonMethod()
{
}

std::vector<Point2d> NewtonMethod::Newton(Expression f, Point2d initPoint, std::string* processLog) {
	std::cout.precision(dbl::max_digits10);

	Point2d result;
	std::vector<Point2d> result_Points;

	std::ostringstream processLogstream;

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

	processLogstream << "Hessian Matrix : " << std::endl;
	processLogstream << "[" << std::endl;
	processLogstream << H[0] << " " << H[1] << std::endl;
	processLogstream << H[2] << " " << H[3] << std::endl;
	processLogstream << "]" << std::endl;

	double test = H[0] * H[3] - H[1] * H[2];
	if (std::abs(test) <= 1.0e-18) {
		processLogstream << "no inverse matrix !!" << std::endl;
		*processLog = processLogstream.str();
		return result_Points;
	}

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

	processLogstream << std::endl;

	processLogstream << "inverse Hessian Matrix : " << std::endl;
	processLogstream << "[" << std::endl;
	processLogstream << inverseH[0] << " " << inverseH[1] << std::endl;
	processLogstream << inverseH[2] << " " << inverseH[3] << std::endl;
	processLogstream << "]" << std::endl;

	double delta_max = 1.0e-8;
	Point2d p_pre = initPoint;
	double delta = 999;
	double delta_pre = 999;

	while (true) {
		result.x = -1 * (inverseH[0] * gradientF[0].getValue(p_pre.x, p_pre.y) + inverseH[1] * gradientF[1].getValue(p_pre.x, p_pre.y)) + p_pre.x;
		result.y = -1 * (inverseH[2] * gradientF[0].getValue(p_pre.x, p_pre.y) + inverseH[3] * gradientF[1].getValue(p_pre.x, p_pre.y)) + p_pre.y;

		std::cout << "result point : " << std::endl;
		std::cout << " ( " << result.x << " , " << result.y << " ) \n" << std::endl;

		processLogstream << "x : " << std::endl;
		processLogstream << result.toString() << "\n" << std::endl;
		processLogstream << std::endl;

		delta = (result - p_pre).norm();
		std::cout << "delta : " << delta<< std::endl;

		if (delta > delta_pre) {
			result = p_pre;

			processLogstream << "finished!!" << std::endl;
			processLogstream << "x : " << std::endl;
			processLogstream << std::setprecision(5) << " ( " << result.x << " , " << result.y << " ) \n" << std::endl;
			processLogstream << "min = " << std::setprecision(5) << f.getValue(result.x, result.y) << std::endl;
			processLogstream << std::endl;

			break;
		}
		else if (delta < delta_max) {
			processLogstream << "finished!!" << std::endl;
			processLogstream << "x : " << std::endl;
			processLogstream << std::setprecision(5) << " ( " << result.x << " , " << result.y << " ) \n" << std::endl;
			processLogstream << "min = " << std::setprecision(5) << f.getValue(result.x, result.y) << std::endl;
			processLogstream << std::endl;

			break;
		}
		else {
			delta_pre = delta;
			
			result_Points.push_back(result);
			p_pre = result;
		}
	}

	

	*processLog = processLogstream.str();

	return result_Points;
}
