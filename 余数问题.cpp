#include<stdio.h>
int main()
{
	int n,i,j=1,t=0;
	printf("please input:\n");
	scanf("%d",&n);
	int a[n+1],b[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	while(1)
	{
		t=0;
		for(i=1;i<=n;i++)
		{
			if(j%a[i]==b[i])
				t++;
		}
		if(t==n)
			break;
		j++;
	}
	printf("Output:\n%d",j);
	return 0;
}

