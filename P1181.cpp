#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int main()
{
	int n, m, x, sum = 0,k = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> x;
		sum+= x;
		if(sum > m)
		{
			sum = x;
			k ++;
		}
	}
	k++;
	cout << k;
}