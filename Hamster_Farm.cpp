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
	long long n,k,t,i = 1,I;
	cin >> n >> k;
	long long min = n;
	while(k--)
	{
		long long a;
		cin >> a;
		if(n % a < min)
		{
			t = a;
			min = n % a;
			I = i;
		}
		i++;
	}
	if( min == n)
		cout << 1 << ' ' << 0;
	else
		cout << I << ' ' << n / t;
	return 0;
}