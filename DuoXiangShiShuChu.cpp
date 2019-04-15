#include <stdio.h>
#include <iostream>
using namespace std; 
int main()
{
	int n,i;
	cin >> n;
	int a[n+1];
	for(i = 0;i <= n;i++)
	{
		cin >> a[i];
	}
	for(i = 0;i <= n;i++)
	{
		if(i == n && i != 0)
		{
			if(a[i] < 0)
			{
				cout << '-' << -a[i];
			}
			if(a[i] > 0)
			{
				cout << '+' << a[i];
			}
		}
		else 
			if(i == n && i == 0)
			{
				if(a[i] < 0)
				{
					cout << '-' << -a[i];
				}
				if(a[i] > 0)
				{
					cout << a[i];
				}
			}
			else
			{
				if(i != n-1)
				{
					if(a[i] < 0 && a[i] != -1)
					{
						cout << '-' << -a[i] << "x^" << n - i;
					}
					if(a[i] > 0 && a[i] != 1)
					{
						if(i != 0)
							cout << '+' << a[i] << "x^" << n - i;
						else
							cout << a[i] << "x^" << n - i;
					}
					if(a[i] < 0 && a[i] == -1)
					{
						cout << '-' << "x^" << n - i;
					}
					if(a[i] > 0 && a[i] == 1)
					{
						if(i != 0)
							cout << '+' << "x^" << n - i;
						else
							cout << "x^" << n - i;
					}
				}
				else
				{
					if(a[i] < 0 && a[i] != -1)
					{
						cout << '-' << -a[i] << "x";
					}
					if(a[i] > 0 && a[i] != 1)
					{
						if(i != 0)
							cout << '+' << a[i] << "x";
						else
							cout << a[i] << "x";
					}
					if(a[i] < 0 && a[i] == -1)
					{
						cout << '-' << "x";
					}
					if(a[i] > 0 && a[i] == 1)
					{
						if(i != 0)
							cout << '+' << "x";
						else
							cout << "x";
					}
				}
			}
	}
	return 0;
}
