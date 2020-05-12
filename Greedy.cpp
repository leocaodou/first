#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class JobNode	//��ҵ����
{
public:
	int no;
	int time;
	JobNode& operator =(JobNode x)
	{
		this->no = x.no;
		this->time = x.time;
		return *this;
	}
};
class Machine     //��������
{
public:
	int id;
	int WorkTime = 0;
	Machine& operator =(Machine x)
	{
		this->id = x.id;
		this->WorkTime = x.WorkTime;
		return *this;
	}
};
Machine heap[100];
int num = 0;
void merge(JobNode *a,int i,int j,int m) //�ϲ�ʱ���㷨,�Ѿ���Ϊ����Ϊ��ҵ����İ汾
{
	JobNode b[j - i + 1];
	int k = 0;
	int p = i,q = m + 1;
	while(1)
	{
		if(a[p].time <= a[q].time)
		{
			b[k] = a[p];
			k++;
			if(p != m + 1)
				p++;
		}
		if(a[p].time > a[q].time)
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
void mergesort(JobNode *a,int i,int j)  //�ϲ�����
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
void sweap(Machine &a,Machine &b)  //����ֵ�ĺ���
{
	Machine t;
	t = a;
	a = b;
	b = t;
}
void up(int p)		//��һ���Ƕ���Ľڵ�������
{
	while(p)
	{
		if(heap[p/2].WorkTime > heap[p].WorkTime)
			sweap(heap[p/2] , heap[p]);
		else
			break;
		p = p / 2;
	}
}
void insert(Machine v)	//����һ���ڵ�
{
	num++;
	heap[num] = v;
	up(num);
}
void down(int p)	//��һ���ڵ����µ�
{
	int s=p*2;
  	while(s <= num)
  	{ 
	    if(s < num && heap[s+1].WorkTime < heap[s].WorkTime) 
	    	s++; 
	    if(heap[s].WorkTime < heap[p].WorkTime)
	    {
	      	swap(heap[s],heap[p]);
	      	p = s;
	      	s = p * 2;
	    }
	    else break;
  	}
}
void pop()		//ɾ������
{
	heap[1] = heap[num];
	num--;
	down(1);
}
void top()		//������������ֵ
{
	cout << heap[1].id << '(' << heap[1].WorkTime <<')'<<endl;
}
int main()
{
	int n,m;
	cout << "��������ҵ����" << endl;
	cin >> n;
	JobNode *a = new JobNode[n+1];
	cout << "��������ҵ����ʱ�䣬�Կո������" << endl;
	for(int i = 1;i <= n;i++)
	{
		a[i].no = i;
		cin >> a[i].time;
	}
	cout << "�������������" << endl;
	cin >> m;
	num = m;
	for(int i = 1;i <= m;i++)
	{
		heap[i].id = i;
		heap[i].WorkTime = 0;
	}
	cout << "��ҵ���������" << endl;
	cout << "ID  " ;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].no < 10)
			cout << a[i].no << "  ";
		else
			cout << a[i].no << " ";
	}
	cout << endl;
	cout << "ʱ��" ;
	for(int i = 1;i <= n;i++)
	{	
		if(a[i].time < 10)
			cout << a[i].time << "  ";
		else
			cout << a[i].time << " ";
	}
	cout << endl;
	cout << "��������Ϊ��" << m << endl;
	cout << "----------------------------------------------------------------------" << endl;
	mergesort(a,1,n);
	cout << "�������ҵ��" << endl;
	cout << "ID  " ;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].no < 10)
			cout << a[i].no << "  ";
		else
			cout << a[i].no << " ";
	}
	cout << endl;
	cout << "ʱ��" ;
	for(int i = 1;i <= n;i++)
	{	
		if(a[i].time < 10)
			cout << a[i].time << "  ";
		else
			cout << a[i].time << " ";
	}
	cout << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "��С�ѳ�ʼ������ʽΪ������id(ռ��ʱ��)" << endl;
	cout << ".............................................................." << endl;
	int k = m/2+1,p=1;
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= k-i;j++)
			cout << "        ";
		for(int j = 1;j <= pow(2,i-1);j++)
		{
			printf("%d(%d)",heap[p].id,heap[p].WorkTime);
			p++;
			cout << "        ";
			if(p == m + 1)
				break;
		}
		cout << endl;
	}
	cout << ".............................................................." << endl;
	int q = n;
	while(q)
	{
		cout <<"������" << heap[1].id << "��" << heap[1].WorkTime << "��" << a[q].time << "��ʱ��η������ҵ" << a[q].no << endl;
		cout << "���������С�ѣ���ʽΪ������id(ռ��ʱ��)" << endl;
		cout << ".............................................................." << endl;
		heap[1].WorkTime += a[q].time;
		down(1);
		int k = m/2+1,p=1;
		for(int i = 1;i <= k;i++)
		{
			for(int j = 1;j <= k-i;j++)
				cout << "        ";
			for(int j = 1;j <= pow(2,i-1);j++)
			{
				printf("%d(%d)",heap[p].id,heap[p].WorkTime);
				p++;
				cout << "        ";
				if(p == m+1)
					break;
			}
			cout << endl;
		}
		cout << ".............................................................." << endl;
		q--;
	}
	down(1);
	for(int i = 1;i <= m-1;i++)
	{
		pop();
	}
	cout << "��ҵ�ӹ�ʱ�䣺" << heap[1].WorkTime << endl; 
}