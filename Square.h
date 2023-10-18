#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Square{
	private:
		static bool check(Point2D* vertices);
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices);
		friend ostream& operator<<(ostream &out, const Square &square);
};

#endif
