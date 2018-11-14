#include<stdio.h>
int main()
{
	int a[5][5],i,j,k,l,n;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			n=0;
			for(k=1;k<=4;k++)
			{
				if(a[i][j]>=a[i][k])
				n=n+1;
			}
			if(n==4)
			{
				n=0;
				for(k=1;k<=4;k++)
				{
					if(a[i][j]<=a[k][j])
					n=n+1;
				}
				if(n==4)
				printf("%d\n",a[i][j]);
			}
		}
	}
	return 0;
} 
