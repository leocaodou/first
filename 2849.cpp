#include<stdio.h>
int main()
{
	float x,y;
	scanf("%f",&x);
	if(x<1)
	y=x*x;
	if(x>=1&&x<10)
	y=5*x-1;
	if(x>=10)
	y=2*x+4;
	printf("x=%0.2f,y=%.2f",x,y);
}
