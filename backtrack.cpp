#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
int c1,c2,n = 5,w[6] = {0},bestw = 0,cw = 0,r = 0,wx,bestx[6],h[6];
void backtrack(int x)
{
	if(x > n)
	{
		bestw = cw;
		return;
	}
	r -=w[x];
	if(cw + w[x] <= c1)
	{
		cw += w[x];
		backtrack(x+1);
		cw -= w[x];
	}
	if(cw + r > bestw)
		backtrack(x+1);
	r+=w[x];
}
void backtrack2(int x)
{
	if(x > n )
	{
		if(cw == wx)
		{
			for (int i = 1; i <= 5; ++i)
			{
				bestx[i] = h[i];
			}
			return;
		}
		else
		{
			bestw = cw;
			return;
		}
		
	}
	r -=w[x];
	if(cw + w[x] <= c1)
	{
		cw += w[x];
		h[x] = 1;
		backtrack2(x+1);
		cw -= w[x];
	}
	if(cw + r > bestw)
	{
		backtrack2(x+1);
		h[x] = 0;
	}
	r+=w[x];
}
int main()
{
	int sum;
	cout << "�����������ִ������������Կո������" << endl;
	cin >> c1 >> c2;
	cout << "�����뼯װ���������Կո������" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		cin >> w[i];
		r += w[i];
	}
	sum = r;
	cout << "��һ�Ҵ���������Ϊ��" << c1 <<"���ڶ��Ҵ���������Ϊ��" << c2 << endl;
	cout << "5����װ�䣬�����ֱ�Ϊ��";
	for (int i = 1; i <= 5; ++i)
	{
		cout << w[i] << ' ';
	}
	cout << endl;
	if(r > c1 + c2)
	{
		cout << "�����ڿ��н�";
		return 0;
	}
	backtrack(1);
	wx = bestw;
	bestw =0;
	cw = 0;
	r = sum;
	if(sum - wx > c2)
	{
		cout << "�����ڿ��н�";
		return 0;
	}
	backtrack2(1);
	cout << "��װ��:";
	for(int i = 0;i <= 5;i++)
	{
		if(bestx[i] == 1)
			cout << i << "(����" << w[i] << ") "; 
	}
	cout << "װ���һ�Ҵ�" << endl;
	cout << "��װ��:";
	for(int i = 1;i <= 5;i++)
	{
		if(bestx[i] == 0)
			cout << i << "(����" << w[i] << ") "; 
	}
	cout << "װ��ڶ��Ҵ�" << endl;
}
