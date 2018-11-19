#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,m,e,t,c;
	char b[11];
	scanf("%s",&b);
	c=strlen(b);
	int k=10;
	int a[c]={1,4,6,2,3,4,6,3,2,1};
	for(i=0;i<c;i++)
	{
		for(j=0;j<c-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	i=0;
	while(m<=k)
	{
		m=m+a[i];
	}
	e=k-i+1;
	printf("%d",c);
	return 0;
}
