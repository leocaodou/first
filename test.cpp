#include<stdio.h>
int main(void)
{
double data1,data2;
char op;
scanf("%lf %c %lf",&data1,&op,&data2); //ע������ʱ�������������֮��Ҫ�ÿո������
switch(op)
{
	case '+':printf("%.2lf+%.2lf=%.2lf",data1,data2,data1+data2);break;
	case '-':
	printf("%.2lf-%.2lf=%.2lf",data1,data2,data1-data2);
	break;
	case '*':
	printf("%.2lf*%.2lf=%.2lf",data1,data2,data1*data2);break;
	case '/':
	if (data2==0)
	printf("by 0 div");
	else
	printf("%.2lf/%.2lf=%.2lf",data1,data2,data1/data2);
	break;
}
return 0;
}