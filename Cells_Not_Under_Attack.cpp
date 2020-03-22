#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int main()
{
	long long n,m,r,c,k = 1;
	cin >> n >> m;
	r = n;
	c = n;
	int X[n + 1] = {0},Y[n + 1] = {0};
	long long s = n * n;
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		if(X[x] || Y[y])
		{
			if(X[x] && Y[y])
			{
				s = s;
			}
			else if(X[x])
				{
					s = s - c;
					if(r > 0)
						r--;
				}
				else
				{
					s = s - r;
					if(c > 0)
						c--;
				}

		}
		else
		{
			s = s - r - c + 1;
			if(r > 0)
				r--;
			if(c > 0)
				c--;
		}
		if(s > 0 && k)
		{
			cout <<	s << ' ';
		}
		else
		{
			cout << 0 << ' ';
			k = 0;
		}
		X[x] = 1;
		Y[y] = 1;
	}
	return 0;
}