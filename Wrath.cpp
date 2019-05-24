#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,s = 1,i;
	cin >> n;
	int a[n];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(a[n - 1] == 0 && n != 1)
		s = 2;
	for(i = n - 2;i > 0;i--)
	{
		if(a[i] > a[i + 1] - 1)
		{
			if(a[i] == 0)
				s++;
		}
		else
		{
			a[i] = a[i + 1] - 1;
			if(a[i] == 0)
				s++;
		}
	}
	cout << s << endl;
	return 0;
}