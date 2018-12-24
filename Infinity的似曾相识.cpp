#include<stdio.h>
int main()
{
	int n,i,m,j,k;
	scanf("%d",&n);
	int a[n+1][1000],c[n+1],d[n+1];
	for(i=1;i<=n;i++)
	{
		int b[i]={0};
		scanf("%d",&d[i]);
		for(j=1;j<=d[i];j++)
		{
			scanf("%d",&a[i][j]);
			for(k=1;k<i;k++)
			{
				if(d[k]!=d[i])
				{
					b[k]=1;
					continue;
				}
				if(b[k]==0)
				{
					if(a[i][j]!=a[k][j])
						b[k]=1;
				}
			}
		}
		for(k=1;k<i;k++)
		{
			if(b[k]==0)
			{
				c[i]=1;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]==1)
		printf("deja vu\n");
		else
		printf("new\n");
	}
	return 0;
}
