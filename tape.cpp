#include<stdio.h>
int main()
{
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	long long a[n],b[n-1];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(i!=0)
			b[i-1]=a[i]-a[i-1]+1;
	}
	if(n==k)
	{
		printf("%lld",n);
		return 0;
	}
	if(k==1)
	{
		printf("%lld",a[n]-a[0]+1);
		return 0;
	}
	
} 
