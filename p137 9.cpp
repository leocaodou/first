#include<stdio.h>
int main()
{
	int a,i,j;
	for(i=1;i<=1000;i++)
	{
		a=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				a=a+j;
		}
		if(a==i)
		{
			printf("%d its factors are",i);
			for(j=1;j<i;j++)
			{
				if(i%j==0)
				printf("%d ",j);
			}
			printf("\n");
		}
	}
	return 0;
}
