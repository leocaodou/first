#include<stdio.h>
int main()
{
	int zuida(int),zuixiao(int);
	int a,b,c,i=1;
	printf("Please input n: ");
	scanf("%d",&a);
	printf("Output:\n");
	if(a==0||a>9999)
		printf("Input error!\n");
	else
	while(1)
	{
		b=zuida(a);
		c=zuixiao(a);
		a=b-c;
		printf("[%d]: %d-%d=%d\n",i,b,c,a);
		if(a==6174)
			break;
		i++;
	}
	return 0;
}
int zuida(int a)
{
	int b[4],i,j,t,c;
	b[0]=a/1000;
	b[1]=(a-b[0]*1000)/100;
	b[2]=(a-b[0]*1000-b[1]*100)/10;
	b[3]=a-b[0]*1000-b[1]*100-b[2]*10;
	for(i=0;i<4-1;i++)
	{
		for(j=0;j<4-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	c=b[0]*1000+b[1]*100+b[2]*10+b[3];
	return c;
}
int zuixiao(int a)
{
	int b[4],i,j,t,c;
	b[0]=a/1000;
	b[1]=(a-b[0]*1000)/100;
	b[2]=(a-b[0]*1000-b[1]*100)/10;
	b[3]=a-b[0]*1000-b[1]*100-b[2]*10;
	for(i=0;i<4-1;i++)
	{
		for(j=0;j<4-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	c=b[0]*1000+b[1]*100+b[2]*10+b[3];
	return c;
}
