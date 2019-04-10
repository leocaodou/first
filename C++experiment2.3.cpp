#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class String{
private:
    char *str;
    unsigned int l;
public:
    String() : str(NULL), l(0){

    }
    String(char *s)
    {
        l = strlen(s);
        if(s)
        {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else
            str = NULL;
        str[strlen(s)] = '\0';
    }
    String(const String& other)
    {
        l = other.l;
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
    const unsigned int size()
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
        unsigned int i;
        char *x;
        x = new char[this->size() + strlen(other.str) + 1];
        strcpy(x, str);
        for(i = 0;i < strlen(other.str);i++)
        {
            x[this->size() + i] = other.str[i];
        }
        x[this->size() + strlen(other.str)] = '\0';
        delete [] str;
        str = x;
        l = l + strlen(other.str);
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
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        else
            str = NULL;
    }
    String& operator+= (const char *s)
    {
        unsigned int i;
        char *x; 
        x = new char[this->size() + strlen(s) + 1];
        strcpy(x, str);
        for(i = 0;i < strlen(s);i++)
        {
            x[this->size() + i] = s[i];
        }
        x[this->size() + strlen(s)] = '\0';
        delete [] str;
        str = x;
        l = l + strlen(s);
        return *this; 
    }
    String operator+ (const char *s)
    {
        unsigned int i;
        
        for(i = 0;i <= strlen(s);i++)
        {
            str[size() + i] = s[i];
        }
        str[size() + strlen(s)] = '\0';
        l = l + strlen(s);
        return *this;
    }
    String operator+ (const String& other)
    {
        unsigned int i;
        char *x;
        if(other.str)
            x = new char[this->size() + strlen(other.str) + 1];
        else
            x = new char[this->size() + 1];
        strcpy(x, str);
        if(other.str)
        {
			for(i = 0;i < strlen(other.str);i++)
			{
			    x[this->size() + i] = other.str[i];
			}
        	x[this->size() + strlen(other.str)] = '\0';
        }
        else
        	x[this->size()] = '\0';
		String a(x);
		delete [] x;
        return a;
    }
    char& operator[] (const int i)
    {
        return str[i];
    }
    bool isNull()const{
        if(str)
            return true;
        else
            return false;
    }
    String& operator<< ( const String& other){
        unsigned int i;
        char *x;
        x = new char[this->size() + strlen(other.str) + 1];
        if(str)
	        strcpy(x, str);
        for(i = 0;i < strlen(other.str);i++)
        {
            x[this->size() + i] = other.str[i];
        }
        x[this->size() + strlen(other.str)] = '\0';
        delete [] str;
        str = x;
        l = l + strlen(other.str);
        return *this;
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
