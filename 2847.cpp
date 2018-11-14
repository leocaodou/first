#include<stdio.h>
int main()
{
	char a;
	int b;
	b=0;
	scanf("%c",&a);
	if(a>='A'&&a<='Z')
	b=1;
	if(a>='a'&&a<='z')
	b=2;
	if(a>=48&&a<=57)
	b=3;
	if(b==0)
	b=4;
	printf("%d",b);
	return 0;
}
