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
	char date;
	Node* L;
	Node* R;
};
class W
{
public:
	Node* ptr;
	char tag;
};
stack<Node*> s;
stack<W> s2;
Node* createBinaryTree()
{
    Node* p;
    char d;
    cin >> d;
    if(d == '0')
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
    return p;
}
void preOder(Node* r)
{
	while(r)
	{
		cout << r->date;
		if(r->R)
		{
			s.push(r->R);
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
void preOder2(Node* r)
{
	if(r)
    {
		cout<<r->date;
        preOder2(r->L);
        preOder2(r->R);
    }
}
void inOder(Node* r)
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
void lastOder(Node* r)
{
	W w;
	while(r || !s2.empty())
	{
		while(r)
		{
			w.ptr = r;
			w.tag = 'L';
			s2.push(w); 
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
				case 'L': w.tag = 'R';s2.push(w);con = 0;r = r->R;break;
				case 'R': cout << r->date;r = NULL;break;
			}
		}
	}
}
int main()
{
	Node *r,*p = createBinaryTree();
	r = p;
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
