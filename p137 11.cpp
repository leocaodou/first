#include<stdio.h>
int main()
{
	double a,b,s,c,i;
	a=100;
	s=0-100;
	for(i=1;i<=10;i++)
	{
		s=s+a*2;
		a=a/2;
	}
	printf("一个经过了%lf米\n",s);
	printf("第10次弹起%lf米\n",a);
	return 0;
 } 
