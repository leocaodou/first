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
	int k;
	cin >> k;
	if(18 * 2 < k)
		cout << -1;
	else
	{
		for(int i = 1;i <= k / 2;i++)
			cout << 8;
		for(int i = 1;i <= k % 2;i++)
			cout << 4;
	}
	return 0;
}