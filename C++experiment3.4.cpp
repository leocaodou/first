#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person{
protected://类成员必须得设置为保护型以便之后输出
    string name;
    char gender;
    int year;
    int month;
    int day;
    bool legalBirthday(const int y, const int m, const int d) const {
        if(y< 0 || m < 0 || m > 12 || d < 0 || d > 31)
            return false;
        int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(m == 2) {
            if( y% 4 != 0 || (y% 100 == 0 && y% 400 != 0)) {
                if( d <= 28)
                    return true;
                else
                    return false;
            }
            else {
                if( d <= 29)
                    return true;
                else
                    return false;
            }
        }
        if(d <= a[m - 1])
            return true;
        else
            return false;
    }
public:
    Person() : name(), gender('U'), year(1900), month(1), day(1){
        printf("Person()\n");
    }
    Person(const string& n, char g, int y, int m, int d) : name(n), gender(g) {

        printf("Person(const string&, char, int, int, int)\n");

        if(legalBirthday(y, m, d)){
            year = y, month = m, day = d;
        }
    }
    Person(const Person& other) : name(other.name), gender(other.gender), year(other.year), month(other.month), day(other.day){
        printf("Person(const Person&)\n");
    }
    Person(const string& n)
    {
        name = n;
    }
    ~Person(){

        printf("~Person()\n");

    }
    void setGender(char g) { gender = g;}
    void setBirthday(int y, int m, int d) {

        if(legalBirthday(y, m, d)){
            year = y, month = m, day = d;
        }
    }
    void setName(const char *str){
        name = str;
    }
    virtual void printProperty() const {//设置为虚函数，因为在其派生类当中有同名作用类似的函数，这样会方便基类指针指向使调用的方便
        cout << "Person::printProperty()\n";//表明是Person类的输出
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
    }
};
class National_Person : virtual public Person{
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
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
    }
    void printProperty ()const
    {
        cout << "National_Person::printProperty()\n";//表明是National_Person类的输出
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
        cout << "Nationality:" << Nationality << '\n';
    }
};
class Chinese :  public National_Person{
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
	void printProperty ()const
	{
        cout << "Chinese::printProperty()\n";//表明是Chinese类的输出
		cout << "National_Person::printProperty()\n";
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
        cout << "Nationality:" << Nationality << '\n';
	}
};
class Student : virtual public Person{
protected:
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
    void printProperty ()const
    {
        cout << "Student::printProperty()\n";//表明是Student类的输出
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
        cout << "School Name:" << schoolName << '\n';
        cout << "Student ID:" << studentID << '\n';
        cout << "Grade:" << grade << '\n';
    }
};
class Chinese_Student :  public Student,public Chinese{
private:
public:
	Chinese_Student() {
		cout << "Chinese_Student()\n";
	}
	Chinese_Student(const string& name, char g,int y,int m,int d,const string& sname,const string& sID,int _grade) :
	Student( name, g, y, m, d, sname, sID, _grade),Chinese(name, g, y, m, d), Person( name,g, y, m, d){
		cout << "Chinese_Student(const string&, char, int, int, int, const string&, const string&, int)\n";
	}
	~Chinese_Student()
	{
		cout << "~Chinese_Student()\n";
	}
	void printProperty() const{
        cout << "Chinese_Student::printProperty()\n";//表明是Chinese_Student类的输出
        cout << "Nationality:" << Nationality << '\n';
        cout << "Name:" << name << "\n";
        cout << "Gender:" << gender << "\n";
        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);
        cout << "School Name:" << schoolName << '\n';
        cout << "Student ID:" << studentID << '\n';
        cout << "Grade:" << grade << '\n';
	}
};
int main() {
    Person *p;//基类指针
    Chinese chnlkh("LEO", 'M', 1999, 10, 6);
    p = &chnlkh;
    p->printProperty();
    cout << '\n';
    National_Person nalkh("LEO", "CHN", 'M', 1999, 10, 6);
    p = &nalkh;
    p->printProperty();
    cout << '\n';
    Student stulkh("LEO", 'M', 1999, 10, 6, "BISTU", "2018011252", 100);
    p = &stulkh;
    p->printProperty();
    cout << '\n';
    Person lkh("LEO", 'M', 1999, 10, 6);
    p = &lkh;
    p->printProperty();
    cout << '\n';
    Chinese_Student cstulkh("LEO", 'M', 1999, 10, 6, "BISTU", "2018011252", 100);
    p = &cstulkh;
    p->printProperty();
    return 0;
}