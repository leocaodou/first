#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c,last;
	int n = 0,k = 0,i = 0,j = 1,s = 0;
	char a[15] = "chi1 huo3 guo1";
	while(1)
	{
		if(c == '\n')
		{
			if(last == '.' && s == 1)
			{
				j--;
				break;
			}
			j++;
			s = 0;
		}
        string a;
        
		last = c;
		c = getchar();
		s++;
		if(c == a[i])
		{
			i++;
			if(i == 14)
			{
				if(n == 0)
					n = j;
				k++;
				i = 0;
			}
		}
		else
			i = 0;
	}
	cout << j << endl;
	if(k == 0)
		cout << "-_-#";
	else
		cout << n << ' ' << k;
}
