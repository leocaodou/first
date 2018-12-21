#include<stdio.h>
int main()
{
	float sum=0;
	int i,n;
	printf("please input n:");
	scanf("%d",&n);
	printf("Output:");
	if(n<=0)
	{
		printf("Input error!");
	}
	else
	{
	for(i=1;i<=n;i++)
	if(i%2==0)
	{sum-=1/float(i);
	}
	else
	{sum+=1/float(i);
	}
		
	}
	printf("the ans is %.5f",sum);
return 0;
	}
