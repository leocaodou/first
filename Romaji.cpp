#include <stdio.h>
#include <string.h>
int main()
{
	char a[101];
	scanf("%s",a);
	int i,x=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='n')
			continue;
		else
			if(a[i+1]!='a'&&a[i+1]!='e'&&a[i+1]!='i'&&a[i+1]!='o'&&a[i+1]!='u')
			{
				x=1;
				break;
			}
	}
	if(x==1)
		printf("NO\n");
	else
		printf("YES\n");
}