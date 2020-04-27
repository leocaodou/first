#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
void LCSlength(int **c,int **b,string x,string y) // 用于得到最长子序列的函数
{
	int m = x.size() - 1;
	int n = y.size() - 1;
	cout << "c矩阵:" << endl;
	for(int i = 0;i <= m;i++)
	{
		c[0][i] = 0;
		b[0][i] = 0;		 
		cout << 0 << ' ';	//由于c数组只有两行，所以赋值时就输出出来，以免之后数据被覆盖无法输出值 
	}
	cout << endl;
	for(int i = 0;i <= 1;i++)
		c[i][0] = 0;
	for(int i = 0;i <= n;i++)
	{
		b[i][0] = 0;
	}
	for(int i = 1;i <= n;i++)	//一行一行的开始解决问题 
	{
		int k,q;
		k = i % 2;	//k代表该用c数组中的哪一行，确保可以重复使用 
		q = k == 0?1:0;			//q表示k的上一行的数据，因为只有两行，所以要判断是第一行还是第二行 
		cout << 0 << ' ';		//输出每行的第一个c数组数据0 
		for(int j = 1;j <= m;j++)	//每行小问题一个个解决 
		{
			if(x[j] == y[i])		//x字符串的第j个和y的第i个相同的话，该问题的最长子序列要比左上方的加一 
			{
				b[i][j] = 1;
				c[k][j] = c[q][j - 1] + 1;
			}
			else if(c[k][j-1] <= c[q][j])	//上边问题的解优于或等于左边的问题的解，该问题值赋给上边的解 
			{
				b[i][j] = 2;
				c[k][j] = c[q][j];
			}
			else		//与上面情况相反 
			{
				b[i][j] = 3;
				c[k][j] = c[k][j-1];
			}
			cout << c[k][j] << ' ';  
		}
		cout << endl;
	}
}
void GetLCS(int **b,int i,int j,string x)		//这个函数用于输出最大公共子串
{
	if(b[i][j] == 0)		//到边缘时就结束递归 
		return;
	if(b[i][j] == 1)		//等于1说明xj == yi，该字符在最长公共子串中 
	{
		GetLCS(b,i - 1,j - 1,x);
		cout << x[j];			
	}
	else if(b[i][j] == 2)	//等于2说明是上面的解 
	{
		GetLCS(b,i - 1,j,x);
	}
	else if(b[i][j] == 3)	//等于3说明是左边的解 
		GetLCS(b,i,j - 1,x);
}
int main()
{
	string p,q,x,y;
	cout << "请输入要比较的第1个字符串：";
	cin >> p;
	cout << "请输入要比较的第2个字符串：";
	cin >> q;
	int n = q.size(),m = p.size();
	x = ' ' + p;
	y = ' ' + q;
	int **c = new int* [2];			//建立c数组来存放每个小问题的解，为了减小空间复杂度，c数组只设置了2行 
	for(int i=0; i <= 1; i++)
		c[i] = new int[m + 1];
	int **b = new int* [n + 1];		//建立b数组用来存放c每个小问题是如何解决的 
	for(int i=0; i <= n; i++)
		b[i] = new int[m + 1];
	LCSlength(c,b,x,y);				//函数用于填满c和b数组，求出最大公共子串的长度
	cout << "b矩阵:" << endl;
	for(int i = 0;i <= n ;i++)
	{
		for(int j = 0;j <= m;j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}
	cout << p << "和" << q <<"的最大公共子串是:" << endl;
	GetLCS(b,n,m,x);		//函数用于输出最大公共子串
	cout << endl << "最大公共子串的长度为："  << c[1][m];
	return 0;
}
