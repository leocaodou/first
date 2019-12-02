#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stack>
using namespace std;
int N;

class Node
{
public:
	char date;//���ڵ����������
	Node* L;//����
	Node* R;//�Һ���
};
class W//�ں������ʱ���������
{
public:
	Node* ptr;//����Ľڵ�
	char tag;//��־�Ƿ�ѭ�������ӻ����Һ���
};
stack<Node*> s;//ǰ������������Žڵ��ջ
stack<W> s2;//��������д�Žڵ��ջ
Node* createBinaryTree()//ʹ��ǰ��ķ�������һ����
{
    Node* p;
    char d;
    cin >> d;
    if(d == '0')//����������Ϊ0��˵���Ǹ��ڵ���Ǹ�����û�к���
    {
        p = NULL;
    }
    else
    {
        p = new Node();
        p->date = d;
        p->L = createBinaryTree();
        p->R = createBinaryTree();
    }
    return p;//��������ͷ�ڵ��ַ
}
void preOder(Node* r)//ǰ�����
{
	while(r)
	{
		cout << r->date;
		if(r->R)
		{
			s.push(r->R);//�Һ��Ӳ�Ϊ����ջ���ȱ������ӣ�һ�����������Һ���
		}
		if(r->L)
			r = r->L;
		else
		{
			if(s.empty())
				return;
			else
			{
				r = s.top();
				s.pop();
			}
		}
	}
}
void preOder2(Node* r)//ʹ�õݹ�ʵ��ǰ�����
{
	if(r)
    {
		cout<<r->date;
        preOder2(r->L);
        preOder2(r->R);
    }
}
void inOder(Node* r)//�������
{
	while(r || !s.empty())
	{
		while(r)
		{
			s.push(r);
			r = r->L;
		}
		if(!s.empty())
		{
			r = s.top();
			s.pop();
			cout << r->date;
			r = r->R;
		}
	}
}
void inOder2(Node* r)//ʹ�õݹ���ʵ���������
{
	if(r)
	{
		inOder2(r->L);
		cout << r->date;
		inOder2(r->R);
	}
}
void lastOder(Node* r)//�������
{
	W w;
	while(r || !s2.empty())
	{
		while(r)
		{
			w.ptr = r;
			w.tag = 'L';//���ΪL˵���ص���ʱ�Ѿ��������������
			s2.push(w); //������ջ���Ժ����
			r = r->L;
		}
		int con = 1;
		while(con && !s2.empty())
		{
			w = s2.top();
			s2.pop();
			r = w.ptr;
			switch(w.tag)
			{
				case 'L': w.tag = 'R';s2.push(w);con = 0;r = r->R;break;//con��Ϊ1������ѭ����ʼ����r���Һ���
				case 'R': cout << r->date;r = NULL;break;//���ΪR˵�����Һ���ȫ�������꣬��ʼ����Լ���Ȼ���ж�ջ����һ��Ԫ��
			}
		}
	}
}
void lastOder2(Node* r)//ʹ�õݹ���ʵ���������
{
	if(r)
	{
		lastOder2(r->L);
		lastOder2(r->R);
		cout << r->date;
	}
}
void change(Node* r)//ʹ�õݹ��㷨���������������Ӻ��Һ���
{
	if(r)
	{
		Node* t;
		t = r->R;
		r->R = r->L;
		r->L = t;
		change(r->L);
    	change(r->R);
	}
}
int main()
{
	Node *r,*p = createBinaryTree();
	r = p;
	preOder(r);
	cout << endl;
	preOder2(r);
	cout << endl;
	while( !s.empty() )//���ջ
    	s.pop();
    r = p;
    inOder(r);
    cout << endl;
	inOder2(r);
	cout << endl;
    while( !s.empty() )
    	s.pop();
    r = p;
  	lastOder(r);
  	cout << endl;
	lastOder2(r);
	cout << endl;
  	change(r);
  	while( !s.empty() )
    	s.pop();
  	cout << endl <<"�ڽ���֮��" << endl;
  	preOder(r);
	cout << endl;
//	preOder2(r);
//	cout << endl;
	while( !s.empty() )
    	s.pop();
    r = p;
    inOder(r);
    cout << endl;
    while( !s.empty() )
      s.pop();
    r = p;
  	lastOder(r);
  	return 0;
}
