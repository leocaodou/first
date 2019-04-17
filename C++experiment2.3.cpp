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
    String() : str(NULL), l(0){//无参的构造函数，并且构造初始化*str与l
    }
    String(const char *s)//带有一个字符串为参数的构造函数
    {
        if(s)//先判断传入的字符串是否为空
        {
            l = strlen(s);
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else//字符串为空则还是把指针*str指向空
        {
            str = NULL;
            l = 0;
        }
        
    }
    String(const String& other) : l(other.l)//拷贝构造函数，可以直接使用需要拷贝构造的l来构造this的l
    {
        if(other.str)//判断需要拷贝的对象str是否为空
        {
            str = new char[other.l + 1];
            strcpy(str, other.str);
        }
        else//为空的话，让构造出来的对象str也指向空
            str = NULL;
    }
    ~String()
    {
        delete [] str;//str的空间是由new开辟出来，所以最后得使用delete删去空间
        l = 0;
    }
    unsigned int size() const//用于返回对象的*str中的字符串的长度
    {
        unsigned int i;
        if(str)
        {
            for(i = 0;;i++)//一个个检测str的每一位是否为'\0'，并且计数，最后检测到'\0'时返回计的数
            {
                if(str[i] =='\0')
                    break;
            }
            return i;
        }
        return 0;
    }
    String& append(const String& other)//在进行两个String类对象相加时的函数，为的是让自己定义的类的字符串相加并且长度相加
    {
        l = other.l + l;//长度相加
        if(other.str)//判断相加的字符串是否为空
        {
            char *x = new char[l + other.l + 1];//定义一个指针并指向一个开辟出两个字符串长度之和的空间
            if(str)//判断被加的对象字符串是否为空
            {
                strcpy(x, str);
                strcat(x,other.str);//把拷贝好的x字符串与other的字符串相加，strcat函数可以用于两字符串相加，更加方便
                delete [] str;
            }
        else
                strcpy(x, other.str);//若自己的字符串为空，直接拷贝other的字符串
            str = x;
            return *this;
        }
        else
            return *this;//若other的字符串为空，直接原封不动的返回
    }
    String& operator= (const String& other)//重载操作符=，加const是为了防止传入的为右值
    {
        l = other.l;
        if(this == &other)//若是和自己赋值，则原封不动返回自己，以免误删自己的str
            return *this;
        if(str)//先判断Str是否为空
        {
            delete [] str;//不为空则删除原本str指向的开辟出的空间，反正空间泄漏
        }
        if(other.str)
        {
            str = new char[other.l + 1];
            strcpy(str, other.str);
        }
        else
            str = NULL;
    }
    String& operator+= (const String& other)//重载操作符+=号
    {
        return append(other);//效果和append函数相似，可以直接使用其与other相加并返回
    }
    String operator+ (const String& other) const//重载操作符+号，加const说明函数对成员不会进行修改
    {
        String A(*this);//先用this来构造出一个A，由于+的返回值不是自己，所以得创建出A来返回
        A += other;
        return A;
    }
    char& operator[] (const int i) const//重载操作符[]，这样可以使得调用具体字符会方便很多
    {
        assert(i >= 0 && i < l);//加入了assert函数，来判断str[i]是否存在，不存在就返回错误报告
            return str[i];
    }
    bool isNull()const{//用于判断str是否为空的函数
        if(str)
            return true;
        else
            return false;
    }
    String& operator<< ( const String& other){//重载操作符<<，效果与append()函数相似
        return this->append(other);
    }
    friend ostream& operator<< ( ostream& output, const String& other);//友元函数，因为<<将会使用到类的private成员
};
ostream& operator<< ( ostream& output, const String& other){//重载函数cout加操作符<<，加const防止传入的值为右值
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