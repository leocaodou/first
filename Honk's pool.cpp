#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int a[500000];
int main()
{
	int n,k,i,max1,y = 0,min1;
	long long s = 0,b,s2 = 0;
	cin >> n >> k;
	for(i = 0; i < n;i++)
	{
		scanf("%d",&a[i]);
		s += a[i];
	}
	b = s / n;
	if(b * n != s)
		y = 1;
	for(i = 0; i < n;i++)
	{
		s2 = s2 + labs(a[i] - b);
	}
	if(s2 / 2 < k)
	{
		if(y == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	sort(a,a + n);
	long long p = 0;
	for(i = 1; a[i] < b;i++)
	{
		if(a[i] != a[i - 1])
		{
			if(p + i * (a[i] - a[i - 1]) > k)
				break;
			else
				p = p + i * a[i] - a[i - 1];
		}
	}
	min1 =  a[i - 1] + (k - p) / i;
	p = 0;
	for(i = 1; a[n - i - 1] > b;i++)
	{
		if(a[n - i - 1] != a[n - i])
		{
			if(p + i * (a[n - i] - a[n - i - 1]) > k)
				break;
			else
				p = p + i * (a[n - i] - a[n - i - 1]);
		}
	}
	max1 =  a[n - i] - (k - p) / i;
	cout << max1 - min1 << endl;
}