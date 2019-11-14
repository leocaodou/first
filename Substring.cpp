#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
#define MAX 0x3f3f3f3f
class W
{
public:
	int d;
	W* next;
	W():d(0),next(NULL){}
	W(int x) : d(x),next(NULL){}
};
class Node
{
public:
	char data;
	int indegree;
	W* firstavc;
	void push(int x)
	{
		W* newW = new W(x);
		if(firstavc == NULL)
		{
			firstavc = newW;
		}
		else
		{
			newW->next = firstavc;
			firstavc = newW;
		}
	}
	Node() : data('\0'),indegree(0),firstavc(NULL){}
};
Node A[300000];
int dp(int x)
{
	W* p = A[x].firstavc;
	while(p)
	{
		
	}
}
int main()
{	
	int n,m,k = 0;
	stack<int> s;
	stack<int> s2;
	cin >> n >> m;
	bool map[n][n];
	memset(map,false,sizeof(map));
	bool B[n];
	char c;
	getchar();
	for(int i = 0;i < n;i++)
	{
		c = getchar();
		A[i].data = c;
	}
	for(int i = 0;i < m;i++)
	{
		int x,y;
		cin >> x >> y;
		if(!map[x - 1][y - 1] && x != y)
		{
			map[x - 1][y - 1] = true;
			A[x - 1].push(y - 1);
			A[y - 1].indegree++;
		}
	}
	for(int i = 0;i < n;i++)
	{
		if(A[i].indegree == 0)
		{
			s.push(i);
			s2.push(i);
			k++;
		}
	}
	while(!s.empty())
	{
		int j = s.top();
		s.pop();
		W* q = A[j].firstavc;
		while(q != NULL)
		{
			A[q->d].indegree--;
			if(A[q->d].indegree == 0)
			{
				s.push(q->d);
				k++;
			}
			q = q->next;
		}
	}
	if(k < n)
	{
		cout << -1;
		return 0;
	}
	while(s2.empty())
	{
		int j = s2.top()
		int ans = dp(j);
		if(max < ans)
			max = ans;
	}
	cout << max;
}
