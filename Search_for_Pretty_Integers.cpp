#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,m,min1 = 10,min2 = 10,i;
	cin >> n >> m;
	int a[n],b[m],c[10][2] = {0};
	for(i = 0;i < n; i++)
	{
		cin >> a[i];
		if(a[i] < min1)
			min1 = a[i];
		c[a[i]][0] = 1; 
	}
	for(i = 0;i < m; i++)
	{
		cin >> b[i];
		if(b[i] < min2)
			min2 = b[i];
		c[b[i]][1] = 1; 
	}
	for(i = 1;i <= 9; i++)
	{
		if(c[i][0] == 1&&c[i][1] == 1)
		{
			cout << i;
			return 0;
		}
	}
	if(min1 == min2)
	{
		cout << min1;
		return 0;
	}
	if(min1 < min2)
	{
		cout << min1 << min2;
		return 0;
	}
	if(min1 > min2)
	{
		cout << min2 << min1;
		return 0;
	}
}