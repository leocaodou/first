#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,m,i,j = 0;
	cin >> n >> m;
	int a[n];
	char b[n][11];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
		scanf("%s",b[i]);
	}
	int c[m][2];
	for(i = 0;i < m;i++)
	{
		cin >> c[i][0] >> c[i][1];
		if(a[j] == 0)
		{
			if(c[i][0] == 0)
			{
				j = j - c[i][1];
				if(j < 0)
					j = n + j;
			}
			else
			{
				 j = j + c[i][1];
				 if(j >= n)
				 	j= j % n;
			}
		}
		else
		{
			if(c[i][0] == 0)
			{
				j = j + c[i][1];
				if(j >= n)
					j = j % n;
			}
			else
			{
				 j = j - c[i][1];
				 if(j < 0)
				 	j= n + j;
			}
		}
	}
	cout << b[j];
	return 0;
}
