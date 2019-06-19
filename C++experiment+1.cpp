#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class person//最为基本的类，拥有每一位子类都有的成员，工龄与相应的工龄工资
{
protected:
	int year;
	double gonglinggongzi;
public:
	virtual double getincome() = 0;//纯虚函数，用于每个派生类的计算工资
	virtual void print() = 0;//纯虚函数，用于输出每个派生类的相应资料
	person() : year(0),gonglinggongzi(0){}
	person(int y,int g) : year(2019 - y + 1),gonglinggongzi(g){}//有参的构造函数，这里可以自动吧输入的入职年份转化为工龄
	void setyear(int n)//用于修改对象的入职年份
	{
		year = 2019 - n + 1;
	}
	void setgonglinggongzi(double g)//用于修改对象的工龄工资
	{
		gonglinggongzi = g;
	}
};
class xiaoshigong//工人与销售员均继承的小时工类
{
protected:
	double he;//每小时的工资
	int time;//每月工作时间
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
class gongren : public person,public xiaoshigong//工人类
{
private:
	int id;//工人特有成员，工号
public:
	gongren() : person(0,50),xiaoshigong(80,0){}
	gongren(int d,int y,double h,int t,double g) : id(d),person(y,g),xiaoshigong(h,t){}
	double getincome()//对于工人的工资算法
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)//计算每年递增的工龄工资
			s = s * 1.2;
		return he * time + s;
	}
	void setID(int i)
	{
		id = i;
	}
	void print()//对于工人这个类的信息输出
	{
		cout << "工人工号：" << id << endl;
		cout << "月工作时数：" << time << endl;
		cout << "总工资："<<endl;
		printf("%lf\n",getincome());
	}
};
class saleman : public person,public xiaoshigong//销售员类
{
private:
	double xiaoshoue;//销售员特有的成员，销售额
public:
	saleman() : person(0,200),xiaoshigong(),xiaoshoue(0){}
	saleman(int y,double h,int t,double x,double g ): person(y,g),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()//对于销售员的的工资算法
	{
		return he * time + year * gonglinggongzi + xiaoshoue * 0.01;
	}
	void setxiaoshoue(double x)
	{
		xiaoshoue = x;
	}
	void print()//对于销售员的信息输出
	{
		cout << "月工作时数：" << time << endl;
		cout << "总工资："<<endl;
		printf("%lf\n",getincome());
	}
};
class guanli : public person//管理人员类
{
private:
	double jiben;//管理人员特有的成员，基本工资
public:
	guanli() : person(0,50),jiben(0) {}
	guanli(int y, double j,double g ) : person(y,g),jiben(j) {}
	double getincome()//对于管理人员的工资算法
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()//对于管理人员的信息输出
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
	cout << "有工人多人个？" << endl; 
	cin >> j;//输入工人的人数
	for(int i =1;i <= j;i++)//循环输入每一个工人信息，下同
	{	
		cout << "第" << i << "个工人信息" << endl;
		gongren a;
		int x;
		double y;
		cout << "工人工号：";
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
		cout << endl;
	}
	cout << "有销售多人个？" << endl;
	cin >> k;
	for(int i =1;i <= k;i++)
	{
		cout << "第" << i << "个销售员信息" << endl;
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
		cout << endl;
	}
	cout << "管理多人个？" << endl;
	cin >> l;
	for(int i =1;i <= l;i++)
	{
		cout << "第" << i << "个管理人员信息" << endl;
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
		cout << endl;
	}
}