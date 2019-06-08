#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define pii pair<int,int>
vector<pair<int,int> >g[50005];
bool vis[50005];
pii dfs(int n){
    vis[n]=1;
    pii r=make_pair(n,0);
    for(int i=0;i<g[n].size();++i){
        pii p=g[n][i];
        if(vis[p.first]) continue;
        pii t=dfs(p.first);
        if(p.second+t.second>r.second){
            r=t;
            r.second+=p.second;
        }
    }
    return r;
}
int main()
{
    int i,j,t,n;
    int u,v,w;
    scanf("%d",&n);
	int a[n-1];
	for(i = 0;i < n - 1;i++)
	{
		cin >> a[i];
	}
    for(i=1;i<=n;++i) g[i].clear();
    for(i=1;i<n;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v,w ));
        g[v].push_back(make_pair(u,w + a[u - 1]));
    }
    int ans=-1;
    memset(vis,0,sizeof(vis));
    pii t1=dfs(1);
    memset(vis,0,sizeof(vis));
    cout<<dfs(t1.first).second<<endl;
    return 0;
}