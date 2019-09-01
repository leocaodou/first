#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t,i;
	cin >> t;
	for(i = 1;i <= t;i++)
	{
		int n,m;
		cin >> n >> m;
		char a[n+1],b[n+1],c[m+1];
		cin >> a;
		cin >> b;
		int x = a[0] - b[0];
		// if(a[1] - b[1] != x)
		// {
		// 	x = b[0] - a[0];
		// }
		cin >> c;
		cout << "Case #" << i << ": ";
		for(int j = 0;j < m;j++)
		{
			char y;
			if(c[j] + x > 90)
			{
				y = c[j] + x - 26;
				cout << y;
				continue;
			}
			if(c[j] + x < 65)
			{
				y = c[j] + x + 26;
				cout << y;
				continue;
			}
			y = c[j] + x;
			cout << y;
		}
		cout << '\n';
	}
	return 0;
}
