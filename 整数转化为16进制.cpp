#include<stdio.h>
#include<math.h>
int main()
{
	long int x,a,c;
	int b,j;
	int i=1;
	char str[100];
	scanf("%ld",&x);
	c=x;
	if(x<0)
		x=-x;
	a=x;
	while(1)
	{
		a=a/16;
		if(a==0)
			break;
		i++;
	}
	for(j=i;j>=1;j--)
	{
		b=x%16;
		x=x/16;
		if(b<=9)
			str[j-1]=48+b;
		else
			str[j-1]=b-9+64;
	}
	if(c<0)
	{
		printf("-%s",str);
		return 0;
	}
	printf("%s",str);
	return 0;
} 
