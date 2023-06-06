#include <iostream>
using namespace std;
class point
{
    int x, y;

public:
    point(int abs, int ord)
    {
        cout << "constructor point " << endl;
        x = abs;
        y = ord;
    }
    ~point()
    {

        cout << " point destructur  " << x << ", " << y << std::endl;
    }
    void affiche()
    {
        cout << "Coordonnees : " << x << ", " << y << std::endl;
    }
};

class coul
{
    short couleur;

public:
    coul(short cl)
    {
        cout << "constructor coul " << endl;
        couleur = cl;
    }
    ~coul()
    {
        cout << "coul destructor " << endl;
    }
    void affiche()
    {
        std::cout << "Couleur : " << couleur << std::endl;
    }
};

class pointcol : public point, public coul
{
public:
    pointcol(int abs, int ord, short cl) : point(abs, ord), coul(cl)
    {
        cout << "constructor pointcol" << endl;
    }
    /*
   In the case of the point and coul classes, they don't define a copy constructor explicitly, so the compiler
    generates a default copy constructor for them. This default copy constructor performs a shallow copy of
    the data members x and y in the point class, and the couleur data member in the coul class.*/
    pointcol(pointcol &other) : point(other), coul(other)
    {
        cout << "copy constructor pointcol" << endl;
    }
    ~pointcol()
    {
        cout << "destructor pointcol" << endl;
    }
    void affiche()
    {
        point::affiche();
        coul::affiche();
    }
};

int main()
{
    pointcol p(3, 4, 5);
    p.affiche();

    pointcol p2 = p; // using the copy constructor
    p2.affiche();

    return 0;
}
