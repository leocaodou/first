#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int sort(int *a,int i,int j)		//做一趟排序的算法
{
	int b = i,e = j;
	cout << endl << "排序范围" << endl;
	for(int q = i;q <= j;q++)
		cout << a[q] << ' ';
	cout << endl << "基准元素a[p]=" << a[i] << endl;  //这里均是以第一个数作为基准
	int k = a[i];
	while(i < j)
	{
		while(i < j && a[j] > k)
		{
			j--;
		}
		if(i < j)
		{
			a[i] = a[j];
		}
		while(i < j && a[i] < k)
		{
			i++;
		}
		if(i < j)
		{
			a[j] = a[i];
		}
	}
	a[i] = k;
	cout << "排序后："<< endl;
	for(int q = b;q <= e;q++)
		cout << a[q] << ' ';
	cout << endl;
	return i;
}
void quicksort(int* a,int i,int j)
{
	if(i >= j)
		return;
	else
	{
		int s = sort(a,i,j);  //做一趟排序，顺便返回一趟排序之后基准数的下标
		quicksort(a,i,s - 1); //对基准数前的数进行排序
		quicksort(a,s + 1,j); //对基准数后的数进行排序
	}
}
int main()
{
	int n;
	cout << "输入需要排序的数的个数\n";
	cin >> n;
	int *a = new int[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	quicksort(a,0,n-1);
	cout << endl << "排序后数据："<<endl;
	for(int i = 0;i < n;i++)
		cout << a[i] << ' ';
}
