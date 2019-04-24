#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person{//Person基类,包含名字，性别，生日年月日
protected://以下成员为保护修饰，作用是可以被其派生类直接使用
	string name;
	char gender;
	int year;
	int month;
	int day;
public:
	Person() : name() ,gender('\0') ,year(1900),month(1),day(1){}
	Person(const string& n,const char a,const int y,const int m,const int d) :name(n) ,gender(a) ,year(y),month(m),day(d)
	{
		printf("Person(const string&, char, int, int, int)\n");
	}
	Person(const Person& other):name(other.name) ,gender(other.gender) ,year(other.year),month(other.month),day(other.day)
	{
		printf("Person(const Person&)\n");
	}
	~Person()
	{
		printf("~Person()\n");
	}
	virtual void printProperty()//虚函数，因为在基类与派生类都含有这个同名函数，方便以后用指针指向时，可以使用相应类的函数
	{
		cout << "Name:" << name << '\n';
		printf("Gender:%c\n",gender);
		printf("Birthday:%d-%02d-%02d\n",year,month,day);
	}
};
class National_Person : public Person{//继承Person类的派生类
private:
	string nat;
public:
	National_Person():nat(){}
	National_Person(const string& n, const string& na, char g, int y, int m, int d) : Person( n, g, y, m, d),nat(na)
	{
		cout << "National_Person(const string&, const string&, char, int, int, int)\n";
	}
	National_Person(const string& na) : nat(na){}
	~National_Person()
	{
		printf("~National_Person()\n");
	}
	void printNationality()//输出国籍的函数
	{
		cout << "Nationality:" << nat << '\n' ;
	}
	void printProperty()//输出此人所有信息
	{
		Person::printProperty();
		cout << "Nationality:" << nat << '\n' ;
	}
};
int main(){

    National_Person lkh("LEO","CHN",'M', 1999, 10, 6);
    lkh.printNationality();
    cout << '\n';
    lkh.printProperty();

    return 0 ;

}