#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int lp(char x)
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
int rp(char x)
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
double operate(double a,double b,char c)
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
class node
{
public:
	T data;
	node* next;
};
template <typename T> 
class LinkedList
{
public:
	node<T>* head;
	LinkedList() : head(NULL){}
	void insertHead(T a)
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void pop()
	{
		node<T>* p = head->next;
		delete head;
		head = p;
	}
	void remove(T d)
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
	T& at(int x)
	{
		node<T> *p;
		p = head;
		for(int i = 0;i < x;i++)
		{
			p = p->next;
		}
		return p->data;
	}
};
void evaluate(string& a)
{
	LinkedList<double> num;
	LinkedList<char> op;
	op.insertHead('#');
	int l = 0,r = 0;
	for(int i = 0;;i++)
	{
		if((a[i] >= 48 && a[i] <= 57) || a[i] == '.')
		{
			double xi = 0,zh = 0;
			zh = a[i] - 48;
			int j = i + 1,k = 0,x = 0;
			while(1)
			{
				if(a[j] == '.')
				{
					k++;
					x++;
					if(k > 1)
					{
						cout << "ÊäÈë´íÎó";
						return;
					}
				}
				if(a[j] >= 48 && a[j] <= 57 )
				{
					if(k == 0)
						zh = zh * 10 + a[j] - 48;
					if(k == 1)
					{
						xi = xi + (a[j] - 48) * pow(0.1,x);
						x++;
					}
				}
				if((a[j] < 48 || a[j] > 57) && a[j] != '.')
				{
					i = j - 1;
					break;
				}
				j++;
			}
			num.insertHead(xi + zh);
		}
		else
		{
			if(a[i] == '(')
				l++;
			if(a[i] == ')')
			{
				r++;
				if(r > l)
				{
					cout << "ÊäÈë´íÎó" << endl;
					return;
				}
			}
			if(op.head == NULL)
			{
				cout << num.at(0);
				return;
			}
			if(lp(a[i]) == -1)
				continue;
			if(lp(a[i]) == 0 && l != r)
			{
				cout << "ÊäÈë´íÎó" << endl;
				return;
			}
			while(1)
			{	
				if(lp(op.head->data) > rp(a[i]))
				{
					double x = operate(num.at(1),num.at(0),op.at(0));
					op.pop();
					num.pop();
					num.pop();
					num.insertHead(x);
				}
				else
					break;
			}
			op.insertHead(a[i]);
			if(op.head->next != NULL)
				if(lp(op.at(0)) == rp(op.at(1)))
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
