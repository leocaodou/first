#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ofstream f("info.txt");//以输出方式打开test.txt文件，从键盘输出到文件
	cout << "请输入姓名：";
	string a;
	cin >> a;
	f << "姓名："<< a << '\n';//输出到文件的内容，下同
	cout << "请输入年龄：";
	cin >> a;
	f << "年龄："<< a << '\n';
	cout << "请输入学号：";
	cin >> a;
	f << "学号："<< a << '\n';
	cout << "请输入出生地：";
	cin >> a;
	f << "出生地："<< a << '\n';
	cout << "请输入体重：";
	cin >> a;
	f << "体重："<< a << '\n';
	cout << "请输入身高：";
	cin >> a;
	f << "身高："<< a << '\n';
	f.close();
	return 0;
}