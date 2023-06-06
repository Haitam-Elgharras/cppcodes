
// // // // // // // #include <iostream>
// // // // // // // #include <stdlib.h>
// // // // // // // using namespace std;

// // // // // // // class hasard
// // // // // // // {
// // // // // // //     int *val;
// // // // // // //     int nbVal;
// // // // // // //     int max;
// // // // // // //     hasard(int, int);
// // // // // // //     ~hasard();
// // // // // // // };

// // // // // // // hasard::hasard(int max, int nbVal = 10)
// // // // // // // {
// // // // // // //     this->nbVal = nbVal;
// // // // // // //     this->max = max;
// // // // // // //     val = new int[nbVal];
// // // // // // //     for (int i = 0; i < nbVal; i++)
// // // // // // //     {
// // // // // // //         val[i] = rand() % (max + 1);
// // // // // // //         cout << rand() % (max + 1) << endl;
// // // // // // //     }
// // // // // // // }
// // // // // // // hasard ::~hasard()
// // // // // // // {
// // // // // // //     cout << "we will deallocate now" << endl;
// // // // // // //     delete[] val;
// // // // // // // }

// // // // // // /*

// // // // // // #include <iostream>
// // // // // // using namespace std;

// // // // // // class compteur
// // // // // // {
// // // // // //     // static int classMembres = 0; we can't initialize a static memeber inside the class

// // // // // //     static int classMembres;

// // // // // // public:
// // // // // //     compteur()
// // // // // //     {
// // // // // //         classMembres++;
// // // // // //     }
// // // // // //     ~compteur()
// // // // // //     {
// // // // // //         cout << classMembres << endl;
// // // // // //         classMembres--;
// // // // // //         cout << "an object was destroyed "
// // // // // //              << "the number of objects now is :" << classMembres << endl;
// // // // // //     }
// // // // // // };
// // // // // // int compteur::classMembres = 0;
// // // // // // void essai()
// // // // // // {
// // // // // //     compteur u, v;
// // // // // // }

// // // // // // int main()
// // // // // // {
// // // // // //     compteur a;
// // // // // //     essai();
// // // // // //     compteur a;

// // // // // //     return 0;
// // // // // // }*/

// // // // // // /*

// // // // // // #include <iostream>
// // // // // // using namespace std;

// // // // // // class point
// // // // // // {
// // // // // //     int x, y;

// // // // // // public:
// // // // // //     point()
// // // // // //     {
// // // // // //         x = y = 0;
// // // // // //     }
// // // // // //     point(int val)
// // // // // //     {
// // // // // //         x = y = val;
// // // // // //     }
// // // // // //     point(int val1, int val2)
// // // // // //     {
// // // // // //         x = val1;
// // // // // //         y = val2;
// // // // // //     }
// // // // // //     void affiche()
// // // // // //     {
// // // // // //         cout << " :x= " << x << " et y= " << y << endl;
// // // // // //     }
// // // // // //     void affiche(char *name)
// // // // // //     {
// // // // // //         cout << *name;
// // // // // //         affiche();
// // // // // //     }
// // // // // // };

// // // // // // int main()
// // // // // // {
// // // // // //     char newName;
// // // // // //     cin >> newName;
// // // // // //     point p1(1, 3);
// // // // // //     p1.affiche(&newName);
// // // // // //     point p2(5);
// // // // // //     cin >> newName;
// // // // // //     for (int i = 0; i < 90; i++)
// // // // // //     {
// // // // // //         p2.affiche(&newName);
// // // // // //     }
// // // // // //     point p3;
// // // // // //     cin >> newName;
// // // // // //     p3.affiche(&newName);
// // // // // // }
// // // // // // */
// // // // // // #include <iostream>
// // // // // // using namespace std;
// // // // // // class Point
// // // // // // {
// // // // // // public:
// // // // // //     Point(int x, int y) : x_(x), y_(y) {}

