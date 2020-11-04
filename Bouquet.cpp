#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long normalPower(long long base, long long power,long long mod)
{
    long long result = 1;
    for (int i = 1; i <= power; i++) {
        result = result * base;
        result = result % mod;
    }
    return result % mod;
}
long long jie(long long n,long long mod)
{
	if(n == 1)
		return 1;
	else
		return jie(n-1,mod) * n % mod;
}
int main()
{
	long long n,a,b;
	cin >> n >> a >> b;
	long long sum = normalPower(2,n,1000000007);
	long long n1 = jie(n,1000000007);
	cout << sum - (n1)/(jie(a,1000000007)*jie(n-a,1000000007)) - (n1)/(jie(b,1000000007)*jie(n-b,1000000007));
	return 0;
}