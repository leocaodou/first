#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,i1,i2,i3,i;
	scanf("%d%d",&a,&b);
	c=a+b;
	int jiwei(int);
	int fan(int,int);
	i1=jiwei(a);
	i2=jiwei(b);
	i3=jiwei(c);
	d=fan(a,i1);
	e=fan(b,i2);
	f=fan(c,i3);
	if(d+e==f)
	printf("%d",c);
	else
	printf("NO");
} 
int fan(int x,int y)
{
	int g[y+1],i,j,a=0,t=0,b=0;
	b=pow(10,y-1);
	g[y]=x/b;
	if(y>=2)
	for(i=y-1;i>=1;i--)
	{
		b=pow(10,i-1);
		t=x/b;
		for(j=i+1;j<=y;j++)
		{
			b=pow(10,j-i);
			t=t-g[j]*b;
		}
		g[i]=t;
	}
	for(i=1;i<=y;i++)
	{
		b=pow(10,i-1);
		a=a+g[y-i+1]*b;
	}
	return a;
}
int jiwei(int x)
{
	int i,g;
	for(i=1;i<5;i++)
	{
		g=pow(10,i);
		if(x/g==0)
		break;
	}
	return i;
}
