#include<stdio.h>
int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	int a[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
