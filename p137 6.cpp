#include<stdio.h>
int main()
{
	int a,i,j,s;
	a=1;
	s=0;
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=i;j++)
		{
			a=a*j;
		}
		s=s+a;
	}
	printf("%d",s);
	return 0;
 } 
