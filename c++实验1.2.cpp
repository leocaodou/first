#include <stdio.h>
void swap(int *d1, int *d2)
{
	int p;
	p = *d1;
	*d1 = *d2;
	*d2 = p;
}
double funct(char x){
	return 0;
}
void swap(int &d1, int &d2){
	int p;
	p = d1;
	d1 = d2;
	d2 = p;
}
char x()
{
	return o;
}
int main(){
    int a, b;
    char x;
    scanf("%d%d", &a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (&a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (a, b);
    printf("a:%d, b:%d\n", a, b);
    double funct(char x);
    char x();
    return 0;
}