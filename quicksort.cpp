#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int sort(int *a,int i,int j)		//��һ��������㷨
{
	int b = i,e = j;
	cout << endl << "����Χ" << endl;
	for(int q = i;q <= j;q++)
		cout << a[q] << ' ';
	cout << endl << "��׼Ԫ��a[p]=" << a[i] << endl;  //��������Ե�һ������Ϊ��׼
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
	cout << "�����"<< endl;
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
		int s = sort(a,i,j);  //��һ������˳�㷵��һ������֮���׼�����±�
		quicksort(a,i,s - 1); //�Ի�׼��ǰ������������
		quicksort(a,s + 1,j); //�Ի�׼���������������
	}
}
int main()
{
	int n;
	cout << "������Ҫ��������ĸ���\n";
	cin >> n;
	int *a = new int[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	quicksort(a,0,n-1);
	cout << endl << "��������ݣ�"<<endl;
	for(int i = 0;i < n;i++)
		cout << a[i] << ' ';
}
