#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f1("old.txt");//先以流出的形式打开一个事先写好有内容的txt
	ofstream f2("new.txt");//再以流入的形式打开一个空的txt
	if (!f1)//先判断两文件能否打开
    {
        cout << "不能打开文件:old.txt\n";
        exit(0);
    }
    if (!f2)
    {
        cout << "不能打开文件:new.txt\n";
        exit(0);
    }
	while(!f1.eof())//文件到头的话就结束循环
	{
		char a,b;
		f1 >> a;//一次次把数据从f1中流向a
		if(!f1)
			break;
		cout << a;//输出a
		if(a >= 'a' && a <= 'z')//如果a是小写字母
		{
			b = a - 32;//b就是a的大写
			f2 << b;//把b放入a当中
		}
		if(a >= 'A' && a <= 'Z')//如果a是大写字母
		{
			b = a + 32;//b就是a的小写
			f2 << b;//把b放入a当中
		}
	}
	f1.close();//关闭文件，释放内存
	f2.close();
	return 0;
}