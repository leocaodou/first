#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
struct my
{
	int t;
	int s;	
};
bool cmp1(my x,my y)
{
	if( x.t < y.t)
		return true;
	else
		return false;
}
bool cmp2(my x,my y)
{
	if( x.s > y.s)
		return true;
	else
		return false;
}
int main()
{
	int n,k,i;
	cin >> n >> k;
	my a[n];
	for(int i = 0;i < n; i++)
	{
		cin >> a[i].t;
	}
	for(int i = 0;i < n; i++)
	{
		cin >> a[i].s;
	}
	sort( a, a+n, cmp2);
	int j = 0,l = 0,x = 0, y = 0;
	for(;;)
	{
		if(k - 2 - j >= 0)
			if(a[k - 1 - j].s == a[k - 1].s)
				j++;
			else
				x = 1;
		else
			x = 1;
		if(k + l < n)
			if(a[k - 1 + l].s == a[k - 1].s)
				l++;
			else
				y = 1;
		else
			y = 1;
		if(x && y)
			break;
	}
	sort(a + k - 1 - j,a + k + l - 1,cmp1);
	long long s = 0,m = 0;
	for( i = 0;i < k;i++)
	{
		s = s + a[i].t;
		m = m + a[i].s;
	}
	cout << s << ' ' << m << endl;
	return 0;
}
