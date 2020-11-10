#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[26] = {0};
	getchar();
	while(n--)
	{
		char x;
		int j = 0;
		memset(a,0,sizeof(a));
		while(true)
		{
			x = getchar();
			if(x == '\n')
				break;
			a[x - 97]++;
			if(a[x - 97] % 2 == 0)
			{
				j--;
			}
			else
			{
				j++;				
			}
		}
		if(j > 1)
			cout << " -1";
		else
		{
			int k;
			for (int i = 0; i < 26; ++i)
			{
				if(a[i] > 0 && a[i] % 2 == 0)
					for (int j = 0; j < a[i]/2; ++j)
					{
						char y = 97+i;
						putchar(y);
					}
				else if(a[i] % 2 != 0)
					k = i;
			}
			for(int i = 0; i < a[k];i++)
			{
				char y = 97+k;
				putchar(y);
			}
			for (int i = 25; i >= 0; --i)
			{
				if(a[i] > 0 && a[i] % 2 == 0)
					for (int j = 0; j < a[i]/2; ++j)
					{
						char y = 97+i;
						putchar(y);
					}
			}
		}
		printf("\n");
	}
	return 0;
}
