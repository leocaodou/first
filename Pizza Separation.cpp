#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[521];
int main()
{
	int  n;
	scanf("%d",&n);
	int i,j;
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans = 521;//只要大于360就行了 
	for (i=0;i<n;i++)
	{
		int sum = 0;
		for (j=i;j<n;j++)
		{
			sum += a[j];
			ans = min(ans,abs(360-sum*2));
		}
	}
	printf("%d\n",ans);
	return 0;
}