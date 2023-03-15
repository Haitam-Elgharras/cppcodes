#include <iostream>

using namespace std;

class A
{
public:
    int tab[10];
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main(void)
{
    /*Puisque B et C héritent de la classe mère A, deux copies de la classe mère
    sont présentes dans la classe D, donc 2*(4*10)=80 octets */
    cout << sizeof(D);
    D x;
    x.B::tab[0] = 10;
    x.C::tab[0] = 20;
    cout << x.B::tab[0];
    cout << x.C::tab[0];
    return 0;
}