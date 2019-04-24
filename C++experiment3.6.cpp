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
class Student : virtual public Person{
private:
    string schoolName;
    string studentID;
    int grade;
public:
    Student() : schoolName(),studentID(),grade(0){
        cout << "Student()\n";
    }
    Student(const string& name, char g,int y,int m,int d,const string& sname,const string& sID,int _grade) : 
    Person(name,g,y,m,d),schoolName(sname),studentID(sID),grade(_grade){
        cout << "Student(const string&, char, int, int, int, const string&, const string&, int)\n";
    }
    ~Student()
    {
        cout << "~Student()\n";
    }
    void setSchoolName(const string& N)
    {
         schoolName = N;
    }
    void setStudentID(const string& ID)
    {
        studentID = ID;
    }
    void setGrade(int a)
    {
        grade = a;
    }
    void printSchoolName()
    {
        cout << schoolName << '\n'; 
    }
    void printStudentID()
    {
        cout << studentID << '\n'; 
    }
    void printGrade()
    {
        cout << grade << '\n'; 
    }
    void printProperty()
    {
        Person::printProperty();
        cout << "School Name:" << schoolName << '\n';
        cout << "Student ID:" << studentID << '\n';
        cout << "Grade:" << grade << '\n';
    }
};
int main(){

    Student lkh("LEO",'M', 1999, 10, 6,"BISTU","2018011252",100);
    cout << '\n';
    lkh.printProperty();

    return 0 ;

}