#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int a = 1,b = 1,n;
	cin >> n;
	bool arr[n + 1] = {false};
	arr[1] = true;
	for(;;)
	{
		int t = a + b;
		if(t > n)
			break;
		arr[t] = true;
		a = b;
		b = t;
	}
	for(int i = 1;i < n + 1;i++)
	{
		if(arr[i])
			cout << "O";
		else
			cout << 'o';
	}
	return 0;
}