#include <stdio.h>
void swap(int *d1, int *d2) //第一种方法
{//把主函数中的定义的变量的地址传到函数中，通过交换指针指向的地址的数字来达到目的
	int p;     //定义一个整型自变量来用于交换两个指针，不能通过定义空指针来交换指针
	p = *d1;
	*d1 = *d2;
	*d2 = p;
}
void swap(int &d1, int &d2)//第二种方法
{//使用引用符号“&”来把主函数的变量值赋给函数形参，这样如同指针一样，修改形参值也能修改原本变量的值
	int p;
	p = d1;
	d1 = d2;
	d2 = p;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (&a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (a, b);
    printf("a:%d, b:%d\n", a, b);
    return 0;
}