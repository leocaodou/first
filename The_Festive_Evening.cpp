#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	getchar();
	int a[26][2]= {0};
	char c[n + 1];
	for(int i = 0;i < n;i++ )
	{
		char b;
		b = getchar();
		c[i] = b;
		a[b - 65][0] = i;
	}
	int j = 0;
	int i = 0;
	for( i = 0;i < n ;i++)
	{
		if(a[int(c[i]) - 65][1] == 0)
		{
			j++;
			a[int(c[i]) - 65][1] = 1;
		}
		if(j > k)
		{
			cout << "YES";
			return 0;
		}
		if(a[int(c[i]) - 65][1] == 1)
		{
			if(a[int(c[i]) - 65][0] == i)
			{
				j--;
				a[int(c[i]) - 65][1] = 0;
			}
		}
		
	}
	cout << "NO";
	return 0;
}
