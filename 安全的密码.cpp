#include<stdio.h>
int main()
{
	int n,m,i,j,x,t,k;
	scanf("%d",&n);
	int b[n+1]={0};
	for(i=1;i<=n;i++)
	{
		x=1;
		scanf("%d",&m);
		int a[6000000];
		for(j=2;j<=m/2;j++)
		{
			t=0;
			for(k=1;k<=j;k++)
			{
				if(j%k==0)
				{
					t++;
				}
			}
			if(t==2)
			{
				a[x]=j;
				x++;
			}
				
		}
		for(j=1;j<=x;j++)
		{
			for(k=j;k<=x;k++)
			{
				if(a[j]*a[k]==m)
					b[i]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
