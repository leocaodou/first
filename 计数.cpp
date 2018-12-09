#include<stdio.h>
int main()
{
	int m,i,j,t,e;
	scanf("%d",&m);
	int a[m+1],c[m+1];
	for(i=1;i<=m;i++)
	{
		c[i]=1;
	}	
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		for(j=1;j<i;j++)
		{
			if(a[j]==a[i])
			{
				c[j]=c[j]+1;
				a[i]=0;
				break;
			}
		}
	}
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				e=c[i];
				a[i]=a[j];
				c[i]=c[j];
				a[j]=t;
				c[j]=e;
			}
		}
	for(i=1;i<=m;i++)
		if(a[i]!=0)
		{
			printf("%d %d\n",a[i],c[i]);
		}
	return 0;
}
