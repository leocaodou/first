#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
int n,a[35],ans,Max = 0,c[35],b[35],k;
bool v[35] = {false},d[35] = {false};
int dfs(int x)
{
	v[x] = true;
	if(v[x - 1] == true)
	{
		if(v[x + 1] == true)
			return a[x];
		else
		{
			for(int i = 1;!v[i];i++)
			{
				return a[x] + dfs( x + i);
			}
		}
	}
	if(v[x + 1] == true)
	{
		if(v[x - 1] == true)
			return a[x];
		else
		{
			for(int i = 1;!v[i];i++)
			{
				return a[x] + dfs( x - i);
			}
		}
	}
	for(int i = 1;!v[i];i++)
	{
		for(int j = 1;!v[j];j++)
		{
			return a[x] + dfs(x - i) * dfs( x + j);
		}
		v[i] = false;
	}
}
int main()
{
	v[0] = true;
	cin >> n;
	v[n + 1] = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		k = 1;
		ans = dfs(i);
		if(ans > Max)
		{
			Max = ans;
		}
		memset(v,false,sizeof(v));
		v[0] = true;
		v[n + 1] = true;
	}
	cout << Max << endl;
	for(int i = 1;i <= n;i++)
	{
		cout << c[i];
	}
}