#include <stdio.h>
int main()
{
	int n,i=1,sum=0,a[10],j,z,t=1,sum1=0,b[10],l;
	printf("请输入1-40000之间的任意一个整数:\n");
	scanf("%d",&n);
	printf("Output:\n");
	if(n<1||n>40000)
	{
	printf("您输入的数字不在规定范围内!");
	return 0;
	}
	l=n;z=n*n;
	 while(n)
	 {
	 	a[i]=n%10;
	 	n=n/10;
	 	i++;
	 }
	 for(j=1;j<i;j++)
	 sum=sum+a[j];
	 while(z)
	 {
	 	b[t]=z%10;
	 	z=z/10;
	 	t++;
	 }
	  for(j=1;j<t;j++)
	 sum1=sum1+b[j];
	 printf("%d的各位数之和为%d,%d平方后各位数之和为%d",l,sum,l,sum1);
	 return 0;
}
