#include<stdio.h>
#include<string.h>
#include<iostream>
int main()
{
	char a[20];
	int i=0,b,c=0,j,u=0;
	printf("Please input string: ");
	scanf("%s",a);
	while(strcmp(a,"0")!=0)
	{
		c=0;
		b=strlen(a);
		for(i=0;i<b;i++)
		{
			for(j=i;j<b;j++)
			{
				int k,x=0,l=1;
				for(k=i;k<=j;k++)
				{
					if(a[k]!=a[j-x])
						l=0;
					x++;
				}
				if(l==1)
					c++;
			}
		}
		if(u==0)
			printf("Output:\n");
		printf("The total number is: ");
		printf("%d\n",c);
		printf("Please input string: ");
		scanf("%s",a);
		u++;
	}
	return 0;
}
