#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
void merge(int *a,int i,int j,int m) //�ϲ�ʱ���㷨
{
	cout << "�ϲ���";
	for (int k = i; k <= m; k++)
	{
		cout << a[k] << ' ';
	}
	cout << "��";
	for (int k = m + 1; k <= j; k++)
	{
		cout << a[k] << ' ';
	}								//�����ǶԺϲ��������������
	cout << endl;
	int b[j - i + 1],k = 0;			//b�������ڴ洢�ϲ��ú���������֮��ֵ
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
void mergesort(int *a,int i,int j)  //�ϲ�����
{
	if(i == j)
		return;//��һ��������Ҫ��������
	else
	{
		int m = (i + j) / 2;  //�ҳ���������м�λ�÷�Ϊ����
		mergesort(a,i,m);     //��ǰ��ν�������
		mergesort(a,m + 1,j); //�Ժ��ν�������
		merge(a,i,j,m);			//��ǰ�������κϲ�
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
	mergesort(a,0,n-1);
	for(int i = 0;i < n;i++)
		cout << a[i] << ' ';
	cout << "��������ݣ�\n";
	for(int i = 0;i < n;i++)
		cout << a[i];

}
