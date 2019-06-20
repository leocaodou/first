#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;
class a
{
public:
    int a;
virtual void foo() = 0;
};
class b
{
public:
    int b;
};
class c : public a,public b
{
public:
    int c;
    void foo()
    {
        cout << "ccc";
    }
};
int main()
{   
    int i =1;
    a *p,*q;
    while(i)
    {
        c x;
        p = &x;
        q = p;
        i--;
    }
    q->foo();
    return 0;
}