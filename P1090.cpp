#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
int a[80010];
int main()
{
	int n,x;
	cin >> n;
	memset(a , 0, sizeof(a));
	for(int i = 0 ;i < n;i++)
	{
			cin >> x;
			a[x]++;	
	}
	long long s = 0;
	int k = 0,p = 0,y = 0;
	for(int i = 1 ;i <= 60000;i++)
	{
		for(int j = 1;j <= a[i]; j++)
		{
			k++;
			p += i;
			if(k == 2)
			{
				y++;
				s += p;
				a[p]++;
				p = 0;
				k = 0;
			}
		}
	}
	cout << s << endl;
	return 0;
}