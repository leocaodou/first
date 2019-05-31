#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Point2D{
	double x, y;
public:
	Point2D(double _x = 0., double _y = 0.) : x(_x), y(_y) {}
	double getX() const
	{
		return x;
	}
	double getY() const
	{
		return y;
	}
	void setX( double _x)
	{
		x = _x;
	}
	void setY( double _y)
	{
		y = _y;
	}
	Point2D& operator= (const Point2D& a)
	{
		x = a.getX();
		y = a.getY();
		return *this;
	}
	friend ostream& operator << (ostream & , const Point2D& );
};
class Rectangle {
	Point2D topLeft, rightBottom;
public:
	Rectangle(double x1,double y1,double x2,double y2)
	{
		topLeft.setX(x1 < x2?x1 : x2);
		topLeft.setY(y1 > y2?y1 : y2);
		rightBottom.setX(x1 > x2?x1 : x2);
		rightBottom.setY(y1 < y2?y1 : y2);
	}
	Rectangle(const Point2D& a,const Point2D& b)
	{
		topLeft.setX(a.getX() < b.getX()?a.getX() : b.getX());
		topLeft.setY(a.getY() > b.getY()?a.getY() : b.getY());
		rightBottom.setX(a.getX() > b.getX()?a.getX() : b.getX());
		rightBottom.setY(a.getY() < b.getY()?a.getY() : b.getY());
	}
	Point2D getTopLeftCorner( ) const
	{
		return topLeft;
	}
	double getWidth() const
	{
		return rightBottom.getX() - topLeft.getX();
	}
	double getHeight() const
	{
		return topLeft.getY() - rightBottom.getY();
	}
	friend ostream& operator << (ostream & out, const Rectangle& rect);
};
	ostream& operator << (ostream & out, const Rectangle& rect)
	{
		out << "Top-Left Corner:" << rect.getTopLeftCorner();
		out << "Width:" << rect.getWidth() << " Height:" << rect.getHeight() << '\n';
		return out;
	}
	ostream& operator << (ostream & out, const Point2D& a)
	{
		out << a.getX() << ' ' <<  a.getY() << '\n';
		return out;
	}
int main()
{
	double x1,x2,y1,y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	Rectangle rect(x1,y1,x2,y2);
	cout << rect;
	Rectangle rect1(Point2D(y2,x2),Point2D(x1,y1));
	cout << rect1;
	return 0;
}