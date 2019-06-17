#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class person
{
protected:
	int year;
	double gonglinggongzi;
public:
	virtual double getincome() = 0;
	virtual void print() = 0;
	person() : year(0){}
	person(int y,int g) : year(2019 - y + 1),gonglinggongzi(g){}
	void setyear(int n)
	{
		year = 2019 - n + 1;
	}
	void setgonglinggongzi(int g)
	{
		gonglinggongzi = g;
	}
};
class xiaoshigong
{
protected:
	double he;
	int time;
public:
	xiaoshigong() : he(0),time(0){}
	xiaoshigong(double h,int t) : he(h),time(t){}
	void sethe(double s)
	{
		he = s;
	}
	void settime(int t)
	{
		time = t;
	}
};
class gongren : public person,public xiaoshigong
{
private:
	int id;
public:
	gongren() : person(0,50),xiaoshigong(80,0){}
	gongren(int d,int y,double h,int t,double g) : id(d),person(y,g),xiaoshigong(h,t){}
	double getincome()
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)
			s = s * 1.2;
		return he * time + s;
	}
	void setID(int i)
	{
		id = i;
	}
	void print()
	{
		cout << "工人工号：" << id << endl;
		cout << "月工作时数：" << time << endl;
		cout << "总工资："<<endl;
		printf("%lf\n",getincome());
	}
};
class saleman : public person,public xiaoshigong
{
private:
	double xiaoshoue;
public:
	saleman() : person(0,200),xiaoshigong(),xiaoshoue(0){}
	saleman(int y,double h,int t,double x,double g ): person(y,g),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()
	{
		return he * time + year * gonglinggongzi + xiaoshoue * 0.01;
	}
	void setxiaoshoue(double x)
	{
		xiaoshoue = x;
	}
	void print()
	{
		cout << "月工作时数：" << time << endl;
		cout << "总工资："<<endl;
		printf("%lf\n",getincome());
	}
};
class guanli : public person
{
private:
	double jiben;
public:
	guanli() : person(0,50),jiben(0) {}
	guanli(int y, double j,double g ) : person(y,g),jiben(j) {}
	double getincome()
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()
	{
		cout << "总工资："<<endl;
		printf("%lf\n",getincome());
	}
	void setjiben(double s)
	{
		jiben = s;
	}
};
int main()
{
	int j,k,l;
	cout << "有工人多人个？";
	cin >> j;
	for(int i =1;i <= j;i++)
	{	
		gongren a;
		int x;
		double y;
		cout << "工人工号";
		cin >> x;
		a.setID(x);
		cout << "参加工作时间：";
		cin >> x;
		a.setyear(x);
		cout << "工人工资：";
		cin >> y;
		a.sethe(y);
		cout << "月工作时数：";
		cin >> x;
		a.settime(x);
		cout << endl;
		a.print();
	}
	cout << "有销售多人个？";
	cin >> k;
	for(int i =1;i <= k;i++)
	{
		saleman a;
		int x;
		double y;
		cout << "参加工作时间：";
		cin >> x;
		a.setyear(x);
		cout << "每小时工资：";
		cin >> y;
		a.sethe(y);
		cout << "月工作时数：";
		cin >> x;
		a.settime(x);
		cout << "销售额：";
		cin >> y;
		a.setxiaoshoue(y);
		cout << endl;
		a.print();
	}
	cout << "管理多人个？";
	cin >> l;
	for(int i =1;i <= l;i++)
	{
		guanli a;
		int x;
		double y;
		cout << "参加工作时间：";
		cin >> x;
		a.setyear(x);
		cout << "基本工资：";
		cin >> y;
		a.setjiben(y);
		cout << endl;
		a.print();
	}
}