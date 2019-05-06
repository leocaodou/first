#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

class Figure{
    public :
        constexpr static double pi = 3.1415927;
        //返回该类对象所代表图形的面积 
        virtual double getArea() const{
            return 0; 
        } 
        //打印该类对象所代表的图形的面积以及类名 
        virtual void print() const{
            cout <<  "Figure:";
        } 
};

//矩形 
 class Rectangle:public Figure{
 private:
 float width,height;    
 public:
    //构造函数 
    Rectangle(float w,float h) : width(w),height(h){}
 //计算面积 
    double getArea() const{
        return width * height; 
    }
 //打印该类对象所代表的图形的面积以及类名 
    void print() const{
        cout <<  "Rectangle:" << getArea();
        }
   };

//圆形 
class Circle : public Figure{
private:
float radius;
 public:
    //构造函数 
    Circle(float r) : radius(r){}
    //计算面积 
double getArea() const{
    return radius * radius * Figure::pi; 
 }  
 //打印该类对象所代表的图形的面积以及类名 
        virtual void print() const{
            cout <<  "Circle:" << getArea();
    }
}; 

class Square:public Rectangle{
private:
public: 
//构造函数
 Square(float l) : Rectangle(l,l){}
 //计算面积 
    double getArea() const{
        return  Rectangle::getArea(); 
    }
//打印该类对象所代表的图形的面积以及类名 
    void print() const{
            cout <<  "Square:" << getArea();
 }  
};

bool compare(Figure *p,Figure *q )
{
    return p->getArea() < q->getArea(); 
}

int main(){
    Rectangle rect(3. , 5.);
    Circle circle(8. / Figure::pi);
    Square square(4.);
    
    Figure *pList [] = {&rect, &circle, &square};
    Figure *min = pList[0];
    
    for(int i = 1; i < 3; ++i){
        if(compare(pList[i], min))
        {
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