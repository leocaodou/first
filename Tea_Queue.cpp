#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class people
{
public:
	int l;
	int r;
};
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k = 1,j = 1;
		cin >> n;
		people a[n];
		int b[n];
		for(int i = 0;i < n;i++)
		{
			cin >> a[i].l >> a[i].r;
			if(a[i].l <= k)
			{
				if(a[i].r >= k)
				{
					b[i] = k;
					k++;
					j++;
				}
				else
					b[i] = 0;
			}
			else
			{
				k = a[i].l;
				b[i] = k;
				k++;
				j++;
			}
		}
		for(int i = 0;i < n;i++)
			printf("%d ",b[i]);
		cout << endl;
	}
}