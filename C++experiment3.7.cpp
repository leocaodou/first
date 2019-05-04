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
		cout << "Person::printProperty()\n";
		cout << "Name:" << name << '\n';
		printf("Gender:%c\n",gender);
		printf("Birthday:%d-%02d-%02d\n",year,month,day);
	}
};
class National_Person : public Person{
private:
    string Nationality;
public:
    National_Person() : Nationality() {
        cout << "National_Person()\n";
    }
    National_Person(const string& n, const string& na, char g, int y, int m, int d) : Person( n, g, y, m, d),Nationality(na)
    {
        cout << "National_Person(const string&, const string&, char, int, int, int)\n";
    }
    National_Person(const string& na) : Nationality(na){}
    ~National_Person()
    {
        printf("~National_Person()\n");
    }
    void setNationality(const string& nat)
    {
        Nationality = nat;
    }
    void printNationality()
    {
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
    }
    void printProperty()
    {
    	cout << "National_Person::printProperty()\n";
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
    }
};
class Chinese : public National_Person{//创建Chinese类，派生与National_Person
public://无新增加的私有成员
public:
	Chinese() : National_Person("CHN"){}//无参构造Chinese时，把国籍改为“CHN”
	Chinese(const string& n, char g, int y, int m, int d) :National_Person(n,"CHN",g,y,m,d){//有参构造时把，用传入的参数与国籍“CHN”来构造National_Person
		printf("Chinese(const string&, char, int, int, int)\n");
	}
	~Chinese()
	{
		cout << "~Chinese()\n";
	}
	void printProperty()
	{
		cout << "Chinese::printProperty()\n";
		National_Person::printProperty();
	}
};
int main() {
    Chinese chnlkh("LEO", 'M', 1999, 10, 6);
    chnlkh.printProperty();
    return 0;
}