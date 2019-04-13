#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
class String{
private:
    char *str;
    size_t length;
public:
    String() : str(NULL), length(0) {}

    String(const char *s) : str(NULL), length(0) {
        if (s == NULL)
            return;
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) : str(NULL), length(0) {
        if (other.str == NULL)
        return;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return;

}

 
    ~String() {
        delete[] str;
        length = 0;
}

String& append(const String &other) {
    if (other.str == NULL)
        return *this;
    if (str == NULL) {
        str = new char[other.length + 1];
        length = other.length;
        strcpy(str, other.str);
        return *this;
    }
    char *temp = new char[length + other.length + 1];
    strcpy(temp, str);
    strcat(temp, other.str);
//  strcpy(temp + length, other.str);
    delete []str;
    str = temp;
    length += other.length;
    return *this;

}


String& operator= (const String&other) {
    if (this == &other)
        return *this;

    delete[] str;
    str = NULL;
    length = 0;

    if (other.str == NULL)
        return *this;

    str = new char[other.length + 1];
    strcpy(str, other.str);
    length = other.length;

    return *this;
    }
String& operator+=(const String& other) {
    return this->append(other);
}

String& operator<<(const String& other) {
    return this->append(other);//return *this += other; 
}

String operator+(const String& other)const {
    if (str == NULL)
        return other;
    if (other.str == NULL)
        return *this;
    String result(*this);
    result += other;//result.length = length + other.length;          result.str = new char[length + other.length +1];            strcpy(result.str, str);    strcpy(result.str +length,other.str);          
    return result;
    }
    char& operator[] (const int i) { 
        assert(i >= 0 && i < length);
        return str[i]; 
    } 

    bool isNull()const{
        return str == NULL;
    }
friend ostream& operator <<(ostream& out, const String& str);
};

 
ostream& operator <<(ostream& out, const String& str) {
    if(str.str)
        cout << str.str;
    else
        return out;
    return out;
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
