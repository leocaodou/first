#include <iostream>
#include <string>
using namespace std;
class Figure
{
public:
    constexpr static double pi = 3.1415927;
    virtual double getArea() const {return 0;}//虚函数，方便用于之后的图形求面积，由于是double类型，因此还有一个return 0；
    virtual void print() const {}//虚函数，方便之后的图形面积结果的输出
};

class Rectangle : public Figure//矩形派生于图形这个基类
{
protected:
    double a;
    double b;
public:
    Rectangle() : a(0),b(0){}//必须有自己的构造函数，否则无法单独定义
    Rectangle(double _a, double _b) : a(_a),b(_b){}
    double getArea() const 
    {
        return a * b;
    }
    void print() const
    {
        cout << "Rectangle:" << getArea();
    }
};
class Circle : public Figure//圆形
{
private:
    double r;
public:
    Circle() : r(0){}
    Circle(double a) : r(a){}
    double getArea() const 
    {
        return pi*r*r;
    }
    void print() const
    {
        cout << "Circle:" << getArea();
    }
};
class Square : public Rectangle//正方形，因为他是特殊的矩形，因此派生于Rectangle
{
public:
    Square() : Rectangle(){}
    Square(double _a) : Rectangle( _a, _a){}
    double getArea() const 
    {
        return a * b;
    }
    void print() const
    {
        cout << "Square:" << getArea();
    }
};
bool compare(Figure *p, Figure *q)//由于判断图形面积大小的函数，传入的变量被基类指针指向，因为基类函数为纯虚函数，所以计算面积会调用自己类的计算面积函数
{
    if(p->getArea() < q->getArea())
        return true;
    else
        return false;
}


int main(){
    Figure A;
    Rectangle rect(3. , 5.);
    Circle circle(8. / Figure::pi);
    Square square(4.);
    
    Figure *pList [] = {&rect, &circle, &square};
    Figure *min = pList[0];
    for(int i = 1; i < 3; ++i){
        if(compare(pList[i], min)){
            pList[i]->print();
            printf(" < ");
            min->print();
            printf("\n");
            min = pList[i];
        }
        else{
            min->print();
            printf(" < ");
            pList[i]->print();
            printf("\n");
        }
    }
    printf("Minimum:\n");
    min->print();
    printf("\n");
    return 0;
}