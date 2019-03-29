#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,j=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int b[n];
	if(a[0]!=0){
		b[0]=a[0];
		j++;
	}
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i-1] &&a[i]!=0)
		{
			b[j]=a[i];
			j++;
		}
	}
	printf("%d",j);
	return 0;
}