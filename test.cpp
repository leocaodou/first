#include<stdio.h>
int main(void)
{
double data1,data2;
char op;
scanf("%lf %c %lf",&data1,&op,&data2); //注意输入时操作数与运算符之间要用空格隔开。
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