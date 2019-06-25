#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class QWQ
{
public:
	string name;
	int c;
};
bool cmp(QWQ a,QWQ b)
{
	if(a.c < b.c)
		return true;
	else
		return false;
}
class date
{
public:
	int month;
	int day;
	int level;
	string ke;
	int jie;
	date():month(0),day(0),level(0),ke("NULL"),jie(0){}
	date(int m,int d,int l,const string& k,int j) : month(m),day(d),level(l),ke(k),jie(j){}
	date(int m,int d,int j) : month(m),day(d),jie(j){}
	bool operator>= (const date& d)
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
	bool operator<= (const date& d)
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
	bool operator== (const date& d)
	{
		if(month == d.month && day == d.day && jie == d.jie)
			return true;
		else
			return false;
	}
};
template <typename T>
class node
{
public:
	T data;
	node* next;
	friend ostream& operator << (ostream& ,const node<date>& );
};
ostream& operator << (ostream& out ,const node<date>& n)
{
	out << n.data.month << "月" << n.data.day << "日第" << n.data.jie << "节的" << n.data.ke << "课";
	switch(n.data.level)
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
template <typename T>
class dateLink
{
public:
	node<T>* head;
	dateLink() : head(NULL){}
	void insertHead(T a)
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void remove(T d)
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
	node<T>* find(T d)
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
	void travalList()
	{
		if(head)
		{
			for(node<T>* i = head;i != NULL;i = i->next)
			{
				cout << *i << endl;
			}
		}
		else
			cout << "这位同学没有缺过课"; 
			cout << endl;
	}
	void deleteList()
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
class student
{
public:
	string n;
	dateLink<date> que;
	student() : n("NULL"){}
	student(const string& _n) : n(_n){}
	void getdate(date d)
	{
		que.insertHead(d);
	}
	void chaxunall()
	{
		que.travalList();
	}
	void deletedateall()
	{
		que.deleteList();
	}
	void deletedate(date d)
	{
		que.remove(d);
	}
	int ci(date a,date b)
	{
		int s = 0;
		for(node<date>* i = que.head;i != NULL;i = i->next)
		{
			if(i->data >= a && i->data <= b && i->data.level == 4)
				s++;
		}
		return s;
	}
	bool operator==(const student& x)
	{
		if(n == x.n)
			return true;
		else
			return false;
	}
};
class ke
{
public:
	string n;
	dateLink<date> da;
	ke() : n("NULL"){}
	ke(const string& _n) : n(_n){}
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
	int n,st = 0,kc = 0;
	dateLink<student> stu;
	dateLink<ke> k;
	while(1)
	{
		cout << "_________________________________________________________________________________" << endl;
		cout << "****************请问您想要做什么？****************\n（1）录入学生的缺课记录（按1）\n（2）修改某个学生的缺课记录（按2）\n（3）查询某个学生的缺课记录（按3）\n（4）删除某个学生的缺课记录（按4）\n（5）统计某段时间内，某门课旷课学生姓名及旷课次数，按旷课次数由少到多排序（按5）\n（6）统计某短时间内，有学生旷课的课程及旷课次数，按旷课人次由少到多排序（按6）\n（7）退出程序（按7）\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "使用功能：";
		cin >> n;
		if(n == 7)
		{
			cout << "感谢您的使用，欢迎再次使用" <<  endl;
			break;
		}
		switch(n)
		{
			case 1 : 
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
				q = k.find(ke(kec));
				if(!q)
				{
					ke p(kec);
					kc++;
					k.insertHead(p);
					q = k.find(p);
				}
				cout << "请输入缺课类型   迟到（1）早退（2）请假（3）旷课（4）" << endl;
				int o;
				cin >> o;
				date D(n,y,o,kec,j);
				q->data.da.insertHead(D);
				node<student> *w;
				w = stu.find(student(name));
				if(!w)
				{
					student p(name);
					stu.insertHead(p);
					st++;
					w = stu.find(p);
				}
				w->data.que.insertHead(D);
				cout << "记录成功！" << endl;
				break;

			}
			case 2:
			{
				string name;
				cout << "请输入你想要修改的同学的名字" << endl;
				cin >> name;
				node<student> *p;
				p = stu.find(student(name));
				if(!p)
				{
					cout << "这位同学没有缺过课" << endl;
					break;
				}
				cout << "请输入您需要修改的日期和第几节课（例如1月1日第2节课输入 1 1 2）" << endl;
				int m,d,j;
				cin >> m >> d >> j;
				date D(m,d,j);
				node<date> *q;
				q = p->data.que.find(D);
				if(!q)
				{
					cout << "这个时间这位同学没有缺课" << endl;
					break;
				}
				cout << "请问你是（1）准备改时间（2）修改课程（3）修改缺课改类型" << endl;
				int n;
				cin >> n;
				switch(n)
				{
					case 1 :
					{
						cout << "输入你要修改的时间" << endl;
						node<ke> *w;
						w = k.find(ke((p->data.que.find(D))->data.ke));
						int _m,_d,_j;
						cin >> _m >> _d >> _j;
						q->data.month = _m;
						q->data.day = _d;
						q->data.jie = _j;
						node<date> *r;
						r = w->data.da.find(D);
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
						w = k.find(ke((p->data.que.find(D))->data.ke));
						w->data.da.remove(D);
						q->data.ke = kk;
						D = q->data;
						w = k.find(ke(kk));
						if(w)
							w->data.da.insertHead(D);
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
						w = k.find(ke((p->data.que.find(D))->data.ke));
						int l;
						cin >> l;
						q->data.level = l;
						node<date> *r;
						r = w->data.da.find(D);
						r->data.level = l;
						break;
					}
					default :
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
				p = stu.find(student(n));
				if(!p)
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
				cin >> f;
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
						p->data.deletedate(D);
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
				QWQ f[st];
				node<student>* ji = stu.head;
				for(int i = 0;i < st;i++)
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + st,cmp);
				for(int i = 0;i < st;i++)
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
				QWQ f[kc];
				node<ke>* ji = k.head;
				for(int i = 0;i < st;i++)
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + st,cmp);
				for(int i = 0;i < st;i++)
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