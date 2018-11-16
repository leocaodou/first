#include<stdio.h>
#define pi 3.1416
int main()
{
	double a,c,s;
	scanf("%lf",&a);
	c=2*pi*a;
	s=pi*a*a;
	printf("%.2lf %.2lf",c,s);
	return 0;
}
