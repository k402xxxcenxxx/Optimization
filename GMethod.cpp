#include "GMethod.h"



CGMethod::CGMethod()
{

}

//Conjugate Gradient Methods 
std::vector<Point2d> CGMethod::CG(Expression f, Point2d initPoint, std::string* processLog, double maxValueX, double minValueX, double maxValueY, double minValueY) {
	std::ostringstream processLogstream;

	Point2d result;
	powellMethod *goldenSectioner = new powellMethod(f);

	//f 的 斜率
	//  ^
	//	a: differential by x
	//  b: differential by y
	//  v
	std::vector<Expression> gradientF;
	gradientF.push_back(f.PartialDifferentiation(variable::x));
	gradientF.push_back(f.PartialDifferentiation(variable::y));
	std::cout << "gradientF : " << std::endl;
	std::cout << gradientF[0].toString() << std::endl;
	std::cout << gradientF[1].toString() << std::endl;

	//F gradient 's transpose
	//<a b>
	std::vector<Expression> gradientF_t;
	gradientF_t.push_back(gradientF[0]);
	gradientF_t.push_back(gradientF[1]);
	std::cout << "gradientF t: " << std::endl;
	std::cout << gradientF_t[0].toString() << std::endl;
	std::cout << gradientF_t[1].toString() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	//
	//step 1
	//

	//the iteration counter
	int i = 0, N = 10000;
	
	//the storage structure
	std::vector<double> fs;
	std::vector<Point2d> xs;

	xs.push_back(initPoint);
	fs.push_back(f.getValue(initPoint.x, initPoint.y));
	std::cout << "fs : " << f.getValue(xs[0].x, xs[0].y) << std::endl;
	std::cout << "xs : (" << xs[0].x << "," << xs[0].y << ")" << std::endl;

	//the tolerance
	double t1 = 1.0e-18, t2 = 1.0e-18, t3 = 1.0e-18;

	//
	//step 2
	//


	//the S
	double Si[2], Si_1[2];

	Point2d S, S_pre;

	for (i = 0; i < N; i++) {

		std::cout << "step : " << i << std::endl;
		processLogstream << "i = " << i << std::endl;
		
		if (i == 0) {
			S = Point2d(-1 * gradientF[0].getValue(initPoint.x, initPoint.y), - 1 * gradientF[1].getValue(initPoint.x, initPoint.y));
		}
		else {
			double b = ((gradientF_t[0].getValue(xs[i].x, xs[i].y) * gradientF[0].getValue(xs[i].x, xs[i].y)) + (gradientF_t[1].getValue(xs[i].x, xs[i].y) * gradientF[1].getValue(xs[i].x, xs[i].y))) 
					 / ((gradientF_t[0].getValue(xs[i-1].x, xs[i-1].y) * gradientF[0].getValue(xs[i-1].x, xs[i-1].y)) + (gradientF_t[1].getValue(xs[i - 1].x, xs[i - 1].y) * gradientF[1].getValue(xs[i - 1].x, xs[i - 1].y)));

			std::cout << "B =  " << b << std::endl;

			S = Point2d(-1 * gradientF[0].getValue(xs[i].x, xs[i].y), -1 * gradientF[1].getValue(xs[i].x, xs[i].y)) + Point2d(b * S_pre.x,b * S_pre.y);
		}

		std::cout << "S =  " << S.toString() << std::endl;
		processLogstream << "S"<<i<<" = " << S.toString() << std::endl;

		//get f(xi+1) = f(xi + a*s)
		std::vector<Expression> X_next;// xi + a*s
		variable tmp_const, tmp_coeff;

		Expression temp_expression;
		temp_expression.add(variable(xs[i].x));
		temp_expression.add(variable(S.x,1,0));
		X_next.push_back(temp_expression);

		temp_expression.clear();

		temp_expression.add(variable(xs[i].y));
		temp_expression.add(variable(S.y,1, 0));
		X_next.push_back(temp_expression);

		std::cout << "X_next[0] : " << X_next[0].toString() << std::endl;
		std::cout << "X_next[1] : " << X_next[1].toString() << std::endl;

		double alpha = goldenSectioner->goldenSectionSearch(-1.0e+18,0,1.0e+18, 1.0e-8, X_next);
		std::cout << "alpha : " << alpha << std::endl;
		processLogstream << "alpha = " << alpha << std::endl;

		processLogstream << "X"<<i<<" = " << xs[i].toString() << std::endl;

		Point2d newX = Point2d(xs[i].x + alpha * S.x, xs[i].y + alpha * S.y);
		if (maxValueY == minValueY) {//代表只要檢查X即可
			if (maxValueX != minValueX) {//代表有設X範圍
				if (newX.x < minValueX || newX.x > maxValueX) {//超出範圍
					double valueUpperBound = f.getValue(maxValueX);
					double valueBottomBound = f.getValue(minValueX);

					if (valueUpperBound > valueBottomBound) {
						xs.push_back(Point2d(minValueX,0));
						fs.push_back(valueBottomBound);
					}
					else {
						xs.push_back(Point2d(maxValueX, 0));
						fs.push_back(valueUpperBound);
					}

					result = xs[i + 1];
					break;
				}
			}
		}
		else {
			if (maxValueX != minValueX) {//代表有設X範圍
				if (newX.x < minValueX || newX.x > maxValueX || newX.y < minValueY || newX.y > maxValueY) {//超出範圍
					double valueUpperBound1 = f.getValue(maxValueX, minValueY);
					double valueUpperBound2 = f.getValue(maxValueX, maxValueY);
					double valueBottomBound1 = f.getValue(minValueX, minValueY);
					double valueBottomBound2 = f.getValue(minValueX, maxValueY);


					if (valueUpperBound1 < valueUpperBound2 && valueUpperBound1 < valueBottomBound1 && valueUpperBound1 < valueBottomBound2) {
						xs.push_back(Point2d(maxValueX, minValueY));
						fs.push_back(valueUpperBound1);
					}
					else if(valueUpperBound2 < valueUpperBound1 && valueUpperBound2 < valueBottomBound1 && valueUpperBound2 < valueBottomBound2){
						xs.push_back(Point2d(maxValueX, maxValueY));
						fs.push_back(valueUpperBound2);
					}
					else if (valueBottomBound1 < valueUpperBound1 && valueBottomBound1 < valueUpperBound2 && valueBottomBound1 < valueBottomBound2) {
						xs.push_back(Point2d(minValueX, minValueY));
						fs.push_back(valueBottomBound1);
					}
					else {
						xs.push_back(Point2d(minValueX, maxValueY));
						fs.push_back(valueBottomBound2);
					}

					result = xs[i + 1];
					break;

				}
			}
		}
		
		//xs.push_back(Point2d(X_next[0].getValue(alpha), X_next[1].getValue(alpha)));
		//fs.push_back(f.getValue(xs[i + 1].x, xs[i + 1].y));

		xs.push_back(newX);
		fs.push_back(f.getValue(xs[i + 1].x, xs[i + 1].y));

		std::cout << "fs : " << f.getValue(xs[i + 1].x, xs[i + 1].y) << std::endl;
		std::cout << "xs : " << xs[i + 1].toString() << std::endl;

		S_pre = S;

		Point2d gradientF_Xnext = Point2d(gradientF[0].getValue(xs[i + 1].x, xs[i + 1].y), gradientF[1].getValue(xs[i + 1].x, xs[i + 1].y));
		result = xs[i+1];

		if (i >= 0) {
			std::cout << "i + 1 = " << fs[i + 1] << ", i = " << fs[i] << std::endl;
			if (std::abs(fs[i+1] - fs[i])<= t1) {
				
				std::cout << "t1" << std::endl;
				break;
			}


			Point2d deltaX = xs[i+1] + xs[i];
			if (pow(deltaX.x, 2) + pow(deltaX.y, 2) <= t2) {
				std::cout << "t2" << std::endl;
				break;
			}


			if (pow(gradientF_Xnext.x, 2) + pow(gradientF_Xnext.y, 2) <= t3) {
				std::cout << "t3" << std::endl;
				break;
			}

		}

		//std::cout << std::endl;
		//std::cout << std::endl;

		processLogstream << std::endl; 
		processLogstream << std::endl;
	}
	std::cout << "result : (" << result.x <<","<< result.y<<")" << std::endl;

	processLogstream << "[X] = " << result.toString() << std::endl;
	processLogstream << "min = " << f.getValue(result.x, result.y) << std::endl;

	//std::cout << "processLogstream : " << std::endl << processLogstream.str() << std::endl;

	*processLog = processLogstream.str();
	return xs;
}