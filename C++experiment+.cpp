#include<iostream>
#include<fstream>
#include<string>
using namespace std;
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
				if(jie < d.jie)
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
	out << n.data.month << "��" << n.data.day << "�յ�" << n.data.jie << "��ȱ��" << n.data.ke << "��";
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
			cout << "����һ��������"; 
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
	void xiugan(date d)
	{
		node<date> *p;
		p = que.find(d);
		cout << "��������Ҫ�޸�ʱ�仹��";
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
		cout << "��������Ҫ��ʲô��\n��1��¼��ѧ����ȱ�μ�¼����1��\n��2���޸�ĳ��ѧ����ȱ�μ�¼����2��\n��3����ѯĳ��ѧ����ȱ�μ�¼����3��\n��4��ɾ��ĳ��ѧ����ȱ�μ�¼����4��\n��5��ͳ��ĳ��ʱ���ڣ�ĳ�ſο���ѧ�����������δ����������δ������ٵ������򣨰�5��\n��6��ͳ��ĳ��ʱ���ڣ���ѧ�����εĿγ̼����δ������������˴����ٵ������򣨰�6��\n��7���˳����򣨰�7��\n";
		cin >> n;
		if(n == 7)
			break;
		switch(n)
		{
			case 1 : 
			{
				string name,kec;
				cout << "������ѧ��������" << endl;
				cin >> name;
				cout << "������γ����ڣ��Լ��ڼ��ڿ�" << endl;
				int n,y,j;
				cin >> n >> y >>j;
				cout << "������γ�����" << endl;
				cin >> kec;
				node<ke> *q;
				q = k.find(ke(kec));
				if(!q)
				{
					ke p(kec);
					st++;
					k.insertHead(p);
					q = k.find(p);
				}
				cout << "������ȱ������   �ٵ���1�����ˣ�2����٣�3�����Σ�4��" << endl;
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
					kc++;
					w = stu.find(p);
				}
				w->data.que.insertHead(D);

			}
			case 2:
			{
				string name;
				cout << "����������Ҫ�޸ĵ�ͬѧ������" << endl;
				cin >> name;
				node<student> *p;
				p = stu.find(student(name));
				cout << "����������Ҫ�޸ĵ����ں͵ڼ��ڿ�" << endl;
				int m,d,j;
				cin >> m >> d >> j;
				date D(m,d,j);
				node<date> *q;
				q = p->data.que.find(D);
				cout << "��������׼����ʱ�䣨1���ǸĿγ̣�2������ȱ�θ����ͣ�3��" << endl;
				int n;
				cin >> n;
				switch(n)
				{
					case 1 :
					{
						cout << "������Ҫ�޸ĵ�ʱ��" << endl;
						//q->data.
					}
				}
			}
		}
	}
}
