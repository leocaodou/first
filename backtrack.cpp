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
	cout << "请输入两艘轮船的载重量，以空格隔开：" << endl;
	cin >> c1 >> c2;
	cout << "请输入集装箱重量，以空格隔开：" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		cin >> w[i];
		r += w[i];
	}
	sum = r;
	cout << "第一艘船的载重量为：" << c1 <<"，第二艘船的载重量为：" << c2 << endl;
	cout << "5个集装箱，重量分别为：";
	for (int i = 1; i <= 5; ++i)
	{
		cout << w[i] << ' ';
	}
	cout << endl;
	if(r > c1 + c2)
	{
		cout << "不存在可行解";
		return 0;
	}
	backtrack(1);
	wx = bestw;
	bestw =0;
	cw = 0;
	r = sum;
	if(sum - wx > c2)
	{
		cout << "不存在可行解";
		return 0;
	}
	backtrack2(1);
	cout << "集装箱:";
	for(int i = 0;i <= 5;i++)
	{
		if(bestx[i] == 1)
			cout << i << "(重量" << w[i] << ") "; 
	}
	cout << "装入第一艘船" << endl;
	cout << "集装箱:";
	for(int i = 1;i <= 5;i++)
	{
		if(bestx[i] == 0)
			cout << i << "(重量" << w[i] << ") "; 
	}
	cout << "装入第二艘船" << endl;
}
