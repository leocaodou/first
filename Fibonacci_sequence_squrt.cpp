#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	long long a,b;
	cin >> a >> b;
	if((3 * a <= b) || (3 * b <= a))
	{
		long long x = a < b?a:b;
		printf("%lld",x);
	}
	else
	{
		long long y;
		long long x = (a > b?a:b)/3;
		y = (a < b?a:b)/2;
		printf("%lld",x > y?x:y);
	}
}