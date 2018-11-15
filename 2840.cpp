#include<stdio.h>
int main()
{
	double a,b,c,i;
	scanf("%lf%lf%lf",&a,&b,&c);
	for(i=1;i<=c;i++)
	{
		a=a*(1+b);
	}
	printf("%.2lf",a);
	return 0;
}
