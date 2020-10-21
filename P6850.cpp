#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int sum = 0,A,t;
	cin >> sum;
	sum += 50;
	for (int i = 0; i < 6; ++i)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cin >> A >> t;
	if(A)
		sum += 5;
	if(sum >= t)
		cout << "AKIOI";
	else
		cout << "AFO";
	return 0;
}