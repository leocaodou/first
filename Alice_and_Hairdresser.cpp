#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include<vector>
using namespace std;
long long v[100000 + 10];
int main()
{
	int n,m,l,k = 0;
	cin >> n >> m >> l;
	for(int i = 1;i <= n; i++)
	{
		cin >> v[i];
		if(v[i] > l && v[i - 1] <= l && i > 1)
			k++;
		if(i == 1&& v[i] > l)
			k++;
	}
	while(m--)
	{
		int t;
		cin >> t;
		if(!t)
		{
			cout << k << endl;
		}
		else
		{
			int p,d,x = 0;
			cin >> p >> d; 
			if(v[p] + d > l && v[p] <= l)
			{
				if(p - 1 > 0 && v[p - 1] > l)
					x++;
				if(p + 1 <= n && v[p + 1] > l)
					x++;
				if(p == 1&& v[2] <= l && n >= 2)
					k++;
				if(p == n&& v[n - 1] <= l && n >= 2)
					k++;
				if(x == 2)
					k--;
				if(x == 0 && p != 1 && p != n)
					k++;
				if(n == 1)
					k++;
			}
			v[p] += d;
		}
	}
	return 0;
}