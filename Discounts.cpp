#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i;
	scanf("%d",&n);
	long long a[n]={0};
	long long s=0,x;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		s=s+a[i];
	}
	sort(a,a+n);
	scanf("%d",&m);
	long long b[m];
	for(i=0;i<m;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(i=0;i<m;i++)
	{
		x=s;
		x=x-a[n-b[i]];
		printf("%lld\n",x);
	}
	return 0;
}