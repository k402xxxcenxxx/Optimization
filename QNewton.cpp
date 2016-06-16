#include "QNewton.h"



QNewton::QNewton()
{
}

std::vector<Point2d> QNewton::QuasiNewton(Expression f, Point2d initPoint, double maxValue, double minValue, std::string* processLog) {
	std::ostringstream processLogstream;

	Point2d result;
	powellMethod *goldenSectioner = new powellMethod(f);
	std::vector<Point2d> results;
	//f 的 斜率
	//  ^
	//	a: differential by x
	//  b: differential by y
	//  v
	std::vector<Expression> G;
	G.push_back(f.PartialDifferentiation(variable::x));
	G.push_back(f.PartialDifferentiation(variable::y));
	std::cout << "gradientF : " << std::endl;
	std::cout << G[0].toString() << std::endl;
	std::cout << G[1].toString() << std::endl;

	//F gradient 's transpose
	//<a b>
	std::vector<Expression> G_t;
	G_t.push_back(G[0]);
	G_t.push_back(G[1]);
	std::cout << "gradientF t: " << std::endl;
	std::cout << G_t[0].toString() << std::endl;
	std::cout << G_t[1].toString() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	//Hessian Matrix
	double* H = new double[4];
	H[0] = G[0].PartialDifferentiation(variable::x).getConstant();
	H[1] = G[0].PartialDifferentiation(variable::y).getConstant();
	H[2] = G[1].PartialDifferentiation(variable::x).getConstant();
	H[3] = G[1].PartialDifferentiation(variable::y).getConstant();

	std::cout << "Initial Hessian Matrix : " << std::endl;
	std::cout << H[0] << " " << H[1] << std::endl;
	std::cout << H[2] << " " << H[3] << std::endl;

	processLogstream << "Initial Hessian Matrix : " << std::endl;
	processLogstream << "[" << std::endl;
	processLogstream << H[0] << " " << H[1] << std::endl;
	processLogstream << H[2] << " " << H[3] << std::endl;
	processLogstream << "]" << std::endl;

	//
	//step 1
	//

	//the iteration counter
	int i = 0, N = 10000;
	double* D = new double[2];

	//initial
	double* F = new double[4];
	F[0] = 1;
	F[1] = 0;
	F[2] = 0;
	F[3] = 1;

	double delta_max = 1.0e-8;
	Point2d p_pre = initPoint;
	double GValue[2] = { G[0].getValue(initPoint.x, initPoint.y) , G[1].getValue(initPoint.x, initPoint.y) };

	//
	//step 2
	//

	//起始就結束
	if ( std::abs(GValue[0]) + std::abs(GValue[1]) < delta_max) {
		std::cout << "G0 = " << std::abs(GValue[0] + GValue[1]) << std::endl;
		result = initPoint;
		std::cout << "剛開始就結束" << std::endl;
		processLogstream << "[X] = " << initPoint.toString() << std::endl;
		processLogstream << "min = " << f.getValue(initPoint.x, initPoint.y) << std::endl;
		*processLog = processLogstream.str();
		results.push_back(initPoint);
		return results;
	}

	while (std::abs(GValue[0]) + std::abs(GValue[1]) > delta_max) {

		D[0] = -1 * (F[0] * G[0].getValue(p_pre.x, p_pre.y) + F[1] * G[1].getValue(p_pre.x, p_pre.y));
		D[1] = -1 * (F[2] * G[0].getValue(p_pre.x, p_pre.y) + F[3] * G[1].getValue(p_pre.x, p_pre.y));

		//
		//step 3
		//

		std::vector<Expression> X_next;
		Expression temp_expression;
		temp_expression.add(variable(p_pre.x));
		temp_expression.add(variable(D[0], 1, 0));
		X_next.push_back(temp_expression);

		temp_expression.clear();

		temp_expression.add(variable(p_pre.y));
		temp_expression.add(variable(D[1], 1, 0));
		X_next.push_back(temp_expression);

		std::cout << "X_next[0] : " << X_next[0].toString() << std::endl;
		std::cout << "X_next[1] : " << X_next[1].toString() << std::endl;

		double alpha = goldenSectioner->goldenSectionSearch(-1.0e+18, 0, 1.0e+18, 1.0e-8, X_next);

		processLogstream << "alpha : " << std::endl;
		processLogstream << alpha << std::endl;
		processLogstream << std::endl;

		result.x = p_pre.x + alpha * D[0];
		result.y = p_pre.y + alpha * D[1];

		std::cout << "result point : " << std::endl;
		std::cout << " ( " << result.x << " , " << result.y << " ) " << std::endl;
		processLogstream << "x : " << std::endl;
		processLogstream << result.toString() << std::endl;
		processLogstream << std::endl;
		results.push_back(result);

		double deltaX[2], deltaG[2], FG[2];

		deltaX[0] = alpha * D[0];
		deltaX[1] = alpha * D[1];

		double GValue_next[2] = { G[0].getValue(result.x, result.y) , G[1].getValue(result.x, result.y) };

		deltaG[0] = GValue_next[0] - GValue[0];
		deltaG[1] = GValue_next[1] - GValue[1];

		FG[0] = F[0] * deltaG[0] + F[1] * deltaG[1];
		FG[1] = F[2] * deltaG[0] + F[3] * deltaG[1];

		double F_next_offset = 
			(deltaX[0] * deltaX[0] + deltaX[1] * deltaX[1]) / (deltaX[0] * deltaG[0] + deltaX[1] * deltaG[1]) -
			(FG[0] * FG[0] + FG[1] * FG[1]) / (deltaG[0] * FG[0] + deltaG[1] * FG[1]);

		F[0] += F_next_offset; 
		F[1] += F_next_offset;
		F[2] += F_next_offset;
		F[3] += F_next_offset;

		processLogstream << "F"<<i+1<< " : " << std::endl;
		processLogstream << result.toString() << std::endl;
		processLogstream << std::endl;

		GValue[0] = GValue_next[0];
		GValue[1] = GValue_next[1];

		p_pre = result;
	}

	processLogstream << "[X] = " << result.toString() << std::endl;
	processLogstream << "min = " << f.getValue(result.x, result.y) << std::endl;

	//std::cout << "processLogstream : " << std::endl << processLogstream.str() << std::endl;

	*processLog = processLogstream.str();
	return results;
}