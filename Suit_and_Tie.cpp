#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class c
{
public:
	int a;
	int b;
	c() : a(0),b(0){}
	int getD()
	{
		return b - a - 1;
	}
};
int main()
{
	int n,s = 0,t = 0,i;
	cin >> n;
	c a[n + 1];
	for(i = 1;i <= 2*n ; i++)
	{
		int x;
		cin >> x;
		if(a[x].a == 0)
			a[x].a = i;
		else
			a[x].b = i;
	}
	for(i = 1;i <= n ; i++)
	{
		s = s + a[i].getD();
	}
	for(i = 1;i <= n ; i++)
	{
		int j;
		for(j = 1;j <=  n ; j++)
		{
			if(a[j].a > a[i].a && a[j].a < a[i].b && a[j].b > a[i].b )
				t++;
			if(a[j].b > a[i].a && a[j].b < a[i].b && a[j].a < a[i].a )
				t++;
		}
	}
	s = s - t/2;
	cout << s;
	return 0;
}
