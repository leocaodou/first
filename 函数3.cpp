#include<stdio.h>
int main()
{
	double C(double);
	double a,i,c;
	for(i=32;i<=100;i=i+4)
	{
		printf("华氏度%.2lf\n",i);
		c=C(i);
		printf("摄氏度是%.2lf\n",c);
	}
	return 0;
}
double C(double f)
{
	double c;
	c=(f-32)/1.8;
	return c;
}
