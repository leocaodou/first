#include<stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	int i=0,j=0,b=0,p=0,e=0;
	char name[20],str[127],ch;
	printf("input the file's name and the string: ");
	scanf("%s",name);
	getchar();
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		printf("\nfile open error!");
		exit(0);
	}
	scanf("%s",str);
	getchar();
    printf("Output: ");
	printf("------------------------File content:----------------------\n");
	ch=fgetc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=fgetc(fp);
		if(ch=='\n')
		{
			i++;	
		}
		if(ch==str[j])
		{
			j++;
		}
		else
		{
			j=0;
		}
		if(str[j]=='\0'&&p==0)
		{
			b=i;
			p=1;
			j=0;
		}
		if(str[j]=='\0'&&p==1)
		{
			e=i;
			j=0;
		}
	}
	if(p==0)
	{
		b=-2;
		e=-2;
	}
	printf("\n------------------------File summary:----------------------\n");
	printf("%d lines, first line: %d, last line: %d\n",i+1,b+1,e+1);
	return 0;
}
