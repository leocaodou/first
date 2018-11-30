#include<stdio.h>
int main()
{
	char str1[10000],str2[10000];
	printf("Please input a string str1 is:");
	gets(str1);
	printf("Please input a string str2 is:");
	gets(str2);
	printf("Output:\n");
	printf("string str1=");
	puts(str1);
	printf("string str2=");
	puts(str2);
	printf("copy string st1 to string str2\n");
	void copy_string(char *from,char *to);
	copy_string(str1,str2);
	printf("string str1=");
	puts(str1);
	printf("string str2=");
	puts(str2);
	return 0;
}
void copy_string(char *from,char *to)
{
	int i=0;
	while(1)
	{
		to[i]=from[i];
		if(to[i]=='\0')
		break;
		i++;
	}
}
