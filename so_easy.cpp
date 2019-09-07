#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int b[1000000];
int main()
{
	int n,m,i,k = 0,j;
	cin >> n >> m;
	for(j = 0; j < m;j++)
	{
		int z,q;
		cin >> z;
		if(z == 1)
		{
			cin >> q;
			b[k] = q;
			sort(b,b + k);
			k ++;
		}
		if(z == 2)
		{
			cin >> q;
			if(q > n)
				cout << -1 << '\n';
			else
			{
				int y = q;
				for(i = 0; i < k;i++)
				{
					if(b[i] == q)
					{
						while(1)
						{
							if(i > k)
								break;
							if(b[i + 1] - b[i] != 1)
							{
								y = b[i] + 1;
								break;
							}
						}
						break;
					}
				}
				cout << y << '\n';
			}
		}
	}
	return 0;
}