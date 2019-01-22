#include<stdio.h>
int main()
{
	while(1)
	{
		long long a,x,y,z,s=0,p=0,q=0;
		scanf("%lld",&a);
		x=a;
		y=a;
		z=a;
		if(a==0)
		{
			break;
		}
		while(x)
		{
			s=s+x%10;
			x=x/10;
		}
		while(y)
		{
			p=p+y%16;
			y=y/16;
		}
		while(z)
		{
			q=q+z%12;
			z=z/12;
		}
		if(s==22&&p==22&&q==22&&a/1000>0&&a/10000==0)
			printf("%lld is a Sky Number.\n",a);
		else
			printf("%lld is not a Sky Number.\n",a);
	}
	return 0;
}
