#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
bool yuan(char x)
{
	if(x == 'a' ||x == 'e'||x == 'i'||x == 'o'||x == 'u')
		return true;
	else
		return false;
}
int main()
{
	char a,b;
	int k = 0,m = 0;
	a = getchar();
	if(!yuan(a))
	{
		k = 1;
		m++;
	}
	cout << a;
	for(;;)
	{
		b = getchar();
		if(b == '\n')
			break;
		if(!yuan(b))
		{
			if(b != a)
			{
				m++;
				k++;
				if(m >= 3)
				{
					printf(" %c",b);
					m = 1;
					k = 1;
				}
				else
					printf("%c",b);
			}
			else
			{
				m++;
				if(m >= 3 && k > 1)
				{
					printf(" %c",b);
					m = 1;
					k = 1;
				}
				else
					printf("%c",b);
			}
		}
		else
		{
			printf("%c",b);
			m = 0;
			k = 0;
		}
		a = b;

	}
	return 0;
}