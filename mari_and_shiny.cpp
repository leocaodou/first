#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;160 140 30 20 10
int main()
{
	int n,i,x = 0,y = 0;
	cin >> n; 
	char a[n + 1];
	getchar();
	for(i = 0;i < n;i++)
	{
		a[i] = getchar();
		if(a[i] == 's')
			x++;
		if(a[i] == 'h')
			y++;

	}
	int Y[y] = {0},k = 0,l = 0,t = 0;
	long long s = 0;
	int f = 0;
	for(i = n -1;i >= 0;i--)
	{
		if(a[i] == 'y')
			l++;
		else
			if(a[i] == 'h')
			{
				Y[k] = l; 
				k++;
			}
			else
				if(a[i] == 's')
				{
					s = s * 2;
					for(int j = t;j < k;j++)
						s = s + Y[j]; 
					f++;
					t = k;
				}
		// if(k == y)
		// {
		// 	s = s + (x - f) * s;
		// 	break;
		// }
		if(f == x)
			break;
	}
	cout << s << endl;
	return 0;
}
