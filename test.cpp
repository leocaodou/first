#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int i = 1;
	int ans = 0;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		if(m>=n)
			ans = ans ^ i;
		else
			ans = ans ^ (i-1);
		i++;
	}
	cout << ans;
}
