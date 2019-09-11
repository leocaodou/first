#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	double a,b,c,d,e;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	e=a*b-c-a*d;
	printf("%.2lf",e);
	return 0;
}
