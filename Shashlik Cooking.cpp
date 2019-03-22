#include <stdio.h>
int main()
{
	int n,k,x,s;
	scanf("%d%d",&n,&k);
	x = 2 * k + 1;
	s = n / x;
	if(n - s * x == 0)
	{
		int a[s],i;
		for(i=0; i<s ;i++)
		{
			a[i]=i*x + k + 1;
		}
		printf("%d\n",s);
		for(i=0; i<s ;i++)
			printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	if(n - s * x >= k+1)
	{
		int a[s+1],i;
		for(i=0; i<s+1 ;i++)
		{
			a[i]=i*x + k + 1;
		}
		printf("%d\n",s+1);
		for(i=0; i<s+1 ;i++)
			printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	if(n - s * x < k+1)
	{
		int y = n - s * x,i;
		int a[s+1];
		a[0] = k - (k + 1 -y) + 1;
		for(i=1; i<s+1 ;i++)
		{
			a[i]=(i-1)*x+2*k+a[0]+1;
		}
		printf("%d\n",s+1);
		for(i=0; i<s+1 ;i++)
			printf("%d ",a[i] );
		printf("\n");
		return 0;
	}
}