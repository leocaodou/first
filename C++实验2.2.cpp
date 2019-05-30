#include <iostream>
#include <stdio.h>
using namespace std;
class Complex{
private:
	double real;
	double imagine;
public:
	Complex() : real(0),imagine(0){//无参的构造函数，并且使用0去构造初始化成员
	}
	Complex(double a, double b) : real(a), imagine(b){//有参数的构造函数，并且使用传入的a和b去初始化成员
	}
	Complex(const Complex& other) : real(other.real),imagine(other.imagine){
	}
	Complex operator+ ( const Complex& other) const{//重载操作符+号，因为是两个自己定义的类相加，第一个const加上的原因是可能传入的是一个右值不然无法引用，并确保传入的Complex不被修改，第二个const是因为函数不会对任何成员进行修改
		return Complex(real + other.real, imagine + other.imagine);
	}
	Complex operator- ( const Complex& other) const{//重载操作符+号，因为是两个自己定义的类相减，两个const原因同上
		return Complex(real - other.real, imagine - other.imagine);
	}
	Complex operator= ( const Complex& other) {//重载操作符=号，便于让自己定义的complex类赋值时进行操作
		real = other.real;
		imagine = other.imagine;
	}
	friend ostream& operator<< ( ostream&,const Complex&);//友元函数，由于非成员重载<<函数会对类中的private的成员进行修改，所以必须在类中加入此友元函数，这里的const必须加上，防止传入的值为右值
	friend Complex operator* ( const Complex&, const Complex&);//友元函数，同样是因为重载*函数会对类中的private的成员进行修改，这里的两个const也同样是防止引用右值，并且确保不会修改传入的两个Complex
};
ostream& operator<< ( ostream& output, const Complex& other){//对于操作符<<的重载,在使用cin输入时会使用到，以确定输出的格式
		cout << other.real << " + " << other.imagine << " i\n";
		return output;
}
Complex operator* ( const Complex& a, const Complex& other){//重载操作符*，使得自己定义的类之间可以进行相乘
		return Complex(a.real * other.real -a.imagine * other.imagine, a.imagine * other.real + a.real * other.imagine);
}
int main(){

    Complex c1(4.234234, -27.6), c2(3.5, -4.7);

    Complex c3, c4;

    c3 = c2 + c1;

    c4 = c3 * c1;

    c2 = c4 - c1;

    cout  << c1  << c2  << c3 << c4 << c1 - c4;//最后输出的是一个右值，所以对应了前面的重载<<的const，必须时刻注意
    return 0;
}