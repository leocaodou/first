#include <stdio.h>
int main()
{
	int n,i,k,s;
	scanf("%d",&n);
	int a[n][2];
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(a[i][1]>=k)
		{
			s=n-i;
			break;
		}
	}
	printf("%d",s);
	return 0;
}