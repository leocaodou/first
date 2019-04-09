#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,i,sum = 0,j,l;
	scanf("%d%d",&n,&k);
	int a[n];
	int m[k]={0},p[k]={0};
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		for(j = 0;j < k; j++)
		{
			if(a[i] >= m[j])
			{
				for(l = k -1;l > j;l--)
				{
					p[l] = p[l-1];
				}
				p[j] = i;
				for(l = k -1;l > j;l--)
				{
					m[l] = m[l-1];
				}
				m[j] = a[i];
				break;
			}
		}
	}
	for(j =0;j < k;j++){
		sum = sum + m[j];
	}
	printf("%d\n",sum);
	sort(p, p+k);
	for(j =0;j < k;j++)
	{
		if(j == 0){
			printf("%d ",p[j]+1);
			continue;
		}
		if(j == k - 1)
			printf("%d ",n - p[j - 1] -1);
		else
			printf("%d ",p[j] - p[j - 1]);
	}
	return 0;
}
