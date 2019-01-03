#include<stdio.h>
int main()
{
	int n,a,b,c,i,j=0;
	printf("请输入现在队伍的列数:\n");
	scanf("%d",&n);
	int t=0,min;
	printf("%d\n",n);
	printf("拉面的制作时间:\n");
	scanf("%d",&a);
	printf("%d\n",a);
	printf("烤肉的制作时间:\n");
	scanf("%d",&b);
	printf("%d\n",b);
	printf("饮料的制作时间:\n");
	scanf("%d",&c);
	printf("%d\n",c);
	for(i=n;i>0;i--)
	{
		j=0;
		t=0;
		printf("第%d对的排列情况:\n",i);
		char p[11];
		scanf("%s",p);
		getchar();
		printf("%s",p);
		putchar(10);
		while(1)
		{
			if(p[j]=='a'||p[j]=='A')
				t=t+a+b+c;
			if(p[j]=='b'||p[j]=='B')
				t=t+2*a+b;
			if(p[j]=='c'||p[j]=='C')
				t=t+3*a+3*b+2*c;
			if(p[j]=='\0')
				break;
			j++;
		}
            if(i==n)
				min=t;
			if(t<min)
				min=t;
	}
	printf("\nOutput:\n最快吃上饭的那个队伍的排队时间:%d",min);
}
