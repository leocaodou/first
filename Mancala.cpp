#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	long long a[14],i,j;
	long long max = 0;
	for(i = 0;i < 14;i++)
		cin >> a[i];
	for(i = 0;i < 14;i++)
	{
		long long k,w,l;
		long long s = 0;
		if(a[i] == 0)
			continue;
		if(14 - i - 1 >= a[i])
		{
			for(j = i + 1;j < a[i];j++)
			{
				if(a[j] % 2)
					s = s + a[j] + 1;
			}
		}
		else
		{
			k = a[i] - (14 - i - 1);
			w = k / 14;
			l = k % 14;
			for(j = 0;j < l;j++)
			{
				if(i == j && (w + 1) % 2 == 0)
				{
						s = s + w + 1;
						continue;
				}
				if((a[j] + w + 1) % 2 == 0 && j < i)
					s += a[j] + w + 1;
				if((a[j] + w + 2) % 2 == 0 && j > i)
					s += a[j] + w + 2;
			}
			for(j = l;j < 14;j++)
			{
				if(i == j && w % 2 == 0)
				{
						s = s + w;
						continue;
				}
				if((a[j] + w) % 2 == 0 && j < i)
					s += a[j] + w;
				if((a[j] + w + 1) % 2 == 0 && j > i)
					s += a[j] + w + 1;
			}
		}
		if( s > max)
			max = s;
	}
	printf("%lld",max);
	return 0;
}
