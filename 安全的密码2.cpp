#include<stdio.h>
int main()
{
	int n,m,i,j,x,t,k,c;
	scanf("%d",&n);
	int b[n+1]={0};
	for(i=1;i<=n;i++)
	{
		t=0;
		scanf("%d",&m);
		for(j=2;j<=(m/2);j++)
		{
			if(m%j==0)
			{
				for(k=1;k<=j;k++)
				{
					if(j%k==0)
					{
						t++;
					}
				}
				if(t!=2)
					break;
				t=0;
				c=m/j;
				for(k=1;k<=c;k++)
				{
					if(c%k==0)
					{
						t++;
					}
				}
				if(t==2)
					b[i]=1;
				break;
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
