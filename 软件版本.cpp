#include<stdio.h>
int main()
{
	int n,i,a,b,c,d,e,f;
	printf("Input number of test:\n"); 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("input the first group version No.:(main sub revision)\n");
		scanf("%d%d%d",&a,&b,&c);
		printf("input  thesecond group version No.:(main sub revision)\n");
		scanf("%d%d%d",&d,&e,&f);
		printf("Output:\n");
		if(a!=d)
			if(a>d)
			printf("First\n");
			else
			printf("Second\n");
		else if(b!=e)
				if(b>e)
					printf("First\n");
				else
					printf("Second\n");
			else if(c!=f)
					if(c>f)
						printf("First\n");
					else
						printf("Second\n");
			else
				printf("Same\n");
	}
	return 0;
} 
