#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,i,k = -1;
	cin >> n;
	int a[n];
	for(i = 0;i < n; i++)
	{
		cin >> a[i];
		if(a[i] != 0 )
		{
			a[i] = k;
			k++;
		}
		else
			k = 1;
	}
	int y = 0;
	for(i = n -1; i >= 0;i--)
	{
		if(y == 0)
			continue;
		if(a[i] == 0)
		{
			y = 1;
			k = 1;
		}
		else
		{
			if(k < a[i] || a[i] == -1)
				a[i] = k;
			k++;
		}
	}
	for(i = 0;i < n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}