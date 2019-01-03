#include<stdio.h>
int main()
{
	int n,i,j,t=0;
	printf("Input n: ");
	scanf("%d",&n);
	int a[n+1][n+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		t=t+a[i][i];
	printf("Output:\nsum=%d\n",t);
	return 0;
}
