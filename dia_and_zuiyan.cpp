#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
class s
{
public:
	int l;
	int f;
	int d;
	s():l(0),f(0),d(0){}
};
int main()
{
	int n,i;
	cin >> n;
	s a[n-1];
	for(i = 0;i < n - 1;i++)
	{
		cin >> a[i].l;
	}
	for(i = 0;i < n - 1;i++)
	{
		int x;
		cin >> x;
		cin >> a[i].f;
	}
	for()
}