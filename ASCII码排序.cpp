#include<stdio.h>
int main()
{
	char a[3][3],t;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%c",&a[i][j]);
		}
		getchar();
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<9-i-1;j++)
			if(a[j/3][j%3]>a[(j+1)/3][(j+1)%3])
			{
				t=a[j/3][j%3];
				a[j/3][j%3]=a[(j+1)/3][(j+1)%3];
				a[(j+1)/3][(j+1)%3]=t;
			}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
} 
