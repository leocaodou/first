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
	int n,k = 0;
	cin >> n;
	char s[n + 10];
	int a[n + 10] ={0},sum[n + 10]={0},x[n + 10]={0};
	cin >> (s + 1);
	if(s[1] == '0')
	{
		a[1] = -1;
	}
	else
		a[1] = 1;
	sum[0] = 0;
	sum[1] = a[1];
	x[sum[1]] = 1;
	for(int i = 2;i <= n;i++)
	{
		if(s[i] == '0')
		{
			a[i] = -1;
		}
		else
			a[i] = 1;
		sum[i] = sum[i - 1] + a[i];
		x[sum[i]] = i;
	}
	for(int i = 0;i <= n;i++)
	{
		if(x[sum[i]] - i >= k)
			k = x[sum[i]] - i;
	}
	cout << k;
	return 0;
}