#include<stdio.h>
int e[1000001]={0};
int main()
{
	int a,b,t=0,i;
	scanf("%d%d",&a,&b);
	int c[a+1],d[b+1];
	for(i=1;i<=a;i++)
	{
		scanf("%d",&c[i]);
		if(e[c[i]]==0)
		{
			e[c[i]]=1;
			t++;
		}
	}
	for(i=1;i<=b;i++)
	{
		scanf("%d",&d[i]);
		if(e[d[i]]==0)
		{
			e[d[i]]=1;
			t++;
		}
	}
	printf("%d\n",t);
	return 0;
}
