#include <stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	long long a[n][2];
	int b[n] = {0};
	for(i = 0;i < n;i++)
	{
		scanf("%lld%lld",&a[i][0],&a[i][1]);
		b[i] = (a[i][0]-1)*9+a[i][1];
	}
	for(i = 0;i < n;i++)
		printf("%d\n",b[i]);
	return 0;
}