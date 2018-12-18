#include<stdio.h>
int main()
{
	int n,m,i,j,t,k;
	scanf("%d",&n);
	float b[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		int a[m+1];
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=1;j<m;j++)
		{
			for(k=1;k<=m-j;k++)
			{
				if(a[k]>a[k+1])
				{
					t=a[k];
					a[k]=a[k+1];
					a[k+1]=t;
				}
			}
		}
		if(m%2==0)
			b[i]=((float)a[m/2]+(float)a[m/2+1])/2;
		if(m%2!=0)
			b[i]=a[(m+1)/2];
	}
	for(i=1;i<=n;i++)
	{
		printf("%.1f\n",b[i]);
	}
	return 0;
} 
