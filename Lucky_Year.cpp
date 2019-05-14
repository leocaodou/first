#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long n,i,a,b;
	cin >> n;
	a = n;
	i = 1;
	while(1)
	{
		n = n / 10;
		if(n == 0)
		{
			break;
		}
		i++;
	}
	b = ((long long)(a / pow(10,i - 1)) + 1) * pow(10,i - 1) - a ;
	cout << b << endl;
	return 0;
}