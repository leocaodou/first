#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	string a;
	char c;
	int x = 0,i;
	int m =0,n = 0;
	while(1)
	{
		c = getchar();
		if( c == 'E')
		{
			x = 1;
		}
		if( c != 'E' && c != '\n' && x == 0)
		{
			a = a + c;
		}
		if(c == '\n' && x == 1)
			break;
	}
	if( a[0] == '\0')
	{
		cout << "0:0\n\n0:0";
	}
	for( i = 0; i < a.length();i++)
	{
		if(i == a.length() - 1)
		{
			if(a[i] == 'W')
				m++;
			else
				n++;
			cout << m << ':' << n << '\n';
			break;
		}
		if( n < 11 && m < 11)
		{
			if(a[i] == 'W')
				m++;
			else
				n++;
		}
		else
		{
			if(abs(m - n) >= 2)
			{
				cout << m << ':' << n << '\n';
				if(a[i] == 'W')
				{
					n = 0;
					m = 1;
				}
				else
				{
					n = 1;
					m = 0;
				}
			}
			else
			{
				if(a[i] == 'W')
					m++;
				else
					n++;
			}
		}
	}
	cout << '\n';
	m = 0;
	n = 0;
	for( i = 0; i < a.length();i++)
	{
		if(i == a.length() - 1)
		{
			if(a[i] == 'W')
				m++;
			else
				n++;
			cout << m << ':' << n << '\n';
			break;
		}
		if( n < 21 && m < 21)
		{
			if(a[i] == 'W')
				m++;
			else
				n++;
		}
		else
		{
			if(abs(m - n) >= 2)
			{
				cout << m << ':' << n << '\n';
				if(a[i] == 'W')
				{
					n = 0;
					m = 1;
				}
				else
				{
					n = 1;
					m = 0;
				}
			}
			else
			{
				if(a[i] == 'W')
					m++;
				else
					n++;
			}
		}
	}
	cout << '\n';
	return 0;
}