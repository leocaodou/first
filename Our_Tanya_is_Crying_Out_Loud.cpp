#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	long long k,n,a,b,x = 0;
	long long s = 0;
	cin >> n >> k >> a >> b;
	if(k == 1)
	{
		s = (n - 1) * a;
		printf("%lld",s);
		return 0;
	}
	for(;;)
	{
		if(n == 1)
			break;
		if(n % k == 0 && x == 0)
		{
			if(b < ( (n - n / k) * a))
			{
				s = s + b;
				n = n / k;
			}
			else
			{
				x = 1;
				// if(n - k != 0)
				// {
				// 	s = s + a * k;
				// 	n = n - k;
				// }
				// else
				// {
				// 	s = s + a * (k - 1);
				// 	n = n - k + 1;
				// }
			}
		}
		else
		{
			if(x == 1)
			{
				s = s + a * (n - 1);
				n = 1;
				continue;
			}
			if(n > k)
			{
				s = s + a * (n % k);
				n = n - n % k;
			}
			else
			{
				s = s + a * (n - 1);
				n = 1;
			}
		}
	}
	cout << s;
}
