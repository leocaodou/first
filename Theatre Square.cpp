#include<stdio.h>
int main()
{
	long long m,n,a,x,y,s;
	scanf("%lld%lld%lld",&m,&n,&a);
	x=m/a;
	y=n/a;
	if(m%a>0)
	{
		x++;
	}
	if(n%a>0)
	{
		y++;
	}
	s=x*y;
	printf("%lld",s);
	return 0;
}
