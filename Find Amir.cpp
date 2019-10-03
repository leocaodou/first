#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	if(n % 2 == 0)
		cout << n / 2 - 1;
	else
		cout << (n - 1) / 2;
}