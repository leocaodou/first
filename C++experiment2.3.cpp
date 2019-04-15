#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
class String{
private:
    char *str;
    unsigned int l;
public:
    String() : str(NULL), l(0){
    }
    String(const char *s)
    {
        if(s)
        {
            l = strlen(s);
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else
        {
            str = NULL;
            l = 0;
        }
        
    }
    String(const String& other) : l(other.l)
    {
        if(other.str)
        {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        else
            str = NULL;
    }
    ~String()
    {
        delete [] str;
        l = 0;
    }
    unsigned int size() const
    {
        unsigned int i;
        if(str)
        {
            for(i = 0;;i++)
            {
                if(str[i] =='\0')
                    break;
            }
            return i;
        }
        return 0;
    }
    String& append(const String& other)
    {
        char *x;
        l = other.l + l;
        if(other.str)
        {
            x = new char[l + other.l + 1];
            if(str)
            {
                strcpy(x, str);
                strcat(x,other.str);
                delete [] str;
            }
            else
                strcpy(x, other.str);
            str = x;
            return *this;
        }
        else
            return *this;
    }
    String& operator= (const String& other)
    {
        l = other.l;
        if(this == &other)
            return *this;
        if(str)
        {
            delete [] str;
        }
        if(other.str)
        {
            str = new char[other.l + 1];
            strcpy(str, other.str);
        }
        else
            str = NULL;
    }
    String& operator+= (const String& other)
    {
        return this->append(other);
    }
    String operator+ (const String& other) const
    {
        String A(*this);
        A += other;
        return A;
    }
    char& operator[] (const int i) const
    {
        assert(i >= 0 && i < l);
            return str[i];
    }
    bool isNull()const{
        if(str)
            return true;
        else
            return false;
    }
    String& operator<< ( const String& other){
        return this->append(other);
    }
    friend ostream& operator<< ( ostream& output, const String& other);
};
ostream& operator<< ( ostream& output, const String& other){
    if(other.str)
        cout << other.str;
    else
        return output;
    }
int main(){
    String a("This is "), b(a);
    String c;
    cout << "a:" << a << "\n" << "b:" << b << "\n" << "c:" << c << "\n";
    c = "a test.";

    cout << "c:" << c << "\n";

    a.append(c);

    cout << "a:" << a << "\n";

    {

        String a("Hello"), b;

        a += " World";

        b  << (a + b);

        cout << "b:" << b << "\n";

        String c;

        c = b + "!";

        cout << "c:" << c << "\n";

    }

    a[0] = 't';
    cout << "a:" << a << "\n";
    return 0;
}