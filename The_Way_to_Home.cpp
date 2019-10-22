#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int main()
{
	int n,d;
	cin >> n >> d;
	string a;
	cin >> a;
	if(a[n - 1] == '0' || a[0] == '0')
	{
		cout << -1 << endl;
		return 0;
	}
	int k = 0,x = 0;
	while(1)
	{
		int p = 0;
		for(int i = 0;i < d;i++)
		{
			if(a[k + d - i] == '1')
			{
				k = k + d - i;
				p = 1;
				x++;
				break;
			}
		}
		if( p == 0)
		{
			cout << -1;
			return 0;
		}
		if(k == n - 1)
		{
			cout << x;
			return 0;
		}
	}
	return 0;
}