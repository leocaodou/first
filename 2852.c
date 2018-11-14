#include<stdio.h>
int main()
{
	int i,j,a,n,s;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{
		a=1;
		for(j=1;j<=i;j++)
		{
			a=a*j;
		}
		s=s+a;
	}
	printf("sum=%d",s);
	return 0;
 } 
