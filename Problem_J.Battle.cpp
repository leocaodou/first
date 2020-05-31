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
int edge[1001][1001],n;
bool vis[1010];
long long ans=0;
void prime(int x,long long d,int r)
{
	vis[x] = true;
	if(r == 0)
	{
		if(d > ans)
			ans = d;
		return;
	}
	else
	{
		int v,dis,max=0;
		for(int i = 1;i <= n;i++)
		{
			if(edge[i][x] > max && !vis[i])
			{
				v = i;
				dis = edge[i][x];
			}
		}
		d += dis;
		prime(v,d,r-1);
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	cin >> n;
	for(int i = 1;i < n;i++)
	{
		for(int j = n;i >= 1 + i;j--)
		{
			int x;
			cin >> x;
			edge[i][j] = x;
			edge[j][i] = x;
		}
	}
	for(int i = 1;i <= n;i++)
		prime(i,0,n);
	cout << ans;
}
