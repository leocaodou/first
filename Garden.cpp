#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,m=0,i;
	scanf("%d%d",&n,&k);
	int a[n];
	m = k;
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		if (a[i] <= k && m > k/ a[i] && k % a[i] == 0)
			m = k / a[i];
	}
	printf("%d",m);
	return 0;
}