#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,n,s;
	cin >> a >> b >> c >> n;
	s = a + b - c;
	if(n - s >= 1 && a < n && b < n && c <= a &&c <= b)
	{
		cout << n - s; 
	}
	else
		cout << -1;
	return 0;
}