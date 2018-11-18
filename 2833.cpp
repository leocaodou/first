#include<stdio.h>
#include<string.h>
int main()
{
	char str[100000];
	int i=0,j,k,m=0,n=0,b=0,t,e,f,c;
	gets(str);
	scanf("%d",&k);
	c=strlen(str);
	int a[c]={1};
	for(i=0;i<c;i++)
	{
		n=0;
		for(j=0;j<=i;j++)
		{
			if(str[j]==str[i])
			{
				n=1;
				break;
			}
		}
		if(n==1)
			continue;
		b=b+1;
		for(j=i;j<=k;j++)
		{
			 if(j==i)
			 {
			 	a[i]=a[i]+1;
			 }
		}
	}
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
	printf("%d",e);
	return 0;
}
