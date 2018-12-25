#include<stdio.h>
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	int d[t+1],e[t+1][10000];
	char f[t+1][10000];
	for(i=1;i<=t;i++)
	{
		int n,m,x=0,y=0,o;
		char t;
		scanf("%d%d",&n,&m);
		char a[n+1][m+1];
		for(j=1;j<=n;j++)
		{
			scanf("%s",a[j]);
			getchar();
		}
		for(j=1;j<=n*m-1;j++)
		{
			for(k=1;k<=n*m-j;k++)
			{
				if(a[k/m+1][k%m]<a[(k+1)/m+1][(k+1)%m])
				{
					t=a[k/m+1][k%m];
					a[k/m+1][k%m]=a[(k+1)/m+1][(k+1)%m];
					a[(k+1)/m+1][(k+1)%m]=t;
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			for(k=0;k<m;k++)
			{
				if(a[j][k]==f[i][x])
					e[i][x]++;
				else
				{
					x++;
					f[i][x]=a[j][k];
					e[i][x]++;
				}
			}
		}
		for(j=1;j<=x-1;j++)
		{
			for(k=1;k<=x-j;k++)
			{
				if(e[i][k]<e[i][k+1])
				{
					o=e[i][k];
					t=f[i][k];
					e[i][k]=e[i][k+1];
					f[i][k]=f[i][k+1];
					e[i][k+1]=o;
					f[i][k+1]=t;
				}
			}
		}
		d[i]=x;
	}
	for(i=1;i<=t;i++)
	{
		printf("%d\n",d[i]);
		for(j=1;j<=d[i];j++)
		{
			printf("%d %c\n",e[i][j],f[i][j]);
		}
	}
	return 0;
}
