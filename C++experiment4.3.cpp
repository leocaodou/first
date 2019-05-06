#include<iostream>
#include<stdio.h>
using namespace std;
class A {
private:
	int *a;
public:
	A() {
		cout << "A()\n";//表明使用到了A类的构造函数，下B类同理
		a = new int[10];//在A类构造时开出10个int的空间
	}
	virtual ~A() {
		cout << "~A()\n";//表明使用到了A类的析构函数
		delete[] a;//在A析构时释放出A开出的空间
	}
};
class B :public A {
private:
	int *b;
public:
	B() {
		cout << "B()\n";
		b = new int[10];//在B类构造时开出10个int的空间
	}
	~B() {
		cout << "~B()\n";
		delete[] b;//释放在构造时开出的空间
	}
};
int main()
{
	A *a;
	a = new B;//使用基类指针开出派生类的空间
	delete a;//删去a开出的空间
	return 0;
}