#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
map<char,int> Map;//用于根据节点名字存储每一个节点的位置 
bool visit[20];//用于判断某一个节点是否已经被访问 
char l[25];//用于存储路径 
int v,m,pp = 0;
queue<int> Q;
class vodelist
{
public:
	int x;//用于存储这个节点位于数组的第几个 
	vodelist* next;//下一个同样与这个节点与某个节点相接的节点 
	vodelist(int a) : x(a){}//构造函数 
};
class Vnode
{
public:
	char x;//节点的符号名字 
	vodelist* next = NULL;//与之相连的节点所在数组中的位置 
	void add(char a) //有某一个节点与之连接的函数 
	{
		vodelist *p = new vodelist(Map[a]);
		p->next = next;
		next = p;
	}
};
Vnode Graph[20];
void CreatAdjGraph()//构造图 
{
	cin >> v >> m;//依次输入图的节点树以及边数 
	for (int i = 0; i < v; ++i)//依次输入每一个节点的名字 
	{
		char c;
		cin >> c;
		Graph[i].x = c;
		Map[c] = i;
	}
	for (int i = 0; i < m; ++i)//依次输入每次边的两端点 
	{
		char x,y;
		cin >> x >> y;
		Graph[Map[x]].add(y);
		Graph[Map[y]].add(x);
	}
}
void dfs(int t)//深度优先搜索 
{
	cout << Graph[t].x << ' '; 
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])//如果该点没有被遍历过 
		{
			visit[p->x] = true;//标记该点被遍历过 
			dfs(Map[Graph[p->x].x]);//开始从这个点深度优先搜索
		}
		p = p->next;//从与p点有关的点一个一个查看 
	}
}
void bfs(int t)//广度优先搜索 
{
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])
		{
			visit[p->x] = true;
			cout << Graph[p->x].x << ' ';//首先将这个点遍历 
			Q.push(p->x);//然后加入队列，等结束所有遍历之后开始从它们开始遍历 
		}
		p = p->next;
	}
	p = Graph[t].next;
	while(!Q.empty())
	{
		int q = Q.front();//取出队列第一个 
		Q.pop();
		bfs(q);//从该节点开始遍历 
		p = p->next;
	}
}
void find(char x,char y,int k)//寻找从x到y的所有路径长度为k的简单路径，使用了DFS的算法 
{
	l[pp] = x;//路径记录 
	pp++;
	visit[Map[x]] = true;
	vodelist* p = Graph[Map[x]].next;
	if(k != 0)//k是指需要的路程 
	{
		while(p)
		{
			if(!visit[p->x])
			{
				visit[p->x] = true;
				find(Graph[p->x].x , y, k - 1);
				pp--;
				visit[p->x] = false;//寻找其他路径，因此需要返回初始状态 
			}
			p = p->next;
		}
	}
	else//如果k为0，说明不能继续向前 
	{
		if(y == x)//如果到达我们的目标点，输出结果 
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
