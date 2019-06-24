#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class node//链表的元素
{
public:
	int data;//用于存放数据
	node* next;//用于指向下一个node，形成相连的链表
	friend ostream& operator << (ostream& ,const node& );//友元函数，对于 << 操作符的重载；
};
ostream& operator << (ostream& out ,const node& n)//操作符重载，为了node的更好的输出
{
	out << n.data;
	return out;
}
class LinkedList//单链表类
{
public:
	node* head;//唯一的成员变量，用于指向链表的开头
	LinkedList() : head(NULL){}//创建一个空链表，所以head指向空
	void insertHead(int a)//在头插入元素的函数
	{
		node* p;//创建一个指针
		p = new node;//开辟出一个新空间用于存放插入的数
		p->data = a;
		p->next = head;//由于是头插入，让原本的第一个元素变为第二个
		head = p;//再让头变成现在这个新加入的元素
	}
	void remove(int d)//用于删除链表当中的所有某个元素
	{
		for(node* i = head;i != NULL;)//从链表的头开始遍历
		{//由于是单向链表，所以当判断到i指向的某一个链表需要删除时，我们无法得知上一个元素的地址，无法形成链表，因此我们需要判断i指向的下一个元素是否需要删除
			if(head->data == d)//当然也有特殊情况，就是当head需要删除时，就直接删除
			{
				node* p = i;
				head = p->next;//由于之前的head被删除，head就指向了下一个元素
				i = p->next;//接着i也指向下一个元素去判断
				delete p;
			}
			else if(i->next)//如果不是head需要删除的话，就判断按照正常情况来判断
			{
				if(i->next->data == d)//如果i的next元素需要被删除
				{
					node* p = i->next;//让p指向需要被删除的元素
					i->next = p->next;//i跳过需要删除的元素，指向下一个元素
					i = i->next;//i也就继续判断
					delete p;
				}
				else
					i = i->next;
			}
			else
				i = i->next;
		}
	}
	node* find(int d)//在链表中寻找某个值的元素
	{
		node* i;
		for(i = head;i != NULL;i = i->next)
		{
			if(i->data == d)
			{
				return i;//找到的话就返回这个地址
			}
		}
		cout << "not find" << endl;
		return NULL;
	}
	void travalList()//遍历链表所有的元素，并输出
	{
		if(head)//如果head没有指向空，遍历输出
		{
			for(node* i = head;i != NULL;i = i->next)
			{
				cout << *i << ' ';
			}
		}
		else//head为空，输出空链表
			cout << "这是一个空链表"; 
			cout << endl;
	}
	void deleteList()//用于删除链表的所有开出的空间
	{
		for(node* i = head;i != NULL;)
		{
			node* p = i;
			i = i->next;//i挨个遍历所有元素，一个个删除
			delete p;
			if(i == NULL)
				break;
		}
		head = NULL;

	}
	bool isEmpty()//用于判断链表是否为空
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
	for(int i = 0; i < 10;i++)//一个个把0~9插入到链表
	{
		a.insertHead(i);
	}
	a.travalList();
	int n;
	while(1)//循环对链表进行操作
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
			cin >> n;
			node* p = a.find(n);
			if(p)
				cout << *p << endl << "地址是" << p << endl;
		}
		a.travalList();
		if(k == 3)
		{
			a.deleteList();
			break;
		}
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
