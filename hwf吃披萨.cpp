#include<stdio.h>
int a[1000000];
int main()
{
	int n = 1,m,i,j,k,t,p=0,l;
	int b[n+1]={0};
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=1;j<m;j++)
		{
			p=0;
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
		for(j=1;j<=m;j++)
		{
			if(a[j]>180)
				break;
		}
		t=j-1;
		for(k=0;k<t;k++)
		{
			for(l=1;l<=t;l++)
			{
				b[i]=a[t-k];
				for(j=l;j<=t-1;j++)
				{
					if(b[i]+a[j]<=180)
						b[i]=b[i]+a[j];
				}
				if(b[i]>p)
				p=b[i];
			}
		}
		b[i]=p;
	}
	for(i=1;i<=n;i++)
		printf("%d\n",(180 - b[i]) * 2);
	return 0;
}
