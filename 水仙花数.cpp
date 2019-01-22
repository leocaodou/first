#include<stdio.h>
int main()
{
	int a[4],n,m,i,j,x,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		p=0;
		for(j=n;j<=m;j++)
		{
			i=1;
			x=j;
			int s=0;
			while(x)
			{
				a[i]=x%10;
				x=x/10;
				i++;
			}
			for(i=1;i<=3;i++)
				s=s+a[i]*a[i]*a[i];
			if(s==j&&p==0)
			{
				printf("%d",s);
				p++;
			}
			else if(s==j&&p!=0)
			{
				printf(" %d",s);
				p++;
			}
			if(j==m&&p==0)
				printf("no");
			if(j==m)
			printf("\n");
		}
	}
	return 0;
} 
