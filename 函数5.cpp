#include<stdio.h>
int main()
{
	int n,x;
	int P(int,int);
	scanf("%d%d",&n,&x);
	printf("%d",P(n,x));
	return 0;
}
int P(int n,int x)
{
	int p[n+1];
	p[0]=0;
	p[1]=x;
	if(n>1)
	p[n]=((2*n-1)*x-p[n-1]-(n-1)*p[n-2])/n;
	return p[n];
}
