#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
map<char,int> Map;
bool visit[20];
char l[25];
int v,m,pp = 0;
queue<int> Q;
class vodelist
{
public:
	int x;
	vodelist* next;
	vodelist(int a) : x(a){}
};
class Vnode
{
public:
	char x;
	vodelist* next = NULL;
	void add(char a)
	{
		vodelist *p = new vodelist(Map[a]);
		p->next = next;
		next = p;
	}
};
Vnode Graph[20];
void CreatAdjGraph()
{
	cin >> v >> m;
	for (int i = 0; i < v; ++i)
	{
		char c;
		cin >> c;
		Graph[i].x = c;
		Map[c] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		char x,y;
		cin >> x >> y;
		Graph[Map[x]].add(y);
		Graph[Map[y]].add(x);
	}
}
void dfs(int t)
{
	cout << Graph[t].x << ' ';
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])
		{
			visit[p->x] = true;
			dfs(Map[Graph[p->x].x]);
		}
		p = p->next;
	}
}
void bfs(int t)
{
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])
		{
			visit[p->x] = true;
			cout << Graph[p->x].x << ' ';
			Q.push(p->x);
		}
		p = p->next;
	}
	p = Graph[t].next;
	while(!Q.empty())
	{
		int q = Q.front();
		Q.pop();
		bfs(q);
		p = p->next;
	}
}
void find(char x,char y,int k)
{
	l[pp] = x;
	pp++;
	visit[Map[x]] = true;
	vodelist* p = Graph[Map[x]].next;
	if(k != 0)
	{
		while(p)
		{
			if(!visit[p->x])
			{
				visit[p->x] = true;
				find(Graph[p->x].x , y, k - 1);
				pp--;
				visit[p->x] = false;
			}
			p = p->next;
		}
	}
	else
	{
		if(y == x)
		{
			for(int i = 0;i < pp;i++)
				cout << l[i] << ' ';
			cout << endl;
		}
		else
			return;
	}
}
int main()
{
	CreatAdjGraph();
	memset(visit,false,sizeof(visit));
	for (int i = 0; i < v; ++i)
	{
		if(!visit[i])
		{
			dfs(i);
		}
	}
	cout << '\n';
	memset(visit,false,sizeof(visit));
	for (int i = 0; i < v; ++i)
	{
		if(!visit[i])
		{
			cout << Graph[i].x << ' ';
			bfs(i);
		}
	}
	memset(visit,false,sizeof(visit));
	cout << '\n';
	char x,y;
	int k;
	cin >> x >> y >> k;
	find(x,y,k);
	return 0;
}
