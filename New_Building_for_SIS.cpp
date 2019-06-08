#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,h,a,b,k;
	cin >> n >> h >> a >> b >> k;
	for(int i = 0;i < k; i++)
	{
		int t1,f1,t2,f2;
		long long s = 0;
		cin >> t1 >> f1 >> t2 >> f2;
		if((f1 < a || f1 >b) && t1 != t2)
		{
			if(f2 < a || f2 > b)
			{
				if(fabs(f1 - a) < fabs(f1 - b))
				{
					s = s + fabs(f1 - a);
					s = s + fabs(f2 - a);
				}
				else
				{
					s = s + fabs(f1 - b);
					s = s + fabs(f2 - b);
				}
			}
			else
			{
				s = s + fabs(f1 - f2);
			}
		}
		else
		{
			s = s + fabs(f1 - f2);
		}
		s = s + fabs(t1 - t2);
		cout << s << endl;
	}
	return 0;
}