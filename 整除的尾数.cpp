#include<stdio.h>
int main()
{
	while(1)
	{
		int a,b,i,n=0;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
			break;
		a=a*100;
		for(i=0;i<=99;i++)
		{
			if((a+i)%b==0&&n==0)
			{
				if(i<10)
					printf("0%d",i);
				else
					printf("%d",i);
				n=1;
				continue;
			}
			if((a+i)%b==0)
				if(i<10)
					printf(" 0%d",i);
				else
					printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}
