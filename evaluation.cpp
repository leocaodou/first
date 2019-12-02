#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int lp(char x)//lp函数，用与返回符号的优先级
{
	switch(x)
	{
		case '+' : return 3;break;
		case '-' : return 3;break;
		case '*' : return 5;break;
		case '/' : return 5;break;
		case '(' : return 1;break;
		case ')' : return 6;break;
		case '#' : return 0;break;
		default :return -1;break;
	}
}
int rp(char x)//rp函数，用与返回符号的优先级，用于和lp比较
{
	switch(x)
	{
		case '+' : return 2;break;
		case '-' : return 2;break;
		case '*' : return 4;break;
		case '/' : return 4;break;
		case '(' : return 6;break;
		case ')' : return 1;break;
		case '#' : return 0;break;
		default :return -1;
	}
}
double operate(double a,double b,char c)//运算函数，用于计算出具体的某段结果
{
	switch(c)
	{
		case '+' : return a + b;break;
		case '-' : return a - b;break;
		case '*' : return a * b;break;
		case '/' : return a / b;break;
		default :return -1;break;
	}
}
template <typename T>
class node//栈的每个节点
{
public:
	T data;
	node* next;
};
template <typename T> 
class Stack//栈的定义
{
public:
	node<T>* head;
	Stack() : head(NULL){}
	void insertHead(T a)//在栈中插入元素
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void pop()//删除元素
	{
		node<T>* p = head->next;
		delete head;
		head = p;
	}
	void remove(T d)//删除具体的某个元素
	{
		for(node<T>* i = head;i != NULL;)
		{
			if(head->data == d)
			{
				node<T>* p = i;
				head = p->next;
				i = p->next;
				delete p;
			}
			else if(i->next)
			{
				if(i->next->data == d)
				{
					node<T>* p = i->next;
					i->next = p->next;
					i = i->next;
					delete p;
				}
				else
					i = i->next;
			}
			else
				i = i->next;
		}
	}
	T& at(int x)//返回具体某一位上的元素的数据
	{
		node<T> *p;
		p = head;
		for(int i = 0;i < x;i++)
		{
			p = p->next;
		}
		return p->data;
	}
	node<T>* find(int x)//返回具体某一位上的元素的节点地址
	{
		node<T> *p;
		p = head;
		for(int i = 0;i < x;i++)
		{
			p = p->next;
		}
		return p;
	}
};
void evaluate(string& a)//计算器函数，传入一个需要计算的算式
{
	Stack<double> num;//用与存储数字的栈
	Stack<char> op;//用于存储运算符的栈
	op.insertHead('#');//把运算符的栈底放入‘#’这样知道在什么时候结束
	int l = 0,r = 0;
	for(int i = 0;;i++)//循环读取传入的字符串然后进行分类，分为数字和运算符
	{
		if((a[i] >= 48 && a[i] <= 57) || a[i] == '.')//如果这个字符为数字或小数点
		{
			double xi = 0,zh = 0;//xi表示这段数字的小数部分，zh表示这段数的整数部分
			zh = a[i] - 48;//字符具体代表的数字
			int j = i + 1,k = 0,x = 0;//j+1开始判断下一个字符，k用于存储这段数字当中小数点个数，x为小数的位数
			while(1)
			{
				if(a[j] == '.')
				{
					k++;
					x++;//有一个小数点，接下来为小数，小数位数为1
					if(k > 1)//小数点个数大于1，输入错误，程序结束
					{
						cout << "输入错误";
						return;
					}
				}
				if(a[j] >= 48 && a[j] <= 57 )
				{
					if(k == 0)
						zh = zh * 10 + a[j] - 48;//k为0说明是整数部分，按整数来计算
					if(k == 1)
					{
						xi = xi + (a[j] - 48) * pow(0.1,x);//k为1说明是小数部分，按小数来计算
						x++;
					}
				}
				if((a[j] < 48 || a[j] > 57) && a[j] != '.')//若该字符不为数字或‘.’，重新判断该字符
				{
					i = j - 1;
					break;
				}
				j++;
			}
			num.insertHead(xi + zh);//把小数和整数合并为这段数
		}
		else
		{
			if(a[i] == '(')
				l++;
			if(a[i] == ')')
			{
				r++;
				if(r > l)//若右括号多于左括号，说明输入错误
				{
					cout << "输入错误" << endl;
					return;
				}
			}
			if(a[i] == ' ')//如果算式中有空格则输入错误
			{
				cout << "输入错误" << endl;
				return;
			}
			if(op.head == NULL)
			{
				cout << num.at(0);
				return;//运算符栈空，直接输出结果
			}
			if(lp(a[i]) == -1)//如果字符为其他字母不影响结果
				continue;
			if(lp(a[i]) == 0 && l != r)
			{
				cout << "输入错误" << endl;
				return;
			}
			while(1)
			{	
				if(lp(op.head->data) > rp(a[i]))//当前的符号右优先级如果小于栈顶的符号的左优先级，开始运算
				{
					if(num.find(1) == NULL ||num.find(0) == NULL)//如果计算的数字最后少于2个，说明输入错误
					{
						cout << "输入错误" << endl;
						return;
					}
					double x = operate(num.at(1),num.at(0),op.at(0));//运算
					op.pop();//删除运算了后的符号
					num.pop();
					num.pop();
					num.insertHead(x);
				}
				else
					break;
			}
			op.insertHead(a[i]);
			if(op.head->next != NULL)
				if(lp(op.at(0)) == rp(op.at(1)))//消除左右括号以及#
				{
					op.pop();
					op.pop();
				}
		}
	}
}
int main()
{
	string a;
	cin >> a;
	evaluate(a);
	return 0;
}