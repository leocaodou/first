#include<stdio.h>
#include<string.h>
void replace(char *,char,char);
int main()
{
	char s[20],c1,c2;
	gets(s);
	scanf("%c",&c1);
	getchar();
	scanf("%c",&c2);
	replace(s,c1,c2);
	puts(s);
	return 0;
}
void replace(char *c,char c1,char c2)
{
	int i;
	for(i=0;i<strlen(c);i++)
	{
		if(*(c+i)==c1)
			*(c+i)=c2;
	}
}
