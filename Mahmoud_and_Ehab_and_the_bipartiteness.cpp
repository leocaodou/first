#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int n,u,v,p = 0,q = 0;
	long long s = 0;
	cin >> n;
	int a,b,c[n] = {0};
	cin >> u >> v;
	b = v;
	a = u;
	c[p]++;
	for(int i = 0;i < n - 2;i ++)
	{
		cin >> u >> v;
		if(a == u)
		{
			q++;
			b = v;
			c[p]++;
		}
		else if(b == u)
		{
			p++;
			a = v;
			c[p]++;
		}
		else if(a == v)
		{
			q++;
			b = u;
			c[p]++;
		}
		else if(b == v)
		{
			p++;
			a = u;
			c[p]++;
		}
	}
	cout << (p + 1) * (q + 1) - n + 1;
	return 0;
}