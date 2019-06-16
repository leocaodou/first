#include<stdio.h>
int main()
{
	int a,b;
	int su(int);
	scanf("%d",&a);
	b=su(a);
	if(b==1)
	printf("是素数\n");
	else
	printf("是素数才怪\n");
}
int su(int x)
{
	int i,n=0,a;
	for(i=1;i<=x;i++)
	{
		if(x%i==0)
		n=n+1;
	}
	if(n==2)
	a=1;
	return a;
}
