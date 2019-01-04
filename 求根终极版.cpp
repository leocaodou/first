#include<stdio.h>
#include<math.h>
void gen1(int a,int b,int c,int d);
void gen2(int a,int b,int c,int d);
void gen3(int a,int b,int c,int d);
int main()
{
	int a,b,c,d;
	printf("Please input a b c:\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("Output:\n");
	if(a==0)
	{
		printf("not a quadratic\n");
		return 0;
	}
	d=b*b-4*a*c;
	if(d>0)
	{
		printf("distinct real roots:\n");
		gen1(a,b,c,d);
	}
	if(d==0)
	{
		printf("two equal roots:\n");
		gen2(a,b,c,d);
	}
	if(d<0)
	{
		printf("complex roots:\n");
		gen3(a,b,c,d);
	}
	return 0;
}
void gen1(int a,int b,int c,int d)
{
	double x1,x2;
	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);
	printf("%.4lf %.4lf",x2,x1);
}
void gen2(int a,int b,int c,int d)
{
	double x;
	x=-(double)b/(2*a);
	printf("%.4lf",x);
}
void gen3(int a,int b,int c,int d)
{
	double p,q;
	p=-(double)b/(2*a);
	q=sqrt(-d)/(2*a);
	printf("%.4lf+%.4lfi %.4lf-%.4lfi",p,q,p,q);
}
