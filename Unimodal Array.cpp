#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,a,b,x = 0;
	cin >> n >> a;
	for(int i = 0;i < n - 1;i++)
	{
		cin >> b;
		if(b == a)
		{
			if(x != 2)
				x = 1;
			if(x == 2)
			{
				cout << "NO";
				return 0;
			}
		}
		if(b > a)
		{
			if(x == 1 || x == 2)
			{
				cout << "NO";
				return 0;
			}
		}
		if(b < a)
		{
			x = 2;
		}
		a = b;
	}
	cout << "YES";
	return 0;
}