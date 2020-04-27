#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
void merge(int *a,int i,int j,int m) //合并时的算法
{
	cout << "合并：";
	for (int k = i; k <= m; k++)
	{
		cout << a[k] << ' ';
	}
	cout << "和";
	for (int k = m + 1; k <= j; k++)
	{
		cout << a[k] << ' ';
	}								//上面是对合并的两段数的输出
	cout << endl;
	int b[j - i + 1],k = 0;			//b数组用于存储合并好后的这段数，之后赋值
	int p = i,q = m + 1;
	while(1)
	{
		if(a[p] <= a[q])
		{
			b[k] = a[p];
			k++;
			if(p != m + 1)
				p++;
		}
		if(a[p] > a[q])
		{
			b[k] = a[q];
			k++;
			if(q != j + 1)
				q++;
		}
		if(p == m + 1)
		{
			for(;k < j - i + 1;k++)
			{
				b[k] = a[q];
				q++;
			}
			break;
		} 
		if(q == j + 1)
		{
			for(;k < j - i + 1;k++)
			{
				b[k] = a[p];
				p++;
			}
			break;
		} 
	}
	for(k = 0;k < j - i + 1;k++)
		a[i+k] = b[k];
}
void mergesort(int *a,int i,int j)  //合并排序
{
	if(i == j)
		return;//对一个数不需要进行排序
	else
	{
		int m = (i + j) / 2;  //找出这段数的中间位置分为两段
		mergesort(a,i,m);     //对前半段进行排序
		mergesort(a,m + 1,j); //对后半段进行排序
		merge(a,i,j,m);			//将前半段与后半段合并
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
	mergesort(a,0,n-1);
	for(int i = 0;i < n;i++)
		cout << a[i] << ' ';
	cout << "排序后数据：\n";
	for(int i = 0;i < n;i++)
		cout << a[i];

}
