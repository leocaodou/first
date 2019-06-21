#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
class person//�����person�࣬ÿһλԱ��������Щ����
{
protected:
	string name;//����
	int year;//����
	double gonglinggongzi;//���乤��
	int id;//Ա������
public:
	virtual double getincome() = 0;//��������Ĵ��麯��
	virtual void print() = 0;//�����ǰ��Ϣ�Ĵ��麯��
	virtual double getxiao()//�������۶�ĺ��������ڲ��������˶���������������Բ����Ǵ��麯��
	{
		return 0;
	}
	person() : year(0),gonglinggongzi(0),name("NULL"),id(0){}
	person(const string& n,int y,int g,int d) :name(n), year(2019 - y + 1),gonglinggongzi(g), id(d){}
	void setname(const string& n)//�޸����ֵĺ�������������
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
class xiaoshigong//Сʱ���࣬�������������ص㣬���Ƕ��������
{
protected:
	double he;//ÿСʱ����
	int time;//�¹���ʱ��
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
class gongren : public person,public xiaoshigong//������
{
public:
	gongren() : person("NULL",0,50,0),xiaoshigong(80,0){}
	gongren(const string& n,int y,double g,int d,double h,int t) : person(n,y,g,d),xiaoshigong(h,t){}
	double getincome()//���㹤�˹���
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)
			s = s * 1.2;
		return he * time + s;
	}
	void print()//���������Ϣ
	{
		cout << "�������֣� " << name << endl;
		cout << "���˹��ţ�" << id << endl;
		printf("��нΪ��%lf\n\n",getincome());
	}
};
class saleman : public person,public xiaoshigong//����Ա����
{
private:
	double xiaoshoue;//���۶�
public:
	saleman() : person("NULL",0,50,0),xiaoshigong(80,0),xiaoshoue(0){}
	saleman(const string& n, int y,double g,int d,double h,int t,double x): person(n,y,g,d),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()//��������Ա������н
	{
		return he * time + year * gonglinggongzi + xiaoshoue * 0.01;
	}
	void setxiaoshoue(double x)
	{
		xiaoshoue = x;
	}
	void print()//��������Ա����Ϣ���
	{
		cout << "����Ա������" << name << endl;
		cout << "����Ա���ţ�" << id << endl;
		printf("��нΪ��%lf\n\n",getincome());
	}
	double getxiao()//�������۶�
	{
		return xiaoshoue;
	}
};
class guanli : public person//������Ա��
{
private:
	double jiben;//��������
public:
	guanli() : person("NULL",0,50,0),jiben(0) {}
	guanli(const string& n,int y, double g, int d,double j ) : person(n,y,g,d),jiben(j) {}
	double getincome()//���������Ա����
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()//���������Ա��Ϣ
	{
		cout << "������Ա�������ǣ�" << name <<endl;
		cout << "������Ա�Ĺ����ǣ�" << id << endl;
		printf("��нΪ��%lf\n\n",getincome());
	}
	void setjiben(double s)
	{
		jiben = s;
	}
};
class SalesManager : public person//���۾�����
{
protected:
	double jiben;//��������
	double total;//�����ܶ�
public:
	SalesManager() : person("NULL",0,50,0),jiben(0) {}
	SalesManager(const string& n,int y, double g, int d,double j = 5000) : person(n,y,g,d),jiben(j) {}
	double getincome()//�������۾�����н
	{
		return jiben + total * 0.06 + year * gonglinggongzi;
	}
	void print()//������۾������Ϣ
	{
		cout << "���۾���������ǣ�" << name <<endl;
		cout << "���۾���Ĺ����ǣ�" << id << endl;
		printf("��нΪ��%lf\n\n",getincome());
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
//�������������ÿ��Ա��
class node
{
public:
	person *per;//ÿ�������Ԫ���ﶼ��һ������ָ����������
	node* next;
};
class LinkedList//��������
{
public:
	node* head;
	LinkedList() : head(NULL){}
	void insertHead(person *a)//ͷ����Ա����Ϣ
	{
		node* p;
		p = new node;//���ٳ�һ���¿ռ����ڴ�Ų���Ա��
		p->per = a;
		p->next = head;
		head = p;
	}
	void travalList()//�������
	{
		if(head)
		{
			for(node* i = head;i != NULL;i = i->next)
			{
				i->per->print();
			}
		}
		else
			cout << "����һ��������"; 
			cout << endl;
	}
	void deleteList()//��������ͷſռ�
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
	bool isEmpty()//�ж������Ƿ�Ϊ��
	{
		if(head == NULL)
			return true;
		else
			return false;
	}
};
double gettotalxse(LinkedList saleman)//���������ܶ���ڼ������۾�����
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
	LinkedList salemanList;//�������Ա������
	LinkedList yuangong;//�������Ա��������
	while(1)//ѭ����¼ÿһ��Ա����Ϣ
	{
		i++;
		string n;
		char a;
		cout << "������Ա�����֣�����Ҫ�������-1��" << endl;
		cin >> n;
		if(n == "-1")
			break;
		cout << "Ա�������ͣ����ˣ�G������Ա��X��������Ա��L�����۾���J��������������۾���" << endl;//�������������۾�����Ϊ����ʱ�������ܶ�ᷢ���ı�
		cin >> a;
		switch(a)
		{
			case 'G':
			{
				int y,t;
				double g = 50,h = 80;
				char c;
				cout << "��ְ��ݣ�";
				cin >> y;
				cout << "�Ƿ���Ҫ�����һ�깤�乤�ʣ�Ĭ��50Ԫ��Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "�Ƿ���Ҫ����ʱн��Ĭ��80Ԫ/Сʱ��Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> h;
				cout << "���빤��ʱ����";
				cin >> t;
				gongren *x;
				x = new gongren(n,y,g,i,h,t);//����ָ��ȥָ��һ���ſ����Ĺ��˿ռ䣬����������˵���Ϣ������Ϊ��һ��ѭ����������������ͬ��
				yuangong.insertHead(x);//���½��Ĺ�����Ϣ��������
				break;
			}
			case 'X':
			{
				int y,t;
				double g = 50,h = 80,X;
				char c;
				cout << "��ְ��ݣ�";
				cin >> y;
				cout << "�Ƿ���Ҫ�����һ�깤�乤�ʣ�Ĭ��50Ԫ/�£�Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "�Ƿ���Ҫ����ʱн��Ĭ��80Ԫ/Сʱ��Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> h;
				cout << "���빤��ʱ����";
				cin >> t;
				cout << "�������۶";
				cin >> X;
				saleman *x;
				x = new saleman(n,y,g,i,h,t,X);
				yuangong.insertHead(x);
				salemanList.insertHead(x);//������Ա����Ҫ�������������Ա������
				break;
			}
			case 'L' :
			{
				int y;
				double g = 50,j;
				char c;
				cout << "��ְ��ݣ�";
				cin >> y;
				cout << "�Ƿ���Ҫ�����һ�깤�乤�ʣ�Ĭ��50Ԫ/�£�Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "����������ʣ�";
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
				cout << "��ְ��ݣ�";
				cin >> y;
				cout << "�Ƿ���Ҫ�����һ�깤�乤�ʣ�Ĭ��50Ԫ/�£�Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> g;
				cout << "�Ƿ���Ҫ����̶����ʣ�Ĭ��5000Ԫ/�£�Y/N   ";
				cin >> c;
				getchar();
				if(c == 'Y')
					cin >> j;
				SalesManager *x;
				x = new SalesManager(n,y,g,i,j);
				x->settotal(gettotalxse(salemanList));//���۾��������Ҫ���������ܶ��趨��
				yuangong.insertHead(x);
				break;
			}
		}
	}
	yuangong.travalList();//��������Ա��������
	salemanList.deleteList();
	yuangong.deleteList();//ɾ������
	return 0;
}