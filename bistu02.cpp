#include <iostream>
using namespace std;
int mod = 1000000007;
long long pow(long long a, long long n)
{
    long long res=1ll;
	while(n)
	{
		if (n&1)
            res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res % mod;
}
int main()
{
	int m,n,k;
	cin >> n >> m >> k;
	int q;
	long long sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> q;
		sum += q;
		sum = sum % mod;
	}
	long long a1 = (sum * pow(n,mod - 2)) % mod;
	sum = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> q;
		sum += q;
		sum = sum % mod;
	}
	long long a2 = (sum * pow(n,mod - 2)) % mod;
	sum = 0;
	for (int i = 0; i < k; ++i)
	{
		cin >> q;
		sum += q;
		sum = sum % mod;
	}
	long long a3 = (sum * pow(n,mod - 2)) % mod;
	cout << a1 * a2 % mod * a3 % mod;
}