#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class node//�����Ԫ��
{
public:
	int data;//���ڴ������
	node* next;//����ָ����һ��node���γ�����������
	friend ostream& operator << (ostream& ,const node& );//��Ԫ���������� << �����������أ�
};
ostream& operator << (ostream& out ,const node& n)//���������أ�Ϊ��node�ĸ��õ����
{
	out << n.data;
	return out;
}
class LinkedList//��������
{
public:
	node* head;//Ψһ�ĳ�Ա����������ָ������Ŀ�ͷ
	LinkedList() : head(NULL){}//����һ������������headָ���
	void insertHead(int a)//��ͷ����Ԫ�صĺ���
	{
		node* p;//����һ��ָ��
		p = new node;//���ٳ�һ���¿ռ����ڴ�Ų������
		p->data = a;
		p->next = head;//������ͷ���룬��ԭ���ĵ�һ��Ԫ�ر�Ϊ�ڶ���
		head = p;//����ͷ�����������¼����Ԫ��
	}
	void remove(int d)//����ɾ�������е�����ĳ��Ԫ��
	{
		for(node* i = head;i != NULL;)//�������ͷ��ʼ����
		{//�����ǵ����������Ե��жϵ�iָ���ĳһ��������Ҫɾ��ʱ�������޷���֪��һ��Ԫ�صĵ�ַ���޷��γ��������������Ҫ�ж�iָ�����һ��Ԫ���Ƿ���Ҫɾ��
			if(head->data == d)//��ȻҲ��������������ǵ�head��Ҫɾ��ʱ����ֱ��ɾ��
			{
				node* p = i;
				head = p->next;//����֮ǰ��head��ɾ����head��ָ������һ��Ԫ��
				i = p->next;//����iҲָ����һ��Ԫ��ȥ�ж�
				delete p;
			}
			else if(i->next)//�������head��Ҫɾ���Ļ������жϰ�������������ж�
			{
				if(i->next->data == d)//���i��nextԪ����Ҫ��ɾ��
				{
					node* p = i->next;//��pָ����Ҫ��ɾ����Ԫ��
					i->next = p->next;//i������Ҫɾ����Ԫ�أ�ָ����һ��Ԫ��
					i = i->next;//iҲ�ͼ����ж�
					delete p;
				}
				else
					i = i->next;
			}
			else
				i = i->next;
		}
	}
	node* find(int d)//��������Ѱ��ĳ��ֵ��Ԫ��
	{
		node* i;
		for(i = head;i != NULL;i = i->next)
		{
			if(i->data == d)
			{
				return i;//�ҵ��Ļ��ͷ��������ַ
			}
		}
		cout << "not find" << endl;
		return NULL;
	}
	void travalList()//�����������е�Ԫ�أ������
	{
		if(head)//���headû��ָ��գ��������
		{
			for(node* i = head;i != NULL;i = i->next)
			{
				cout << *i << ' ';
			}
		}
		else//headΪ�գ����������
			cout << "����һ��������"; 
			cout << endl;
	}
	void deleteList()//����ɾ����������п����Ŀռ�
	{
		for(node* i = head;i != NULL;)
		{
			node* p = i;
			i = i->next;//i������������Ԫ�أ�һ����ɾ��
			delete p;
			if(i == NULL)
				break;
		}
		head = NULL;

	}
	bool isEmpty()//�����ж������Ƿ�Ϊ��
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
	for(int i = 0; i < 10;i++)//һ������0~9���뵽����
	{
		a.insertHead(i);
	}
	a.travalList();
	int n;
	while(1)//ѭ����������в���
	{
		int k;
		cout << "����������Ҫɾ����1�����ǲ��ң�2��һ����������ɾ���б�3��" << endl;
		cin >> k;
		if(k == 1)
		{
			cout << "��Ҫɾ���ĸ���" << endl;
			cin >> n;
			a.remove(n);
		}
		if(k == 2)
		{
			cout << "��Ҫ�����ĸ���" << endl;
			cin >> n;
			node* p = a.find(n);
			if(p)
				cout << *p << endl << "��ַ��" << p << endl;
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
