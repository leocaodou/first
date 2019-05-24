#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,m,min2,min1 = 1000,i,j;
	cin >> n >> m;
	char a[n],b[m];
	cin >> a >> b;
	int c[m-n+1][n];
	for(i = 0;i <= m - n;i++)
	{
		int s = 0;
		int x = 0;
		for(j = 0; j < n;j++)
		{
			if(a[j] != b[j + i])
			{
				c[i][s] = j + 1;
				s++;
				if(s > min1)
				{
					x = 1;
					break;
				}
			}
		}
		if( x == 1)
			continue;
		min1 = s;
		min2 = i;
		if(s == 0)
			break;
	}
	cout << min1 << endl;
	for(i = 0;i < min1;i++)
		cout << c[min2][i] << ' ';
	return 0;
}