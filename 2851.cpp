#include<stdio.h>
int main()
{
	int n,a,i,j;
	s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			a=j*j;
		}
		s=s+a;
	}
	printf("%d",n);
	return 0;
}
