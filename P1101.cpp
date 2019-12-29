#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
string s = "yizhong";
bool b[100][100] = {0};
char a[110][110];
int n,c[7][2];
void dfs(int i,int j,int x,int k)
{
	if(a[i][j] == s[k] && k < 7)
	{
		c[k][0] = i;
		c[k][1] = j;
		k++;
	}
	else
		return;
	if(k == 7)
	{
		for(int p = 0;p < 7;p++)
		{
			b[c[p][0]][c[p][1]] = true;
		}
		return;
	}
	switch(x)
	{
		case 1 : dfs(i - 1,j,x,k);break;
		case 2 : dfs(i + 1,j,x,k);break;
		case 3 : dfs(i,j - 1,x,k);break;
		case 4 : dfs(i,j + 1,x,k);break;
		case 5 : dfs(i - 1,j - 1,x,k);break;
		case 6 : dfs(i + 1,j - 1,x,k);break;
		case 7 : dfs(i - 1,j + 1,x,k);break;
		case 8 : dfs(i + 1,j + 1,x,k);break;
	}
}
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cin >> a[i][j];
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			dfs(i,j,1,0);
			dfs(i,j,2,0);
			dfs(i,j,3,0);
			dfs(i,j,4,0);
			dfs(i,j,5,0);
			dfs(i,j,6,0);
			dfs(i,j,7,0);
			dfs(i,j,8,0);
		}
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(b[i][j])
			{
				cout << a[i][j];
			}
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}