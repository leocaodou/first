#include<stdio.h>
int main()
{
	int y,i,j,n,m,k,l,x,t;
	scanf("%d",&y);
	for(i=1;i<=y;i++)
	{
		x=1;t=0;
		scanf("%d%d%d",&n,&m,&k);
		char a[n+1][m+1],c[n+1][m+1];
		int p[k+2],q[k+2];
		for(j=1;j<n;j++)
		{
			scanf("%s",a[j]);
		}
		for(j=1;j<n;j++)
		{
			for(l=1;l<m;l++)
			{
				if(a[j][l]=='I')
				{
					p[1]=j;
					q[1]=l;
					x++;
				}
				if(a[j][l]=='E')
				{
					p[1+x]=j;
					q[1+x]=l;
					x++;
				}
				if(x==k)
					break;
			}
		}
		while(1)
		{
			if(a[p[1]+1][q[1]]==' ')
			{
				p[1]++;
				continue;
			}
			if(a[p[1]][q[1]]==' ')
			{
				p[1]--;
				continue;
			}
			
		}
		if(a[p[1]-1][q[1]]==' ')
			t++;
		if(a[p[1]][q[1]+1]==' ')
			t++;
		if(a[p[1]][q[1]-1]==' ')
			t++;
		if(t>1)
		c[p[1]][q[1]]='Y';
	}
}
