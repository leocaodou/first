#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
map<int,char> Map;
int Max1 = 0,Max2 = 0,Max = 0;
int s;
bool visit[100010];
bool visit2[100010];
class vodelist
{
public:
	int x;
	char c;
	vodelist* next;
	vodelist(int a,char f) : x(a),c(f){}
};
class Vnode
{
public:
	char c;
	vodelist* next = NULL;
	void add(int a,char f)
	{
		vodelist *p = new vodelist(a,f);
		p->next = next;
		next = p;
	}
};
Vnode tree[100010];
void dfs(int t,int n)
{
	visit[t] = true;
	if(t != n)
		visit2[t] =true;
	vodelist* p = tree[t].next;
	while(p)
	{
		if(!visit[p->x] && p->c != tree[t].c)
		{
			s++;
			dfs(p->x,n);
			if(s > Max)
				Max = s;
			s--;
		}
		p = p->next;
	}
}
int main()
{
	int n;
	cin >> n;
	char c;
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		cin >> c;
		tree[i].c = c;
	}
	for (int i = 1; i < n; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tree[a].add(b,tree[b].c);
	}
	memset(visit2,false,sizeof(visit2));
	for (int i = 1; i <= n; ++i)
	{
		s=0;
		memset(visit,false,sizeof(visit));
		if(!visit2[i] )
			dfs(i,i);
	}
	cout << Max;
}