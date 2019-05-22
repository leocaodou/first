#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i,j = 1;
	cin >> n;
	int a[n];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int x = 0;
	for(i = 0;i < n;i++)
	{
		if( a[i] == i && x == 0)
		{
			j++;
		}
		else
		{
			x = 1;
			if(a[i] == a[i - 1] && a[i - 1] != i - 1)
			{
				j++;
				if( a[i + 1] == i + 1)
					j++;
				i++;
			}
		}
	}
	cout << j;
	return 0;
}