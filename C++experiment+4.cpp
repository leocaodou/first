#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f1("old.txt");
	ofstream f2("new.txt");
	if (!f1)
    {
        cout << "不能打开文件:old.txt\n";
        exit(0);
    }
    if (!f2)
    {
        cout << "不能打开文件:new.txt\n";
        exit(0);
    }
	while(!f1.eof())
	{
		char a,b;
		f1 >> a;
		if(!f1)
			break;
		cout << a;
		if(a >= 'a' && a <= 'z')
		{
			b = a - 32;
			f2 << b;
		}
		if(a >= 'A' && a <= 'Z')
		{
			b = a + 32;
			f2 << b;
		}
	}
	return 0;
}