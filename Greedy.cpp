#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class JobNode	//作业的类
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
class Machine     //机器的类
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
void merge(JobNode *a,int i,int j,int m) //合并时的算法,已经改为符合为作业排序的版本
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
void mergesort(JobNode *a,int i,int j)  //合并排序
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
void sweap(Machine &a,Machine &b)  //交换值的函数
{
	Machine t;
	t = a;
	a = b;
	b = t;
}
void up(int p)		//将一个非顶点的节点向上提
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
void insert(Machine v)	//插入一个节点
{
	num++;
	heap[num] = v;
	up(num);
}
void down(int p)	//把一个节点向下调
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
void pop()		//删除顶点
{
	heap[1] = heap[num];
	num--;
	down(1);
}
void top()		//返回输出顶点的值
{
	cout << heap[1].id << '(' << heap[1].WorkTime <<')'<<endl;
}
int main()
{
	int n,m;
	cout << "请输入作业数量" << endl;
	cin >> n;
	JobNode *a = new JobNode[n+1];
	cout << "请输入作业处理时间，以空格隔开：" << endl;
	for(int i = 1;i <= n;i++)
	{
		a[i].no = i;
		cin >> a[i].time;
	}
	cout << "请输入机器数量" << endl;
	cin >> m;
	num = m;
	for(int i = 1;i <= m;i++)
	{
		heap[i].id = i;
		heap[i].WorkTime = 0;
	}
	cout << "作业输入情况：" << endl;
	cout << "ID  " ;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].no < 10)
			cout << a[i].no << "  ";
		else
			cout << a[i].no << " ";
	}
	cout << endl;
	cout << "时间" ;
	for(int i = 1;i <= n;i++)
	{	
		if(a[i].time < 10)
			cout << a[i].time << "  ";
		else
			cout << a[i].time << " ";
	}
	cout << endl;
	cout << "机器数量为：" << m << endl;
	cout << "----------------------------------------------------------------------" << endl;
	mergesort(a,1,n);
	cout << "排序后作业：" << endl;
	cout << "ID  " ;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].no < 10)
			cout << a[i].no << "  ";
		else
			cout << a[i].no << " ";
	}
	cout << endl;
	cout << "时间" ;
	for(int i = 1;i <= n;i++)
	{	
		if(a[i].time < 10)
			cout << a[i].time << "  ";
		else
			cout << a[i].time << " ";
	}
	cout << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "最小堆初始化，格式为：机器id(占用时间)" << endl;
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
		cout <<"将机器" << heap[1].id << "从" << heap[1].WorkTime << "到" << a[q].time << "的时间段分配给作业" << a[q].no << endl;
		cout << "调整后的最小堆，格式为：机器id(占用时间)" << endl;
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
	cout << "作业加工时间：" << heap[1].WorkTime << endl; 
}