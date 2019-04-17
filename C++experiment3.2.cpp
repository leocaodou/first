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

        cout << "\n\n";
        cout << "Name:" << name << "\n";

        cout << "Gender:" << gender << "\n";

        printf("Birthday:%d-%.2d-%.2d\n", year, month, day);

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
        cout << "\n\n";
        Person::printProperty();
        cout << "Nationality:" << Nationality << '\n';
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
        cout << "\n\n";
        Person::printProperty();
        cout << "SchoolName:" << schoolName << '\n';
        cout << "StudentID:" << studentID << '\n';
        cout << "Grade:" << grade << '\n';
    }
};


int main(){

    National_Person chnDmm ("丁濛", "CHN", 'M', 1982, 5, 3);

    cout << "chnDmm:\n";

    chnDmm.printProperty();

    chnDmm.setNationality("USA");

    chnDmm.setName("Dmm");

    chnDmm.printProperty();



    Student stuDmm("丁濛", 'M', 1982, 5, 3, "ZJU", "3001112322", 2000);

    cout << "stuDmm:\n";

    stuDmm.printProperty();

    stuDmm.setSchoolName("THU");

    stuDmm.setStudentID("2005016579");

    stuDmm.printProperty();



    Person dmm(stuDmm);

    dmm.setName("Gavotte");

    cout << "dmm:\n";

    dmm.printProperty(); 

    cout << "stuDmm:\n";

    stuDmm.printProperty();
    return 0;
}