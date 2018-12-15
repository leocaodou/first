#include<stdio.h>
int main()
{
	int n,i,j,c,d,e,f;
	scanf("%d",&n);
	int a[n+1];
	char b[n+1][10000];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c=a[i]/64;
		d=(a[i]%64)/16;
		e=(a[i]%16)/4;
		f=a[i]%4;
		for(j=0;j<=c-1;j++)
		{
			if(c==0)
				break;
			b[i][j]='~';
		}
	    for(j=0;j<=d-1;j++)
		{
			if(d==0)
				break;
			b[i][j+c]='@';
		}
		for(j=0;j<=e-1;j++)
		{
			if(e==0)
				break;
			b[i][j+d+c]='^';
		}
		for(j=0;j<=f-1;j++)
		{
			if(f==0)
				break;
			b[i][j+d+c+e]='*';
		}
	}
	for(i=1;i<=n;i++)
	{
		puts(b[i]);
	}
	return 0;
} 
