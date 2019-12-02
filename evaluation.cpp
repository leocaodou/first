#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int lp(char x)//lp���������뷵�ط��ŵ����ȼ�
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
int rp(char x)//rp���������뷵�ط��ŵ����ȼ������ں�lp�Ƚ�
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
double operate(double a,double b,char c)//���㺯�������ڼ���������ĳ�ν��
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
class node//ջ��ÿ���ڵ�
{
public:
	T data;
	node* next;
};
template <typename T> 
class Stack//ջ�Ķ���
{
public:
	node<T>* head;
	Stack() : head(NULL){}
	void insertHead(T a)//��ջ�в���Ԫ��
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void pop()//ɾ��Ԫ��
	{
		node<T>* p = head->next;
		delete head;
		head = p;
	}
	void remove(T d)//ɾ�������ĳ��Ԫ��
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
	T& at(int x)//���ؾ���ĳһλ�ϵ�Ԫ�ص�����
	{
		node<T> *p;
		p = head;
		for(int i = 0;i < x;i++)
		{
			p = p->next;
		}
		return p->data;
	}
	node<T>* find(int x)//���ؾ���ĳһλ�ϵ�Ԫ�صĽڵ��ַ
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
void evaluate(string& a)//����������������һ����Ҫ�������ʽ
{
	Stack<double> num;//����洢���ֵ�ջ
	Stack<char> op;//���ڴ洢�������ջ
	op.insertHead('#');//���������ջ�׷��롮#������֪����ʲôʱ�����
	int l = 0,r = 0;
	for(int i = 0;;i++)//ѭ����ȡ������ַ���Ȼ����з��࣬��Ϊ���ֺ������
	{
		if((a[i] >= 48 && a[i] <= 57) || a[i] == '.')//�������ַ�Ϊ���ֻ�С����
		{
			double xi = 0,zh = 0;//xi��ʾ������ֵ�С�����֣�zh��ʾ���������������
			zh = a[i] - 48;//�ַ�������������
			int j = i + 1,k = 0,x = 0;//j+1��ʼ�ж���һ���ַ���k���ڴ洢������ֵ���С���������xΪС����λ��
			while(1)
			{
				if(a[j] == '.')
				{
					k++;
					x++;//��һ��С���㣬������ΪС����С��λ��Ϊ1
					if(k > 1)//С�����������1��������󣬳������
					{
						cout << "�������";
						return;
					}
				}
				if(a[j] >= 48 && a[j] <= 57 )
				{
					if(k == 0)
						zh = zh * 10 + a[j] - 48;//kΪ0˵�����������֣�������������
					if(k == 1)
					{
						xi = xi + (a[j] - 48) * pow(0.1,x);//kΪ1˵����С�����֣���С��������
						x++;
					}
				}
				if((a[j] < 48 || a[j] > 57) && a[j] != '.')//�����ַ���Ϊ���ֻ�.���������жϸ��ַ�
				{
					i = j - 1;
					break;
				}
				j++;
			}
			num.insertHead(xi + zh);//��С���������ϲ�Ϊ�����
		}
		else
		{
			if(a[i] == '(')
				l++;
			if(a[i] == ')')
			{
				r++;
				if(r > l)//�������Ŷ��������ţ�˵���������
				{
					cout << "�������" << endl;
					return;
				}
			}
			if(a[i] == ' ')//�����ʽ���пո����������
			{
				cout << "�������" << endl;
				return;
			}
			if(op.head == NULL)
			{
				cout << num.at(0);
				return;//�����ջ�գ�ֱ��������
			}
			if(lp(a[i]) == -1)//����ַ�Ϊ������ĸ��Ӱ����
				continue;
			if(lp(a[i]) == 0 && l != r)
			{
				cout << "�������" << endl;
				return;
			}
			while(1)
			{	
				if(lp(op.head->data) > rp(a[i]))//��ǰ�ķ��������ȼ����С��ջ���ķ��ŵ������ȼ�����ʼ����
				{
					if(num.find(1) == NULL ||num.find(0) == NULL)//�������������������2����˵���������
					{
						cout << "�������" << endl;
						return;
					}
					double x = operate(num.at(1),num.at(0),op.at(0));//����
					op.pop();//ɾ�������˺�ķ���
					num.pop();
					num.pop();
					num.insertHead(x);
				}
				else
					break;
			}
			op.insertHead(a[i]);
			if(op.head->next != NULL)
				if(lp(op.at(0)) == rp(op.at(1)))//�������������Լ�#
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