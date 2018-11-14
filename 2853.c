#include<stdio.h>
int main()
{
	int i,j,a,b,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=0;
		for(j=1;j<=i;j++)
		{
			a=a+j;
		}
		b=b+a;
	}
	printf("%d",b);
	return 0;
}
