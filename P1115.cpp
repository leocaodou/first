#include <iostream>
using namespace std;
int main()
{
	unsigned long long n,a,b,c,d;
	cin >> n;
	while(n--)
	{

		cin >> a >> b >> c >> d;
		if(a == b && a == c && a== d)
			cout << 1 << endl;
		else if( a + b == c + d || a + c == b + d || a + d == b + c)
			if(a == c || a == d || a == c || d == b || c == b || c == d)
				cout << 4 << endl;
			else
				cout << 8 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}