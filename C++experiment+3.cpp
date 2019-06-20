#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int c[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//用于存储非闰年的每个月的天数
int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//用于存储闰年的每个月的天数
int getPower(int x,int y)//计算整型的次方
{
	int s = 1;
	for(int i = 1;i <= y ;i++)//循环y次，求x的y次方
	{
		s = s * x;
	}
	return s;
}
double getPower(double x,int y)//重载getPower()函数，用于求浮点型的次方
{
	double s = 1;
	for(int i = 1;i <= y ;i++)
	{
		s = s * x;
	}
	return s;
}
class Date//日期类
{
private:
	int y;//年
	int m;//月
	int d;//日
public:
	Date(int n,int _y,int r) : y(n),m(_y),d(r){}
	Date(const Date& other) : y(other.y),m(other.m),d(other.d){}
	Date operator+ (int x)//操作符+的重载，用于一个日期加上多少天后
	{
		Date a = *this;
		while(x)//直到需要加的天数为0跳出循环
		{
			if(((y % 4 == 0)&&(y % 100 != 0))||(y % 400 == 0))//先判断当前是不是闰年
			{
				if(b[a.m - 1] - a.d + 1 <= x)//若所要加的天数超过了当前距离距离下一个月的话
				{
					x = x - (b[a.m - 1] - a.d + 1);//x减去到下一个月的需要的天数
					a.d = 1;//由于到了下一个月，日期变为1
					a.m++;//月数加一
					if(a.m > 12)//如果月数加一后，大于12
					{
						a.y++;//年数加一
						a.m = 1;//月数变为1
					}
				}
				else//若所要加的天数到不了下一个月的话
				{					
					a.d = a.d + x;//直接全部加到日期上
					x = 0;//x归0
				}
			}
			else//若不是闰年，操作基本和闰年相似，只是数组换为a[12]
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
	Date& operator= (const Date& other)//重载运算符=
	{
		y = other.y;
		m = other.m;
		d = other.d;
		return *this;
	}
	friend ostream& operator << (ostream& ,const Date&);//友元函数，为了更好的输出日期
};
ostream& operator << (ostream& out ,const Date& n)
{
	out << n.y << "年" << n.m << "月" << n.d << "日" << endl;
	return out;
}
int main()
{
	int a, n;
	double b;
	cout << "请输入一个整数和一个小数" << endl;
	cin >> a >> b;
	cout << "你想要它们的多少次方" << endl;
	cin >> n;
	cout << "a的n次方为" << getPower(a,n) << endl;
	cout << "b的n次方为" << getPower(b,n) << endl;
	int ni,y,r,x;
	cout << "请输入年月日" << endl;
	cin >> ni >> y >> r;
	cout <<"你想知道多少天后的日期" << endl;
	cin >> x;
	Date t(ni,y,r);
	t = t + x;
	cout << t;
	return 0;
}