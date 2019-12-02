#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
using namespace std;
int N,m=1;
void show(int *a)//输出结果的函数
{
	cout << m << endl;
	m++;
	for(int i = 1; i <= N;i++)//一行一行的输出
	{
		for(int j = 1; j < a[i]; j++)
		{
			cout << "口";//口代表空格
		}
		cout << "皇";//皇代表可以放皇后的位置
		for(int j = a[i] + 1; j <= N; j++)
		{
			cout << "口";
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool check(int x,int i,int* a)//检查这样皇后之间是否有冲突
{
	for(int j = 1;j <= x-1;j++)
	{
		if(i == a[j] || abs(x - j) == abs(i - a[j]))
			return false;//有冲突返回失败
	}
	return true;//没有冲突返回成功
}
void dfs(int x,int *a)//回溯
{
	if(x > N)//x大于n说明所有皇后均已安排好位置
	{
		show(a);
	}
	for(int i = 1;i <= N;i ++)
	{
		if(check(x,i,a))
		{
			a[x] = i;
			dfs(x+1,a);//目前位置成功，开始寻找下一个位
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