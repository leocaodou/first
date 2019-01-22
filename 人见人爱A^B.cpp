#include<stdio.h>
int main()
{
	while(1)
	{
		long a,b,i,s=1;
		scanf("%ld%ld",&a,&b);
		if(a==0&&b==0)
			break;
		for(i=1;i<=b;i++)
			s=s*a%1000;
		printf("%ld\n",s);
	}
	return 0;
} 
