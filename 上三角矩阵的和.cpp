#include<stdio.h>
int main()
{
	int m,n,i,j,k;
	scanf("%d",&m);
	int b[m+1]={0};
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		int a[n+1];
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			for(k=1;k<=j;k++)
				b[i]=b[i]+a[j]*a[k];
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%d\n",b[i]);
	}
	return 0;
}
