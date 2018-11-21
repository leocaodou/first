#include<stdio.h>
int main()
{
	int A(int,int);
	int m,n,a;
	scanf("%d%d",&m,&n);
	a=A(m,n);
	printf("%d",a);
}
int A(int m,int n)
{
	int jie(int);
	int z,x,y;
	x=jie(m);
	y=jie(n);
	z=x/jie(m-n);
	return z;
}
int jie(int x)
{
	int i,j=1;
	for(i=1;i<=x;i++)
	{
		j=j*i;
	}
	return j;
}
