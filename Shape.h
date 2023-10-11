#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

#include <string>
#include "Point2D.h"

class Shape{
	protected:
		string color;
	
	public:
		Shape();
		Shape(string color);
		string get_color() const;
		void set_color(string c);
		virtual double area() const;
		virtual double perimeter() const;
		virtual void translate(double incX, double incY);
		virtual void print();
};

#endif