// // // // // //     Point operator+(const Point other) const
// // // // // //     {
// // // // // //         return Point(x_ + other.x_, y_ + other.y_);
// // // // // //     }
// // // // // //     Point operator*(int h)
// // // // // //     {
// // // // // //         return Point(x_ * h, y_ * h);
// // // // // //     }
// // // // // //     int operator*(const Point other) const
// // // // // //     {
// // // // // //         return x_ * other.x_ + y_ * other.y_;
// // // // // //     }
// // // // // //     void display() const
// // // // // //     {
// // // // // //         std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
// // // // // //     }

// // // // // // private:
// // // // // //     int x_;
// // // // // //     int y_;
// // // // // // };

// // // // // // int main()
// // // // // // {
// // // // // //     Point a(1, 2);
// // // // // //     Point b(1, 2);
// // // // // //     int produitScalair = 0;
// // // // // //     // it's the same as c=a.operator+(b) but we must use the c=a+b
// // // // // //     Point c = a + b;
// // // // // //     c.display();
// // // // // //     produitScalair = a * b;
// // // // // //     cout << produitScalair << endl;
// // // // // //     a = a * 5;
// // // // // //     a.display();
// // // // // //     return 0;
// // // // // // }

// // // // // #include <iostream>

// // // // // class list
// // // // // {

// // // // //     int taille;
// // // // //     float *adr;

// // // // // public:
// // // // //     list(int);
// // // // //     list(list &);
// // // // //     void saisie();
// // // // //     void affiche();
// // // // //     void operator=(list &);
// // // // //     float operator[](int);
// // // // //     ~list();
// // // // // };

// // // // // list::list(int t)
// // // // // {
// // // // //     cout << "the construction of a list ";
// // // // //     taille = t;
// // // // //     adr = new float[taille];
// // // // // }

// // // // // list::list(list &other)
// // // // // {
// // // // //     cout << "the copy constructor";
// // // // //     taille = other.taille;
// // // // //     adr = new float[taille];
// // // // //     for (int i = 0; i < taille; i++)
// // // // //     {
// // // // //         adr[i] = other.adr[i];
// // // // //     }
// // // // // };

// // // // // void list::saisie()
// // // // // {
// // // // //     for (int i = 0; i < taille; i++)
// // // // //     {
// // // // //         cout << "write a number ";
// // // // //         cin >> adr[i];
// // // // //     }
// // // // // }
// // // // // void list::affiche()
// // // // // {
// // // // //     cout << "the data of the list is : \n";
// // // // //     for (int i = 0; i < taille; i++)
// // // // //     {
// // // // //         cout << adr[i] << endl;
// // // // //     }
// // // // // }

// // // // // void list::operator=(list &other)
// // // // // {
// // // // //     cout << "the = operator ";
// // // // //     taille = other.taille;
// // // // //     adr = new float[taille];
// // // // //     for (int i = 0; i < taille; i++)
// // // // //     {
// // // // //         adr[i] = other.adr[i];
// // // // //     }
// // // // // }

// // // // // float list::operator[](int i)
// // // // // {
// // // // //     return adr[i];
// // // // // }

// // // // // #include <iostream>
// // // // // using namespace std;

// // // // // // #include "list.h" // assuming the list class is defined in a separate header file

// // // // // int main()
// // // // // {
// // // // //     int size;
// // // // //     cout << "Enter the size of the list: ";
// // // // //     cin >> size;

// // // // //     list myList(size);

// // // // //     cout << "Enter " << size << " numbers for the list:\n";
// // // // //     myList.saisie();

// // // // //     cout << "The contents of the list are:\n";
// // // // //     myList.affiche();

// // // // //     cout << "Testing the copy constructor:\n";
// // // // //     list myList2(myList);
// // // // //     cout << "The contents of the copied list are:\n";
// // // // //     myList2.affiche();

// // // // //     cout << "Testing the = operator:\n";
// // // // //     list myList3(0); // create an empty list to assign to
// // // // //     myList3 = myList;
// // // // //     cout << "The contents of the assigned list are:\n";
// // // // //     myList3.affiche();

