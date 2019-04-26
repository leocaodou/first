#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,max = 0,m,i;
	cin >> n;
	char a[n + 1];
	cin >> a;
	for(i = 0;i < strlen(a); i++)
	{
		int b[26] = {0};
		m = 0;
		while(1)
		{
			if(a[i] >= 'A' && a[i] <= 'Z')
				break;
			if(b[int(a[i]) - 97] == 0)
			{
				m++;
				b[int(a[i]) - 97] = 1;
			}
			i++;
			if(i == n)
				break;
		}
		if( m > max)
			max = m;
	}
	cout << max;
	return 0;
}