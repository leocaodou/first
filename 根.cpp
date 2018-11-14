#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float d,e;
	float swe(int,int,int);
	float lkh(int,int,int);
	float okn(int,int,int);
	scanf("%d%d%d",&a,&b,&c);
	if(b*b-4*a*c<0)
		printf("无实数根\n");
	if((b*b-4*a*c)==0)
	{
		d=swe(a,b,c);
		printf("%.2f",d);
	}
	if(b*b-4*a*c>0)
	{
		d=lkh(a,b,c);
		e=okn(a,b,c);
		printf("%.2f\n",d);
		printf("%.2f\n",e);
	}
	return 0;
 } 
 
 
float swe(int x,int y,int z)
{
	float d;
	d=(-y)/(2*z);
	return d;
} 
float lkh(int x,int y,int z)
{
	float d;
	d=((-y)+(sqrt(y*y-4*x*z)))/(2*x);
	return d;
}
float okn(int x,int y,int z)
{
	float d;
	d=((-y)-(sqrt(y*y-4*x*z)))/(2*x);
	return d;
}
