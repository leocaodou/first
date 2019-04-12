#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,t,i,sum = 0,d = 0,x = 0;
	cin >> n >> t;
	int a[n];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
		if(x == 0)
		{
			sum = sum + (86400 - a[i]);
			d++;
		}
		if(sum >= t)
			x = d;
	}
	printf("%d",x);
	return 0;
}