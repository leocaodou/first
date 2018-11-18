#include<stdio.h>
int main()
{
	int i,j,a,b;
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",a-b);
	}
	return 0;
}
