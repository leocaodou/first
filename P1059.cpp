#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int s = 0;
	for(int i = 1;i < n; i++)
	{
		if(a[i] == a[i - 1])
		{
			s++;
		}
	}
	cout << n - s << endl << a[0];
	for(int i = 1;i < n; i++)
	{
		if(a[i] != a[i - 1])
		{
			cout << ' ' << a[i];
		}
	}
	return 0;
}