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
		printf("���ҳɹ�");
		break;
		}
		if(i==10)
		printf("û���ҵ�"); 
	}
	return 0;
}
