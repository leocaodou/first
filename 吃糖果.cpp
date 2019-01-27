#include<stdio.h>
int main()
{
	int t,i,j,a;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int n,max=0,s=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			s=s+a;
			if(a>max)
			{
				max=a;
			}
		}
		s=s-max;
		if(s>=(max-1))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
