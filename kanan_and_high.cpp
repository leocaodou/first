#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,a,b,s = 1,max = 0;
	cin >> n;
	cin >> a;
	for(i = 1; i < n; i++)
	{
		cin >> b;
		if(b - a <= 8)
			s++;
		else
		{
			if(s > max)
				max = s;
			s = 1;
		}
		a = b;
	}
	if(s > max)
		max = s;
	cout << max;
	return 0;
}