#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,i,y,k = 0,j=0;
	cin >> n >> x;
	for( i = 0;i < n;i++)
	{
		cin >> y;
		if(y < x)
			k++;
		if(y == x)
			j = 1;
	}
	cout << x - k + j;
}