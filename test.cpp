#include<stdio.h>
int main()
{
	char *x;
	x = new char[100];
	x[0] = 'a';
	x[1] = '\0';
	printf("%s",x);
}
