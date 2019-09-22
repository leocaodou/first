#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class node
{
public:
	node* f;
	int x;
	int s;
};
int main()
{
	int n,k,o = 0,j = 0,i,p = 0;
	cin >> n >> k;
	int a[n],b[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(o == j && o!= 0)
		{
			b[p] = abs(a[i] - a[i - 1]);
			p++;
		}
		if(a[i] % 2 == 0)
			o++;
		else
			j++;
	}
	if(p == 0)
	{
		cout << 0;
		return 0;
	}
	int tmp = 0,ans = 0;
	sort(b,b + p);
	for(i = 0;i < p;i++)
	{
		if(tmp + b[i] <= k)
		{
			tmp += b[i];
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;
}