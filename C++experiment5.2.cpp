#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream f("test.txt");//以输入方式打开test.txt文件，从硬盘输入到内存
	string a;
	for(int i = 0; i < 11;i++)//由于test.txt文件中字符与字符是以空格间距，在f >> a 过程中是一个一个输入到内存，因此得来一个循环输出
	{
		f >> a;//把文件中的字符输入到内存中的a中
		cout << a << ' ';
	}
	f.close();//关闭文件
	return 0;
}