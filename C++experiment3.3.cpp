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
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
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
class Student : public Person{
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
class Chinese_Student : public Student,public Chinese{
private:
public:
	Chinese_Student() {
		cout << "Chinese_Student()\n";
	}
	Chinese_Student(const string& name, char g,int y,int m,int d,const string& sname,const string& sID,int _grade) :
	Student( name, g, y, m, d, sname, sID, _grade),Chinese(name, g, y, m, d){
		cout << "Chinese_Student(const string&, char, int, int, int, const string&, const string&, int)\n";
	}
	~Chinese_Student()
	{
		cout << "~Chinese_Student()\n";
	}
	void printProperty(){
		Chinese::printProperty();
		Student::printProperty();
	}
};
int main() {

    Chinese_Student chnStuDmm("丁濛", 'M', 1982, 5, 3, "ZJU", "3001112322", 2000);

    chnStuDmm.printProperty();

    return 0;

}