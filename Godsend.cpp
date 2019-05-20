#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i,j = 0,k = 0;
	cin >> n;
	int a[n];
	for(i = 0;i < n;i++)
	{
		int b;
		cin >> b;
		if(b % 2 == 0)
		{
			a[i] = 0;
			j++;
		}
		else
		{
			a[i] = 1;
			k++;
		}
	}
	if(k != 0)
	{
		cout << "First";
		return 0;
	}
	else
		cout << "Second";
	return 0;
}