#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class a
{
public:
	int a = 5;
};
int main()
{
	a x[5];
	a *p = x;
	cout << p->a;
	return 0;
}