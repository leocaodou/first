#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
class people
{
public:
	int time;
	int num;
	people() : time(0),num(0){}
};
bool cmp(people &a,people &b)
{
	if(a.time < b.time)
		return true;
	else
		return false;
}
int main()
{
	int n ,t;
	cin >> n;
	people a[n + 2];
	int sum[n + 2] = {0};
	long long s = 0;
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		a[i].time = t;
		a[i].num = i + 1;
	}
	sort(a, a + n,cmp);
	sum[0] = 0;
	for(int i = 0;i < n; i++)
	{
		cout << a[i].num << ' ';
		if(i != 0)
			sum[i] = sum[i - 1] + a[i - 1].time;
	}
	for(int i = 0;i < n; i++)
		s = s + sum[i];
	printf("\n%.2lf",double(s) / n);
	return 0;
}