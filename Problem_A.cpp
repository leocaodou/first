#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
char weng[] = {'W','T','Y','U','I','O','A','H','X','V','M'};
bool is(char x)
{
	for (int i = 0; i < 11; ++i)
	{
		if(x == weng[i])
			return true;
	}
	return false;
}
int main()
{
	char x;
	int sum = 0,wen = 0;
	while(1)
	{
		x = getchar();
		if(x != '\n')
		{
			sum++;
			if(is(x))
			{
				wen++;
			}
		}
		else
			break;
	}
	if(wen > sum/2)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	return 0;
}