// // // // //     cout << "Testing the [] operator:\n";
// // // // //     for (int i = 0; i < size; i++)
// // // // //     {
// // // // //         cout << "myList[" << i << "] = " << myList[i] << endl;
// // // // //     }

// // // // //     return 0;
// // // // // }
// // // // #include <iostream>
// // // // #include <string>
// // // // using namespace std;

// // // // class Base
// // // // {
// // // // private:
// // // //     int base_private_var;

// // // // protected:
// // // //     int base_protected_var;

// // // // public:
// // // //     int base_public_var;

// // // //     Base() : base_private_var(0), base_protected_var(0), base_public_var(0) {}

// // // //     // Method to get private member
// // // //     int get_base_private_var() const
// // // //     {
// // // //         return base_private_var;
// // // //     }
// // // //     void set_base_private_var_base(int value)
// // // //     {
// // // //         base_private_var = value;
// // // //     }
// // // //     void set_base_protected_var_base(int value)
// // // //     {
// // // //         base_protected_var = value;
// // // //     }
// // // //     int get_base_protected_var() const
// // // //     {
// // // //         return base_protected_var;
// // // //     }
// // // // };

// // // // // Classe dérivée héritant de Base
// // // // class Derived : protected Base
// // // // {
// // // // private:
// // // //     int derived_private_var;

// // // // public:
// // // //     int derived_public_var;

// // // //     Derived() : derived_private_var(0), derived_public_var(0) {}

// // // //     // Method to set base private member
// // // //     void set_base_private_var_derived(int value)
// // // //     {
// // // //         set_base_private_var_base(value); // private inside the derived
// // // //     }

// // // //     // Method to get base protected member cause it considered private here
// // // //     int get_base_protected_var() const
// // // //     {
// // // //         return base_protected_var;
// // // //     }

// // // //     // Method to get base public member
// // // //     int get_base_public_var() const
// // // //     {
// // // //         return base_public_var;
// // // //     }

// // // //     int get_base_private_var_derived() const
// // // //     {
// // // //         return get_base_private_var();
// // // //     }
// // // // };
// // // // int main()
// // // // {
// // // //     // Création d'une instance de Base
// // // //     Base b;

// // // //     // Accès aux membres publics de Base
// // // //     b.base_public_var = 42;
// // // //     b.set_base_protected_var_base(99);
// // // //     cout << b.get_base_protected_var() << endl;

// // // //     // Création d'une instance de Derived
// // // //     Derived d;

// // // //     // // Accès aux membres publics de Derived
// // // //     // d.derived_public_var = 23;

// // // //     // // Accès aux membres publics de Base via une instance de Derived
// // // //     // d.base_public_var = 13;

// // // //     // Accès aux membres privés de Base et de Derived via une méthode publique de Derived
// // // //     d.set_base_private_var_derived(10);
// // // //     cout << d.get_base_private_var_derived();
// // // //     // Accès aux membres protégés et publics de Base via des méthodes publiques de Derived
// // // //     int base_protected_var = d.get_base_protected_var();
// // // //     int base_public_var = d.get_base_public_var();

// // // //     return 0;
// // // // }
// // // #include <iostream>
// // // #include <string>
// // // using namespace std;

// // // class Base
// // // {
// // // public:
// // //     Base()
// // //     {
// // //         std::cout << "Constructor of Base" << std::endl;
// // //     }
// // //     ~Base()
// // //     {
// // //         std::cout << "Destructor of Base" << std::endl;
// // //     }
// // // };

// // // class Derived : public Base
// // // {
// // // public:
// // //     Derived()
// // //     {
// // //         std::cout << "Constructor of Derived" << std::endl;
// // //     }
// // //     ~Derived()
// // //     {
// // //         std::cout << "Destructor of Derived" << std::endl;
// // //     }
// // // };

// // // int main()
// // // {
// // //     Derived d;
// // //     return 0;
// // // }

// // #include <iostream>
// // #include <cmath>

// // using namespace std;

