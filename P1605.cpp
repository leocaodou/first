#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int m,n,t,x1,y1,x2,y2,ans = 0;
bool k = false;
bool v[6][6] = {false};
bool is(int x,int y,int a,int b)
{
	if(x == a && y == b)
		return true;
	else
		return false;
}
void dfs(int x,int y)
{
	if(x == 0|| x > m ||y == 0 || y > n)
		return;
	if(is(x,y,x2,y2))
	{
		ans++;
		return;
	}
	v[x][y] = true;
	if(!v[x + 1][y])
	{
		dfs(x + 1,y);
		v[x + 1][y] = false;
	}
	if(!v[x - 1][y])
	{
		dfs(x - 1,y);
		v[x - 1][y] = false;
	}
	if(!v[x][y + 1])
	{
		dfs(x,y + 1);
		v[x][y + 1] = false;
	}
	if(!v[x][y - 1])
	{
		dfs(x,y - 1);
		v[x][y - 1] = false;
	}
}
int main()
{
	cin >> n >> m >> t;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 0;i < t;i++)
	{
		int p,b;
		cin >> p >> b;
		if(is(x2,y2,p,b))
		{
			k = true;
		}
		v[p][b] = true;
	}
	if(k)
	{
		cout << 0;
		return 0;
	}
	dfs(x1,y1);
	cout << ans <<endl;
}