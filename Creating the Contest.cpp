#include <stdio.h>
int main()
{
	int max=0,i,n;
	scanf("%d",&n);
	long long a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n-1;i++)
	{
		int j=i+1,s=1;
		while(1)
		{
			if(a[j]>a[i]*2)
			{
				if(s>max)
					max=s;
				break;
			}
			j++;
		}
		if(n-i-1<max)
			break;
	}
	printf("%d",max);
	return 0;
}