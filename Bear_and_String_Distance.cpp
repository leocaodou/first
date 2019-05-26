#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,s = 0,i;
	cin >> n >> k;
	char a[n];
	int d[n];
	scanf("%s",a);
	for(i = 0;i < n;i++)
	{
	 	d[i] = (122 - a[i]) > (a[i] -97)?(122 - a[i]) : (a[i] -97);
		s = s + d[i];
	}
	if(k > s)
	{
		cout << -1;
		return 0;
	}
	for(i = 0;i < n;i++)
	{
		if(k == 0)
		{
			printf("%c",a[i]);
			continue;
		}
		if(k - d[i] >= 0 && k != 0)
		{
			if(a[i] + d[i] == 122)
				printf("z");
			else
				printf("a");
			k = k - d[i];
		}
		else if(k - d[i] < 0 && k != 0)
			{
				if(a[i] + d[i] > 122)
				{
					char c = a[i] - k;
					printf("%c",c);
					k = 0;
				}
				else
				{
					char c = a[i] + k;
					printf("%c",c);
					k = 0;
				}
		}
	}
	return 0;
}
