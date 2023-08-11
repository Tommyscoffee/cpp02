#include "Point.hpp"

Point::Point() :_x(0), _y(0)
{
	std::cout << "Point default constructor" << std::endl;
}

Point::Point(const float f_x, const float f_y) :_x(f_x), _y(f_y)
{
	std::cout << "Point(const float) constructor" << std::endl;
}

Point::Point(const Point &obj)
{
	std::cout << "Point Copy constructor" << std::endl;
	this->_x = obj._x;
	this->_y = obj._y;
}

Point& Point::operator = (const Point &obj)
{
	std::cout << "opeartor = called" << std::endl;
	this->_x = obj._x;
	this->_y = obj._y;
	return (*this);
}