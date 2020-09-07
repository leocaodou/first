#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int main()
{
	int n,x[26] = {0};
	long long k = 0,max = 0;
	cin >> n >> k;
	string a;
	cin >> a;
	for(int i = 0;i < n;i++)
	{
		x[a[i] - 97]++;
		if(max < x[a[i] - 97])
			max = x[a[i] - 97];
	}
	printf("%lld",max*k);
} 
