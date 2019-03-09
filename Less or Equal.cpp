#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	long long n,k,i,t,j;
	scanf("%lld%lld",&n,&k);
	long long a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(k==n)
	{
		printf("1000000000");
		return 0;
	}
	sort(a,a+n);
	if(k==0)
	{
		if(a[0]>1)
			printf("%lld",a[0]-1);
		else
			printf("-1");
		return 0;
	}
	if(a[k-1]==a[k])
		printf("-1");
	else
		printf("%lld",a[k-1]);
	return 0;
}
