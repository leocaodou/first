#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
class person
{
protected:
	string name;
	int year;
	double gonglinggongzi;
	int id;
public:
	virtual double getincome() = 0;
	virtual void print() = 0;
	virtual double getxiao()
	{
		return 0;
	}
	person() : year(0),gonglinggongzi(0),name("NULL"),id(0){}
	person(const string& n,int y,int g,int d) :name(n), year(2019 - y + 1),gonglinggongzi(g), id(d){}
	void setname(const string& n)
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
public:
	gongren() : person("NULL",0,50,0),xiaoshigong(80,0){}
	gongren(const string& n,int y,double g,int d,double h,int t) : person(n,y,g,d),xiaoshigong(h,t){}
	double getincome()
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)
			s = s * 1.2;
		return he * time + s;
	}
	void print()
	{
		cout << "工人名字： " << name << endl;
		cout << "工人工号：" << id << endl;
		printf("月薪为：%lf\n\n",getincome());
	}
};
class saleman : public person,public xiaoshigong
{
private:
	double xiaoshoue;
public:
	saleman() : person("NULL",0,50,0),xiaoshigong(80,0),xiaoshoue(0){}
	saleman(const string& n, int y,double g,int d,double h,int t,double x): person(n,y,g,d),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()
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
	double getxiao()
	{
		return xiaoshoue;
	}
};
class guanli : public person
{
private:
	double jiben;
public:
	guanli() : person("NULL",0,50,0),jiben(0) {}
	guanli(const string& n,int y, double g, int d,double j ) : person(n,y,g,d),jiben(j) {}
	double getincome()
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()
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
class SalesManager : public person
{
protected:
	double jiben;
	double total;
public:
	SalesManager() : person("NULL",0,50,0),jiben(0) {}
	SalesManager(const string& n,int y, double g, int d,double j = 5000) : person(n,y,g,d),jiben(j) {}
	double getincome()
	{
		return jiben + total * 0.06 + year * gonglinggongzi;
	}
	void print()
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
class node
{
public:
	person *per;
	node* next;
};
class LinkedList
{
public:
	node* head;
	LinkedList() : head(NULL){}
	void insertHead(person *a)
	{
		node* p;
		p = new node;
		p->per = a;
		p->next = head;
		head = p;
	}
	void travalList()
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
	void deleteList()
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
	bool isEmpty()
	{
		if(head == NULL)
			return true;
		else
			return false;
	}
};
double gettotalxse(LinkedList saleman)
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
	LinkedList salemanList;
	LinkedList yuangong;
	while(1)
	{
		i++;
		string n;
		char a;
		cout << "请输入员工名字：（想要结束输出-1）" << endl;
		cin >> n;
		if(n == "-1")
			break;
		cout << "员工的类型（工人：G，销售员：X，管理人员：L，销售经理：J）（最后输入销售经理）" << endl;
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
				x = new gongren(n,y,g,i,h,t);
				yuangong.insertHead(x);
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
				salemanList.insertHead(x);
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
				x->settotal(gettotalxse(salemanList));
				yuangong.insertHead(x);
				break;
			}
		}
	}
	yuangong.travalList();
	yuangong.deleteList();
	return 0;
}