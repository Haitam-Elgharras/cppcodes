

#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    point();
    point(int);
    point(int, int);
    point(point &);
    void affiche();
    void affiche(char *);
    friend point &operator+(point &, point &);
    void operator=(point const b);
};

point::point()
{
    x = y = 0;
}
point::point(int val)
{
    x = y = val;
}
point::point(int val1, int val2)
{
    x = val1;
    y = val2;
}
point::point(point &b)
{
    cout << "called the copy constructor" << endl;
    this->x = b.x;
    this->y = b.y;
}

void point::affiche()
{
    cout << " x= " << x << " et y= " << y << endl;
}
void point::affiche(char *name)
{
    cout << *name;
    affiche();
}

point &operator+(point &a, point &b)
{
    cout << "called the operator +" << endl;
    point *c = new point(a.x + b.x, a.y + b.y);
    return *c;
}
void point::operator=(point const b)
{
    cout << "called the operator =" << endl;
    this->x = b.x;
    this->y = b.y;
}
class Base
{
private:
    int base_private_var;

protected:
    int base_protected_var;

public:
    int base_public_var;

    Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

    void base_public_func() {}
    void getProPri()
    {
        cout << base_private_var << " " << base_protected_var;
    }
};
class Derived : protected Base
{
private:
    int derived_private_var;

public:
    int derived_public_var;

    Derived() : derived_private_var(0), derived_public_var(0) {}
    void setPro(int a)
    {
        base_protected_var = a;
    }
    void derived_public_func() {}
};

int main()
{
    // Création d'une instance de Base
    Base b;

    // Création d'une instance de Derived
    Derived d;

    // Impossible d'accéder aux membres privés de Base et de Derived depuis l'extérieur
    // d.base_private_var = 10; // Erreur de compilation : 'int Base::base_private_var' is private within this context
    // d.derived_private_var = 20; // Erreur de compilation : 'int Derived::derived_private_var' is private within this context
    // d.base_protected_var=30; //Erreur de compilation :'int base::base_protected_var' is protected within this context(acessible inside the class)

    return 0;
}
