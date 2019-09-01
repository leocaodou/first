#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int ci(int x)
{
	int c;
	c = (-1 + sqrt(1 + 4 * 1 * (2 * x))) / 2;
	if(c != ((-1 + sqrt(1 + 4 * 1 * (2 * x))) / 2))
		c ++;
	return c;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		long long s = 0;
		int n;
		cin >> n;
		int y[n];
		for(int j = 0;j < n;j++)
		{
			int a,b,c;
			cin >> a >> b;
			c = ci(a);
			y[j] = b / c;
			s = s + b;
		}
	}
}