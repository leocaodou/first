class A {
private:
    int a;
public:
    A(int _a = 0) : a(_a) { }
};

class B : public A {
private:
     int a;
public:
    B(int _a) : a(_a) {}

};
int main()
{
    B b(5);
    return 0;
}