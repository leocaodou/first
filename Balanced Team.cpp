#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n=0,max=0,i;
	scanf("%d",&n);
	long a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	long b[n-1];
	for(i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(i=0;i<n-1;i++)
	{
		int j=i,s=0,k=1;
		while(j<n-1)
		{
			s=s+b[j];
			if(s>5)
				break;
			j++;
			k++;
		}
		if(k>max)
			max=k;
	}
	printf("%d",max);
}