#include <stdio.h>
int main()
{
	int n,i=1,sum=0,a[10],j,z,t=1,sum1=0,b[10],l;
	printf("������1-40000֮�������һ������:\n");
	scanf("%d",&n);
	printf("Output:\n");
	if(n<1||n>40000)
	{
	printf("����������ֲ��ڹ涨��Χ��!");
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
	 printf("%d�ĸ�λ��֮��Ϊ%d,%dƽ�����λ��֮��Ϊ%d",l,sum,l,sum1);
	 return 0;
}
