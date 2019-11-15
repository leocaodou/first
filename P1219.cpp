#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int N,m=1,k = 0;
void show(int *a)
{
	for(int i = 1; i <= N;i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
bool check(int x,int i,int* a)
{
	for(int j = 1;j <= x-1;j++)
	{
		if(i == a[j] || abs(x - j) == abs(i - a[j]))
			return false;
	}
	return true;
}
void dfs(int x,int *a)
{
	if(x > N)
	{
		if( k < 3)
			show(a);
		k++;
	}
	for(int i = 1;i <= N;i ++)
	{
		if(check(x,i,a))
		{
			a[x] = i;
			dfs(x+1,a);
		}
	}
}
int main()
{
	cin >> N;
	int a[N];
	dfs(1,a);
	cout << k << endl;
	return 0;
}