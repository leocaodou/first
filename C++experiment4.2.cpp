#include <iostream>
#include <string>
using namespace std;
class Figure
{
public:
    constexpr static double pi = 3.1415927;
    virtual double getArea() const = 0;
    virtual void print() const = 0;
};

class Rectangle : public Figure
{
protected:
    double a;
    double b;
public:
    Rectangle() : a(0),b(0){}
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
class Circle : public Figure
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
class Square : public Rectangle
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
bool compare(Figure *p, Figure *q)
{
    if(p->getArea() < q->getArea())
        return true;
    else
        return false;
}


int main(){
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