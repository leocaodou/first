#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n],min = -1;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	for(int i = 1;i <= 100;i++)
	{
		int sum = 0;
		for(int j = 0; j < n;j++)
			sum += (a[j]-i) *(a[j]-i);
		if(sum < min || min == -1)
			min = sum;
	}
	cout << min;
}