#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
long long pow_mod(int a,int b,int c)
{
	long long ans = 1;
	long long base = a%c;
	while(b)
	{
		if(b & 1)
			ans = (ans*base)%c;
		base = (base*base)%c;
		b >>= 1;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		long long sum = 1;
		cin >> n;
		for(double i = 1.5;;i=i+1)
		{
			int k = i*i;
			int p = (i-1)*(i-1);
			if(k > n)
			{
				sum = sum * pow_mod(i,n-p,1000000007) % 1000000007;
				break;
			}
			else
			{
				sum = sum * pow_mod(i,k-p,1000000007) % 1000000007;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
