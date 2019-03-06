#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,c,b;
	scanf("%d",&n);
	getchar();
	char s[n][100]={0},a[n][100]={0};
	for(i=0;i<n;i++)
	{
		gets(s[i]);
		b=strlen(s[i]);
		c=strlen(s[i]);
		if(c<=10)
		{
			strcpy(a[i],s[i]);
		}
		else
		{
			a[i][0]=s[i][0];
			if(c-2>=10)
			{
				a[i][1]=(c-2)/10+48;
				c=(c-2)%10;
				a[i][2]=c+48;
				a[i][3]=s[i][b-1];
			}
			else
			{
				a[i][1]=c+48-2;
				a[i][2]=s[i][b-1];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		puts(a[i]);
	}
	return 0;
}
