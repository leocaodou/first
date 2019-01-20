#include<stdio.h>
int main()
{
	long double r,v;
	while(scanf("%Lf",&r)!=EOF)
	{
		v=(4.0/3)*3.1415926535898*r*r*r;
		printf("%.3Lf\n",v);
	}
	return 0;
}
