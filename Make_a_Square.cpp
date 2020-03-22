#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int n,Min,sum = 0,w = 1,a[11];
void dfs(int k,int i,int q)
{
	if(i == w)
	{
		int p = sqrt(n);
		if(p * p == n)
		{
			Min = 0;
			return;
		}
		return;
	}
	else
	{
		for(int l = k;l <= w - q;l++)
		{
			if(w - l == q)
			{
				if((sum == 0) && (a[l] == 0))
						return;
				for(int m = l;m < w;m++)
					sum = sum * 10 + a[m];
				int p = sqrt(sum);
				if(p * p == sum)
				{
					if(Min > w - i)
						Min = w - i;
					return;
				}
				else
					return;
			}
			else
			{
				if(q == 0)
				{
					int p = sqrt(sum);
					if(p * p == sum)
					{
						if(Min > w - i)
							Min = w - i;
						return;
					}
					else
						return;
				}
				else
				{
					int S =sum;
					if((sum == 0) && (a[l] == 0))
						continue;
					sum = sum * 10 + a[l];
					int L = l + 1,Q = q - 1;
					dfs(L,i,Q);
					sum = S;
				}
			}
		}
		
	}
}
int main()
{
	int s;
	cin >> n;
	s = n;
	
	while(1)
	{
		s = s / 10;
		if(s == 0)
			break;
		w++;
	}
	Min = w;
	int i = w;
	s = n;
	for(int j = 0;j < w;j++)
	{
		a[w - 1 - j] = s % 10;
		s = s / 10;
	}
	int o = w;
	while(o--)
	{
		for(;i >= 0;)
		{
			dfs(0 ,i,i);
			sum = 0;
			i --;
		}
	}
	if(Min == w)
		cout << - 1;
	else
		cout << Min;
	return 0 ;
}
