#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class seat
{
public:
	int row = 0;
	int w;
	
};
bool cmp(seat x,seat y)
{
	if(x.w < y.w)
		return true;
	else
		return false;
}
int main()
{
	int n;
	cin >> n;
	seat a[n];
	int b[n] = {0};
	for(int i = 1;i <= n;i++)
	{
		a[i - 1].row = i;
		cin >> a[i - 1].w;
	}
	getchar();
	sort(a,a + n,cmp);
	int k = 0,t = 0;
	for(int i = 1;i <= 2*n;i++)
	{
		char x;
		x = getchar();
		if(x == '0')
		{
			printf("%d ",a[k].row);
			b[t] = a[k].row;
			k++;
			t++;
		}
		if(x == '1')
		{
			printf("%d ",b[t - 1]);
			t --;
		}
	}
	return 0;
}
