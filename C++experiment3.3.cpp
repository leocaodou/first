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
	Person() : name() ,gender('\0') ,year(1900),month(1),day(1){
        cout << "Person()\n";
    }
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
    void setName(const string& n)//在基类中设置改名的函数
    {
        name = n;
    }
	virtual void printProperty()
	{
		cout << "Name:" << name << '\n';
		printf("Gender:%c\n",gender);
		printf("Birthday:%d-%02d-%02d\n",year,month,day);
	}
};
class National_Person : virtual public Person{//虚继承Person类，为了防止在构造Chinese_Student时构造出两个Person，无法达到修改名字的目的
protected:
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
        cout << "Nationality:" << Nationality << '\n';
    }
    void printProperty()
    {
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
    }
};
class Chinese : public National_Person{//又National_Person到Chinese_Student继承是单线的，所以不会出现重复构造的情况，所以这里不需要加virtual
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
class Student : virtual public Person{//虚继承，理由同National_Person
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
	Person(name,g,y,m,d),Student( name, g, y, m, d, sname, sID, _grade),Chinese(name, g, y, m, d){//由于基类的Person和National_Person为虚继承，不会构造出Person类，所以需要在这里再次构造
		cout << "Chinese_Student(const string&, char, int, int, int, const string&, const string&, int)\n";
	}
	~Chinese_Student()
	{
		cout << "~Chinese_Student()\n";
	}
	void printProperty(){
		Student::printProperty();
        cout << "Nationality:" << Nationality << '\n';
	}
};
int main() {

    Chinese_Student chnStulkh("LEO", 'M', 1999, 10, 6, "BISTU", "2018011252", 100);

    chnStulkh.printProperty();
    chnStulkh.setName("Leocaodou");//直接调用基类Person类中的setName函数
    cout << "\n\n\n";
    chnStulkh.printProperty();
    return 0;

}