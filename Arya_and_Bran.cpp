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
	int n,k,s = 0,a,t = 0;
	cin >> n >> k;
	while(n--)
	{
		cin >> a;
		s += a;
		if(s > 8)
		{
			s -= 8;
			k = k - 8;
			t++;
		}
		else
		{
			k = k - s;			
			s = 0;
			t++;
		}
		if(k <= 0)
			break;
	}
	if(k <= 0)
		cout << t;
	else
		cout << -1;
	return 0;
}