// // #define M_PI 3.14159265358979323846

// class Coordonne
// {
// private:
//     int x, y;
//     friend class Triangle;

// public:
//     Coordonne(int a = 0, int b = 0) : x(a), y(b) {}

//     // deplace the point
//     void deplace(int a, int b)
//     {
//         x += a;
//         y += b;
//     }

//     // print the coordinates of the point
//     void affiche() const
//     {
//         cout << "x = " << x << " y = " << y << endl;
//     }

//     // calculate the distance between two points
//     double distance(const Coordonne &other) const
//     {
//         return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
//     }
// };

// class Forme
// {
// protected:
//     short couleur;

// public:
//     Forme(short c = 1) : couleur(c)
//     {
//         cout << "constructor for forme" << endl;
//     }

//     // copy constructor for Forme
//     Forme(const Forme &f)
//     {
//         cout << "copy constructor for forme" << endl;

//         couleur = f.couleur;
//     }

//     ~Forme()
//     {
//         cout << " destructor for forme" << endl;
//     }

//     // print the color of the shape
//     void affiche() const { cout << "Couleur: " << couleur << endl; }

//     // assignment operator for Forme
//     Forme &
//     operator=(const Forme &f)
//     {
//         if (this != &f)
//         {
//             couleur = f.couleur;
//         }
//         return *this;
//     }

//     // calculate perimeter of the shape
//     double perimetre() const { return 0; }

//     // calculate surface of the shape
//     double surface() const { return 0; }

//     // move the shape
//     void deplace() {}
// };

// class Cercle : public Forme
// {
// private:
//     Coordonne centre;
//     double rayon;

// public:
//     Cercle(short c = 0, int x = 0, int y = 0, double r = 0) : Forme(c), rayon(r), centre(x, y)
//     {
//         cout << "the cercle constructor" << endl;
//     }

//     // copy constructor for Cercle
//     Cercle(const Cercle &c) : Forme(c), centre(c.centre), rayon(c.rayon)
//     {
//         cout << "the copy constructor for Cercle" << endl;
//     }

//     // destructor for Cercle
//     ~Cercle()
//     {
//         cout << "the cercle destructor" << endl;
//     }

//     // print the circle properties
//     void affiche() const
//     {
//         cout << "the cercle";
//         Forme::affiche();
//         cout << "Centre: ";
//         centre.affiche();
//         cout << "Rayon: " << rayon << endl;
//     }

//     // assignment operator for Cercle
//     Cercle &operator=(const Cercle &c)
//     {
//         if (this != &c)
//         {
//             Forme::operator=(c);
//             centre = c.centre;
//             rayon = c.rayon;
//         }
//         return *this;
//     }

//     // calculate perimeter of the circle
//     double perimetre() const { return 2 * M_PI * rayon; }

//     // calculate surface of the circle
//     double surface() const { return M_PI * rayon * rayon; }

//     // move the circle
//     void deplace(int a, int b) { centre.deplace(a, b); }
// };

// class Triangle : public Forme
// {
// private:
//     Coordonne a, b, c;

// public:
//     Triangle(short c = 0, int ax = 0, int ay = 0, int bx = 0, int by = 0, int cx = 0, int cy = 0) : Forme(c), b(bx, by), c(cx, cy)
//     {
//         cout << "the constructor for triangle" << endl;
//         // the default = will be called
//         a = Coordonne(ax, ay);
//     }
//     Triangle(Triangle &t) : Forme(t), a(t.a), b(t.b), c(t.c)
//     {
//         cout << "the copy constructor for triangle " << endl;
//     }
//     ~Triangle()
//     {
//         cout << "the destructor for triangle " << endl;
//     }
//     void affiche() const
//     {
//         cout << "the triangle";
//         Forme::affiche();
//         a.affiche();
//         b.affiche();
//         c.affiche();
//     }
//     Triangle &operator=(Triangle &t)
//     {
//         if (this != &t)
//         {
//             Forme::operator=(t);
//             a = t.a;
//             b = t.b;
//             c = t.c;
//         }
//         return *this;
//     }

