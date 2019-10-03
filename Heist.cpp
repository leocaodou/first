#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, max = 0, min = 1000000000;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(x < min)
			min = x;
		if(x > max)
			max = x;
	}
	cout << max - min + 1 - n;
	return 0;
}