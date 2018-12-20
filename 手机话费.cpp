#include<stdio.h>
int main()
{
	int n,k,a,b;
	while(1)
	{
		scanf("%d%d",&n,&k);
		if(n==0&&k==0)
			break;
		b=n;
		a=n;
		while(1)
		{
			b=b/k;
			if(b==0)
				break;
			a=a+b;
		}
		printf("%d\n",a);
	}
	return 0;
}
