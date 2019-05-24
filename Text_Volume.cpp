#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,i,max = 0,s = 0;
	cin >> n;
	char a[n + 1];
	getchar();
	for(i = 0 ; i < n; i++)
	{
		a[i] = getchar();
		if(a[i] != ' ')
		{
			if(a[i] >= 65 && a[i] <= 90)
			{
				s++;
			}
		}
		else
		{
			if(s > max)
				max = s;	
			s = 0;
		}
	}
	if(s > max)
		max = s;
	cout << max <<endl;
	return 0;
}