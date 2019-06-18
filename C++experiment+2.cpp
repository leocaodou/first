#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	friend ostream& operator << (ostream& ,const node& );
};
ostream& operator << (ostream& out ,const node& n)
{
	out << n.data;
	return out;
}
class LinkedList
{
public:
	node* head;
	LinkedList() : head(NULL){}
	void insertHead(int a)
	{
		node* p;
		p = new node;
		p->data = a;
		p->next = head;
		head = p;
	}
	void remove(int d)
	{
		for(node* i = head;i != NULL;i = i->next)
		{
			if(i->next)
			{
				if(i->next->data == d)
				{
					node* p = i->next;
					i->next = p->next;
					delete p;
				}
			}
			if(i->data == d)
			{
				node* p = i;
				head = p->next;
				i = head->next;
				delete p;
			}
		}
	}
	node* find(int d)
	{
		node* i;
		for(i = head;i != NULL;i = i->next)
		{
			if(i->data == d)
			{
				return i;
			}
		}
		cout << "not find";
		return NULL;
	}
	void travalList()
	{
		for(node* i = head;i != NULL;i = i->next)
		{
			cout << *i << ' ';
		}
		cout << endl;
	}
	void deleteList()
	{
		for(node* i = head;i != NULL;i = i->next)
		{
			if(i == NULL)
				break;
			node* p = i;
			i = i->next;
			delete p;
			if(i == NULL)
				break;
		}
		head = NULL;

	}
	bool isEmpty()
	{
		if(head == NULL)
			return true;
		else
			return false;
	}
};
int main()
{
	LinkedList a;
	for(int i = 0; i < 10;i++)
	{
		a.insertHead(i);
	}
	a.travalList();
	int n;
	while(1)
	{
		int k;
		cout << "请问你是想要删除（1）还是查找（2）一个数？或是删除列表（3）" << endl;
		cin >> k;
		if(k == 1)
		{
			cout << "想要删除哪个？" << endl;
			cin >> n;
			a.remove(n);
		}
		if(k == 2)
		{
			cout << "想要查找哪个？" << endl;
			node* p = a.find(5);
			cout << *p << endl;
		}
		a.travalList();
		if(k == 3)
			a.deleteList();
		if(a.isEmpty())
		{
			cout << "a is empty" << endl;
		}
		else
			cout << "a is not empty" << endl;
	}
	if(a.isEmpty())
	{
		cout << "a is empty" << endl;
	}
	else
		cout << "a is not empty" << endl;
	return 0;
}