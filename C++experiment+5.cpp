#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
class person//构造出person类，每一位员工都有这些属性
{
protected:
	string name;//名字
	int year;//工龄
	double gonglinggongzi;//工龄工资
	int id;//员工工号
public:
	virtual double getincome() = 0;//计算收入的纯虚函数
	virtual void print() = 0;//输出当前信息的纯虚函数
	virtual double getxiao()//返回销售额的函数，由于不是所有人都有这个函数，所以不能是纯虚函数
	{
		return 0;
	}
	person() : year(0),gonglinggongzi(0),name("NULL"),id(0){}
	person(const string& n,int y,int g,int d) :name(n), year(2019 - y + 1),gonglinggongzi(g), id(d){}
	void setname(const string& n)//修改名字的函数，以下类似
	{
		name = n;
	}
	void setyear(int n)
	{
		year = 2019 - n + 1;
	}
	void setgonglinggongzi(double g)
	{
		gonglinggongzi = g;
	}
	void setID(int d)
	{
		id = d;
	}
};
class xiaoshigong//小时工类，部分类有相似特点，于是多了这个类
{
protected:
	double he;//每小时工资
	int time;//月工作时长
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
public:
	gongren() : person("NULL",0,50,0),xiaoshigong(80,0){}
	gongren(const string& n,int y,double g,int d,double h,int t) : person(n,y,g,d),xiaoshigong(h,t){}
	double getincome()//计算工人工资
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)
			s = s * 1.2;
		return he * time + s;
	}
	void print()//输出工人信息
	{
		cout << "工人名字： " << name << endl;
		cout << "工人工号：" << id << endl;
		printf("月薪为：%lf\n\n",getincome());
	}
};
class saleman : public person,public xiaoshigong//销售员工类
{
private:
	double xiaoshoue;//销售额
public:
	saleman() : person("NULL",0,50,0),xiaoshigong(80,0),xiaoshoue(0){}
	saleman(const string& n, int y,double g,int d,double h,int t,double x): person(n,y,g,d),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()//计算销售员工的月薪
	{
		return he * time + year * gonglinggongzi + xiaoshoue * 0.01;
	}
	void setxiaoshoue(double x)
	{
		xiaoshoue = x;
	}
	void print()//对于销售员的信息输出
	{
		cout << "销售员姓名：" << name << endl;
		cout << "销售员工号：" << id << endl;
		printf("月薪为：%lf\n\n",getincome());
	}
	double getxiao()//返回销售额
	{
		return xiaoshoue;
	}
};
class guanli : public person//管理人员类
{
private:
	double jiben;//基本工资
public:
	guanli() : person("NULL",0,50,0),jiben(0) {}
	guanli(const string& n,int y, double g, int d,double j ) : person(n,y,g,d),jiben(j) {}
	double getincome()//计算管理人员工资
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()//输出管理人员信息
	{
		cout << "管理人员的名字是：" << name <<endl;
		cout << "管理人员的工号是：" << id << endl;
		printf("月薪为：%lf\n\n",getincome());
	}
	void setjiben(double s)
	{
		jiben = s;
	}
};
class SalesManager : public person//销售经理类
{
protected:
	double jiben;//基本工资
	double total;//销售总额
public:
	SalesManager() : person("NULL",0,50,0),jiben(0) {}
	SalesManager(const string& n,int y, double g, int d,double j = 5000) : person(n,y,g,d),jiben(j) {}
	double getincome()//计算销售经理月薪
	{
		return jiben + total * 0.06 + year * gonglinggongzi;
	}
	void print()//输出销售经理的消息
	{
		cout << "销售经理的名字是：" << name <<endl;
		cout << "销售经理的工号是：" << id << endl;
		printf("月薪为：%lf\n\n",getincome());
	}
	void settotal(double a)
	{
		total = a;
	}
	void setjiben(double j)
	{
		jiben = j;
	}
};
//创建链表来存放每个员工
class node
{
public:
	person *per;//每个链表的元素里都有一个基类指针用来调用
	node* next;
};
class LinkedList//单项链表
{
public:
	node* head;
	LinkedList() : head(NULL){}
	void insertHead(person *a)//头插入员工信息
	{
		node* p;
		p = new node;//开辟出一个新空间用于存放插入员工
		p->per = a;
		p->next = head;
		head = p;
	}
	void travalList()//遍历输出
	{
		if(head)
		{
			for(node* i = head;i != NULL;i = i->next)
			{
				i->per->print();
			}
		}
		else
			cout << "这是一个空链表"; 
			cout << endl;
	}
	void deleteList()//清空链表，释放空间
	{
		for(node* i = head;i != NULL;)
		{
			node* p = i;
			i = i->next;
			delete p;
			if(i == NULL)
				break;
		}
		head = NULL;

	}
	bool isEmpty()//判断链表是否为空
	{
		if(head == NULL)
			return true;
		else
			return false;
	}
};
double gettotalxse(LinkedList saleman)//计算销售总额，用于计算销售经理工资
{
	double s = 0;
	for(node* i = saleman.head;i != NULL;i = i->next)
	{
		s =  s + i->per->getxiao();
	}
	return s;
}
int main()
{
	int i = 1000;
	LinkedList salemanList;//存放销售员的链表
	LinkedList yuangong;//存放所有员工的链表
	while(1)//循环记录每一个员工信息
	{
		i++;
		string n;
		char a;
		cout << "请输入员工名字：（想要结束输出-1）" << endl;
		cin >> n;
		if(n == "-1")
			break;
		cout << "员工的类型（工人：G，销售员：X，管理人员：L，销售经理：J）（最后输入销售经理）" << endl;//最后才能输入销售经理，因为这是时的销售总额不会发生改变
		cin >> a;
		switch(a)
		{
			case 'G':
			{
				int y,t;
				double g = 50,h = 80;
				char c;
				cout << "入职年份：";
				cin >> y;
				cout << "是否需要输入第一年工龄工资（默认50元）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "是否需要输入时薪（默认80元/小时）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> h;
				cout << "输入工作时长：";
				cin >> t;
				gongren *x;
				x = new gongren(n,y,g,i,h,t);//用新指针去指向一个才开出的工人空间，这样这个工人的信息不会因为这一次循环而被清理，后面类同理
				yuangong.insertHead(x);//把新建的工人信息存入链表
				break;
			}
			case 'X':
			{
				int y,t;
				double g = 50,h = 80,X;
				char c;
				cout << "入职年份：";
				cin >> y;
				cout << "是否需要输入第一年工龄工资（默认50元/月）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "是否需要输入时薪（默认80元/小时）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> h;
				cout << "输入工作时长：";
				cin >> t;
				cout << "输入销售额：";
				cin >> X;
				saleman *x;
				x = new saleman(n,y,g,i,h,t,X);
				yuangong.insertHead(x);
				salemanList.insertHead(x);//销售人员还需要将其放入销售人员链表当中
				break;
			}
			case 'L' :
			{
				int y;
				double g = 50,j;
				char c;
				cout << "入职年份：";
				cin >> y;
				cout << "是否需要输入第一年工龄工资（默认50元/月）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "输入基本工资：";
				cin >> j;
				guanli *x;
				x = new guanli(n,y,g,i,j);
				yuangong.insertHead(x);
				break;
			}
			case 'J' :
			{
				int y;
				double g = 50,j = 5000;
				char c;
				cout << "入职年份：";
				cin >> y;
				cout << "是否需要输入第一年工龄工资（默认50元/月）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "是否需要输入固定工资（默认5000元/月）Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> j;
				SalesManager *x;
				x = new SalesManager(n,y,g,i,j);
				x->settotal(gettotalxse(salemanList));//销售经理最后需要将其销售总额设定好
				yuangong.insertHead(x);
				break;
			}
		}
	}
	yuangong.travalList();//遍历所有员工的链表
	salemanList.deleteList();
	yuangong.deleteList();//删除链表
	return 0;
}