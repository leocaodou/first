#include<string>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include <math.h>
using namespace std;
int p(int i)
{
	int d,a;
	d = sqrt(i);
	int t;
	for(t = 2; t <= d ;t++)
	{
		if( i % t== 0)
			break;
	}
	if(t > d)
		return 1;
//	else
//		return 0;
}
int main() {
	int n;
	scanf("%d",&n);
	int m = 0;
	for(int i =2;i <=n;i++)
	{
		if(p(i) == 1)
		{
			printf("%5d",i );
			m++;
			if(m % 8 == 0)
				cout << endl;
		}
	}
}
