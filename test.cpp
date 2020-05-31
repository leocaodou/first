#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
bool cmp(int a,int b)
{
	if(a<b)
		return true;
	else
		return false;
}
int main()
{
	int a[] = {-1,-2,6,5,9,3,6,45,32};
	double b=16.69;
	int c=(int)b;
	cout << c << endl;
	sort(a,a+9,cmp);
	int i;
	for (i = 0; i < 9; i++)
	{
		cout << a[i] << ' ';
	}
	cout << i;
}