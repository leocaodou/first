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
	char date;//树节点包含的数据
	Node* L;//左孩子
	Node* R;//右孩子
};
class W//在后序遍历时所需的类型
{
public:
	Node* ptr;//具体的节点
	char tag;//标志是否循环完左孩子或者右孩子
};
stack<Node*> s;//前序和中序遍历存放节点的栈
stack<W> s2;//后序遍历中存放节点的栈
Node* createBinaryTree()//使用前序的方法建立一棵树
{
    Node* p;
    char d;
    cin >> d;
    if(d == '0')//如果输入的树为0，说明那个节点的那个方向没有孩子
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
    return p;//返回树的头节点地址
}
void preOder(Node* r)//前序遍历
{
	while(r)
	{
		cout << r->date;
		if(r->R)
		{
			s.push(r->R);//右孩子不为空入栈，先遍历左孩子，一会再来遍历右孩子
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
void preOder2(Node* r)//使用递归实现前序遍历
{
	if(r)
    {
		cout<<r->date;
        preOder2(r->L);
        preOder2(r->R);
    }
}
void inOder(Node* r)//中序遍历
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
void inOder2(Node* r)//使用递归来实现中序遍历
{
	if(r)
	{
		inOder2(r->L);
		cout << r->date;
		inOder2(r->R);
	}
}
void lastOder(Node* r)//后序遍历
{
	W w;
	while(r || !s2.empty())
	{
		while(r)
		{
			w.ptr = r;
			w.tag = 'L';//标记为L说明回到他时已经遍历完成它左孩子
			s2.push(w); //将其入栈，稍后遍历
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
				case 'L': w.tag = 'R';s2.push(w);con = 0;r = r->R;break;//con变为1，跳出循环开始遍历r的右孩子
				case 'R': cout << r->date;r = NULL;break;//标记为R说明左右孩子全部遍历完，开始输出自己，然后判断栈的下一个元素
			}
		}
	}
}
void lastOder2(Node* r)//使用递归来实现中序遍历
{
	if(r)
	{
		lastOder2(r->L);
		lastOder2(r->R);
		cout << r->date;
	}
}
void change(Node* r)//使用递归算法交换树的所有左孩子和右孩子
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
	while( !s.empty() )//清空栈
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
  	cout << endl <<"在交换之后" << endl;
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
