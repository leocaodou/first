#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h> 
#include <stack>
using namespace std;
void LCSlength(int **c,int **b,string x,string y) // ���ڵõ�������еĺ���
{
	int m = x.size() - 1;
	int n = y.size() - 1;
	cout << "c����:" << endl;
	for(int i = 0;i <= m;i++)
	{
		c[0][i] = 0;
		b[0][i] = 0;		 
		cout << 0 << ' ';	//����c����ֻ�����У����Ը�ֵʱ���������������֮�����ݱ������޷����ֵ 
	}
	cout << endl;
	for(int i = 0;i <= 1;i++)
		c[i][0] = 0;
	for(int i = 0;i <= n;i++)
	{
		b[i][0] = 0;
	}
	for(int i = 1;i <= n;i++)	//һ��һ�еĿ�ʼ������� 
	{
		int k,q;
		k = i % 2;	//k�������c�����е���һ�У�ȷ�������ظ�ʹ�� 
		q = k == 0?1:0;			//q��ʾk����һ�е����ݣ���Ϊֻ�����У�����Ҫ�ж��ǵ�һ�л��ǵڶ��� 
		cout << 0 << ' ';		//���ÿ�еĵ�һ��c��������0 
		for(int j = 1;j <= m;j++)	//ÿ��С����һ������� 
		{
			if(x[j] == y[i])		//x�ַ����ĵ�j����y�ĵ�i����ͬ�Ļ�����������������Ҫ�����Ϸ��ļ�һ 
			{
				b[i][j] = 1;
				c[k][j] = c[q][j - 1] + 1;
			}
			else if(c[k][j-1] <= c[q][j])	//�ϱ�����Ľ����ڻ������ߵ�����Ľ⣬������ֵ�����ϱߵĽ� 
			{
				b[i][j] = 2;
				c[k][j] = c[q][j];
			}
			else		//����������෴ 
			{
				b[i][j] = 3;
				c[k][j] = c[k][j-1];
			}
			cout << c[k][j] << ' ';  
		}
		cout << endl;
	}
}
void GetLCS(int **b,int i,int j,string x)		//����������������󹫹��Ӵ�
{
	if(b[i][j] == 0)		//����Եʱ�ͽ����ݹ� 
		return;
	if(b[i][j] == 1)		//����1˵��xj == yi�����ַ���������Ӵ��� 
	{
		GetLCS(b,i - 1,j - 1,x);
		cout << x[j];			
	}
	else if(b[i][j] == 2)	//����2˵��������Ľ� 
	{
		GetLCS(b,i - 1,j,x);
	}
	else if(b[i][j] == 3)	//����3˵������ߵĽ� 
		GetLCS(b,i,j - 1,x);
}
int main()
{
	string p,q,x,y;
	cout << "������Ҫ�Ƚϵĵ�1���ַ�����";
	cin >> p;
	cout << "������Ҫ�Ƚϵĵ�2���ַ�����";
	cin >> q;
	int n = q.size(),m = p.size();
	x = ' ' + p;
	y = ' ' + q;
	int **c = new int* [2];			//����c���������ÿ��С����Ľ⣬Ϊ�˼�С�ռ临�Ӷȣ�c����ֻ������2�� 
	for(int i=0; i <= 1; i++)
		c[i] = new int[m + 1];
	int **b = new int* [n + 1];		//����b�����������cÿ��С��������ν���� 
	for(int i=0; i <= n; i++)
		b[i] = new int[m + 1];
	LCSlength(c,b,x,y);				//������������c��b���飬�����󹫹��Ӵ��ĳ���
	cout << "b����:" << endl;
	for(int i = 0;i <= n ;i++)
	{
		for(int j = 0;j <= m;j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}
	cout << p << "��" << q <<"����󹫹��Ӵ���:" << endl;
	GetLCS(b,n,m,x);		//�������������󹫹��Ӵ�
	cout << endl << "��󹫹��Ӵ��ĳ���Ϊ��"  << c[1][m];
	return 0;
}
