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
	printf("һ��������%lf��\n",s);
	printf("��10�ε���%lf��\n",a);
	return 0;
 } 
