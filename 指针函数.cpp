#include<stdio.h>
int main()
{
	int a,b;
	int *c,*d;
	c=&a;
	d=&b;
	void max(int *a,int *b);
	scanf("%d%d",&a,&b);
	if(a<b)
	max(c,d);
	printf("%d %d",a,b);
	return 0;
}
void max(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
