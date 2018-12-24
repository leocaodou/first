#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char name[20];
	int n;
	printf("Input filename:");
	scanf("%s",name);
	getchar();
	printf("Input n:");
	scanf("%d",&n);
	char str[n+1];
	printf("Output:\n");
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		printf("Open Error!\n");
		exit(0);
	}
	fgets(str,n+1,fp);
	printf("%s\n",str);
	fclose(fp);
	return 0;
}
