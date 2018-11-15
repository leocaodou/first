#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	double g;
	scanf("%d%d",&a,&b);
	c=a+b;
	d=a-b;
	e=a*b;
	g=double(a)/double(b);
	f=a%b;
	printf("%d+%d=%d\n",a,b,c);
	printf("%d-%d=%d\n",a,b,d);
	printf("%d*%d=%d\n",a,b,e);
	printf("%d/%d=%.2lf\n",a,b,g);
	printf("%d",a);
	printf("%%");
	printf("%d=%d",b,f);
	return 0;
}
