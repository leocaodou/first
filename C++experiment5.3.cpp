#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ofstream f("info.txt");//�������ʽ��test.txt�ļ����Ӽ���������ļ�
	cout << "������������";
	string a;
	cin >> a;
	f << "������"<< a << '\n';//������ļ������ݣ���ͬ
	cout << "���������䣺";
	cin >> a;
	f << "���䣺"<< a << '\n';
	cout << "������ѧ�ţ�";
	cin >> a;
	f << "ѧ�ţ�"<< a << '\n';
	cout << "����������أ�";
	cin >> a;
	f << "�����أ�"<< a << '\n';
	cout << "���������أ�";
	cin >> a;
	f << "���أ�"<< a << '\n';
	cout << "��������ߣ�";
	cin >> a;
	f << "��ߣ�"<< a << '\n';
	f.close();
	return 0;
}