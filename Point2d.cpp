#include "Point2d.h"
Point2d::Point2d()
{

}

Point2d::Point2d(double pointx, double pointy) {
	x = pointx;
	y = pointy;
}

std::string Point2d::toString() {
	std::ostringstream strs;
	strs << std::fixed << "( " << std::setprecision(7) << x << " , " << std::setprecision(7) << y << ")"<<std::endl;
	return strs.str();
}

double Point2d::norm() {
	return std::sqrt(x*x + y*y);
}
