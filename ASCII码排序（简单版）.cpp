#include<stdio.h>
int main()
{
	char a[3],t;
	int i,j;
	while(scanf("%s",a)!=EOF)
	{
		getchar();
		for(i=0;i<2;i++)
			for(j=0;j<3-1-i;j++)
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
		printf("%c %c %c",a[0],a[1],a[2]);
		printf("\n");
	}
	return 0;
} 
