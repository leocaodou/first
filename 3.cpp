#include<stdio.h>
int main()
{
	int a[11],age,i;
	for(i=1;i<=10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&age);
	for(i=1;i<=10;i++)
	{
		if(a[i]==age)
		{ 
		printf("查找成功");
		break;
		}
		if(i==10)
		printf("没有找到"); 
	}
	return 0;
}
