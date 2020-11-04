#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	int t = 0,m = pow(k,t);
	while(1)
	{
		if(n / m == 0)
			break;
		t++;
		m = pow(k,t); 
	}
	cout << t;

}