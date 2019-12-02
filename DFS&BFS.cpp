#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
map<char,int> Map;//���ڸ��ݽڵ����ִ洢ÿһ���ڵ��λ�� 
bool visit[20];//�����ж�ĳһ���ڵ��Ƿ��Ѿ������� 
char l[25];//���ڴ洢·�� 
int v,m,pp = 0;
queue<int> Q;
class vodelist
{
public:
	int x;//���ڴ洢����ڵ�λ������ĵڼ��� 
	vodelist* next;//��һ��ͬ��������ڵ���ĳ���ڵ���ӵĽڵ� 
	vodelist(int a) : x(a){}//���캯�� 
};
class Vnode
{
public:
	char x;//�ڵ�ķ������� 
	vodelist* next = NULL;//��֮�����Ľڵ����������е�λ�� 
	void add(char a) //��ĳһ���ڵ���֮���ӵĺ��� 
	{
		vodelist *p = new vodelist(Map[a]);
		p->next = next;
		next = p;
	}
};
Vnode Graph[20];
void CreatAdjGraph()//����ͼ 
{
	cin >> v >> m;//��������ͼ�Ľڵ����Լ����� 
	for (int i = 0; i < v; ++i)//��������ÿһ���ڵ������ 
	{
		char c;
		cin >> c;
		Graph[i].x = c;
		Map[c] = i;
	}
	for (int i = 0; i < m; ++i)//��������ÿ�αߵ����˵� 
	{
		char x,y;
		cin >> x >> y;
		Graph[Map[x]].add(y);
		Graph[Map[y]].add(x);
	}
}
void dfs(int t)//����������� 
{
	cout << Graph[t].x << ' '; 
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])//����õ�û�б������� 
		{
			visit[p->x] = true;//��Ǹõ㱻������ 
			dfs(Map[Graph[p->x].x]);//��ʼ������������������
		}
		p = p->next;//����p���йصĵ�һ��һ���鿴 
	}
}
void bfs(int t)//����������� 
{
	visit[t] = true;
	vodelist* p = Graph[t].next;
	while(p)
	{
		if(!visit[p->x])
		{
			visit[p->x] = true;
			cout << Graph[p->x].x << ' ';//���Ƚ��������� 
			Q.push(p->x);//Ȼ�������У��Ƚ������б���֮��ʼ�����ǿ�ʼ���� 
		}
		p = p->next;
	}
	p = Graph[t].next;
	while(!Q.empty())
	{
		int q = Q.front();//ȡ�����е�һ�� 
		Q.pop();
		bfs(q);//�Ӹýڵ㿪ʼ���� 
		p = p->next;
	}
}
void find(char x,char y,int k)//Ѱ�Ҵ�x��y������·������Ϊk�ļ�·����ʹ����DFS���㷨 
{
	l[pp] = x;//·����¼ 
	pp++;
	visit[Map[x]] = true;
	vodelist* p = Graph[Map[x]].next;
	if(k != 0)//k��ָ��Ҫ��·�� 
	{
		while(p)
		{
			if(!visit[p->x])
			{
				visit[p->x] = true;
				find(Graph[p->x].x , y, k - 1);
				pp--;
				visit[p->x] = false;//Ѱ������·���������Ҫ���س�ʼ״̬ 
			}
			p = p->next;
		}
	}
	else//���kΪ0��˵�����ܼ�����ǰ 
	{
		if(y == x)//����������ǵ�Ŀ��㣬������ 
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
