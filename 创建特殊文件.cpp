#include <stdio.h>
#include <stdlib.h>

void save(char str[20], int n);
void prnt(char str[20], int n);

int main()
{
	int n;
	char str[20];
	
	printf("Input filename:");
	scanf("%s", str);
	printf("Input n:");
	scanf("%d", &n);
	save(str, n);
	prnt(str, n);
	return 0;
}

void save(char str[20], int n)
{
	/******start******/
	FILE *fp;
	int i,c[n],a=1,b=0;
	c[0]=1;
	c[1]=1;
	fp=fopen(str,"wb+");
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			c[i]=a;
			b=a+b;
		}
		else
		{
			c[i]=b;
			a=a+b;
		}
	}
	for(i=0;i<n;i++)
	{
			fwrite(c+i,sizeof(int),1, fp);
	}
		fclose(fp);
	/******end******/
}
void prnt(char str[20], int n)
{
	int i, te;
	FILE *fp;

	fp = fopen(str, "rb");
	if (fp == NULL)
	{
		exit(0);
	}
	printf("Output:\n");
	for (i = 0; i < n; i++)
	{
		fread(&te, sizeof(int), 1, fp);
		printf("%d ", te);
	}
	printf("\n");
	fclose(fp);
}


