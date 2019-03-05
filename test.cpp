#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *name="aaa";
	char *a=name;
	name=(char *)malloc(sizeof(char)*(strlen("aaa")+1));
	strcpy(name,"bbb");
	printf("%c,%s",*a,*name);
	return 0;
} 
