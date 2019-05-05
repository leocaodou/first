#include<iostream>
#include<stdio.h>
using namespace std;
class A {
private:
	int *a;
public:
	A() {
		cout << "A()\n";
		a = new int[10];
	}
	~A() {
		cout << "~A()\n";
		delete[] a;
	}
};
class B :public A {
private:
	int *b;
public:
	B() {
		cout << "B()\n";
		b = new int[10];
	}
	~B() {
		cout << "~B()\n";
		delete[] b;
	}
};
int main()
{
	A *a;
	a = new B;
	delete a;
	return 0;
}