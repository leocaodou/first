#include<stdio.h>
int main()
{
	int n,b,c,d,i=0,j;
	char a[100];
	printf("Please input number: ");
	scanf("%d",&n);
	printf("Output:\n");
	if(n<=0||n>=1000)
	{
		printf("input error!");
		return 0;
	}
	if(n/100!=0)
	{
		b=n/100;
		if(b<=3)
		{
			for(j=0;j<b;j++)
				a[j]='C';
			i=b;
		}
		if(b==4)
		{
			a[0]='C';
			a[1]='D';
			i=2;
		}
		if(b>=5&&b<9)
		{
			a[0]='D';
			for(j=1;j<=b-5;j++)
				a[j]='C';
			i=b-4;
		}
		if(b==9)
		{
			a[0]='C';
			a[1]='M';
			i=2;
		}
	}
	if(n/10%10!=0)
	{
		b=n/10%10;
		if(b<=3)
		{
			for(j=0;j<b;j++)
				a[i+j]='X';
			i=b+i;
		}
		if(b==4)
		{
			a[i]='X';
			a[i+1]='L';
			i=2+i;
		}
		if(b>=5&&b<9)
		{
			a[i]='L';
			for(j=1;j<=b-5;j++)
				a[i+j]='X';
			i=b-4+i;
		}
		if(b==9)
		{
			a[i]='X';
			a[i+1]='C';
			i=2+i;
		}
	}
	if(n%10!=0)
	{
		b=n%10;
		if(b<=3)
		{
			for(j=0;j<b;j++)
				a[i+j]='I';
			i=b+i;
		}
		if(b==4)
		{
			a[i]='I';
			a[i+1]='V';
			i=2+i;
		}
		if(b>=5&&b<9)
		{
			a[i]='V';
			for(j=1;j<=b-5;j++)
				a[i+j]='I';
			i=b-4+i;
		}
		if(b==9)
		{
			a[i]='I';
			a[i+1]='X';
			i=2+i;
		}
	}
	printf("%d=%s",n,a);
	return 0;	
}
