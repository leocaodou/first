#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	char code[3];
	int n,i,x = 0,j,y = 0;
	cin >> code >> n;
	char a[n][3];
	for(i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i][0] == code[0] && a[i][1] == code[1])
			x = 1;
	}
	for(i = 0;i < n;i++)
	{
		if(x == 1)
			break;
		if(a[i][1] == code[0])
			for(j = 0;j < n;j++)
			{
				if(a[j][0] == code[1])
				{
					y = 1;
					break;
				}
			}
		if(y ==1)
			break;
	}
	if(x == 1||y ==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
