#include<stdio.h>
int main()
{
	int jie(int);
	int a,b,c;
	scanf("%d",&a);
	b=jie(a);
	printf("%d",b);
	return 0;
}
int jie(int a)
{
	int j;
	if(a==0)
	{
		j=1;
	}
	if(a!=0)
	j=a*jie(a-1);
	return j;
}
