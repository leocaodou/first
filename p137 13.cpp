#include<stdio.h>
#include<math.h>
int main()
{
	float x,a,b;
	scanf("%f",&a);
	x=a/2;
	while(1)
	{
		b=x;
		x=(x+a/x)/2;
		if(fabs(b-x)<=1e-5)
			break;
	}
	printf("%f",x);
	return 0;
}
