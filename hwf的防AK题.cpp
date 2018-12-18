#include<stdio.h>
int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	int b[n+1]={0};
	char a[n+1][100000];
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		for(j=0;;j++)
		{
			if(a[i][j]=='\0')
				break;
		}
		t=j;
		for(j=0;j<t;j++)
		{
			if(a[i][j]=='A')
			{
				if(a[i][j+1]=='K')
					b[i]++;
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d\n",b[i]);
	return 0; 
}
