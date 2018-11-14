#include<stdio.h>
#include<math.h>
int main()
{
	int n,a,i,j,s,b;
	s=0;
	scanf("%d%d",&n,&a);
	for(i=1;i<=n;i++)
	{
		b=0;
		for(j=1;j<=i;j++)
		{
			b=a*pow(10,(j-1))+b;
		}
		s=s+b;
	}
	printf("s=%d",s);
	return 0;
 } 

