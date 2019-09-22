#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	int a[n];
	for(i = 0;i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0; i < n; i++)
	{
		int b[n] = {0};
		int x = i;
		while(1)
		{
			b[x]++;
			x = a[x] - 1;
			if(b[x] == 2)
				break;
		}
		cout << x + 1 << ' ';
	}
	return 0;
}