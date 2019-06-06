#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class point
{
public:
	int x;
	int y;
	point(int a = 0,int b = 0) : x(a),y(b){}
	ponit(const point& r) : x(r.x),y(r.y){}
};
class Rectangles
{
public:
	point a;
	point b;
	Rectangles(int x1 = 0,int y1 = 0 ,int x2 = 0,int y2 = 0) : a(x1,y1),b(x2,y2){}
	Rectangles(point _a,point _b) : a(_a),b(_b){}
	Rectangles operator+ (const Rectangles& rect)
	{
		if(b.x > rect.a.x && b.x < rect.b.x && b.y > rect.a.y && b.y < rect.b.y)
		{
			if(a.x > rect.a.x && a.x < rect.b.x && a.y > rect.a.y && a.y < rect.b.y)
				return *this;
			else
				return Rectangles(rect.a, b);
		}
		if(a.x > rect.a.x && a.x < rect.b.x && a.y > rect.a.y && a.y < rect.b.y)
		{
			if(b.x > rect.a.x && b.x < rect.b.x && b.y > rect.a.y && b.y < rect.b.y)
				return *this;
			else
				return Rectangles(a, rect.b);
		}
		return 0;
	}
};
int main()
{
	int n,i;
	cin >> n;
	int a,b,c,d;
	Rectangles f[n];
	Rectangles x,y;
	int t = 0;
	cin >> a >> b >> c >> d;
	f[0] = Rectangles(a,b,c,d);
	for( i = 1; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		f[i] = Rectangles(a,b,c,d);
		x = f[i] + f[i - 1];
		if( x == 0)
			t++;

	}
	return 0;
}