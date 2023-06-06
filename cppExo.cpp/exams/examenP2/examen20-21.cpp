#include <iostream>
#include <math.h>
using namespace std;
class rectangle
{
    float x, y; //(top-left)
    float z, t; //(right-bottom)

public:
    rectangle();
    rectangle(float x_, float y_);
    rectangle(float x_, float y_, float z_, float t_);
    ~rectangle();
    float perimetre();
    float surface();
    void affiche();
    void affiche(char *nom);
    static int nombreRectangle;
};
int rectangle::nombreRectangle = 0;
rectangle::rectangle() : x(10), y(5), z(0), t(0)
{
    nombreRectangle++;
}
rectangle::rectangle(float x_, float y_) : x(x_), y(x_), z(y_), t(y_)
{
    nombreRectangle++;
}
rectangle::rectangle(float x_, float y_, float z_, float t_) : x(x_), y(y_), z(z_), t(t_)
{
    nombreRectangle++;
}
rectangle::~rectangle()
{
    nombreRectangle--;
    cout << "le destructeur est appeler pour l'objet :" << endl;
    affiche();
}
float rectangle::perimetre()
{
    cout << "le perimetre du rectangle est :" << 2 * (x - z) + 2 * (y - t) << endl;
    return 2 * (x - z) + 2 * (y - t);
}
float rectangle::surface()
{
    cout << "la surface du rectangle est :" << (x - z) * (y - t) << endl;
    return (x - z) * (y - t);
};
void rectangle::affiche()
{
    cout << "top-left"
         << " (" << x << ',' << " " << y << ")" << endl;
    cout << "right-bottom"
         << " (" << z << ',' << " " << t << ")" << endl;
    cout << "le nombre d'objet actuelle est :" << nombreRectangle << endl;
};
void rectangle::affiche(char *nom)
{
    cout << nom << endl;
    affiche();
}

void Test()
{
    rectangle a(10, 2), b(7, 12, 1, 11);
}

int main()
{
    rectangle r0(3, 2);
    // r0.perimetre();
    // r0.surface();
    Test();
    char name[] = "myRectangle";
    rectangle r1(9, 5);
    r1.affiche(name);
    // r1.surface();
    // r1.perimetre();
    // r1.surface();
    return 0;
}