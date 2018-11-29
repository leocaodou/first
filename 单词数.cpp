#include<stdio.h>
int main()
{
	char a;
	int n;
	while(1)
	{
		scanf("%s",&a);
		if(a=='#')
			break;
		n=n+1;
	}
	printf("%d",n);
	return 0;
}
