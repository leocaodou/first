#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
class D
{
public:
	int m;
	int n;
	int a;
	D() : m(0),n(0),a(0){}
	D(int x,int y,int z):m(x),n(y),a(z){}
};
bool cmp(D a1,D a2)
{
	if(a1.a > a2.a)
		return true;
	else
		return false;
}
int main()
{
	int M,N,K,i,j,k = 1,s = 0;
	cin >> M >> N >> K;
	D a[M*N + 1];
	for(i = 1; i <= M; i++)
		for(j = 1;j <= N;j++)
		{
			a[k].m = i;
			a[k].n = j;
			cin >> a[k].a;
			k++;
		}
	sort(a + 1,a + 1 + M * N,cmp);
	K = K;
	int p = 0,q = 0,t = 0;
	for(i = 1;i <= M * N ;i++)
	{
		if(i == 1)
		{
			t = a[i].m + 1;
			if(t + a[i].m > K)
				break;
			else
			{
				s = s + a[i].a;
				p = a[i].m;
				q = a[i].n;
			}
		}
		else
		{
			t = t +  abs(a[i].m - p)+abs(a[i].n - q) + 1;
			if(t + a[i].m > K)
				break;
			else
			{
				s = s + a[i].a;
				p = a[i].m;
				q = a[i].n;
			}
		}
	}
	cout << s << endl;
	return 0;
}
