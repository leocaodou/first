#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
#define MAX 0x3f3f3f3f
int dis[100],v[100],map[100][100];
void dijkstra(int a,int n)
{
	memset(v,0,sizeof(v));
	for(int i = 0; i < n;i++ )
	{
		dis[i] = min(MAX,map[a][i]);
	}
	v[a] = 1;
	for(int i = 0; i < n;i++ )
	{
		int m = MAX,x;
		for(int j = 0; j< n;j++)
		{
			if(!v[j] && dis[j] <= m)
			{
				m = dis[x = j];
			}
		}
		v[x] = 1;
		for(int j = 0; j< n;j++)
		{
			dis[j] = min(dis[j],dis[x] + map[x][j]);
		}
	}
}
int main()
{	
	int n ,m;
	cin >> n >> m;
	memset(map,MAX,sizeof(map));
	for(int i =0 ;i < m;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		map[x][y] = w;
		map[y][x] = w;
	}
	for(int i =0 ;i < n;i++)
		map[i][i] = 0;
	dijkstra(0,n);
	for(int i =0 ;i < n;i++)
		cout << dis[i] << endl;
	return 0;
}
