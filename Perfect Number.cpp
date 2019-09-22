#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    long long a[k + 1];
    for(long long m=19,i=1;i <= k;m++)
    {
        int sum = 0;
        long long n = m;
        while(n)
        {
           sum += n % 10;
           n = n / 10;
       	}
       	if(sum == 10)
		{
			a[i] = m;
			i++;
		}
    }
    printf("%lld\n",a[k]);
    return 0;
}
