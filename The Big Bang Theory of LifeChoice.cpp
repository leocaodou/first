#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,na,nb,i;
	cin >> n >> na >> nb;
	int a[na],b[nb],x = 0,y = 0,j = 0,k = 0;
	int c[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
	for(i = 0;i < na;i++)
		cin >> a[i];
	for(i = 0;i < nb;i++)
		cin >> b[i];
	for(i = 0;i < n;i++)
	{
		x = x + c[a[j]][b[k]];
		y = y + c[b[k]][a[j]];
		j++;
		k++;
		if(j == na)
			j = 0;
		if(k == nb)
			k = 0;
	}
	cout << x << ' ' << y;
	return 0;
}