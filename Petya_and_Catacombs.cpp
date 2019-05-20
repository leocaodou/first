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
		if( a[i] == i)
		{
			j++;
		}
	}
	cout << j;
	return 0;
}