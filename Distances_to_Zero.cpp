#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,i,k = 1;
	cin >> n;
	int a[n];
	int y = 0;
	for(i = 0;i < n; i++)
	{
		cin >> a[i];
		if(y == 1)
			if(a[i] != 0 )
			{
				a[i] = k;
				k++;
			}
			else
				k = 1;
		if(y == 0)
			if(a[i] == 0)
				y = 1;
			else
				a[i] = -1;
			
	}
	y = 0;
	for(i = n -1; i >= 0;i--)
	{
		if(a[i] == 0)
		{
			y = 1;
			k = 1;
		}
		if(y == 1)
			if(a[i] == 0)
			{
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
