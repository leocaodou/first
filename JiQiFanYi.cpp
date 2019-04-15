#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int m,n,i,x = 0,j = 0,z,k,p = 0;
	cin >> m >> n;
	int a[m];
	for(i = 0;i < n;i++)
	{
		cin >> z;
		if(i + 1 < m && p ==0)
		{
			int y = 0;
			for(k = 0;k < x;k++)
			{
				if(a[k] == z)
				{
					y = 1;
					break;
				}
			}
			if(y == 0)
			{
				a[x] = z;
				if(x == m - 1)
				{
					p = 1;
					x = 0;
				}
				else
				{
					x++;
				}
				j++;
			}
		}
		else
		{
			int y = 0;
			for(k = 0;k < m;k++)
			{
				if(a[k] == z)
				{
					y = 1;
					break;
				}
			}
			if(y == 0)
			{
				a[x] = z;
				if(x == m -1)
				{
					x = 0;
				}
				else
				{
					x++;
				}
				j++;
			}
		}
	}
	cout << j;
	return 0;
}