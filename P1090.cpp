#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>
using namespace std;
int heap[10010], num = 0;
void sweap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void up(int p)
{
	while(p)
	{
		if(heap[p/2] > heap[p])
			sweap(heap[p/2] , heap[p]);
		else
			break;
		p = p / 2;
	}
}
void insert(int v)
{
	num++;
	heap[num] = v;
	up(num);
}

void down(int p)
{
	int s=p*2;
  	while(s <= num)
  	{ 
	    if(s < num&&heap[s+1]<heap[s]) 
	    	s++; 
	    if(heap[s]<heap[p])
	    {
	      	swap(heap[s],heap[p]);
	      	p=s; s=p*2;
	    }
	    else break;
  	}
}
void pop()
{
	heap[1] = heap[num];
	num--;
	down(1);
}
int top()
{
	return heap[1];
}
int main()
{
	int n,x;
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		insert(x);
	}
	for(int i = 1;i < n;i++)
	{
		int t1,t2;
		t1 = top();
		pop();
		t2 = top();
		pop();
		sum += t1 + t2;
		insert(t1 + t2);
	}
	cout << sum << endl;
}