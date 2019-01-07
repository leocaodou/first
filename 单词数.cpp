#include<stdio.h>
int main()
{
	char a[100000];
	int n=0;
	{
		n=0;
		while(1)
		{	
			while(scanf("%c",&a)!=EOF)
			if(a[0]=='#')
				break;
			n=n+1;
		}
	printf("%d",n);
	}
	return 0;
}
