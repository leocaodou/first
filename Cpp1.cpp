#include<stdio.h>
#include <algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a,b,x;
	cin >> a;
	x=a/2;
	b=x;
	while(1)
	{
		b=x;
		x=(x+a/x)/2;
		if(fabs(b-x)<1e-5)
		break;
	}
	printf("%lf",x);
	return 0;
}

