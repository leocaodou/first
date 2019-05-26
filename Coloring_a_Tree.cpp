#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,t = 1,i;
	cin >> n;
	int a[n + 1],b[n + 1];
	a[1] = 1;
	for(i = 2;i <= n; i++)
		cin >> a[i];
	for(i = 1;i <= n; i++)
	{
		cin >> b[i];
	}
	int c[n] = {0};
	for(i = 2;i <= n; i++)
	{
		if(b[a[i]] != b[i])
			t++;
	}
	cout << t << endl;
	return 0;
}