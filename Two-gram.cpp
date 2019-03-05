#include<stdio.h>
int main()
{
	int n=0,i,k=0,j,a=0,c=0,max=0,x;
	scanf("%d",&n);
	getchar();
	char str[n+1],str1[n][3];
	gets(str);
	for(i=0;i<n;i++)
	{
		a=0;
		c=0;
		for(j=0;j<=n;j++)
		{
			if(str[i]==str1[j][0]&&str[i+1]==str1[j][1])
			{
				a=1;
				break;
			}
		}
		if(a==1)
		{
			continue;	
		}
		str1[k][0]=str[i];
		str1[k][1]=str[i+1];
		for(j=0;j<n-1;j++)
		{
			if(str[j]==str1[k][0]&&str[j+1]==str1[k][1])
				c++;
		}
		if(c>max)
		{
			x=i;
			max=c;
		}
	}
	printf("%c%c",str[x],str[x+1]);
	return 0;
}
