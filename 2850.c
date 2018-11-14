#include<stdio.h>
int main()
{
	int a,b,n;
	scanf("%d",&n);
	while(1)
	{
		if(n%3!=0)
		{
			printf("%4d",n);
			a=a+1;
		}
		if(a==10)
		{
			break;
		}
		n++;
	}
	return 0;
}
