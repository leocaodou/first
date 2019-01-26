#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	while(gets(str)!=NULL)
	{
		int i,j;
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]==' '&&str[i+1]=='y'&&str[i+2]=='o'&&str[i+3]=='u'&&(str[i+4]==' '||str[i+4]=='\0'))
			{
				str[i+1]='w';
				str[i+2]='e';
				for(j=i+3;j<strlen(str);j++)
				{
					str[j]=str[j+1];
				}
			}
			if(i==0&&str[i]=='y'&&str[i+1]=='o'&&str[i+2]=='u'&&(str[i+3]==' '||str[i+3]=='\0'))
			{
				str[i]='w';
				str[i+1]='e';
				for(j=i+2;j<strlen(str);j++)
				{
					str[j]=str[j+1];
				}
			}
		}
		printf("%s\n",str);
	}
	return 0;
}
