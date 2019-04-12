#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	long long n,m,a,b;
	cin >> n >> m;
	a = n;
	b = m;
	while(1)
	{
		if(a < 2*b  && b < 2*a)
			break;
		if(a == 0 || b == 0)
			break;
		if(a > b)
			a = a % (2*b);
		else
			b = b % (2*a);
	}
	cout << a << ' ' << b;
}
