#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float, const float);
		Point(const Point&);
		//Point(const int);
		//~Point();
};

Point::Point() : x(0), y(0) {}

Point::Point(const float param_x, const float param_y) : x(param_x), y(param_y) {}

Point::Point(const Point& param) : x(param.x), y(param.y) {}

#endif