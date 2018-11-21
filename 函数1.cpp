#include<stdio.h>
int main()
{
	int dadada(int,int,int);
	int a,b,c,d,e,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	x=dadada(a,b,c);
	y=dadada(x,d,e);
	printf("%d",y);
	return 0;
}
int dadada(int x,int y,int z)
{
	int t,q;
	t=x>y?x:y;
	q=t>z?t:z;
	return q;
}
