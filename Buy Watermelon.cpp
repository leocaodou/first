#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n % 2 == 0 && n > 2)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}