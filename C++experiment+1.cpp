#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class person//��Ϊ�������࣬ӵ��ÿһλ���඼�еĳ�Ա����������Ӧ�Ĺ��乤��
{
protected:
	int year;
	double gonglinggongzi;
public:
	virtual double getincome() = 0;//���麯��������ÿ��������ļ��㹤��
	virtual void print() = 0;//���麯�����������ÿ�����������Ӧ����
	person() : year(0),gonglinggongzi(0){}
	person(int y,int g) : year(2019 - y + 1),gonglinggongzi(g){}//�вεĹ��캯������������Զ����������ְ���ת��Ϊ����
	void setyear(int n)//�����޸Ķ������ְ���
	{
		year = 2019 - n + 1;
	}
	void setgonglinggongzi(double g)//�����޸Ķ���Ĺ��乤��
	{
		gonglinggongzi = g;
	}
};
class xiaoshigong//����������Ա���̳е�Сʱ����
{
protected:
	double he;//ÿСʱ�Ĺ���
	int time;//ÿ�¹���ʱ��
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
private:
	int id;//�������г�Ա������
public:
	gongren() : person(0,50),xiaoshigong(80,0){}
	gongren(int d,int y,double h,int t,double g) : id(d),person(y,g),xiaoshigong(h,t){}
	double getincome()//���ڹ��˵Ĺ����㷨
	{
		double s = gonglinggongzi;
		for(int i = 2;i <= year;i++)//����ÿ������Ĺ��乤��
			s = s * 1.2;
		return he * time + s;
	}
	void setID(int i)
	{
		id = i;
	}
	void print()//���ڹ�����������Ϣ���
	{
		cout << "���˹��ţ�" << id << endl;
		cout << "�¹���ʱ����" << time << endl;
		cout << "�ܹ��ʣ�"<<endl;
		printf("%lf\n",getincome());
	}
};
class saleman : public person,public xiaoshigong//����Ա��
{
private:
	double xiaoshoue;//����Ա���еĳ�Ա�����۶�
public:
	saleman() : person(0,200),xiaoshigong(),xiaoshoue(0){}
	saleman(int y,double h,int t,double x,double g ): person(y,g),xiaoshigong(h,t),xiaoshoue(x){}
	double getincome()//��������Ա�ĵĹ����㷨
	{
		return he * time + year * gonglinggongzi + xiaoshoue * 0.01;
	}
	void setxiaoshoue(double x)
	{
		xiaoshoue = x;
	}
	void print()//��������Ա����Ϣ���
	{
		cout << "�¹���ʱ����" << time << endl;
		cout << "�ܹ��ʣ�"<<endl;
		printf("%lf\n",getincome());
	}
};
class guanli : public person//������Ա��
{
private:
	double jiben;//������Ա���еĳ�Ա����������
public:
	guanli() : person(0,50),jiben(0) {}
	guanli(int y, double j,double g ) : person(y,g),jiben(j) {}
	double getincome()//���ڹ�����Ա�Ĺ����㷨
	{
		return  year * gonglinggongzi + jiben;
	}
	void print()//���ڹ�����Ա����Ϣ���
	{
		cout << "�ܹ��ʣ�"<<endl;
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
	cout << "�й��˶��˸���" << endl; 
	cin >> j;//���빤�˵�����
	for(int i =1;i <= j;i++)//ѭ������ÿһ��������Ϣ����ͬ
	{	
		cout << "��" << i << "��������Ϣ" << endl;
		gongren a;
		int x;
		double y;
		cout << "���˹��ţ�";
		cin >> x;
		a.setID(x);
		cout << "�μӹ���ʱ�䣺";
		cin >> x;
		a.setyear(x);
		cout << "���˹��ʣ�";
		cin >> y;
		a.sethe(y);
		cout << "�¹���ʱ����";
		cin >> x;
		a.settime(x);
		cout << endl;
		a.print();
		cout << endl;
	}
	cout << "�����۶��˸���" << endl;
	cin >> k;
	for(int i =1;i <= k;i++)
	{
		cout << "��" << i << "������Ա��Ϣ" << endl;
		saleman a;
		int x;
		double y;
		cout << "�μӹ���ʱ�䣺";
		cin >> x;
		a.setyear(x);
		cout << "ÿСʱ���ʣ�";
		cin >> y;
		a.sethe(y);
		cout << "�¹���ʱ����";
		cin >> x;
		a.settime(x);
		cout << "���۶";
		cin >> y;
		a.setxiaoshoue(y);
		cout << endl;
		a.print();
		cout << endl;
	}
	cout << "�������˸���" << endl;
	cin >> l;
	for(int i =1;i <= l;i++)
	{
		cout << "��" << i << "��������Ա��Ϣ" << endl;
		guanli a;
		int x;
		double y;
		cout << "�μӹ���ʱ�䣺";
		cin >> x;
		a.setyear(x);
		cout << "�������ʣ�";
		cin >> y;
		a.setjiben(y);
		cout << endl;
		a.print();
		cout << endl;
	}
}