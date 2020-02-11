#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int a[n],b[10] = {0};
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < m;i++)
	{
		int x;
		cin >> x;
		b[x] = 1;
	}
	for(int i = 0;i < n;i++)
	{
		if(b[a[i]])
			cout << a[i] << ' ';
	}
	return 0;
}