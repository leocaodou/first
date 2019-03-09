#include<stdio.h>
int main()
{
	int n,i,j,k,p=0;
	scanf("%d",&n);
	long long a[n]={0},b[n]={0};
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		b[0]=a[i];
		for(j=0;j<n-1;j++)
		{
			p=0;
			for(k=0;k<n;k++)
			{
				if(a[k]*3==b[j])
				{
					b[j+1]=a[k];
					p=1;
					break;
				}
				else
					if(a[k]==b[j]*2)
					{
						b[j+1]=a[k];
						p=1;
						break;
					}
					else
					if(k==n-1)
						break;
			}
		}
		if(j==n-2&&p==1)
		break;
	}
	for(i=0;i<n;i++)
	{
		printf("%lld ",b[i]);
	}
}
