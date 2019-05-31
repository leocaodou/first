#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,n1,n2,i;
	cin >> n >> n1 >> n2;
	int a[n];
	for(i = 0; i < n;i++)
		cin >> a[i];
	sort(a,a + n,cmp);
	double s1 = 0,s2 = 0,s;
	for(i = 0; i < (n1<n2?n1:n2);i++)
		s1 = s1 + a[i];
	s1 = s1 / (n1<n2?n1:n2);
	for(i = (n1<n2?n1:n2); i < n1+n2 ;i++)
		s2 = s2 + a[i];
	s2 = s2 / (n1>n2?n1:n2);
	s = s1 + s2;
	printf("%.8lf",s);
	return 0;
}