#include <stdio.h>
#include <iostream>
using namespace std; 
int main()
{
	int n,i;
	cin >> n;
	int a[n][4];
	for(i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1]>> a[i][2]>> a[i][3];
	}
	int x,y;
	cin >> x >> y;
	for(i = n - 1; i>=0; i--)
	{
		if(a[i][0] + a[i][2] >= x && a[i][0] <= x && a[i][1] + a[i][3] >= y && a[i][1] <= y){
			cout << i + 1;
			return 0;
		}
	}
	cout << -1; 
	return 0;
}
