#include<stdio.h>
int main()
{
	long long b,i=2;
	scanf("%lld",&b);
	long long c[b],k=0;
	while(1)
	{
		if(zhi(i) == 0)
		{
			while(1)
			{
				if(b / i != 0)
					break
				else
				{
					b = b / i;
					c[k] = i;
					k++;
				}
			}
		}
		if(b < i)
			break;
		i++;
	}
}
int zhi( long long x)
{
	long long i;
	for(i=2; i<=sqrt(x); i++)
	{
		if(x % i == 0)
		{
			return 1;
		}
	}
	return 0;
}