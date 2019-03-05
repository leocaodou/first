#include<stdio.h>
int main()
{
	long long n,k;
	scanf("%lld%lld",&n,&k);
	while(k)
	{
		if(n%10>0)
		{
			n--;
			k--;
			continue;
		}
		else
		{
			n=n/10;
			k--;
		}
	}
	printf("%lld",n);
	return 0;
} 
