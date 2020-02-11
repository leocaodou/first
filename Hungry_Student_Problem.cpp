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
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin >> n;
		int k = 0;
		while(1)
		{
			
			if(n % 7 == 0)
			{
				k = 1;
				break;
			}
			n -= 3;
			if(n < 0)
				break;
		}
		if(k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}