#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
class a
{
public:
	string d;
	int l;
	a():l(0){}
	a(const a& other) : l(l) {
		d = other.d;
	}
bool operator < (const a&o)
{
	if(l < o.l)
		return true;
	if(l > o.l)
		return false;
	else
	{
		for(int i = 0;i < l;i++)
		{
			if(d[i] < o.d[i])
				return true;
			if(d[i] > o.d[i])
				return false;
		}
		return false;
	}
}
};
istream& operator >> (istream& in, a& other) 
{
	char x;
	int i;
    for(i = 0;; i++)
    {
    	x = getchar();
    	if( x == '\n')
    		break;
    	other.d += x;
    }
    other.l = i;
    return in;
}
int main()
{
	int n,y;
	cin >> n;
	getchar();
	a max;
	max.l = 0;
	a t[n];
	for(int i = 0;i < n;i++)
	{
		cin >> t[i];
		if(max < t[i])
		{
			max.d = t[i].d;
			max.l = t[i].l;
			y = i;
		}
	}
	cout << y + 1 << endl;
	cout << max.d;
}
