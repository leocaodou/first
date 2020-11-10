#include <bits/stdc++.h>
using namespace std;
long long a[2010];
int b[2010];
int mod = 20000311;
typedef long long ll;
void init()
{
	a[1] = 1ll;
	for(int i = 2; i <= 2000;i++)
		a[i] = i * a[i - 1] % mod;
}
bool cmp(int a,int b)
{
	if(a > b)
		return true;
	else
		return false;
}
int main()
{
	int n,m;
	cin >> n >> m;
	sum = a[n];
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	sort(b,b+m,cmp);
	for (int i = 0; i < m; ++i)
	{
		sum = sum - 
	}
}
