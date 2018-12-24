#include<stdio.h>
int main()
{
	int n,m,i=0,j=0,k;
	scanf("%d%d",&n,&m);
	int a[n]={0};
	for(k=1;k<n;k++)
	{
		while(1)
		{
			if(a[i]==0)
				j=j+1;
			if(j==m)
			{
				a[i]=1;
				break;
			}
			i++;
			if(i==n)
				i=0;
		}
		j=0;
		i++;
		if(i==n)
		i=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
			printf("%d",i);
	}
	return 0;
}