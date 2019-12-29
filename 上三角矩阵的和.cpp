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
	int m,n,i,j;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		int a[n+1];
		a[0] = 0;
		long long s =0,ans= 0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			s += a[j];
		}
		for(j=1;j<=n;j++)
		{
			s = s - a[j - 1];
			ans = ans + s * a[j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
