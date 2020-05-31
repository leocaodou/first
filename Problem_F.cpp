#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
#include <vector>
using namespace std;
class node
{
public:
	int no;
	long long d;
	node(int a,long long b):no(a),d(b){};
};
vector<node> v[300000+10];
bool vis[300000+10];
long long ans = 0;
void dfs(int n,long long d)
{
	vis[n] = true;
	int size = v[n].size();
	if(size == 1 && vis[v[n][0].no])
	{
		ans = ans > d?ans:d;
		return;
	}
	for(int i = 0;i < size;i++)
	{
		if(!vis[v[n][i].no])
			dfs(v[n][i].no,d + v[n][i].d);
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	int n;
	cin >> n;
	int a,b;
	long long c;
	long long sum = 0;
	for(int i = 1;i < n;i++)
	{
		scanf("%d%d%lld",&a,&b,&c);
		v[a].push_back(node(b,c));
		v[b].push_back(node(a,c));
		sum += c;
	}
	dfs(1,0);
	cout << 2 * sum - ans;
}
