#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class QWQ//用于排序时储存数据和名字
{
public:
	string name;
	int c;
};
bool cmp(QWQ a,QWQ b)//在排序的标准
{
	if(a.c < b.c)
		return true;
	else
		return false;
}
class date
{
public:
	int month;//月
	int day;//日
	int level;//缺课等级
	string ke;//所缺课程名字
	int jie;//节
	date():month(0),day(0),level(0),ke("NULL"),jie(0){}
	date(int m,int d,int l,const string& k,int j) : month(m),day(d),level(l),ke(k),jie(j){}//有5个参数的构造函数，由于录入信息
	date(int m,int d,int j) : month(m),day(d),jie(j){}//只有月日节三个参数的构造函数，用于信息的查找
	bool operator>= (const date& d)//对于运算符>=的重载，对于日期的比较，我们只需要挨个比较月日节就行了
	{
		if(month > d.month)
			return true;
		if(month == d.month)
		{
			if(day > d.day)
				return true;
			if(day == d.day)
			{
				if(jie >= d.jie)
					return true;
				else
					return false;
			}
			return false;
		}
		return false;
	}
	bool operator<= (const date& d)//对于操作符<=的重载，与>=相似
	{
		if(month < d.month)
			return true;
		if(month == d.month)
		{
			if(day < d.day)
				return true;
			if(day == d.day)
			{
				if(jie <= d.jie)
					return true;
				else
					return false;
			}
			return false;
		}
		return false;
	}
	bool operator== (const date& d)//对于操作符==的重载，判断日期是否相等
	{
		if(month == d.month && day == d.day && jie == d.jie)
			return true;
		else
			return false;
	}
};
template <typename T>//泛型
class node
{
public:
	T data;//储存数据
	node* next;
	friend ostream& operator << (ostream& ,const node<date>& );//专门输出时间这个类型的链表
};
ostream& operator << (ostream& out ,const node<date>& n)//专门输出时间这个类型的链表的具体实现
{
	out << n.data.month << "月" << n.data.day << "日第" << n.data.jie << "节的" << n.data.ke << "课";
	switch(n.data.level)//记得加上等级
	{
		case 1 :
		{
			cout << "迟到了";
			break; 
		}
		case 2 :
		{
			cout << "早退了";
			break;
		}
		case 3 :
		{
			cout << "请假了";
			break;
		}
		case 4 :
		{
			cout << "旷课了";
			break;
		} 
	}
	return out;
}
template <typename T>//链表泛型
class dateLink
{
public:
	node<T>* head;
	dateLink() : head(NULL){}
	void insertHead(T a)//插入元素
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void remove(T d)//链表元素的删除
	{
		for(node<T>* i = head;i != NULL;)
		{
			if(head->data == d)
			{
				node<T>* p = i;
				head = p->next;
				i = p->next;
				delete p;
				return;
			}
			else if(i->next)
			{
				if(i->next->data == d)
				{
					node<T>* p = i->next;
					i->next = p->next;
					i = i->next;
					delete p;
					return;
				}
				else
					i = i->next;
			}
			else
				i = i->next;
		}
	}
	node<T>* find(T d)//查找链表某一个元素
	{
		node<T>* i;
		for(i = head;i != NULL;i = i->next)
		{
			if(i->data == d)
			{
				return i;
			}
		}
		return NULL;
	}
	void travalList()//遍历链表
	{
		if(head)
		{
			for(node<T>* i = head;i != NULL;i = i->next)
			{
				cout << *i << endl;
			}
		}
		else
			cout << "这位同学没有缺过课"; //链表为空
			cout << endl;
	}
	void deleteList()//删除整个链表，释放空间
	{
		for(node<T>* i = head;i != NULL;)
		{
			node<T>* p = i;
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
class student//学生类
{
public:
	string n;//储存学生姓名
	dateLink<date> que;//储存同学的缺课信息
	student() : n("NULL"){}
	student(const string& _n) : n(_n){}
	void getdate(date d)//录入学生的缺课信息
	{
		que.insertHead(d);
	}
	void chaxunall()//查询学生的所有缺课情况
	{
		que.travalList();
	}
	void deletedateall()//删除所有的缺课信息
	{
		que.deleteList();
	}
	void deletedate(date d)//删除具体某一个时间的链表
	{
		que.remove(d);
	}
	int ci(date a,date b)//统计在某段时间内的缺课次数
	{
		int s = 0;
		for(node<date>* i = que.head;i != NULL;i = i->next)
		{
			if(i->data >= a && i->data <= b && i->data.level == 4)
				s++;
		}
		return s;
	}
	bool operator==(const student& x)//对于==的重载，用于判断两个学生是否相同
	{
		if(n == x.n)
			return true;
		else
			return false;
	}
};
class ke//课程的类
{
public:
	string n;
	dateLink<date> da;//储存缺席这门课程的时间
	ke() : n("NULL"){}//
	ke(const string& _n) : n(_n){}
	//后面的函数内容与student类大同小异
	void getdate(date d)
	{
		da.insertHead(d);
	}
	void deletedateall()
	{
		da.deleteList();
	}
	int ci(date a,date b)
	{
		int s = 0;
		for(node<date>* i = da.head;i != NULL;i = i->next)
		{
			if(i->data >= a && i->data <= b && i->data.level == 4)
				s++;
		}
		return s;
	}
	bool operator==(const ke& x)
	{
		if(n == x.n)
			return true;
		else
			return false;
	}
};
int main()
{
	int st = 0,kc = 0;
	dateLink<student> stu;//建立student的链表，用于储存学生信息
	dateLink<ke> k;//建立课程的链表，用于储存课程
	while(1)
	{
		cout << "_________________________________________________________________________________" << endl;
		cout << "****************请问您想要做什么？****************\n（1）录入学生的缺课记录（按1）\n（2）修改某个学生的缺课记录（按2）\n（3）查询某个学生的缺课记录（按3）\n（4）删除某个学生的缺课记录（按4）\n（5）统计某段时间内，某门课旷课学生姓名及旷课次数，按旷课次数由少到多排序（按5）\n（6）统计某短时间内，有学生旷课的课程及旷课次数，按旷课人次由少到多排序（按6）\n（7）退出程序（按7）\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//对于目录的输出
		cout << "使用功能：";
		int n;
		fflush(stdin);//清除缓冲区，防止死循环
		scanf("%d",&n);
		//功能选用
		if(n == 7)
		{
			cout << "感谢您的使用，欢迎再次使用" <<  endl;
			break;
		}
		switch(n)
		{
			case 1 : //录入学生缺课记录
			{
				string name,kec;
				cout << "请输入学生的姓名" << endl;
				cin >> name;
				cout << "请输入课程日期，以及第几节课（例如1月1日第2节课输入 1 1 2）" << endl;
				int n,y,j;
				cin >> n >> y >>j;
				cout << "请输入课程名称" << endl;
				cin >> kec;
				node<ke> *q;
				q = k.find(ke(kec));//先查找在课程链表中是否已经有该课程
				if(!q)//如果没有该课程
				{
					ke p(kec);//构造一个该类的课程
					kc++;//课程数目加一
					k.insertHead(p);//把这课程添加到课程链表内
					q = k.find(p);//继续把q指向课程链表的该课程
				}
				cout << "请输入缺课类型   迟到（1）早退（2）请假（3）旷课（4）" << endl;
				int o;
				cin >> o;
				date D(n,y,o,kec,j);//构造一个该课程信息
				q->data.da.insertHead(D);//把这个日期添加到课程当中
				node<student> *w;
				w = stu.find(student(name));//先查找在学生链表当中是否已经有这一位同学
				if(!w)//没有的话
				{
					student p(name);//构造一个该学生
					stu.insertHead(p);//在学生链表当中添加该学生
					st++;//学生数目加一
					w = stu.find(p);//让指针指向该学生
				}
				w->data.que.insertHead(D);//在学生信息中添加这个缺课信息
				cout << "记录成功！" << endl;
				break;

			}
			case 2://修改某同学的信息
			{
				string name;
				cout << "请输入你想要修改的同学的名字" << endl;
				cin >> name;
				node<student> *p;
				p = stu.find(student(name));//让指针指向该学生
				if(!p)//若指针为空
				{
					cout << "这位同学没有缺过课" << endl;
					break;
				}
				cout << "请输入您需要修改的日期和第几节课（例如1月1日第2节课输入 1 1 2）" << endl;
				int m,d,j;
				cin >> m >> d >> j;//修改的某一天
				date D(m,d,j);
				node<date> *q;
				q = p->data.que.find(D);//指向该学生的那一天信息
				if(!q)//若指针为空
				{
					cout << "这个时间这位同学没有缺课" << endl;
					break;
				}
				cout << "请问你是（1）准备改时间（2）修改课程（3）修改缺课改类型" << endl;
				int n;
				fflush(stdin);//清除缓冲区，防止死循环
				scanf("%d",&n);
				switch(n)//配对修改
				{
					case 1 :
					{
						cout << "输入你要修改的时间" << endl;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//找到课程，因为在修改学生信息的同时，课程相关信息也必须修改
						int _m,_d,_j;
						cin >> _m >> _d >> _j;//输入需要修改的几月几日第几节
						q->data.month = _m;
						q->data.day = _d;
						q->data.jie = _j;
						node<date> *r;
						r = w->data.da.find(D);//找到对应课程的需要修改日期
						r->data.month = _m;
						r->data.day = _d;
						r->data.jie = _j;
						break;
					}
					case 2:
					{
						cout << "输入你要修改的课程" << endl;
						string kk;
						cin >> kk;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//我们也需要对相关课程进行修改
						w->data.da.remove(D);
						q->data.ke = kk;//把日期信息修改
						D = q->data;
						w = k.find(ke(kk));//查看修改后的课程是否存在
						if(w)
							w->data.da.insertHead(D);//存在的话直接加上
						else
						{
							ke o(kk);
							kc++;
							k.insertHead(o);
							w = k.find(ke(kk));
							w->data.da.insertHead(D);
						}
						break;
					}
					case 3 :
					{
						cout << "输入你要修改缺课类型" << endl;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//把当日课程找到
						int l;
						cin >> l;
						q->data.level = l;//修改
						node<date> *r;
						r = w->data.da.find(D);//同样修改课程那里的情况
						r->data.level = l;
						break;
					}
					default ://输入均不匹配
					{
						cout << "输入错误" << endl;
						break;
					}
				}
				cout << "修改成功！"<<endl;
				break; 
			}
			case 3 :
			{
				cout << "请输入你想要查看的同学的名字" << endl;
				string n;
				cin >> n;
				node<student> *p;
				p = stu.find(student(n));//找到这位同学
				if(!p)//若指针为空
				{
					cout << "这个时间这位同学没有缺课";
					break;
				}
				p->data.que.travalList();
				break;
			}
			case 4 :
			{
				cout << "请输入你想要删除缺课记录同学的名字" << endl;
				string n;
				cin >> n;
				node<student> *p;
				p = stu.find(student(n));
				if(!p)
				{
					cout << "这个时间这位同学没有缺课" << endl;
					break;
				}
				cout << "请问是想（1）删除所有的记录还是（2）具体某个时间的记录" << endl;
				int f;
				fflush(stdin);//清除缓冲区，防止死循环
				scanf("%d",&f);
				switch(f)
				{
					case 1 :
					{
						p->data.deletedateall();
						break;
					}
					case 2 :
					{
						cout << "输入你要删除记录的时间" << endl;
						int m,d,j;
						cin >> m >> d >> j;
						date D(m,d,j);
						p->data.deletedate(D);//调用删除时间的函数
						break;
					}
					default :
					{
						cout << "输入错误" << endl;
					}
				}
				break;
			}
			case 5 :
			{
				int m,d,j;
				cout << "请输入需要查询的两个时间段\n" << "从多久开始（月 日 节）" << endl;
				cin >> m >> d >> j;
				date A(m,d,j);
				cout << "到多久结束（月 日 节）"<< endl;
				cin >> m >> d >> j;
				date B(m,d,j);
				QWQ f[st];//把所有的学生放入数组当中，便于排序
				node<student>* ji = stu.head;
				for(int i = 0;i < st;i++)//存储数据
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + st,cmp);//调用sort函数排序
				for(int i = 0;i < st;i++)//依次输出
				{
					cout << f[i].name <<"在所给时间内缺课" << f[i].c << "次" << endl;
				}
				break;
			}
			case 6:
			{
				int m,d,j;
				cout << "请输入需要查询的两个时间段\n" << "从多久开始（月 日 节）" << endl;
				cin >> m >> d >> j;
				date A(m,d,j);
				cout << "到多久结束（月 日 节）"<< endl;
				cin >> m >> d >> j;
				date B(m,d,j);
				QWQ f[kc];//把所有的课程及其数据放入数组
				node<ke>* ji = k.head;
				for(int i = 0;i < kc;i++)//开始录入数据
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + kc,cmp);
				for(int i = 0;i < kc;i++)
				{
					cout << f[i].name <<"课在所给时间内有" << f[i].c << "人缺课" << endl;
				}
				break;
			}
			default :
			{
				cout << "输入错误，重新输入" << endl;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}
	stu.deleteList();
	k.deleteList();
	return 0;
}
