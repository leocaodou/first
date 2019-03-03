#include<stdio.h>
int main()
{
	double i=100;
	i++;
	double *p=&i;
	double **q;
	q=&p;
	printf("%p,%p,%p,%p,%p,%p,%p",&i,p,&p,q,&q,&*q,&**q);
	return 0;
} 
