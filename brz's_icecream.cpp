#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int c[2000005];
int main()
{
	long long n,k,q,x,y;
	cin >> n >> k >> q;
	cin >> x;
	c[0] = 1;
	for(int i = 1;i < n;i++)
	{
		cin >> y;
		if(y != x)
			c[i] = c[i - 1]+1;
		else
			c[i] = c[i - 1];
		x = y;
	}
	for(int i = 0;i < q;i++)
	{
		int a, b;
		cin >> a >> b;
		if(c[b-1] - c[a-1] +1 >= k)
			printf("YES %d\n");
		else
			printf("NO %d\n");
	}
}