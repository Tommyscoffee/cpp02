#include <iostream>
#include <string.h>

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point &obj);
		~Point();

		Point& operator = (const Point &obj);
}

bool bsp( Point const a, Point const b, Point const c, Point const point);