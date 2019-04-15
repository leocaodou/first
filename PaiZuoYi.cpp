#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int m,n,k,l,d,i,j,o;
	cin >> m >> n >> k >> l >> d;
	int a[k],b[l],c[d][2][2],x[n-1] ={0},y[m-1] = {0},max = 0,p[k],q[l];
	for(i = 0;i < d; i++)
	{
		cin >> c[i][0][0] >> c[i][0][1] >> c[i][1][0] >> c[i][1][1];
		if(c[i][0][0] == c[i][1][0])
		{
			if(c[i][0][1] < c[i][1][1])
				x[c[i][0][1] - 1]++;
			else
				x[c[i][1][1] - 1]++;
		}
		if(c[i][0][1] == c[i][1][1])
		{
			if(c[i][0][0] < c[i][1][0])
				y[c[i][0][0] - 1]++;
			else
				y[c[i][1][0] - 1]++;
		}
	}
	for(i = 0; i < k;i++)
	{
		max = 0;
		for(j = 0;j < m - 1;j++)
			if(y[j] > y[max]){
				max = j;
			}
		p[i] = max;
		y[max] = -1;
	}
	for(i = 0; i < l;i++)
	{
		max = 0;
		for(j = 0;j < n -1;j++)
			if(x[j] > x[max]){
				max = j;
			}
		q[i] = max;
		x[max] = -1;
	}
	sort(p, p+k);
	sort(q, q+l);
	o = 0;
	for(i = 0; i < k;i++)
	{
		if(o == 0){
			cout << p[i] + 1;
			o++;
		}
		else
			cout << ' ' << p[i] + 1;
	}
	printf("\n");
	o = 0;
	for(i = 0; i < l;i++)
	{
		if(o == 0){
			cout << q[i] + 1;
			o++;
		}
		else
			cout << ' ' << q[i] + 1;
	}
}
