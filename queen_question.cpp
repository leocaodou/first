#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int N,m=1;
void show(int *a)//�������ĺ���
{
	cout << m << endl;
	m++;
	for(int i = 1; i <= N;i++)//һ��һ�е����
	{
		for(int j = 1; j < a[i]; j++)
		{
			cout << "��";//�ڴ���ո�
		}
		cout << "��";//�ʴ�����ԷŻʺ��λ��
		for(int j = a[i] + 1; j <= N; j++)
		{
			cout << "��";
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool check(int x,int i,int* a)//��������ʺ�֮���Ƿ��г�ͻ
{
	for(int j = 1;j <= x-1;j++)
	{
		if(i == a[j] || abs(x - j) == abs(i - a[j]))
			return false;//�г�ͻ����ʧ��
	}
	return true;//û�г�ͻ���سɹ�
}
void dfs(int x,int *a)//����
{
	if(x > N)//x����n˵�����лʺ���Ѱ��ź�λ��
	{
		show(a);
	}
	for(int i = 1;i <= N;i ++)
	{
		if(check(x,i,a))
		{
			a[x] = i;
			dfs(x+1,a);//Ŀǰλ�óɹ�����ʼѰ����һ��λ
		}
	}
}
int main()
{
	cin >> N;
	int a[N];
	dfs(1,a);
	return 0;
}