#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,i,max = 0,min = 1e6,a,t;
	cin >> n;
	for(i = 0;i < n; i++)
	{
		cin >> a;
		if(a <= 5*1e5 && a > max)
			max = a;
		if(a > 5*1e5 && a < min )
			min = a;
	}
	t = (max - 1) > (1e6 - min)?(max - 1):(1e6 - min);
	cout << t;
	return 0;
}