#include <iostream>
using namespace std;
class Complex {
private:
    double real,imagine;    
public: 
    Complex(){
        real = 0;
        imagine = 0;
}
    Complex(const double r,const double i){
        real = r;
        imagine = i;
    }
    Complex(const Complex& other){
        real = other.real;
        imagine = other.imagine;
        
    }
Complex& operator=(const Complex& other){
    if(this != &other)
    real = other.real;
    imagine = other.imagine;
}   
Complex operator+ (const Complex& other) const{
    return Complex(real + other.real,imagine + other.imagine);
}
Complex operator- (const Complex& other) const{
    return Complex(real - other.real,imagine - other.imagine);
}

    friend Complex operator* (const Complex& , const Complex& );
    friend ostream& operator<<( ostream& output ,const Complex&);
}; 
Complex operator* (const Complex& op1, const Complex& op2){
    double s = op1.real*op2.real - op1.imagine*op2.imagine;
    double x = op1.imagine*op2.real + op1.real*op2.imagine;
    Complex c(s,x);
    return c;}
ostream& operator<<( ostream& output ,const Complex& c){
    cout<< c.real <<" + "<< c.imagine <<" i\n";
    return output;
}

int main(){
    Complex c1(4.234234, -27.6), c2(3.5, -4.7);
    Complex c3, c4;
    c3 = c2 + c1;
    c4 = c3 * c1;
    c2 = c4 - c1;
    cout  << c1  << c2  << c3  << c4  << c1 - c4 ;
    return 0;
}
