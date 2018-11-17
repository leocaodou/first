#include<stdio.h>
int main()
{
	int a[41],b[11]={0},i;
	for(i=1;i<=40;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=b[a[i]]+1;
	}
	for(i=1;i<=10;i++)
	printf("%dºÅÓÐ%dÆ±\n",i,b[i]);
	return 0;
}  
