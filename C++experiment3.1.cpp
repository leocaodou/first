#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person{
private:
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
	virtual void printProperty()
	{
		cout << "Name:" << name << '\n';
		printf("Gender:%c\n",gender);
		printf("Birthday:%d-%02d-%02d\n",year,month,day);
	}
};
class National_Person : public Person{
private:
	string nat;
public:
	National_Person():nat('\0'){}
	National_Person(const string& n, const string& na, char g, int y, int m, int d) : Person( n, g, y, m, d),nat(na)
	{
		cout << "National_Person(const string&, const string&, char, int, int, int)\n";
	}
	National_Person(const string& na) : nat(na){}
	~National_Person()
	{
		printf("~National_Person()\n");
	}
	void printProperty()
	{
		Person::printProperty();
		cout << "Nationality:" << nat << '\n' ;
	}
};
class Chinese : public National_Person{
public:

public:
	Chinese() : National_Person("CHN"){}
	Chinese(const string& n, char g, int y, int m, int d) :National_Person(n,"CHN",g,y,m,d){
		printf("Chinese(const string&, char, int, int, int)\n");
	}
	~Chinese()
	{
		cout << "~Chinese()\n";
	}
	void printProperty()
	{
		National_Person::printProperty();
	}
};
int main(){

    Chinese chnDmm("丁濛",'M', 1982, 5, 3);

    chnDmm.printProperty();

    return 0 ;

}