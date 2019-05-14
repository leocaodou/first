#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,m,k,i;
	cin >> n >> m >> k;
	int a[n];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	i = 1;
	while(1)
	{
		if(m - i >= 1)
		{
			if(a[m - i - 1] <= k && a[m - i - 1] != 0)
			{
				cout << i * 10;
				break;
			}
		}
		if(m + i <= n )
		{
			if(a[m + i - 1] <= k && a[m + i - 1] != 0)
			{
				cout << i * 10;
				break;
			}
		}
		i++;
	}
	return 0;
}