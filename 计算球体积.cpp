#include<stdio.h>
#define PI 3.1415927
int main()
{
	long double r,v;
	while(scanf("%Lf",&r)!=EOF)
	{
		v=(4.0/3)*PI*r*r*r;
		printf("%.3Lf\n",v);
	}
	return 0;
}
