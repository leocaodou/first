#include<stdio.h>
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
	if(k<=n/2)
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		if(i==k)
			break;
	}
	if(k>n/2)
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(a[j]>a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
		if(i==n-k)
			break;
	}
	if(k==0)
	{
		if(a[n-1]>1)
			printf("%lld",a[n-1]-1);
		else
			printf("-1");
		return 0;
	}
	if(a[n-k]==a[n-k-1])
		printf("-1");
	else
		printf("%lld",a[k-1]);
	return 0;
}
