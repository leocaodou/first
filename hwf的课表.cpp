#include<stdio.h>
int main()
{
	int n,m,i,j,p,q;
	scanf("%d",&n);
	int b[n+1]={0};
	for(i=1;i<=n;i++)
	{
		int a[8][7]={0};
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d%d",&p,&q);
			if(a[p][q]==0)
			{
				a[p][q]=1;
				b[i]++;
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d\n",b[i]);
	return 0;
}
