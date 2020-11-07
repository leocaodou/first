#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
typedef long long ll;
ll n,a,b,ans;
ll normalPowe(ll a, ll n)
{
    ll res=1ll;
	while(n)
	{
		if (n&1)
            res=res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res%mod;
}
ll C(ll n,ll m)
{
	if(n<m)
        return 0;
	if(n==m||!m)
		return 1;
	if(m<n-m)
		m=n-m;
	ll a=1;
	for(ll i=m+1;i<=n;++i)
	a=a*i%mod;
	ll b=1;
	for(ll i=1;i<=n-m;++i)
	b=b*i%mod;
	return a * normalPowe(b,mod-2) % mod ;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n,a,b;
	cin >> n >> a >> b;
	ll sum = normalPowe(2ll,n);
	cout << ((sum - C(n,a) - C(n,b) - 1)%mod+mod)%mod;
	return 0;
}