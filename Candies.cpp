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
	long long n,Min,Max,a = 0,b = 0,k;
	cin >> n;
	Max = n;
	Min = 0;
	k = (Max + Min ) / 2;
	while(1)
	{
		k = (Max + Min ) / 2;
		a = 0;
		b = 0;
		if(Max == (Min + 1))
		{
			cout << Max;
			break;
		}
		long long w = n;
		while(w)
		{
			if(w <= k)
			{
				a += w;
				w = 0;
			}
			else
			{
				a += k;
				w = w - k;
			}
			b += w / 10;
			w = w- w / 10;
		}
		if(a > b)
		{
			Max = k;
		}
		if(a < b)
		{
			Min = k;
		}
		if(a == b || Max == Min )
		{
			cout << k;
			break;
		}
	}
	return 0;
}
