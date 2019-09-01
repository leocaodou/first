#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
double fa(int a ,int b);
int main()
{
	int t,i;
	cin >> t;
	for(i = 1;i <= t;i++)
	{
		int a,b;
		double s = 1;
		cin >> a >> b;

		for(int j = t;j >= 2;j--)
		{
			s = s - fa(a,j);
		}
		printf("%.6lf",s);
	}
}
double fab(int a ,int b)
{
	if(b == a)
	{
		double c;
		c = 1.0/a;
		return c;
	}
	else
		return fa(a,b + 1) * (1.0 / b);
}