#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int c[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//���ڴ洢�������ÿ���µ�����
int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//���ڴ洢�����ÿ���µ�����
int getPower(int x,int y)//�������͵Ĵη�
{
	int s = 1;
	for(int i = 1;i <= y ;i++)//ѭ��y�Σ���x��y�η�
	{
		s = s * x;
	}
	return s;
}
double getPower(double x,int y)//����getPower()�����������󸡵��͵Ĵη�
{
	double s = 1;
	for(int i = 1;i <= y ;i++)
	{
		s = s * x;
	}
	return s;
}
class Date//������
{
private:
	int y;//��
	int m;//��
	int d;//��
public:
	Date(int n,int _y,int r) : y(n),m(_y),d(r){}
	Date(const Date& other) : y(other.y),m(other.m),d(other.d){}
	Date operator+ (int x)//������+�����أ�����һ�����ڼ��϶������
	{
		Date a = *this;
		while(x)//ֱ����Ҫ�ӵ�����Ϊ0����ѭ��
		{
			if(((y % 4 == 0)&&(y % 100 != 0))||(y % 400 == 0))//���жϵ�ǰ�ǲ�������
			{
				if(b[a.m - 1] - a.d + 1 <= x)//����Ҫ�ӵ����������˵�ǰ���������һ���µĻ�
				{
					x = x - (b[a.m - 1] - a.d + 1);//x��ȥ����һ���µ���Ҫ������
					a.d = 1;//���ڵ�����һ���£����ڱ�Ϊ1
					a.m++;//������һ
					if(a.m > 12)//���������һ�󣬴���12
					{
						a.y++;//������һ
						a.m = 1;//������Ϊ1
					}
				}
				else//����Ҫ�ӵ�������������һ���µĻ�
				{					
					a.d = a.d + x;//ֱ��ȫ���ӵ�������
					x = 0;//x��0
				}
			}
			else//���������꣬�����������������ƣ�ֻ�����黻Ϊa[12]
			{
				if(c[a.m - 1] - a.d + 1 <= x)
				{
					x = x - (c[a.m - 1] - a.d + 1);
					a.d = 1;
					a.m++;
					if(a.m > 12)
					{
						a.y++;
						a.m = 1;
					}
				}
				else
				{
					x = 0;
					a.d = a.d + x;
				}
			}
		}
		return a;
	}
	Date& operator= (const Date& other)//���������=
	{
		y = other.y;
		m = other.m;
		d = other.d;
		return *this;
	}
	friend ostream& operator << (ostream& ,const Date&);//��Ԫ������Ϊ�˸��õ��������
};
ostream& operator << (ostream& out ,const Date& n)
{
	out << n.y << "��" << n.m << "��" << n.d << "��" << endl;
	return out;
}
int main()
{
	int a, n;
	double b;
	cout << "������һ��������һ��С��" << endl;
	cin >> a >> b;
	cout << "����Ҫ���ǵĶ��ٴη�" << endl;
	cin >> n;
	cout << "a��n�η�Ϊ" << getPower(a,n) << endl;
	cout << "b��n�η�Ϊ" << getPower(b,n) << endl;
	int ni,y,r,x;
	cout << "������������" << endl;
	cin >> ni >> y >> r;
	cout <<"����֪��������������" << endl;
	cin >> x;
	Date t(ni,y,r);
	t = t + x;
	cout << t;
	return 0;
}