#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
class milk
{
public:
	int prize;
	int num;
	milk() : prize(0),num(0){}
	milk(int a,int b) : prize(a),num(b){}
};
bool cmp(milk &a,milk &b)
{
	if(a.prize < b.prize)
		return true;
	else
		return false;
}
int main()
{
	int n,m,sum = 0;
	long long psum = 0;
	cin >> n >> m;
	milk a[m + 2];
	for(int i = 0;i < m ;i++)
	{
		int x,y;
		cin >> x >> y;
		a[i].prize = x;
		a[i].num = y;
	}
	sort(a,a + m,cmp);
	for(int i = 0;i < m;i++)
	{
		if(sum + a[i].num > n)
		{
			psum += (n - sum) * a[i].prize;
			sum = n;
			break;
		}
		else
		{
			sum += a[i].num;
			psum += a[i].num * a[i].prize;
		}
	}
	cout << psum << endl;
}