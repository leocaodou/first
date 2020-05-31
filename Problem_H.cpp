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
	int n,k,num = 0;
	cin >> n;
	int a[400000],s=0;
	for(int i = 0;i < n; i++)
	{
		cin >> k;
		for(int j = s;j < s+k;j++)
			cin >> a[j];
		s += k;
	}
	for(int i = 0; i < s;i++)
	{
		int sum = 0;
		for(int j = 0;j < a[i];j++)
		{
			cin >> k;
			sum += k;
		}
		if(sum > 0)
			num++;
	}
	cout << num;
}
