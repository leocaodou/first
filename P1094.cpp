#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
bool cmp(int &a,int &b)
{
	if(a > b)
		return true;
	else
		return false;
}
int main()
{
	int w,n,k = 0;
	cin >> w >> n;
	int a[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	sort(a,a + n,cmp);
	int j = n - 1;
	for(int i = 0;i < n;i++)
	{
		int x;
		if(i == j)
		{
			k++;
			break;
		}
		if(i > j)
		{
			break;
		}
		x = a[i] + a[j];
		if(x > w)
		{
			k++;
		}
		else
		{
			j--;
			k++;
		}
	}
	cout << k << endl;
	return 0;
}