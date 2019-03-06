#include<stdio.h>
main(void)
{
	int a[21],b,i,j;
	b=0;
	for(i=1;i<=20;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<60)
		b=b+1;
	}
	printf("%d",b);
	return 0;
}
