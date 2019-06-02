#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	long long n,k,i,s = 0;
	cin >> n >> k;
	int a[11] = {0},b[11] = {0},c = 0;
	for( i = 0; i < n;i++)
	{
		int x;
		cin >> x;
		if(x == 100)
		{
			s = s + 10;
			continue;
		}
		if(x > 90)
			b[(x/10+1)*10-x]++;
		else
		{
			a[(x/10+1)*10-x]++;
			c = 9 - x/10 + c;
		}
		s = s + x/10;
	}
	for(i = 1;i < 10 ;i++)
	{
		if(k - a[i] * i < 0)
		{
			s = k / i + s;
			k = 0;
			break;
		}
		s = a[i] * i + s;
		k = k - a[i] * i;
		if(k - b[i] * i < 0)
		{
			s = k / i + s;
			k = 0;
			break;
		}
		s = b[i] * i + s;
		k = k - b[i] * i;
	}
	if(k / 10 > c)
		s = c + s;
	else
		s = k / 10 + s;
	cout << s;
	return 0;
}