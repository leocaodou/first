#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
char b[200000 + 10];
int main()
{
	int n,x[26] = {0},sum = 0,max = 0,k = 0,p = -1;
	cin >> n;
	string a;
	cin >> a;
	for(int i = 0;i < n;i++)
	{
		x[a[i] - 97]++;
	}
	for(int i = 25;i >= 0;i--)
	{
		if(x[i] % 2 == 0)
		{
			sum += x[i]/2;
			for(int j = 0;j < x[i]/2;j++)
			{
				b[k] = (char)(97+i);
				k++;
			}
		}
		else
		{
			sum += (x[i] - 1)/2;
			for(int j = 0;j < (x[i]-1)/2;j++)
			{
				b[k] = (char)(97+i);
				k++;
			}
			if(p == -1)
				p = i;
		}
	}
	printf("%d\n",sum*2 + 1);
	for(int i = 0;i < sum;i++)
		printf("%c",b[i]);
	printf("%c",(char)(97+p));
	for(int i = sum - 1;i >= 0;i--)
		printf("%c",b[i]);
	return 0;
}
