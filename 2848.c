#include<stdio.h>
int main()
{
	float a,b,c,max,min;
	scanf("%f%f%f",&a,&b,&c);
	max=a>b?a:b;
	max=max>c?max:c;
	min=a<b?a:b;
	min=min<c?min:c;
	printf("%.2f %.2f",max,min);
	return 0;
}
	
