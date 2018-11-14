#include<stdio.h>
int main()
{
	float x,y;
	scanf("%f",&x);
	if(x<3)
	y=x+5;
	if(x==3)
	y=2*x;
	if(x>3&&x<10)
	y=6*x-4;
	if(x>=10)
	y=3*x-11;
	printf("x=%.3f,",x);
	printf("y=%.3f",y);
	return 0;
}
