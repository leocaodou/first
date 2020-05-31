#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
class cai
{
public:
	int no;
	double val;
};
bool cmp(cai a,cai b)
{
	if(a.val < b.val)
		return true;
	else
		return false;
}
int main()
{
	int n,m,x;
	long long sum = 0;
	cin >> n >> m;
	int a[n];
	cai b[n];
	for(int i = 0; i < n;i++)
		cin >> a[i];
	for(int i = 0; i < n;i++)
	{
		cin >> x;
		b[i].no = i;
		b[i].val = x * 1.0/a[i];
	}
	sort(b,b+n,cmp);
	int p = 0, q = 0;
	int i;
	while(m)
	{
		double need = 0;
		for(i = 0; i < n;i++)
		{
			if(b[i].val - p < 1)
			{
				if(b[i].val - p > 0)
				{
					need += (1-b[i].val + p) * a[b[i].no];
				}
				else
					need += a[b[i].no];
			}
			else
			{
				q = i;
				break;
			}
		}
		if(need == 0)
		{
			sum += (int)b[q].val - p;
			p = (int)b[q].val - p;
			continue;
		}
		if(b[q - 1].val - p <= 0)
		{
			if(i != n)
			{
				if((int)b[q].val - p > m/need)
				{
					sum += m/need;
					break;
				}
				else
				{
					sum +=(int)b[q].val - p;
					m = m - need*((int)b[q].val - p);
					p += (int)b[q].val - p;
				}
			}
			else
			{
				sum += m/need;
				break;
			}
		}
		else
		{
			if(m > need)
			{
				m -= need;
				sum++;
				p++;
			}
			else
				break;
		}
	}
	cout << sum;
	return 0;
}
