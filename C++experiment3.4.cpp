#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person{
protected:
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

    void printProperty() const {

        cout << "Name:" << name << "\n";

        cout << "Gender:" << gender << "\n";

        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);

    }

};
class National_Person : virtual public Person{
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
	void printProperty()
	{
		National_Person::printProperty();
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
	void printProperty(){
		Chinese::printProperty();
		Student::printProperty();
	}
};
int main() {

    Chinese_Student chnStuDmm("丁濛", 'M', 1982, 5, 3, "ZJU", "3001112322", 2000);

    cout << "Before:\n";

    chnStuDmm.printProperty();

    chnStuDmm.setName("Gavotte");

    cout << "\nAfter:\n";

    chnStuDmm.printProperty();

    return 0;

}