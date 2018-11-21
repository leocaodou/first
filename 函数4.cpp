#include<stdio.h>
int main()
{
	void su(int);
	int a,b;
	scanf("%d",&a);
	su(a);
	return 0;
}
void su(int a)
{
	int i,n=0;
	for(i=1;i<=a;i++)
	{
		if(a%i==0)
			n=n+1;
	}
	if(n>=3)
	printf("不是素数");
	else
	printf("是素数"); 
}
