#include <iostream>
#include <stdio.h>
using namespace std;
class Complex{
private:
	double real;
	double imagine;
public:
	Complex() : real(0),imagine(0){
	}
	Complex(double a, double b) : real(a), imagine(b){
	}
	Complex(const Complex& other) : real(other.real),imagine(other.imagine){
	}
	Complex operator+ ( const Complex& other) const{
		return Complex(real + other.real, imagine + other.imagine);
	}
	Complex operator- ( const Complex& other) const{
		return Complex(real - other.real, imagine - other.imagine);
	}
	Complex& operator= ( const Complex& other) {
		real = other.real;
		imagine = other.imagine;
		return *this;
	}
	friend ostream& operator<< ( ostream&,const Complex&);
	friend Complex operator* ( const Complex&, const Complex&);
};
ostream& operator<< ( ostream& output, const Complex& other){
		cout << other.real << " + " << other.imagine << " i\n";
		return output;
}
Complex operator* ( const Complex& a, const Complex& other){
		return Complex(a.real * other.real -a.imagine * other.imagine, a.imagine * other.real + a.real * other.imagine);
}
int main(){

    Complex c1(4.234234, -27.6), c2(3.5, -4.7);

    Complex c3, c4;

    c3 = c2 + c1;

    c4 = c3 * c1;

    c2 = c4 - c1;

    cout  << c1  << c2  << c3 << c4 << c1 - c4;
    return 0;
}