//     double perimetre() const // p=d1+d2+d3;
//     {
//         // the distance between each 2 points
//         double ab = a.distance(b);
//         double ac = a.distance(c);
//         double bc = b.distance(c);
//         return ab + ac + bc;
//     }
//     double surface() const
//     {
//         double ab = a.distance(b);
//         double ac = a.distance(c);
//         double abac = (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
//         double angleA = acos(abac / (ab * ac));
//         return 0.5 * ab * ac * sin(angleA);
//     }
//     void deplace(int dx, int dy)
//     {
//         a.x += dx;
//         a.y += dy;
//         b.x += dx;
//         b.y += dy;
//         c.x += dx;
//         c.y += dy;
//     }
// };

// class Rectangle : public Forme
// {
// protected:
//     Coordonne hd; // Haut-droit
//     Coordonne bg; // Bas-Gauche
// public:
//     Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, short c = 0) : hd(x1, y1), bg(x2, y2), Forme(c) {}
//     Rectangle(const Rectangle &r) : Forme(r.couleur), hd(r.hd), bg(r.bg) {}
//     void affiche() const
//     {
//         Forme::affiche();
//         hd.affiche();
//         bg.affiche();
//     }
//     void deplace(int dx, int dy)
//     {
//         hd.deplace(dx, dy);
//         bg.deplace(dx, dy);
//     }
//     // int surface() const { return (bg.x - hd.x) * (bg.y - hd.y); }
//     // int perimetre() const { return 2 * (bg.x - hd.x + bg.y - hd.y); }
// };

// class Carre : public Rectangle
// {
// private:
//     short cote;

// public:
//     Carre(int x = 0, int y = 0, int c = 0, short color = 1) : Rectangle(x, y, c, c, color), cote(c) {}
//     Carre(const Carre &other) : Rectangle(other), cote(other.cote) {}
//     Carre &operator=(const Carre &other)
//     {
//         if (this != &other)
//         {
//             Rectangle::operator=(other);
//             cote = other.cote;
//         }
//         return *this;
//     }
//     void affiche() const
//     {
//         cout << "Coin bas gauche: ";
//         Rectangle::affiche();
//         cout << ", Cote: " << cote << ", Couleur: " << couleur << endl;
//     }
//     void deplace(int dx, int dy)
//     {
//         Rectangle::deplace(dx, dy);
//     }
//     int surface() const
//     {
//         return cote * cote;
//     }
//     int perimetre() const
//     {
//         return 4 * cote;
//     }
// };

// int main()
// {
//     // création d'un cercle de coordonnées (10, 20), de rayon 5 et de couleur 12
//     Cercle c(10, 20, 5, 12);

//     // affichage du cercle
//     c.affiche();

//     // déplacement du cercle de (5, 4)
//     c.deplace(5, 4);

//     // affichage du cercle
//     c.affiche();

//     // création d'un triangle avec les coordonnées (0, 0), (1, 1) et (2, 2)
//     Triangle t(0, 0, 0, 1, 1, 2, 2);

//     // affichage du triangle
//     t.affiche();

//     // déplacement du triangle de (5, 4)
//     t.deplace(5, 4);

//     // affichage du triangle après déplacement
//     t.affiche();

//     Carre C(1, 1, 12, 13);

//     // affichage du triangle
//     C.affiche();

//     // déplacement du triangle de (5, 4)
//     C.deplace(5, 4);

//     // affichage du triangle après déplacement
//     C.affiche();

//     return 0;
// }
#include <iostream>
using namespace std;
class A
{
public:
    void foo() { cout << "A::foo()" << endl; }
};

class B : public A
{
public:
    void foo() { cout << "B::foo()" << endl; }
};

class C : public A
{
public:
    void foo() { cout << "C::foo()" << endl; }
};

class D : public B, public C
{
public:
    void foo() { cout << "D::foo()" << endl; }
};

int main()
{
    D d;
    d.A::foo();
    return 0;
}