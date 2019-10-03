#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2,p,q;
	cin >> x1 >> y1 >> x2 >> y2 >> p >> q;
	int x = abs(x1 - x2), y = abs(y1 - y2);
	if(!(x % p) && !(y % q))
	{
		if((x / p) % 2 == (y / q) % 2)
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "NO";
	return 0;
}