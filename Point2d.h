#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
public class Point2d
{
public:
	double x;
	double y;

	Point2d();
	Point2d(double pointx,double pointy);

	Point2d &operator=(Point2d p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	Point2d &operator+=(double d)
	{
		x += d;
		y += d;
		return *this;
	}

	Point2d &operator-=(double d)
	{
		x -= d;
		y -= d;
		return *this;
	}

	Point2d &operator+(Point2d p)
	{
		Point2d* p1 = new Point2d();

		p1->x = x + p.x;
		p1->y = y + p.y;
		return *p1;
	}

	Point2d &operator-(Point2d p)
	{
		Point2d* p1 = new Point2d();

		p1->x = x - p.x;
		p1->y = y - p.y;
		return *p1;
	}

	double norm();

	std::string toString();
};

