#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,a,b,i;
	cin >> n >> a >> b;
	if(a > b)
	{
		int s = 0;
		for(i = 0;;i++)
		{
			s = n - a * i;
			if(s % b == 0)
			{
				cout << "YES" << endl;
				cout << i << ' ' << s / b;
				return 0;
			}
			if(s < a || s < b)
				break;
		}
		cout << "NO" << endl;
	}
	else
	{
		int s = 0;
		for(i = 0;;i++)
		{
			s = n - b * i;
			if(s % a == 0)
			{
				cout << "YES" << endl;
				cout << s / a << ' ' << i;
				return 0;
			}
			if(s < a || s < b)
				break;
		}
		cout << "NO" << endl;
	}
}